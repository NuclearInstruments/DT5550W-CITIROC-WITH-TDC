set outputDir C:/OpenHardware/UserProject/CitirocRedoutFullV/output/CitirocRedoutFullV
file mkdir $outputDir
create_project CitirocRedoutFullV C:/OpenHardware/UserProject/CitirocRedoutFullV/output/CitirocRedoutFullV -part XC7K160TFFG676-2 -force
set_property source_mgmt_mode None [current_project]
set_property target_language VHDL [current_project]
set_property XPM_LIBRARIES {XPM_CDC XPM_MEMORY XPM_FIFO} [current_project]
add_files -force C:/OpenHardware/UserProject/CitirocRedoutFullV/HDL/pcores/clk_wiz_0.xcix
add_files -force C:/OpenHardware/UserProject/CitirocRedoutFullV/HDL/pcores/clk_wiz_0.xcix
add_files -force C:/OpenHardware/UserProject/CitirocRedoutFullV/HDL/pcores/DTClockGenerator.xci
add_files -force C:/OpenHardware/UserProject/CitirocRedoutFullV/HDL/pcores/fast_clock.xci
add_files -force C:/OpenHardware/UserProject/CitirocRedoutFullV/HDL/pcores/fifo_generator_0.xcix
add_files -force C:/OpenHardware/UserProject/CitirocRedoutFullV/HDL/pcores/fifo_generator_0.xcix
add_files -force C:/OpenHardware/UserProject/CitirocRedoutFullV/HDL/pcores/FlashPageMemory.xci
add_files -force C:/OpenHardware/UserProject/CitirocRedoutFullV/HDL/pcores/FTDI_FIFOs.xci
add_files -force C:/OpenHardware/UserProject/CitirocRedoutFullV/HDL/pcores/FTDI_FIFO_AW.xci
add_files -force C:/OpenHardware/UserProject/CitirocRedoutFullV/HDL/pcores/tdc_05ns_pll.xci
add_files -force C:/OpenHardware/UserProject/CitirocRedoutFullV/HDL/pcores/TestBram.xci
add_files -force C:/OpenHardware/UserProject/CitirocRedoutFullV/HDL/subpage_frameproc.vhd
add_files -force C:/OpenHardware/UserProject/CitirocRedoutFullV/HDL/subpage_Framing.vhd
add_files -force C:/OpenHardware/UserProject/CitirocRedoutFullV/HDL/subpage_Timer64.vhd
add_files -force C:/OpenHardware/UserProject/CitirocRedoutFullV/HDL/subpage_TriggerLogic.vhd
add_files -force C:/OpenHardware/UserProject/CitirocRedoutFullV/HDL/top_CitirocRedoutFullV.vhd
add_files -force C:/OpenHardware/UserProject/CitirocRedoutFullV/HDL/pcores/ADC1.v
add_files -force C:/OpenHardware/UserProject/CitirocRedoutFullV/HDL/pcores/adcs_top.vhd
add_files -force C:/OpenHardware/UserProject/CitirocRedoutFullV/HDL/pcores/adcs_top.vhd
add_files -force C:/OpenHardware/UserProject/CitirocRedoutFullV/HDL/pcores/ADC_FRAME_S.vhd
add_files -force C:/OpenHardware/UserProject/CitirocRedoutFullV/HDL/pcores/ADC_FRAME_S.vhd
add_files -force C:/OpenHardware/UserProject/CitirocRedoutFullV/HDL/pcores/adc_interface.vhd
add_files -force C:/OpenHardware/UserProject/CitirocRedoutFullV/HDL/pcores/adc_interface.vhd
add_files -force C:/OpenHardware/UserProject/CitirocRedoutFullV/HDL/pcores/adc_sync.vhd
add_files -force C:/OpenHardware/UserProject/CitirocRedoutFullV/HDL/pcores/adc_sync.vhd
add_files -force C:/OpenHardware/UserProject/CitirocRedoutFullV/HDL/pcores/chronoenable.vhd
add_files -force C:/OpenHardware/UserProject/CitirocRedoutFullV/HDL/pcores/chronoenable.vhd
add_files -force C:/OpenHardware/UserProject/CitirocRedoutFullV/HDL/pcores/CitirocAnalogReadoutV2.vhd
add_files -force C:/OpenHardware/UserProject/CitirocRedoutFullV/HDL/pcores/CitirocAnalogReadoutV2.vhd
add_files -force C:/OpenHardware/UserProject/CitirocRedoutFullV/HDL/pcores/CitirocFrameTransferV2.vhd
add_files -force C:/OpenHardware/UserProject/CitirocRedoutFullV/HDL/pcores/CitirocFrameTransferV2.vhd
add_files -force C:/OpenHardware/UserProject/CitirocRedoutFullV/HDL/pcores/CitirocSlowControl.vhd
add_files -force C:/OpenHardware/UserProject/CitirocRedoutFullV/HDL/pcores/CitirocSlowControl.vhd
add_files -force C:/OpenHardware/UserProject/CitirocRedoutFullV/HDL/pcores/comparator.vhd
add_files -force C:/OpenHardware/UserProject/CitirocRedoutFullV/HDL/pcores/comparator.vhd
add_files -force C:/OpenHardware/UserProject/CitirocRedoutFullV/HDL/pcores/counter_rising.vhd
add_files -force C:/OpenHardware/UserProject/CitirocRedoutFullV/HDL/pcores/counter_rising.vhd
add_files -force C:/OpenHardware/UserProject/CitirocRedoutFullV/HDL/pcores/DT5550W_iic.vhd
add_files -force C:/OpenHardware/UserProject/CitirocRedoutFullV/HDL/pcores/DT5550W_iic.vhd
add_files -force C:/OpenHardware/UserProject/CitirocRedoutFullV/HDL/pcores/d_latch.vhd
add_files -force C:/OpenHardware/UserProject/CitirocRedoutFullV/HDL/pcores/d_latch.vhd
add_files -force C:/OpenHardware/UserProject/CitirocRedoutFullV/HDL/pcores/edge_pos.vhd
add_files -force C:/OpenHardware/UserProject/CitirocRedoutFullV/HDL/pcores/edge_pos.vhd
add_files -force C:/OpenHardware/UserProject/CitirocRedoutFullV/HDL/pcores/ff_sr.vhd
add_files -force C:/OpenHardware/UserProject/CitirocRedoutFullV/HDL/pcores/ff_sr.vhd
add_files -force C:/OpenHardware/UserProject/CitirocRedoutFullV/HDL/pcores/FlashController.vhd
add_files -force C:/OpenHardware/UserProject/CitirocRedoutFullV/HDL/pcores/FlashController.vhd
add_files -force C:/OpenHardware/UserProject/CitirocRedoutFullV/HDL/pcores/flash_prog.vhd
add_files -force C:/OpenHardware/UserProject/CitirocRedoutFullV/HDL/pcores/flash_prog.vhd
add_files -force C:/OpenHardware/UserProject/CitirocRedoutFullV/HDL/pcores/frequency_meter.vhd
add_files -force C:/OpenHardware/UserProject/CitirocRedoutFullV/HDL/pcores/frequency_meter.vhd
add_files -force C:/OpenHardware/UserProject/CitirocRedoutFullV/HDL/pcores/ft600_fifo245_core.vhd
add_files -force C:/OpenHardware/UserProject/CitirocRedoutFullV/HDL/pcores/ft600_fifo245_core.vhd
add_files -force C:/OpenHardware/UserProject/CitirocRedoutFullV/HDL/pcores/ft600_fifo245_wrapper.vhd
add_files -force C:/OpenHardware/UserProject/CitirocRedoutFullV/HDL/pcores/ft600_fifo245_wrapper.vhd
add_files -force C:/OpenHardware/UserProject/CitirocRedoutFullV/HDL/pcores/iic_master_andrea.vhd
add_files -force C:/OpenHardware/UserProject/CitirocRedoutFullV/HDL/pcores/iic_master_andrea.vhd
add_files -force C:/OpenHardware/UserProject/CitirocRedoutFullV/HDL/pcores/init_clock_gen.vhd
add_files -force C:/OpenHardware/UserProject/CitirocRedoutFullV/HDL/pcores/init_clock_gen.vhd
add_files -force C:/OpenHardware/UserProject/CitirocRedoutFullV/HDL/pcores/MCRateMeter.vhd
add_files -force C:/OpenHardware/UserProject/CitirocRedoutFullV/HDL/pcores/MCRateMeter.vhd
add_files -force C:/OpenHardware/UserProject/CitirocRedoutFullV/HDL/pcores/pulseshaper.vhd
add_files -force C:/OpenHardware/UserProject/CitirocRedoutFullV/HDL/pcores/pulseshaper.vhd
add_files -force C:/OpenHardware/UserProject/CitirocRedoutFullV/HDL/pcores/PULSE_GENERATOR.vhd
add_files -force C:/OpenHardware/UserProject/CitirocRedoutFullV/HDL/pcores/PULSE_GENERATOR.vhd
add_files -force C:/OpenHardware/UserProject/CitirocRedoutFullV/HDL/pcores/security.vhd
add_files -force C:/OpenHardware/UserProject/CitirocRedoutFullV/HDL/pcores/security.vhd
add_files -force C:/OpenHardware/UserProject/CitirocRedoutFullV/HDL/pcores/spi32bit_master_write.vhd
add_files -force C:/OpenHardware/UserProject/CitirocRedoutFullV/HDL/pcores/spi32bit_master_write.vhd
add_files -force C:/OpenHardware/UserProject/CitirocRedoutFullV/HDL/pcores/spi93lc56_16bit.vhd
add_files -force C:/OpenHardware/UserProject/CitirocRedoutFullV/HDL/pcores/spi93lc56_16bit.vhd
add_files -force C:/OpenHardware/UserProject/CitirocRedoutFullV/HDL/pcores/spi_timing_module.vhd
add_files -force C:/OpenHardware/UserProject/CitirocRedoutFullV/HDL/pcores/spi_timing_module.vhd
add_files -force C:/OpenHardware/UserProject/CitirocRedoutFullV/HDL/pcores/tdc_sync_nofifo.vhd
add_files -force C:/OpenHardware/UserProject/CitirocRedoutFullV/HDL/pcores/tdc_sync_nofifo.vhd
add_files -force C:/OpenHardware/UserProject/CitirocRedoutFullV/HDL/pcores/TimestampGenerator.vhd
add_files -force C:/OpenHardware/UserProject/CitirocRedoutFullV/HDL/pcores/TimestampGenerator.vhd
add_files -force C:/OpenHardware/UserProject/CitirocRedoutFullV/HDL/pcores/U447_custompacket.vhd
add_files -force C:/OpenHardware/UserProject/CitirocRedoutFullV/HDL/pcores/U447_custompacket.vhd
add_files -force C:/OpenHardware/UserProject/CitirocRedoutFullV/HDL/pcores/xlx_oscilloscope_sync.vhd
add_files -force C:/OpenHardware/UserProject/CitirocRedoutFullV/HDL/pcores/xlx_oscilloscope_sync.vhd
add_files -force C:/OpenHardware/UserProject/CitirocRedoutFullV/HDL/pcores/xlx_soft_gd.vhd
add_files -force C:/OpenHardware/UserProject/CitirocRedoutFullV/HDL/pcores/xlx_soft_gd.vhd
add_files -force -fileset constrs_1 C:/OpenHardware/UserProject/CitirocRedoutFullV/HDL/dt555w_constraints.xdc
import_files -force -norecurse
import_files -fileset constrs_1 -force -norecurse C:/OpenHardware/UserProject/CitirocRedoutFullV/HDL/dt555w_constraints.xdc
foreach ip [get_ips] {
upgrade_ip [get_ips $ip]
set ip_filename [get_property IP_FILE $ip]
set ip_dcp [file rootname $ip_filename]
append ip_dcp ".dcp"
set ip_xml [file rootname $ip_filename]
append ip_xml ".xml"
if {([file exists $ip_dcp] == 0) || [expr {[file mtime $ip_filename ] > [file mtime $ip_dcp ]}]} {
reset_target all $ip
file delete $ip_xml
generate_target all $ip
}
}
set_property Top top_CitirocRedoutFullV [current_fileset]
set obj [get_runs impl_1]
set obj_s [get_runs synth_1]
set_property -name "steps.write_bitstream.args.bin_file" -value "1" -objects $obj
exit
