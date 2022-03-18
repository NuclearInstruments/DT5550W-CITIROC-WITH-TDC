from CitirocRedoutFullV_Functions import *
from ctypes import *
import matplotlib.pyplot as plt
import time

[ListOfDevices, count] = ListDevices()
if (count > 0):

	board = ListOfDevices[0].encode('utf-8')

	Init()
	[err, handle] = ConnectDevice(board)
	if (err == 0):
		print("Successful connection to board ", board)
	else:
		print("Connection Error")


	Citiroc_CitirocCfg0_CONFIG("1110111011101110111011101110111011101110111011101110111011101110111011101110111011101110111011101110111011101110111011101110111011101110111011101110111011101110111011101110111011101110111011101110111011101110111011101110111011101110111011101110111011101110110111111111111111111111111111111111111111111011111100111111101111001111011100000001100000001100000001100000001100000001100000001100000001100000001100000001100000001100000001100000001100000001100000001100000001100000001100000001100000001100000001100000001100000001100000001100000001100000001100000001100000001100000001100000001100000001100000001100000001100000001000100000000000000100000000000000100000000000000100000000000000100000000000000100000000000000100000000000000100000000000000100000000000000100000000000000100000000000000100000000000000100000000000000100000000000000100000000000000100000000000000100000000000000100000000000000100000000000000100000000000000100000000000000100000000000000100000000000000100000000000000100000000000000100000000000000100000000000000100000000000000100000000000000100000000000000100000000000000100000000000111111110100101100010010110011111111111111011",handle)


	Citiroc_CitirocCfg0_CONFIG("1110111011101110111011101110111011101110111011101110111011101110111011101110111011101110111011101110111011101110111011101110111011101110111011101110111011101110111011101110111011101110111011101110111011101110111011101110111011101110111011101110111011101110110111111111111111111111111111111111111111111011111100111111101111001111011100000001100000001100000001100000001100000001100000001100000001100000001100000001100000001100000001100000001100000001100000001100000001100000001100000001100000001100000001100000001100000001100000001100000001100000001100000001100000001100000001100000001100000001100000001100000001100000001000100000000000000100000000000000100000000000000100000000000000100000000000000100000000000000100000000000000100000000000000100000000000000100000000000000100000000000000100000000000000100000000000000100000000000000100000000000000100000000000000100000000000000100000000000000100000000000000100000000000000100000000000000100000000000000100000000000000100000000000000100000000000000100000000000000100000000000000100000000000000100000000000000100000000000000100000000000000100000000000111111110100101100010010110011111111111111011",handle)


	Citiroc_CitirocCfg0_CONFIG("1110111011101110111011101110111011101110111011101110111011101110111011101110111011101110111011101110111011101110111011101110111011101110111011101110111011101110111011101110111011101110111011101110111011101110111011101110111011101110111011101110111011101110110111111111111111111111111111111111111111111011111100111111101111001111011100000001100000001100000001100000001100000001100000001100000001100000001100000001100000001100000001100000001100000001100000001100000001100000001100000001100000001100000001100000001100000001100000001100000001100000001100000001100000001100000001100000001100000001100000001100000001100000001000100000000000000100000000000000100000000000000100000000000000100000000000000100000000000000100000000000000100000000000000100000000000000100000000000000100000000000000100000000000000100000000000000100000000000000100000000000000100000000000000100000000000000100000000000000100000000000000100000000000000100000000000000100000000000000100000000000000100000000000000100000000000000100000000000000100000000000000100000000000000100000000000000100000000000000100000000000000100000000000111111110100101100010010110011111111111111011",handle)


	Citiroc_CitirocCfg0_CONFIG("1110111011101110111011101110111011101110111011101110111011101110111011101110111011101110111011101110111011101110111011101110111011101110111011101110111011101110111011101110111011101110111011101110111011101110111011101110111011101110111011101110111011101110110111111111111111111111111111111111111111111011111100111111101111001111011100000001100000001100000001100000001100000001100000001100000001100000001100000001100000001100000001100000001100000001100000001100000001100000001100000001100000001100000001100000001100000001100000001100000001100000001100000001100000001100000001100000001100000001100000001100000001100000001000100000000000000100000000000000100000000000000100000000000000100000000000000100000000000000100000000000000100000000000000100000000000000100000000000000100000000000000100000000000000100000000000000100000000000000100000000000000100000000000000100000000000000100000000000000100000000000000100000000000000100000000000000100000000000000100000000000000100000000000000100000000000000100000000000000100000000000000100000000000000100000000000000100000000000000100000000000000100000000000111111110100101100010010110011111111111111011",handle)


	plt.ion()
	plt.show()
	N_Packet = 100
	Timeout_ms = 1000
	N_Total_Events = 10000
	ReadDataNumber = 0
	if (CPACK_CP_0_RESET(handle) != 0):
		print("Reset Error!")
	if (CPACK_CP_0_START(handle) == True):
		[err, Frame_Status] = CPACK_CP_0_GET_STATUS(handle)
		if (Frame_Status >0):
			while(ReadDataNumber < N_Total_Events):
				[err, Frame_Data, Frame_Read_Data, Frame_Valid_Data] = CPACK_CP_0_GET_DATA(N_Packet, Timeout_ms, handle)
				[Time_Code, Pack_Id, Energy] = CPACK_CP_0_RECONSTRUCT_DATA(Frame_Data)                 
				ReadDataNumber += N_Packet
				print("Event Id: ", Pack_Id[0])
				plt.cla()
				plt.plot(Energy[0])
				plt.pause(0.01)
				print("Total Acquired Events: ", ReadDataNumber)
		else:
			print("Status Error")
	else:
		print("Start Error")


	## ---------------------------------------------------- ##
    ## CODE EXAMPLE FOR THE Citiroc FRAME TRANSFER          ##
    plt.ion()
	while True:
		[err, data, read_data, valid_data] = CitirocFRAME_CitirocFrame0_GET_DATA(16, 1000, handle)
		if (valid_data>0):
			[ AsicId, Time_Code, RunTime_Code, Pack_Id, ChargeHg, ChargeLg, Hit] = CitirocFRAME_CitirocFrame0_RECONSTRUCT_DATA(data, valid_data)
			print(Pack_Id, Time_Code)

			plt.cla()
			plt.plot(Charge[0])
			plt.pause(0.01)
    ## ---------------------------------------------------- ##

	plt.ion()
    Oscilloscope_Status = 0
    Timeout_ms = 1000
    Decimator = 0
    Pre_Trigger = 100
    Trigger_Level = 1000
    Trigger_Channel = 0
	Trigger_Mode = "Free" #"Free", "Analog", "Digital0", "Digital1", "Digital2", "Digital3"
	Trigger_Edge = "Rising" #"Rising", "Falling"
	
    while(1):
        if (OSCILLOSCOPE_Oscilloscope_0_SET_DECIMATOR(Decimator, handle) != 0): 
            print("Set Decimator Error")
            exit
        if (OSCILLOSCOPE_Oscilloscope_0_SET_PRETRIGGER(Pre_Trigger, handle) != 0): 
            print("Set PreTrigger Error")
            exit
        if (OSCILLOSCOPE_Oscilloscope_0_SET_TRIGGER_LEVEL(Trigger_Level, handle) != 0):
            print("Set Trigger Level Error")
            exit
        if (OSCILLOSCOPE_Oscilloscope_0_SET_TRIGGER_MODE(Trigger_Mode, Trigger_Channel, Trigger_Edge, handle) != 0):
            print("Set Trigger Mode Error")
            exit
        if (OSCILLOSCOPE_Oscilloscope_0_START(handle) == True):
            while (Oscilloscope_Status != 1):
                [err, Oscilloscope_Status] = OSCILLOSCOPE_Oscilloscope_0_GET_STATUS(handle)
            [err, Event_Position] = OSCILLOSCOPE_Oscilloscope_0_GET_POSITION(handle)
            [err, Oscilloscope_Data, Oscilloscope_Read_Data, Oscilloscope_Valid_Data] = OSCILLOSCOPE_Oscilloscope_0_GET_DATA(Timeout_ms, handle)
            [Analog, Digital0, Digital1, Digital2, Digital3] = OSCILLOSCOPE_Oscilloscope_0_RECONSTRUCT_DATA(Oscilloscope_Data, Event_Position, Pre_Trigger)
			plt.cla()
			plt.plot(Analog)
			plt.pause(0.01)
		else:
			print("Start Error")

	plt.ion()
    Oscilloscope_Status = 0
    Timeout_ms = 1000
    Decimator = 0
    Pre_Trigger = 100
    Trigger_Level = 1000
    Trigger_Channel = 0
	Trigger_Mode = "Free" #"Free", "Analog", "Digital0", "Digital1", "Digital2", "Digital3"
	Trigger_Edge = "Rising" #"Rising", "Falling"
	
    while(1):
        if (OSCILLOSCOPE_Oscilloscope_1_SET_DECIMATOR(Decimator, handle) != 0): 
            print("Set Decimator Error")
            exit
        if (OSCILLOSCOPE_Oscilloscope_1_SET_PRETRIGGER(Pre_Trigger, handle) != 0): 
            print("Set PreTrigger Error")
            exit
        if (OSCILLOSCOPE_Oscilloscope_1_SET_TRIGGER_LEVEL(Trigger_Level, handle) != 0):
            print("Set Trigger Level Error")
            exit
        if (OSCILLOSCOPE_Oscilloscope_1_SET_TRIGGER_MODE(Trigger_Mode, Trigger_Channel, Trigger_Edge, handle) != 0):
            print("Set Trigger Mode Error")
            exit
        if (OSCILLOSCOPE_Oscilloscope_1_START(handle) == True):
            while (Oscilloscope_Status != 1):
                [err, Oscilloscope_Status] = OSCILLOSCOPE_Oscilloscope_1_GET_STATUS(handle)
            [err, Event_Position] = OSCILLOSCOPE_Oscilloscope_1_GET_POSITION(handle)
            [err, Oscilloscope_Data, Oscilloscope_Read_Data, Oscilloscope_Valid_Data] = OSCILLOSCOPE_Oscilloscope_1_GET_DATA(Timeout_ms, handle)
            [Analog, Digital0, Digital1, Digital2, Digital3] = OSCILLOSCOPE_Oscilloscope_1_RECONSTRUCT_DATA(Oscilloscope_Data, Event_Position, Pre_Trigger)
			plt.cla()
			plt.plot(Analog)
			plt.pause(0.01)
		else:
			print("Start Error")

	plt.ion()
    Oscilloscope_Status = 0
    Timeout_ms = 1000
    Decimator = 0
    Pre_Trigger = 100
    Trigger_Level = 1000
    Trigger_Channel = 0
	Trigger_Mode = "Free" #"Free", "Analog", "Digital0", "Digital1", "Digital2", "Digital3"
	Trigger_Edge = "Rising" #"Rising", "Falling"
	
    while(1):
        if (OSCILLOSCOPE_Oscilloscope_2_SET_DECIMATOR(Decimator, handle) != 0): 
            print("Set Decimator Error")
            exit
        if (OSCILLOSCOPE_Oscilloscope_2_SET_PRETRIGGER(Pre_Trigger, handle) != 0): 
            print("Set PreTrigger Error")
            exit
        if (OSCILLOSCOPE_Oscilloscope_2_SET_TRIGGER_LEVEL(Trigger_Level, handle) != 0):
            print("Set Trigger Level Error")
            exit
        if (OSCILLOSCOPE_Oscilloscope_2_SET_TRIGGER_MODE(Trigger_Mode, Trigger_Channel, Trigger_Edge, handle) != 0):
            print("Set Trigger Mode Error")
            exit
        if (OSCILLOSCOPE_Oscilloscope_2_START(handle) == True):
            while (Oscilloscope_Status != 1):
                [err, Oscilloscope_Status] = OSCILLOSCOPE_Oscilloscope_2_GET_STATUS(handle)
            [err, Event_Position] = OSCILLOSCOPE_Oscilloscope_2_GET_POSITION(handle)
            [err, Oscilloscope_Data, Oscilloscope_Read_Data, Oscilloscope_Valid_Data] = OSCILLOSCOPE_Oscilloscope_2_GET_DATA(Timeout_ms, handle)
            [Analog, Digital0, Digital1, Digital2, Digital3] = OSCILLOSCOPE_Oscilloscope_2_RECONSTRUCT_DATA(Oscilloscope_Data, Event_Position, Pre_Trigger)
			plt.cla()
			plt.plot(Analog)
			plt.pause(0.01)
		else:
			print("Start Error")

	plt.ion()
    Oscilloscope_Status = 0
    Timeout_ms = 1000
    Decimator = 0
    Pre_Trigger = 100
    Trigger_Level = 1000
    Trigger_Channel = 0
	Trigger_Mode = "Free" #"Free", "Analog", "Digital0", "Digital1", "Digital2", "Digital3"
	Trigger_Edge = "Rising" #"Rising", "Falling"
	
    while(1):
        if (OSCILLOSCOPE_Oscilloscope_3_SET_DECIMATOR(Decimator, handle) != 0): 
            print("Set Decimator Error")
            exit
        if (OSCILLOSCOPE_Oscilloscope_3_SET_PRETRIGGER(Pre_Trigger, handle) != 0): 
            print("Set PreTrigger Error")
            exit
        if (OSCILLOSCOPE_Oscilloscope_3_SET_TRIGGER_LEVEL(Trigger_Level, handle) != 0):
            print("Set Trigger Level Error")
            exit
        if (OSCILLOSCOPE_Oscilloscope_3_SET_TRIGGER_MODE(Trigger_Mode, Trigger_Channel, Trigger_Edge, handle) != 0):
            print("Set Trigger Mode Error")
            exit
        if (OSCILLOSCOPE_Oscilloscope_3_START(handle) == True):
            while (Oscilloscope_Status != 1):
                [err, Oscilloscope_Status] = OSCILLOSCOPE_Oscilloscope_3_GET_STATUS(handle)
            [err, Event_Position] = OSCILLOSCOPE_Oscilloscope_3_GET_POSITION(handle)
            [err, Oscilloscope_Data, Oscilloscope_Read_Data, Oscilloscope_Valid_Data] = OSCILLOSCOPE_Oscilloscope_3_GET_DATA(Timeout_ms, handle)
            [Analog, Digital0, Digital1, Digital2, Digital3] = OSCILLOSCOPE_Oscilloscope_3_RECONSTRUCT_DATA(Oscilloscope_Data, Event_Position, Pre_Trigger)
			plt.cla()
			plt.plot(Analog)
			plt.pause(0.01)
		else:
			print("Start Error")

