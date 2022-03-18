--- ========================================================================
-- ****************************************************************************
-- Company:         CAEN SpA - Viareggio - Italy
-- Model:           FERS-A5202
-- FPGA Proj. Name: FERS
-- Device:
-- Author:          Carlo Tintori
-- Date:            Jul 2019
-- ----------------------------------------------------------------------------
-- Description:     I2C controller for DAC MCP4726 and HV module A7585
-- ****************************************************************************

library ieee;
use ieee.std_logic_1164.all;
use ieee.std_logic_misc.all;
use ieee.numeric_std.all;


entity DT5550W_iic is
  port(
		clk                  : in     std_logic; -- system clock
		reset                : in     std_logic; -- global reset (active high)
		i2c_sda              : inout  std_logic; -- I2C data
		i2c_scl              : inout    std_logic; -- I2C clock
		i2c_fail             : out    std_logic; -- I2C fail (ack = 0)
		i2c_busy             : out    std_logic; -- I2C busy (transaction in progress)
		
		REG_IIC_STATUS       : out    std_logic_vector(31 downto 0);
		
		REG_HV_STATUS_RD 	 : out std_logic_vector (31 downto 0);
		REG_HV_OUTV_RD 		 : out std_logic_vector (31 downto 0);
		REG_HV_IOUT_RD		 : out std_logic_vector (31 downto 0);
		REG_HV_TEMP_RD 		 : out std_logic_vector (31 downto 0);
		REG_HV_VTARGET_RD 	 : out std_logic_vector (31 downto 0);
		REG_HV_AVTARGET_RD 	 : out std_logic_vector (31 downto 0);
		
		REG_ON_OFF_WR 	 			: in std_logic_vector (31 downto 0);
		REG_HV_EMERGENCY		    : in std_logic_vector (31 downto 0);
		REG_HV_SET_VOLTAGE_WR 	 	: in std_logic_vector (31 downto 0);
		REG_HV_ENABLE_TCOMP_WR 	 	: in std_logic_vector (31 downto 0);
		REG_HV_T_M_WR 	 			: in std_logic_vector (31 downto 0);
		REG_HV_T_Q_WR 	 			: in std_logic_vector (31 downto 0);
		REG_HV_TCOMP_COEF_WR 	 	: in std_logic_vector (31 downto 0);
		REG_HV_MAX_I_WR 	 		: in std_logic_vector (31 downto 0);
		REG_RAMP_SPEED_WR 	 		: in std_logic_vector (31 downto 0);
		REG_HV_MAX_V_WR 	 		: in std_logic_vector (31 downto 0);
		
		INT_ON_OFF_WR 	 			: in std_logic_vector (0 downto 0);
		INT_HV_EMERGENCY		    : in std_logic_vector (0 downto 0);
		INT_HV_SET_VOLTAGE_WR 	 	: in std_logic_vector (0 downto 0);
		INT_HV_ENABLE_TCOMP_WR 	 	: in std_logic_vector (0 downto 0);
		INT_HV_T_M_WR 	 			: in std_logic_vector (0 downto 0);
		INT_HV_T_Q_WR 	 			: in std_logic_vector (0 downto 0);
		INT_HV_TCOMP_COEF_WR 	 	: in std_logic_vector (0 downto 0);
		INT_HV_MAX_I_WR 	 		: in std_logic_vector (0 downto 0);
		INT_RAMP_SPEED_WR 	 		: in std_logic_vector (0 downto 0);
		INT_HV_MAX_V_WR 	 		: in std_logic_vector (0 downto 0);
		INT_EEPROM_WR 	    		: in std_logic_vector (0 downto 0);

		REG_TEMP_SENS_READ_1		: out std_logic_vector (31 downto 0);
		REG_TEMP_SENS_READ_2		: out std_logic_vector (31 downto 0);
		
		REG_EEPROM_WR               : in std_logic_vector (31 downto 0);
		
		PGB_EEPROM_KEY 				: out std_logic_vector (31 downto 0);
		PGB_REG_MODEL 				: out std_logic_vector (31 downto 0);
		PGB_BOARD_SN 				: out std_logic_vector (31 downto 0);
		PGB_ASIC_COUNT 				: out std_logic_vector (31 downto 0)

      );
end DT5550W_iic;

architecture rtl of DT5550W_iic is

  type TYPE_SEQ_STATE  is (SEQ_IDLE, HV_ADDR, HV_INT_ADDR, HV_DATA_TYPE, HV_WAIT_R, HV_REP_ADDR, HV_DATA_B0, HV_DATA_B1, HV_DATA_B2, HV_DATA_B3,
							TEMP_SENS_R1, TEMP_SENS_R2, TEMP_SENS_R3, TEMP_SENS_R4, TEMP_SENS_R5, TEMP_SENS_R6,
							EEPROM_R1, EEPROM_R2, EEPROM_R3, EEPROM_R4, EEPROM_R5, EEPROM_R6,
							EEPROM_WR1, EEPROM_WR2, EEPROM_WR3,
							CORE_WAIT
  );
  signal state_seq    : TYPE_SEQ_STATE;
  signal state_seq_next    : TYPE_SEQ_STATE;
  --type TYPE_I2C_STATE  is (I2C_IDLE, I2C_START1, I2C_START2, I2C_START3, I2C_WDATA1, I2C_WDATA2, I2C_WDATA3, I2C_RDATA1, I2C_RDATA2, I2C_RDATA3, 
  --                         I2C_ACK1, I2C_ACK2, I2C_ACK3, I2C_ACK4, I2C_STOP1, I2C_STOP2, I2C_STOP3, I2C_WAIT1, I2C_WAIT2, I2C_WAIT3, I2C_WAIT);
  --signal state_i2c    : TYPE_I2C_STATE;

  --signal i2c_cnt        : unsigned(8 downto 0); 
  --signal wait_cnt       : unsigned(15 downto 0) := (others => '0'); 
  --signal bit_cnt        : unsigned(3 downto 0); 
  signal i2c_rbyte      : std_logic_vector(7 downto 0); 
  signal i2c_wbyte      : std_logic_vector(7 downto 0); 
  --signal scl            : std_logic; 
  --signal sda            : std_logic; 
  signal ack            : std_logic; 
  --signal ack_all        : std_logic; 
  --signal scl_oe         : std_logic; 
  --signal sda_oe         : std_logic; 

--  signal i2c_docyc      : std_logic;  -- make an i2c cycle (1 byte read or write)
--  signal i2c_send_start : std_logic;  -- i2c cycle must begin with a start (or restart) bit
--  signal i2c_send_stop  : std_logic;  -- i2c cycle must end with a stop bit
--	signal i2c_done       : std_logic;  -- i2c cycle done (1 byte transferred)
  signal i2c_acks       : std_logic;  -- OR of the ACKs in a sequence of N bytes
  signal i2c_rnw        : std_logic;  -- i2c byte R or W cycle (Read=1, Write=0)
--  signal i2c_last       : std_logic;  -- last byte of a read sequence (no ACK)
  signal hv_rnw_cyc     : std_logic;  -- HV Read/Write reg (Read=1: seq of 9 bytes, Write=0: seq of 7 bytes))

  --signal i2c_stop_cnt   : unsigned(3 downto 0) := (others => '0');

  --constant I2C_PERIOD   : unsigned(i2c_cnt'range) := to_unsigned(127, i2c_cnt'length);  -- I2C rate = 400 kHz = 2.5 uS (1 clock cycle = 3 FSM steps)  --> MAX: 511 is ok
  
  
  signal HV_READ_TIMEOUT : integer := 125000000;
  signal TEMP_SENS_TIMEOUT : integer := 125000000;
  signal BOARDINFO_TIMEOUT : integer := 0;
  

	signal	l_INT_ON_OFF_WR 	 		:  std_logic := '0';
	signal	l_INT_HV_EMERGENCY		    :  std_logic := '0';
	signal	l_INT_HV_SET_VOLTAGE_WR 	:  std_logic := '0';
	signal	l_INT_HV_ENABLE_TCOMP_WR 	:  std_logic := '0';
	signal	l_INT_HV_T_M_WR 	 		:  std_logic := '0';
	signal	l_INT_HV_T_Q_WR 	 		:  std_logic := '0';
	signal	l_INT_HV_TCOMP_COEF_WR 	 	:  std_logic := '0';
	signal	l_INT_HV_MAX_I_WR 	 		:  std_logic := '0';
	signal	l_INT_RAMP_SPEED_WR 	 	:  std_logic := '0';
	signal	l_INT_HV_MAX_V_WR 	 		:  std_logic := '0';
	signal  l_INT_EEPROM_WR		        :  std_logic := '0';
		  
	signal  HV_READ_STEP : std_logic_vector (7 downto 0) := x"00";
	signal  HV_REG_ADDRESS : std_logic_vector (7 downto 0) := x"00";
	signal  TEMP_SENS_STEP : std_logic_vector (7 downto 0) := x"00";
	signal  EEPROM_READ_ADDR : std_logic_vector (7 downto 0) := x"00";
	signal  EEPROM_ADDR : std_logic_vector (7 downto 0) := x"00";
	signal  HV_REG_DATA_RD : std_logic_vector (31 downto 0) := x"00000000";
	signal  HV_REG_DATA_WR : std_logic_vector (31 downto 0) := x"00000000";
	
	signal EEPROM_DATA_WR : std_logic_vector(7 downto 0);
    signal EEPROM_ADDR_WR : std_logic_vector(7 downto 0);
                
	
  
  signal HV_REG_ADDR	: std_logic_vector (7 downto 0) := x"00";
  signal HV_REG_DATA	: std_logic_vector (31 downto 0) := x"00000000";
  signal TEMP_SENS_ADDR	: std_logic_vector (7 downto 0) := x"00";
  
  signal TEMP_SENS_READ : std_logic_vector (15 downto 0) := x"0000";
  
  signal eeprom_byte : integer range 0 to 63 := 0;
  signal EEPROM_DATA_BUFFER : std_logic_vector(16*8-1 downto 0);
  
signal IIC_exec : std_logic := '0';
signal IIC_busy : std_logic := '0';
signal IIC_ack_error : std_logic := '0';
signal IIC_devaddress : std_logic_vector (7 downto 0) := x"00";
  
  attribute mark_debug : string;  
  
COMPONENT i2c_master_andrea IS
  GENERIC(
    input_clk : INTEGER := 125_000_000; --input clock speed from user logic in Hz
    bus_clk   : INTEGER := 400_000);   --speed the i2c bus (scl) will run at in Hz
  PORT(
    clk       : IN     STD_LOGIC;                    --system clock
    reset_n   : IN     STD_LOGIC;                    --active low reset
    ena       : IN     STD_LOGIC;                    --latch in command
    addr      : IN     STD_LOGIC_VECTOR(6 DOWNTO 0); --address of target slave
    rw        : IN     STD_LOGIC;                    --'0' is write, '1' is read
    data_wr   : IN     STD_LOGIC_VECTOR(7 DOWNTO 0); --data to write to slave
    busy      : OUT    STD_LOGIC;                    --indicates transaction in progress
    data_rd   : OUT    STD_LOGIC_VECTOR(7 DOWNTO 0); --data read from slave
    ack_error : BUFFER STD_LOGIC;                    --flag if improper acknowledge from slave
    sda       : INOUT  STD_LOGIC;                    --serial data output of i2c bus
    scl       : INOUT  STD_LOGIC);                   --serial clock output of i2c bus
END COMPONENT;


  
  -- attribute mark_debug of state_seq         : signal is "TRUE";
  -- attribute mark_debug of i2c_wbyte         : signal is "TRUE";
  -- attribute mark_debug of i2c_docyc         : signal is "TRUE";
  -- attribute mark_debug of i2c_busy          : signal is "TRUE";
  -- attribute mark_debug of state_i2c         : signal is "TRUE";
  -- attribute mark_debug of scl               : signal is "TRUE";
  -- attribute mark_debug of sda               : signal is "TRUE";
  -- attribute mark_debug of i2c_rdata         : signal is "TRUE";
  -- attribute mark_debug of i2c_rbyte         : signal is "TRUE";
  
begin

--  i2c_scl  <= scl when scl_oe = '1' else 'Z';
--  i2c_sda  <= sda when sda_oe = '1' else 'Z';
  i2c_fail <= i2c_acks;


  -- *********************************************
  -- I2C FSM
  -- *********************************************
  

iic_master : i2c_master_andrea
  PORT MAP(
    clk       => clk,
    reset_n   => '1',
    ena       => IIC_exec,
    addr      => IIC_devaddress(6 downto 0),
    rw        => i2c_rnw,
    data_wr   => i2c_wbyte,
    busy      => IIC_busy,
    data_rd   => i2c_rbyte,
    ack_error => IIC_ack_error,
    sda       => i2c_sda,
    scl       => i2c_scl);

ack <= not IIC_ack_error;


  process(clk)
  begin
    if rising_edge(clk) then
    
      if reset = '1' then
--        scl            <= '1'; 
--        sda            <= '1';
--        ack            <= '0';
--        scl_oe         <= '0';
--        sda_oe         <= '0';
--        i2c_done       <= '0';
        i2c_acks       <= '0';
        i2c_rnw        <= '0';
--        i2c_busy       <= '1';
        hv_rnw_cyc     <= '0';
        i2c_wbyte      <= (others => '0');
--        i2c_cnt        <= (others => '0');
--        bit_cnt        <= (others => '0');
--        wait_cnt       <= (others => '0');
--        i2c_stop_cnt   <= (others => '0');
        state_seq      <= SEQ_IDLE;
--        state_i2c      <= I2C_IDLE;
      else  
	  
		if INT_ON_OFF_WR(0) = '1' then
			l_INT_ON_OFF_WR <= '1';
		end if;	
		if INT_HV_EMERGENCY(0) = '1' then
			l_INT_HV_EMERGENCY <= '1';
		end if;	
		if INT_HV_SET_VOLTAGE_WR(0) = '1' then
			l_INT_HV_SET_VOLTAGE_WR <= '1';
		end if;	
		if INT_HV_ENABLE_TCOMP_WR(0) = '1' then
			l_INT_HV_ENABLE_TCOMP_WR <= '1';
		end if;	
		if INT_HV_T_M_WR(0) = '1' then
			l_INT_HV_T_M_WR <= '1';
		end if;	
		if INT_HV_T_Q_WR(0) = '1' then
			l_INT_HV_T_Q_WR <= '1';
		end if;	
		if INT_HV_TCOMP_COEF_WR(0) = '1' then
			l_INT_HV_TCOMP_COEF_WR <= '1';
		end if;	
		if INT_HV_MAX_I_WR(0) = '1' then
			l_INT_HV_MAX_I_WR <= '1';
		end if;	
		if INT_RAMP_SPEED_WR(0) = '1' then
			l_INT_RAMP_SPEED_WR <= '1';
		end if;	
		if INT_HV_MAX_V_WR(0) = '1' then
			l_INT_HV_MAX_V_WR <= '1';
		end if;		  
		
		if INT_EEPROM_WR(0) = '1' then
            l_INT_EEPROM_WR <= '1';
        end if;    		

        if (state_seq = SEQ_IDLE) THEN
            REG_IIC_STATUS(0) <= '1';
        else
            REG_IIC_STATUS(0) <= '0';
        end if;
		--IIC_exec <= '0';
        --i2c_docyc      <= '0';
--        wait_cnt <= wait_cnt + 1;
        case state_seq is
        
          when SEQ_IDLE =>
--            i2c_wbyte  <= (others => '0');
--            i2c_rnw   <= '0';

			--if state_i2c = I2C_IDLE then
				if BOARDINFO_TIMEOUT = 0 then
					IIC_devaddress <= x"54";   					
					state_seq <= EEPROM_R1;
					BOARDINFO_TIMEOUT <= 125000000;
				
				elsif TEMP_SENS_TIMEOUT = 0 then
					 case TEMP_SENS_STEP is 
						 when x"00" =>
							 IIC_devaddress <= x"48";   
							 state_seq <= TEMP_SENS_R1;
							 TEMP_SENS_STEP <= x"01";
						 when x"01" =>
							 REG_TEMP_SENS_READ_1 <=x"00000" & TEMP_SENS_READ(7 downto 0) & TEMP_SENS_READ(11 downto 8) ;
							 IIC_devaddress <= x"4A";
							 state_seq <= TEMP_SENS_R1;						
							 TEMP_SENS_STEP <= x"02";
						 when x"02" =>
							 REG_TEMP_SENS_READ_2 <=x"00000" & TEMP_SENS_READ(7 downto 0) & TEMP_SENS_READ(11 downto 8);
							 TEMP_SENS_STEP <= x"00";
							 TEMP_SENS_TIMEOUT <= 120000000;
							
						 when others => 
							 TEMP_SENS_STEP <= x"00";
					 end case;
					
				elsif HV_READ_TIMEOUT = 0 then
					IIC_devaddress <= x"73";    
					state_seq <= HV_ADDR; 
					HV_REG_ADDRESS <= HV_READ_STEP;
					hv_rnw_cyc <= '1'; 
					case HV_READ_STEP is
						when x"00" =>		-- HV STATUS
							HV_READ_STEP <= x"E7";
							
						when x"E7" =>		-- VOUT
							if HV_REG_DATA_RD = x"00000000" then
								REG_HV_STATUS_RD(0) <= '0';	
							else
								REG_HV_STATUS_RD(0) <= '1';	
							end if;
							HV_READ_STEP <= x"E8";
							
						when x"E8" =>		--IOUT
							REG_HV_OUTV_RD <= HV_REG_DATA_RD;
							HV_READ_STEP <= x"EA";
							
						when x"EA" =>		--TEMPERATURE
							REG_HV_IOUT_RD <= HV_REG_DATA_RD;
							HV_READ_STEP <= x"EB";						

						when x"EB" =>		--V TARGET
							REG_HV_TEMP_RD <= HV_REG_DATA_RD;
							HV_READ_STEP <= x"EC";						

						when x"EC" =>		--ACTUAL TARGET
							REG_HV_VTARGET_RD <= HV_REG_DATA_RD;
							HV_READ_STEP <= x"F9";						

						when x"F9" =>		--V COMPLIANCE ON
							REG_HV_AVTARGET_RD <= HV_REG_DATA_RD;
							HV_READ_STEP <= x"FA";						

						when x"FA" =>		--I COMPLIANCE ON
							if HV_REG_DATA_RD = x"00000000" then
								REG_HV_STATUS_RD(1) <= '0';	
							else
								REG_HV_STATUS_RD(1) <= '1';	
							end if;
							HV_READ_STEP <= x"FB";
							
						when x"FB" =>		--DUMMY
							if HV_REG_DATA_RD = x"00000000" then
								REG_HV_STATUS_RD(2) <= '0';	
							else
								REG_HV_STATUS_RD(2) <= '1';	
							end if;						
							HV_READ_STEP <= x"00";
							HV_READ_TIMEOUT <= 20000000;
							
						when others =>
							HV_READ_STEP <= x"00";
					end case;
					
				
				else
					TEMP_SENS_TIMEOUT <= TEMP_SENS_TIMEOUT -1;
					HV_READ_TIMEOUT <= HV_READ_TIMEOUT -1;
					if l_INT_ON_OFF_WR = '1' then
						l_INT_ON_OFF_WR <= '0';
						hv_rnw_cyc <= '0'; 
						IIC_devaddress <= x"73";  						
						state_seq <= HV_ADDR; 
						if REG_ON_OFF_WR(0) = '1' then
							HV_REG_DATA_WR <= x"00002710";
						else
							HV_REG_DATA_WR <= x"00000000";
						end if;
						HV_REG_ADDRESS <= x"00";
					elsif l_INT_HV_EMERGENCY = '1' then
						l_INT_HV_EMERGENCY <= '0';
						hv_rnw_cyc <= '0'; 
						IIC_devaddress <= x"73";  	                                                                                                 
						state_seq <= HV_ADDR; 
						HV_REG_DATA_WR <= x"00002710";
						HV_REG_ADDRESS <= x"1F";
					elsif l_INT_HV_SET_VOLTAGE_WR = '1' then --write HV voltage
						l_INT_HV_SET_VOLTAGE_WR <= '0';
						hv_rnw_cyc <= '0'; 
						IIC_devaddress <= x"73";  	
						state_seq <= HV_ADDR; 
						HV_REG_DATA_WR <= REG_HV_SET_VOLTAGE_WR;
						HV_REG_ADDRESS <= x"02";		
					elsif l_INT_HV_ENABLE_TCOMP_WR = '1' then --write Enable temperature compensation voltage
						l_INT_HV_ENABLE_TCOMP_WR <= '0';
						hv_rnw_cyc <= '0'; 
						IIC_devaddress <= x"73";  	
						state_seq <= HV_ADDR; 
						if REG_HV_ENABLE_TCOMP_WR(0) = '1' then
							HV_REG_DATA_WR <= x"00004E20";
						else
							HV_REG_DATA_WR <= x"00000000";
						end if;
						HV_REG_ADDRESS <= x"01";				
					elsif l_INT_HV_T_M_WR = '1' then--write HV thermometer M coefficient
						l_INT_HV_T_M_WR <= '0';
						hv_rnw_cyc <= '0'; 
						IIC_devaddress <= x"73";  	
						state_seq <= HV_ADDR; 
						HV_REG_DATA_WR <= REG_HV_T_M_WR;
						HV_REG_ADDRESS <= x"08";			
					elsif l_INT_HV_T_Q_WR = '1' then --write HV thermometer Q coefficient
						l_INT_HV_T_Q_WR <= '0';
						hv_rnw_cyc <= '0'; 
						IIC_devaddress <= x"73";  	
						state_seq <= HV_ADDR; 
						HV_REG_DATA_WR <= REG_HV_T_Q_WR;
						HV_REG_ADDRESS <= x"09";			
					elsif l_INT_HV_TCOMP_COEF_WR = '1' then --write HV correction temperature coefficient
						l_INT_HV_TCOMP_COEF_WR <= '0';
						hv_rnw_cyc <= '0'; 
						IIC_devaddress <= x"73";  	
						state_seq <= HV_ADDR; 
						HV_REG_DATA_WR <= REG_HV_TCOMP_COEF_WR;
						HV_REG_ADDRESS <= x"1C";			
					elsif l_INT_HV_MAX_I_WR = '1' then --write HV max current
						l_INT_HV_MAX_I_WR <= '0';
						hv_rnw_cyc <= '0'; 
						IIC_devaddress <= x"73";  	
						state_seq <= HV_ADDR; 
						HV_REG_DATA_WR <= REG_HV_MAX_I_WR;
						HV_REG_ADDRESS <= x"06";			
					elsif l_INT_RAMP_SPEED_WR = '1' then --write HV ramp speed
						l_INT_RAMP_SPEED_WR <= '0';
						hv_rnw_cyc <= '0'; 
						IIC_devaddress <= x"73";  	
						state_seq <= HV_ADDR; 
						HV_REG_DATA_WR <= REG_RAMP_SPEED_WR;
						HV_REG_ADDRESS <= x"03";			
					elsif l_INT_HV_MAX_V_WR = '1' then --write HV max V
						l_INT_HV_MAX_V_WR <= '0';
						hv_rnw_cyc <= '0'; 
						IIC_devaddress <= x"73";  	                                                                                                   
						state_seq <= HV_ADDR; 
						HV_REG_DATA_WR <= REG_HV_MAX_V_WR;
						HV_REG_ADDRESS <= x"04";	
                    elsif l_INT_EEPROM_WR = '1' then --write HV max V
                        l_INT_EEPROM_WR <= '0';
                        hv_rnw_cyc <= '0'; 
                        IIC_devaddress <= x"54";                                                                                                         
                        state_seq <= EEPROM_WR1; 
                        EEPROM_DATA_WR <= REG_EEPROM_WR(7 downto 0);
                        EEPROM_ADDR_WR <= REG_EEPROM_WR(15 downto 8);				
					end if;				
				end if;
			--end if;
			
          -- HV control            
          when HV_ADDR =>
			IIC_exec <= '1';
			i2c_rnw <= '0';
			i2c_wbyte <= HV_REG_ADDRESS;
			state_seq <= CORE_WAIT;
            state_seq_next <= HV_INT_ADDR;                                      
            
            
          when HV_INT_ADDR =>
			IIC_exec <= '1';
			i2c_wbyte <= x"01";										     -- FIXED POINT DATA FORMAT
			i2c_rnw <= '0';
			if IIC_busy = '0' then
				i2c_acks  <= i2c_acks or not ack;                              -- fail signal to send out
    			state_seq <= CORE_WAIT;
                state_seq_next <= HV_DATA_TYPE;                                      
			end if;
            
            
          when HV_DATA_TYPE =>
		    IIC_exec <= '1';
			if hv_rnw_cyc = '1' then                                        -- if ti is a read reg
				i2c_rnw <= '1';
            else
				i2c_rnw <= '0';
                i2c_wbyte <= HV_REG_DATA_WR(7 downto 0);                   -- write byte0
            end if;      		  
			
			if IIC_busy = '0' then
				i2c_acks  <= i2c_acks or not ack;                              -- fail signal to send out
    			state_seq <= CORE_WAIT;
                state_seq_next <= HV_DATA_B0;                                      
			end if;
		  
            
            
          when HV_DATA_B0 =>   
		    IIC_exec <= '1';
			if hv_rnw_cyc = '1' then                                        -- if ti is a read reg
				i2c_rnw <= '1';
            else
				i2c_rnw <= '0';
                i2c_wbyte <= HV_REG_DATA_WR(15 downto 8);                   -- write byte0
            end if;      		  
				
			if IIC_busy = '0' then
				i2c_acks  <= i2c_acks or not ack;                              -- fail signal to send out
				HV_REG_DATA_RD(7 downto 0) <= i2c_rbyte;
                state_seq <= CORE_WAIT;
                state_seq_next <= HV_DATA_B1;                                      
			end if;
            
          when HV_DATA_B1 =>
		    IIC_exec <= '1';
			if hv_rnw_cyc = '1' then                                        -- if ti is a read reg
				i2c_rnw <= '1';
            else
				i2c_rnw <= '0';
                i2c_wbyte <= HV_REG_DATA_WR(23 downto 16);                   -- write byte0
            end if;      		  
				
			if IIC_busy = '0' then
				i2c_acks  <= i2c_acks or not ack;                              -- fail signal to send out
				HV_REG_DATA_RD(15 downto 8) <= i2c_rbyte;
                state_seq <= CORE_WAIT;
                state_seq_next <= HV_DATA_B2;                                      
			end if;
			
          when HV_DATA_B2 =>
		    IIC_exec <= '1';
			if hv_rnw_cyc = '1' then                                        -- if ti is a read reg
				i2c_rnw <= '1';
            else
				i2c_rnw <= '0';
                i2c_wbyte <= HV_REG_DATA_WR(31 downto 24);                   -- write byte0
            end if;      		  
				
			if IIC_busy = '0' then
				i2c_acks  <= i2c_acks or not ack;                              -- fail signal to send out
				HV_REG_DATA_RD(23 downto 16) <= i2c_rbyte;
                state_seq <= CORE_WAIT;
                state_seq_next <= HV_DATA_B3;                                      
			end if;

          when HV_DATA_B3 =>
		    IIC_exec <= '0';
			if hv_rnw_cyc = '1' then                                        -- if ti is a read reg
				i2c_rnw <= '1';
            else
				i2c_rnw <= '0';
            end if;  			
			
			if IIC_busy = '0' then
				i2c_acks  <= i2c_acks or not ack;                              -- fail signal to send out
				HV_REG_DATA_RD(31 downto 24) <= i2c_rbyte;                                      				
				state_seq <= SEQ_IDLE;
			end if;			

			
           when TEMP_SENS_R1 =>
           	    IIC_exec <= '1';
                i2c_rnw <= '0';
                i2c_wbyte <= x"00";
                state_seq <= CORE_WAIT;
                state_seq_next <= TEMP_SENS_R2;   
            
           when TEMP_SENS_R2 =>
		        IIC_exec <= '1';
                i2c_rnw <= '1';
           
               if IIC_busy = '0' then
                   i2c_acks  <= i2c_acks or not ack;                              -- fail signal to send out
                   state_seq <= CORE_WAIT;
                   state_seq_next <= TEMP_SENS_R3;                                      
               end if;
                    
            
           when TEMP_SENS_R3 =>
		       IIC_exec <= '1';
               i2c_rnw <= '1';           
               if IIC_busy = '0' then
                    TEMP_SENS_READ(7 downto 0) <= i2c_rbyte;
                    i2c_acks  <= i2c_acks or not ack;                              -- fail signal to send out
                    state_seq <= CORE_WAIT;
                    state_seq_next <= TEMP_SENS_R4;                                      
                end if;                

           when TEMP_SENS_R4 =>
		       IIC_exec <= '0';
               i2c_rnw <= '1';           
               if IIC_busy = '0' then
                    TEMP_SENS_READ(15 downto 8) <= i2c_rbyte;
                    i2c_acks  <= i2c_acks or not ack;                              -- fail signal to send out
                    state_seq <= SEQ_IDLE;                                     
                end if;                

              
           when EEPROM_R1 =>
           	    IIC_exec <= '1';
                i2c_rnw <= '0';
                i2c_wbyte <= x"00";
                state_seq <= CORE_WAIT;
                state_seq_next <= EEPROM_R2; 

           when EEPROM_R2 =>
		        IIC_exec <= '1';
                i2c_rnw <= '1';
           
               if IIC_busy = '0' then
                   i2c_acks  <= i2c_acks or not ack;                              -- fail signal to send out
                   state_seq <= CORE_WAIT;
                   state_seq_next <= EEPROM_R3; 
				   eeprom_byte <= 0;				   
               end if;
			   
           when EEPROM_R3 =>
		       IIC_exec <= '1';
               i2c_rnw <= '1';           
               if IIC_busy = '0' then
                    EEPROM_DATA_BUFFER((eeprom_byte+1)*8-1 downto (eeprom_byte)*8) <= i2c_rbyte;   
                    i2c_acks  <= i2c_acks or not ack;                              -- fail signal to send out
                    state_seq <= CORE_WAIT;
					eeprom_byte <= eeprom_byte +1;
					if eeprom_byte = 14 then					
						state_seq_next <= EEPROM_R4;         	
					else
						state_seq_next <= EEPROM_R3;         
					end if;
                end if;  			 


           when EEPROM_R4 =>
		       IIC_exec <= '0';
               i2c_rnw <= '1';           
               if IIC_busy = '0' then
                    EEPROM_DATA_BUFFER((eeprom_byte+1)*8-1 downto (eeprom_byte)*8) <= i2c_rbyte;   
                    i2c_acks  <= i2c_acks or not ack;                              -- fail signal to send out
                    state_seq <= SEQ_IDLE; 

					PGB_EEPROM_KEY <= EEPROM_DATA_BUFFER( (4)*8 -1 downto 0);
					PGB_REG_MODEL  <= x"00" & EEPROM_DATA_BUFFER( (4+3)*8 -1 downto (0+4)*8);
					PGB_ASIC_COUNT <= x"000000" & EEPROM_DATA_BUFFER( (4+4)*8 -1 downto (4+3)*8);
					PGB_BOARD_SN <= EEPROM_DATA_BUFFER( (4+4+4)*8 -1 downto (4+4)*8);					
					
                end if;  
                
            when EEPROM_WR1 =>
                IIC_exec <= '1';
                i2c_rnw <= '0';
                i2c_wbyte <= EEPROM_ADDR_WR;
                state_seq <= CORE_WAIT;
                state_seq_next <= EEPROM_WR2;                                      
            
            when EEPROM_WR2 =>
                IIC_exec <= '1';
                i2c_wbyte <= EEPROM_DATA_WR;                                             -- FIXED POINT DATA FORMAT
                i2c_rnw <= '0';
                if IIC_busy = '0' then
                    i2c_acks  <= i2c_acks or not ack;                              -- fail signal to send out
                    state_seq <= CORE_WAIT;
                    state_seq_next <= EEPROM_WR3;                                      
                end if;
            
            when EEPROM_WR3 =>
                IIC_exec <= '0';
                i2c_rnw <= '0';           
                if IIC_busy = '0' then
                     i2c_acks  <= i2c_acks or not ack;                              -- fail signal to send out
                     state_seq <= SEQ_IDLE; 
                 end if;              
            
            when CORE_WAIT =>
                if IIC_busy = '1' then
                    state_seq <= state_seq_next;
                end if;
            
            when others => 
                state_seq <= SEQ_IDLE;
        end case;    
                
      end if;
    end if;  
  end process;  

end rtl;




LIBRARY ieee;
USE ieee.std_logic_1164.all;
USE ieee.std_logic_unsigned.all;

ENTITY i2c_master_andrea IS
  GENERIC(
    input_clk : INTEGER := 125_000_000; --input clock speed from user logic in Hz
    bus_clk   : INTEGER := 400_000);   --speed the i2c bus (scl) will run at in Hz
  PORT(
    clk       : IN     STD_LOGIC;                    --system clock
    reset_n   : IN     STD_LOGIC;                    --active low reset
    ena       : IN     STD_LOGIC;                    --latch in command
    addr      : IN     STD_LOGIC_VECTOR(6 DOWNTO 0); --address of target slave
    rw        : IN     STD_LOGIC;                    --'0' is write, '1' is read
    data_wr   : IN     STD_LOGIC_VECTOR(7 DOWNTO 0); --data to write to slave
    busy      : OUT    STD_LOGIC;                    --indicates transaction in progress
    data_rd   : OUT    STD_LOGIC_VECTOR(7 DOWNTO 0); --data read from slave
    ack_error : BUFFER STD_LOGIC;                    --flag if improper acknowledge from slave
    sda       : INOUT  STD_LOGIC;                    --serial data output of i2c bus
    scl       : INOUT  STD_LOGIC);                   --serial clock output of i2c bus
END i2c_master_andrea;

ARCHITECTURE logic OF i2c_master_andrea IS
  CONSTANT divider  :  INTEGER := (input_clk/bus_clk)/4; --number of clocks in 1/4 cycle of scl
  TYPE machine IS(ready, start, command, slv_ack1, wr, rd, slv_ack2, mstr_ack, stop); --needed states
  SIGNAL state         : machine;                        --state machine
  SIGNAL data_clk      : STD_LOGIC;                      --data clock for sda
  SIGNAL data_clk_prev : STD_LOGIC;                      --data clock during previous system clock
  SIGNAL scl_clk       : STD_LOGIC;                      --constantly running internal scl
  SIGNAL scl_ena       : STD_LOGIC := '0';               --enables internal scl to output
  SIGNAL sda_int       : STD_LOGIC := '1';               --internal sda
  SIGNAL sda_ena_n     : STD_LOGIC;                      --enables internal sda to output
  SIGNAL addr_rw       : STD_LOGIC_VECTOR(7 DOWNTO 0);   --latched in address and read/write
  SIGNAL data_tx       : STD_LOGIC_VECTOR(7 DOWNTO 0);   --latched in data to write to slave
  SIGNAL data_rx       : STD_LOGIC_VECTOR(7 DOWNTO 0);   --data received from slave
  SIGNAL bit_cnt       : INTEGER RANGE 0 TO 7 := 7;      --tracks bit number in transaction
  SIGNAL stretch       : STD_LOGIC := '0';               --identifies if slave is stretching scl
BEGIN

  --generate the timing for the bus clock (scl_clk) and the data clock (data_clk)
  PROCESS(clk, reset_n)
    VARIABLE count  :  INTEGER RANGE 0 TO divider*4;  --timing for clock generation
  BEGIN
    IF(reset_n = '0') THEN                --reset asserted
      stretch <= '0';
      count := 0;
    ELSIF(clk'EVENT AND clk = '1') THEN
      data_clk_prev <= data_clk;          --store previous value of data clock
      IF(count = divider*4-1) THEN        --end of timing cycle
        count := 0;                       --reset timer
      ELSIF(stretch = '0') THEN           --clock stretching from slave not detected
        count := count + 1;               --continue clock generation timing
      END IF;
      CASE count IS
        WHEN 0 TO divider-1 =>            --first 1/4 cycle of clocking
          scl_clk <= '0';
          data_clk <= '0';
        WHEN divider TO divider*2-1 =>    --second 1/4 cycle of clocking
          scl_clk <= '0';
          data_clk <= '1';
        WHEN divider*2 TO divider*3-1 =>  --third 1/4 cycle of clocking
          scl_clk <= '1';                 --release scl
          IF(scl = '0') THEN              --detect if slave is stretching clock
            stretch <= '1';
          ELSE
            stretch <= '0';
          END IF;
          data_clk <= '1';
        WHEN OTHERS =>                    --last 1/4 cycle of clocking
          scl_clk <= '1';
          data_clk <= '0';
      END CASE;
    END IF;
  END PROCESS;

  --state machine and writing to sda during scl low (data_clk rising edge)
  PROCESS(clk, reset_n)
  BEGIN
    IF(reset_n = '0') THEN                 --reset asserted
      state <= ready;                      --return to initial state
      busy <= '1';                         --indicate not available
      scl_ena <= '0';                      --sets scl high impedance
      sda_int <= '1';                      --sets sda high impedance
      ack_error <= '0';                    --clear acknowledge error flag
      bit_cnt <= 7;                        --restarts data bit counter
      data_rd <= "00000000";               --clear data read port
    ELSIF(clk'EVENT AND clk = '1') THEN
      IF(data_clk = '1' AND data_clk_prev = '0') THEN  --data clock rising edge
        CASE state IS
          WHEN ready =>                      --idle state
            IF(ena = '1') THEN               --transaction requested
              busy <= '1';                   --flag busy
              addr_rw <= addr & rw;          --collect requested slave address and command
              data_tx <= data_wr;            --collect requested data to write
              state <= start;                --go to start bit
            ELSE                             --remain idle
              busy <= '0';                   --unflag busy
              state <= ready;                --remain idle
            END IF;
          WHEN start =>                      --start bit of transaction
            busy <= '1';                     --resume busy if continuous mode
            sda_int <= addr_rw(bit_cnt);     --set first address bit to bus
            state <= command;                --go to command
          WHEN command =>                    --address and command byte of transaction
            IF(bit_cnt = 0) THEN             --command transmit finished
              sda_int <= '1';                --release sda for slave acknowledge
              bit_cnt <= 7;                  --reset bit counter for "byte" states
              state <= slv_ack1;             --go to slave acknowledge (command)
            ELSE                             --next clock cycle of command state
              bit_cnt <= bit_cnt - 1;        --keep track of transaction bits
              sda_int <= addr_rw(bit_cnt-1); --write address/command bit to bus
              state <= command;              --continue with command
            END IF;
          WHEN slv_ack1 =>                   --slave acknowledge bit (command)
            IF(addr_rw(0) = '0') THEN        --write command
              sda_int <= data_tx(bit_cnt);   --write first bit of data
              state <= wr;                   --go to write byte
            ELSE                             --read command
              sda_int <= '1';                --release sda from incoming data
              state <= rd;                   --go to read byte
            END IF;
          WHEN wr =>                         --write byte of transaction
            busy <= '1';                     --resume busy if continuous mode
            IF(bit_cnt = 0) THEN             --write byte transmit finished
              sda_int <= '1';                --release sda for slave acknowledge
              bit_cnt <= 7;                  --reset bit counter for "byte" states
              state <= slv_ack2;             --go to slave acknowledge (write)
            ELSE                             --next clock cycle of write state
              bit_cnt <= bit_cnt - 1;        --keep track of transaction bits
              sda_int <= data_tx(bit_cnt-1); --write next bit to bus
              state <= wr;                   --continue writing
            END IF;
          WHEN rd =>                         --read byte of transaction
            busy <= '1';                     --resume busy if continuous mode
            IF(bit_cnt = 0) THEN             --read byte receive finished
              IF(ena = '1' AND addr_rw = addr & rw) THEN  --continuing with another read at same address
                sda_int <= '0';              --acknowledge the byte has been received
              ELSE                           --stopping or continuing with a write
                sda_int <= '1';              --send a no-acknowledge (before stop or repeated start)
              END IF;
              bit_cnt <= 7;                  --reset bit counter for "byte" states
              data_rd <= data_rx;            --output received data
              state <= mstr_ack;             --go to master acknowledge
            ELSE                             --next clock cycle of read state
              bit_cnt <= bit_cnt - 1;        --keep track of transaction bits
              state <= rd;                   --continue reading
            END IF;
          WHEN slv_ack2 =>                   --slave acknowledge bit (write)
            IF(ena = '1') THEN               --continue transaction
              busy <= '0';                   --continue is accepted
              addr_rw <= addr & rw;          --collect requested slave address and command
              data_tx <= data_wr;            --collect requested data to write
              IF(addr_rw = addr & rw) THEN   --continue transaction with another write
                sda_int <= data_wr(bit_cnt); --write first bit of data
                state <= wr;                 --go to write byte
              ELSE                           --continue transaction with a read or new slave
                state <= start;              --go to repeated start
              END IF;
            ELSE                             --complete transaction
              state <= stop;                 --go to stop bit
            END IF;
          WHEN mstr_ack =>                   --master acknowledge bit after a read
            IF(ena = '1') THEN               --continue transaction
              busy <= '0';                   --continue is accepted and data received is available on bus
              addr_rw <= addr & rw;          --collect requested slave address and command
              data_tx <= data_wr;            --collect requested data to write
              IF(addr_rw = addr & rw) THEN   --continue transaction with another read
                sda_int <= '1';              --release sda from incoming data
                state <= rd;                 --go to read byte
              ELSE                           --continue transaction with a write or new slave
                state <= start;              --repeated start
              END IF;    
            ELSE                             --complete transaction
              state <= stop;                 --go to stop bit
            END IF;
          WHEN stop =>                       --stop bit of transaction
            busy <= '0';                     --unflag busy
            state <= ready;                  --go to idle state
        END CASE;    
      ELSIF(data_clk = '0' AND data_clk_prev = '1') THEN  --data clock falling edge
        CASE state IS
          WHEN start =>                  
            IF(scl_ena = '0') THEN                  --starting new transaction
              scl_ena <= '1';                       --enable scl output
              ack_error <= '0';                     --reset acknowledge error output
            END IF;
          WHEN slv_ack1 =>                          --receiving slave acknowledge (command)
            IF(sda /= '0' OR ack_error = '1') THEN  --no-acknowledge or previous no-acknowledge
              ack_error <= '1';                     --set error output if no-acknowledge
            END IF;
          WHEN rd =>                                --receiving slave data
            data_rx(bit_cnt) <= sda;                --receive current slave data bit
          WHEN slv_ack2 =>                          --receiving slave acknowledge (write)
            IF(sda /= '0' OR ack_error = '1') THEN  --no-acknowledge or previous no-acknowledge
              ack_error <= '1';                     --set error output if no-acknowledge
            END IF;
          WHEN stop =>
            scl_ena <= '0';                         --disable scl
          WHEN OTHERS =>
            NULL;
        END CASE;
      END IF;
    END IF;
  END PROCESS;  

  --set sda output
  WITH state SELECT
    sda_ena_n <= data_clk_prev WHEN start,     --generate start condition
                 NOT data_clk_prev WHEN stop,  --generate stop condition
                 sda_int WHEN OTHERS;          --set to internal sda signal    
      
  --set scl and sda outputs
  scl <= '0' WHEN (scl_ena = '1' AND scl_clk = '0') ELSE 'Z';
  sda <= '0' WHEN sda_ena_n = '0' ELSE 'Z';
  
END logic;
