
Q
Command: %s
53*	vivadotcl2 
route_design2default:defaultZ4-113h px? 
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
p
,Running DRC as a precondition to command %s
22*	vivadotcl2 
route_design2default:defaultZ4-22h px? 
P
Running DRC with %s threads
24*drc2
82default:defaultZ23-27h px? 
?
?CONFIG_VOLTAGE with Config Bank VCCO: The CONFIG_MODE property of current_design specifies a configuration mode (SPIx4) that uses pins in bank %s.  I/O standards used in this bank have a voltage requirement of 2.50.  However, the CONFIG_VOLTAGE for current_design is set to 1.8.  Ensure that your configuration voltage is compatible with the I/O standards in banks used by your configuration mode.  Refer to device configuration user guide for more information.    Pins used by config mode: B24 (IO_L1P_T0_D00_MOSI_14), A25 (IO_L1N_T0_D01_DIN_14), B22 (IO_L2P_T0_D02_14), A22 (IO_L2N_T0_D03_14), B25 (IO_L3P_T0_DQS_PUDC_B_14), and C23 (IO_L6P_T0_FCS_B_14)%s*DRC2.
 "
142default:default2default:default2(
 DRC|Pin Planning2default:default8ZCFGBVS-7h px? 
b
DRC finished with %s
79*	vivadotcl2(
0 Errors, 1 Warnings2default:defaultZ4-198h px? 
e
BPlease refer to the DRC report (report_drc) for more information.
80*	vivadotclZ4-199h px? 
V

Starting %s Task
103*constraints2
Routing2default:defaultZ18-103h px? 
}
BMultithreading enabled for route_design using a maximum of %s CPUs17*	routeflow2
82default:defaultZ35-254h px? 
p

Phase %s%s
101*constraints2
1 2default:default2#
Build RT Design2default:defaultZ18-101h px? 
C
.Phase 1 Build RT Design | Checksum: 16d8b4f10
*commonh px? 
?

%s
*constraints2?
?Time (s): cpu = 00:00:25 ; elapsed = 00:00:12 . Memory (MB): peak = 3480.266 ; gain = 0.000 ; free physical = 18224 ; free virtual = 643362default:defaulth px? 
v

Phase %s%s
101*constraints2
2 2default:default2)
Router Initialization2default:defaultZ18-101h px? 
o

Phase %s%s
101*constraints2
2.1 2default:default2 
Create Timer2default:defaultZ18-101h px? 
B
-Phase 2.1 Create Timer | Checksum: 16d8b4f10
*commonh px? 
?

%s
*constraints2?
?Time (s): cpu = 00:00:27 ; elapsed = 00:00:14 . Memory (MB): peak = 3480.266 ; gain = 0.000 ; free physical = 18223 ; free virtual = 643342default:defaulth px? 
{

Phase %s%s
101*constraints2
2.2 2default:default2,
Fix Topology Constraints2default:defaultZ18-101h px? 
N
9Phase 2.2 Fix Topology Constraints | Checksum: 16d8b4f10
*commonh px? 
?

%s
*constraints2?
?Time (s): cpu = 00:00:28 ; elapsed = 00:00:14 . Memory (MB): peak = 3480.266 ; gain = 0.000 ; free physical = 18182 ; free virtual = 642942default:defaulth px? 
t

Phase %s%s
101*constraints2
2.3 2default:default2%
Pre Route Cleanup2default:defaultZ18-101h px? 
G
2Phase 2.3 Pre Route Cleanup | Checksum: 16d8b4f10
*commonh px? 
?

%s
*constraints2?
?Time (s): cpu = 00:00:28 ; elapsed = 00:00:15 . Memory (MB): peak = 3480.266 ; gain = 0.000 ; free physical = 18182 ; free virtual = 642942default:defaulth px? 
p

Phase %s%s
101*constraints2
2.4 2default:default2!
Update Timing2default:defaultZ18-101h px? 
C
.Phase 2.4 Update Timing | Checksum: 132a19710
*commonh px? 
?

%s
*constraints2?
?Time (s): cpu = 00:00:59 ; elapsed = 00:00:28 . Memory (MB): peak = 3480.266 ; gain = 0.000 ; free physical = 18152 ; free virtual = 642642default:defaulth px? 
?
Intermediate Timing Summary %s164*route2L
8| WNS=0.370  | TNS=0.000  | WHS=-1.934 | THS=-3929.553|
2default:defaultZ35-416h px? 
}

Phase %s%s
101*constraints2
2.5 2default:default2.
Update Timing for Bus Skew2default:defaultZ18-101h px? 
r

Phase %s%s
101*constraints2
2.5.1 2default:default2!
Update Timing2default:defaultZ18-101h px? 
E
0Phase 2.5.1 Update Timing | Checksum: 18af8a645
*commonh px? 
?

%s
*constraints2?
?Time (s): cpu = 00:01:22 ; elapsed = 00:00:34 . Memory (MB): peak = 3480.266 ; gain = 0.000 ; free physical = 18131 ; free virtual = 642432default:defaulth px? 
?
Intermediate Timing Summary %s164*route2J
6| WNS=0.370  | TNS=0.000  | WHS=N/A    | THS=N/A    |
2default:defaultZ35-416h px? 
O
:Phase 2.5 Update Timing for Bus Skew | Checksum: d0318557
*commonh px? 
?

%s
*constraints2?
?Time (s): cpu = 00:01:22 ; elapsed = 00:00:35 . Memory (MB): peak = 3480.266 ; gain = 0.000 ; free physical = 18126 ; free virtual = 642382default:defaulth px? 
I
4Phase 2 Router Initialization | Checksum: 1a30549f0
*commonh px? 
?

%s
*constraints2?
?Time (s): cpu = 00:01:22 ; elapsed = 00:00:35 . Memory (MB): peak = 3480.266 ; gain = 0.000 ; free physical = 18126 ; free virtual = 642382default:defaulth px? 
p

Phase %s%s
101*constraints2
3 2default:default2#
Initial Routing2default:defaultZ18-101h px? 
C
.Phase 3 Initial Routing | Checksum: 1ff4e3af1
*commonh px? 
?

%s
*constraints2?
?Time (s): cpu = 00:01:52 ; elapsed = 00:00:41 . Memory (MB): peak = 3480.266 ; gain = 0.000 ; free physical = 18113 ; free virtual = 642252default:defaulth px? 
s

Phase %s%s
101*constraints2
4 2default:default2&
Rip-up And Reroute2default:defaultZ18-101h px? 
u

Phase %s%s
101*constraints2
4.1 2default:default2&
Global Iteration 02default:defaultZ18-101h px? 
?
Intermediate Timing Summary %s164*route2J
6| WNS=0.054  | TNS=0.000  | WHS=N/A    | THS=N/A    |
2default:defaultZ35-416h px? 
H
3Phase 4.1 Global Iteration 0 | Checksum: 1c953734f
*commonh px? 
?

%s
*constraints2?
?Time (s): cpu = 00:16:48 ; elapsed = 00:03:37 . Memory (MB): peak = 3480.266 ; gain = 0.000 ; free physical = 18113 ; free virtual = 642262default:defaulth px? 
F
1Phase 4 Rip-up And Reroute | Checksum: 1c953734f
*commonh px? 
?

%s
*constraints2?
?Time (s): cpu = 00:16:48 ; elapsed = 00:03:37 . Memory (MB): peak = 3480.266 ; gain = 0.000 ; free physical = 18113 ; free virtual = 642262default:defaulth px? 
|

Phase %s%s
101*constraints2
5 2default:default2/
Delay and Skew Optimization2default:defaultZ18-101h px? 
p

Phase %s%s
101*constraints2
5.1 2default:default2!
Delay CleanUp2default:defaultZ18-101h px? 
C
.Phase 5.1 Delay CleanUp | Checksum: 1c953734f
*commonh px? 
?

%s
*constraints2?
?Time (s): cpu = 00:16:49 ; elapsed = 00:03:37 . Memory (MB): peak = 3480.266 ; gain = 0.000 ; free physical = 18113 ; free virtual = 642262default:defaulth px? 
z

Phase %s%s
101*constraints2
5.2 2default:default2+
Clock Skew Optimization2default:defaultZ18-101h px? 
M
8Phase 5.2 Clock Skew Optimization | Checksum: 1c953734f
*commonh px? 
?

%s
*constraints2?
?Time (s): cpu = 00:16:49 ; elapsed = 00:03:38 . Memory (MB): peak = 3480.266 ; gain = 0.000 ; free physical = 18113 ; free virtual = 642262default:defaulth px? 
O
:Phase 5 Delay and Skew Optimization | Checksum: 1c953734f
*commonh px? 
?

%s
*constraints2?
?Time (s): cpu = 00:16:49 ; elapsed = 00:03:38 . Memory (MB): peak = 3480.266 ; gain = 0.000 ; free physical = 18114 ; free virtual = 642262default:defaulth px? 
n

Phase %s%s
101*constraints2
6 2default:default2!
Post Hold Fix2default:defaultZ18-101h px? 
p

Phase %s%s
101*constraints2
6.1 2default:default2!
Hold Fix Iter2default:defaultZ18-101h px? 
r

Phase %s%s
101*constraints2
6.1.1 2default:default2!
Update Timing2default:defaultZ18-101h px? 
E
0Phase 6.1.1 Update Timing | Checksum: 18cc4dc22
*commonh px? 
?

%s
*constraints2?
?Time (s): cpu = 00:16:56 ; elapsed = 00:03:40 . Memory (MB): peak = 3480.266 ; gain = 0.000 ; free physical = 18117 ; free virtual = 642302default:defaulth px? 
?
Intermediate Timing Summary %s164*route2J
6| WNS=0.067  | TNS=0.000  | WHS=-0.055 | THS=-0.141 |
2default:defaultZ35-416h px? 
C
.Phase 6.1 Hold Fix Iter | Checksum: 1aa069033
*commonh px? 
?

%s
*constraints2?
?Time (s): cpu = 00:16:56 ; elapsed = 00:03:40 . Memory (MB): peak = 3480.266 ; gain = 0.000 ; free physical = 18116 ; free virtual = 642282default:defaulth px? 
A
,Phase 6 Post Hold Fix | Checksum: 246b2866a
*commonh px? 
?

%s
*constraints2?
?Time (s): cpu = 00:16:57 ; elapsed = 00:03:40 . Memory (MB): peak = 3480.266 ; gain = 0.000 ; free physical = 18116 ; free virtual = 642282default:defaulth px? 
o

Phase %s%s
101*constraints2
7 2default:default2"
Route finalize2default:defaultZ18-101h px? 
B
-Phase 7 Route finalize | Checksum: 1af286762
*commonh px? 
?

%s
*constraints2?
?Time (s): cpu = 00:16:58 ; elapsed = 00:03:41 . Memory (MB): peak = 3480.266 ; gain = 0.000 ; free physical = 18115 ; free virtual = 642282default:defaulth px? 
v

Phase %s%s
101*constraints2
8 2default:default2)
Verifying routed nets2default:defaultZ18-101h px? 
I
4Phase 8 Verifying routed nets | Checksum: 1af286762
*commonh px? 
?

%s
*constraints2?
?Time (s): cpu = 00:16:58 ; elapsed = 00:03:41 . Memory (MB): peak = 3480.266 ; gain = 0.000 ; free physical = 18113 ; free virtual = 642262default:defaulth px? 
r

Phase %s%s
101*constraints2
9 2default:default2%
Depositing Routes2default:defaultZ18-101h px? 
E
0Phase 9 Depositing Routes | Checksum: 1c9cdd111
*commonh px? 
?

%s
*constraints2?
?Time (s): cpu = 00:17:01 ; elapsed = 00:03:44 . Memory (MB): peak = 3480.266 ; gain = 0.000 ; free physical = 18107 ; free virtual = 642202default:defaulth px? 
t

Phase %s%s
101*constraints2
10 2default:default2&
Post Router Timing2default:defaultZ18-101h px? 
q

Phase %s%s
101*constraints2
10.1 2default:default2!
Update Timing2default:defaultZ18-101h px? 
D
/Phase 10.1 Update Timing | Checksum: 1da9c1a6f
*commonh px? 
?

%s
*constraints2?
?Time (s): cpu = 00:17:07 ; elapsed = 00:03:46 . Memory (MB): peak = 3480.266 ; gain = 0.000 ; free physical = 18113 ; free virtual = 642252default:defaulth px? 
?
Estimated Timing Summary %s
57*route2J
6| WNS=0.067  | TNS=0.000  | WHS=0.053  | THS=0.000  |
2default:defaultZ35-57h px? 
?
?The final timing numbers are based on the router estimated timing analysis. For a complete and accurate timing signoff, please run report_timing_summary.
127*routeZ35-327h px? 
G
2Phase 10 Post Router Timing | Checksum: 1da9c1a6f
*commonh px? 
?

%s
*constraints2?
?Time (s): cpu = 00:17:07 ; elapsed = 00:03:46 . Memory (MB): peak = 3480.266 ; gain = 0.000 ; free physical = 18113 ; free virtual = 642252default:defaulth px? 
@
Router Completed Successfully
2*	routeflowZ35-16h px? 
?

%s
*constraints2?
?Time (s): cpu = 00:17:08 ; elapsed = 00:03:47 . Memory (MB): peak = 3480.266 ; gain = 0.000 ; free physical = 18191 ; free virtual = 643042default:defaulth px? 
Z
Releasing license: %s
83*common2"
Implementation2default:defaultZ17-83h px? 
?
G%s Infos, %s Warnings, %s Critical Warnings and %s Errors encountered.
28*	vivadotcl2
1982default:default2
1842default:default2
212default:default2
02default:defaultZ4-41h px? 
^
%s completed successfully
29*	vivadotcl2 
route_design2default:defaultZ4-42h px? 
?
r%sTime (s): cpu = %s ; elapsed = %s . Memory (MB): peak = %s ; gain = %s ; free physical = %s ; free virtual = %s
480*common2"
route_design: 2default:default2
00:17:162default:default2
00:03:522default:default2
3480.2662default:default2
0.0002default:default2
181862default:default2
642992default:defaultZ17-722h px? 
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
00:00:092default:default2
00:00:042default:default2
3480.2662default:default2
0.0002default:default2
180012default:default2
642612default:defaultZ17-722h px? 
?
 The %s '%s' has been generated.
621*common2

checkpoint2default:default2}
i/home/utente/projects/CitirocRedoutFullV/CitirocRedoutFullV.runs/impl_1/TOP_CitirocRedoutFullV_routed.dcp2default:defaultZ17-1381h px? 
?
r%sTime (s): cpu = %s ; elapsed = %s . Memory (MB): peak = %s ; gain = %s ; free physical = %s ; free virtual = %s
480*common2&
write_checkpoint: 2default:default2
00:00:192default:default2
00:00:132default:default2
3480.2662default:default2
0.0002default:default2
181432default:default2
642892default:defaultZ17-722h px? 
?
%s4*runtcl2?
?Executing : report_drc -file TOP_CitirocRedoutFullV_drc_routed.rpt -pb TOP_CitirocRedoutFullV_drc_routed.pb -rpx TOP_CitirocRedoutFullV_drc_routed.rpx
2default:defaulth px? 
?
Command: %s
53*	vivadotcl2?
?report_drc -file TOP_CitirocRedoutFullV_drc_routed.rpt -pb TOP_CitirocRedoutFullV_drc_routed.pb -rpx TOP_CitirocRedoutFullV_drc_routed.rpx2default:defaultZ4-113h px? 
>
IP Catalog is up to date.1232*coregenZ19-1839h px? 
P
Running DRC with %s threads
24*drc2
82default:defaultZ23-27h px? 
?
#The results of DRC are in file %s.
168*coretcl2?
m/home/utente/projects/CitirocRedoutFullV/CitirocRedoutFullV.runs/impl_1/TOP_CitirocRedoutFullV_drc_routed.rptm/home/utente/projects/CitirocRedoutFullV/CitirocRedoutFullV.runs/impl_1/TOP_CitirocRedoutFullV_drc_routed.rpt2default:default8Z2-168h px? 
\
%s completed successfully
29*	vivadotcl2

report_drc2default:defaultZ4-42h px? 
?
r%sTime (s): cpu = %s ; elapsed = %s . Memory (MB): peak = %s ; gain = %s ; free physical = %s ; free virtual = %s
480*common2 
report_drc: 2default:default2
00:00:202default:default2
00:00:062default:default2
3492.2462default:default2
11.9802default:default2
180842default:default2
642292default:defaultZ17-722h px? 
?
%s4*runtcl2?
?Executing : report_methodology -file TOP_CitirocRedoutFullV_methodology_drc_routed.rpt -pb TOP_CitirocRedoutFullV_methodology_drc_routed.pb -rpx TOP_CitirocRedoutFullV_methodology_drc_routed.rpx
2default:defaulth px? 
?
Command: %s
53*	vivadotcl2?
?report_methodology -file TOP_CitirocRedoutFullV_methodology_drc_routed.rpt -pb TOP_CitirocRedoutFullV_methodology_drc_routed.pb -rpx TOP_CitirocRedoutFullV_methodology_drc_routed.rpx2default:defaultZ4-113h px? 
E
%Done setting XDC timing constraints.
35*timingZ38-35h px? 
E
%Done setting XDC timing constraints.
35*timingZ38-35h px? 
Y
$Running Methodology with %s threads
74*drc2
82default:defaultZ23-133h px? 
?
2The results of Report Methodology are in file %s.
450*coretcl2?
y/home/utente/projects/CitirocRedoutFullV/CitirocRedoutFullV.runs/impl_1/TOP_CitirocRedoutFullV_methodology_drc_routed.rpty/home/utente/projects/CitirocRedoutFullV/CitirocRedoutFullV.runs/impl_1/TOP_CitirocRedoutFullV_methodology_drc_routed.rpt2default:default8Z2-1520h px? 
d
%s completed successfully
29*	vivadotcl2&
report_methodology2default:defaultZ4-42h px? 
?
r%sTime (s): cpu = %s ; elapsed = %s . Memory (MB): peak = %s ; gain = %s ; free physical = %s ; free virtual = %s
480*common2(
report_methodology: 2default:default2
00:00:482default:default2
00:00:152default:default2
3640.8982default:default2
148.6522default:default2
175922default:default2
637372default:defaultZ17-722h px? 
?
%s4*runtcl2?
?Executing : report_power -file TOP_CitirocRedoutFullV_power_routed.rpt -pb TOP_CitirocRedoutFullV_power_summary_routed.pb -rpx TOP_CitirocRedoutFullV_power_routed.rpx
2default:defaulth px? 
?
Command: %s
53*	vivadotcl2?
?report_power -file TOP_CitirocRedoutFullV_power_routed.rpt -pb TOP_CitirocRedoutFullV_power_summary_routed.pb -rpx TOP_CitirocRedoutFullV_power_routed.rpx2default:defaultZ4-113h px? 
{
$Power model is not available for %s
23*power24
STARTUPE2_inst	STARTUPE2_inst2default:default8Z33-23h px? 
?
$Power model is not available for %s
23*power2_
DNA_PORT_inst	:USBInterface/Inst_ft600_fifo245_core/SEC_SYS/DNA_PORT_inst2default:default8Z33-23h px? 
E
%Done setting XDC timing constraints.
35*timingZ38-35h px? 
K
,Running Vector-less Activity Propagation...
51*powerZ33-51h px? 
P
3
Finished Running Vector-less Activity Propagation
1*powerZ33-1h px? 
?
?Detected over-assertion of set/reset/preset/clear net with high fanouts, power estimation might not be accurate. Please run Tool - Power Constraint Wizard to set proper switching activities for control signals.282*powerZ33-332h px? 
?
G%s Infos, %s Warnings, %s Critical Warnings and %s Errors encountered.
28*	vivadotcl2
2122default:default2
1852default:default2
212default:default2
02default:defaultZ4-41h px? 
^
%s completed successfully
29*	vivadotcl2 
report_power2default:defaultZ4-42h px? 
?
r%sTime (s): cpu = %s ; elapsed = %s . Memory (MB): peak = %s ; gain = %s ; free physical = %s ; free virtual = %s
480*common2"
report_power: 2default:default2
00:00:302default:default2
00:00:112default:default2
3808.8482default:default2
167.9492default:default2
174942default:default2
636502default:defaultZ17-722h px? 
?
%s4*runtcl2?
yExecuting : report_route_status -file TOP_CitirocRedoutFullV_route_status.rpt -pb TOP_CitirocRedoutFullV_route_status.pb
2default:defaulth px? 
?
%s4*runtcl2?
?Executing : report_timing_summary -max_paths 10 -file TOP_CitirocRedoutFullV_timing_summary_routed.rpt -rpx TOP_CitirocRedoutFullV_timing_summary_routed.rpx -warn_on_violation 
2default:defaulth px? 
r
UpdateTimingParams:%s.
91*timing29
% Speed grade: -2, Delay Type: min_max2default:defaultZ38-91h px? 
|
CMultithreading enabled for timing update using a maximum of %s CPUs155*timing2
82default:defaultZ38-191h px? 
?
}There are set_bus_skew constraint(s) in this design. Please run report_bus_skew to ensure that bus skew requirements are met.223*timingZ38-436h px? 
?
%s4*runtcl2s
_Executing : report_incremental_reuse -file TOP_CitirocRedoutFullV_incremental_reuse_routed.rpt
2default:defaulth px? 
x
TNo incremental reuse to report, no incremental placement and routing data was found.278*	vivadotclZ4-545h px? 
?
%s4*runtcl2s
_Executing : report_clock_utilization -file TOP_CitirocRedoutFullV_clock_utilization_routed.rpt
2default:defaulth px? 
?
r%sTime (s): cpu = %s ; elapsed = %s . Memory (MB): peak = %s ; gain = %s ; free physical = %s ; free virtual = %s
480*common2.
report_clock_utilization: 2default:default2
00:00:072default:default2
00:00:072default:default2
3853.8202default:default2
0.0002default:default2
174382default:default2
635962default:defaultZ17-722h px? 


End Record