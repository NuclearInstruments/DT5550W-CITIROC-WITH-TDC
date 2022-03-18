----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date: 31.03.2018 17:52:01
-- Design Name: 
-- Module Name: CITIROCAnalogMonitor - Behavioral
-- Project Name: 
-- Target Devices: 
-- Tool Versions: 
-- Description: 
-- 
-- Dependencies: 
-- 
-- Revision:
-- Revision 0.01 - File Created
-- Additional Comments:
-- 
----------------------------------------------------------------------------------


library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.STD_LOGIC_ARITH.ALL;
use IEEE.STD_LOGIC_UNSIGNED.ALL;

Library xpm;
use xpm.vcomponents.all;

-- Uncomment the following library declaration if using
-- arithmetic functions with Signed or Unsigned values
--use IEEE.NUMERIC_STD.ALL;

-- Uncomment the following library declaration if instantiating
-- any Xilinx leaf cells in this code.
--library UNISIM;
--use UNISIM.VComponents.all;

entity CITIROCAnalogReadoutV2 is
    Generic (   CLKDIV : integer := 25;
                TRIGGER_HOLD_DELAY : integer := 10
    );
    Port (  
            clk : in STD_LOGIC;
			reject_data : in std_logic;
			reset : in STD_LOGIC;
            TRIG : in STD_LOGIC;
			ADC_IN_LG : in STD_LOGIC_VECTOR (15 downto 0);
			ADC_IN_HG : in STD_LOGIC_VECTOR (15 downto 0);
			CHARGE_HIT_in : in STD_LOGIC;
            chrage_srin_a : out STD_LOGIC;
            chrage_sr_resetb : out STD_LOGIC;
            chrage_clk_a : out STD_LOGIC;
            raz_chn : out STD_LOGIC;
			val_evnt : out STD_LOGIC;
            hold_hg  : out STD_LOGIC;
            hold_lg  : out STD_LOGIC;
			
			
			
			M_ENERGY_LG : out STD_LOGIC_VECTOR (15 downto 0);
			M_ENERGY_HG : out STD_LOGIC_VECTOR (15 downto 0);
			M_CLK : out STD_LOGIC_VECTOR (0 downto 0);
			M_DIN : out STD_LOGIC_VECTOR (0 downto 0);
			
			S_CHID : out STD_LOGIC_VECTOR (4 downto 0);
			S_ENERGY_LG : out STD_LOGIC_VECTOR (15 downto 0);
			S_ENERGY_HG : out STD_LOGIC_VECTOR (15 downto 0);
			S_HIT : out STD_LOGIC_VECTOR (0 downto 0);
			S_DV : out STD_LOGIC_VECTOR (0 downto 0);

			P_ENERGY_0_LG : out STD_LOGIC_VECTOR (15 downto 0);
			P_ENERGY_0_HG : out STD_LOGIC_VECTOR (15 downto 0);
			P_HIT_0 : out STD_LOGIC_VECTOR (0 downto 0);
			P_ENERGY_1_LG : out STD_LOGIC_VECTOR (15 downto 0);
			P_ENERGY_1_HG : out STD_LOGIC_VECTOR (15 downto 0);
			P_HIT_1 : out STD_LOGIC_VECTOR (0 downto 0);
			P_ENERGY_2_LG : out STD_LOGIC_VECTOR (15 downto 0);
			P_ENERGY_2_HG : out STD_LOGIC_VECTOR (15 downto 0);
			P_HIT_2 : out STD_LOGIC_VECTOR (0 downto 0);
			P_ENERGY_3_LG : out STD_LOGIC_VECTOR (15 downto 0);
			P_ENERGY_3_HG : out STD_LOGIC_VECTOR (15 downto 0);
			P_HIT_3 : out STD_LOGIC_VECTOR (0 downto 0);
			P_ENERGY_4_LG : out STD_LOGIC_VECTOR (15 downto 0);
			P_ENERGY_4_HG : out STD_LOGIC_VECTOR (15 downto 0);
			P_HIT_4 : out STD_LOGIC_VECTOR (0 downto 0);
			P_ENERGY_5_LG : out STD_LOGIC_VECTOR (15 downto 0);
			P_ENERGY_5_HG : out STD_LOGIC_VECTOR (15 downto 0);
			P_HIT_5 : out STD_LOGIC_VECTOR (0 downto 0);
			P_ENERGY_6_LG : out STD_LOGIC_VECTOR (15 downto 0);
			P_ENERGY_6_HG : out STD_LOGIC_VECTOR (15 downto 0);
			P_HIT_6 : out STD_LOGIC_VECTOR (0 downto 0);
			P_ENERGY_7_LG : out STD_LOGIC_VECTOR (15 downto 0);
			P_ENERGY_7_HG : out STD_LOGIC_VECTOR (15 downto 0);
			P_HIT_7 : out STD_LOGIC_VECTOR (0 downto 0);
			P_ENERGY_8_LG : out STD_LOGIC_VECTOR (15 downto 0);
			P_ENERGY_8_HG : out STD_LOGIC_VECTOR (15 downto 0);
			P_HIT_8 : out STD_LOGIC_VECTOR (0 downto 0);
			P_ENERGY_9_LG : out STD_LOGIC_VECTOR (15 downto 0);
			P_ENERGY_9_HG : out STD_LOGIC_VECTOR (15 downto 0);
			P_HIT_9 : out STD_LOGIC_VECTOR (0 downto 0);
			P_ENERGY_10_LG : out STD_LOGIC_VECTOR (15 downto 0);
			P_ENERGY_10_HG : out STD_LOGIC_VECTOR (15 downto 0);
			P_HIT_10 : out STD_LOGIC_VECTOR (0 downto 0);
			P_ENERGY_11_LG : out STD_LOGIC_VECTOR (15 downto 0);
			P_ENERGY_11_HG : out STD_LOGIC_VECTOR (15 downto 0);
			P_HIT_11 : out STD_LOGIC_VECTOR (0 downto 0);
			P_ENERGY_12_LG : out STD_LOGIC_VECTOR (15 downto 0);
			P_ENERGY_12_HG : out STD_LOGIC_VECTOR (15 downto 0);
			P_HIT_12 : out STD_LOGIC_VECTOR (0 downto 0);
			P_ENERGY_13_LG : out STD_LOGIC_VECTOR (15 downto 0);
			P_ENERGY_13_HG : out STD_LOGIC_VECTOR (15 downto 0);
			P_HIT_13 : out STD_LOGIC_VECTOR (0 downto 0);
			P_ENERGY_14_LG : out STD_LOGIC_VECTOR (15 downto 0);
			P_ENERGY_14_HG : out STD_LOGIC_VECTOR (15 downto 0);
			P_HIT_14 : out STD_LOGIC_VECTOR (0 downto 0);
			P_ENERGY_15_LG : out STD_LOGIC_VECTOR (15 downto 0);
			P_ENERGY_15_HG : out STD_LOGIC_VECTOR (15 downto 0);
			P_HIT_15 : out STD_LOGIC_VECTOR (0 downto 0);
			P_ENERGY_16_LG : out STD_LOGIC_VECTOR (15 downto 0);
			P_ENERGY_16_HG : out STD_LOGIC_VECTOR (15 downto 0);
			P_HIT_16 : out STD_LOGIC_VECTOR (0 downto 0);
			P_ENERGY_17_LG : out STD_LOGIC_VECTOR (15 downto 0);
			P_ENERGY_17_HG : out STD_LOGIC_VECTOR (15 downto 0);
			P_HIT_17 : out STD_LOGIC_VECTOR (0 downto 0);
			P_ENERGY_18_LG : out STD_LOGIC_VECTOR (15 downto 0);
			P_ENERGY_18_HG : out STD_LOGIC_VECTOR (15 downto 0);
			P_HIT_18 : out STD_LOGIC_VECTOR (0 downto 0);
			P_ENERGY_19_LG : out STD_LOGIC_VECTOR (15 downto 0);
			P_ENERGY_19_HG : out STD_LOGIC_VECTOR (15 downto 0);
			P_HIT_19 : out STD_LOGIC_VECTOR (0 downto 0);
			P_ENERGY_20_LG : out STD_LOGIC_VECTOR (15 downto 0);
			P_ENERGY_20_HG : out STD_LOGIC_VECTOR (15 downto 0);
			P_HIT_20 : out STD_LOGIC_VECTOR (0 downto 0);
			P_ENERGY_21_LG : out STD_LOGIC_VECTOR (15 downto 0);
			P_ENERGY_21_HG : out STD_LOGIC_VECTOR (15 downto 0);
			P_HIT_21 : out STD_LOGIC_VECTOR (0 downto 0);
			P_ENERGY_22_LG : out STD_LOGIC_VECTOR (15 downto 0);
			P_ENERGY_22_HG : out STD_LOGIC_VECTOR (15 downto 0);
			P_HIT_22 : out STD_LOGIC_VECTOR (0 downto 0);
			P_ENERGY_23_LG : out STD_LOGIC_VECTOR (15 downto 0);
			P_ENERGY_23_HG : out STD_LOGIC_VECTOR (15 downto 0);
			P_HIT_23 : out STD_LOGIC_VECTOR (0 downto 0);
			P_ENERGY_24_LG : out STD_LOGIC_VECTOR (15 downto 0);
			P_ENERGY_24_HG : out STD_LOGIC_VECTOR (15 downto 0);
			P_HIT_24 : out STD_LOGIC_VECTOR (0 downto 0);
			P_ENERGY_25_LG : out STD_LOGIC_VECTOR (15 downto 0);
			P_ENERGY_25_HG : out STD_LOGIC_VECTOR (15 downto 0);
			P_HIT_25 : out STD_LOGIC_VECTOR (0 downto 0);
			P_ENERGY_26_LG : out STD_LOGIC_VECTOR (15 downto 0);
			P_ENERGY_26_HG : out STD_LOGIC_VECTOR (15 downto 0);
			P_HIT_26 : out STD_LOGIC_VECTOR (0 downto 0);
			P_ENERGY_27_LG : out STD_LOGIC_VECTOR (15 downto 0);
			P_ENERGY_27_HG : out STD_LOGIC_VECTOR (15 downto 0);
			P_HIT_27 : out STD_LOGIC_VECTOR (0 downto 0);
			P_ENERGY_28_LG : out STD_LOGIC_VECTOR (15 downto 0);
			P_ENERGY_28_HG : out STD_LOGIC_VECTOR (15 downto 0);
			P_HIT_28 : out STD_LOGIC_VECTOR (0 downto 0);
			P_ENERGY_29_LG : out STD_LOGIC_VECTOR (15 downto 0);
			P_ENERGY_29_HG : out STD_LOGIC_VECTOR (15 downto 0);
			P_HIT_29 : out STD_LOGIC_VECTOR (0 downto 0);
			P_ENERGY_30_LG : out STD_LOGIC_VECTOR (15 downto 0);
			P_ENERGY_30_HG : out STD_LOGIC_VECTOR (15 downto 0);
			P_HIT_30 : out STD_LOGIC_VECTOR (0 downto 0);
			P_ENERGY_31_LG : out STD_LOGIC_VECTOR (15 downto 0);
			P_ENERGY_31_HG : out STD_LOGIC_VECTOR (15 downto 0);
			P_HIT_31 : out STD_LOGIC_VECTOR (0 downto 0);			
			P_DV : out STD_LOGIC_VECTOR (0 downto 0);

			P_FRAME_ACK : in STD_LOGIC_VECTOR (0 downto 0);
			P_FRAME_DV : out STD_LOGIC_VECTOR (0 downto 0);
			P_FRAME_DATA : out STD_LOGIC_VECTOR (1023 downto 0);
			
			CHIP_TEMP : out STD_LOGIC_VECTOR (15 downto 0);
			
			TS_IN : in STD_LOGIC_VECTOR (63 downto 0);
			TS0_IN : in STD_LOGIC_VECTOR (31 downto 0);
			TS_OUT : out STD_LOGIC_VECTOR (63 downto 0);
			TS0_OUT : out STD_LOGIC_VECTOR (31 downto 0);

            HOLD_WIN_LENGTH : in STD_LOGIC_VECTOR (15 downto 0);
            
			BUSY : out STD_LOGIC_VECTOR (0 downto 0);
			
			T_OR32 : in  STD_LOGIC_VECTOR (0 downto 0);
			T0 : in  STD_LOGIC_VECTOR (0 downto 0);
			TDC_CLOCKS : in std_logic_vector (5 downto 0);
			
            VALIDATION_REG : in std_logic_vector(31 downto 0);
            VALIDATION_IN : in std_logic_vector(0 downto 0);
            RUNRESET : in std_logic_vector(0 downto 0);
            COUNTER_TRIGGER : out STD_LOGIC_VECTOR (31 downto 0);
            COUNTER_VALIDATION : out STD_LOGIC_VECTOR (31 downto 0);
            FLAGS : out STD_LOGIC_VECTOR (31 downto 0);
            SW_VETO : in STD_LOGIC_VECTOR(0 downto 0)
    );
end CITIROCAnalogReadoutV2;

architecture Behavioral of CITIROCAnalogReadoutV2 is
    
    signal iEnable : std_logic;
    signal iAnalogOnly : std_logic;
	signal start_c_raz : std_logic_vector (7 downto 0) := x"FF";
	type FILTER_AN is array (0 to 35) of std_logic_vector(15 downto 0);
	type BUFFER_AN is array (0 to 35) of std_logic_vector(15 downto 0);
	signal BUFFER_DATA_LG : BUFFER_AN;
	signal BUFFER_DATA_HG : BUFFER_AN;
	signal BUFFER_HIT : std_logic_vector (34 downto 0);
	signal I : integer range 0 to 50 := 0;
	signal CH_idx : integer range 0 to 50 := 0;
	signal  ADC_FILTERED_LG : std_logic_vector(15 downto 0);
	signal  ADC_FILTERED_HG : std_logic_vector(15 downto 0);
	
	signal ichrage_srin_a: STD_LOGIC;
    signal ichrage_clk_a : STD_LOGIC;

    signal dummy_data : std_logic_vector (13 downto 0) := (others => '0');
    
    signal hold : std_logic := '0';
    signal i_reset_chrg : std_logic := '0';
    
    component ila_acq IS
    PORT (
    clk : IN STD_LOGIC;
    
    
    probe0 : IN STD_LOGIC_VECTOR(15 DOWNTO 0);
        probe1 : IN STD_LOGIC_VECTOR(15 DOWNTO 0);
        probe2 : IN STD_LOGIC_VECTOR(15 DOWNTO 0);
        probe3 : IN STD_LOGIC_VECTOR(15 DOWNTO 0);
        probe4 : IN STD_LOGIC_VECTOR(3 DOWNTO 0);
        probe5 : IN STD_LOGIC_VECTOR(0 DOWNTO 0);
        probe6 : IN STD_LOGIC_VECTOR(0 DOWNTO 0);
        probe7 : IN STD_LOGIC_VECTOR(0 DOWNTO 0);
        probe8 : IN STD_LOGIC_VECTOR(0 DOWNTO 0);
        probe9 : IN STD_LOGIC_VECTOR(0 DOWNTO 0);
        probe10 : IN STD_LOGIC_VECTOR(0 DOWNTO 0);
        probe11 : IN STD_LOGIC_VECTOR(0 DOWNTO 0);
        probe12 : IN STD_LOGIC_VECTOR(15 DOWNTO 0);
        probe13 : IN STD_LOGIC_VECTOR(15 DOWNTO 0)
    );
    END component;
    
    
    component tdc_sync_nofifo is
      generic (
            TS_BITS           : integer := 58;  -- number of bits for the absolute time 
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
              evtn_tref            : out       std_logic;
              evnt_valid           : out     std_logic;
              hit_asyn             : in     std_logic;                     -- Asynchronous hit 
              hit_p1               : out    std_logic;                     -- Hit output 
              t_ref                : in         std_logic                      --flag_t0  
         );
    end component;    
    
    signal S_ENERGY_LGb :  STD_LOGIC_VECTOR (15 downto 0);
    signal S_ENERGY_HGb :  STD_LOGIC_VECTOR (15 downto 0);
    
    signal TDC_TS : STD_LOGIC_VECTOR(47 downto 0);
    signal TDC_READY : STD_LOGIC;
    signal TDC_T0L : STD_LOGIC;
    signal iValidation : STD_LOGIC:='0';
    signal oValidation : STD_LOGIC:='0';
    signal ValidationLatch : STD_LOGIC:='0';
    signal ValidationCounter : std_logic_vector(31 downto 0);
    signal TriggerCounter : std_logic_vector(31 downto 0);
begin
    hold_hg <= hold;
    hold_lg <= hold;
    chrage_srin_a <= ichrage_srin_a;
    chrage_clk_a <= ichrage_clk_a;
    chrage_sr_resetb <= i_reset_chrg;
    M_ENERGY_LG <= ADC_FILTERED_LG;
    M_ENERGY_HG <= ADC_FILTERED_HG;
    
    M_CLK(0) <= ichrage_clk_a;
    M_DIN(0) <= ichrage_srin_a;
    
    
    TDC : tdc_sync_nofifo 
      generic map(
            TS_BITS => 44, 
            TOT_BITS => 9 )
        Port Map( 
              reset                 => reset,
              clk                   => TDC_CLOCKS(0),
              clk90                 => TDC_CLOCKS(1),
              sclk                  => TDC_CLOCKS(5 downto 2),
              run                   => '1',
              abstime               => unsigned(TS_IN(43 downto 0)),
              evnt_absolute_time    => TDC_TS,  
              evnt_tot              => open,  
              evtn_tref             => TDC_T0L,
              evnt_valid            => TDC_READY,
              hit_asyn              => T_OR32(0), 
              hit_p1                => open, 
              t_ref                 => T0(0)  
         );
    
    

 ANALOG_READOUT : block
        signal BLKSM : std_logic_vector (3 downto 0) := x"0";
        signal iA_trigger_logic : std_logic;
        signal oA_trigger_logic : std_logic;
        signal counter : integer;
        signal bitcounter : integer;
        
        signal filterMem_LG : FILTER_AN := (others => (others => '0'));
        signal filterMem_HG : FILTER_AN := (others => (others => '0'));
        
        signal accumulator_LG : std_logic_vector (31 downto 0) := (others => '0');
        signal accumulator_HG : std_logic_vector (31 downto 0) := (others => '0');
        signal HITMEM : std_logic_vector (45 downto 0) := (others => '0');
        signal skip : std_logic := '0';
        signal arm_tdc_capture : std_logic := '0';
        
        signal oT0 : std_logic;
        signal iT0 : std_logic;
        signal ValidationTimeoutCounter : std_logic_vector(15 downto 0);
        signal ValidationTimeout : std_logic := '0';
        signal ValidationReset : std_logic := '0';
        signal TriggerLatch : std_logic := '0';
    begin
    
        
--    ilaA : ila_acq 
--    PORT MAP(
--    clk => clk ,
    
    
--    probe0 => ADC_IN_LG,
--        probe1 => ADC_IN_HG ,
--        probe2 => ADC_FILTERED_LG ,
--        probe3 => ADC_FILTERED_HG ,
--        probe4 => BLKSM ,
--        probe5(0) => hold ,
--        probe6(0) => iA_trigger_logic ,
--        probe7(0) => ichrage_srin_a ,
--        probe8(0) => ichrage_clk_a ,
--        probe9(0) => i_reset_chrg ,
--        probe10(0) => CHARGE_HIT_in  ,
--        probe11(0) => reject_data,
--        probe12 => S_ENERGY_LGb,
--        probe13 => S_ENERGY_HGb 
--    );
   
    
        ANALOG_SM : process(clk)
        begin
			if reset = '1' then
				start_c_raz <= x"06";
				BLKSM <= x"0";
				P_DV <= "0";
				S_DV <= "0";
				BUSY <= "0";	
				ichrage_srin_a <= '0';
                ichrage_clk_a  <= '0';
                i_reset_chrg <= '0';
				raz_chn <= '0';
				val_evnt <= '0';		
				filterMem_LG <= (others => (others => '0'));
				filterMem_HG <= (others => (others => '0'));	
				accumulator_LG <= (others => '0');
				accumulator_HG <= (others => '0');	
				ValidationReset <= '0';
            elsif rising_edge(clk) then
				P_DV <= "0";
				
                S_DV <= "0";
                val_evnt <= '1';
                ValidationReset <= '0';
                
                iA_trigger_logic <= TRIG;
                oA_trigger_logic <= iA_trigger_logic;
                
                filterMem_LG(0) <= ADC_IN_LG;
                for Z in 1 to 16 loop
                    filterMem_LG(Z) <= filterMem_LG(Z-1);
                end loop;
                accumulator_LG <= accumulator_LG + ext(filterMem_LG(0),32) - ext(filterMem_LG(8),32);

                filterMem_HG(0) <= ADC_IN_HG;
                for Z in 1 to 16 loop
                    filterMem_HG(Z) <= filterMem_HG(Z-1);
                end loop;
                accumulator_HG <= accumulator_HG + ext(filterMem_HG(0),32) - ext(filterMem_HG(8),32);

                if accumulator_LG(2) = '0' then  
                    ADC_FILTERED_LG <=  accumulator_LG(16+3-1 downto 3);
                else 
                    ADC_FILTERED_LG <=  accumulator_LG(16+3-1 downto 3) +1;
                end if;
                
                if accumulator_HG(2) = '0' then  
                    ADC_FILTERED_HG <=  accumulator_HG(16+3-1 downto 3);
                else
                    ADC_FILTERED_HG <=  accumulator_HG(16+3-1 downto 3) + 1;
                end if;
                
                if arm_tdc_capture = '1' and TDC_READY = '1' then
                    arm_tdc_capture <= '0';
                    TS_OUT <=  "0000" & x"000" & TDC_TS(47 downto 0);
                    --TDC_T0L
                end if;
                iT0 <= T0(0);
                oT0 <= iT0;
                

                case BLKSM is
                
                    when x"0" =>
                        raz_chn <= '0';
                        BUSY <= "0";
                        ichrage_clk_a  <= '0';
                        hold <= '0';
                        i_reset_chrg <= '1';
                        CH_idx <= 0;
                        TriggerLatch <= '0';
                        if (iA_trigger_logic = '1' and oA_trigger_logic = '0') then-- or (iT0 = '1' and oT0='0')  then
                            BUSY <= "1";
                            BLKSM <= x"1";
                            counter <= conv_integer(HOLD_WIN_LENGTH);--TRIGGER_HOLD_DELAY;
                            bitcounter <= 32;
                            I <= 0;
							TS0_OUT <= TS0_IN(31 downto 0);
							TS_OUT <= TS_IN(59 downto 0) & "0000";
							arm_tdc_capture <= '1';
							ValidationReset <= '1';
							TriggerLatch <= '1';
							COUNTER_TRIGGER <= TriggerCounter+1;
                        else
							if iA_trigger_logic ='1' then
							 raz_chn <= '1';
							end if; 
                        end if;
                    
                    when x"1" =>
                        
                        if counter = 0 then
                            hold <= '1';
                            BLKSM <= x"2";
                        else
                            counter <= counter -1;
                        end if;           
                        
                   when x"2" =>
                        i_reset_chrg <= '0';
                        counter <= 16;
                        
                        if VALIDATION_REG(0) = '0' then
                            BLKSM <= x"3";
                            FLAGS <= x"00000000";
                            COUNTER_VALIDATION <= x"00000000";
                        else
                            COUNTER_VALIDATION <= ValidationCounter;
                            if ValidationLatch = '1' then
                                BLKSM <= x"3";
                                FLAGS <= x"00000001";
                            end if;
                            
                            if ValidationTimeout = '1' then
                                if VALIDATION_REG(1) = '0' then
                                    BLKSM <= x"3";    
                                else
                                    start_c_raz <= x"06";
                                    hold <= '0';
                                    BLKSM <= x"A";
                                end if; 
                                FLAGS <= x"00000002";               
                            end if; 
                        end if;
                        
                                                                  
                   when x"3" =>
                        if counter = 0 then
                            i_reset_chrg <= '1';
                            counter <= 16;
                            BLKSM <= x"4";
                        else
                            counter <= counter -1;
                        end if;           
                
                   when x"4" =>
                        if counter = 0 then
                            BLKSM <= x"5";
                        ELSE
                            counter <= counter -1;
                        end if;
                        
                   when x"5" =>
                        BLKSM <= x"6";
                        ichrage_srin_a <= '1';
                        ichrage_clk_a  <= '0';
                        counter <= CLKDIV;
                        
                   when x"6" =>
                        if counter = 0 then
                            ichrage_clk_a  <= '1';
                            counter <= CLKDIV;    
                            BLKSM <= x"7";   
                        else
                            counter <= counter - 1;
                        end if;
                        
                   when x"7" =>
                       -- 6 è un valore empirico stimato da analyser come perfetto momento
                       -- dove campionare il segnale
                       if counter = CLKDIV/2+1 then
                           --entre qui dopo i primi sul fronte di discesa del terzo colpo di clock (I=2)
                           --per allinearsi alla pipeline dell'ADC che ora va a 20 MHz
                           --per ridurre l'INL
                           if I>2 then
                           
                               if CH_IDX < 32 then
                                   BUFFER_DATA_LG(CH_IDX) <= ADC_FILTERED_LG; 
                                   BUFFER_DATA_HG(CH_IDX) <= ADC_FILTERED_HG;
                                   BUFFER_HIT(CH_IDX) <= HITMEM(CH_IDX);
                                   S_ENERGY_LGb <=ADC_FILTERED_LG;
                                   S_ENERGY_HGb <=ADC_FILTERED_HG;
                                   S_HIT(0) <= HITMEM(CH_IDX);
                                   S_CHID <= conv_std_logic_vector(CH_IDX,5);
                                   S_DV <= "1";
                                   CH_IDX <= CH_IDX +1;
                               else
                                   CHIP_TEMP <= ADC_FILTERED_LG;
                               end if;
                           end if; 
                       end if;
                                          
                        if counter = 0 then
                           ichrage_clk_a  <= '0';
                           ichrage_srin_a <= '0';
                           counter <= CLKDIV;    
                           BLKSM <= x"8";    
                       else
                           counter <= counter - 1;
                       end if;
                   
                   when x"8" =>

                        
                        
                        if counter = 0 then
                            ichrage_clk_a  <= '1';
                            counter <= CLKDIV;
                            HITMEM(I) <= CHARGE_HIT_in;
                            I <= I + 1;
                            if I < 37 then                    --Acquisizione standardard  (era 32)
                                BLKSM <= x"7";
                            else
                                BLKSM <= x"9";                --Uscita
                            end if;                               
                        else
                            counter <= counter - 1;
                        end if;                       
                   
                   when x"9" =>
                       dummy_data <= dummy_data +1;
                       hold <= '0';
                       BLKSM <= x"A";
                       
                       start_c_raz <= x"06";
                       
                       P_ENERGY_0_LG <= BUFFER_DATA_LG(0);
                       P_ENERGY_0_HG <= BUFFER_DATA_HG(0);
                       P_HIT_0(0) <= BUFFER_HIT(0);
                       P_ENERGY_1_LG <= BUFFER_DATA_LG(1);
                       P_ENERGY_1_HG <= BUFFER_DATA_HG(1);
                       P_HIT_1(0) <= BUFFER_HIT(1);
                       P_ENERGY_2_LG <= BUFFER_DATA_LG(2);
                       P_ENERGY_2_HG <= BUFFER_DATA_HG(2);
                       P_HIT_2(0) <= BUFFER_HIT(2);
                       P_ENERGY_3_LG <= BUFFER_DATA_LG(3);
                       P_ENERGY_3_HG <= BUFFER_DATA_HG(3);
                       P_HIT_3(0) <= BUFFER_HIT(3);
                       P_ENERGY_4_LG <= BUFFER_DATA_LG(4);
                       P_ENERGY_4_HG <= BUFFER_DATA_HG(4);
                       P_HIT_4(0) <= BUFFER_HIT(4);
                       P_ENERGY_5_LG <= BUFFER_DATA_LG(5);
                       P_ENERGY_5_HG <= BUFFER_DATA_HG(5);
                       P_HIT_5(0) <= BUFFER_HIT(5);
                       P_ENERGY_6_LG <= BUFFER_DATA_LG(6);
                       P_ENERGY_6_HG <= BUFFER_DATA_HG(6);
                       P_HIT_6(0) <= BUFFER_HIT(6);
                       P_ENERGY_7_LG <= BUFFER_DATA_LG(7);
                       P_ENERGY_7_HG <= BUFFER_DATA_HG(7);
                       P_HIT_7(0) <= BUFFER_HIT(7);
                       P_ENERGY_8_LG <= BUFFER_DATA_LG(8);
                       P_ENERGY_8_HG <= BUFFER_DATA_HG(8);
                       P_HIT_8(0) <= BUFFER_HIT(8);
                       P_ENERGY_9_LG <= BUFFER_DATA_LG(9);
                       P_ENERGY_9_HG <= BUFFER_DATA_HG(9);
                       P_HIT_9(0) <= BUFFER_HIT(9);
                       P_ENERGY_10_LG <= BUFFER_DATA_LG(10);
                       P_ENERGY_10_HG <= BUFFER_DATA_HG(10);
                       P_HIT_10(0) <= BUFFER_HIT(10);
                       P_ENERGY_11_LG <= BUFFER_DATA_LG(11);
                       P_ENERGY_11_HG <= BUFFER_DATA_HG(11);
                       P_HIT_11(0) <= BUFFER_HIT(11);
                       P_ENERGY_12_LG <= BUFFER_DATA_LG(12);
                       P_ENERGY_12_HG <= BUFFER_DATA_HG(12);
                       P_HIT_12(0) <= BUFFER_HIT(12);
                       P_ENERGY_13_LG <= BUFFER_DATA_LG(13);
                       P_ENERGY_13_HG <= BUFFER_DATA_HG(13);
                       P_HIT_13(0) <= BUFFER_HIT(13);
                       P_ENERGY_14_LG <= BUFFER_DATA_LG(14);
                       P_ENERGY_14_HG <= BUFFER_DATA_HG(14);
                       P_HIT_14(0) <= BUFFER_HIT(14);
                       P_ENERGY_15_LG <= BUFFER_DATA_LG(15);
                       P_ENERGY_15_HG <= BUFFER_DATA_HG(15);
                       P_HIT_15(0) <= BUFFER_HIT(15);
                       P_ENERGY_16_LG <= BUFFER_DATA_LG(16);
                       P_ENERGY_16_HG <= BUFFER_DATA_HG(16);
                       P_HIT_16(0) <= BUFFER_HIT(16);
                       P_ENERGY_17_LG <= BUFFER_DATA_LG(17);
                       P_ENERGY_17_HG <= BUFFER_DATA_HG(17);
                       P_HIT_17(0) <= BUFFER_HIT(17);
                       P_ENERGY_18_LG <= BUFFER_DATA_LG(18);
                       P_ENERGY_18_HG <= BUFFER_DATA_HG(18);
                       P_HIT_18(0) <= BUFFER_HIT(18);
                       P_ENERGY_19_LG <= BUFFER_DATA_LG(19);
                       P_ENERGY_19_HG <= BUFFER_DATA_HG(19);
                       P_HIT_19(0) <= BUFFER_HIT(19);
                       P_ENERGY_20_LG <= BUFFER_DATA_LG(20);
                       P_ENERGY_20_HG <= BUFFER_DATA_HG(20);
                       P_HIT_20(0) <= BUFFER_HIT(20);
                       P_ENERGY_21_LG <= BUFFER_DATA_LG(21);
                       P_ENERGY_21_HG <= BUFFER_DATA_HG(21);
                       P_HIT_21(0) <= BUFFER_HIT(21);
                       P_ENERGY_22_LG <= BUFFER_DATA_LG(22);
                       P_ENERGY_22_HG <= BUFFER_DATA_HG(22);
                       P_HIT_22(0) <= BUFFER_HIT(22);
                       P_ENERGY_23_LG <= BUFFER_DATA_LG(23);
                       P_ENERGY_23_HG <= BUFFER_DATA_HG(23);
                       P_HIT_23(0) <= BUFFER_HIT(23);
                       P_ENERGY_24_LG <= BUFFER_DATA_LG(24);
                       P_ENERGY_24_HG <= BUFFER_DATA_HG(24);
                       P_HIT_24(0) <= BUFFER_HIT(24);
                       P_ENERGY_25_LG <= BUFFER_DATA_LG(25);
                       P_ENERGY_25_HG <= BUFFER_DATA_HG(25);
                       P_HIT_25(0) <= BUFFER_HIT(25);
                       P_ENERGY_26_LG <= BUFFER_DATA_LG(26);
                       P_ENERGY_26_HG <= BUFFER_DATA_HG(26);
                       P_HIT_26(0) <= BUFFER_HIT(26);
                       P_ENERGY_27_LG <= BUFFER_DATA_LG(27);
                       P_ENERGY_27_HG <= BUFFER_DATA_HG(27);
                       P_HIT_27(0) <= BUFFER_HIT(27);
                       P_ENERGY_28_LG <= BUFFER_DATA_LG(28);
                       P_ENERGY_28_HG <= BUFFER_DATA_HG(28);
                       P_HIT_28(0) <= BUFFER_HIT(28);
                       P_ENERGY_29_LG <= BUFFER_DATA_LG(29);
                       P_ENERGY_29_HG <= BUFFER_DATA_HG(29);
                       P_HIT_29(0) <= BUFFER_HIT(29);
                       P_ENERGY_30_LG <= BUFFER_DATA_LG(30);
                       P_ENERGY_30_HG <= BUFFER_DATA_HG(30);
                       P_HIT_30(0) <= BUFFER_HIT(30);
                       P_ENERGY_31_LG <= BUFFER_DATA_LG(31);
                       P_ENERGY_31_HG <= BUFFER_DATA_HG(31);
                       P_HIT_31(0) <= BUFFER_HIT(31);
                       P_DV <= "1";                           
                    
					   P_FRAME_DATA <=	"000" & BUFFER_HIT(0) & BUFFER_DATA_LG(0)(13 DOWNTO 0) & BUFFER_DATA_HG(0)(13 DOWNTO 0) &
                                            "000" & BUFFER_HIT(1) & BUFFER_DATA_LG(1)(13 DOWNTO 0) & BUFFER_DATA_HG(1)(13 DOWNTO 0) &
                                            "000" & BUFFER_HIT(2) & BUFFER_DATA_LG(2)(13 DOWNTO 0) & BUFFER_DATA_HG(2)(13 DOWNTO 0) &
                                            "000" & BUFFER_HIT(3) & BUFFER_DATA_LG(3)(13 DOWNTO 0) & BUFFER_DATA_HG(3)(13 DOWNTO 0) &
                                            "000" & BUFFER_HIT(4) & BUFFER_DATA_LG(4)(13 DOWNTO 0) & BUFFER_DATA_HG(4)(13 DOWNTO 0) &
                                            "000" & BUFFER_HIT(5) & BUFFER_DATA_LG(5)(13 DOWNTO 0) & BUFFER_DATA_HG(5)(13 DOWNTO 0) &
                                            "000" & BUFFER_HIT(6) & BUFFER_DATA_LG(6)(13 DOWNTO 0) & BUFFER_DATA_HG(6)(13 DOWNTO 0) &
                                            "000" & BUFFER_HIT(7) & BUFFER_DATA_LG(7)(13 DOWNTO 0) & BUFFER_DATA_HG(7)(13 DOWNTO 0) &
                                            
                                            "000" & BUFFER_HIT(8) & BUFFER_DATA_LG(8)(13 DOWNTO 0) & BUFFER_DATA_HG(8)(13 DOWNTO 0) &
                                            "000" & BUFFER_HIT(9) & BUFFER_DATA_LG(9)(13 DOWNTO 0) & BUFFER_DATA_HG(9)(13 DOWNTO 0) &
                                            "000" & BUFFER_HIT(10) & BUFFER_DATA_LG(10)(13 DOWNTO 0) & BUFFER_DATA_HG(10)(13 DOWNTO 0) &
                                            "000" & BUFFER_HIT(11) & BUFFER_DATA_LG(11)(13 DOWNTO 0) & BUFFER_DATA_HG(11)(13 DOWNTO 0) &
                                            "000" & BUFFER_HIT(12) & BUFFER_DATA_LG(12)(13 DOWNTO 0) & BUFFER_DATA_HG(12)(13 DOWNTO 0) &
                                            "000" & BUFFER_HIT(13) & BUFFER_DATA_LG(13)(13 DOWNTO 0) & BUFFER_DATA_HG(13)(13 DOWNTO 0) &
                                            "000" & BUFFER_HIT(14) & BUFFER_DATA_LG(14)(13 DOWNTO 0) & BUFFER_DATA_HG(14)(13 DOWNTO 0) &
                                            "000" & BUFFER_HIT(15) & BUFFER_DATA_LG(15)(13 DOWNTO 0) & BUFFER_DATA_HG(15)(13 DOWNTO 0) &
                                            
                                            "000" & BUFFER_HIT(16) & BUFFER_DATA_LG(16)(13 DOWNTO 0) & BUFFER_DATA_HG(16)(13 DOWNTO 0) &
                                            "000" & BUFFER_HIT(17) & BUFFER_DATA_LG(17)(13 DOWNTO 0) & BUFFER_DATA_HG(17)(13 DOWNTO 0) &
                                            "000" & BUFFER_HIT(18) & BUFFER_DATA_LG(18)(13 DOWNTO 0) & BUFFER_DATA_HG(18)(13 DOWNTO 0) &
                                            "000" & BUFFER_HIT(19) & BUFFER_DATA_LG(19)(13 DOWNTO 0) & BUFFER_DATA_HG(19)(13 DOWNTO 0) &
                                            "000" & BUFFER_HIT(20) & BUFFER_DATA_LG(20)(13 DOWNTO 0) & BUFFER_DATA_HG(20)(13 DOWNTO 0) &
                                            "000" & BUFFER_HIT(21) & BUFFER_DATA_LG(21)(13 DOWNTO 0) & BUFFER_DATA_HG(21)(13 DOWNTO 0) &
                                            "000" & BUFFER_HIT(22) & BUFFER_DATA_LG(22)(13 DOWNTO 0) & BUFFER_DATA_HG(22)(13 DOWNTO 0) &
                                            "000" & BUFFER_HIT(23) & BUFFER_DATA_LG(23)(13 DOWNTO 0) & BUFFER_DATA_HG(23)(13 DOWNTO 0) &
                                            
                                            "000" & BUFFER_HIT(24) & BUFFER_DATA_LG(24)(13 DOWNTO 0) & BUFFER_DATA_HG(24)(13 DOWNTO 0) &
                                            "000" & BUFFER_HIT(25) & BUFFER_DATA_LG(25)(13 DOWNTO 0) & BUFFER_DATA_HG(25)(13 DOWNTO 0) &
                                            "000" & BUFFER_HIT(26) & BUFFER_DATA_LG(26)(13 DOWNTO 0) & BUFFER_DATA_HG(26)(13 DOWNTO 0) &
                                            "000" & BUFFER_HIT(27) & BUFFER_DATA_LG(27)(13 DOWNTO 0) & BUFFER_DATA_HG(27)(13 DOWNTO 0) &
                                            "000" & BUFFER_HIT(28) & BUFFER_DATA_LG(28)(13 DOWNTO 0) & BUFFER_DATA_HG(28)(13 DOWNTO 0) &
                                            "000" & BUFFER_HIT(29) & BUFFER_DATA_LG(29)(13 DOWNTO 0) & BUFFER_DATA_HG(29)(13 DOWNTO 0) &
                                            "000" & BUFFER_HIT(30) & BUFFER_DATA_LG(30)(13 DOWNTO 0) & BUFFER_DATA_HG(30)(13 DOWNTO 0) &
                                            "000" & BUFFER_HIT(31) & BUFFER_DATA_LG(31)(13 DOWNTO 0) & BUFFER_DATA_HG(31)(13 DOWNTO 0);
							
							P_FRAME_DV <= "1";			
								
                    when x"A" =>
                        if start_c_raz = x"00" then
                                raz_chn <= '0';
                                BLKSM <= x"B";
                                start_c_raz <= x"1F";
                                --val_evnt <= '1';
                        else
                                if start_c_raz = x"06" then
                                    raz_chn <= '0';
                                  --  val_evnt <= '0';
                                else
                                    if start_c_raz = x"04" then
                                        raz_chn <= '1';
                                    else
                                        if start_c_raz = x"02" then
                                            raz_chn <= '0';
                                        end if;
                                    end if;
                                end if;
                                    start_c_raz <= start_c_raz -1; 
                        end if;
                    when x"B" =>     --dead time
                        if start_c_raz = x"00" then
                            BLKSM <= x"0";
                        else
                            start_c_raz <= start_c_raz -1; 
                        end if;                   
					when others =>
                        BLKSM <= x"0";
              end case;
    
                if reject_data ='1' then
                    BLKSM <= x"A"; 
                    start_c_raz <= x"06";                                    --avvia la procedura di reset dell'ASIC
                end if;

				if P_FRAME_ACK ="1" then
					P_FRAME_DV <= "0";				
				end if;

                if ValidationReset = '1' then
                    ValidationTimeoutCounter <= VALIDATION_REG(31 downto 16);
                    ValidationTimeout <= '0';
                else
                    if ValidationLatch = '1' then
                        ValidationTimeout <= '0';
                    else
                        if ValidationTimeoutCounter > 0 then
                            ValidationTimeoutCounter <= ValidationTimeoutCounter -1;
                        else
                            ValidationTimeout <= '1';
                        end if;
                    end if;
                end if;
                				
				
	            iValidation <= VALIDATION_IN(0);
                oValidation <= iValidation;
                if ValidationReset = '1' then
                    ValidationLatch <= '0';
                else
                    if (iValidation = '1' and oValidation = '0' and VALIDATION_REG(4) = '1') or (iValidation = '1' and VALIDATION_REG(4) = '0')   then
                        if TriggerLatch = '1' then
                            ValidationLatch <= '1';
                        else
                            if SW_VETO(0) = '0' and VALIDATION_REG(2) = '1'  then
                                P_FRAME_DV <= "1";
                                P_DV <= "1";
                                COUNTER_VALIDATION <= ValidationCounter;
                                FLAGS <= x"00000003";
                            end if;
                        end if;
                        ValidationCounter <=ValidationCounter +1; 

                    end if;
                end if;
                
                if RUNRESET(0) = '1' then
                    ValidationCounter <= (others => '0');
                    TriggerCounter <=  (others => '0');
                end if;
                
                if (iA_trigger_logic = '1' and oA_trigger_logic = '0') then
                    TriggerCounter <= TriggerCounter +1;
                end if;
            end if;
        end process;
    end block;
end Behavioral;
