-- Copyright 1986-2017 Xilinx, Inc. All Rights Reserved.
-- --------------------------------------------------------------------------------
-- Tool Version: Vivado v.2017.4 (lin64) Build 2086221 Fri Dec 15 20:54:30 MST 2017
-- Date        : Thu Mar 17 16:33:40 2022
-- Host        : 5e51b3163f10 running 64-bit NIbuntu 16.04.7 LTS
-- Command     : write_vhdl -force -mode synth_stub
--               /home/utente/projects/CitirocRedoutFullV/CitirocRedoutFullV.srcs/sources_1/ip/fast_clock/fast_clock_stub.vhdl
-- Design      : fast_clock
-- Purpose     : Stub declaration of top-level module interface
-- Device      : xc7k160tffg676-2
-- --------------------------------------------------------------------------------
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

entity fast_clock is
  Port ( 
    clk_100 : out STD_LOGIC;
    clk_200 : out STD_LOGIC;
    clk_250 : out STD_LOGIC;
    clk_250_90 : out STD_LOGIC;
    clk_500 : out STD_LOGIC;
    clk_500_90 : out STD_LOGIC;
    reset : in STD_LOGIC;
    locked : out STD_LOGIC;
    clk_in1 : in STD_LOGIC
  );

end fast_clock;

architecture stub of fast_clock is
attribute syn_black_box : boolean;
attribute black_box_pad_pin : string;
attribute syn_black_box of stub : architecture is true;
attribute black_box_pad_pin of stub : architecture is "clk_100,clk_200,clk_250,clk_250_90,clk_500,clk_500_90,reset,locked,clk_in1";
begin
end;
