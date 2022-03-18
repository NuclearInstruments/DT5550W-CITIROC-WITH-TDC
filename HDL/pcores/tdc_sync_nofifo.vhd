library ieee;
use ieee.std_logic_1164.all;
use ieee.std_logic_misc.all;
use ieee.numeric_std.all;

library UNISIM;
use UNISIM.VComponents.all;

entity tdc_sync_nofifo is
  generic (
		TS_BITS           : integer := 56;  -- number of bits for the absolute time 
		TOT_BITS           : integer := 9   -- number of bits for the time over threshold

    );
    Port ( 
	      reset                : in     std_logic;                     -- global reset (active high)
			clk                  : in     std_logic;                     -- system clock (125 MHz)
            clk90                : in     std_logic;                     -- clk 125 MHz shifted by 90 degrees
			sclk                 : in     std_logic_vector(3 downto 0);  -- 250 MHz skewed clocks
			run                  : in     std_logic;                     -- run
			abstime              : in     unsigned(TS_BITS-1 downto 0); -- absolute time stamp
			evnt_absolute_time   : out    std_logic_vector(4+TS_BITS-1 downto 0);  
			evnt_tot             : out    std_logic_vector(TOT_BITS-1 downto 0);  
			evtn_tref			 : out	   std_logic;
			evnt_valid			 : out 	std_logic;
			hit_asyn             : in     std_logic;                     -- Asynchronous hit 
			hit_p1               : out    std_logic;                     -- Hit output 
			t_ref			 	 : in 		std_logic					  --flag_t0
			
	 );
end tdc_sync_nofifo;

architecture Behavioral of tdc_sync_nofifo is
	constant w_trgho            : integer := 16;
  type TYPE_HIT_STATE  is (HIT_0, HIT_1);
  signal fsm_hit, fsm_hit_fe  : TYPE_HIT_STATE;
 
  signal hit_s, hit_ss   : std_logic;
  signal hit_start       : std_logic;
  signal hit_end         : std_logic;
  signal tref_s          : std_logic;
  signal tref_latch      : std_logic;
  
  signal hit_s_fe        : std_logic;
  signal hit_start_fe    : std_logic;
  signal hit_end_fe      : std_logic;
  signal tref_s_fe       : std_logic;
  signal tref_latch_fe   : std_logic;
  
  signal tref_flag       : std_logic := '0';
  
  signal hrf_full        : std_logic := '0';

  signal trgho           : std_logic;
  signal cnt_trgho       : unsigned(w_trgho-1 downto 0);
  signal holdoff_time    : unsigned(w_trgho-1 downto 0);
  signal start_tot       : std_logic;
  signal hit_rdy         : std_logic;
  signal hit_position    : std_logic_vector(1 downto 0);
  signal tot_position    : std_logic_vector(1 downto 0);
  signal want_tot        : std_logic;

  -- hit FIFOs (contains trise+tot of the hits)
  --signal hrf_din         : std_logic_vector(data_width-1 downto 0);     
  signal hrf_wr_en       : std_logic;
 
  -- skewed clock capture for fine time measurement
  signal ftclk           : std_logic_vector(5 downto 0);
  signal hitr_cpt        : unsigned(5 downto 0);  -- rising
  signal hitf_cpt        : unsigned(5 downto 0);  -- falling

  signal trise           : unsigned(4+TS_BITS-1 downto 0);  -- coarse (TS_BITS bits) + fine (4 bits)
  signal tot             : unsigned(TOT_BITS-1 downto 0);  -- fine time of over threshold (fall-rise)
  signal totcnt          : unsigned(9 downto 0);  -- counters for tot time out
  
  signal tref_cnt        : unsigned(31 downto 0);  -- only for TREF (is_tref=true)
  
  ---------------------------------------------------------------------
  function decode_cpt (cpt : unsigned(5 downto 0)) return unsigned is
  begin
    --                      0123456789ABCDEF
    -- clk     = cpt(5) ____--------________--------________
    -- clk90   = cpt(4) ________--------________--------____
    -- sclk(0) = cpt(3) ____----____----____----____----____
    -- sclk(1) = cpt(2) -____----____----____----____----___
    -- sclk(2) = cpt(1) --____----____----____----____----__
    -- sclk(3) = cpt(0) ---____----____----____----____----_

    case cpt(3 downto 0) is
      when "0001" => return (cpt(4)     & "000");
      when "0011" => return (cpt(4)     & "001");
      when "0111" => return (not cpt(5) & "010");
      when "1111" => return (not cpt(5) & "011");
      when "1110" => return (not cpt(5) & "100");
      when "1100" => return (not cpt(5) & "101");
      when "1000" => return (not cpt(4) & "110");
      when "0000" => return (not cpt(4) & "111");
      when others => return ("0000");
    end case;
  end function;
  
begin

  want_tot <= '1'; -- when not is_tref and (ccregs.acq_ctrl(timing_info'range) = "01" or ccregs.acq_ctrl(timing_info'range) = "10") else '0';
  holdoff_time <= x"000A"; --unsigned(ccregs.trgho) when not is_tref else (others => '0');
  
--  hrf_busy  <= hrf_full;

  -- Rising edge of clk
  process(clk)
  begin
    if rising_edge(clk) then
      hit_s     <= hit_asyn;  -- hit_asyn synced with a 125 MHz clk
		tref_s	 <= t_ref;
      hit_start <= '0';
      hit_end   <= '0';
      case fsm_hit is
        when HIT_0  =>  if hit_s = '1' and trgho = '0' and hrf_full = '0' then
                          hit_start <= '1';
								  tref_latch <= tref_s;
                          fsm_hit   <= HIT_1;
                        end if;  
        when HIT_1  =>  if hit_s = '0' then
                          hit_end   <= '1';
                          fsm_hit   <= HIT_0;
                        end if;  
      end case;
    end if;  
  end process;
  -- Falling edge of clk
  process(clk)
  begin
    if falling_edge(clk) then
      hit_s_fe     <= hit_asyn;  -- hit_asyn synced with a 125 MHz clk
		tref_s_fe	 <= t_ref;
      hit_start_fe <= '0';
      hit_end_fe   <= '0';
      case fsm_hit_fe is
        when HIT_0  =>  if hit_s_fe = '1' and trgho = '0' and hrf_full = '0' then
                          hit_start_fe <= '1';
								  tref_latch_fe <= tref_s_fe;
                          fsm_hit_fe   <= HIT_1;
                        end if;  
        when HIT_1  =>  if hit_s_fe = '0' then
                          hit_end_fe   <= '1';
                          fsm_hit_fe   <= HIT_0;
                        end if;  
      end case;
    end if;  
  end process;

  hit_p1 <= hit_start;

  -- trigger Hold-off (remains active for a given number of clock cycles) 
  process(clk)
  begin
    if rising_edge(clk) then
      if reset = '1' then
        trgho         <= '0';
        cnt_trgho     <= (others => '0');
      else
        if (hit_start = '1' or hit_start_fe = '1') and holdoff_time /= 0 then
          trgho     <= '1';
          cnt_trgho <= holdoff_time;
        end if;  
        if cnt_trgho /= 0 then
          cnt_trgho <= cnt_trgho - 1;
        else
          trgho <= '0';
        end if;  
      end if;  
    end if;  
  end process;
 

  -- **********************************************************************************
  -- Tstamper
  -- **********************************************************************************
  -- 6 bit signal: 16 possible values --> 125 MHz => 8 ns / 16 values = 0.5 ns 
  -- 100001  -> ftclk = 0x21
  -- 100011  -> ftclk = 0x23
  -- 100111  -> ftclk = 0x27
  -- 101111  -> ftclk = 0x2F
  -- 111110  -> ftclk = 0x3E
  -- 111100  -> ftclk = 0x3C
  -- 111000  -> ftclk = 0x38
  -- 110000  -> ftclk = 0x30
  -- 010001  -> ftclk = 0x11
  -- 010011  -> ftclk = 0x13
  -- 010111  -> ftclk = 0x17
  -- 011111  -> ftclk = 0x1F
  -- 001110  -> ftclk = 0x0E
  -- 001100  -> ftclk = 0x0C
  -- 001000  -> ftclk = 0x08
  -- 000000  -> ftclk = 0x00
  ftclk <= clk & clk90 & sclk;                               
  
  hitr_cpt <= unsigned(ftclk) when rising_edge (hit_asyn);   -- store fine time stamp of the rising edge of the incoming signal
  hitf_cpt <= unsigned(ftclk) when falling_edge(hit_asyn);   -- store fine time stamp of the fallin edge of the incoming signal

  -- ------------------------------------------------------------------
  -- calculate fine time (0.5 ns steps) of Trise and ToT
  -- ------------------------------------------------------------------
  process(clk)
  begin
    if rising_edge(clk) then
      if reset = '1' then
		  tref_flag 	<= '0';
        hit_rdy      <= '0';
        hrf_wr_en    <= '0';
        start_tot    <= '0';
        hit_position <= "11";
        tot_position <= "11";
        trise        <= (others => '0');
        tot          <= (others => '0');
        totcnt       <= (others => '0');
      else
        hit_rdy      <= '0';
        hit_position <= "11";
        tot_position <= "11";
        
        if start_tot = '1' then
          totcnt <= totcnt + 1;
        end if;  
      
        -- Calculate hit tstamp (time at leading edge of hit)
        if hit_position = "11" then
          if hit_start = '1' then
            if (decode_cpt(hitr_cpt) >= 4 and decode_cpt(hitr_cpt) <= 11 ) then
              hit_position <= "01";
              start_tot    <= '1';
              totcnt       <= (others => '0');  
				  tref_flag	   <= tref_latch;
            end if;    
          end if;            
          if hit_start_fe = '1' then
            if (decode_cpt(hitr_cpt) < 4 ) then
              hit_position <= "00";
              start_tot    <= '1';
              totcnt       <= (others => '0');   
				  tref_flag	   <= tref_latch_fe;
            elsif (decode_cpt(hitr_cpt) > 11 ) then
              hit_position <= "10";
              start_tot    <= '1';
              totcnt       <= (others => '0');              
				  tref_flag	   <= tref_latch_fe;
            end if;     
          end if;  
        else
          if (hit_position = "00") then
            trise <= (abstime + 1) & decode_cpt(hitr_cpt);
          elsif (hit_position = "01") then
            trise <= abstime & decode_cpt(hitr_cpt);
          elsif (hit_position = "10") then  
            trise <= abstime & decode_cpt(hitr_cpt);
          end if;
			 evtn_tref <= tref_flag;
          if (want_tot = '0') then 
            hit_rdy <= '1';     
          end if;           
        end if;
        
        -- Calculate tot (time at trailing edge - time at leading edge)
        if want_tot = '1' then
          if tot_position = "11" then
            if (hit_end = '1' or totcnt = 63) then
              start_tot <= '0';
              if(decode_cpt(hitf_cpt) >= 4 and decode_cpt(hitf_cpt) <= 11 ) then
                tot_position <= "01";
              end if;  
            end if;
            if (hit_end_fe = '1' or totcnt = 63) then
              start_tot <= '0';
              if(decode_cpt(hitf_cpt) < 4 ) then
                tot_position <= "00";
              elsif(decode_cpt(hitf_cpt) > 11 ) then
                tot_position <= "10";
              end if;
            end if;
          else
            if (tot_position = "00") then
              tot <=  ( (abstime(TOT_BITS-5 downto 0) + 1) & decode_cpt(hitf_cpt) ) - trise(TOT_BITS-1 downto 0);
            elsif (tot_position = "01") then
              tot <=  ( abstime(TOT_BITS-5 downto 0)  & decode_cpt(hitf_cpt) ) - trise(TOT_BITS-1 downto 0);
            elsif (tot_position = "10") then 
              tot <=  ( abstime(TOT_BITS-5 downto 0)  & decode_cpt(hitf_cpt) ) - trise(TOT_BITS-1 downto 0);          
            end if;
            hit_rdy <= '1';

          end if;    
        end if;  
        
        hrf_wr_en  <= hit_rdy and run;  -- write the hit in the channel FIFO

      end if;  
    end if;
  end process;
  

evnt_absolute_time   <= std_logic_vector(trise);  
evnt_tot             <= std_logic_vector(tot);
evnt_valid				<= hrf_wr_en;
hrf_full <= '0';

end Behavioral;