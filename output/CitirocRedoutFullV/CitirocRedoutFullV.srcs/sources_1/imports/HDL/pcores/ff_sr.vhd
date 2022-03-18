------------------------------------------------------------------
--						Nuclear Instruments						--
--																--
--							SciCompiler							--
--																--
--	Module:				FLIP FLOP SET RESET       				--
--	Version:			1.0										--
--	Creation Data:		13-07-2017								--
--																--
--																--
------------------------------------------------------------------

library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.STD_LOGIC_ARITH.ALL;
use IEEE.STD_LOGIC_UNSIGNED.ALL;
use IEEE.STD_LOGIC_MISC.ALL;
--Library UNISIM;
--use UNISIM.vcomponents.all;


entity FF_SR is
  port (
	CE : IN STD_LOGIC_VECTOR (0 DOWNTO 0);
	RESET : IN STD_LOGIC_VECTOR (0 DOWNTO 0);
	SET : IN STD_LOGIC_VECTOR (0 DOWNTO 0);
	PORT_OUT: OUT STD_LOGIC_VECTOR(0 DOWNTO 0)
	);
end;


architecture Behavioral of FF_SR is

begin

	ff_set_reset: process(SET,RESET)
	begin
        if RESET(0) = '1' and CE = "1" then
            PORT_OUT <= "0"; 
        else
            if rising_edge(SET(0)) and CE = "1"  then
              PORT_OUT <=  "1";
            end if;
        end if;
    end process;
end Behavioral; 