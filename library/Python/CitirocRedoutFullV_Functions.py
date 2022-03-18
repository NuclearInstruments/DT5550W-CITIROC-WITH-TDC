
































import CitirocRedoutFullV_RegisterFile
from ctypes import *
import array
import numpy as np

import os

mydll = cdll.LoadLibrary(os.path.dirname(__file__) +'/niusb3_core.dll')

def Init():
    err = mydll.NI_USB3_Init()
    return err

def ConnectDevice(board):
    handle = c_void_p(256)
    err = mydll.NI_USB3_ConnectDevice(board, byref(handle))
    return err, handle

def CloseConnect(handle):
    err = mydll.NI_USB3_CloseConnection(byref(handle))
    return err	
	
def ListDevices():
    count = c_int(0)
    s = create_string_buffer(2048)
    err = mydll.NI_USB3_ListDevices(byref(s), 0, byref(count))
    str_con = (s.value.decode('ascii')) 
    str_devices = str_con.split(';')
    dev_count = count.value
    return str_devices, dev_count 

def __abstracted_reg_write(data, address, handle):
    err = mydll.NI_USB3_WriteReg(data, address, byref(handle))
    return err

def __abstracted_reg_read(address, handle):
    data = c_uint(0)
    err = mydll.NI_USB3_ReadReg(byref(data), address, byref(handle))
    return err, data.value

def __abstracted_mem_write(data, count, address, timeout_ms, handle):
    written_data = c_uint(0)
    err = mydll.NI_USB3_WriteData(data, count, address, 0, timeout_ms, byref(handle), byref(written_data))
    return err, written_data.value

def __abstracted_mem_read(count, address, timeout_ms, handle):
    data = (c_uint * (2* count))()
    read_data = c_uint(0)
    valid_data = c_uint(0)
    err = mydll.NI_USB3_ReadData(byref(data), count, address, 0, timeout_ms, byref(handle), byref(read_data), byref(valid_data))
    return err, data, read_data.value, valid_data.value

def __abstracted_fifo_write(data, count, address, timeout_ms, handle):
    written_data = c_uint(0)
    err = mydll.NI_USB3_WriteData(data, count, address, 1, timeout_ms, byref(handle), byref(written_data))
    return err, written_data.value

def __abstracted_fifo_read(count, address, address_status, blocking, timeout_ms, handle):
    data = (c_uint * (2 * count))()
    read_data = c_uint(0)
    valid_data = c_uint(0)
    err = mydll.NI_USB3_ReadData(byref(data), count, address, 1, timeout_ms, byref(handle), byref(read_data), byref(valid_data))
    return err, data, read_data, valid_data 	
	
#def SetAFEBaseAddress(handle):
#    err = mydll.NI_USB3_SetIICControllerBaseAddress(CitirocRedoutFullV_RegisterFile.SCI_AFE_REG_CTRL, CitirocRedoutFullV_RegisterFile.SCI_AFE_REG_MON, byref(handle))
#    return err

def SetAFEOffset(top, value, handle):
    err = mydll.NI_USB3_SetOffset(top, value, byref(handle))   
    return err

def SetAFEImpedance(value, handle):
    err = mydll.NI_USB3_SetImpedance(value, byref(handle))
    return err
	
def SetIICControllerBaseAddress(reg_cntrl, reg_mon, handle):
    err = mydll.NI_USB3_SetIICControllerBaseAddress(reg_cntrl, reg_mon, byref(handle))
    return err

def SetHV_A7585D(enable, voltge, handle):
    err = mydll.NI_USB3_SetHV(enable, c_float(voltge), byref(handle))
    return err

def GetHV_A7585D(handle):    
    enable = c_int(0)
    voltage = c_float(0)
    current = c_float(0)
    err = mydll.NI_USB3_GetHV(byref(enable), byref(voltage), byref(current), byref(handle))
    return err, enable.value, voltage.value, current.value
	
def gray_to_bin(num, nbit):
	temp = num ^ (num >> 8)
	temp ^= (temp >> 4)
	temp ^= (temp >> 2)
	temp ^= (temp >> 1)
	return temp	

def REG_TRIG_A_SEL_GET(handle):
    [err, data] = __abstracted_reg_read(CitirocRedoutFullV_RegisterFile.SCI_REG_TRIG_A_SEL, handle)
    return err, data

def REG_TRIG_A_SEL_SET(data, handle):
    err = __abstracted_reg_write(data, CitirocRedoutFullV_RegisterFile.SCI_REG_TRIG_A_SEL, handle)
    return err

def REG_VET_A_EN_GET(handle):
    [err, data] = __abstracted_reg_read(CitirocRedoutFullV_RegisterFile.SCI_REG_VET_A_EN, handle)
    return err, data

def REG_VET_A_EN_SET(data, handle):
    err = __abstracted_reg_write(data, CitirocRedoutFullV_RegisterFile.SCI_REG_VET_A_EN, handle)
    return err

def REG_VET_B_EN_GET(handle):
    [err, data] = __abstracted_reg_read(CitirocRedoutFullV_RegisterFile.SCI_REG_VET_B_EN, handle)
    return err, data

def REG_VET_B_EN_SET(data, handle):
    err = __abstracted_reg_write(data, CitirocRedoutFullV_RegisterFile.SCI_REG_VET_B_EN, handle)
    return err

def REG_VET_C_EN_GET(handle):
    [err, data] = __abstracted_reg_read(CitirocRedoutFullV_RegisterFile.SCI_REG_VET_C_EN, handle)
    return err, data

def REG_VET_C_EN_SET(data, handle):
    err = __abstracted_reg_write(data, CitirocRedoutFullV_RegisterFile.SCI_REG_VET_C_EN, handle)
    return err

def REG_VET_D_EN_GET(handle):
    [err, data] = __abstracted_reg_read(CitirocRedoutFullV_RegisterFile.SCI_REG_VET_D_EN, handle)
    return err, data

def REG_VET_D_EN_SET(data, handle):
    err = __abstracted_reg_write(data, CitirocRedoutFullV_RegisterFile.SCI_REG_VET_D_EN, handle)
    return err

def REG_SW_VET_A_GET(handle):
    [err, data] = __abstracted_reg_read(CitirocRedoutFullV_RegisterFile.SCI_REG_SW_VET_A, handle)
    return err, data

def REG_SW_VET_A_SET(data, handle):
    err = __abstracted_reg_write(data, CitirocRedoutFullV_RegisterFile.SCI_REG_SW_VET_A, handle)
    return err

def REG_SW_VET_B_GET(handle):
    [err, data] = __abstracted_reg_read(CitirocRedoutFullV_RegisterFile.SCI_REG_SW_VET_B, handle)
    return err, data

def REG_SW_VET_B_SET(data, handle):
    err = __abstracted_reg_write(data, CitirocRedoutFullV_RegisterFile.SCI_REG_SW_VET_B, handle)
    return err

def REG_SW_VET_C_GET(handle):
    [err, data] = __abstracted_reg_read(CitirocRedoutFullV_RegisterFile.SCI_REG_SW_VET_C, handle)
    return err, data

def REG_SW_VET_C_SET(data, handle):
    err = __abstracted_reg_write(data, CitirocRedoutFullV_RegisterFile.SCI_REG_SW_VET_C, handle)
    return err

def REG_SW_VET_D_GET(handle):
    [err, data] = __abstracted_reg_read(CitirocRedoutFullV_RegisterFile.SCI_REG_SW_VET_D, handle)
    return err, data

def REG_SW_VET_D_SET(data, handle):
    err = __abstracted_reg_write(data, CitirocRedoutFullV_RegisterFile.SCI_REG_SW_VET_D, handle)
    return err

def REG_TRIG_GBL_SEL_GET(handle):
    [err, data] = __abstracted_reg_read(CitirocRedoutFullV_RegisterFile.SCI_REG_TRIG_GBL_SEL, handle)
    return err, data

def REG_TRIG_GBL_SEL_SET(data, handle):
    err = __abstracted_reg_write(data, CitirocRedoutFullV_RegisterFile.SCI_REG_TRIG_GBL_SEL, handle)
    return err

def REG_EXT_DELAY_GET(handle):
    [err, data] = __abstracted_reg_read(CitirocRedoutFullV_RegisterFile.SCI_REG_EXT_DELAY, handle)
    return err, data

def REG_EXT_DELAY_SET(data, handle):
    err = __abstracted_reg_write(data, CitirocRedoutFullV_RegisterFile.SCI_REG_EXT_DELAY, handle)
    return err

def REG_SW_TRIG_FREQ_GET(handle):
    [err, data] = __abstracted_reg_read(CitirocRedoutFullV_RegisterFile.SCI_REG_SW_TRIG_FREQ, handle)
    return err, data

def REG_SW_TRIG_FREQ_SET(data, handle):
    err = __abstracted_reg_write(data, CitirocRedoutFullV_RegisterFile.SCI_REG_SW_TRIG_FREQ, handle)
    return err

def REG_A_RATE_GET(handle):
    [err, data] = __abstracted_reg_read(CitirocRedoutFullV_RegisterFile.SCI_REG_A_RATE, handle)
    return err, data

def REG_A_RATE_SET(data, handle):
    err = __abstracted_reg_write(data, CitirocRedoutFullV_RegisterFile.SCI_REG_A_RATE, handle)
    return err

def REG_B_RATE_GET(handle):
    [err, data] = __abstracted_reg_read(CitirocRedoutFullV_RegisterFile.SCI_REG_B_RATE, handle)
    return err, data

def REG_B_RATE_SET(data, handle):
    err = __abstracted_reg_write(data, CitirocRedoutFullV_RegisterFile.SCI_REG_B_RATE, handle)
    return err

def REG_C_RATE_GET(handle):
    [err, data] = __abstracted_reg_read(CitirocRedoutFullV_RegisterFile.SCI_REG_C_RATE, handle)
    return err, data

def REG_C_RATE_SET(data, handle):
    err = __abstracted_reg_write(data, CitirocRedoutFullV_RegisterFile.SCI_REG_C_RATE, handle)
    return err

def REG_D_RATE_GET(handle):
    [err, data] = __abstracted_reg_read(CitirocRedoutFullV_RegisterFile.SCI_REG_D_RATE, handle)
    return err, data

def REG_D_RATE_SET(data, handle):
    err = __abstracted_reg_write(data, CitirocRedoutFullV_RegisterFile.SCI_REG_D_RATE, handle)
    return err

def REG_T0_COUNT_GET(handle):
    [err, data] = __abstracted_reg_read(CitirocRedoutFullV_RegisterFile.SCI_REG_T0_COUNT, handle)
    return err, data

def REG_T0_COUNT_SET(data, handle):
    err = __abstracted_reg_write(data, CitirocRedoutFullV_RegisterFile.SCI_REG_T0_COUNT, handle)
    return err

def REG_A_TRG_GET(handle):
    [err, data] = __abstracted_reg_read(CitirocRedoutFullV_RegisterFile.SCI_REG_A_TRG, handle)
    return err, data

def REG_A_TRG_SET(data, handle):
    err = __abstracted_reg_write(data, CitirocRedoutFullV_RegisterFile.SCI_REG_A_TRG, handle)
    return err

def REG_B_TRG_GET(handle):
    [err, data] = __abstracted_reg_read(CitirocRedoutFullV_RegisterFile.SCI_REG_B_TRG, handle)
    return err, data

def REG_B_TRG_SET(data, handle):
    err = __abstracted_reg_write(data, CitirocRedoutFullV_RegisterFile.SCI_REG_B_TRG, handle)
    return err

def REG_C_TRG_GET(handle):
    [err, data] = __abstracted_reg_read(CitirocRedoutFullV_RegisterFile.SCI_REG_C_TRG, handle)
    return err, data

def REG_C_TRG_SET(data, handle):
    err = __abstracted_reg_write(data, CitirocRedoutFullV_RegisterFile.SCI_REG_C_TRG, handle)
    return err

def REG_D_TRG_GET(handle):
    [err, data] = __abstracted_reg_read(CitirocRedoutFullV_RegisterFile.SCI_REG_D_TRG, handle)
    return err, data

def REG_D_TRG_SET(data, handle):
    err = __abstracted_reg_write(data, CitirocRedoutFullV_RegisterFile.SCI_REG_D_TRG, handle)
    return err

def REG_RUNSTART_GET(handle):
    [err, data] = __abstracted_reg_read(CitirocRedoutFullV_RegisterFile.SCI_REG_RUNSTART, handle)
    return err, data

def REG_RUNSTART_SET(data, handle):
    err = __abstracted_reg_write(data, CitirocRedoutFullV_RegisterFile.SCI_REG_RUNSTART, handle)
    return err

def REG_RUN_TIME_LSB_GET(handle):
    [err, data] = __abstracted_reg_read(CitirocRedoutFullV_RegisterFile.SCI_REG_RUN_TIME_LSB, handle)
    return err, data

def REG_RUN_TIME_LSB_SET(data, handle):
    err = __abstracted_reg_write(data, CitirocRedoutFullV_RegisterFile.SCI_REG_RUN_TIME_LSB, handle)
    return err

def REG_RUN_TIME_MSB_GET(handle):
    [err, data] = __abstracted_reg_read(CitirocRedoutFullV_RegisterFile.SCI_REG_RUN_TIME_MSB, handle)
    return err, data

def REG_RUN_TIME_MSB_SET(data, handle):
    err = __abstracted_reg_write(data, CitirocRedoutFullV_RegisterFile.SCI_REG_RUN_TIME_MSB, handle)
    return err

def REG_DEAD_TIME_LSB_GET(handle):
    [err, data] = __abstracted_reg_read(CitirocRedoutFullV_RegisterFile.SCI_REG_DEAD_TIME_LSB, handle)
    return err, data

def REG_DEAD_TIME_LSB_SET(data, handle):
    err = __abstracted_reg_write(data, CitirocRedoutFullV_RegisterFile.SCI_REG_DEAD_TIME_LSB, handle)
    return err

def REG_DEAD_TIME_MSB_GET(handle):
    [err, data] = __abstracted_reg_read(CitirocRedoutFullV_RegisterFile.SCI_REG_DEAD_TIME_MSB, handle)
    return err, data

def REG_DEAD_TIME_MSB_SET(data, handle):
    err = __abstracted_reg_write(data, CitirocRedoutFullV_RegisterFile.SCI_REG_DEAD_TIME_MSB, handle)
    return err

def REG_A_LOST_GET(handle):
    [err, data] = __abstracted_reg_read(CitirocRedoutFullV_RegisterFile.SCI_REG_A_LOST, handle)
    return err, data

def REG_A_LOST_SET(data, handle):
    err = __abstracted_reg_write(data, CitirocRedoutFullV_RegisterFile.SCI_REG_A_LOST, handle)
    return err

def REG_B_LOST_GET(handle):
    [err, data] = __abstracted_reg_read(CitirocRedoutFullV_RegisterFile.SCI_REG_B_LOST, handle)
    return err, data

def REG_B_LOST_SET(data, handle):
    err = __abstracted_reg_write(data, CitirocRedoutFullV_RegisterFile.SCI_REG_B_LOST, handle)
    return err

def REG_C_LOST_GET(handle):
    [err, data] = __abstracted_reg_read(CitirocRedoutFullV_RegisterFile.SCI_REG_C_LOST, handle)
    return err, data

def REG_C_LOST_SET(data, handle):
    err = __abstracted_reg_write(data, CitirocRedoutFullV_RegisterFile.SCI_REG_C_LOST, handle)
    return err

def REG_D_LOST_GET(handle):
    [err, data] = __abstracted_reg_read(CitirocRedoutFullV_RegisterFile.SCI_REG_D_LOST, handle)
    return err, data

def REG_D_LOST_SET(data, handle):
    err = __abstracted_reg_write(data, CitirocRedoutFullV_RegisterFile.SCI_REG_D_LOST, handle)
    return err

def REG_T0_SOFT_FREQ_GET(handle):
    [err, data] = __abstracted_reg_read(CitirocRedoutFullV_RegisterFile.SCI_REG_T0_SOFT_FREQ, handle)
    return err, data

def REG_T0_SOFT_FREQ_SET(data, handle):
    err = __abstracted_reg_write(data, CitirocRedoutFullV_RegisterFile.SCI_REG_T0_SOFT_FREQ, handle)
    return err

def REG_T0_SEL_GET(handle):
    [err, data] = __abstracted_reg_read(CitirocRedoutFullV_RegisterFile.SCI_REG_T0_SEL, handle)
    return err, data

def REG_T0_SEL_SET(data, handle):
    err = __abstracted_reg_write(data, CitirocRedoutFullV_RegisterFile.SCI_REG_T0_SEL, handle)
    return err

def REG_HOLD_TIME_GET(handle):
    [err, data] = __abstracted_reg_read(CitirocRedoutFullV_RegisterFile.SCI_REG_HOLD_TIME, handle)
    return err, data

def REG_HOLD_TIME_SET(data, handle):
    err = __abstracted_reg_write(data, CitirocRedoutFullV_RegisterFile.SCI_REG_HOLD_TIME, handle)
    return err

def REG_FR_IFP_GET(handle):
    [err, data] = __abstracted_reg_read(CitirocRedoutFullV_RegisterFile.SCI_REG_FR_IFP, handle)
    return err, data

def REG_FR_IFP_SET(data, handle):
    err = __abstracted_reg_write(data, CitirocRedoutFullV_RegisterFile.SCI_REG_FR_IFP, handle)
    return err

def REG_FR_LIMIT_GET(handle):
    [err, data] = __abstracted_reg_read(CitirocRedoutFullV_RegisterFile.SCI_REG_FR_LIMIT, handle)
    return err, data

def REG_FR_LIMIT_SET(data, handle):
    err = __abstracted_reg_write(data, CitirocRedoutFullV_RegisterFile.SCI_REG_FR_LIMIT, handle)
    return err

def REG_FR_IFP2_GET(handle):
    [err, data] = __abstracted_reg_read(CitirocRedoutFullV_RegisterFile.SCI_REG_FR_IFP2, handle)
    return err, data

def REG_FR_IFP2_SET(data, handle):
    err = __abstracted_reg_write(data, CitirocRedoutFullV_RegisterFile.SCI_REG_FR_IFP2, handle)
    return err

def REG_FR_MODE_GET(handle):
    [err, data] = __abstracted_reg_read(CitirocRedoutFullV_RegisterFile.SCI_REG_FR_MODE, handle)
    return err, data

def REG_FR_MODE_SET(data, handle):
    err = __abstracted_reg_write(data, CitirocRedoutFullV_RegisterFile.SCI_REG_FR_MODE, handle)
    return err

def REG_FR_DBG1_GET(handle):
    [err, data] = __abstracted_reg_read(CitirocRedoutFullV_RegisterFile.SCI_REG_FR_DBG1, handle)
    return err, data

def REG_FR_DBG1_SET(data, handle):
    err = __abstracted_reg_write(data, CitirocRedoutFullV_RegisterFile.SCI_REG_FR_DBG1, handle)
    return err

def REG_FR_DBG2_GET(handle):
    [err, data] = __abstracted_reg_read(CitirocRedoutFullV_RegisterFile.SCI_REG_FR_DBG2, handle)
    return err, data

def REG_FR_DBG2_SET(data, handle):
    err = __abstracted_reg_write(data, CitirocRedoutFullV_RegisterFile.SCI_REG_FR_DBG2, handle)
    return err

def REG_VALIDATION_CFG_GET(handle):
    [err, data] = __abstracted_reg_read(CitirocRedoutFullV_RegisterFile.SCI_REG_VALIDATION_CFG, handle)
    return err, data

def REG_VALIDATION_CFG_SET(data, handle):
    err = __abstracted_reg_write(data, CitirocRedoutFullV_RegisterFile.SCI_REG_VALIDATION_CFG, handle)
    return err

def REG_HV_ON_GET(handle):
    [err, data] = __abstracted_reg_read(CitirocRedoutFullV_RegisterFile.SCI_REG_HV_ON, handle)
    return err, data

def REG_HV_ON_SET(data, handle):
    err = __abstracted_reg_write(data, CitirocRedoutFullV_RegisterFile.SCI_REG_HV_ON, handle)
    return err

def REG_HV_EMERGENCY_GET(handle):
    [err, data] = __abstracted_reg_read(CitirocRedoutFullV_RegisterFile.SCI_REG_HV_EMERGENCY, handle)
    return err, data

def REG_HV_EMERGENCY_SET(data, handle):
    err = __abstracted_reg_write(data, CitirocRedoutFullV_RegisterFile.SCI_REG_HV_EMERGENCY, handle)
    return err

def REG_HV_VOUT_GET(handle):
    [err, data] = __abstracted_reg_read(CitirocRedoutFullV_RegisterFile.SCI_REG_HV_VOUT, handle)
    return err, data

def REG_HV_VOUT_SET(data, handle):
    err = __abstracted_reg_write(data, CitirocRedoutFullV_RegisterFile.SCI_REG_HV_VOUT, handle)
    return err

def REG_HV_ENTCOMP_GET(handle):
    [err, data] = __abstracted_reg_read(CitirocRedoutFullV_RegisterFile.SCI_REG_HV_ENTCOMP, handle)
    return err, data

def REG_HV_ENTCOMP_SET(data, handle):
    err = __abstracted_reg_write(data, CitirocRedoutFullV_RegisterFile.SCI_REG_HV_ENTCOMP, handle)
    return err

def REG_HV_TM_GET(handle):
    [err, data] = __abstracted_reg_read(CitirocRedoutFullV_RegisterFile.SCI_REG_HV_TM, handle)
    return err, data

def REG_HV_TM_SET(data, handle):
    err = __abstracted_reg_write(data, CitirocRedoutFullV_RegisterFile.SCI_REG_HV_TM, handle)
    return err

def REG_HV_TQ_GET(handle):
    [err, data] = __abstracted_reg_read(CitirocRedoutFullV_RegisterFile.SCI_REG_HV_TQ, handle)
    return err, data

def REG_HV_TQ_SET(data, handle):
    err = __abstracted_reg_write(data, CitirocRedoutFullV_RegisterFile.SCI_REG_HV_TQ, handle)
    return err

def REG_HV_TCOEF_GET(handle):
    [err, data] = __abstracted_reg_read(CitirocRedoutFullV_RegisterFile.SCI_REG_HV_TCOEF, handle)
    return err, data

def REG_HV_TCOEF_SET(data, handle):
    err = __abstracted_reg_write(data, CitirocRedoutFullV_RegisterFile.SCI_REG_HV_TCOEF, handle)
    return err

def REG_HV_IMAX_GET(handle):
    [err, data] = __abstracted_reg_read(CitirocRedoutFullV_RegisterFile.SCI_REG_HV_IMAX, handle)
    return err, data

def REG_HV_IMAX_SET(data, handle):
    err = __abstracted_reg_write(data, CitirocRedoutFullV_RegisterFile.SCI_REG_HV_IMAX, handle)
    return err

def REG_HV_RAMP_GET(handle):
    [err, data] = __abstracted_reg_read(CitirocRedoutFullV_RegisterFile.SCI_REG_HV_RAMP, handle)
    return err, data

def REG_HV_RAMP_SET(data, handle):
    err = __abstracted_reg_write(data, CitirocRedoutFullV_RegisterFile.SCI_REG_HV_RAMP, handle)
    return err

def REG_HV_VMAX_GET(handle):
    [err, data] = __abstracted_reg_read(CitirocRedoutFullV_RegisterFile.SCI_REG_HV_VMAX, handle)
    return err, data

def REG_HV_VMAX_SET(data, handle):
    err = __abstracted_reg_write(data, CitirocRedoutFullV_RegisterFile.SCI_REG_HV_VMAX, handle)
    return err

def REG_HV_MSTATUS_GET(handle):
    [err, data] = __abstracted_reg_read(CitirocRedoutFullV_RegisterFile.SCI_REG_HV_MSTATUS, handle)
    return err, data

def REG_HV_MSTATUS_SET(data, handle):
    err = __abstracted_reg_write(data, CitirocRedoutFullV_RegisterFile.SCI_REG_HV_MSTATUS, handle)
    return err

def REG_HV_MVOUT_GET(handle):
    [err, data] = __abstracted_reg_read(CitirocRedoutFullV_RegisterFile.SCI_REG_HV_MVOUT, handle)
    return err, data

def REG_HV_MVOUT_SET(data, handle):
    err = __abstracted_reg_write(data, CitirocRedoutFullV_RegisterFile.SCI_REG_HV_MVOUT, handle)
    return err

def REG_HV_MTEMP_GET(handle):
    [err, data] = __abstracted_reg_read(CitirocRedoutFullV_RegisterFile.SCI_REG_HV_MTEMP, handle)
    return err, data

def REG_HV_MTEMP_SET(data, handle):
    err = __abstracted_reg_write(data, CitirocRedoutFullV_RegisterFile.SCI_REG_HV_MTEMP, handle)
    return err

def REG_HV_MVTARGET_GET(handle):
    [err, data] = __abstracted_reg_read(CitirocRedoutFullV_RegisterFile.SCI_REG_HV_MVTARGET, handle)
    return err, data

def REG_HV_MVTARGET_SET(data, handle):
    err = __abstracted_reg_write(data, CitirocRedoutFullV_RegisterFile.SCI_REG_HV_MVTARGET, handle)
    return err

def REG_HV_MAVTARGET_GET(handle):
    [err, data] = __abstracted_reg_read(CitirocRedoutFullV_RegisterFile.SCI_REG_HV_MAVTARGET, handle)
    return err, data

def REG_HV_MAVTARGET_SET(data, handle):
    err = __abstracted_reg_write(data, CitirocRedoutFullV_RegisterFile.SCI_REG_HV_MAVTARGET, handle)
    return err

def REG_T_SENS1_GET(handle):
    [err, data] = __abstracted_reg_read(CitirocRedoutFullV_RegisterFile.SCI_REG_T_SENS1, handle)
    return err, data

def REG_T_SENS1_SET(data, handle):
    err = __abstracted_reg_write(data, CitirocRedoutFullV_RegisterFile.SCI_REG_T_SENS1, handle)
    return err

def REG_T_SENS2_GET(handle):
    [err, data] = __abstracted_reg_read(CitirocRedoutFullV_RegisterFile.SCI_REG_T_SENS2, handle)
    return err, data

def REG_T_SENS2_SET(data, handle):
    err = __abstracted_reg_write(data, CitirocRedoutFullV_RegisterFile.SCI_REG_T_SENS2, handle)
    return err

def REG_HV_MIOUT_GET(handle):
    [err, data] = __abstracted_reg_read(CitirocRedoutFullV_RegisterFile.SCI_REG_HV_MIOUT, handle)
    return err, data

def REG_HV_MIOUT_SET(data, handle):
    err = __abstracted_reg_write(data, CitirocRedoutFullV_RegisterFile.SCI_REG_HV_MIOUT, handle)
    return err

def REG_TRIGGER_OUT_W_GET(handle):
    [err, data] = __abstracted_reg_read(CitirocRedoutFullV_RegisterFile.SCI_REG_TRIGGER_OUT_W, handle)
    return err, data

def REG_TRIGGER_OUT_W_SET(data, handle):
    err = __abstracted_reg_write(data, CitirocRedoutFullV_RegisterFile.SCI_REG_TRIGGER_OUT_W, handle)
    return err

def REG_T0SW_GET(handle):
    [err, data] = __abstracted_reg_read(CitirocRedoutFullV_RegisterFile.SCI_REG_T0SW, handle)
    return err, data

def REG_T0SW_SET(data, handle):
    err = __abstracted_reg_write(data, CitirocRedoutFullV_RegisterFile.SCI_REG_T0SW, handle)
    return err

def REG_GTS_RESSEL_GET(handle):
    [err, data] = __abstracted_reg_read(CitirocRedoutFullV_RegisterFile.SCI_REG_GTS_RESSEL, handle)
    return err, data

def REG_GTS_RESSEL_SET(data, handle):
    err = __abstracted_reg_write(data, CitirocRedoutFullV_RegisterFile.SCI_REG_GTS_RESSEL, handle)
    return err

def REG_TRIG_MASK_A_GET(handle):
    [err, data] = __abstracted_reg_read(CitirocRedoutFullV_RegisterFile.SCI_REG_TRIG_MASK_A, handle)
    return err, data

def REG_TRIG_MASK_A_SET(data, handle):
    err = __abstracted_reg_write(data, CitirocRedoutFullV_RegisterFile.SCI_REG_TRIG_MASK_A, handle)
    return err

def REG_TRIG_MASK_B_GET(handle):
    [err, data] = __abstracted_reg_read(CitirocRedoutFullV_RegisterFile.SCI_REG_TRIG_MASK_B, handle)
    return err, data

def REG_TRIG_MASK_B_SET(data, handle):
    err = __abstracted_reg_write(data, CitirocRedoutFullV_RegisterFile.SCI_REG_TRIG_MASK_B, handle)
    return err

def REG_TRIG_MASK_C_GET(handle):
    [err, data] = __abstracted_reg_read(CitirocRedoutFullV_RegisterFile.SCI_REG_TRIG_MASK_C, handle)
    return err, data

def REG_TRIG_MASK_C_SET(data, handle):
    err = __abstracted_reg_write(data, CitirocRedoutFullV_RegisterFile.SCI_REG_TRIG_MASK_C, handle)
    return err

def REG_TRIG_MASK_D_GET(handle):
    [err, data] = __abstracted_reg_read(CitirocRedoutFullV_RegisterFile.SCI_REG_TRIG_MASK_D, handle)
    return err, data

def REG_TRIG_MASK_D_SET(data, handle):
    err = __abstracted_reg_write(data, CitirocRedoutFullV_RegisterFile.SCI_REG_TRIG_MASK_D, handle)
    return err

def REG_T0_RESET_ON_START_GET(handle):
    [err, data] = __abstracted_reg_read(CitirocRedoutFullV_RegisterFile.SCI_REG_T0_RESET_ON_START, handle)
    return err, data

def REG_T0_RESET_ON_START_SET(data, handle):
    err = __abstracted_reg_write(data, CitirocRedoutFullV_RegisterFile.SCI_REG_T0_RESET_ON_START, handle)
    return err

def REG_ISRUNNING_GET(handle):
    [err, data] = __abstracted_reg_read(CitirocRedoutFullV_RegisterFile.SCI_REG_ISRUNNING, handle)
    return err, data

def REG_ISRUNNING_SET(data, handle):
    err = __abstracted_reg_write(data, CitirocRedoutFullV_RegisterFile.SCI_REG_ISRUNNING, handle)
    return err

def REG_VETO_WAIT_RUN_GET(handle):
    [err, data] = __abstracted_reg_read(CitirocRedoutFullV_RegisterFile.SCI_REG_VETO_WAIT_RUN, handle)
    return err, data

def REG_VETO_WAIT_RUN_SET(data, handle):
    err = __abstracted_reg_write(data, CitirocRedoutFullV_RegisterFile.SCI_REG_VETO_WAIT_RUN, handle)
    return err

def REG_GBL_EN_VETO_EXT_GET(handle):
    [err, data] = __abstracted_reg_read(CitirocRedoutFullV_RegisterFile.SCI_REG_GBL_EN_VETO_EXT, handle)
    return err, data

def REG_GBL_EN_VETO_EXT_SET(data, handle):
    err = __abstracted_reg_write(data, CitirocRedoutFullV_RegisterFile.SCI_REG_GBL_EN_VETO_EXT, handle)
    return err

def REG_INVETO_GET(handle):
    [err, data] = __abstracted_reg_read(CitirocRedoutFullV_RegisterFile.SCI_REG_INVETO, handle)
    return err, data

def REG_INVETO_SET(data, handle):
    err = __abstracted_reg_write(data, CitirocRedoutFullV_RegisterFile.SCI_REG_INVETO, handle)
    return err

def REG_TRG_OUT_MONOSTABLE_EN_GET(handle):
    [err, data] = __abstracted_reg_read(CitirocRedoutFullV_RegisterFile.SCI_REG_TRG_OUT_MONOSTABLE_EN, handle)
    return err, data

def REG_TRG_OUT_MONOSTABLE_EN_SET(data, handle):
    err = __abstracted_reg_write(data, CitirocRedoutFullV_RegisterFile.SCI_REG_TRG_OUT_MONOSTABLE_EN, handle)
    return err




def Citiroc_CitirocCfg0_CONFIG(incfg, handle):  
	bitstream = array.array('I',(0 for i in range(0,1152)))
	cfg = array.array('I',(0 for i in range(0,20)))
	bitstream_str = np.fromstring(incfg,'u1') - ord('0')
	for i in range (0,len(bitstream_str)):
		bitstream[i] = bitstream_str[i]
	for i in range (0,36):
		for j in range(0,32):
			cfg[i] += (bitstream[i*32+j] << j)
	__abstracted_reg_write(cfg[0], CitirocRedoutFullV_RegisterFile.SCI_REG_CitirocCfg0_REG_CFG0, handle)
	__abstracted_reg_write(cfg[1], CitirocRedoutFullV_RegisterFile.SCI_REG_CitirocCfg0_REG_CFG1, handle)
	__abstracted_reg_write(cfg[2], CitirocRedoutFullV_RegisterFile.SCI_REG_CitirocCfg0_REG_CFG2, handle)
	__abstracted_reg_write(cfg[3], CitirocRedoutFullV_RegisterFile.SCI_REG_CitirocCfg0_REG_CFG3, handle)
	__abstracted_reg_write(cfg[4], CitirocRedoutFullV_RegisterFile.SCI_REG_CitirocCfg0_REG_CFG4, handle)
	__abstracted_reg_write(cfg[5], CitirocRedoutFullV_RegisterFile.SCI_REG_CitirocCfg0_REG_CFG5, handle)
	__abstracted_reg_write(cfg[6], CitirocRedoutFullV_RegisterFile.SCI_REG_CitirocCfg0_REG_CFG6, handle)
	__abstracted_reg_write(cfg[7], CitirocRedoutFullV_RegisterFile.SCI_REG_CitirocCfg0_REG_CFG7, handle)
	__abstracted_reg_write(cfg[8], CitirocRedoutFullV_RegisterFile.SCI_REG_CitirocCfg0_REG_CFG8, handle)
	__abstracted_reg_write(cfg[9], CitirocRedoutFullV_RegisterFile.SCI_REG_CitirocCfg0_REG_CFG9, handle)
	__abstracted_reg_write(cfg[10], CitirocRedoutFullV_RegisterFile.SCI_REG_CitirocCfg0_REG_CFG10, handle)
	__abstracted_reg_write(cfg[11], CitirocRedoutFullV_RegisterFile.SCI_REG_CitirocCfg0_REG_CFG11, handle)
	__abstracted_reg_write(cfg[12], CitirocRedoutFullV_RegisterFile.SCI_REG_CitirocCfg0_REG_CFG12, handle)
	__abstracted_reg_write(cfg[13], CitirocRedoutFullV_RegisterFile.SCI_REG_CitirocCfg0_REG_CFG13, handle)
	__abstracted_reg_write(cfg[14], CitirocRedoutFullV_RegisterFile.SCI_REG_CitirocCfg0_REG_CFG14, handle)
	__abstracted_reg_write(cfg[15], CitirocRedoutFullV_RegisterFile.SCI_REG_CitirocCfg0_REG_CFG15, handle)
	__abstracted_reg_write(cfg[16], CitirocRedoutFullV_RegisterFile.SCI_REG_CitirocCfg0_REG_CFG16, handle)
	__abstracted_reg_write(cfg[17], CitirocRedoutFullV_RegisterFile.SCI_REG_CitirocCfg0_REG_CFG17, handle)
	__abstracted_reg_write(cfg[18], CitirocRedoutFullV_RegisterFile.SCI_REG_CitirocCfg0_REG_CFG18, handle)
	__abstracted_reg_write(cfg[19], CitirocRedoutFullV_RegisterFile.SCI_REG_CitirocCfg0_REG_CFG19, handle)
	__abstracted_reg_write(0, CitirocRedoutFullV_RegisterFile.SCI_REG_CitirocCfg0_START_REG_CFG, handle)
	__abstracted_reg_write(1, CitirocRedoutFullV_RegisterFile.SCI_REG_CitirocCfg0_START_REG_CFG, handle)
	__abstracted_reg_write(0, CitirocRedoutFullV_RegisterFile.SCI_REG_CitirocCfg0_START_REG_CFG, handle)




def Citiroc_CitirocCfg0_CONFIG(incfg, handle):  
	bitstream = array.array('I',(0 for i in range(0,1152)))
	cfg = array.array('I',(0 for i in range(0,20)))
	bitstream_str = np.fromstring(incfg,'u1') - ord('0')
	for i in range (0,len(bitstream_str)):
		bitstream[i] = bitstream_str[i]
	for i in range (0,36):
		for j in range(0,32):
			cfg[i] += (bitstream[i*32+j] << j)
	__abstracted_reg_write(cfg[0], CitirocRedoutFullV_RegisterFile.SCI_REG_CitirocCfg1_REG_CFG0, handle)
	__abstracted_reg_write(cfg[1], CitirocRedoutFullV_RegisterFile.SCI_REG_CitirocCfg1_REG_CFG1, handle)
	__abstracted_reg_write(cfg[2], CitirocRedoutFullV_RegisterFile.SCI_REG_CitirocCfg1_REG_CFG2, handle)
	__abstracted_reg_write(cfg[3], CitirocRedoutFullV_RegisterFile.SCI_REG_CitirocCfg1_REG_CFG3, handle)
	__abstracted_reg_write(cfg[4], CitirocRedoutFullV_RegisterFile.SCI_REG_CitirocCfg1_REG_CFG4, handle)
	__abstracted_reg_write(cfg[5], CitirocRedoutFullV_RegisterFile.SCI_REG_CitirocCfg1_REG_CFG5, handle)
	__abstracted_reg_write(cfg[6], CitirocRedoutFullV_RegisterFile.SCI_REG_CitirocCfg1_REG_CFG6, handle)
	__abstracted_reg_write(cfg[7], CitirocRedoutFullV_RegisterFile.SCI_REG_CitirocCfg1_REG_CFG7, handle)
	__abstracted_reg_write(cfg[8], CitirocRedoutFullV_RegisterFile.SCI_REG_CitirocCfg1_REG_CFG8, handle)
	__abstracted_reg_write(cfg[9], CitirocRedoutFullV_RegisterFile.SCI_REG_CitirocCfg1_REG_CFG9, handle)
	__abstracted_reg_write(cfg[10], CitirocRedoutFullV_RegisterFile.SCI_REG_CitirocCfg1_REG_CFG10, handle)
	__abstracted_reg_write(cfg[11], CitirocRedoutFullV_RegisterFile.SCI_REG_CitirocCfg1_REG_CFG11, handle)
	__abstracted_reg_write(cfg[12], CitirocRedoutFullV_RegisterFile.SCI_REG_CitirocCfg1_REG_CFG12, handle)
	__abstracted_reg_write(cfg[13], CitirocRedoutFullV_RegisterFile.SCI_REG_CitirocCfg1_REG_CFG13, handle)
	__abstracted_reg_write(cfg[14], CitirocRedoutFullV_RegisterFile.SCI_REG_CitirocCfg1_REG_CFG14, handle)
	__abstracted_reg_write(cfg[15], CitirocRedoutFullV_RegisterFile.SCI_REG_CitirocCfg1_REG_CFG15, handle)
	__abstracted_reg_write(cfg[16], CitirocRedoutFullV_RegisterFile.SCI_REG_CitirocCfg1_REG_CFG16, handle)
	__abstracted_reg_write(cfg[17], CitirocRedoutFullV_RegisterFile.SCI_REG_CitirocCfg1_REG_CFG17, handle)
	__abstracted_reg_write(cfg[18], CitirocRedoutFullV_RegisterFile.SCI_REG_CitirocCfg1_REG_CFG18, handle)
	__abstracted_reg_write(cfg[19], CitirocRedoutFullV_RegisterFile.SCI_REG_CitirocCfg1_REG_CFG19, handle)
	__abstracted_reg_write(0, CitirocRedoutFullV_RegisterFile.SCI_REG_CitirocCfg1_START_REG_CFG, handle)
	__abstracted_reg_write(1, CitirocRedoutFullV_RegisterFile.SCI_REG_CitirocCfg1_START_REG_CFG, handle)
	__abstracted_reg_write(0, CitirocRedoutFullV_RegisterFile.SCI_REG_CitirocCfg1_START_REG_CFG, handle)




def Citiroc_CitirocCfg0_CONFIG(incfg, handle):  
	bitstream = array.array('I',(0 for i in range(0,1152)))
	cfg = array.array('I',(0 for i in range(0,20)))
	bitstream_str = np.fromstring(incfg,'u1') - ord('0')
	for i in range (0,len(bitstream_str)):
		bitstream[i] = bitstream_str[i]
	for i in range (0,36):
		for j in range(0,32):
			cfg[i] += (bitstream[i*32+j] << j)
	__abstracted_reg_write(cfg[0], CitirocRedoutFullV_RegisterFile.SCI_REG_CitirocCfg2_REG_CFG0, handle)
	__abstracted_reg_write(cfg[1], CitirocRedoutFullV_RegisterFile.SCI_REG_CitirocCfg2_REG_CFG1, handle)
	__abstracted_reg_write(cfg[2], CitirocRedoutFullV_RegisterFile.SCI_REG_CitirocCfg2_REG_CFG2, handle)
	__abstracted_reg_write(cfg[3], CitirocRedoutFullV_RegisterFile.SCI_REG_CitirocCfg2_REG_CFG3, handle)
	__abstracted_reg_write(cfg[4], CitirocRedoutFullV_RegisterFile.SCI_REG_CitirocCfg2_REG_CFG4, handle)
	__abstracted_reg_write(cfg[5], CitirocRedoutFullV_RegisterFile.SCI_REG_CitirocCfg2_REG_CFG5, handle)
	__abstracted_reg_write(cfg[6], CitirocRedoutFullV_RegisterFile.SCI_REG_CitirocCfg2_REG_CFG6, handle)
	__abstracted_reg_write(cfg[7], CitirocRedoutFullV_RegisterFile.SCI_REG_CitirocCfg2_REG_CFG7, handle)
	__abstracted_reg_write(cfg[8], CitirocRedoutFullV_RegisterFile.SCI_REG_CitirocCfg2_REG_CFG8, handle)
	__abstracted_reg_write(cfg[9], CitirocRedoutFullV_RegisterFile.SCI_REG_CitirocCfg2_REG_CFG9, handle)
	__abstracted_reg_write(cfg[10], CitirocRedoutFullV_RegisterFile.SCI_REG_CitirocCfg2_REG_CFG10, handle)
	__abstracted_reg_write(cfg[11], CitirocRedoutFullV_RegisterFile.SCI_REG_CitirocCfg2_REG_CFG11, handle)
	__abstracted_reg_write(cfg[12], CitirocRedoutFullV_RegisterFile.SCI_REG_CitirocCfg2_REG_CFG12, handle)
	__abstracted_reg_write(cfg[13], CitirocRedoutFullV_RegisterFile.SCI_REG_CitirocCfg2_REG_CFG13, handle)
	__abstracted_reg_write(cfg[14], CitirocRedoutFullV_RegisterFile.SCI_REG_CitirocCfg2_REG_CFG14, handle)
	__abstracted_reg_write(cfg[15], CitirocRedoutFullV_RegisterFile.SCI_REG_CitirocCfg2_REG_CFG15, handle)
	__abstracted_reg_write(cfg[16], CitirocRedoutFullV_RegisterFile.SCI_REG_CitirocCfg2_REG_CFG16, handle)
	__abstracted_reg_write(cfg[17], CitirocRedoutFullV_RegisterFile.SCI_REG_CitirocCfg2_REG_CFG17, handle)
	__abstracted_reg_write(cfg[18], CitirocRedoutFullV_RegisterFile.SCI_REG_CitirocCfg2_REG_CFG18, handle)
	__abstracted_reg_write(cfg[19], CitirocRedoutFullV_RegisterFile.SCI_REG_CitirocCfg2_REG_CFG19, handle)
	__abstracted_reg_write(0, CitirocRedoutFullV_RegisterFile.SCI_REG_CitirocCfg2_START_REG_CFG, handle)
	__abstracted_reg_write(1, CitirocRedoutFullV_RegisterFile.SCI_REG_CitirocCfg2_START_REG_CFG, handle)
	__abstracted_reg_write(0, CitirocRedoutFullV_RegisterFile.SCI_REG_CitirocCfg2_START_REG_CFG, handle)




def Citiroc_CitirocCfg0_CONFIG(incfg, handle):  
	bitstream = array.array('I',(0 for i in range(0,1152)))
	cfg = array.array('I',(0 for i in range(0,20)))
	bitstream_str = np.fromstring(incfg,'u1') - ord('0')
	for i in range (0,len(bitstream_str)):
		bitstream[i] = bitstream_str[i]
	for i in range (0,36):
		for j in range(0,32):
			cfg[i] += (bitstream[i*32+j] << j)
	__abstracted_reg_write(cfg[0], CitirocRedoutFullV_RegisterFile.SCI_REG_CitirocCfg3_REG_CFG0, handle)
	__abstracted_reg_write(cfg[1], CitirocRedoutFullV_RegisterFile.SCI_REG_CitirocCfg3_REG_CFG1, handle)
	__abstracted_reg_write(cfg[2], CitirocRedoutFullV_RegisterFile.SCI_REG_CitirocCfg3_REG_CFG2, handle)
	__abstracted_reg_write(cfg[3], CitirocRedoutFullV_RegisterFile.SCI_REG_CitirocCfg3_REG_CFG3, handle)
	__abstracted_reg_write(cfg[4], CitirocRedoutFullV_RegisterFile.SCI_REG_CitirocCfg3_REG_CFG4, handle)
	__abstracted_reg_write(cfg[5], CitirocRedoutFullV_RegisterFile.SCI_REG_CitirocCfg3_REG_CFG5, handle)
	__abstracted_reg_write(cfg[6], CitirocRedoutFullV_RegisterFile.SCI_REG_CitirocCfg3_REG_CFG6, handle)
	__abstracted_reg_write(cfg[7], CitirocRedoutFullV_RegisterFile.SCI_REG_CitirocCfg3_REG_CFG7, handle)
	__abstracted_reg_write(cfg[8], CitirocRedoutFullV_RegisterFile.SCI_REG_CitirocCfg3_REG_CFG8, handle)
	__abstracted_reg_write(cfg[9], CitirocRedoutFullV_RegisterFile.SCI_REG_CitirocCfg3_REG_CFG9, handle)
	__abstracted_reg_write(cfg[10], CitirocRedoutFullV_RegisterFile.SCI_REG_CitirocCfg3_REG_CFG10, handle)
	__abstracted_reg_write(cfg[11], CitirocRedoutFullV_RegisterFile.SCI_REG_CitirocCfg3_REG_CFG11, handle)
	__abstracted_reg_write(cfg[12], CitirocRedoutFullV_RegisterFile.SCI_REG_CitirocCfg3_REG_CFG12, handle)
	__abstracted_reg_write(cfg[13], CitirocRedoutFullV_RegisterFile.SCI_REG_CitirocCfg3_REG_CFG13, handle)
	__abstracted_reg_write(cfg[14], CitirocRedoutFullV_RegisterFile.SCI_REG_CitirocCfg3_REG_CFG14, handle)
	__abstracted_reg_write(cfg[15], CitirocRedoutFullV_RegisterFile.SCI_REG_CitirocCfg3_REG_CFG15, handle)
	__abstracted_reg_write(cfg[16], CitirocRedoutFullV_RegisterFile.SCI_REG_CitirocCfg3_REG_CFG16, handle)
	__abstracted_reg_write(cfg[17], CitirocRedoutFullV_RegisterFile.SCI_REG_CitirocCfg3_REG_CFG17, handle)
	__abstracted_reg_write(cfg[18], CitirocRedoutFullV_RegisterFile.SCI_REG_CitirocCfg3_REG_CFG18, handle)
	__abstracted_reg_write(cfg[19], CitirocRedoutFullV_RegisterFile.SCI_REG_CitirocCfg3_REG_CFG19, handle)
	__abstracted_reg_write(0, CitirocRedoutFullV_RegisterFile.SCI_REG_CitirocCfg3_START_REG_CFG, handle)
	__abstracted_reg_write(1, CitirocRedoutFullV_RegisterFile.SCI_REG_CitirocCfg3_START_REG_CFG, handle)
	__abstracted_reg_write(0, CitirocRedoutFullV_RegisterFile.SCI_REG_CitirocCfg3_START_REG_CFG, handle)




def CPACK_CP_0_RESET(handle):
	err = __abstracted_reg_write(2, CitirocRedoutFullV_RegisterFile.SCI_REG_CP_0_CONFIG, handle)
	err = __abstracted_reg_write(0, CitirocRedoutFullV_RegisterFile.SCI_REG_CP_0_CONFIG, handle)
	return err

def CPACK_CP_0_FLUSH(handle):
	err = __abstracted_reg_write(4, CitirocRedoutFullV_RegisterFile.SCI_REG_CP_0_CONFIG, handle)
	err = __abstracted_reg_write(0, CitirocRedoutFullV_RegisterFile.SCI_REG_CP_0_CONFIG, handle)
	return err

def CPACK_CP_0_START(handle):
	err = __abstracted_reg_write(2, CitirocRedoutFullV_RegisterFile.SCI_REG_CP_0_CONFIG, handle)
	if (err != 0):
	   return False
	err = __abstracted_reg_write(0, CitirocRedoutFullV_RegisterFile.SCI_REG_CP_0_CONFIG, handle)
	if (err != 0):
	   return False
	err = __abstracted_reg_write(1, CitirocRedoutFullV_RegisterFile.SCI_REG_CP_0_CONFIG, handle)
	if (err != 0):
	   return False
	return True

def CPACK_CP_0_GET_STATUS(handle):
	[err, status] = __abstracted_reg_read(CitirocRedoutFullV_RegisterFile.SCI_REG_CP_0_READ_STATUS, handle)
	status = status & 0xf
	return err, status

def CPACK_CP_0_GET_AVAILABLE_DATA(handle):
	[err, status] = __abstracted_reg_read(CitirocRedoutFullV_RegisterFile.SCI_REG_CP_0_READ_VALID_WORDS, handle)
	return err, status

def CPACK_CP_0_GET_DATA(n_packet, timeout_ms, handle):
	data_length = n_packet *( 3 + <<<NUMBER OF PACKET LINES AFTER THE HEADER HERE>>>)
	[err, data, read_data, valid_data] = __abstracted_fifo_read(data_length, CitirocRedoutFullV_RegisterFile.SCI_REG_CP_0_FIFOADDRESS, CitirocRedoutFullV_RegisterFile.SCI_REG_CP_0_READ_STATUS, True, timeout_ms, handle)
	return err, data, read_data, valid_data


def CPACK_CP_0_RECONSTRUCT_DATA(FrameData):
	in_sync = 0
	tot_data = len(FrameData)
	n_ch = <<<NUMBER OF PACKET LINES AFTER THE HEADER HERE>>>
	n_packet = tot_data / (n_ch + 3)
	event_energy, Time_Code, Pack_Id, Energy = ([] for i in range(4))
	for i in range(len(FrameData)):
		mpe = FrameData[i]
		if (in_sync == 0):
			if (mpe != 0x<<<YOUR HEADER HERE>>>):
				continue
			in_sync = 1
			continue
		if (in_sync == 1):
			event_timecode = mpe 
			Time_Code.append(event_timecode)
			in_sync = 2
			continue
		if (in_sync == 2):
			Pack_Id.append(mpe)
			in_sync = 3
			ch_index = 0
			continue
		if (in_sync == 3):
			if (mpe == 0x<<<YOUR HEADER HERE>>>):
				in_sync = 1
			else:
				ev_energy = mpe
				event_energy.append(ev_energy)
				ch_index += 1
				if (ch_index == n_ch):
					Energy.append(event_energy)
					event_energy = []
					in_sync = 0
	return Time_Code, Pack_Id, Energy




def CitirocFRAME_CitirocFrame0_RESET(handle):
	err = __abstracted_reg_write(0x100, CitirocRedoutFullV_RegisterFile.SCI_REG_CitirocFrame0_CONTROL, handle)
	return err

def CitirocFRAME_CitirocFrame0_START(handle):
	err = __abstracted_reg_write(0, CitirocRedoutFullV_RegisterFile.SCI_REG_CitirocFrame0_CONTROL, handle)
def CitirocFRAME_CitirocFrame0_GET_STATUS(handle):
	[err, status] = __abstracted_reg_read(CitirocRedoutFullV_RegisterFile.SCI_REG_CitirocFrame0_STATUS, handle)
	available = status & 0x1
	word_available = (status >> 16) & 0xFFFF
	return err, available, word_available

def CitirocFRAME_CitirocFrame0_GET_DATA(n_packet, timeout_ms, handle):
	data_length = n_packet * 38
	[err, data, read_data, valid_data] = __abstracted_fifo_read(data_length, CitirocRedoutFullV_RegisterFile.SCI_REG_CitirocFrame0_FIFOADDRESS,CitirocRedoutFullV_RegisterFile.SCI_REG_CitirocFrame0_STATUS, 1, timeout_ms, handle)
	return err, data, read_data.value, valid_data.value

def CitirocFRAME_CitirocFrame0_RECONSTRUCT_DATA(FrameData, valid_data):
	in_sync = 0
	datarow = array.array('I',(0 for i in range(0,100)))
	event_charge_hg, event_charge_lg, event_hit, Time_Code, RunTime_Code, AsicId, Pack_Id, ChargeHg, ChargeLg, Hit  = ([] for i in range(10))
	for i in range(valid_data):
		mpe = FrameData[i]
		if (in_sync == 0):
			if (mpe>>4 != 0x8000000):
				in_sync = 0
				continue
			__asic_id = mpe & 0x4
			in_sync = 1
			continue
		if (in_sync == 1):
			__timecode = mpe
			in_sync = 2
			continue
		if (in_sync == 2):
			__runtimecode = mpe
			in_sync = 3
			continue
		if (in_sync == 3):
			__runtimecode += mpe << 32
			in_sync = 4
			continue
		if (in_sync == 4):
			__packid = mpe
			j=0
			in_sync = 5
			continue
		if (in_sync == 5):
			datarow[j * 3 + 0] = (mpe >> 0) & 0x3FFF
			datarow[j * 3 + 1] = (mpe >> 14) & 0x3FFF
			datarow[j * 3 + 2] = (mpe >> 28) & 0x1
			j+=1
			if (j == 32):
				in_sync = 6
				event_charge_hg = []
				event_charge_lg = []
				event_hit = []
			continue
		if (in_sync == 6):
			if ((mpe & 0xc0000000) == 0xc0000000):
				for i in range(0,32):
					event_hit.append(datarow[(i * 3) + 2])
					event_charge_hg.append( datarow[(i * 3) + 0] )
					event_charge_lg.append( datarow[(i * 3) + 1] )
				AsicId.append(__asic_id)
				Time_Code.append(__timecode)
				RunTime_Code.append(__runtimecode)
				Pack_Id.append(__packid)
				ChargeHg.append(event_charge_hg)
				ChargeLg.append(event_charge_lg)
				Hit.append(event_hit)
			in_sync = 0
			continue

	return AsicId, Time_Code, RunTime_Code, Pack_Id, ChargeHg, ChargeLg, Hit




def RATE_METER_RateMeter_1_GET_DATA(channels, timeout_ms, handle):
    [err, data, read_data, valid_data] = __abstracted_mem_read(channels, CitirocRedoutFullV_RegisterFile.SCI_REG_RateMeter_1_FIFOADDRESS, timeout_ms, handle)
    return err, data, read_data, valid_data




def RATE_METER_RateMeter_1_GET_DATA_COUNTS(channels, timeout_ms, handle):
    [err, data, read_data, valid_data] = __abstracted_mem_read(channels, CitirocRedoutFullV_RegisterFile.SCI_REG_RateMeter_1_FIFOADDRESS + 512, timeout_ms, handle)
    return err, data, read_data, valid_data




def RATE_METER_RateMeter_0_GET_DATA(channels, timeout_ms, handle):
    [err, data, read_data, valid_data] = __abstracted_mem_read(channels, CitirocRedoutFullV_RegisterFile.SCI_REG_RateMeter_0_FIFOADDRESS, timeout_ms, handle)
    return err, data, read_data, valid_data




def RATE_METER_RateMeter_0_GET_DATA_COUNTS(channels, timeout_ms, handle):
    [err, data, read_data, valid_data] = __abstracted_mem_read(channels, CitirocRedoutFullV_RegisterFile.SCI_REG_RateMeter_0_FIFOADDRESS + 512, timeout_ms, handle)
    return err, data, read_data, valid_data




def RATE_METER_RateMeter_2_GET_DATA(channels, timeout_ms, handle):
    [err, data, read_data, valid_data] = __abstracted_mem_read(channels, CitirocRedoutFullV_RegisterFile.SCI_REG_RateMeter_2_FIFOADDRESS, timeout_ms, handle)
    return err, data, read_data, valid_data




def RATE_METER_RateMeter_2_GET_DATA_COUNTS(channels, timeout_ms, handle):
    [err, data, read_data, valid_data] = __abstracted_mem_read(channels, CitirocRedoutFullV_RegisterFile.SCI_REG_RateMeter_2_FIFOADDRESS + 512, timeout_ms, handle)
    return err, data, read_data, valid_data




def RATE_METER_RateMeter_3_GET_DATA(channels, timeout_ms, handle):
    [err, data, read_data, valid_data] = __abstracted_mem_read(channels, CitirocRedoutFullV_RegisterFile.SCI_REG_RateMeter_3_FIFOADDRESS, timeout_ms, handle)
    return err, data, read_data, valid_data




def RATE_METER_RateMeter_3_GET_DATA_COUNTS(channels, timeout_ms, handle):
    [err, data, read_data, valid_data] = __abstracted_mem_read(channels, CitirocRedoutFullV_RegisterFile.SCI_REG_RateMeter_3_FIFOADDRESS + 512, timeout_ms, handle)
    return err, data, read_data, valid_data



def OSCILLOSCOPE_Oscilloscope_0_START(handle):
    err = __abstracted_reg_write(0, CitirocRedoutFullV_RegisterFile.SCI_REG_Oscilloscope_0_CONFIG_ARM, handle)
    if (err != 0):
       return False
    err = __abstracted_reg_write(1, CitirocRedoutFullV_RegisterFile.SCI_REG_Oscilloscope_0_CONFIG_ARM, handle)
    if (err != 0):
       return False
    return True

def OSCILLOSCOPE_Oscilloscope_0_SET_DECIMATOR(OscilloscopeDecimator, handle):
    err = __abstracted_reg_write(OscilloscopeDecimator, CitirocRedoutFullV_RegisterFile.SCI_REG_Oscilloscope_0_CONFIG_DECIMATOR, handle)
    return err

def OSCILLOSCOPE_Oscilloscope_0_SET_PRETRIGGER(OscilloscopePreTrigger, handle):
    err = __abstracted_reg_write(OscilloscopePreTrigger, CitirocRedoutFullV_RegisterFile.SCI_REG_Oscilloscope_0_CONFIG_PRETRIGGER, handle)
    return err

def OSCILLOSCOPE_Oscilloscope_0_SET_TRIGGER_LEVEL(OscilloscopeTriggerLevel, handle):
    err = __abstracted_reg_write(OscilloscopeTriggerLevel, CitirocRedoutFullV_RegisterFile.SCI_REG_Oscilloscope_0_CONFIG_TRIGGER_LEVEL, handle)
    return err

def OSCILLOSCOPE_Oscilloscope_0_SET_TRIGGER_MODE(OscilloscopeTriggerMode, OscilloscopeTriggerChannel, OscilloscopeTriggerEdge, handle):
    AnalogTrigger = 0
    Digital0Trigger = 0
    Digital1Trigger = 0
    Digital2Trigger = 0
    Digital3Trigger = 0
    SoftwareTrigger = 0
    if (OscilloscopeTriggerMode == "Analog"):
        AnalogTrigger = 1
    if (OscilloscopeTriggerMode == "Digital0"):
        Digital0Trigger = 1
    if (OscilloscopeTriggerMode == "Digital1"):
        Digital1Trigger = 1
    if (OscilloscopeTriggerMode == "Digital2"):
        Digital2Trigger = 1
    if (OscilloscopeTriggerMode == "Digital3"):
        Digital3Trigger = 1
    if (OscilloscopeTriggerMode == "Free"):
        SoftwareTrigger = 1
    if (OscilloscopeTriggerEdge == "Rising"):
        Edge = 0
    else:
        Edge = 1
    triggermode = c_int(0)
    triggermode = (OscilloscopeTriggerChannel << 8)  + (SoftwareTrigger << 7 ) + (Edge << 3) + (SoftwareTrigger << 1) + AnalogTrigger +(Digital0Trigger << 2) + (Digital1Trigger << 2) + Digital1Trigger + (Digital2Trigger << 2) + (Digital2Trigger << 1) + (Digital3Trigger << 2) + (Digital3Trigger << 1) + Digital3Trigger
    err = __abstracted_reg_write(triggermode, CitirocRedoutFullV_RegisterFile.SCI_REG_Oscilloscope_0_CONFIG_TRIGGER_MODE, handle)
    return err

def OSCILLOSCOPE_Oscilloscope_0_GET_STATUS(handle):
    [err, status] = __abstracted_reg_read(CitirocRedoutFullV_RegisterFile.SCI_REG_Oscilloscope_0_READ_STATUS, handle)
    return err, status

def OSCILLOSCOPE_Oscilloscope_0_GET_POSITION(handle):
    [err, position] = __abstracted_reg_read(CitirocRedoutFullV_RegisterFile.SCI_REG_Oscilloscope_0_READ_POSITION, handle)
    return err, position

def OSCILLOSCOPE_Oscilloscope_0_GET_DATA(timeout_ms, handle):
    [err, data, read_data, valid_data] = __abstracted_mem_read(2048, CitirocRedoutFullV_RegisterFile.SCI_REG_Oscilloscope_0_FIFOADDRESS, timeout_ms, handle)
    return err, data, read_data, valid_data

def OSCILLOSCOPE_Oscilloscope_0_RECONSTRUCT_DATA(OscilloscopeData, OscilloscopePosition, OscilloscopePreTrigger):
    OscilloscopeChannels = 2
    OscilloscopeSamples = 1024
    Analog = list(range(OscilloscopeSamples*OscilloscopeChannels))
    Digital0 = list(range(OscilloscopeSamples*OscilloscopeChannels))
    Digital1 = list(range(OscilloscopeSamples*OscilloscopeChannels))
    Digital2 = list(range(OscilloscopeSamples*OscilloscopeChannels))
    Digital3 = list(range(OscilloscopeSamples*OscilloscopeChannels))
    for n in range(OscilloscopeChannels):
        current = OscilloscopePosition - OscilloscopePreTrigger
        if ((current) > 0):
            k = 0
            for i in range(current, OscilloscopeSamples-1):
                Analog[k+ OscilloscopeSamples * n] = OscilloscopeData[i+ OscilloscopeSamples * n] & 65535
                Digital0[k+ OscilloscopeSamples * n] = (OscilloscopeData[i+ OscilloscopeSamples * n] >> 16 & 1)
                Digital1[k+ OscilloscopeSamples * n] = (OscilloscopeData[i+ OscilloscopeSamples * n] >> 17 & 1)
                Digital2[k+ OscilloscopeSamples * n] = (OscilloscopeData[i+ OscilloscopeSamples * n] >> 18 & 1)
                Digital3[k+ OscilloscopeSamples * n] = (OscilloscopeData[i+ OscilloscopeSamples * n] >> 19 & 1)
                k = k + 1
            for i in range(0, current-1):
                Analog[k+ OscilloscopeSamples * n] = OscilloscopeData[i+ OscilloscopeSamples * n] & 65535
                Digital0[k+ OscilloscopeSamples * n] = (OscilloscopeData[i+ OscilloscopeSamples * n] >> 16 & 1)
                Digital1[k+ OscilloscopeSamples * n] = (OscilloscopeData[i+ OscilloscopeSamples * n] >> 17 & 1)
                Digital2[k+ OscilloscopeSamples * n] = (OscilloscopeData[i+ OscilloscopeSamples * n] >> 18 & 1)
                Digital3[k+ OscilloscopeSamples * n] = (OscilloscopeData[i+ OscilloscopeSamples * n] >> 19 & 1)
                k = k + 1
        else:
            k = 0
            for i in range(OscilloscopeSamples+current, OscilloscopeSamples-1):
                Analog[k+ OscilloscopeSamples * n] = OscilloscopeData[i+ OscilloscopeSamples * n] & 65535
                Digital0[k+ OscilloscopeSamples * n] = (OscilloscopeData[i+ OscilloscopeSamples * n] >> 16 & 1)
                Digital1[k+ OscilloscopeSamples * n] = (OscilloscopeData[i+ OscilloscopeSamples * n] >> 17 & 1)
                Digital2[k+ OscilloscopeSamples * n] = (OscilloscopeData[i+ OscilloscopeSamples * n] >> 18 & 1)
                Digital3[k+ OscilloscopeSamples * n] = (OscilloscopeData[i+ OscilloscopeSamples * n] >> 19 & 1)
                k = k + 1
            for i in range(0, OscilloscopeSamples+current-1):
                Analog[k+ OscilloscopeSamples * n] = OscilloscopeData[i+ OscilloscopeSamples * n] & 65535
                Digital0[k+ OscilloscopeSamples * n] = (OscilloscopeData[i+ OscilloscopeSamples * n] >> 16 & 1)
                Digital1[k+ OscilloscopeSamples * n] = (OscilloscopeData[i+ OscilloscopeSamples * n] >> 17 & 1)
                Digital2[k+ OscilloscopeSamples * n] = (OscilloscopeData[i+ OscilloscopeSamples * n] >> 18 & 1)
                Digital3[k+ OscilloscopeSamples * n] = (OscilloscopeData[i+ OscilloscopeSamples * n] >> 19 & 1)
                k = k + 1
    return Analog, Digital0, Digital1,Digital2, Digital3



def OSCILLOSCOPE_Oscilloscope_1_START(handle):
    err = __abstracted_reg_write(0, CitirocRedoutFullV_RegisterFile.SCI_REG_Oscilloscope_1_CONFIG_ARM, handle)
    if (err != 0):
       return False
    err = __abstracted_reg_write(1, CitirocRedoutFullV_RegisterFile.SCI_REG_Oscilloscope_1_CONFIG_ARM, handle)
    if (err != 0):
       return False
    return True

def OSCILLOSCOPE_Oscilloscope_1_SET_DECIMATOR(OscilloscopeDecimator, handle):
    err = __abstracted_reg_write(OscilloscopeDecimator, CitirocRedoutFullV_RegisterFile.SCI_REG_Oscilloscope_1_CONFIG_DECIMATOR, handle)
    return err

def OSCILLOSCOPE_Oscilloscope_1_SET_PRETRIGGER(OscilloscopePreTrigger, handle):
    err = __abstracted_reg_write(OscilloscopePreTrigger, CitirocRedoutFullV_RegisterFile.SCI_REG_Oscilloscope_1_CONFIG_PRETRIGGER, handle)
    return err

def OSCILLOSCOPE_Oscilloscope_1_SET_TRIGGER_LEVEL(OscilloscopeTriggerLevel, handle):
    err = __abstracted_reg_write(OscilloscopeTriggerLevel, CitirocRedoutFullV_RegisterFile.SCI_REG_Oscilloscope_1_CONFIG_TRIGGER_LEVEL, handle)
    return err

def OSCILLOSCOPE_Oscilloscope_1_SET_TRIGGER_MODE(OscilloscopeTriggerMode, OscilloscopeTriggerChannel, OscilloscopeTriggerEdge, handle):
    AnalogTrigger = 0
    Digital0Trigger = 0
    Digital1Trigger = 0
    Digital2Trigger = 0
    Digital3Trigger = 0
    SoftwareTrigger = 0
    if (OscilloscopeTriggerMode == "Analog"):
        AnalogTrigger = 1
    if (OscilloscopeTriggerMode == "Digital0"):
        Digital0Trigger = 1
    if (OscilloscopeTriggerMode == "Digital1"):
        Digital1Trigger = 1
    if (OscilloscopeTriggerMode == "Digital2"):
        Digital2Trigger = 1
    if (OscilloscopeTriggerMode == "Digital3"):
        Digital3Trigger = 1
    if (OscilloscopeTriggerMode == "Free"):
        SoftwareTrigger = 1
    if (OscilloscopeTriggerEdge == "Rising"):
        Edge = 0
    else:
        Edge = 1
    triggermode = c_int(0)
    triggermode = (OscilloscopeTriggerChannel << 8)  + (SoftwareTrigger << 7 ) + (Edge << 3) + (SoftwareTrigger << 1) + AnalogTrigger +(Digital0Trigger << 2) + (Digital1Trigger << 2) + Digital1Trigger + (Digital2Trigger << 2) + (Digital2Trigger << 1) + (Digital3Trigger << 2) + (Digital3Trigger << 1) + Digital3Trigger
    err = __abstracted_reg_write(triggermode, CitirocRedoutFullV_RegisterFile.SCI_REG_Oscilloscope_1_CONFIG_TRIGGER_MODE, handle)
    return err

def OSCILLOSCOPE_Oscilloscope_1_GET_STATUS(handle):
    [err, status] = __abstracted_reg_read(CitirocRedoutFullV_RegisterFile.SCI_REG_Oscilloscope_1_READ_STATUS, handle)
    return err, status

def OSCILLOSCOPE_Oscilloscope_1_GET_POSITION(handle):
    [err, position] = __abstracted_reg_read(CitirocRedoutFullV_RegisterFile.SCI_REG_Oscilloscope_1_READ_POSITION, handle)
    return err, position

def OSCILLOSCOPE_Oscilloscope_1_GET_DATA(timeout_ms, handle):
    [err, data, read_data, valid_data] = __abstracted_mem_read(2048, CitirocRedoutFullV_RegisterFile.SCI_REG_Oscilloscope_1_FIFOADDRESS, timeout_ms, handle)
    return err, data, read_data, valid_data

def OSCILLOSCOPE_Oscilloscope_1_RECONSTRUCT_DATA(OscilloscopeData, OscilloscopePosition, OscilloscopePreTrigger):
    OscilloscopeChannels = 2
    OscilloscopeSamples = 1024
    Analog = list(range(OscilloscopeSamples*OscilloscopeChannels))
    Digital0 = list(range(OscilloscopeSamples*OscilloscopeChannels))
    Digital1 = list(range(OscilloscopeSamples*OscilloscopeChannels))
    Digital2 = list(range(OscilloscopeSamples*OscilloscopeChannels))
    Digital3 = list(range(OscilloscopeSamples*OscilloscopeChannels))
    for n in range(OscilloscopeChannels):
        current = OscilloscopePosition - OscilloscopePreTrigger
        if ((current) > 0):
            k = 0
            for i in range(current, OscilloscopeSamples-1):
                Analog[k+ OscilloscopeSamples * n] = OscilloscopeData[i+ OscilloscopeSamples * n] & 65535
                Digital0[k+ OscilloscopeSamples * n] = (OscilloscopeData[i+ OscilloscopeSamples * n] >> 16 & 1)
                Digital1[k+ OscilloscopeSamples * n] = (OscilloscopeData[i+ OscilloscopeSamples * n] >> 17 & 1)
                Digital2[k+ OscilloscopeSamples * n] = (OscilloscopeData[i+ OscilloscopeSamples * n] >> 18 & 1)
                Digital3[k+ OscilloscopeSamples * n] = (OscilloscopeData[i+ OscilloscopeSamples * n] >> 19 & 1)
                k = k + 1
            for i in range(0, current-1):
                Analog[k+ OscilloscopeSamples * n] = OscilloscopeData[i+ OscilloscopeSamples * n] & 65535
                Digital0[k+ OscilloscopeSamples * n] = (OscilloscopeData[i+ OscilloscopeSamples * n] >> 16 & 1)
                Digital1[k+ OscilloscopeSamples * n] = (OscilloscopeData[i+ OscilloscopeSamples * n] >> 17 & 1)
                Digital2[k+ OscilloscopeSamples * n] = (OscilloscopeData[i+ OscilloscopeSamples * n] >> 18 & 1)
                Digital3[k+ OscilloscopeSamples * n] = (OscilloscopeData[i+ OscilloscopeSamples * n] >> 19 & 1)
                k = k + 1
        else:
            k = 0
            for i in range(OscilloscopeSamples+current, OscilloscopeSamples-1):
                Analog[k+ OscilloscopeSamples * n] = OscilloscopeData[i+ OscilloscopeSamples * n] & 65535
                Digital0[k+ OscilloscopeSamples * n] = (OscilloscopeData[i+ OscilloscopeSamples * n] >> 16 & 1)
                Digital1[k+ OscilloscopeSamples * n] = (OscilloscopeData[i+ OscilloscopeSamples * n] >> 17 & 1)
                Digital2[k+ OscilloscopeSamples * n] = (OscilloscopeData[i+ OscilloscopeSamples * n] >> 18 & 1)
                Digital3[k+ OscilloscopeSamples * n] = (OscilloscopeData[i+ OscilloscopeSamples * n] >> 19 & 1)
                k = k + 1
            for i in range(0, OscilloscopeSamples+current-1):
                Analog[k+ OscilloscopeSamples * n] = OscilloscopeData[i+ OscilloscopeSamples * n] & 65535
                Digital0[k+ OscilloscopeSamples * n] = (OscilloscopeData[i+ OscilloscopeSamples * n] >> 16 & 1)
                Digital1[k+ OscilloscopeSamples * n] = (OscilloscopeData[i+ OscilloscopeSamples * n] >> 17 & 1)
                Digital2[k+ OscilloscopeSamples * n] = (OscilloscopeData[i+ OscilloscopeSamples * n] >> 18 & 1)
                Digital3[k+ OscilloscopeSamples * n] = (OscilloscopeData[i+ OscilloscopeSamples * n] >> 19 & 1)
                k = k + 1
    return Analog, Digital0, Digital1,Digital2, Digital3



def OSCILLOSCOPE_Oscilloscope_2_START(handle):
    err = __abstracted_reg_write(0, CitirocRedoutFullV_RegisterFile.SCI_REG_Oscilloscope_2_CONFIG_ARM, handle)
    if (err != 0):
       return False
    err = __abstracted_reg_write(1, CitirocRedoutFullV_RegisterFile.SCI_REG_Oscilloscope_2_CONFIG_ARM, handle)
    if (err != 0):
       return False
    return True

def OSCILLOSCOPE_Oscilloscope_2_SET_DECIMATOR(OscilloscopeDecimator, handle):
    err = __abstracted_reg_write(OscilloscopeDecimator, CitirocRedoutFullV_RegisterFile.SCI_REG_Oscilloscope_2_CONFIG_DECIMATOR, handle)
    return err

def OSCILLOSCOPE_Oscilloscope_2_SET_PRETRIGGER(OscilloscopePreTrigger, handle):
    err = __abstracted_reg_write(OscilloscopePreTrigger, CitirocRedoutFullV_RegisterFile.SCI_REG_Oscilloscope_2_CONFIG_PRETRIGGER, handle)
    return err

def OSCILLOSCOPE_Oscilloscope_2_SET_TRIGGER_LEVEL(OscilloscopeTriggerLevel, handle):
    err = __abstracted_reg_write(OscilloscopeTriggerLevel, CitirocRedoutFullV_RegisterFile.SCI_REG_Oscilloscope_2_CONFIG_TRIGGER_LEVEL, handle)
    return err

def OSCILLOSCOPE_Oscilloscope_2_SET_TRIGGER_MODE(OscilloscopeTriggerMode, OscilloscopeTriggerChannel, OscilloscopeTriggerEdge, handle):
    AnalogTrigger = 0
    Digital0Trigger = 0
    Digital1Trigger = 0
    Digital2Trigger = 0
    Digital3Trigger = 0
    SoftwareTrigger = 0
    if (OscilloscopeTriggerMode == "Analog"):
        AnalogTrigger = 1
    if (OscilloscopeTriggerMode == "Digital0"):
        Digital0Trigger = 1
    if (OscilloscopeTriggerMode == "Digital1"):
        Digital1Trigger = 1
    if (OscilloscopeTriggerMode == "Digital2"):
        Digital2Trigger = 1
    if (OscilloscopeTriggerMode == "Digital3"):
        Digital3Trigger = 1
    if (OscilloscopeTriggerMode == "Free"):
        SoftwareTrigger = 1
    if (OscilloscopeTriggerEdge == "Rising"):
        Edge = 0
    else:
        Edge = 1
    triggermode = c_int(0)
    triggermode = (OscilloscopeTriggerChannel << 8)  + (SoftwareTrigger << 7 ) + (Edge << 3) + (SoftwareTrigger << 1) + AnalogTrigger +(Digital0Trigger << 2) + (Digital1Trigger << 2) + Digital1Trigger + (Digital2Trigger << 2) + (Digital2Trigger << 1) + (Digital3Trigger << 2) + (Digital3Trigger << 1) + Digital3Trigger
    err = __abstracted_reg_write(triggermode, CitirocRedoutFullV_RegisterFile.SCI_REG_Oscilloscope_2_CONFIG_TRIGGER_MODE, handle)
    return err

def OSCILLOSCOPE_Oscilloscope_2_GET_STATUS(handle):
    [err, status] = __abstracted_reg_read(CitirocRedoutFullV_RegisterFile.SCI_REG_Oscilloscope_2_READ_STATUS, handle)
    return err, status

def OSCILLOSCOPE_Oscilloscope_2_GET_POSITION(handle):
    [err, position] = __abstracted_reg_read(CitirocRedoutFullV_RegisterFile.SCI_REG_Oscilloscope_2_READ_POSITION, handle)
    return err, position

def OSCILLOSCOPE_Oscilloscope_2_GET_DATA(timeout_ms, handle):
    [err, data, read_data, valid_data] = __abstracted_mem_read(2048, CitirocRedoutFullV_RegisterFile.SCI_REG_Oscilloscope_2_FIFOADDRESS, timeout_ms, handle)
    return err, data, read_data, valid_data

def OSCILLOSCOPE_Oscilloscope_2_RECONSTRUCT_DATA(OscilloscopeData, OscilloscopePosition, OscilloscopePreTrigger):
    OscilloscopeChannels = 2
    OscilloscopeSamples = 1024
    Analog = list(range(OscilloscopeSamples*OscilloscopeChannels))
    Digital0 = list(range(OscilloscopeSamples*OscilloscopeChannels))
    Digital1 = list(range(OscilloscopeSamples*OscilloscopeChannels))
    Digital2 = list(range(OscilloscopeSamples*OscilloscopeChannels))
    Digital3 = list(range(OscilloscopeSamples*OscilloscopeChannels))
    for n in range(OscilloscopeChannels):
        current = OscilloscopePosition - OscilloscopePreTrigger
        if ((current) > 0):
            k = 0
            for i in range(current, OscilloscopeSamples-1):
                Analog[k+ OscilloscopeSamples * n] = OscilloscopeData[i+ OscilloscopeSamples * n] & 65535
                Digital0[k+ OscilloscopeSamples * n] = (OscilloscopeData[i+ OscilloscopeSamples * n] >> 16 & 1)
                Digital1[k+ OscilloscopeSamples * n] = (OscilloscopeData[i+ OscilloscopeSamples * n] >> 17 & 1)
                Digital2[k+ OscilloscopeSamples * n] = (OscilloscopeData[i+ OscilloscopeSamples * n] >> 18 & 1)
                Digital3[k+ OscilloscopeSamples * n] = (OscilloscopeData[i+ OscilloscopeSamples * n] >> 19 & 1)
                k = k + 1
            for i in range(0, current-1):
                Analog[k+ OscilloscopeSamples * n] = OscilloscopeData[i+ OscilloscopeSamples * n] & 65535
                Digital0[k+ OscilloscopeSamples * n] = (OscilloscopeData[i+ OscilloscopeSamples * n] >> 16 & 1)
                Digital1[k+ OscilloscopeSamples * n] = (OscilloscopeData[i+ OscilloscopeSamples * n] >> 17 & 1)
                Digital2[k+ OscilloscopeSamples * n] = (OscilloscopeData[i+ OscilloscopeSamples * n] >> 18 & 1)
                Digital3[k+ OscilloscopeSamples * n] = (OscilloscopeData[i+ OscilloscopeSamples * n] >> 19 & 1)
                k = k + 1
        else:
            k = 0
            for i in range(OscilloscopeSamples+current, OscilloscopeSamples-1):
                Analog[k+ OscilloscopeSamples * n] = OscilloscopeData[i+ OscilloscopeSamples * n] & 65535
                Digital0[k+ OscilloscopeSamples * n] = (OscilloscopeData[i+ OscilloscopeSamples * n] >> 16 & 1)
                Digital1[k+ OscilloscopeSamples * n] = (OscilloscopeData[i+ OscilloscopeSamples * n] >> 17 & 1)
                Digital2[k+ OscilloscopeSamples * n] = (OscilloscopeData[i+ OscilloscopeSamples * n] >> 18 & 1)
                Digital3[k+ OscilloscopeSamples * n] = (OscilloscopeData[i+ OscilloscopeSamples * n] >> 19 & 1)
                k = k + 1
            for i in range(0, OscilloscopeSamples+current-1):
                Analog[k+ OscilloscopeSamples * n] = OscilloscopeData[i+ OscilloscopeSamples * n] & 65535
                Digital0[k+ OscilloscopeSamples * n] = (OscilloscopeData[i+ OscilloscopeSamples * n] >> 16 & 1)
                Digital1[k+ OscilloscopeSamples * n] = (OscilloscopeData[i+ OscilloscopeSamples * n] >> 17 & 1)
                Digital2[k+ OscilloscopeSamples * n] = (OscilloscopeData[i+ OscilloscopeSamples * n] >> 18 & 1)
                Digital3[k+ OscilloscopeSamples * n] = (OscilloscopeData[i+ OscilloscopeSamples * n] >> 19 & 1)
                k = k + 1
    return Analog, Digital0, Digital1,Digital2, Digital3



def OSCILLOSCOPE_Oscilloscope_3_START(handle):
    err = __abstracted_reg_write(0, CitirocRedoutFullV_RegisterFile.SCI_REG_Oscilloscope_3_CONFIG_ARM, handle)
    if (err != 0):
       return False
    err = __abstracted_reg_write(1, CitirocRedoutFullV_RegisterFile.SCI_REG_Oscilloscope_3_CONFIG_ARM, handle)
    if (err != 0):
       return False
    return True

def OSCILLOSCOPE_Oscilloscope_3_SET_DECIMATOR(OscilloscopeDecimator, handle):
    err = __abstracted_reg_write(OscilloscopeDecimator, CitirocRedoutFullV_RegisterFile.SCI_REG_Oscilloscope_3_CONFIG_DECIMATOR, handle)
    return err

def OSCILLOSCOPE_Oscilloscope_3_SET_PRETRIGGER(OscilloscopePreTrigger, handle):
    err = __abstracted_reg_write(OscilloscopePreTrigger, CitirocRedoutFullV_RegisterFile.SCI_REG_Oscilloscope_3_CONFIG_PRETRIGGER, handle)
    return err

def OSCILLOSCOPE_Oscilloscope_3_SET_TRIGGER_LEVEL(OscilloscopeTriggerLevel, handle):
    err = __abstracted_reg_write(OscilloscopeTriggerLevel, CitirocRedoutFullV_RegisterFile.SCI_REG_Oscilloscope_3_CONFIG_TRIGGER_LEVEL, handle)
    return err

def OSCILLOSCOPE_Oscilloscope_3_SET_TRIGGER_MODE(OscilloscopeTriggerMode, OscilloscopeTriggerChannel, OscilloscopeTriggerEdge, handle):
    AnalogTrigger = 0
    Digital0Trigger = 0
    Digital1Trigger = 0
    Digital2Trigger = 0
    Digital3Trigger = 0
    SoftwareTrigger = 0
    if (OscilloscopeTriggerMode == "Analog"):
        AnalogTrigger = 1
    if (OscilloscopeTriggerMode == "Digital0"):
        Digital0Trigger = 1
    if (OscilloscopeTriggerMode == "Digital1"):
        Digital1Trigger = 1
    if (OscilloscopeTriggerMode == "Digital2"):
        Digital2Trigger = 1
    if (OscilloscopeTriggerMode == "Digital3"):
        Digital3Trigger = 1
    if (OscilloscopeTriggerMode == "Free"):
        SoftwareTrigger = 1
    if (OscilloscopeTriggerEdge == "Rising"):
        Edge = 0
    else:
        Edge = 1
    triggermode = c_int(0)
    triggermode = (OscilloscopeTriggerChannel << 8)  + (SoftwareTrigger << 7 ) + (Edge << 3) + (SoftwareTrigger << 1) + AnalogTrigger +(Digital0Trigger << 2) + (Digital1Trigger << 2) + Digital1Trigger + (Digital2Trigger << 2) + (Digital2Trigger << 1) + (Digital3Trigger << 2) + (Digital3Trigger << 1) + Digital3Trigger
    err = __abstracted_reg_write(triggermode, CitirocRedoutFullV_RegisterFile.SCI_REG_Oscilloscope_3_CONFIG_TRIGGER_MODE, handle)
    return err

def OSCILLOSCOPE_Oscilloscope_3_GET_STATUS(handle):
    [err, status] = __abstracted_reg_read(CitirocRedoutFullV_RegisterFile.SCI_REG_Oscilloscope_3_READ_STATUS, handle)
    return err, status

def OSCILLOSCOPE_Oscilloscope_3_GET_POSITION(handle):
    [err, position] = __abstracted_reg_read(CitirocRedoutFullV_RegisterFile.SCI_REG_Oscilloscope_3_READ_POSITION, handle)
    return err, position

def OSCILLOSCOPE_Oscilloscope_3_GET_DATA(timeout_ms, handle):
    [err, data, read_data, valid_data] = __abstracted_mem_read(2048, CitirocRedoutFullV_RegisterFile.SCI_REG_Oscilloscope_3_FIFOADDRESS, timeout_ms, handle)
    return err, data, read_data, valid_data

def OSCILLOSCOPE_Oscilloscope_3_RECONSTRUCT_DATA(OscilloscopeData, OscilloscopePosition, OscilloscopePreTrigger):
    OscilloscopeChannels = 2
    OscilloscopeSamples = 1024
    Analog = list(range(OscilloscopeSamples*OscilloscopeChannels))
    Digital0 = list(range(OscilloscopeSamples*OscilloscopeChannels))
    Digital1 = list(range(OscilloscopeSamples*OscilloscopeChannels))
    Digital2 = list(range(OscilloscopeSamples*OscilloscopeChannels))
    Digital3 = list(range(OscilloscopeSamples*OscilloscopeChannels))
    for n in range(OscilloscopeChannels):
        current = OscilloscopePosition - OscilloscopePreTrigger
        if ((current) > 0):
            k = 0
            for i in range(current, OscilloscopeSamples-1):
                Analog[k+ OscilloscopeSamples * n] = OscilloscopeData[i+ OscilloscopeSamples * n] & 65535
                Digital0[k+ OscilloscopeSamples * n] = (OscilloscopeData[i+ OscilloscopeSamples * n] >> 16 & 1)
                Digital1[k+ OscilloscopeSamples * n] = (OscilloscopeData[i+ OscilloscopeSamples * n] >> 17 & 1)
                Digital2[k+ OscilloscopeSamples * n] = (OscilloscopeData[i+ OscilloscopeSamples * n] >> 18 & 1)
                Digital3[k+ OscilloscopeSamples * n] = (OscilloscopeData[i+ OscilloscopeSamples * n] >> 19 & 1)
                k = k + 1
            for i in range(0, current-1):
                Analog[k+ OscilloscopeSamples * n] = OscilloscopeData[i+ OscilloscopeSamples * n] & 65535
                Digital0[k+ OscilloscopeSamples * n] = (OscilloscopeData[i+ OscilloscopeSamples * n] >> 16 & 1)
                Digital1[k+ OscilloscopeSamples * n] = (OscilloscopeData[i+ OscilloscopeSamples * n] >> 17 & 1)
                Digital2[k+ OscilloscopeSamples * n] = (OscilloscopeData[i+ OscilloscopeSamples * n] >> 18 & 1)
                Digital3[k+ OscilloscopeSamples * n] = (OscilloscopeData[i+ OscilloscopeSamples * n] >> 19 & 1)
                k = k + 1
        else:
            k = 0
            for i in range(OscilloscopeSamples+current, OscilloscopeSamples-1):
                Analog[k+ OscilloscopeSamples * n] = OscilloscopeData[i+ OscilloscopeSamples * n] & 65535
                Digital0[k+ OscilloscopeSamples * n] = (OscilloscopeData[i+ OscilloscopeSamples * n] >> 16 & 1)
                Digital1[k+ OscilloscopeSamples * n] = (OscilloscopeData[i+ OscilloscopeSamples * n] >> 17 & 1)
                Digital2[k+ OscilloscopeSamples * n] = (OscilloscopeData[i+ OscilloscopeSamples * n] >> 18 & 1)
                Digital3[k+ OscilloscopeSamples * n] = (OscilloscopeData[i+ OscilloscopeSamples * n] >> 19 & 1)
                k = k + 1
            for i in range(0, OscilloscopeSamples+current-1):
                Analog[k+ OscilloscopeSamples * n] = OscilloscopeData[i+ OscilloscopeSamples * n] & 65535
                Digital0[k+ OscilloscopeSamples * n] = (OscilloscopeData[i+ OscilloscopeSamples * n] >> 16 & 1)
                Digital1[k+ OscilloscopeSamples * n] = (OscilloscopeData[i+ OscilloscopeSamples * n] >> 17 & 1)
                Digital2[k+ OscilloscopeSamples * n] = (OscilloscopeData[i+ OscilloscopeSamples * n] >> 18 & 1)
                Digital3[k+ OscilloscopeSamples * n] = (OscilloscopeData[i+ OscilloscopeSamples * n] >> 19 & 1)
                k = k + 1
    return Analog, Digital0, Digital1,Digital2, Digital3

