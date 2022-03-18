// Copyright 1986-2017 Xilinx, Inc. All Rights Reserved.
// --------------------------------------------------------------------------------
// Tool Version: Vivado v.2017.4 (lin64) Build 2086221 Fri Dec 15 20:54:30 MST 2017
// Date        : Thu Mar 17 16:33:39 2022
// Host        : 5e51b3163f10 running 64-bit NIbuntu 16.04.7 LTS
// Command     : write_verilog -force -mode synth_stub
//               /home/utente/projects/CitirocRedoutFullV/CitirocRedoutFullV.srcs/sources_1/ip/fast_clock/fast_clock_stub.v
// Design      : fast_clock
// Purpose     : Stub declaration of top-level module interface
// Device      : xc7k160tffg676-2
// --------------------------------------------------------------------------------

// This empty module with port declaration file causes synthesis tools to infer a black box for IP.
// The synthesis directives are for Synopsys Synplify support to prevent IO buffer insertion.
// Please paste the declaration into a Verilog source file or add the file as an additional source.
module fast_clock(clk_100, clk_200, clk_250, clk_250_90, clk_500, 
  clk_500_90, reset, locked, clk_in1)
/* synthesis syn_black_box black_box_pad_pin="clk_100,clk_200,clk_250,clk_250_90,clk_500,clk_500_90,reset,locked,clk_in1" */;
  output clk_100;
  output clk_200;
  output clk_250;
  output clk_250_90;
  output clk_500;
  output clk_500_90;
  input reset;
  output locked;
  input clk_in1;
endmodule
