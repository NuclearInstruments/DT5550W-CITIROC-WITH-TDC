
?
?No debug cores found in the current design.
Before running the implement_debug_core command, either use the Set Up Debug wizard (GUI mode)
or use the create_debug_core and connect_debug_core Tcl commands to insert debug cores into the design.
154*	chipscopeZ16-241h px? 
Q
Command: %s
53*	vivadotcl2 
place_design2default:defaultZ4-113h px? 
?
@Attempting to get a license for feature '%s' and/or device '%s'
308*common2"
Implementation2default:default2
xc7k160t2default:defaultZ17-347h px? 
?
0Got license for feature '%s' and/or device '%s'
310*common2"
Implementation2default:default2
xc7k160t2default:defaultZ17-349h px? 
P
Running DRC with %s threads
24*drc2
82default:defaultZ23-27h px? 
V
DRC finished with %s
79*	vivadotcl2
0 Errors2default:defaultZ4-198h px? 
e
BPlease refer to the DRC report (report_drc) for more information.
80*	vivadotclZ4-199h px? 
p
,Running DRC as a precondition to command %s
22*	vivadotcl2 
place_design2default:defaultZ4-22h px? 
P
Running DRC with %s threads
24*drc2
82default:defaultZ23-27h px? 
?
?CONFIG_VOLTAGE with Config Bank VCCO: The CONFIG_MODE property of current_design specifies a configuration mode (SPIx4) that uses pins in bank %s.  I/O standards used in this bank have a voltage requirement of 2.50.  However, the CONFIG_VOLTAGE for current_design is set to 1.8.  Ensure that your configuration voltage is compatible with the I/O standards in banks used by your configuration mode.  Refer to device configuration user guide for more information.    Pins used by config mode: B24 (IO_L1P_T0_D00_MOSI_14), A25 (IO_L1N_T0_D01_DIN_14), B22 (IO_L2P_T0_D02_14), A22 (IO_L2N_T0_D03_14), B25 (IO_L3P_T0_DQS_PUDC_B_14), and C23 (IO_L6P_T0_FCS_B_14)%s*DRC2.
 "
142default:default2default:default2(
 DRC|Pin Planning2default:default8ZCFGBVS-7h px? 
?
YReport rule limit reached: REQP-1839 rule limit reached: 20 violations have been found.%s*DRC29
 !DRC|DRC System|Rule limit reached2default:default8ZCHECK-3h px? 
?
YReport rule limit reached: REQP-1840 rule limit reached: 20 violations have been found.%s*DRC29
 !DRC|DRC System|Rule limit reached2default:default8ZCHECK-3h px? 
?
?RAMB36 async control check: The RAMB36E1 %s has an input control pin %s (net: %s) which is driven by a register (%s) that has an active asychronous set or reset. This may cause corruption of the memory contents and/or read values when the set/reset is asserted and is not analyzed by the default static timing analysis. It is suggested to eliminate the use of a set/reset to registers driving this RAMB pin or else use a synchronous reset in which the assertion of the reset is timed by default.%s*DRC2?
 "?
?FC/PAGEMEM/U0/inst_blk_mem_gen/gnbram.gnativebmg.native_blk_mem_gen/valid.cstr/ramloop[0].ram.r/prim_noinit.ram/DEVICE_7SERIES.NO_BMM_INFO.TRUE_DP.SIMPLE_PRIM36.ram	?FC/PAGEMEM/U0/inst_blk_mem_gen/gnbram.gnativebmg.native_blk_mem_gen/valid.cstr/ramloop[0].ram.r/prim_noinit.ram/DEVICE_7SERIES.NO_BMM_INFO.TRUE_DP.SIMPLE_PRIM36.ram2default:default2default:default2?
 "?
?FC/PAGEMEM/U0/inst_blk_mem_gen/gnbram.gnativebmg.native_blk_mem_gen/valid.cstr/ramloop[0].ram.r/prim_noinit.ram/DEVICE_7SERIES.NO_BMM_INFO.TRUE_DP.SIMPLE_PRIM36.ram/WEA[0]?FC/PAGEMEM/U0/inst_blk_mem_gen/gnbram.gnativebmg.native_blk_mem_gen/valid.cstr/ramloop[0].ram.r/prim_noinit.ram/DEVICE_7SERIES.NO_BMM_INFO.TRUE_DP.SIMPLE_PRIM36.ram/WEA[0]2default:default2default:default2?
 "?
vFC/PAGEMEM/U0/inst_blk_mem_gen/gnbram.gnativebmg.native_blk_mem_gen/valid.cstr/ramloop[0].ram.r/prim_noinit.ram/wea[0]sFC/PAGEMEM/U0/inst_blk_mem_gen/gnbram.gnativebmg.native_blk_mem_gen/valid.cstr/ramloop[0].ram.r/prim_noinit.ram/wea2default:default2default:default2?
 "?
|USBInterface/DATA_READ_FIFO/U0/inst_fifo_gen/gconvfifo.rf/grf.rf/gntv_or_sync_fifo.gl0.wr/gwas.gpf.wrpf/gpf1.prog_full_i_reg	|USBInterface/DATA_READ_FIFO/U0/inst_fifo_gen/gconvfifo.rf/grf.rf/gntv_or_sync_fifo.gl0.wr/gwas.gpf.wrpf/gpf1.prog_full_i_reg2default:default2default:default2B
 *DRC|Netlist|Instance|Required Pin|RAMB36E12default:default8Z	REQP-1839h px? 
?
?RAMB36 async control check: The RAMB36E1 %s has an input control pin %s (net: %s) which is driven by a register (%s) that has an active asychronous set or reset. This may cause corruption of the memory contents and/or read values when the set/reset is asserted and is not analyzed by the default static timing analysis. It is suggested to eliminate the use of a set/reset to registers driving this RAMB pin or else use a synchronous reset in which the assertion of the reset is timed by default.%s*DRC2?
 "?
?FC/PAGEMEM/U0/inst_blk_mem_gen/gnbram.gnativebmg.native_blk_mem_gen/valid.cstr/ramloop[0].ram.r/prim_noinit.ram/DEVICE_7SERIES.NO_BMM_INFO.TRUE_DP.SIMPLE_PRIM36.ram	?FC/PAGEMEM/U0/inst_blk_mem_gen/gnbram.gnativebmg.native_blk_mem_gen/valid.cstr/ramloop[0].ram.r/prim_noinit.ram/DEVICE_7SERIES.NO_BMM_INFO.TRUE_DP.SIMPLE_PRIM36.ram2default:default2default:default2?
 "?
?FC/PAGEMEM/U0/inst_blk_mem_gen/gnbram.gnativebmg.native_blk_mem_gen/valid.cstr/ramloop[0].ram.r/prim_noinit.ram/DEVICE_7SERIES.NO_BMM_INFO.TRUE_DP.SIMPLE_PRIM36.ram/WEA[1]?FC/PAGEMEM/U0/inst_blk_mem_gen/gnbram.gnativebmg.native_blk_mem_gen/valid.cstr/ramloop[0].ram.r/prim_noinit.ram/DEVICE_7SERIES.NO_BMM_INFO.TRUE_DP.SIMPLE_PRIM36.ram/WEA[1]2default:default2default:default2?
 "?
vFC/PAGEMEM/U0/inst_blk_mem_gen/gnbram.gnativebmg.native_blk_mem_gen/valid.cstr/ramloop[0].ram.r/prim_noinit.ram/wea[0]sFC/PAGEMEM/U0/inst_blk_mem_gen/gnbram.gnativebmg.native_blk_mem_gen/valid.cstr/ramloop[0].ram.r/prim_noinit.ram/wea2default:default2default:default2?
 "?
|USBInterface/DATA_READ_FIFO/U0/inst_fifo_gen/gconvfifo.rf/grf.rf/gntv_or_sync_fifo.gl0.wr/gwas.gpf.wrpf/gpf1.prog_full_i_reg	|USBInterface/DATA_READ_FIFO/U0/inst_fifo_gen/gconvfifo.rf/grf.rf/gntv_or_sync_fifo.gl0.wr/gwas.gpf.wrpf/gpf1.prog_full_i_reg2default:default2default:default2B
 *DRC|Netlist|Instance|Required Pin|RAMB36E12default:default8Z	REQP-1839h px? 
?
?RAMB36 async control check: The RAMB36E1 %s has an input control pin %s (net: %s) which is driven by a register (%s) that has an active asychronous set or reset. This may cause corruption of the memory contents and/or read values when the set/reset is asserted and is not analyzed by the default static timing analysis. It is suggested to eliminate the use of a set/reset to registers driving this RAMB pin or else use a synchronous reset in which the assertion of the reset is timed by default.%s*DRC2?
 "?
?FC/PAGEMEM/U0/inst_blk_mem_gen/gnbram.gnativebmg.native_blk_mem_gen/valid.cstr/ramloop[0].ram.r/prim_noinit.ram/DEVICE_7SERIES.NO_BMM_INFO.TRUE_DP.SIMPLE_PRIM36.ram	?FC/PAGEMEM/U0/inst_blk_mem_gen/gnbram.gnativebmg.native_blk_mem_gen/valid.cstr/ramloop[0].ram.r/prim_noinit.ram/DEVICE_7SERIES.NO_BMM_INFO.TRUE_DP.SIMPLE_PRIM36.ram2default:default2default:default2?
 "?
?FC/PAGEMEM/U0/inst_blk_mem_gen/gnbram.gnativebmg.native_blk_mem_gen/valid.cstr/ramloop[0].ram.r/prim_noinit.ram/DEVICE_7SERIES.NO_BMM_INFO.TRUE_DP.SIMPLE_PRIM36.ram/WEA[2]?FC/PAGEMEM/U0/inst_blk_mem_gen/gnbram.gnativebmg.native_blk_mem_gen/valid.cstr/ramloop[0].ram.r/prim_noinit.ram/DEVICE_7SERIES.NO_BMM_INFO.TRUE_DP.SIMPLE_PRIM36.ram/WEA[2]2default:default2default:default2?
 "?
vFC/PAGEMEM/U0/inst_blk_mem_gen/gnbram.gnativebmg.native_blk_mem_gen/valid.cstr/ramloop[0].ram.r/prim_noinit.ram/wea[0]sFC/PAGEMEM/U0/inst_blk_mem_gen/gnbram.gnativebmg.native_blk_mem_gen/valid.cstr/ramloop[0].ram.r/prim_noinit.ram/wea2default:default2default:default2?
 "?
|USBInterface/DATA_READ_FIFO/U0/inst_fifo_gen/gconvfifo.rf/grf.rf/gntv_or_sync_fifo.gl0.wr/gwas.gpf.wrpf/gpf1.prog_full_i_reg	|USBInterface/DATA_READ_FIFO/U0/inst_fifo_gen/gconvfifo.rf/grf.rf/gntv_or_sync_fifo.gl0.wr/gwas.gpf.wrpf/gpf1.prog_full_i_reg2default:default2default:default2B
 *DRC|Netlist|Instance|Required Pin|RAMB36E12default:default8Z	REQP-1839h px? 
?
?RAMB36 async control check: The RAMB36E1 %s has an input control pin %s (net: %s) which is driven by a register (%s) that has an active asychronous set or reset. This may cause corruption of the memory contents and/or read values when the set/reset is asserted and is not analyzed by the default static timing analysis. It is suggested to eliminate the use of a set/reset to registers driving this RAMB pin or else use a synchronous reset in which the assertion of the reset is timed by default.%s*DRC2?
 "?
?FC/PAGEMEM/U0/inst_blk_mem_gen/gnbram.gnativebmg.native_blk_mem_gen/valid.cstr/ramloop[0].ram.r/prim_noinit.ram/DEVICE_7SERIES.NO_BMM_INFO.TRUE_DP.SIMPLE_PRIM36.ram	?FC/PAGEMEM/U0/inst_blk_mem_gen/gnbram.gnativebmg.native_blk_mem_gen/valid.cstr/ramloop[0].ram.r/prim_noinit.ram/DEVICE_7SERIES.NO_BMM_INFO.TRUE_DP.SIMPLE_PRIM36.ram2default:default2default:default2?
 "?
?FC/PAGEMEM/U0/inst_blk_mem_gen/gnbram.gnativebmg.native_blk_mem_gen/valid.cstr/ramloop[0].ram.r/prim_noinit.ram/DEVICE_7SERIES.NO_BMM_INFO.TRUE_DP.SIMPLE_PRIM36.ram/WEA[3]?FC/PAGEMEM/U0/inst_blk_mem_gen/gnbram.gnativebmg.native_blk_mem_gen/valid.cstr/ramloop[0].ram.r/prim_noinit.ram/DEVICE_7SERIES.NO_BMM_INFO.TRUE_DP.SIMPLE_PRIM36.ram/WEA[3]2default:default2default:default2?
 "?
vFC/PAGEMEM/U0/inst_blk_mem_gen/gnbram.gnativebmg.native_blk_mem_gen/valid.cstr/ramloop[0].ram.r/prim_noinit.ram/wea[0]sFC/PAGEMEM/U0/inst_blk_mem_gen/gnbram.gnativebmg.native_blk_mem_gen/valid.cstr/ramloop[0].ram.r/prim_noinit.ram/wea2default:default2default:default2?
 "?
|USBInterface/DATA_READ_FIFO/U0/inst_fifo_gen/gconvfifo.rf/grf.rf/gntv_or_sync_fifo.gl0.wr/gwas.gpf.wrpf/gpf1.prog_full_i_reg	|USBInterface/DATA_READ_FIFO/U0/inst_fifo_gen/gconvfifo.rf/grf.rf/gntv_or_sync_fifo.gl0.wr/gwas.gpf.wrpf/gpf1.prog_full_i_reg2default:default2default:default2B
 *DRC|Netlist|Instance|Required Pin|RAMB36E12default:default8Z	REQP-1839h px? 
?
?RAMB36 async control check: The RAMB36E1 %s has an input control pin %s (net: %s) which is driven by a register (%s) that has an active asychronous set or reset. This may cause corruption of the memory contents and/or read values when the set/reset is asserted and is not analyzed by the default static timing analysis. It is suggested to eliminate the use of a set/reset to registers driving this RAMB pin or else use a synchronous reset in which the assertion of the reset is timed by default.%s*DRC2?
 "?
?TBR/U0/inst_blk_mem_gen/gnbram.gnativebmg.native_blk_mem_gen/valid.cstr/ramloop[0].ram.r/prim_noinit.ram/DEVICE_7SERIES.NO_BMM_INFO.SP.SIMPLE_PRIM36.ram	?TBR/U0/inst_blk_mem_gen/gnbram.gnativebmg.native_blk_mem_gen/valid.cstr/ramloop[0].ram.r/prim_noinit.ram/DEVICE_7SERIES.NO_BMM_INFO.SP.SIMPLE_PRIM36.ram2default:default2default:default2?
 "?
?TBR/U0/inst_blk_mem_gen/gnbram.gnativebmg.native_blk_mem_gen/valid.cstr/ramloop[0].ram.r/prim_noinit.ram/DEVICE_7SERIES.NO_BMM_INFO.SP.SIMPLE_PRIM36.ram/WEA[0]?TBR/U0/inst_blk_mem_gen/gnbram.gnativebmg.native_blk_mem_gen/valid.cstr/ramloop[0].ram.r/prim_noinit.ram/DEVICE_7SERIES.NO_BMM_INFO.SP.SIMPLE_PRIM36.ram/WEA[0]2default:default2default:default2?
 "?
oTBR/U0/inst_blk_mem_gen/gnbram.gnativebmg.native_blk_mem_gen/valid.cstr/ramloop[0].ram.r/prim_noinit.ram/wea[0]lTBR/U0/inst_blk_mem_gen/gnbram.gnativebmg.native_blk_mem_gen/valid.cstr/ramloop[0].ram.r/prim_noinit.ram/wea2default:default2default:default2?
 "?
|USBInterface/DATA_READ_FIFO/U0/inst_fifo_gen/gconvfifo.rf/grf.rf/gntv_or_sync_fifo.gl0.wr/gwas.gpf.wrpf/gpf1.prog_full_i_reg	|USBInterface/DATA_READ_FIFO/U0/inst_fifo_gen/gconvfifo.rf/grf.rf/gntv_or_sync_fifo.gl0.wr/gwas.gpf.wrpf/gpf1.prog_full_i_reg2default:default2default:default2B
 *DRC|Netlist|Instance|Required Pin|RAMB36E12default:default8Z	REQP-1839h px? 
?
?RAMB36 async control check: The RAMB36E1 %s has an input control pin %s (net: %s) which is driven by a register (%s) that has an active asychronous set or reset. This may cause corruption of the memory contents and/or read values when the set/reset is asserted and is not analyzed by the default static timing analysis. It is suggested to eliminate the use of a set/reset to registers driving this RAMB pin or else use a synchronous reset in which the assertion of the reset is timed by default.%s*DRC2?
 "?
?TBR/U0/inst_blk_mem_gen/gnbram.gnativebmg.native_blk_mem_gen/valid.cstr/ramloop[0].ram.r/prim_noinit.ram/DEVICE_7SERIES.NO_BMM_INFO.SP.SIMPLE_PRIM36.ram	?TBR/U0/inst_blk_mem_gen/gnbram.gnativebmg.native_blk_mem_gen/valid.cstr/ramloop[0].ram.r/prim_noinit.ram/DEVICE_7SERIES.NO_BMM_INFO.SP.SIMPLE_PRIM36.ram2default:default2default:default2?
 "?
?TBR/U0/inst_blk_mem_gen/gnbram.gnativebmg.native_blk_mem_gen/valid.cstr/ramloop[0].ram.r/prim_noinit.ram/DEVICE_7SERIES.NO_BMM_INFO.SP.SIMPLE_PRIM36.ram/WEA[1]?TBR/U0/inst_blk_mem_gen/gnbram.gnativebmg.native_blk_mem_gen/valid.cstr/ramloop[0].ram.r/prim_noinit.ram/DEVICE_7SERIES.NO_BMM_INFO.SP.SIMPLE_PRIM36.ram/WEA[1]2default:default2default:default2?
 "?
oTBR/U0/inst_blk_mem_gen/gnbram.gnativebmg.native_blk_mem_gen/valid.cstr/ramloop[0].ram.r/prim_noinit.ram/wea[0]lTBR/U0/inst_blk_mem_gen/gnbram.gnativebmg.native_blk_mem_gen/valid.cstr/ramloop[0].ram.r/prim_noinit.ram/wea2default:default2default:default2?
 "?
|USBInterface/DATA_READ_FIFO/U0/inst_fifo_gen/gconvfifo.rf/grf.rf/gntv_or_sync_fifo.gl0.wr/gwas.gpf.wrpf/gpf1.prog_full_i_reg	|USBInterface/DATA_READ_FIFO/U0/inst_fifo_gen/gconvfifo.rf/grf.rf/gntv_or_sync_fifo.gl0.wr/gwas.gpf.wrpf/gpf1.prog_full_i_reg2default:default2default:default2B
 *DRC|Netlist|Instance|Required Pin|RAMB36E12default:default8Z	REQP-1839h px? 
?
?RAMB36 async control check: The RAMB36E1 %s has an input control pin %s (net: %s) which is driven by a register (%s) that has an active asychronous set or reset. This may cause corruption of the memory contents and/or read values when the set/reset is asserted and is not analyzed by the default static timing analysis. It is suggested to eliminate the use of a set/reset to registers driving this RAMB pin or else use a synchronous reset in which the assertion of the reset is timed by default.%s*DRC2?
 "?
?TBR/U0/inst_blk_mem_gen/gnbram.gnativebmg.native_blk_mem_gen/valid.cstr/ramloop[0].ram.r/prim_noinit.ram/DEVICE_7SERIES.NO_BMM_INFO.SP.SIMPLE_PRIM36.ram	?TBR/U0/inst_blk_mem_gen/gnbram.gnativebmg.native_blk_mem_gen/valid.cstr/ramloop[0].ram.r/prim_noinit.ram/DEVICE_7SERIES.NO_BMM_INFO.SP.SIMPLE_PRIM36.ram2default:default2default:default2?
 "?
?TBR/U0/inst_blk_mem_gen/gnbram.gnativebmg.native_blk_mem_gen/valid.cstr/ramloop[0].ram.r/prim_noinit.ram/DEVICE_7SERIES.NO_BMM_INFO.SP.SIMPLE_PRIM36.ram/WEA[2]?TBR/U0/inst_blk_mem_gen/gnbram.gnativebmg.native_blk_mem_gen/valid.cstr/ramloop[0].ram.r/prim_noinit.ram/DEVICE_7SERIES.NO_BMM_INFO.SP.SIMPLE_PRIM36.ram/WEA[2]2default:default2default:default2?
 "?
oTBR/U0/inst_blk_mem_gen/gnbram.gnativebmg.native_blk_mem_gen/valid.cstr/ramloop[0].ram.r/prim_noinit.ram/wea[0]lTBR/U0/inst_blk_mem_gen/gnbram.gnativebmg.native_blk_mem_gen/valid.cstr/ramloop[0].ram.r/prim_noinit.ram/wea2default:default2default:default2?
 "?
|USBInterface/DATA_READ_FIFO/U0/inst_fifo_gen/gconvfifo.rf/grf.rf/gntv_or_sync_fifo.gl0.wr/gwas.gpf.wrpf/gpf1.prog_full_i_reg	|USBInterface/DATA_READ_FIFO/U0/inst_fifo_gen/gconvfifo.rf/grf.rf/gntv_or_sync_fifo.gl0.wr/gwas.gpf.wrpf/gpf1.prog_full_i_reg2default:default2default:default2B
 *DRC|Netlist|Instance|Required Pin|RAMB36E12default:default8Z	REQP-1839h px? 
?
?RAMB36 async control check: The RAMB36E1 %s has an input control pin %s (net: %s) which is driven by a register (%s) that has an active asychronous set or reset. This may cause corruption of the memory contents and/or read values when the set/reset is asserted and is not analyzed by the default static timing analysis. It is suggested to eliminate the use of a set/reset to registers driving this RAMB pin or else use a synchronous reset in which the assertion of the reset is timed by default.%s*DRC2?
 "?
?TBR/U0/inst_blk_mem_gen/gnbram.gnativebmg.native_blk_mem_gen/valid.cstr/ramloop[0].ram.r/prim_noinit.ram/DEVICE_7SERIES.NO_BMM_INFO.SP.SIMPLE_PRIM36.ram	?TBR/U0/inst_blk_mem_gen/gnbram.gnativebmg.native_blk_mem_gen/valid.cstr/ramloop[0].ram.r/prim_noinit.ram/DEVICE_7SERIES.NO_BMM_INFO.SP.SIMPLE_PRIM36.ram2default:default2default:default2?
 "?
?TBR/U0/inst_blk_mem_gen/gnbram.gnativebmg.native_blk_mem_gen/valid.cstr/ramloop[0].ram.r/prim_noinit.ram/DEVICE_7SERIES.NO_BMM_INFO.SP.SIMPLE_PRIM36.ram/WEA[3]?TBR/U0/inst_blk_mem_gen/gnbram.gnativebmg.native_blk_mem_gen/valid.cstr/ramloop[0].ram.r/prim_noinit.ram/DEVICE_7SERIES.NO_BMM_INFO.SP.SIMPLE_PRIM36.ram/WEA[3]2default:default2default:default2?
 "?
oTBR/U0/inst_blk_mem_gen/gnbram.gnativebmg.native_blk_mem_gen/valid.cstr/ramloop[0].ram.r/prim_noinit.ram/wea[0]lTBR/U0/inst_blk_mem_gen/gnbram.gnativebmg.native_blk_mem_gen/valid.cstr/ramloop[0].ram.r/prim_noinit.ram/wea2default:default2default:default2?
 "?
|USBInterface/DATA_READ_FIFO/U0/inst_fifo_gen/gconvfifo.rf/grf.rf/gntv_or_sync_fifo.gl0.wr/gwas.gpf.wrpf/gpf1.prog_full_i_reg	|USBInterface/DATA_READ_FIFO/U0/inst_fifo_gen/gconvfifo.rf/grf.rf/gntv_or_sync_fifo.gl0.wr/gwas.gpf.wrpf/gpf1.prog_full_i_reg2default:default2default:default2B
 *DRC|Netlist|Instance|Required Pin|RAMB36E12default:default8Z	REQP-1839h px? 
?
?RAMB36 async control check: The RAMB36E1 %s has an input control pin %s (net: %s) which is driven by a register (%s) that has an active asychronous set or reset. This may cause corruption of the memory contents and/or read values when the set/reset is asserted and is not analyzed by the default static timing analysis. It is suggested to eliminate the use of a set/reset to registers driving this RAMB pin or else use a synchronous reset in which the assertion of the reset is timed by default.%s*DRC2?
 "?
?U447/xpm_fifo_async_inst/gnuram_async_fifo.xpm_fifo_base_inst/gen_sdpram.xpm_memory_base_inst/gen_wr_a.gen_word_narrow.mem_reg_0_0	?U447/xpm_fifo_async_inst/gnuram_async_fifo.xpm_fifo_base_inst/gen_sdpram.xpm_memory_base_inst/gen_wr_a.gen_word_narrow.mem_reg_0_02default:default2default:default2?
 "?
?U447/xpm_fifo_async_inst/gnuram_async_fifo.xpm_fifo_base_inst/gen_sdpram.xpm_memory_base_inst/gen_wr_a.gen_word_narrow.mem_reg_0_0/ENARDEN?U447/xpm_fifo_async_inst/gnuram_async_fifo.xpm_fifo_base_inst/gen_sdpram.xpm_memory_base_inst/gen_wr_a.gen_word_narrow.mem_reg_0_0/ENARDEN2default:default2default:default2?
 "?
aU447/xpm_fifo_async_inst/gnuram_async_fifo.xpm_fifo_base_inst/gen_sdpram.xpm_memory_base_inst/enaaU447/xpm_fifo_async_inst/gnuram_async_fifo.xpm_fifo_base_inst/gen_sdpram.xpm_memory_base_inst/ena2default:default2default:default2N
 "8
U447/FIFO_WE_reg	U447/FIFO_WE_reg2default:default2default:default2B
 *DRC|Netlist|Instance|Required Pin|RAMB36E12default:default8Z	REQP-1839h px? 
?
?RAMB36 async control check: The RAMB36E1 %s has an input control pin %s (net: %s) which is driven by a register (%s) that has an active asychronous set or reset. This may cause corruption of the memory contents and/or read values when the set/reset is asserted and is not analyzed by the default static timing analysis. It is suggested to eliminate the use of a set/reset to registers driving this RAMB pin or else use a synchronous reset in which the assertion of the reset is timed by default.%s*DRC2?
 "?
?U447/xpm_fifo_async_inst/gnuram_async_fifo.xpm_fifo_base_inst/gen_sdpram.xpm_memory_base_inst/gen_wr_a.gen_word_narrow.mem_reg_0_0	?U447/xpm_fifo_async_inst/gnuram_async_fifo.xpm_fifo_base_inst/gen_sdpram.xpm_memory_base_inst/gen_wr_a.gen_word_narrow.mem_reg_0_02default:default2default:default2?
 "?
?U447/xpm_fifo_async_inst/gnuram_async_fifo.xpm_fifo_base_inst/gen_sdpram.xpm_memory_base_inst/gen_wr_a.gen_word_narrow.mem_reg_0_0/ENBWREN?U447/xpm_fifo_async_inst/gnuram_async_fifo.xpm_fifo_base_inst/gen_sdpram.xpm_memory_base_inst/gen_wr_a.gen_word_narrow.mem_reg_0_0/ENBWREN2default:default2default:default2?
 "?
?U447/xpm_fifo_async_inst/gnuram_async_fifo.xpm_fifo_base_inst/gen_sdpram.xpm_memory_base_inst/gen_wr_a.gen_word_narrow.mem_reg_0_31_i_1_n_0?U447/xpm_fifo_async_inst/gnuram_async_fifo.xpm_fifo_base_inst/gen_sdpram.xpm_memory_base_inst/gen_wr_a.gen_word_narrow.mem_reg_0_31_i_1_n_02default:default2default:default2?
 "?
qUSBInterface/ADDRESS_FIFO/U0/inst_fifo_gen/gconvfifo.rf/grf.rf/gntv_or_sync_fifo.gl0.rd/gras.rsts/ram_empty_i_reg	qUSBInterface/ADDRESS_FIFO/U0/inst_fifo_gen/gconvfifo.rf/grf.rf/gntv_or_sync_fifo.gl0.rd/gras.rsts/ram_empty_i_reg2default:default2default:default2B
 *DRC|Netlist|Instance|Required Pin|RAMB36E12default:default8Z	REQP-1839h px? 
?
?RAMB36 async control check: The RAMB36E1 %s has an input control pin %s (net: %s) which is driven by a register (%s) that has an active asychronous set or reset. This may cause corruption of the memory contents and/or read values when the set/reset is asserted and is not analyzed by the default static timing analysis. It is suggested to eliminate the use of a set/reset to registers driving this RAMB pin or else use a synchronous reset in which the assertion of the reset is timed by default.%s*DRC2?
 "?
?U447/xpm_fifo_async_inst/gnuram_async_fifo.xpm_fifo_base_inst/gen_sdpram.xpm_memory_base_inst/gen_wr_a.gen_word_narrow.mem_reg_0_0	?U447/xpm_fifo_async_inst/gnuram_async_fifo.xpm_fifo_base_inst/gen_sdpram.xpm_memory_base_inst/gen_wr_a.gen_word_narrow.mem_reg_0_02default:default2default:default2?
 "?
?U447/xpm_fifo_async_inst/gnuram_async_fifo.xpm_fifo_base_inst/gen_sdpram.xpm_memory_base_inst/gen_wr_a.gen_word_narrow.mem_reg_0_0/ENBWREN?U447/xpm_fifo_async_inst/gnuram_async_fifo.xpm_fifo_base_inst/gen_sdpram.xpm_memory_base_inst/gen_wr_a.gen_word_narrow.mem_reg_0_0/ENBWREN2default:default2default:default2?
 "?
?U447/xpm_fifo_async_inst/gnuram_async_fifo.xpm_fifo_base_inst/gen_sdpram.xpm_memory_base_inst/gen_wr_a.gen_word_narrow.mem_reg_0_31_i_1_n_0?U447/xpm_fifo_async_inst/gnuram_async_fifo.xpm_fifo_base_inst/gen_sdpram.xpm_memory_base_inst/gen_wr_a.gen_word_narrow.mem_reg_0_31_i_1_n_02default:default2default:default2?
 "?
|USBInterface/DATA_READ_FIFO/U0/inst_fifo_gen/gconvfifo.rf/grf.rf/gntv_or_sync_fifo.gl0.wr/gwas.gpf.wrpf/gpf1.prog_full_i_reg	|USBInterface/DATA_READ_FIFO/U0/inst_fifo_gen/gconvfifo.rf/grf.rf/gntv_or_sync_fifo.gl0.wr/gwas.gpf.wrpf/gpf1.prog_full_i_reg2default:default2default:default2B
 *DRC|Netlist|Instance|Required Pin|RAMB36E12default:default8Z	REQP-1839h px? 
?
?RAMB36 async control check: The RAMB36E1 %s has an input control pin %s (net: %s) which is driven by a register (%s) that has an active asychronous set or reset. This may cause corruption of the memory contents and/or read values when the set/reset is asserted and is not analyzed by the default static timing analysis. It is suggested to eliminate the use of a set/reset to registers driving this RAMB pin or else use a synchronous reset in which the assertion of the reset is timed by default.%s*DRC2?
 "?
?U447/xpm_fifo_async_inst/gnuram_async_fifo.xpm_fifo_base_inst/gen_sdpram.xpm_memory_base_inst/gen_wr_a.gen_word_narrow.mem_reg_0_0	?U447/xpm_fifo_async_inst/gnuram_async_fifo.xpm_fifo_base_inst/gen_sdpram.xpm_memory_base_inst/gen_wr_a.gen_word_narrow.mem_reg_0_02default:default2default:default2?
 "?
?U447/xpm_fifo_async_inst/gnuram_async_fifo.xpm_fifo_base_inst/gen_sdpram.xpm_memory_base_inst/gen_wr_a.gen_word_narrow.mem_reg_0_0/WEA[0]?U447/xpm_fifo_async_inst/gnuram_async_fifo.xpm_fifo_base_inst/gen_sdpram.xpm_memory_base_inst/gen_wr_a.gen_word_narrow.mem_reg_0_0/WEA[0]2default:default2default:default2?
 "?
aU447/xpm_fifo_async_inst/gnuram_async_fifo.xpm_fifo_base_inst/gen_sdpram.xpm_memory_base_inst/enaaU447/xpm_fifo_async_inst/gnuram_async_fifo.xpm_fifo_base_inst/gen_sdpram.xpm_memory_base_inst/ena2default:default2default:default2N
 "8
U447/FIFO_WE_reg	U447/FIFO_WE_reg2default:default2default:default2B
 *DRC|Netlist|Instance|Required Pin|RAMB36E12default:default8Z	REQP-1839h px? 
?
?RAMB36 async control check: The RAMB36E1 %s has an input control pin %s (net: %s) which is driven by a register (%s) that has an active asychronous set or reset. This may cause corruption of the memory contents and/or read values when the set/reset is asserted and is not analyzed by the default static timing analysis. It is suggested to eliminate the use of a set/reset to registers driving this RAMB pin or else use a synchronous reset in which the assertion of the reset is timed by default.%s*DRC2?
 "?
?U447/xpm_fifo_async_inst/gnuram_async_fifo.xpm_fifo_base_inst/gen_sdpram.xpm_memory_base_inst/gen_wr_a.gen_word_narrow.mem_reg_0_1	?U447/xpm_fifo_async_inst/gnuram_async_fifo.xpm_fifo_base_inst/gen_sdpram.xpm_memory_base_inst/gen_wr_a.gen_word_narrow.mem_reg_0_12default:default2default:default2?
 "?
?U447/xpm_fifo_async_inst/gnuram_async_fifo.xpm_fifo_base_inst/gen_sdpram.xpm_memory_base_inst/gen_wr_a.gen_word_narrow.mem_reg_0_1/ENARDEN?U447/xpm_fifo_async_inst/gnuram_async_fifo.xpm_fifo_base_inst/gen_sdpram.xpm_memory_base_inst/gen_wr_a.gen_word_narrow.mem_reg_0_1/ENARDEN2default:default2default:default2?
 "?
aU447/xpm_fifo_async_inst/gnuram_async_fifo.xpm_fifo_base_inst/gen_sdpram.xpm_memory_base_inst/enaaU447/xpm_fifo_async_inst/gnuram_async_fifo.xpm_fifo_base_inst/gen_sdpram.xpm_memory_base_inst/ena2default:default2default:default2N
 "8
U447/FIFO_WE_reg	U447/FIFO_WE_reg2default:default2default:default2B
 *DRC|Netlist|Instance|Required Pin|RAMB36E12default:default8Z	REQP-1839h px? 
?
?RAMB36 async control check: The RAMB36E1 %s has an input control pin %s (net: %s) which is driven by a register (%s) that has an active asychronous set or reset. This may cause corruption of the memory contents and/or read values when the set/reset is asserted and is not analyzed by the default static timing analysis. It is suggested to eliminate the use of a set/reset to registers driving this RAMB pin or else use a synchronous reset in which the assertion of the reset is timed by default.%s*DRC2?
 "?
?U447/xpm_fifo_async_inst/gnuram_async_fifo.xpm_fifo_base_inst/gen_sdpram.xpm_memory_base_inst/gen_wr_a.gen_word_narrow.mem_reg_0_1	?U447/xpm_fifo_async_inst/gnuram_async_fifo.xpm_fifo_base_inst/gen_sdpram.xpm_memory_base_inst/gen_wr_a.gen_word_narrow.mem_reg_0_12default:default2default:default2?
 "?
?U447/xpm_fifo_async_inst/gnuram_async_fifo.xpm_fifo_base_inst/gen_sdpram.xpm_memory_base_inst/gen_wr_a.gen_word_narrow.mem_reg_0_1/ENBWREN?U447/xpm_fifo_async_inst/gnuram_async_fifo.xpm_fifo_base_inst/gen_sdpram.xpm_memory_base_inst/gen_wr_a.gen_word_narrow.mem_reg_0_1/ENBWREN2default:default2default:default2?
 "?
?U447/xpm_fifo_async_inst/gnuram_async_fifo.xpm_fifo_base_inst/gen_sdpram.xpm_memory_base_inst/gen_wr_a.gen_word_narrow.mem_reg_0_31_i_1_n_0?U447/xpm_fifo_async_inst/gnuram_async_fifo.xpm_fifo_base_inst/gen_sdpram.xpm_memory_base_inst/gen_wr_a.gen_word_narrow.mem_reg_0_31_i_1_n_02default:default2default:default2?
 "?
qUSBInterface/ADDRESS_FIFO/U0/inst_fifo_gen/gconvfifo.rf/grf.rf/gntv_or_sync_fifo.gl0.rd/gras.rsts/ram_empty_i_reg	qUSBInterface/ADDRESS_FIFO/U0/inst_fifo_gen/gconvfifo.rf/grf.rf/gntv_or_sync_fifo.gl0.rd/gras.rsts/ram_empty_i_reg2default:default2default:default2B
 *DRC|Netlist|Instance|Required Pin|RAMB36E12default:default8Z	REQP-1839h px? 
?
?RAMB36 async control check: The RAMB36E1 %s has an input control pin %s (net: %s) which is driven by a register (%s) that has an active asychronous set or reset. This may cause corruption of the memory contents and/or read values when the set/reset is asserted and is not analyzed by the default static timing analysis. It is suggested to eliminate the use of a set/reset to registers driving this RAMB pin or else use a synchronous reset in which the assertion of the reset is timed by default.%s*DRC2?
 "?
?U447/xpm_fifo_async_inst/gnuram_async_fifo.xpm_fifo_base_inst/gen_sdpram.xpm_memory_base_inst/gen_wr_a.gen_word_narrow.mem_reg_0_1	?U447/xpm_fifo_async_inst/gnuram_async_fifo.xpm_fifo_base_inst/gen_sdpram.xpm_memory_base_inst/gen_wr_a.gen_word_narrow.mem_reg_0_12default:default2default:default2?
 "?
?U447/xpm_fifo_async_inst/gnuram_async_fifo.xpm_fifo_base_inst/gen_sdpram.xpm_memory_base_inst/gen_wr_a.gen_word_narrow.mem_reg_0_1/ENBWREN?U447/xpm_fifo_async_inst/gnuram_async_fifo.xpm_fifo_base_inst/gen_sdpram.xpm_memory_base_inst/gen_wr_a.gen_word_narrow.mem_reg_0_1/ENBWREN2default:default2default:default2?
 "?
?U447/xpm_fifo_async_inst/gnuram_async_fifo.xpm_fifo_base_inst/gen_sdpram.xpm_memory_base_inst/gen_wr_a.gen_word_narrow.mem_reg_0_31_i_1_n_0?U447/xpm_fifo_async_inst/gnuram_async_fifo.xpm_fifo_base_inst/gen_sdpram.xpm_memory_base_inst/gen_wr_a.gen_word_narrow.mem_reg_0_31_i_1_n_02default:default2default:default2?
 "?
|USBInterface/DATA_READ_FIFO/U0/inst_fifo_gen/gconvfifo.rf/grf.rf/gntv_or_sync_fifo.gl0.wr/gwas.gpf.wrpf/gpf1.prog_full_i_reg	|USBInterface/DATA_READ_FIFO/U0/inst_fifo_gen/gconvfifo.rf/grf.rf/gntv_or_sync_fifo.gl0.wr/gwas.gpf.wrpf/gpf1.prog_full_i_reg2default:default2default:default2B
 *DRC|Netlist|Instance|Required Pin|RAMB36E12default:default8Z	REQP-1839h px? 
?
?RAMB36 async control check: The RAMB36E1 %s has an input control pin %s (net: %s) which is driven by a register (%s) that has an active asychronous set or reset. This may cause corruption of the memory contents and/or read values when the set/reset is asserted and is not analyzed by the default static timing analysis. It is suggested to eliminate the use of a set/reset to registers driving this RAMB pin or else use a synchronous reset in which the assertion of the reset is timed by default.%s*DRC2?
 "?
?U447/xpm_fifo_async_inst/gnuram_async_fifo.xpm_fifo_base_inst/gen_sdpram.xpm_memory_base_inst/gen_wr_a.gen_word_narrow.mem_reg_0_1	?U447/xpm_fifo_async_inst/gnuram_async_fifo.xpm_fifo_base_inst/gen_sdpram.xpm_memory_base_inst/gen_wr_a.gen_word_narrow.mem_reg_0_12default:default2default:default2?
 "?
?U447/xpm_fifo_async_inst/gnuram_async_fifo.xpm_fifo_base_inst/gen_sdpram.xpm_memory_base_inst/gen_wr_a.gen_word_narrow.mem_reg_0_1/WEA[0]?U447/xpm_fifo_async_inst/gnuram_async_fifo.xpm_fifo_base_inst/gen_sdpram.xpm_memory_base_inst/gen_wr_a.gen_word_narrow.mem_reg_0_1/WEA[0]2default:default2default:default2?
 "?
aU447/xpm_fifo_async_inst/gnuram_async_fifo.xpm_fifo_base_inst/gen_sdpram.xpm_memory_base_inst/enaaU447/xpm_fifo_async_inst/gnuram_async_fifo.xpm_fifo_base_inst/gen_sdpram.xpm_memory_base_inst/ena2default:default2default:default2N
 "8
U447/FIFO_WE_reg	U447/FIFO_WE_reg2default:default2default:default2B
 *DRC|Netlist|Instance|Required Pin|RAMB36E12default:default8Z	REQP-1839h px? 
?
?RAMB36 async control check: The RAMB36E1 %s has an input control pin %s (net: %s) which is driven by a register (%s) that has an active asychronous set or reset. This may cause corruption of the memory contents and/or read values when the set/reset is asserted and is not analyzed by the default static timing analysis. It is suggested to eliminate the use of a set/reset to registers driving this RAMB pin or else use a synchronous reset in which the assertion of the reset is timed by default.%s*DRC2?
 "?
?U447/xpm_fifo_async_inst/gnuram_async_fifo.xpm_fifo_base_inst/gen_sdpram.xpm_memory_base_inst/gen_wr_a.gen_word_narrow.mem_reg_0_10	?U447/xpm_fifo_async_inst/gnuram_async_fifo.xpm_fifo_base_inst/gen_sdpram.xpm_memory_base_inst/gen_wr_a.gen_word_narrow.mem_reg_0_102default:default2default:default2?
 "?
?U447/xpm_fifo_async_inst/gnuram_async_fifo.xpm_fifo_base_inst/gen_sdpram.xpm_memory_base_inst/gen_wr_a.gen_word_narrow.mem_reg_0_10/ENARDEN?U447/xpm_fifo_async_inst/gnuram_async_fifo.xpm_fifo_base_inst/gen_sdpram.xpm_memory_base_inst/gen_wr_a.gen_word_narrow.mem_reg_0_10/ENARDEN2default:default2default:default2?
 "?
aU447/xpm_fifo_async_inst/gnuram_async_fifo.xpm_fifo_base_inst/gen_sdpram.xpm_memory_base_inst/enaaU447/xpm_fifo_async_inst/gnuram_async_fifo.xpm_fifo_base_inst/gen_sdpram.xpm_memory_base_inst/ena2default:default2default:default2N
 "8
U447/FIFO_WE_reg	U447/FIFO_WE_reg2default:default2default:default2B
 *DRC|Netlist|Instance|Required Pin|RAMB36E12default:default8Z	REQP-1839h px? 
?
?RAMB36 async control check: The RAMB36E1 %s has an input control pin %s (net: %s) which is driven by a register (%s) that has an active asychronous set or reset. This may cause corruption of the memory contents and/or read values when the set/reset is asserted and is not analyzed by the default static timing analysis. It is suggested to eliminate the use of a set/reset to registers driving this RAMB pin or else use a synchronous reset in which the assertion of the reset is timed by default.%s*DRC2?
 "?
?U447/xpm_fifo_async_inst/gnuram_async_fifo.xpm_fifo_base_inst/gen_sdpram.xpm_memory_base_inst/gen_wr_a.gen_word_narrow.mem_reg_0_10	?U447/xpm_fifo_async_inst/gnuram_async_fifo.xpm_fifo_base_inst/gen_sdpram.xpm_memory_base_inst/gen_wr_a.gen_word_narrow.mem_reg_0_102default:default2default:default2?
 "?
?U447/xpm_fifo_async_inst/gnuram_async_fifo.xpm_fifo_base_inst/gen_sdpram.xpm_memory_base_inst/gen_wr_a.gen_word_narrow.mem_reg_0_10/ENBWREN?U447/xpm_fifo_async_inst/gnuram_async_fifo.xpm_fifo_base_inst/gen_sdpram.xpm_memory_base_inst/gen_wr_a.gen_word_narrow.mem_reg_0_10/ENBWREN2default:default2default:default2?
 "?
?U447/xpm_fifo_async_inst/gnuram_async_fifo.xpm_fifo_base_inst/gen_sdpram.xpm_memory_base_inst/gen_wr_a.gen_word_narrow.mem_reg_0_31_i_1_n_0?U447/xpm_fifo_async_inst/gnuram_async_fifo.xpm_fifo_base_inst/gen_sdpram.xpm_memory_base_inst/gen_wr_a.gen_word_narrow.mem_reg_0_31_i_1_n_02default:default2default:default2?
 "?
qUSBInterface/ADDRESS_FIFO/U0/inst_fifo_gen/gconvfifo.rf/grf.rf/gntv_or_sync_fifo.gl0.rd/gras.rsts/ram_empty_i_reg	qUSBInterface/ADDRESS_FIFO/U0/inst_fifo_gen/gconvfifo.rf/grf.rf/gntv_or_sync_fifo.gl0.rd/gras.rsts/ram_empty_i_reg2default:default2default:default2B
 *DRC|Netlist|Instance|Required Pin|RAMB36E12default:default8Z	REQP-1839h px? 
?
?RAMB36 async control check: The RAMB36E1 %s has an input control pin %s (net: %s) which is driven by a register (%s) that has an active asychronous set or reset. This may cause corruption of the memory contents and/or read values when the set/reset is asserted and is not analyzed by the default static timing analysis. It is suggested to eliminate the use of a set/reset to registers driving this RAMB pin or else use a synchronous reset in which the assertion of the reset is timed by default.%s*DRC2?
 "?
?U447/xpm_fifo_async_inst/gnuram_async_fifo.xpm_fifo_base_inst/gen_sdpram.xpm_memory_base_inst/gen_wr_a.gen_word_narrow.mem_reg_0_10	?U447/xpm_fifo_async_inst/gnuram_async_fifo.xpm_fifo_base_inst/gen_sdpram.xpm_memory_base_inst/gen_wr_a.gen_word_narrow.mem_reg_0_102default:default2default:default2?
 "?
?U447/xpm_fifo_async_inst/gnuram_async_fifo.xpm_fifo_base_inst/gen_sdpram.xpm_memory_base_inst/gen_wr_a.gen_word_narrow.mem_reg_0_10/ENBWREN?U447/xpm_fifo_async_inst/gnuram_async_fifo.xpm_fifo_base_inst/gen_sdpram.xpm_memory_base_inst/gen_wr_a.gen_word_narrow.mem_reg_0_10/ENBWREN2default:default2default:default2?
 "?
?U447/xpm_fifo_async_inst/gnuram_async_fifo.xpm_fifo_base_inst/gen_sdpram.xpm_memory_base_inst/gen_wr_a.gen_word_narrow.mem_reg_0_31_i_1_n_0?U447/xpm_fifo_async_inst/gnuram_async_fifo.xpm_fifo_base_inst/gen_sdpram.xpm_memory_base_inst/gen_wr_a.gen_word_narrow.mem_reg_0_31_i_1_n_02default:default2default:default2?
 "?
|USBInterface/DATA_READ_FIFO/U0/inst_fifo_gen/gconvfifo.rf/grf.rf/gntv_or_sync_fifo.gl0.wr/gwas.gpf.wrpf/gpf1.prog_full_i_reg	|USBInterface/DATA_READ_FIFO/U0/inst_fifo_gen/gconvfifo.rf/grf.rf/gntv_or_sync_fifo.gl0.wr/gwas.gpf.wrpf/gpf1.prog_full_i_reg2default:default2default:default2B
 *DRC|Netlist|Instance|Required Pin|RAMB36E12default:default8Z	REQP-1839h px? 
?
?RAMB36 async control check: The RAMB36E1 %s has an input control pin %s (net: %s) which is driven by a register (%s) that has an active asychronous set or reset. This may cause corruption of the memory contents and/or read values when the set/reset is asserted and is not analyzed by the default static timing analysis. It is suggested to eliminate the use of a set/reset to registers driving this RAMB pin or else use a synchronous reset in which the assertion of the reset is timed by default.%s*DRC2?
 "?
?U447/xpm_fifo_async_inst/gnuram_async_fifo.xpm_fifo_base_inst/gen_sdpram.xpm_memory_base_inst/gen_wr_a.gen_word_narrow.mem_reg_0_10	?U447/xpm_fifo_async_inst/gnuram_async_fifo.xpm_fifo_base_inst/gen_sdpram.xpm_memory_base_inst/gen_wr_a.gen_word_narrow.mem_reg_0_102default:default2default:default2?
 "?
?U447/xpm_fifo_async_inst/gnuram_async_fifo.xpm_fifo_base_inst/gen_sdpram.xpm_memory_base_inst/gen_wr_a.gen_word_narrow.mem_reg_0_10/WEA[0]?U447/xpm_fifo_async_inst/gnuram_async_fifo.xpm_fifo_base_inst/gen_sdpram.xpm_memory_base_inst/gen_wr_a.gen_word_narrow.mem_reg_0_10/WEA[0]2default:default2default:default2?
 "?
aU447/xpm_fifo_async_inst/gnuram_async_fifo.xpm_fifo_base_inst/gen_sdpram.xpm_memory_base_inst/enaaU447/xpm_fifo_async_inst/gnuram_async_fifo.xpm_fifo_base_inst/gen_sdpram.xpm_memory_base_inst/ena2default:default2default:default2N
 "8
U447/FIFO_WE_reg	U447/FIFO_WE_reg2default:default2default:default2B
 *DRC|Netlist|Instance|Required Pin|RAMB36E12default:default8Z	REQP-1839h px? 
?

?RAMB18 async control check: The RAMB18E1 %s has an input control pin %s (net: %s) which is driven by a register (%s) that has an active asychronous set or reset. This may cause corruption of the memory contents and/or read values when the set/reset is asserted and is not analyzed by the default static timing analysis. It is suggested to eliminate the use of a set/reset to registers driving this RAMB pin or else use a synchronous reset in which the assertion of the reset is timed by default.%s*DRC2?
 "?
QU192/xpm_memory_sdpram_inst/xpm_memory_base_inst/gen_wr_a.gen_word_narrow.mem_reg	QU192/xpm_memory_sdpram_inst/xpm_memory_base_inst/gen_wr_a.gen_word_narrow.mem_reg2default:default2default:default2?
 "?
aU192/xpm_memory_sdpram_inst/xpm_memory_base_inst/gen_wr_a.gen_word_narrow.mem_reg/ADDRARDADDR[10]aU192/xpm_memory_sdpram_inst/xpm_memory_base_inst/gen_wr_a.gen_word_narrow.mem_reg/ADDRARDADDR[10]2default:default2default:default2?
 "?
9U192/xpm_memory_sdpram_inst/xpm_memory_base_inst/addra[6]9U192/xpm_memory_sdpram_inst/xpm_memory_base_inst/addra[6]2default:default2default:default2J
 "4
U192/WP_reg[6]	U192/WP_reg[6]2default:default2default:default2B
 *DRC|Netlist|Instance|Required Pin|RAMB18E12default:default8Z	REQP-1840h px? 
?

?RAMB18 async control check: The RAMB18E1 %s has an input control pin %s (net: %s) which is driven by a register (%s) that has an active asychronous set or reset. This may cause corruption of the memory contents and/or read values when the set/reset is asserted and is not analyzed by the default static timing analysis. It is suggested to eliminate the use of a set/reset to registers driving this RAMB pin or else use a synchronous reset in which the assertion of the reset is timed by default.%s*DRC2?
 "?
QU192/xpm_memory_sdpram_inst/xpm_memory_base_inst/gen_wr_a.gen_word_narrow.mem_reg	QU192/xpm_memory_sdpram_inst/xpm_memory_base_inst/gen_wr_a.gen_word_narrow.mem_reg2default:default2default:default2?
 "?
aU192/xpm_memory_sdpram_inst/xpm_memory_base_inst/gen_wr_a.gen_word_narrow.mem_reg/ADDRARDADDR[11]aU192/xpm_memory_sdpram_inst/xpm_memory_base_inst/gen_wr_a.gen_word_narrow.mem_reg/ADDRARDADDR[11]2default:default2default:default2?
 "?
9U192/xpm_memory_sdpram_inst/xpm_memory_base_inst/addra[7]9U192/xpm_memory_sdpram_inst/xpm_memory_base_inst/addra[7]2default:default2default:default2J
 "4
U192/WP_reg[7]	U192/WP_reg[7]2default:default2default:default2B
 *DRC|Netlist|Instance|Required Pin|RAMB18E12default:default8Z	REQP-1840h px? 
?

?RAMB18 async control check: The RAMB18E1 %s has an input control pin %s (net: %s) which is driven by a register (%s) that has an active asychronous set or reset. This may cause corruption of the memory contents and/or read values when the set/reset is asserted and is not analyzed by the default static timing analysis. It is suggested to eliminate the use of a set/reset to registers driving this RAMB pin or else use a synchronous reset in which the assertion of the reset is timed by default.%s*DRC2?
 "?
QU192/xpm_memory_sdpram_inst/xpm_memory_base_inst/gen_wr_a.gen_word_narrow.mem_reg	QU192/xpm_memory_sdpram_inst/xpm_memory_base_inst/gen_wr_a.gen_word_narrow.mem_reg2default:default2default:default2?
 "?
aU192/xpm_memory_sdpram_inst/xpm_memory_base_inst/gen_wr_a.gen_word_narrow.mem_reg/ADDRARDADDR[12]aU192/xpm_memory_sdpram_inst/xpm_memory_base_inst/gen_wr_a.gen_word_narrow.mem_reg/ADDRARDADDR[12]2default:default2default:default2?
 "?
9U192/xpm_memory_sdpram_inst/xpm_memory_base_inst/addra[8]9U192/xpm_memory_sdpram_inst/xpm_memory_base_inst/addra[8]2default:default2default:default2J
 "4
U192/WP_reg[8]	U192/WP_reg[8]2default:default2default:default2B
 *DRC|Netlist|Instance|Required Pin|RAMB18E12default:default8Z	REQP-1840h px? 
?

?RAMB18 async control check: The RAMB18E1 %s has an input control pin %s (net: %s) which is driven by a register (%s) that has an active asychronous set or reset. This may cause corruption of the memory contents and/or read values when the set/reset is asserted and is not analyzed by the default static timing analysis. It is suggested to eliminate the use of a set/reset to registers driving this RAMB pin or else use a synchronous reset in which the assertion of the reset is timed by default.%s*DRC2?
 "?
QU192/xpm_memory_sdpram_inst/xpm_memory_base_inst/gen_wr_a.gen_word_narrow.mem_reg	QU192/xpm_memory_sdpram_inst/xpm_memory_base_inst/gen_wr_a.gen_word_narrow.mem_reg2default:default2default:default2?
 "?
aU192/xpm_memory_sdpram_inst/xpm_memory_base_inst/gen_wr_a.gen_word_narrow.mem_reg/ADDRARDADDR[13]aU192/xpm_memory_sdpram_inst/xpm_memory_base_inst/gen_wr_a.gen_word_narrow.mem_reg/ADDRARDADDR[13]2default:default2default:default2?
 "?
9U192/xpm_memory_sdpram_inst/xpm_memory_base_inst/addra[9]9U192/xpm_memory_sdpram_inst/xpm_memory_base_inst/addra[9]2default:default2default:default2J
 "4
U192/WP_reg[9]	U192/WP_reg[9]2default:default2default:default2B
 *DRC|Netlist|Instance|Required Pin|RAMB18E12default:default8Z	REQP-1840h px? 
?

?RAMB18 async control check: The RAMB18E1 %s has an input control pin %s (net: %s) which is driven by a register (%s) that has an active asychronous set or reset. This may cause corruption of the memory contents and/or read values when the set/reset is asserted and is not analyzed by the default static timing analysis. It is suggested to eliminate the use of a set/reset to registers driving this RAMB pin or else use a synchronous reset in which the assertion of the reset is timed by default.%s*DRC2?
 "?
QU192/xpm_memory_sdpram_inst/xpm_memory_base_inst/gen_wr_a.gen_word_narrow.mem_reg	QU192/xpm_memory_sdpram_inst/xpm_memory_base_inst/gen_wr_a.gen_word_narrow.mem_reg2default:default2default:default2?
 "?
`U192/xpm_memory_sdpram_inst/xpm_memory_base_inst/gen_wr_a.gen_word_narrow.mem_reg/ADDRARDADDR[4]`U192/xpm_memory_sdpram_inst/xpm_memory_base_inst/gen_wr_a.gen_word_narrow.mem_reg/ADDRARDADDR[4]2default:default2default:default2?
 "?
9U192/xpm_memory_sdpram_inst/xpm_memory_base_inst/addra[0]9U192/xpm_memory_sdpram_inst/xpm_memory_base_inst/addra[0]2default:default2default:default2J
 "4
U192/WP_reg[0]	U192/WP_reg[0]2default:default2default:default2B
 *DRC|Netlist|Instance|Required Pin|RAMB18E12default:default8Z	REQP-1840h px? 
?

?RAMB18 async control check: The RAMB18E1 %s has an input control pin %s (net: %s) which is driven by a register (%s) that has an active asychronous set or reset. This may cause corruption of the memory contents and/or read values when the set/reset is asserted and is not analyzed by the default static timing analysis. It is suggested to eliminate the use of a set/reset to registers driving this RAMB pin or else use a synchronous reset in which the assertion of the reset is timed by default.%s*DRC2?
 "?
QU192/xpm_memory_sdpram_inst/xpm_memory_base_inst/gen_wr_a.gen_word_narrow.mem_reg	QU192/xpm_memory_sdpram_inst/xpm_memory_base_inst/gen_wr_a.gen_word_narrow.mem_reg2default:default2default:default2?
 "?
`U192/xpm_memory_sdpram_inst/xpm_memory_base_inst/gen_wr_a.gen_word_narrow.mem_reg/ADDRARDADDR[5]`U192/xpm_memory_sdpram_inst/xpm_memory_base_inst/gen_wr_a.gen_word_narrow.mem_reg/ADDRARDADDR[5]2default:default2default:default2?
 "?
9U192/xpm_memory_sdpram_inst/xpm_memory_base_inst/addra[1]9U192/xpm_memory_sdpram_inst/xpm_memory_base_inst/addra[1]2default:default2default:default2J
 "4
U192/WP_reg[1]	U192/WP_reg[1]2default:default2default:default2B
 *DRC|Netlist|Instance|Required Pin|RAMB18E12default:default8Z	REQP-1840h px? 
?

?RAMB18 async control check: The RAMB18E1 %s has an input control pin %s (net: %s) which is driven by a register (%s) that has an active asychronous set or reset. This may cause corruption of the memory contents and/or read values when the set/reset is asserted and is not analyzed by the default static timing analysis. It is suggested to eliminate the use of a set/reset to registers driving this RAMB pin or else use a synchronous reset in which the assertion of the reset is timed by default.%s*DRC2?
 "?
QU192/xpm_memory_sdpram_inst/xpm_memory_base_inst/gen_wr_a.gen_word_narrow.mem_reg	QU192/xpm_memory_sdpram_inst/xpm_memory_base_inst/gen_wr_a.gen_word_narrow.mem_reg2default:default2default:default2?
 "?
`U192/xpm_memory_sdpram_inst/xpm_memory_base_inst/gen_wr_a.gen_word_narrow.mem_reg/ADDRARDADDR[6]`U192/xpm_memory_sdpram_inst/xpm_memory_base_inst/gen_wr_a.gen_word_narrow.mem_reg/ADDRARDADDR[6]2default:default2default:default2?
 "?
9U192/xpm_memory_sdpram_inst/xpm_memory_base_inst/addra[2]9U192/xpm_memory_sdpram_inst/xpm_memory_base_inst/addra[2]2default:default2default:default2J
 "4
U192/WP_reg[2]	U192/WP_reg[2]2default:default2default:default2B
 *DRC|Netlist|Instance|Required Pin|RAMB18E12default:default8Z	REQP-1840h px? 
?

?RAMB18 async control check: The RAMB18E1 %s has an input control pin %s (net: %s) which is driven by a register (%s) that has an active asychronous set or reset. This may cause corruption of the memory contents and/or read values when the set/reset is asserted and is not analyzed by the default static timing analysis. It is suggested to eliminate the use of a set/reset to registers driving this RAMB pin or else use a synchronous reset in which the assertion of the reset is timed by default.%s*DRC2?
 "?
QU192/xpm_memory_sdpram_inst/xpm_memory_base_inst/gen_wr_a.gen_word_narrow.mem_reg	QU192/xpm_memory_sdpram_inst/xpm_memory_base_inst/gen_wr_a.gen_word_narrow.mem_reg2default:default2default:default2?
 "?
`U192/xpm_memory_sdpram_inst/xpm_memory_base_inst/gen_wr_a.gen_word_narrow.mem_reg/ADDRARDADDR[7]`U192/xpm_memory_sdpram_inst/xpm_memory_base_inst/gen_wr_a.gen_word_narrow.mem_reg/ADDRARDADDR[7]2default:default2default:default2?
 "?
9U192/xpm_memory_sdpram_inst/xpm_memory_base_inst/addra[3]9U192/xpm_memory_sdpram_inst/xpm_memory_base_inst/addra[3]2default:default2default:default2J
 "4
U192/WP_reg[3]	U192/WP_reg[3]2default:default2default:default2B
 *DRC|Netlist|Instance|Required Pin|RAMB18E12default:default8Z	REQP-1840h px? 
?

?RAMB18 async control check: The RAMB18E1 %s has an input control pin %s (net: %s) which is driven by a register (%s) that has an active asychronous set or reset. This may cause corruption of the memory contents and/or read values when the set/reset is asserted and is not analyzed by the default static timing analysis. It is suggested to eliminate the use of a set/reset to registers driving this RAMB pin or else use a synchronous reset in which the assertion of the reset is timed by default.%s*DRC2?
 "?
QU192/xpm_memory_sdpram_inst/xpm_memory_base_inst/gen_wr_a.gen_word_narrow.mem_reg	QU192/xpm_memory_sdpram_inst/xpm_memory_base_inst/gen_wr_a.gen_word_narrow.mem_reg2default:default2default:default2?
 "?
`U192/xpm_memory_sdpram_inst/xpm_memory_base_inst/gen_wr_a.gen_word_narrow.mem_reg/ADDRARDADDR[8]`U192/xpm_memory_sdpram_inst/xpm_memory_base_inst/gen_wr_a.gen_word_narrow.mem_reg/ADDRARDADDR[8]2default:default2default:default2?
 "?
9U192/xpm_memory_sdpram_inst/xpm_memory_base_inst/addra[4]9U192/xpm_memory_sdpram_inst/xpm_memory_base_inst/addra[4]2default:default2default:default2J
 "4
U192/WP_reg[4]	U192/WP_reg[4]2default:default2default:default2B
 *DRC|Netlist|Instance|Required Pin|RAMB18E12default:default8Z	REQP-1840h px? 
?

?RAMB18 async control check: The RAMB18E1 %s has an input control pin %s (net: %s) which is driven by a register (%s) that has an active asychronous set or reset. This may cause corruption of the memory contents and/or read values when the set/reset is asserted and is not analyzed by the default static timing analysis. It is suggested to eliminate the use of a set/reset to registers driving this RAMB pin or else use a synchronous reset in which the assertion of the reset is timed by default.%s*DRC2?
 "?
QU192/xpm_memory_sdpram_inst/xpm_memory_base_inst/gen_wr_a.gen_word_narrow.mem_reg	QU192/xpm_memory_sdpram_inst/xpm_memory_base_inst/gen_wr_a.gen_word_narrow.mem_reg2default:default2default:default2?
 "?
`U192/xpm_memory_sdpram_inst/xpm_memory_base_inst/gen_wr_a.gen_word_narrow.mem_reg/ADDRARDADDR[9]`U192/xpm_memory_sdpram_inst/xpm_memory_base_inst/gen_wr_a.gen_word_narrow.mem_reg/ADDRARDADDR[9]2default:default2default:default2?
 "?
9U192/xpm_memory_sdpram_inst/xpm_memory_base_inst/addra[5]9U192/xpm_memory_sdpram_inst/xpm_memory_base_inst/addra[5]2default:default2default:default2J
 "4
U192/WP_reg[5]	U192/WP_reg[5]2default:default2default:default2B
 *DRC|Netlist|Instance|Required Pin|RAMB18E12default:default8Z	REQP-1840h px? 
?

?RAMB18 async control check: The RAMB18E1 %s has an input control pin %s (net: %s) which is driven by a register (%s) that has an active asychronous set or reset. This may cause corruption of the memory contents and/or read values when the set/reset is asserted and is not analyzed by the default static timing analysis. It is suggested to eliminate the use of a set/reset to registers driving this RAMB pin or else use a synchronous reset in which the assertion of the reset is timed by default.%s*DRC2?
 "?
PU85/xpm_memory_sdpram_inst/xpm_memory_base_inst/gen_wr_a.gen_word_narrow.mem_reg	PU85/xpm_memory_sdpram_inst/xpm_memory_base_inst/gen_wr_a.gen_word_narrow.mem_reg2default:default2default:default2?
 "?
`U85/xpm_memory_sdpram_inst/xpm_memory_base_inst/gen_wr_a.gen_word_narrow.mem_reg/ADDRARDADDR[10]`U85/xpm_memory_sdpram_inst/xpm_memory_base_inst/gen_wr_a.gen_word_narrow.mem_reg/ADDRARDADDR[10]2default:default2default:default2?
 "?
8U85/xpm_memory_sdpram_inst/xpm_memory_base_inst/addra[6]8U85/xpm_memory_sdpram_inst/xpm_memory_base_inst/addra[6]2default:default2default:default2H
 "2
U85/WP_reg[6]	U85/WP_reg[6]2default:default2default:default2B
 *DRC|Netlist|Instance|Required Pin|RAMB18E12default:default8Z	REQP-1840h px? 
?

?RAMB18 async control check: The RAMB18E1 %s has an input control pin %s (net: %s) which is driven by a register (%s) that has an active asychronous set or reset. This may cause corruption of the memory contents and/or read values when the set/reset is asserted and is not analyzed by the default static timing analysis. It is suggested to eliminate the use of a set/reset to registers driving this RAMB pin or else use a synchronous reset in which the assertion of the reset is timed by default.%s*DRC2?
 "?
PU85/xpm_memory_sdpram_inst/xpm_memory_base_inst/gen_wr_a.gen_word_narrow.mem_reg	PU85/xpm_memory_sdpram_inst/xpm_memory_base_inst/gen_wr_a.gen_word_narrow.mem_reg2default:default2default:default2?
 "?
`U85/xpm_memory_sdpram_inst/xpm_memory_base_inst/gen_wr_a.gen_word_narrow.mem_reg/ADDRARDADDR[11]`U85/xpm_memory_sdpram_inst/xpm_memory_base_inst/gen_wr_a.gen_word_narrow.mem_reg/ADDRARDADDR[11]2default:default2default:default2?
 "?
8U85/xpm_memory_sdpram_inst/xpm_memory_base_inst/addra[7]8U85/xpm_memory_sdpram_inst/xpm_memory_base_inst/addra[7]2default:default2default:default2H
 "2
U85/WP_reg[7]	U85/WP_reg[7]2default:default2default:default2B
 *DRC|Netlist|Instance|Required Pin|RAMB18E12default:default8Z	REQP-1840h px? 
?

?RAMB18 async control check: The RAMB18E1 %s has an input control pin %s (net: %s) which is driven by a register (%s) that has an active asychronous set or reset. This may cause corruption of the memory contents and/or read values when the set/reset is asserted and is not analyzed by the default static timing analysis. It is suggested to eliminate the use of a set/reset to registers driving this RAMB pin or else use a synchronous reset in which the assertion of the reset is timed by default.%s*DRC2?
 "?
PU85/xpm_memory_sdpram_inst/xpm_memory_base_inst/gen_wr_a.gen_word_narrow.mem_reg	PU85/xpm_memory_sdpram_inst/xpm_memory_base_inst/gen_wr_a.gen_word_narrow.mem_reg2default:default2default:default2?
 "?
`U85/xpm_memory_sdpram_inst/xpm_memory_base_inst/gen_wr_a.gen_word_narrow.mem_reg/ADDRARDADDR[12]`U85/xpm_memory_sdpram_inst/xpm_memory_base_inst/gen_wr_a.gen_word_narrow.mem_reg/ADDRARDADDR[12]2default:default2default:default2?
 "?
8U85/xpm_memory_sdpram_inst/xpm_memory_base_inst/addra[8]8U85/xpm_memory_sdpram_inst/xpm_memory_base_inst/addra[8]2default:default2default:default2H
 "2
U85/WP_reg[8]	U85/WP_reg[8]2default:default2default:default2B
 *DRC|Netlist|Instance|Required Pin|RAMB18E12default:default8Z	REQP-1840h px? 
?

?RAMB18 async control check: The RAMB18E1 %s has an input control pin %s (net: %s) which is driven by a register (%s) that has an active asychronous set or reset. This may cause corruption of the memory contents and/or read values when the set/reset is asserted and is not analyzed by the default static timing analysis. It is suggested to eliminate the use of a set/reset to registers driving this RAMB pin or else use a synchronous reset in which the assertion of the reset is timed by default.%s*DRC2?
 "?
PU85/xpm_memory_sdpram_inst/xpm_memory_base_inst/gen_wr_a.gen_word_narrow.mem_reg	PU85/xpm_memory_sdpram_inst/xpm_memory_base_inst/gen_wr_a.gen_word_narrow.mem_reg2default:default2default:default2?
 "?
`U85/xpm_memory_sdpram_inst/xpm_memory_base_inst/gen_wr_a.gen_word_narrow.mem_reg/ADDRARDADDR[13]`U85/xpm_memory_sdpram_inst/xpm_memory_base_inst/gen_wr_a.gen_word_narrow.mem_reg/ADDRARDADDR[13]2default:default2default:default2?
 "?
8U85/xpm_memory_sdpram_inst/xpm_memory_base_inst/addra[9]8U85/xpm_memory_sdpram_inst/xpm_memory_base_inst/addra[9]2default:default2default:default2H
 "2
U85/WP_reg[9]	U85/WP_reg[9]2default:default2default:default2B
 *DRC|Netlist|Instance|Required Pin|RAMB18E12default:default8Z	REQP-1840h px? 
?

?RAMB18 async control check: The RAMB18E1 %s has an input control pin %s (net: %s) which is driven by a register (%s) that has an active asychronous set or reset. This may cause corruption of the memory contents and/or read values when the set/reset is asserted and is not analyzed by the default static timing analysis. It is suggested to eliminate the use of a set/reset to registers driving this RAMB pin or else use a synchronous reset in which the assertion of the reset is timed by default.%s*DRC2?
 "?
PU85/xpm_memory_sdpram_inst/xpm_memory_base_inst/gen_wr_a.gen_word_narrow.mem_reg	PU85/xpm_memory_sdpram_inst/xpm_memory_base_inst/gen_wr_a.gen_word_narrow.mem_reg2default:default2default:default2?
 "?
_U85/xpm_memory_sdpram_inst/xpm_memory_base_inst/gen_wr_a.gen_word_narrow.mem_reg/ADDRARDADDR[4]_U85/xpm_memory_sdpram_inst/xpm_memory_base_inst/gen_wr_a.gen_word_narrow.mem_reg/ADDRARDADDR[4]2default:default2default:default2?
 "?
8U85/xpm_memory_sdpram_inst/xpm_memory_base_inst/addra[0]8U85/xpm_memory_sdpram_inst/xpm_memory_base_inst/addra[0]2default:default2default:default2H
 "2
U85/WP_reg[0]	U85/WP_reg[0]2default:default2default:default2B
 *DRC|Netlist|Instance|Required Pin|RAMB18E12default:default8Z	REQP-1840h px? 
?

?RAMB18 async control check: The RAMB18E1 %s has an input control pin %s (net: %s) which is driven by a register (%s) that has an active asychronous set or reset. This may cause corruption of the memory contents and/or read values when the set/reset is asserted and is not analyzed by the default static timing analysis. It is suggested to eliminate the use of a set/reset to registers driving this RAMB pin or else use a synchronous reset in which the assertion of the reset is timed by default.%s*DRC2?
 "?
PU85/xpm_memory_sdpram_inst/xpm_memory_base_inst/gen_wr_a.gen_word_narrow.mem_reg	PU85/xpm_memory_sdpram_inst/xpm_memory_base_inst/gen_wr_a.gen_word_narrow.mem_reg2default:default2default:default2?
 "?
_U85/xpm_memory_sdpram_inst/xpm_memory_base_inst/gen_wr_a.gen_word_narrow.mem_reg/ADDRARDADDR[5]_U85/xpm_memory_sdpram_inst/xpm_memory_base_inst/gen_wr_a.gen_word_narrow.mem_reg/ADDRARDADDR[5]2default:default2default:default2?
 "?
8U85/xpm_memory_sdpram_inst/xpm_memory_base_inst/addra[1]8U85/xpm_memory_sdpram_inst/xpm_memory_base_inst/addra[1]2default:default2default:default2H
 "2
U85/WP_reg[1]	U85/WP_reg[1]2default:default2default:default2B
 *DRC|Netlist|Instance|Required Pin|RAMB18E12default:default8Z	REQP-1840h px? 
?

?RAMB18 async control check: The RAMB18E1 %s has an input control pin %s (net: %s) which is driven by a register (%s) that has an active asychronous set or reset. This may cause corruption of the memory contents and/or read values when the set/reset is asserted and is not analyzed by the default static timing analysis. It is suggested to eliminate the use of a set/reset to registers driving this RAMB pin or else use a synchronous reset in which the assertion of the reset is timed by default.%s*DRC2?
 "?
PU85/xpm_memory_sdpram_inst/xpm_memory_base_inst/gen_wr_a.gen_word_narrow.mem_reg	PU85/xpm_memory_sdpram_inst/xpm_memory_base_inst/gen_wr_a.gen_word_narrow.mem_reg2default:default2default:default2?
 "?
_U85/xpm_memory_sdpram_inst/xpm_memory_base_inst/gen_wr_a.gen_word_narrow.mem_reg/ADDRARDADDR[6]_U85/xpm_memory_sdpram_inst/xpm_memory_base_inst/gen_wr_a.gen_word_narrow.mem_reg/ADDRARDADDR[6]2default:default2default:default2?
 "?
8U85/xpm_memory_sdpram_inst/xpm_memory_base_inst/addra[2]8U85/xpm_memory_sdpram_inst/xpm_memory_base_inst/addra[2]2default:default2default:default2H
 "2
U85/WP_reg[2]	U85/WP_reg[2]2default:default2default:default2B
 *DRC|Netlist|Instance|Required Pin|RAMB18E12default:default8Z	REQP-1840h px? 
?

?RAMB18 async control check: The RAMB18E1 %s has an input control pin %s (net: %s) which is driven by a register (%s) that has an active asychronous set or reset. This may cause corruption of the memory contents and/or read values when the set/reset is asserted and is not analyzed by the default static timing analysis. It is suggested to eliminate the use of a set/reset to registers driving this RAMB pin or else use a synchronous reset in which the assertion of the reset is timed by default.%s*DRC2?
 "?
PU85/xpm_memory_sdpram_inst/xpm_memory_base_inst/gen_wr_a.gen_word_narrow.mem_reg	PU85/xpm_memory_sdpram_inst/xpm_memory_base_inst/gen_wr_a.gen_word_narrow.mem_reg2default:default2default:default2?
 "?
_U85/xpm_memory_sdpram_inst/xpm_memory_base_inst/gen_wr_a.gen_word_narrow.mem_reg/ADDRARDADDR[7]_U85/xpm_memory_sdpram_inst/xpm_memory_base_inst/gen_wr_a.gen_word_narrow.mem_reg/ADDRARDADDR[7]2default:default2default:default2?
 "?
8U85/xpm_memory_sdpram_inst/xpm_memory_base_inst/addra[3]8U85/xpm_memory_sdpram_inst/xpm_memory_base_inst/addra[3]2default:default2default:default2H
 "2
U85/WP_reg[3]	U85/WP_reg[3]2default:default2default:default2B
 *DRC|Netlist|Instance|Required Pin|RAMB18E12default:default8Z	REQP-1840h px? 
?

?RAMB18 async control check: The RAMB18E1 %s has an input control pin %s (net: %s) which is driven by a register (%s) that has an active asychronous set or reset. This may cause corruption of the memory contents and/or read values when the set/reset is asserted and is not analyzed by the default static timing analysis. It is suggested to eliminate the use of a set/reset to registers driving this RAMB pin or else use a synchronous reset in which the assertion of the reset is timed by default.%s*DRC2?
 "?
PU85/xpm_memory_sdpram_inst/xpm_memory_base_inst/gen_wr_a.gen_word_narrow.mem_reg	PU85/xpm_memory_sdpram_inst/xpm_memory_base_inst/gen_wr_a.gen_word_narrow.mem_reg2default:default2default:default2?
 "?
_U85/xpm_memory_sdpram_inst/xpm_memory_base_inst/gen_wr_a.gen_word_narrow.mem_reg/ADDRARDADDR[8]_U85/xpm_memory_sdpram_inst/xpm_memory_base_inst/gen_wr_a.gen_word_narrow.mem_reg/ADDRARDADDR[8]2default:default2default:default2?
 "?
8U85/xpm_memory_sdpram_inst/xpm_memory_base_inst/addra[4]8U85/xpm_memory_sdpram_inst/xpm_memory_base_inst/addra[4]2default:default2default:default2H
 "2
U85/WP_reg[4]	U85/WP_reg[4]2default:default2default:default2B
 *DRC|Netlist|Instance|Required Pin|RAMB18E12default:default8Z	REQP-1840h px? 
?

?RAMB18 async control check: The RAMB18E1 %s has an input control pin %s (net: %s) which is driven by a register (%s) that has an active asychronous set or reset. This may cause corruption of the memory contents and/or read values when the set/reset is asserted and is not analyzed by the default static timing analysis. It is suggested to eliminate the use of a set/reset to registers driving this RAMB pin or else use a synchronous reset in which the assertion of the reset is timed by default.%s*DRC2?
 "?
PU85/xpm_memory_sdpram_inst/xpm_memory_base_inst/gen_wr_a.gen_word_narrow.mem_reg	PU85/xpm_memory_sdpram_inst/xpm_memory_base_inst/gen_wr_a.gen_word_narrow.mem_reg2default:default2default:default2?
 "?
_U85/xpm_memory_sdpram_inst/xpm_memory_base_inst/gen_wr_a.gen_word_narrow.mem_reg/ADDRARDADDR[9]_U85/xpm_memory_sdpram_inst/xpm_memory_base_inst/gen_wr_a.gen_word_narrow.mem_reg/ADDRARDADDR[9]2default:default2default:default2?
 "?
8U85/xpm_memory_sdpram_inst/xpm_memory_base_inst/addra[5]8U85/xpm_memory_sdpram_inst/xpm_memory_base_inst/addra[5]2default:default2default:default2H
 "2
U85/WP_reg[5]	U85/WP_reg[5]2default:default2default:default2B
 *DRC|Netlist|Instance|Required Pin|RAMB18E12default:default8Z	REQP-1840h px? 
c
DRC finished with %s
79*	vivadotcl2)
0 Errors, 43 Warnings2default:defaultZ4-198h px? 
e
BPlease refer to the DRC report (report_drc) for more information.
80*	vivadotclZ4-199h px? 
U

Starting %s Task
103*constraints2
Placer2default:defaultZ18-103h px? 
}
BMultithreading enabled for place_design using a maximum of %s CPUs12*	placeflow2
82default:defaultZ30-611h px? 
v

Phase %s%s
101*constraints2
1 2default:default2)
Placer Initialization2default:defaultZ18-101h px? 
?

Phase %s%s
101*constraints2
1.1 2default:default29
%Placer Initialization Netlist Sorting2default:defaultZ18-101h px? 
?
r%sTime (s): cpu = %s ; elapsed = %s . Memory (MB): peak = %s ; gain = %s ; free physical = %s ; free virtual = %s
480*common2.
Netlist sorting complete. 2default:default2
00:00:00.102default:default2
00:00:00.112default:default2
3480.2662default:default2
0.0002default:default2
188162default:default2
649002default:defaultZ17-722h px? 
[
FPhase 1.1 Placer Initialization Netlist Sorting | Checksum: 12d0b68ef
*commonh px? 
?

%s
*constraints2?
?Time (s): cpu = 00:00:00.12 ; elapsed = 00:00:00.12 . Memory (MB): peak = 3480.266 ; gain = 0.000 ; free physical = 18816 ; free virtual = 649002default:defaulth px? 
E
%Done setting XDC timing constraints.
35*timingZ38-35h px? 
u
)Pushed %s inverter(s) to %s load pin(s).
98*opt2
02default:default2
02default:defaultZ31-138h px? 
?
r%sTime (s): cpu = %s ; elapsed = %s . Memory (MB): peak = %s ; gain = %s ; free physical = %s ; free virtual = %s
480*common2.
Netlist sorting complete. 2default:default2
00:00:00.112default:default2
00:00:00.102default:default2
3480.2662default:default2
0.0002default:default2
188182default:default2
649032default:defaultZ17-722h px? 
?

Phase %s%s
101*constraints2
1.2 2default:default2F
2IO Placement/ Clock Placement/ Build Placer Device2default:defaultZ18-101h px? 
?
?A LUT '%s' is driving clock pin of %s registers. This could lead to large hold time violations. First few involved registers are:
%s524*place20
USBInterface/hitf_cpt[5]_i_12default:default2
122default:default2?
?	U464/TDC/hitf_cpt_reg[0] {FDRE}
	U464/TDC/hitf_cpt_reg[1] {FDRE}
	U464/TDC/hitf_cpt_reg[2] {FDRE}
	U464/TDC/hitf_cpt_reg[3] {FDRE}
	U464/TDC/hitf_cpt_reg[4] {FDRE}
2default:defaultZ30-568h px? 
?
?A LUT '%s' is driving clock pin of %s registers. This could lead to large hold time violations. First few involved registers are:
%s524*place23
USBInterface/hitf_cpt[5]_i_1__02default:default2
122default:default2?
?	U456/TDC/hitf_cpt_reg[0] {FDRE}
	U456/TDC/hitf_cpt_reg[1] {FDRE}
	U456/TDC/hitf_cpt_reg[2] {FDRE}
	U456/TDC/hitf_cpt_reg[3] {FDRE}
	U456/TDC/hitf_cpt_reg[4] {FDRE}
2default:defaultZ30-568h px? 
?
?A LUT '%s' is driving clock pin of %s registers. This could lead to large hold time violations. First few involved registers are:
%s524*place23
USBInterface/hitf_cpt[5]_i_1__12default:default2
122default:default2?
?	U460/TDC/hitf_cpt_reg[0] {FDRE}
	U460/TDC/hitf_cpt_reg[1] {FDRE}
	U460/TDC/hitf_cpt_reg[2] {FDRE}
	U460/TDC/hitf_cpt_reg[3] {FDRE}
	U460/TDC/hitf_cpt_reg[4] {FDRE}
2default:defaultZ30-568h px? 
?
?A LUT '%s' is driving clock pin of %s registers. This could lead to large hold time violations. First few involved registers are:
%s524*place23
USBInterface/hitf_cpt[5]_i_1__22default:default2
122default:default2?
?	U452/TDC/hitf_cpt_reg[0] {FDRE}
	U452/TDC/hitf_cpt_reg[1] {FDRE}
	U452/TDC/hitf_cpt_reg[2] {FDRE}
	U452/TDC/hitf_cpt_reg[3] {FDRE}
	U452/TDC/hitf_cpt_reg[4] {FDRE}
2default:defaultZ30-568h px? 
E
%Done setting XDC timing constraints.
35*timingZ38-35h px? 
h
SPhase 1.2 IO Placement/ Clock Placement/ Build Placer Device | Checksum: 113a57e1e
*commonh px? 
?

%s
*constraints2?
?Time (s): cpu = 00:00:25 ; elapsed = 00:00:14 . Memory (MB): peak = 3480.266 ; gain = 0.000 ; free physical = 18690 ; free virtual = 647752default:defaulth px? 
}

Phase %s%s
101*constraints2
1.3 2default:default2.
Build Placer Netlist Model2default:defaultZ18-101h px? 
P
;Phase 1.3 Build Placer Netlist Model | Checksum: 17f576122
*commonh px? 
?

%s
*constraints2?
?Time (s): cpu = 00:00:44 ; elapsed = 00:00:24 . Memory (MB): peak = 3480.266 ; gain = 0.000 ; free physical = 18540 ; free virtual = 646262default:defaulth px? 
z

Phase %s%s
101*constraints2
1.4 2default:default2+
Constrain Clocks/Macros2default:defaultZ18-101h px? 
M
8Phase 1.4 Constrain Clocks/Macros | Checksum: 17f576122
*commonh px? 
?

%s
*constraints2?
?Time (s): cpu = 00:00:44 ; elapsed = 00:00:25 . Memory (MB): peak = 3480.266 ; gain = 0.000 ; free physical = 18540 ; free virtual = 646262default:defaulth px? 
I
4Phase 1 Placer Initialization | Checksum: 17f576122
*commonh px? 
?

%s
*constraints2?
?Time (s): cpu = 00:00:44 ; elapsed = 00:00:25 . Memory (MB): peak = 3480.266 ; gain = 0.000 ; free physical = 18540 ; free virtual = 646262default:defaulth px? 
q

Phase %s%s
101*constraints2
2 2default:default2$
Global Placement2default:defaultZ18-101h px? 
D
/Phase 2 Global Placement | Checksum: 115cbf07e
*commonh px? 
?

%s
*constraints2?
?Time (s): cpu = 00:02:11 ; elapsed = 00:01:04 . Memory (MB): peak = 3480.266 ; gain = 0.000 ; free physical = 18459 ; free virtual = 645452default:defaulth px? 
q

Phase %s%s
101*constraints2
3 2default:default2$
Detail Placement2default:defaultZ18-101h px? 
}

Phase %s%s
101*constraints2
3.1 2default:default2.
Commit Multi Column Macros2default:defaultZ18-101h px? 
P
;Phase 3.1 Commit Multi Column Macros | Checksum: 115cbf07e
*commonh px? 
?

%s
*constraints2?
?Time (s): cpu = 00:02:11 ; elapsed = 00:01:05 . Memory (MB): peak = 3480.266 ; gain = 0.000 ; free physical = 18459 ; free virtual = 645442default:defaulth px? 


Phase %s%s
101*constraints2
3.2 2default:default20
Commit Most Macros & LUTRAMs2default:defaultZ18-101h px? 
R
=Phase 3.2 Commit Most Macros & LUTRAMs | Checksum: 1b9393aaf
*commonh px? 
?

%s
*constraints2?
?Time (s): cpu = 00:02:27 ; elapsed = 00:01:11 . Memory (MB): peak = 3480.266 ; gain = 0.000 ; free physical = 18445 ; free virtual = 645302default:defaulth px? 
y

Phase %s%s
101*constraints2
3.3 2default:default2*
Area Swap Optimization2default:defaultZ18-101h px? 
L
7Phase 3.3 Area Swap Optimization | Checksum: 1f8e73d2c
*commonh px? 
?

%s
*constraints2?
?Time (s): cpu = 00:02:28 ; elapsed = 00:01:11 . Memory (MB): peak = 3480.266 ; gain = 0.000 ; free physical = 18445 ; free virtual = 645302default:defaulth px? 
?

Phase %s%s
101*constraints2
3.4 2default:default22
Pipeline Register Optimization2default:defaultZ18-101h px? 
T
?Phase 3.4 Pipeline Register Optimization | Checksum: 1b2618f62
*commonh px? 
?

%s
*constraints2?
?Time (s): cpu = 00:02:28 ; elapsed = 00:01:11 . Memory (MB): peak = 3480.266 ; gain = 0.000 ; free physical = 18445 ; free virtual = 645312default:defaulth px? 
x

Phase %s%s
101*constraints2
3.5 2default:default2)
Timing Path Optimizer2default:defaultZ18-101h px? 
K
6Phase 3.5 Timing Path Optimizer | Checksum: 1b2618f62
*commonh px? 
?

%s
*constraints2?
?Time (s): cpu = 00:02:28 ; elapsed = 00:01:12 . Memory (MB): peak = 3480.266 ; gain = 0.000 ; free physical = 18445 ; free virtual = 645302default:defaulth px? 
t

Phase %s%s
101*constraints2
3.6 2default:default2%
Fast Optimization2default:defaultZ18-101h px? 
G
2Phase 3.6 Fast Optimization | Checksum: 1aa089b5e
*commonh px? 
?

%s
*constraints2?
?Time (s): cpu = 00:02:29 ; elapsed = 00:01:12 . Memory (MB): peak = 3480.266 ; gain = 0.000 ; free physical = 18441 ; free virtual = 645262default:defaulth px? 


Phase %s%s
101*constraints2
3.7 2default:default20
Small Shape Detail Placement2default:defaultZ18-101h px? 
t

Phase %s%s
101*constraints2
3.7.1 2default:default2#
Place Remaining2default:defaultZ18-101h px? 
G
2Phase 3.7.1 Place Remaining | Checksum: 1995d5c7f
*commonh px? 
?

%s
*constraints2?
?Time (s): cpu = 00:02:55 ; elapsed = 00:01:37 . Memory (MB): peak = 3480.266 ; gain = 0.000 ; free physical = 18301 ; free virtual = 643872default:defaulth px? 
R
=Phase 3.7 Small Shape Detail Placement | Checksum: 1995d5c7f
*commonh px? 
?

%s
*constraints2?
?Time (s): cpu = 00:02:56 ; elapsed = 00:01:38 . Memory (MB): peak = 3480.266 ; gain = 0.000 ; free physical = 18325 ; free virtual = 644122default:defaulth px? 
u

Phase %s%s
101*constraints2
3.8 2default:default2&
Re-assign LUT pins2default:defaultZ18-101h px? 
H
3Phase 3.8 Re-assign LUT pins | Checksum: 1a8a901e1
*commonh px? 
?

%s
*constraints2?
?Time (s): cpu = 00:02:57 ; elapsed = 00:01:39 . Memory (MB): peak = 3480.266 ; gain = 0.000 ; free physical = 18330 ; free virtual = 644162default:defaulth px? 
?

Phase %s%s
101*constraints2
3.9 2default:default22
Pipeline Register Optimization2default:defaultZ18-101h px? 
T
?Phase 3.9 Pipeline Register Optimization | Checksum: 156c486ff
*commonh px? 
?

%s
*constraints2?
?Time (s): cpu = 00:03:00 ; elapsed = 00:01:42 . Memory (MB): peak = 3480.266 ; gain = 0.000 ; free physical = 18330 ; free virtual = 644162default:defaulth px? 
u

Phase %s%s
101*constraints2
3.10 2default:default2%
Fast Optimization2default:defaultZ18-101h px? 
H
3Phase 3.10 Fast Optimization | Checksum: 1a3a816b4
*commonh px? 
?

%s
*constraints2?
?Time (s): cpu = 00:03:12 ; elapsed = 00:01:47 . Memory (MB): peak = 3480.266 ; gain = 0.000 ; free physical = 18347 ; free virtual = 644332default:defaulth px? 
D
/Phase 3 Detail Placement | Checksum: 1a3a816b4
*commonh px? 
?

%s
*constraints2?
?Time (s): cpu = 00:03:13 ; elapsed = 00:01:48 . Memory (MB): peak = 3480.266 ; gain = 0.000 ; free physical = 18348 ; free virtual = 644342default:defaulth px? 
?

Phase %s%s
101*constraints2
4 2default:default2<
(Post Placement Optimization and Clean-Up2default:defaultZ18-101h px? 
{

Phase %s%s
101*constraints2
4.1 2default:default2,
Post Commit Optimization2default:defaultZ18-101h px? 
E
%Done setting XDC timing constraints.
35*timingZ38-35h px? 
?

Phase %s%s
101*constraints2
4.1.1 2default:default2/
Post Placement Optimization2default:defaultZ18-101h px? 
V
APost Placement Optimization Initialization | Checksum: 14bb9b0d5
*commonh px? 
u

Phase %s%s
101*constraints2
4.1.1.1 2default:default2"
BUFG Insertion2default:defaultZ18-101h px? 
?
EMultithreading enabled for phys_opt_design using a maximum of %s CPUs380*physynth2
82default:defaultZ32-721h px? 
?
PProcessed net %s, BUFG insertion was skipped due to placement/routing conflicts.32*	placeflow2!
U422/U422_out2default:defaultZ46-33h px? 
?
PProcessed net %s, BUFG insertion was skipped due to placement/routing conflicts.32*	placeflow2*
U617/sec_pulse_reg_n_02default:defaultZ46-33h px? 
?
PProcessed net %s, BUFG insertion was skipped due to placement/routing conflicts.32*	placeflow2*
U615/sec_pulse_reg_n_02default:defaultZ46-33h px? 
?
PProcessed net %s, BUFG insertion was skipped due to placement/routing conflicts.32*	placeflow2*
U613/sec_pulse_reg_n_02default:defaultZ46-33h px? 
?
PProcessed net %s, BUFG insertion was skipped due to placement/routing conflicts.32*	placeflow2*
U611/sec_pulse_reg_n_02default:defaultZ46-33h px? 
?
PProcessed net %s, BUFG insertion was skipped due to placement/routing conflicts.32*	placeflow21
U447/xpm_fifo_async_inst/E[0]2default:defaultZ46-33h px? 
?
PProcessed net %s, BUFG insertion was skipped due to placement/routing conflicts.32*	placeflow2<
(U253/ASIC_BITSTREAM_CFG[1140]_i_1__2_n_02default:defaultZ46-33h px? 
?
PProcessed net %s, BUFG insertion was skipped due to placement/routing conflicts.32*	placeflow2<
(U251/ASIC_BITSTREAM_CFG[1140]_i_1__1_n_02default:defaultZ46-33h px? 
?
PProcessed net %s, BUFG insertion was skipped due to placement/routing conflicts.32*	placeflow2<
(U249/ASIC_BITSTREAM_CFG[1140]_i_1__0_n_02default:defaultZ46-33h px? 
?
PProcessed net %s, BUFG insertion was skipped due to placement/routing conflicts.32*	placeflow27
#U1/ASIC_BITSTREAM_CFG[1140]_i_1_n_02default:defaultZ46-33h px? 
?
PProcessed net %s, BUFG insertion was skipped due to placement/routing conflicts.32*	placeflow2@
,USBInterface/arbiter.FIFODATALATCH_reg[0][0]2default:defaultZ46-33h px? 
?
?BUFG insertion identified %s candidate nets, %s success, %s skipped for placement/routing, %s skipped for timing, %s skipped for netlist change reason.30*	placeflow2
112default:default2
02default:default2
112default:default2
02default:default2
02default:defaultZ46-31h px? 
H
3Phase 4.1.1.1 BUFG Insertion | Checksum: 14bb9b0d5
*commonh px? 
?

%s
*constraints2?
?Time (s): cpu = 00:03:38 ; elapsed = 00:01:57 . Memory (MB): peak = 3480.266 ; gain = 0.000 ; free physical = 18382 ; free virtual = 644682default:defaulth px? 
?
hPost Placement Timing Summary WNS=%s. For the most accurate timing information please run report_timing.610*place2
0.4272default:defaultZ30-746h px? 
S
>Phase 4.1.1 Post Placement Optimization | Checksum: 11617b4ad
*commonh px? 
?

%s
*constraints2?
?Time (s): cpu = 00:04:19 ; elapsed = 00:02:24 . Memory (MB): peak = 3480.266 ; gain = 0.000 ; free physical = 18376 ; free virtual = 644622default:defaulth px? 
N
9Phase 4.1 Post Commit Optimization | Checksum: 11617b4ad
*commonh px? 
?

%s
*constraints2?
?Time (s): cpu = 00:04:19 ; elapsed = 00:02:25 . Memory (MB): peak = 3480.266 ; gain = 0.000 ; free physical = 18376 ; free virtual = 644622default:defaulth px? 
y

Phase %s%s
101*constraints2
4.2 2default:default2*
Post Placement Cleanup2default:defaultZ18-101h px? 
L
7Phase 4.2 Post Placement Cleanup | Checksum: 11617b4ad
*commonh px? 
?

%s
*constraints2?
?Time (s): cpu = 00:04:20 ; elapsed = 00:02:26 . Memory (MB): peak = 3480.266 ; gain = 0.000 ; free physical = 18378 ; free virtual = 644642default:defaulth px? 
s

Phase %s%s
101*constraints2
4.3 2default:default2$
Placer Reporting2default:defaultZ18-101h px? 
F
1Phase 4.3 Placer Reporting | Checksum: 11617b4ad
*commonh px? 
?

%s
*constraints2?
?Time (s): cpu = 00:04:21 ; elapsed = 00:02:26 . Memory (MB): peak = 3480.266 ; gain = 0.000 ; free physical = 18378 ; free virtual = 644632default:defaulth px? 
z

Phase %s%s
101*constraints2
4.4 2default:default2+
Final Placement Cleanup2default:defaultZ18-101h px? 
M
8Phase 4.4 Final Placement Cleanup | Checksum: 1a47326e1
*commonh px? 
?

%s
*constraints2?
?Time (s): cpu = 00:04:21 ; elapsed = 00:02:27 . Memory (MB): peak = 3480.266 ; gain = 0.000 ; free physical = 18377 ; free virtual = 644632default:defaulth px? 
\
GPhase 4 Post Placement Optimization and Clean-Up | Checksum: 1a47326e1
*commonh px? 
?

%s
*constraints2?
?Time (s): cpu = 00:04:22 ; elapsed = 00:02:27 . Memory (MB): peak = 3480.266 ; gain = 0.000 ; free physical = 18377 ; free virtual = 644632default:defaulth px? 
>
)Ending Placer Task | Checksum: 14f4f699f
*commonh px? 
?

%s
*constraints2?
?Time (s): cpu = 00:04:22 ; elapsed = 00:02:28 . Memory (MB): peak = 3480.266 ; gain = 0.000 ; free physical = 18473 ; free virtual = 645582default:defaulth px? 
Z
Releasing license: %s
83*common2"
Implementation2default:defaultZ17-83h px? 
?
G%s Infos, %s Warnings, %s Critical Warnings and %s Errors encountered.
28*	vivadotcl2
1812default:default2
1832default:default2
212default:default2
02default:defaultZ4-41h px? 
^
%s completed successfully
29*	vivadotcl2 
place_design2default:defaultZ4-42h px? 
?
r%sTime (s): cpu = %s ; elapsed = %s . Memory (MB): peak = %s ; gain = %s ; free physical = %s ; free virtual = %s
480*common2"
place_design: 2default:default2
00:04:292default:default2
00:02:332default:default2
3480.2662default:default2
0.0002default:default2
184732default:default2
645592default:defaultZ17-722h px? 
D
Writing placer database...
1603*designutilsZ20-1893h px? 
=
Writing XDEF routing.
211*designutilsZ20-211h px? 
J
#Writing XDEF routing logical nets.
209*designutilsZ20-209h px? 
J
#Writing XDEF routing special nets.
210*designutilsZ20-210h px? 
?
r%sTime (s): cpu = %s ; elapsed = %s . Memory (MB): peak = %s ; gain = %s ; free physical = %s ; free virtual = %s
480*common2)
Write XDEF Complete: 2default:default2
00:00:082default:default2
00:00:032default:default2
3480.2662default:default2
0.0002default:default2
183212default:default2
645252default:defaultZ17-722h px? 
?
 The %s '%s' has been generated.
621*common2

checkpoint2default:default2}
i/home/utente/projects/CitirocRedoutFullV/CitirocRedoutFullV.runs/impl_1/TOP_CitirocRedoutFullV_placed.dcp2default:defaultZ17-1381h px? 
?
r%sTime (s): cpu = %s ; elapsed = %s . Memory (MB): peak = %s ; gain = %s ; free physical = %s ; free virtual = %s
480*common2&
write_checkpoint: 2default:default2
00:00:202default:default2
00:00:142default:default2
3480.2662default:default2
0.0002default:default2
184332default:default2
645442default:defaultZ17-722h px? 
q
%s4*runtcl2U
AExecuting : report_io -file TOP_CitirocRedoutFullV_io_placed.rpt
2default:defaulth px? 
?
?report_io: Time (s): cpu = 00:00:00.15 ; elapsed = 00:00:00.23 . Memory (MB): peak = 3480.266 ; gain = 0.000 ; free physical = 18417 ; free virtual = 64528
*commonh px? 
?
%s4*runtcl2?
?Executing : report_utilization -file TOP_CitirocRedoutFullV_utilization_placed.rpt -pb TOP_CitirocRedoutFullV_utilization_placed.pb
2default:defaulth px? 
?
?report_utilization: Time (s): cpu = 00:00:00.76 ; elapsed = 00:00:00.83 . Memory (MB): peak = 3480.266 ; gain = 0.000 ; free physical = 18432 ; free virtual = 64543
*commonh px? 
?
%s4*runtcl2r
^Executing : report_control_sets -verbose -file TOP_CitirocRedoutFullV_control_sets_placed.rpt
2default:defaulth px? 
?
?report_control_sets: Time (s): cpu = 00:00:00.25 ; elapsed = 00:00:00.33 . Memory (MB): peak = 3480.266 ; gain = 0.000 ; free physical = 18431 ; free virtual = 64543
*commonh px? 


End Record