#include "RegisterFile.h"
#include "Def.h"
#include <stdint.h>
#include <stdlib.h>
#include  <stdbool.h>

#ifdef __cplusplus
#ifdef SCICOMPILER_EXPORTS
#define SCILIB extern "C" __declspec(dllexport) 
#else
#define SCILIB extern "C" __declspec(dllimport)
#endif
#else
#define SCILIB __declspec(dllexport) 
#endif

typedef struct
{
	uint64_t Time_Code;
	uint32_t Id;
	uint32_t Pack_Id;
	uint32_t *Energy;
	uint32_t Valid;
} t_FRAME_packet;


typedef struct
{
	t_FRAME_packet *packets;
	int allocated_packets;
	int valid_packets;
} t_FRAME_packet_collection;




SCILIB int USB3_ListDevices(char *ListOfDevice, char *model,  int *Count);
SCILIB int USB3_ConnectDevice(char *serial_number, NI_HANDLE *handle);
SCILIB int USB3_CloseConnection(NI_HANDLE *handle);
SCILIB int USB3_Init();

SCILIB int __abstracted_mem_write(uint32_t *data, uint32_t count, 
										uint32_t address,  
										uint32_t timeout_ms, NI_HANDLE *handle, 
										uint32_t *written_data);
SCILIB int __abstracted_mem_read(uint32_t *data, uint32_t count, 
										uint32_t address, 
										uint32_t timeout_ms, NI_HANDLE *handle, 
										uint32_t *read_data, uint32_t *valid_data);
SCILIB int __abstracted_fifo_write(uint32_t *data, uint32_t count, 
										uint32_t address,  
										uint32_t timeout_ms, NI_HANDLE *handle, 
										uint32_t *written_data);
SCILIB int __abstracted_fifo_read(uint32_t *data, uint32_t count, 
										uint32_t address, 
										uint32_t address_status, 
										bool blocking,
										uint32_t timeout_ms, NI_HANDLE *handle, 
										uint32_t *read_data, uint32_t *valid_data);
SCILIB int __abstracted_reg_write(uint32_t data, uint32_t address, NI_HANDLE *handle);
SCILIB int __abstracted_reg_read(uint32_t *data, uint32_t address, NI_HANDLE *handle);
SCILIB int AFE_USB3_SetOffset(boolean top, uint32_t DACCODE, NI_HANDLE *handle);
SCILIB int AFE_USB3_SetImpedance(boolean R50, NI_HANDLE *handle);
SCILIB int AFE_USB3_SetIICControllerBaseAddress(uint32_t ControlAddress, uint32_t StatusAddress, NI_HANDLE *handle);

SCILIB int Utility_PEAK_DATA_FORM_DOWNLOAD_BUFFER(void *buffer_handle, int32_t *val);

SCILIB int Utility_ENQUEUE_DATA_IN_DOWNLOAD_BUFFER(void *buffer_handle, int32_t *val, uint32_t size, uint32_t *enqueued_data);

SCILIB int Utility_ALLOCATE_DOWNLOAD_BUFFER(void **buffer_handle, uint32_t buffer_size);

SCILIB void free_FRAME_packet_collectionvoid(t_FRAME_packet_collection *decoded_packets);
SCILIB void free_PETIROCFRAME_packet_collection(t_ASIC_packet_collection *decoded_packets);

SCILIB int PETIROC_ALLFIFO_FLUSH(NI_HANDLE *handle);

SCILIB int SetHV_A7585D(bool Enable, float voltage, NI_HANDLE *handle);
SCILIB int GetHV_A7585D(bool *Enable, float *voltage, float *current, NI_HANDLE *handle);
SCILIB int IICUser_OpenControllerInit(uint32_t ControlAddress, uint32_t StatusAddress, NI_HANDLE *handle, NI_IIC_HANDLE *IIC_Handle);
SCILIB int IICUser_ReadData(uint8_t address, uint8_t *value, int len, uint8_t *value_read, int len_read, NI_IIC_HANDLE *IIC_Handle);
SCILIB int IICUser_WriteData(uint8_t address, uint8_t *value, int len, NI_IIC_HANDLE *IIC_Handle);
SCILIB int GetDT5550WTempSens(int address, float *temp, NI_HANDLE *handle);
SCILIB char *ReadFirmwareInformation(NI_HANDLE *handle);
SCILIB int ReadSN(uint32_t *SN, NI_HANDLE *handle);
SCILIB int GetDT5550_DGBoardInfo(char *model, int *asic_count, int *SN, NI_HANDLE *handle);





















typedef struct  {
    uint32_t row[133];
}t_CP_0_struct;

















































SCILIB int REG_TRIG_A_SEL_GET(uint32_t *val, NI_HANDLE *handle);
SCILIB int REG_TRIG_A_SEL_SET(uint32_t val, NI_HANDLE *handle);
SCILIB int REG_VET_A_EN_GET(uint32_t *val, NI_HANDLE *handle);
SCILIB int REG_VET_A_EN_SET(uint32_t val, NI_HANDLE *handle);
SCILIB int REG_VET_B_EN_GET(uint32_t *val, NI_HANDLE *handle);
SCILIB int REG_VET_B_EN_SET(uint32_t val, NI_HANDLE *handle);
SCILIB int REG_VET_C_EN_GET(uint32_t *val, NI_HANDLE *handle);
SCILIB int REG_VET_C_EN_SET(uint32_t val, NI_HANDLE *handle);
SCILIB int REG_VET_D_EN_GET(uint32_t *val, NI_HANDLE *handle);
SCILIB int REG_VET_D_EN_SET(uint32_t val, NI_HANDLE *handle);
SCILIB int REG_SW_VET_A_GET(uint32_t *val, NI_HANDLE *handle);
SCILIB int REG_SW_VET_A_SET(uint32_t val, NI_HANDLE *handle);
SCILIB int REG_SW_VET_B_GET(uint32_t *val, NI_HANDLE *handle);
SCILIB int REG_SW_VET_B_SET(uint32_t val, NI_HANDLE *handle);
SCILIB int REG_SW_VET_C_GET(uint32_t *val, NI_HANDLE *handle);
SCILIB int REG_SW_VET_C_SET(uint32_t val, NI_HANDLE *handle);
SCILIB int REG_SW_VET_D_GET(uint32_t *val, NI_HANDLE *handle);
SCILIB int REG_SW_VET_D_SET(uint32_t val, NI_HANDLE *handle);
SCILIB int REG_TRIG_GBL_SEL_GET(uint32_t *val, NI_HANDLE *handle);
SCILIB int REG_TRIG_GBL_SEL_SET(uint32_t val, NI_HANDLE *handle);
SCILIB int REG_EXT_DELAY_GET(uint32_t *val, NI_HANDLE *handle);
SCILIB int REG_EXT_DELAY_SET(uint32_t val, NI_HANDLE *handle);
SCILIB int REG_SW_TRIG_FREQ_GET(uint32_t *val, NI_HANDLE *handle);
SCILIB int REG_SW_TRIG_FREQ_SET(uint32_t val, NI_HANDLE *handle);
SCILIB int REG_A_RATE_GET(uint32_t *val, NI_HANDLE *handle);
SCILIB int REG_A_RATE_SET(uint32_t val, NI_HANDLE *handle);
SCILIB int REG_B_RATE_GET(uint32_t *val, NI_HANDLE *handle);
SCILIB int REG_B_RATE_SET(uint32_t val, NI_HANDLE *handle);
SCILIB int REG_C_RATE_GET(uint32_t *val, NI_HANDLE *handle);
SCILIB int REG_C_RATE_SET(uint32_t val, NI_HANDLE *handle);
SCILIB int REG_D_RATE_GET(uint32_t *val, NI_HANDLE *handle);
SCILIB int REG_D_RATE_SET(uint32_t val, NI_HANDLE *handle);
SCILIB int REG_T0_COUNT_GET(uint32_t *val, NI_HANDLE *handle);
SCILIB int REG_T0_COUNT_SET(uint32_t val, NI_HANDLE *handle);
SCILIB int REG_A_TRG_GET(uint32_t *val, NI_HANDLE *handle);
SCILIB int REG_A_TRG_SET(uint32_t val, NI_HANDLE *handle);
SCILIB int REG_B_TRG_GET(uint32_t *val, NI_HANDLE *handle);
SCILIB int REG_B_TRG_SET(uint32_t val, NI_HANDLE *handle);
SCILIB int REG_C_TRG_GET(uint32_t *val, NI_HANDLE *handle);
SCILIB int REG_C_TRG_SET(uint32_t val, NI_HANDLE *handle);
SCILIB int REG_D_TRG_GET(uint32_t *val, NI_HANDLE *handle);
SCILIB int REG_D_TRG_SET(uint32_t val, NI_HANDLE *handle);
SCILIB int REG_RUNSTART_GET(uint32_t *val, NI_HANDLE *handle);
SCILIB int REG_RUNSTART_SET(uint32_t val, NI_HANDLE *handle);
SCILIB int REG_RUN_TIME_LSB_GET(uint32_t *val, NI_HANDLE *handle);
SCILIB int REG_RUN_TIME_LSB_SET(uint32_t val, NI_HANDLE *handle);
SCILIB int REG_RUN_TIME_MSB_GET(uint32_t *val, NI_HANDLE *handle);
SCILIB int REG_RUN_TIME_MSB_SET(uint32_t val, NI_HANDLE *handle);
SCILIB int REG_DEAD_TIME_LSB_GET(uint32_t *val, NI_HANDLE *handle);
SCILIB int REG_DEAD_TIME_LSB_SET(uint32_t val, NI_HANDLE *handle);
SCILIB int REG_DEAD_TIME_MSB_GET(uint32_t *val, NI_HANDLE *handle);
SCILIB int REG_DEAD_TIME_MSB_SET(uint32_t val, NI_HANDLE *handle);
SCILIB int REG_A_LOST_GET(uint32_t *val, NI_HANDLE *handle);
SCILIB int REG_A_LOST_SET(uint32_t val, NI_HANDLE *handle);
SCILIB int REG_B_LOST_GET(uint32_t *val, NI_HANDLE *handle);
SCILIB int REG_B_LOST_SET(uint32_t val, NI_HANDLE *handle);
SCILIB int REG_C_LOST_GET(uint32_t *val, NI_HANDLE *handle);
SCILIB int REG_C_LOST_SET(uint32_t val, NI_HANDLE *handle);
SCILIB int REG_D_LOST_GET(uint32_t *val, NI_HANDLE *handle);
SCILIB int REG_D_LOST_SET(uint32_t val, NI_HANDLE *handle);
SCILIB int REG_T0_SOFT_FREQ_GET(uint32_t *val, NI_HANDLE *handle);
SCILIB int REG_T0_SOFT_FREQ_SET(uint32_t val, NI_HANDLE *handle);
SCILIB int REG_T0_SEL_GET(uint32_t *val, NI_HANDLE *handle);
SCILIB int REG_T0_SEL_SET(uint32_t val, NI_HANDLE *handle);
SCILIB int REG_HOLD_TIME_GET(uint32_t *val, NI_HANDLE *handle);
SCILIB int REG_HOLD_TIME_SET(uint32_t val, NI_HANDLE *handle);
SCILIB int REG_FR_IFP_GET(uint32_t *val, NI_HANDLE *handle);
SCILIB int REG_FR_IFP_SET(uint32_t val, NI_HANDLE *handle);
SCILIB int REG_FR_LIMIT_GET(uint32_t *val, NI_HANDLE *handle);
SCILIB int REG_FR_LIMIT_SET(uint32_t val, NI_HANDLE *handle);
SCILIB int REG_FR_IFP2_GET(uint32_t *val, NI_HANDLE *handle);
SCILIB int REG_FR_IFP2_SET(uint32_t val, NI_HANDLE *handle);
SCILIB int REG_FR_MODE_GET(uint32_t *val, NI_HANDLE *handle);
SCILIB int REG_FR_MODE_SET(uint32_t val, NI_HANDLE *handle);
SCILIB int REG_FR_DBG1_GET(uint32_t *val, NI_HANDLE *handle);
SCILIB int REG_FR_DBG1_SET(uint32_t val, NI_HANDLE *handle);
SCILIB int REG_FR_DBG2_GET(uint32_t *val, NI_HANDLE *handle);
SCILIB int REG_FR_DBG2_SET(uint32_t val, NI_HANDLE *handle);
SCILIB int REG_VALIDATION_CFG_GET(uint32_t *val, NI_HANDLE *handle);
SCILIB int REG_VALIDATION_CFG_SET(uint32_t val, NI_HANDLE *handle);
SCILIB int REG_HV_ON_GET(uint32_t *val, NI_HANDLE *handle);
SCILIB int REG_HV_ON_SET(uint32_t val, NI_HANDLE *handle);
SCILIB int REG_HV_EMERGENCY_GET(uint32_t *val, NI_HANDLE *handle);
SCILIB int REG_HV_EMERGENCY_SET(uint32_t val, NI_HANDLE *handle);
SCILIB int REG_HV_VOUT_GET(uint32_t *val, NI_HANDLE *handle);
SCILIB int REG_HV_VOUT_SET(uint32_t val, NI_HANDLE *handle);
SCILIB int REG_HV_ENTCOMP_GET(uint32_t *val, NI_HANDLE *handle);
SCILIB int REG_HV_ENTCOMP_SET(uint32_t val, NI_HANDLE *handle);
SCILIB int REG_HV_TM_GET(uint32_t *val, NI_HANDLE *handle);
SCILIB int REG_HV_TM_SET(uint32_t val, NI_HANDLE *handle);
SCILIB int REG_HV_TQ_GET(uint32_t *val, NI_HANDLE *handle);
SCILIB int REG_HV_TQ_SET(uint32_t val, NI_HANDLE *handle);
SCILIB int REG_HV_TCOEF_GET(uint32_t *val, NI_HANDLE *handle);
SCILIB int REG_HV_TCOEF_SET(uint32_t val, NI_HANDLE *handle);
SCILIB int REG_HV_IMAX_GET(uint32_t *val, NI_HANDLE *handle);
SCILIB int REG_HV_IMAX_SET(uint32_t val, NI_HANDLE *handle);
SCILIB int REG_HV_RAMP_GET(uint32_t *val, NI_HANDLE *handle);
SCILIB int REG_HV_RAMP_SET(uint32_t val, NI_HANDLE *handle);
SCILIB int REG_HV_VMAX_GET(uint32_t *val, NI_HANDLE *handle);
SCILIB int REG_HV_VMAX_SET(uint32_t val, NI_HANDLE *handle);
SCILIB int REG_HV_MSTATUS_GET(uint32_t *val, NI_HANDLE *handle);
SCILIB int REG_HV_MSTATUS_SET(uint32_t val, NI_HANDLE *handle);
SCILIB int REG_HV_MVOUT_GET(uint32_t *val, NI_HANDLE *handle);
SCILIB int REG_HV_MVOUT_SET(uint32_t val, NI_HANDLE *handle);
SCILIB int REG_HV_MTEMP_GET(uint32_t *val, NI_HANDLE *handle);
SCILIB int REG_HV_MTEMP_SET(uint32_t val, NI_HANDLE *handle);
SCILIB int REG_HV_MVTARGET_GET(uint32_t *val, NI_HANDLE *handle);
SCILIB int REG_HV_MVTARGET_SET(uint32_t val, NI_HANDLE *handle);
SCILIB int REG_HV_MAVTARGET_GET(uint32_t *val, NI_HANDLE *handle);
SCILIB int REG_HV_MAVTARGET_SET(uint32_t val, NI_HANDLE *handle);
SCILIB int REG_T_SENS1_GET(uint32_t *val, NI_HANDLE *handle);
SCILIB int REG_T_SENS1_SET(uint32_t val, NI_HANDLE *handle);
SCILIB int REG_T_SENS2_GET(uint32_t *val, NI_HANDLE *handle);
SCILIB int REG_T_SENS2_SET(uint32_t val, NI_HANDLE *handle);
SCILIB int REG_HV_MIOUT_GET(uint32_t *val, NI_HANDLE *handle);
SCILIB int REG_HV_MIOUT_SET(uint32_t val, NI_HANDLE *handle);
SCILIB int REG_TRIGGER_OUT_W_GET(uint32_t *val, NI_HANDLE *handle);
SCILIB int REG_TRIGGER_OUT_W_SET(uint32_t val, NI_HANDLE *handle);
SCILIB int REG_T0SW_GET(uint32_t *val, NI_HANDLE *handle);
SCILIB int REG_T0SW_SET(uint32_t val, NI_HANDLE *handle);
SCILIB int REG_GTS_RESSEL_GET(uint32_t *val, NI_HANDLE *handle);
SCILIB int REG_GTS_RESSEL_SET(uint32_t val, NI_HANDLE *handle);
SCILIB int REG_TRIG_MASK_A_GET(uint32_t *val, NI_HANDLE *handle);
SCILIB int REG_TRIG_MASK_A_SET(uint32_t val, NI_HANDLE *handle);
SCILIB int REG_TRIG_MASK_B_GET(uint32_t *val, NI_HANDLE *handle);
SCILIB int REG_TRIG_MASK_B_SET(uint32_t val, NI_HANDLE *handle);
SCILIB int REG_TRIG_MASK_C_GET(uint32_t *val, NI_HANDLE *handle);
SCILIB int REG_TRIG_MASK_C_SET(uint32_t val, NI_HANDLE *handle);
SCILIB int REG_TRIG_MASK_D_GET(uint32_t *val, NI_HANDLE *handle);
SCILIB int REG_TRIG_MASK_D_SET(uint32_t val, NI_HANDLE *handle);
SCILIB int REG_T0_RESET_ON_START_GET(uint32_t *val, NI_HANDLE *handle);
SCILIB int REG_T0_RESET_ON_START_SET(uint32_t val, NI_HANDLE *handle);
SCILIB int REG_ISRUNNING_GET(uint32_t *val, NI_HANDLE *handle);
SCILIB int REG_ISRUNNING_SET(uint32_t val, NI_HANDLE *handle);
SCILIB int REG_VETO_WAIT_RUN_GET(uint32_t *val, NI_HANDLE *handle);
SCILIB int REG_VETO_WAIT_RUN_SET(uint32_t val, NI_HANDLE *handle);
SCILIB int REG_GBL_EN_VETO_EXT_GET(uint32_t *val, NI_HANDLE *handle);
SCILIB int REG_GBL_EN_VETO_EXT_SET(uint32_t val, NI_HANDLE *handle);
SCILIB int REG_INVETO_GET(uint32_t *val, NI_HANDLE *handle);
SCILIB int REG_INVETO_SET(uint32_t val, NI_HANDLE *handle);
SCILIB int REG_TRG_OUT_MONOSTABLE_EN_GET(uint32_t *val, NI_HANDLE *handle);
SCILIB int REG_TRG_OUT_MONOSTABLE_EN_SET(uint32_t val, NI_HANDLE *handle);
//-----------------------------------------------------------------
//-
//- Citiroc_CitirocCfg0_CONFIG
//-
//- Configure ASIC.
//-
//- ARGUMENTS:
//- 	           incfg   PARAM_IN    int32_t
//- 		Bitstream to be downloaded to the ASIC. Use integrated SciCompiler Tool to generate the bitstream or read Citiroc documentation
//- 		DEFAULT: 
//- 		OPTIONAL: False
//-
//- 	          handle PARAM_INOUT  NI_HANDLE
//- 		Connection handle to the board
//- 		DEFAULT: 
//- 		OPTIONAL: False
//-
//-
//- RETURN [int]
//- 	Return if the function has been succesfully executed
//- 		0) Success
//- 		-1) Error
//-
//-----------------------------------------------------------------

SCILIB int Citiroc_CitirocCfg0_CONFIG(char *incfg, NI_HANDLE *handle);
//-----------------------------------------------------------------
//-
//- Citiroc_CitirocCfg0_CONFIG_MON
//-
//- Configure ASIC Monitor probe.
//-
//- ARGUMENTS:
//- 	           incfg   PARAM_IN    int32_t
//- 		Bitstream to be downloaded to the ASIC. Use integrated SciCompiler Tool to generate the bitstream or read Citiroc documentation
//- 		DEFAULT: 
//- 		OPTIONAL: False
//-
//- 	          handle PARAM_INOUT  NI_HANDLE
//- 		Connection handle to the board
//- 		DEFAULT: 
//- 		OPTIONAL: False
//-
//-
//- RETURN [int]
//- 	Return if the function has been succesfully executed
//- 		0) Success
//- 		-1) Error
//-
//-----------------------------------------------------------------

SCILIB int Citiroc_CitirocCfg0_CONFIG_MON(char *incfg, NI_HANDLE *handle);
//-----------------------------------------------------------------
//-
//- Citiroc_CitirocCfg1_CONFIG
//-
//- Configure ASIC.
//-
//- ARGUMENTS:
//- 	           incfg   PARAM_IN    int32_t
//- 		Bitstream to be downloaded to the ASIC. Use integrated SciCompiler Tool to generate the bitstream or read Citiroc documentation
//- 		DEFAULT: 
//- 		OPTIONAL: False
//-
//- 	          handle PARAM_INOUT  NI_HANDLE
//- 		Connection handle to the board
//- 		DEFAULT: 
//- 		OPTIONAL: False
//-
//-
//- RETURN [int]
//- 	Return if the function has been succesfully executed
//- 		0) Success
//- 		-1) Error
//-
//-----------------------------------------------------------------

SCILIB int Citiroc_CitirocCfg1_CONFIG(char *incfg, NI_HANDLE *handle);
//-----------------------------------------------------------------
//-
//- Citiroc_CitirocCfg1_CONFIG_MON
//-
//- Configure ASIC Monitor probe.
//-
//- ARGUMENTS:
//- 	           incfg   PARAM_IN    int32_t
//- 		Bitstream to be downloaded to the ASIC. Use integrated SciCompiler Tool to generate the bitstream or read Citiroc documentation
//- 		DEFAULT: 
//- 		OPTIONAL: False
//-
//- 	          handle PARAM_INOUT  NI_HANDLE
//- 		Connection handle to the board
//- 		DEFAULT: 
//- 		OPTIONAL: False
//-
//-
//- RETURN [int]
//- 	Return if the function has been succesfully executed
//- 		0) Success
//- 		-1) Error
//-
//-----------------------------------------------------------------

SCILIB int Citiroc_CitirocCfg1_CONFIG_MON(char *incfg, NI_HANDLE *handle);
//-----------------------------------------------------------------
//-
//- Citiroc_CitirocCfg2_CONFIG
//-
//- Configure ASIC.
//-
//- ARGUMENTS:
//- 	           incfg   PARAM_IN    int32_t
//- 		Bitstream to be downloaded to the ASIC. Use integrated SciCompiler Tool to generate the bitstream or read Citiroc documentation
//- 		DEFAULT: 
//- 		OPTIONAL: False
//-
//- 	          handle PARAM_INOUT  NI_HANDLE
//- 		Connection handle to the board
//- 		DEFAULT: 
//- 		OPTIONAL: False
//-
//-
//- RETURN [int]
//- 	Return if the function has been succesfully executed
//- 		0) Success
//- 		-1) Error
//-
//-----------------------------------------------------------------

SCILIB int Citiroc_CitirocCfg2_CONFIG(char *incfg, NI_HANDLE *handle);
//-----------------------------------------------------------------
//-
//- Citiroc_CitirocCfg2_CONFIG_MON
//-
//- Configure ASIC Monitor probe.
//-
//- ARGUMENTS:
//- 	           incfg   PARAM_IN    int32_t
//- 		Bitstream to be downloaded to the ASIC. Use integrated SciCompiler Tool to generate the bitstream or read Citiroc documentation
//- 		DEFAULT: 
//- 		OPTIONAL: False
//-
//- 	          handle PARAM_INOUT  NI_HANDLE
//- 		Connection handle to the board
//- 		DEFAULT: 
//- 		OPTIONAL: False
//-
//-
//- RETURN [int]
//- 	Return if the function has been succesfully executed
//- 		0) Success
//- 		-1) Error
//-
//-----------------------------------------------------------------

SCILIB int Citiroc_CitirocCfg2_CONFIG_MON(char *incfg, NI_HANDLE *handle);
//-----------------------------------------------------------------
//-
//- Citiroc_CitirocCfg3_CONFIG
//-
//- Configure ASIC.
//-
//- ARGUMENTS:
//- 	           incfg   PARAM_IN    int32_t
//- 		Bitstream to be downloaded to the ASIC. Use integrated SciCompiler Tool to generate the bitstream or read Citiroc documentation
//- 		DEFAULT: 
//- 		OPTIONAL: False
//-
//- 	          handle PARAM_INOUT  NI_HANDLE
//- 		Connection handle to the board
//- 		DEFAULT: 
//- 		OPTIONAL: False
//-
//-
//- RETURN [int]
//- 	Return if the function has been succesfully executed
//- 		0) Success
//- 		-1) Error
//-
//-----------------------------------------------------------------

SCILIB int Citiroc_CitirocCfg3_CONFIG(char *incfg, NI_HANDLE *handle);
//-----------------------------------------------------------------
//-
//- Citiroc_CitirocCfg3_CONFIG_MON
//-
//- Configure ASIC Monitor probe.
//-
//- ARGUMENTS:
//- 	           incfg   PARAM_IN    int32_t
//- 		Bitstream to be downloaded to the ASIC. Use integrated SciCompiler Tool to generate the bitstream or read Citiroc documentation
//- 		DEFAULT: 
//- 		OPTIONAL: False
//-
//- 	          handle PARAM_INOUT  NI_HANDLE
//- 		Connection handle to the board
//- 		DEFAULT: 
//- 		OPTIONAL: False
//-
//-
//- RETURN [int]
//- 	Return if the function has been succesfully executed
//- 		0) Success
//- 		-1) Error
//-
//-----------------------------------------------------------------

SCILIB int Citiroc_CitirocCfg3_CONFIG_MON(char *incfg, NI_HANDLE *handle);
//-----------------------------------------------------------------
//-
//- CPACK_CP_0_START
//-
//- Start acquisition.
//-
//- ARGUMENTS:
//- 	          handle PARAM_INOUT  NI_HANDLE
//- 		Connection handle to the board
//- 		DEFAULT: 
//- 		OPTIONAL: False
//-
//-
//- RETURN [int]
//- 	Return if the function has been succesfully executed
//- 		0) Success
//- 		-1) Error
//-
//-----------------------------------------------------------------

SCILIB int CPACK_CP_0_START(NI_HANDLE *handle)
;
//-----------------------------------------------------------------
//-
//- CPACK_CP_0_STOP
//-
//- Start acquisition.
//-
//- ARGUMENTS:
//- 	          handle PARAM_INOUT  NI_HANDLE
//- 		Connection handle to the board
//- 		DEFAULT: 
//- 		OPTIONAL: False
//-
//-
//- RETURN [int]
//- 	Return if the function has been succesfully executed
//- 		0) Success
//- 		-1) Error
//-
//-----------------------------------------------------------------

SCILIB int CPACK_CP_0_STOP(NI_HANDLE *handle)
;
//-----------------------------------------------------------------
//-
//- CPACK_CP_0_RESET
//-
//- Reset counters and FIFO
//-
//- ARGUMENTS:
//- 	          handle PARAM_INOUT  NI_HANDLE
//- 		Connection handle to the board
//- 		DEFAULT: 
//- 		OPTIONAL: False
//-
//-
//- RETURN [int]
//- 	Return if the function has been succesfully executed
//- 		0) Success
//- 		-1) Error
//-
//-----------------------------------------------------------------

SCILIB int CPACK_CP_0_RESET(NI_HANDLE *handle);
//-----------------------------------------------------------------
//-
//- CPACK_CP_0_FLUSH
//-
//- Clear Fifo Content
//-
//- ARGUMENTS:
//- 	          handle PARAM_INOUT  NI_HANDLE
//- 		Connection handle to the board
//- 		DEFAULT: 
//- 		OPTIONAL: False
//-
//-
//- RETURN [int]
//- 	Return if the function has been succesfully executed
//- 		0) Success
//- 		-1) Error
//-
//-----------------------------------------------------------------

SCILIB int CPACK_CP_0_FLUSH(NI_HANDLE *handle);
//-----------------------------------------------------------------
//-
//- CPACK_CP_0_STATUS
//-
//- Get status
//-
//- ARGUMENTS:
//- 	          status  PARAM_OUT    int32_t
//- 		Return the status:
//- 		DEFAULT: 
//- 		OPTIONAL: False
//- 		bit[0] = 0) No data available
//- 		bit[0] = 1) Data available
//- 		bit[1] = 1) Running
//- 		bit[2] = 1) Full
//-
//- 	          handle PARAM_INOUT  NI_HANDLE
//- 		Connection handle to the board
//- 		DEFAULT: 
//- 		OPTIONAL: False
//-
//-
//- RETURN [int]
//- 	Return if the function has been succesfully executed
//- 		0) Success
//- 		-1) Error
//-
//-----------------------------------------------------------------

SCILIB int CPACK_CP_0_STATUS(uint32_t *status,NI_HANDLE *handle);
//-----------------------------------------------------------------
//-
//- CPACK_CP_0_DATA_AVAILABLE
//-
//- Return number of word available in the FIFO
//-
//- ARGUMENTS:
//- 	          status  PARAM_OUT    int32_t
//- 		Return the status (1) data available (0) no data
//- 		DEFAULT: 
//- 		OPTIONAL: False
//- 		bit[0] = 0) No data available
//- 		bit[0] = 1) Data available
//- 		bit[1] = 1) Running
//- 		bit[2] = 1) Full
//-
//- 	          handle PARAM_INOUT  NI_HANDLE
//- 		Connection handle to the board
//- 		DEFAULT: 
//- 		OPTIONAL: False
//-
//-
//- RETURN [int]
//- 	Return if the function has been succesfully executed
//- 		0) Success
//- 		-1) Error
//-
//-----------------------------------------------------------------

SCILIB int CPACK_CP_0_DATA_AVAILABLE(uint32_t *status,NI_HANDLE *handle);
//-----------------------------------------------------------------
//-
//- CPACK_CP_0_DOWNLOAD
//-
//- Download data from buffer. Data in the buffer respect the packet layout defined in the Packet Creator Tool
//- 
//- USAGE: 
//- 
//-
//- ARGUMENTS:
//- 	             val  PARAM_OUT   uint32_t
//- 		uint32_t buffer data with preallocated size of at list 'size' parameters + 16 word
//- 		DEFAULT: 
//- 		OPTIONAL: False
//-
//- 	             val   PARAM_IN       size
//- 		number of word to download from the buffer. 
//- 		DEFAULT: 
//- 		OPTIONAL: False
//-
//- 	             val   PARAM_IN    int32_t
//- 		timeout in ms
//- 		DEFAULT: 
//- 		OPTIONAL: False
//-
//- 	          handle PARAM_INOUT  NI_HANDLE
//- 		Connection handle to the board
//- 		DEFAULT: 
//- 		OPTIONAL: False
//-
//- 	       read_data  PARAM_OUT    int32_t
//- 		number of word read from the buffer
//- 		DEFAULT: 
//- 		OPTIONAL: False
//-
//- 	      valid_data  PARAM_OUT    int32_t
//- 		number of word valid in the buffer
//- 		DEFAULT: 
//- 		OPTIONAL: False
//-
//-
//- RETURN [int]
//- 	Return if the function has been succesfully executed
//- 		0) Success
//- 		-1) Error
//-
//-----------------------------------------------------------------

SCILIB int CPACK_CP_0_DOWNLOAD(uint32_t *val, uint32_t size, int32_t timeout, NI_HANDLE *handle, uint32_t *read_data, uint32_t *valid_data);
//-----------------------------------------------------------------
//-
//- CPACK_CP_0_RECONSTRUCT_DATA
//-
//- Take in input a circular buffer (buffer_handle) allocated with the function Utility_ALLOCATE_DOWNLOAD_BUFFER 
//- And filled with downloaded data Utility_ENQUEUE_DATA_IN_DOWNLOAD_BUFFER And decoded the packet  
//- created with the Image (Frame Transfer block).
//- The function internally allocate the output data structure t_FRAME_packet_collection And fill it with packed data
//- decoded. Release the memory allocated by the function with free_FRAME_packet_collectionvoid(buffer) function
//- in order to avoid memory leakage
//- ----------------------------------------
//- USAGE: 
//-   t_FRAME_packet_collection decoded_packets; 
//-   uint32_t data_frame[100000]; 
//-   void *BufferDownloadHandler = NULL;
//- 
//-   Utility_ALLOCATE_DOWNLOAD_BUFFER(&BufferDownloadHandler, 1024*1024);
//-   .... initialize frame transfer ....
//-   while (1){
//-     CPACK_CP0_DOWNLOAD(&data_frame, N_Packet * (PacketSize), timeout_frame, &handle, &read_data_frame, &valid_data_frame); 
//-     Utility_ENQUEUE_DATA_IN_DOWNLOAD_BUFFER(BufferDownloadHandler, data_frame, valid_data_frame, &valid_data_enqueued); 
//-     if (CPACK_CP_0_RECONSTRUCT_DATA(BufferDownloadHandler, &decoded_packets) == 0) { 
//-         .... process data contained in decoded_packets....
//-         free_FRAME_packet_collectionvoid(&decoded_packets);
//-     }
//- 
//- 
//- 
//- 
//- THIS FUNCTION MUST BE CONFIGURED IN FUNCTION OF THE PACKET LAYOUT DEFINED IN THE TOOL!
//- 
//- 
//- 
//- This Is just the skeleton for the decoded function!
//- In the state 3 of the thate machine in the code the packet decoder extract every line from the packet
//- for example if the payload of your packet Is 8 channels of 16 bits alligned 2 channels per row
//- 1:   0xFFFFFFFF      %%HEADER                            Decoded in state 0
//- 2:   0xtttttttt      %%TIMECODE                          Decoded in state 1
//- 3:   0xpppppppp      %%PACKET COUNTER                    Decoded in state 2
//- 4:   IN1    IN2      %%16 BIT DATA * 2 Channels          Decoded in state 3
//- 5:   IN3    IN4      %%16 BIT DATA * 2 Channels          Decoded in state 3
//- 6:   IN5    IN6      %%16 BIT DATA * 2 Channels          Decoded in state 3
//- 7:   IN7    IN7      %%16 BIT DATA * 2 Channels          Decoded in state 3
//- <<<NUMBER OF PACKET LINES AFTER THE HEADER HERE>>> must be set to 4 (the line containing the payload 4...7)
//- You can change the state machine in an arbitrary way in order to correctly decode packets and extract every single channels
//- This function example works as is for the following packet format
//- 1:   0xFFFFFFFF      %%HEADER                            Decoded in state 0
//- 2:   0xtttttttt      %%TIMECODE                          Decoded in state 1
//- 3:   0xpppppppp      %%PACKET COUNTER                    Decoded in state 2
//- 4:   IN1             %%32 BIT DATA                       Decoded in state 3
//- 5:   IN2             %%32 BIT DATA                       Decoded in state 3
//- 6:   IN3             %%32 BIT DATA                       Decoded in state 3
//- 7:   IN4             %%32 BIT DATA                       Decoded in state 3
//- 
//-
//- ARGUMENTS:
//- 	   buffer_handle   PARAM_IN       void
//- 		void pointer to the allocated memory area
//- 		DEFAULT: 
//- 		OPTIONAL: False
//-
//- 	 decoded_packets  PARAM_OUT t_FRAME_packet_collection
//- 		Output vector containing the decoded data
//- 		DEFAULT: 
//- 		OPTIONAL: False
//-
//-
//- RETURN [int]
//- 	Return if the function has been succesfully executed
//- 		0) Success
//- 		-1) Error
//-
//-----------------------------------------------------------------

SCILIB int CPACK_CP_0_RECONSTRUCT_DATA(void *buffer_handle, t_generic_event_collection *decoded_packets);
//-----------------------------------------------------------------
//-
//- CitirocFRAME_CitirocFrame0_GetStatus
//-
//- Get status
//-
//- ARGUMENTS:
//- 	is_data_available  PARAM_OUT    int32_t
//- 		Return the component status
//- 		DEFAULT: 
//- 		OPTIONAL: False
//- 		0) No data available
//- 		1) Data available
//-
//- 	  word_available  PARAM_OUT    int32_t
//- 		Number of word available in the FIFO
//- 		DEFAULT: 
//- 		OPTIONAL: False
//-
//- 	          handle PARAM_INOUT  NI_HANDLE
//- 		Connection handle to the board
//- 		DEFAULT: 
//- 		OPTIONAL: False
//-
//-
//- RETURN [int]
//- 	Return if the function has been succesfully executed
//- 		0) Success
//- 		-1) Error
//-
//-----------------------------------------------------------------

SCILIB int CitirocFRAME_CitirocFrame0_GetStatus(uint32_t *is_data_available, uint32_t *word_available, NI_HANDLE *handle);
//-----------------------------------------------------------------
//-
//- CitirocFRAME_CitirocFrame0_RESET
//-
//- Reset FIFO content.
//-
//- ARGUMENTS:
//- 	          handle PARAM_INOUT  NI_HANDLE
//- 		Connection handle to the board
//- 		DEFAULT: 
//- 		OPTIONAL: False
//-
//-
//- RETURN [int]
//- 	Return if the function has been succesfully executed
//- 		0) Success
//- 		-1) Error
//-
//-----------------------------------------------------------------

SCILIB int CitirocFRAME_CitirocFrame0_RESET(NI_HANDLE *handle);
//-----------------------------------------------------------------
//-
//- CitirocFRAME_CitirocFrame0_START
//-
//- Reset FIFO content.
//-
//- ARGUMENTS:
//- 	          handle PARAM_INOUT  NI_HANDLE
//- 		Connection handle to the board
//- 		DEFAULT: 
//- 		OPTIONAL: False
//-
//-
//- RETURN [int]
//- 	Return if the function has been succesfully executed
//- 		0) Success
//- 		-1) Error
//-
//-----------------------------------------------------------------

SCILIB int CitirocFRAME_CitirocFrame0_START(NI_HANDLE *handle);
//-----------------------------------------------------------------
//-
//- CitirocFRAME_CitirocFrame0_DOWNLOAD
//-
//- Download data from buffer. 
//- 
//- USAGE: 
//- 
//-
//- ARGUMENTS:
//- 	             val  PARAM_OUT   uint32_t
//- 		uint32_t buffer data with preallocated size of at list 'size' parameters + 16 word
//- 		DEFAULT: 
//- 		OPTIONAL: False
//-
//- 	             val   PARAM_IN       size
//- 		number of word to download from the buffer. 
//- 		DEFAULT: 
//- 		OPTIONAL: False
//-
//- 	             val   PARAM_IN    int32_t
//- 		timeout in ms
//- 		DEFAULT: 
//- 		OPTIONAL: False
//-
//- 	          handle PARAM_INOUT  NI_HANDLE
//- 		Connection handle to the board
//- 		DEFAULT: 
//- 		OPTIONAL: False
//-
//- 	       read_data  PARAM_OUT    int32_t
//- 		number of word read from the buffer
//- 		DEFAULT: 
//- 		OPTIONAL: False
//-
//- 	      valid_data  PARAM_OUT    int32_t
//- 		number of word valid in the buffer
//- 		DEFAULT: 
//- 		OPTIONAL: False
//-
//-
//- RETURN [int]
//- 	Return if the function has been succesfully executed
//- 		0) Success
//- 		-1) Error
//-
//-----------------------------------------------------------------

SCILIB int CitirocFRAME_CitirocFrame0_DOWNLOAD(uint32_t *val, uint32_t size, int32_t timeout, NI_HANDLE *handle, uint32_t *read_data, uint32_t *valid_data);
//-----------------------------------------------------------------
//-
//- CitirocFRAME_CitirocFrame0_RECONSTRUCT_DATA
//-
//- Take in input a circular buffer (buffer_handle) allocated with the function Utility_ALLOCATE_DOWNLOAD_BUFFER 
//- and filled with downloaded data Utility_ENQUEUE_DATA_IN_DOWNLOAD_BUFFER and decoded the packet  
//- created with the Image (Frame Transfer block).
//- The function internally allocate the output data structure t_ASIC_packet_collection and fill it with packed data
//- decoded. Release the memory allocated by the function with free_CitirocFRAME_packet_collection(buffer) function
//- in order to avoid memory leakage
//- ----------------------------------------
//- USAGE: 
//-   t_FRAME_packet_collection decoded_packets; 
//-   uint32_t data_frame[100000]; 
//-   void *BufferDownloadHandler = NULL;
//- 
//-   Utility_ALLOCATE_DOWNLOAD_BUFFER(&BufferDownloadHandler, 1024*1024);
//-   .... initialize frame transfer ....
//-   while (1){
//-     CitirocFRAME_CitirocFrame0_DOWNLOAD(&data_frame, N_Packet * (PacketSize), timeout_frame, &handle, &read_data_frame, &valid_data_frame); 
//-     Utility_ENQUEUE_DATA_IN_DOWNLOAD_BUFFER(BufferDownloadHandler, data_frame, valid_data_frame, &valid_data_enqueued); 
//-     if (CitirocFRAME_CitirocFrame0_RECONSTRUCT_DATA(BufferDownloadHandler, &decoded_packets) == 0) { 
//-         .... process data contained in decoded_packets....
//-         free_FRAME_packet_collectionvoid(&decoded_packets);
//-     }
//- 
//- 
//-
//- ARGUMENTS:
//- 	   buffer_handle   PARAM_IN       void
//- 		void pointer to the allocated memory area
//- 		DEFAULT: 
//- 		OPTIONAL: False
//-
//- 	 decoded_packets  PARAM_OUT t_FRAME_packet_collection
//- 		Output vector containing the decoded data
//- 		DEFAULT: 
//- 		OPTIONAL: False
//-
//-
//- RETURN [int]
//- 	Return if the function has been succesfully executed
//- 		0) Success
//- 		-1) Error
//-
//-----------------------------------------------------------------

SCILIB int CitirocFRAME_CitirocFrame0_RECONSTRUCT_DATA(void *buffer_handle, t_ASIC_packet_collection *decoded_packets);
//-----------------------------------------------------------------
//-
//- RATE_METER_RateMeter_1_GET_DATA
//-
//- USAGE: 
//- 
//-
//- ARGUMENTS:
//- 	             val  PARAM_OUT   uint32_t
//- 		uint32_t buffer data with preallocated size of at list 'size' parameters + 16 word
//- 		DEFAULT: 
//- 		OPTIONAL: False
//-
//- 	             val   PARAM_IN   channels
//- 		number of word to download from the buffer.
//- 		DEFAULT: 
//- 		OPTIONAL: False
//-
//- 	             val   PARAM_IN    int32_t
//- 		timeout in ms
//- 		DEFAULT: 
//- 		OPTIONAL: False
//-
//- 	          handle PARAM_INOUT  NI_HANDLE
//- 		Connection handle to the board
//- 		DEFAULT: 
//- 		OPTIONAL: False
//-
//- 	       read_data  PARAM_OUT    int32_t
//- 		number of word read from the buffer
//- 		DEFAULT: 
//- 		OPTIONAL: False
//-
//- 	      valid_data  PARAM_OUT    int32_t
//- 		number of word valid in the buffer
//- 		DEFAULT: 
//- 		OPTIONAL: False
//-
//-
//- RETURN [int]
//- 	Return if the function has been succesfully executed
//- 		0) Success
//- 		-1) Error
//-
//-----------------------------------------------------------------

SCILIB int RATE_METER_RateMeter_1_GET_DATA(uint32_t *val, uint32_t channels, int32_t timeout, NI_HANDLE *handle, uint32_t *read_data, uint32_t *valid_data);
//-----------------------------------------------------------------
//-
//- RATE_METER_RateMeter_1_GET_DATA_COUNTS
//-
//- USAGE: 
//- 
//-
//- ARGUMENTS:
//- 	             val  PARAM_OUT   uint32_t
//- 		uint32_t buffer data with preallocated size of at list 'size' parameters + 16 word
//- 		DEFAULT: 
//- 		OPTIONAL: False
//-
//- 	             val   PARAM_IN   channels
//- 		number of word to download from the buffer.
//- 		DEFAULT: 
//- 		OPTIONAL: False
//-
//- 	             val   PARAM_IN    int32_t
//- 		timeout in ms
//- 		DEFAULT: 
//- 		OPTIONAL: False
//-
//- 	          handle PARAM_INOUT  NI_HANDLE
//- 		Connection handle to the board
//- 		DEFAULT: 
//- 		OPTIONAL: False
//-
//- 	       read_data  PARAM_OUT    int32_t
//- 		number of word read from the buffer
//- 		DEFAULT: 
//- 		OPTIONAL: False
//-
//- 	      valid_data  PARAM_OUT    int32_t
//- 		number of word valid in the buffer
//- 		DEFAULT: 
//- 		OPTIONAL: False
//-
//-
//- RETURN [int]
//- 	Return if the function has been succesfully executed
//- 		0) Success
//- 		-1) Error
//-
//-----------------------------------------------------------------

SCILIB int RATE_METER_RateMeter_1_GET_DATA_COUNTS(uint32_t *val, uint32_t channels, int32_t timeout, NI_HANDLE *handle, uint32_t *read_data, uint32_t *valid_data);
//-----------------------------------------------------------------
//-
//- RATE_METER_RateMeter_0_GET_DATA
//-
//- USAGE: 
//- 
//-
//- ARGUMENTS:
//- 	             val  PARAM_OUT   uint32_t
//- 		uint32_t buffer data with preallocated size of at list 'size' parameters + 16 word
//- 		DEFAULT: 
//- 		OPTIONAL: False
//-
//- 	             val   PARAM_IN   channels
//- 		number of word to download from the buffer.
//- 		DEFAULT: 
//- 		OPTIONAL: False
//-
//- 	             val   PARAM_IN    int32_t
//- 		timeout in ms
//- 		DEFAULT: 
//- 		OPTIONAL: False
//-
//- 	          handle PARAM_INOUT  NI_HANDLE
//- 		Connection handle to the board
//- 		DEFAULT: 
//- 		OPTIONAL: False
//-
//- 	       read_data  PARAM_OUT    int32_t
//- 		number of word read from the buffer
//- 		DEFAULT: 
//- 		OPTIONAL: False
//-
//- 	      valid_data  PARAM_OUT    int32_t
//- 		number of word valid in the buffer
//- 		DEFAULT: 
//- 		OPTIONAL: False
//-
//-
//- RETURN [int]
//- 	Return if the function has been succesfully executed
//- 		0) Success
//- 		-1) Error
//-
//-----------------------------------------------------------------

SCILIB int RATE_METER_RateMeter_0_GET_DATA(uint32_t *val, uint32_t channels, int32_t timeout, NI_HANDLE *handle, uint32_t *read_data, uint32_t *valid_data);
//-----------------------------------------------------------------
//-
//- RATE_METER_RateMeter_0_GET_DATA_COUNTS
//-
//- USAGE: 
//- 
//-
//- ARGUMENTS:
//- 	             val  PARAM_OUT   uint32_t
//- 		uint32_t buffer data with preallocated size of at list 'size' parameters + 16 word
//- 		DEFAULT: 
//- 		OPTIONAL: False
//-
//- 	             val   PARAM_IN   channels
//- 		number of word to download from the buffer.
//- 		DEFAULT: 
//- 		OPTIONAL: False
//-
//- 	             val   PARAM_IN    int32_t
//- 		timeout in ms
//- 		DEFAULT: 
//- 		OPTIONAL: False
//-
//- 	          handle PARAM_INOUT  NI_HANDLE
//- 		Connection handle to the board
//- 		DEFAULT: 
//- 		OPTIONAL: False
//-
//- 	       read_data  PARAM_OUT    int32_t
//- 		number of word read from the buffer
//- 		DEFAULT: 
//- 		OPTIONAL: False
//-
//- 	      valid_data  PARAM_OUT    int32_t
//- 		number of word valid in the buffer
//- 		DEFAULT: 
//- 		OPTIONAL: False
//-
//-
//- RETURN [int]
//- 	Return if the function has been succesfully executed
//- 		0) Success
//- 		-1) Error
//-
//-----------------------------------------------------------------

SCILIB int RATE_METER_RateMeter_0_GET_DATA_COUNTS(uint32_t *val, uint32_t channels, int32_t timeout, NI_HANDLE *handle, uint32_t *read_data, uint32_t *valid_data);
//-----------------------------------------------------------------
//-
//- RATE_METER_RateMeter_2_GET_DATA
//-
//- USAGE: 
//- 
//-
//- ARGUMENTS:
//- 	             val  PARAM_OUT   uint32_t
//- 		uint32_t buffer data with preallocated size of at list 'size' parameters + 16 word
//- 		DEFAULT: 
//- 		OPTIONAL: False
//-
//- 	             val   PARAM_IN   channels
//- 		number of word to download from the buffer.
//- 		DEFAULT: 
//- 		OPTIONAL: False
//-
//- 	             val   PARAM_IN    int32_t
//- 		timeout in ms
//- 		DEFAULT: 
//- 		OPTIONAL: False
//-
//- 	          handle PARAM_INOUT  NI_HANDLE
//- 		Connection handle to the board
//- 		DEFAULT: 
//- 		OPTIONAL: False
//-
//- 	       read_data  PARAM_OUT    int32_t
//- 		number of word read from the buffer
//- 		DEFAULT: 
//- 		OPTIONAL: False
//-
//- 	      valid_data  PARAM_OUT    int32_t
//- 		number of word valid in the buffer
//- 		DEFAULT: 
//- 		OPTIONAL: False
//-
//-
//- RETURN [int]
//- 	Return if the function has been succesfully executed
//- 		0) Success
//- 		-1) Error
//-
//-----------------------------------------------------------------

SCILIB int RATE_METER_RateMeter_2_GET_DATA(uint32_t *val, uint32_t channels, int32_t timeout, NI_HANDLE *handle, uint32_t *read_data, uint32_t *valid_data);
//-----------------------------------------------------------------
//-
//- RATE_METER_RateMeter_2_GET_DATA_COUNTS
//-
//- USAGE: 
//- 
//-
//- ARGUMENTS:
//- 	             val  PARAM_OUT   uint32_t
//- 		uint32_t buffer data with preallocated size of at list 'size' parameters + 16 word
//- 		DEFAULT: 
//- 		OPTIONAL: False
//-
//- 	             val   PARAM_IN   channels
//- 		number of word to download from the buffer.
//- 		DEFAULT: 
//- 		OPTIONAL: False
//-
//- 	             val   PARAM_IN    int32_t
//- 		timeout in ms
//- 		DEFAULT: 
//- 		OPTIONAL: False
//-
//- 	          handle PARAM_INOUT  NI_HANDLE
//- 		Connection handle to the board
//- 		DEFAULT: 
//- 		OPTIONAL: False
//-
//- 	       read_data  PARAM_OUT    int32_t
//- 		number of word read from the buffer
//- 		DEFAULT: 
//- 		OPTIONAL: False
//-
//- 	      valid_data  PARAM_OUT    int32_t
//- 		number of word valid in the buffer
//- 		DEFAULT: 
//- 		OPTIONAL: False
//-
//-
//- RETURN [int]
//- 	Return if the function has been succesfully executed
//- 		0) Success
//- 		-1) Error
//-
//-----------------------------------------------------------------

SCILIB int RATE_METER_RateMeter_2_GET_DATA_COUNTS(uint32_t *val, uint32_t channels, int32_t timeout, NI_HANDLE *handle, uint32_t *read_data, uint32_t *valid_data);
//-----------------------------------------------------------------
//-
//- RATE_METER_RateMeter_3_GET_DATA
//-
//- USAGE: 
//- 
//-
//- ARGUMENTS:
//- 	             val  PARAM_OUT   uint32_t
//- 		uint32_t buffer data with preallocated size of at list 'size' parameters + 16 word
//- 		DEFAULT: 
//- 		OPTIONAL: False
//-
//- 	             val   PARAM_IN   channels
//- 		number of word to download from the buffer.
//- 		DEFAULT: 
//- 		OPTIONAL: False
//-
//- 	             val   PARAM_IN    int32_t
//- 		timeout in ms
//- 		DEFAULT: 
//- 		OPTIONAL: False
//-
//- 	          handle PARAM_INOUT  NI_HANDLE
//- 		Connection handle to the board
//- 		DEFAULT: 
//- 		OPTIONAL: False
//-
//- 	       read_data  PARAM_OUT    int32_t
//- 		number of word read from the buffer
//- 		DEFAULT: 
//- 		OPTIONAL: False
//-
//- 	      valid_data  PARAM_OUT    int32_t
//- 		number of word valid in the buffer
//- 		DEFAULT: 
//- 		OPTIONAL: False
//-
//-
//- RETURN [int]
//- 	Return if the function has been succesfully executed
//- 		0) Success
//- 		-1) Error
//-
//-----------------------------------------------------------------

SCILIB int RATE_METER_RateMeter_3_GET_DATA(uint32_t *val, uint32_t channels, int32_t timeout, NI_HANDLE *handle, uint32_t *read_data, uint32_t *valid_data);
//-----------------------------------------------------------------
//-
//- RATE_METER_RateMeter_3_GET_DATA_COUNTS
//-
//- USAGE: 
//- 
//-
//- ARGUMENTS:
//- 	             val  PARAM_OUT   uint32_t
//- 		uint32_t buffer data with preallocated size of at list 'size' parameters + 16 word
//- 		DEFAULT: 
//- 		OPTIONAL: False
//-
//- 	             val   PARAM_IN   channels
//- 		number of word to download from the buffer.
//- 		DEFAULT: 
//- 		OPTIONAL: False
//-
//- 	             val   PARAM_IN    int32_t
//- 		timeout in ms
//- 		DEFAULT: 
//- 		OPTIONAL: False
//-
//- 	          handle PARAM_INOUT  NI_HANDLE
//- 		Connection handle to the board
//- 		DEFAULT: 
//- 		OPTIONAL: False
//-
//- 	       read_data  PARAM_OUT    int32_t
//- 		number of word read from the buffer
//- 		DEFAULT: 
//- 		OPTIONAL: False
//-
//- 	      valid_data  PARAM_OUT    int32_t
//- 		number of word valid in the buffer
//- 		DEFAULT: 
//- 		OPTIONAL: False
//-
//-
//- RETURN [int]
//- 	Return if the function has been succesfully executed
//- 		0) Success
//- 		-1) Error
//-
//-----------------------------------------------------------------

SCILIB int RATE_METER_RateMeter_3_GET_DATA_COUNTS(uint32_t *val, uint32_t channels, int32_t timeout, NI_HANDLE *handle, uint32_t *read_data, uint32_t *valid_data);
//-----------------------------------------------------------------
//-
//- OSCILLOSCOPE_Oscilloscope_0_START
//-
//- Start Oscilloscope acquisition.
//-
//- ARGUMENTS:
//- 	          handle PARAM_INOUT  NI_HANDLE
//- 		Connection handle to the board
//- 		DEFAULT: 
//- 		OPTIONAL: False
//-
//-
//- RETURN [int]
//- 	Return if the function has been succesfully executed
//- 		0) Success
//- 		-1) Error
//-
//-----------------------------------------------------------------

SCILIB int OSCILLOSCOPE_Oscilloscope_0_START(NI_HANDLE *handle)
;
//-----------------------------------------------------------------
//-
//- OSCILLOSCOPE_Oscilloscope_0_SET_PARAMETERS
//-
//- Configure oscilloscope parameters
//-
//- ARGUMENTS:
//- 	       decimator   PARAM_IN    int32_t
//- 		Set decimator value. 0: no decimation, 1: divide by two, ...
//- 		DEFAULT: 
//- 		OPTIONAL: False
//-
//- 	             pre   PARAM_IN    int32_t
//- 		Set the length in samples of pre-trigger buffer
//- 		DEFAULT: 
//- 		OPTIONAL: False
//-
//- 	software_trigger   PARAM_IN    int32_t
//- 		Generate software trigger to force start acquisition (1:generate trigger)
//- 		DEFAULT: 
//- 		OPTIONAL: False
//-
//- 	  analog_trigger   PARAM_IN    int32_t
//- 		Enable threshold trigger on analog input of selected channel
//- 		DEFAULT: 
//- 		OPTIONAL: False
//- 		0) Disable
//- 		1) Enable
//-
//- 	digital0_trigger   PARAM_IN    int32_t
//- 		Enable digital trigger on digital in 0 of selected channel
//- 		DEFAULT: 
//- 		OPTIONAL: False
//- 		0) Disable
//- 		1) Enable
//-
//- 	digital1_trigger   PARAM_IN    int32_t
//- 		Enable digital trigger on digital in 1 of selected channel
//- 		DEFAULT: 
//- 		OPTIONAL: False
//- 		0) Disable
//- 		1) Enable
//-
//- 	digital2_trigger   PARAM_IN    int32_t
//- 		Enable digital trigger on digital in 2 of selected channel
//- 		DEFAULT: 
//- 		OPTIONAL: False
//- 		0) Disable
//- 		1) Enable
//-
//- 	digital3_trigger   PARAM_IN    int32_t
//- 		Enable digital trigger on digital in 3 of selected channel
//- 		DEFAULT: 
//- 		OPTIONAL: False
//- 		0) Disable
//- 		1) Enable
//-
//- 	 trigger_channel   PARAM_IN    int32_t
//- 		Select channel of the oscilloscope connected to the trigger logic
//- 		DEFAULT: 
//- 		OPTIONAL: False
//-
//- 	    trigger_edge   PARAM_IN    int32_t
//- 		Select channel of the oscilloscope connected to the trigger logic
//- 		DEFAULT: 
//- 		OPTIONAL: False
//- 		0) Rising
//- 		1) Falling
//-
//- 	   trigger_level   PARAM_IN    int32_t
//- 		Level in LSB of the leading edge comparator on analog input. Use only with analog_trigger=1
//- 		DEFAULT: 
//- 		OPTIONAL: False
//-
//- 	          handle PARAM_INOUT  NI_HANDLE
//- 		Connection handle to the board
//- 		DEFAULT: 
//- 		OPTIONAL: False
//-
//-
//- RETURN [int]
//- 	Return if the function has been succesfully executed
//- 		0) Success
//- 		-1) Error
//-
//-----------------------------------------------------------------

SCILIB int OSCILLOSCOPE_Oscilloscope_0_SET_PARAMETERS(int32_t decimator, int32_t pre, int32_t software_trigger, int32_t analog_trigger, int32_t digital0_trigger, int32_t digital1_trigger, int32_t digital2_trigger, int32_t digital3_trigger, int32_t trigger_channel, int32_t trigger_edge, int32_t trigger_level, NI_HANDLE *handle);
//-----------------------------------------------------------------
//-
//- OSCILLOSCOPE_Oscilloscope_0_STATUS
//-
//- Get Oscilloscope status
//-
//- ARGUMENTS:
//- 	          status  PARAM_OUT    int32_t
//- 		Return the oscilloscope status
//- 		DEFAULT: 
//- 		OPTIONAL: False
//- 		0) No data available
//- 		1) Data available
//-
//- 	          handle PARAM_INOUT  NI_HANDLE
//- 		Connection handle to the board
//- 		DEFAULT: 
//- 		OPTIONAL: False
//-
//-
//- RETURN [int]
//- 	Return if the function has been succesfully executed
//- 		0) Success
//- 		-1) Error
//-
//-----------------------------------------------------------------

SCILIB int OSCILLOSCOPE_Oscilloscope_0_STATUS(uint32_t *status,NI_HANDLE *handle);
//-----------------------------------------------------------------
//-
//- OSCILLOSCOPE_Oscilloscope_0_POSITION
//-
//- Get Oscilloscope trigger position. The trigger position indicate the position in the output buffer of each channels where the sample at t0 occureed. PRE-TRIGGER samples before t0 is the pre-trigger data.
//-
//- ARGUMENTS:
//- 	        position  PARAM_OUT    int32_t
//- 		Return the trigger position in the data set in order to correct recustruct the pre-prigger and post trigger data
//- 		DEFAULT: 
//- 		OPTIONAL: False
//-
//- 	          handle PARAM_INOUT  NI_HANDLE
//- 		Connection handle to the board
//- 		DEFAULT: 
//- 		OPTIONAL: False
//-
//-
//- RETURN [int]
//- 	Return if the function has been succesfully executed
//- 		0) Success
//- 		-1) Error
//-
//-----------------------------------------------------------------

SCILIB int OSCILLOSCOPE_Oscilloscope_0_POSITION(int32_t *position,NI_HANDLE *handle);
//-----------------------------------------------------------------
//-
//- OSCILLOSCOPE_Oscilloscope_0_DOWNLOAD
//-
//- Download data from oscilloscope buffer. Please note that downloaded data is not time ordered and the trigger position info data must be obtained using the OSCILLOSCOPE_Oscilloscope_0POSITION function 
//- 
//- USAGE: 
//-     OSCILLOSCOPE_Oscilloscope_0_DOWNLOAD(data_buffer, BUFFER_SIZE_Oscilloscope_0, 1000, handle, rd, vp);
//- 
//-
//- ARGUMENTS:
//- 	             val  PARAM_OUT   uint32_t
//- 		uint32_t buffer data with preallocated size of at list 'size' parameters + 16 word
//- 		DEFAULT: 
//- 		OPTIONAL: False
//-
//- 	             val   PARAM_IN       size
//- 		number of word to download from the buffer. Use macro BUFFER_SIZE_Oscilloscope_0 to get actual oscilloscope buffer size on FPGA
//- 		DEFAULT: 
//- 		OPTIONAL: False
//-
//- 	             val   PARAM_IN    int32_t
//- 		timeout in ms
//- 		DEFAULT: 
//- 		OPTIONAL: False
//-
//- 	          handle PARAM_INOUT  NI_HANDLE
//- 		Connection handle to the board
//- 		DEFAULT: 
//- 		OPTIONAL: False
//-
//- 	       read_data  PARAM_OUT    int32_t
//- 		number of word read from the buffer
//- 		DEFAULT: 
//- 		OPTIONAL: False
//-
//- 	      valid_data  PARAM_OUT    int32_t
//- 		number of word valid in the buffer
//- 		DEFAULT: 
//- 		OPTIONAL: False
//-
//-
//- RETURN [int]
//- 	Return if the function has been succesfully executed
//- 		0) Success
//- 		-1) Error
//-
//-----------------------------------------------------------------

SCILIB int OSCILLOSCOPE_Oscilloscope_0_DOWNLOAD(uint32_t *val, uint32_t size, int32_t timeout, NI_HANDLE *handle, uint32_t *read_data, uint32_t *valid_data);
//-----------------------------------------------------------------
//-
//- OSCILLOSCOPE_Oscilloscope_0_RECONSTRUCT
//-
//- Take as input the downloaded buffer and decode the the different track for each channels. Channel order is the following: [0...1023] Channel 1, [1024...2047] Channel2
//- 
//- 
//-
//- ARGUMENTS:
//- 	        data_osc   PARAM_IN   uint32_t
//- 		uint32_t buffer containing the raw data download with the DOWNLOAD function
//- 		DEFAULT: 
//- 		OPTIONAL: False
//-
//- 	        position   PARAM_IN   uint32_t
//- 		Position of the trigger obtained with the POSITION function
//- 		DEFAULT: 
//- 		OPTIONAL: False
//-
//- 	     pre_trigger   PARAM_IN    int32_t
//- 		Length of the pre-trigger
//- 		DEFAULT: 
//- 		OPTIONAL: False
//-
//- 	     read_analog  PARAM_OUT   uint32_t
//- 		Analog track reordered in time. Data are encoded in unsigned data format between -32576 and 32576
//- 		DEFAULT: 
//- 		OPTIONAL: False
//-
//- 	   read_digital0  PARAM_OUT   uint32_t
//- 		Digital track 0 reordered
//- 		DEFAULT: 
//- 		OPTIONAL: False
//-
//- 	   read_digital1  PARAM_OUT   uint32_t
//- 		Digital track 1 reordered
//- 		DEFAULT: 
//- 		OPTIONAL: False
//-
//- 	   read_digital2  PARAM_OUT   uint32_t
//- 		Digital track 2 reordered
//- 		DEFAULT: 
//- 		OPTIONAL: False
//-
//- 	   read_digital3  PARAM_OUT   uint32_t
//- 		Digital track 3 reordered
//- 		DEFAULT: 
//- 		OPTIONAL: False
//-
//-
//- RETURN [int]
//- 	Return if the function has been succesfully executed
//- 		0) Success
//- 		-1) Error
//-
//-----------------------------------------------------------------

SCILIB int OSCILLOSCOPE_Oscilloscope_0_RECONSTRUCT(uint32_t *data_osc, uint32_t position, int32_t pre_trigger, uint32_t *read_analog, uint32_t *read_digital0, uint32_t *read_digital1, uint32_t *read_digital2, uint32_t *read_digital3);
//-----------------------------------------------------------------
//-
//- OSCILLOSCOPE_Oscilloscope_1_START
//-
//- Start Oscilloscope acquisition.
//-
//- ARGUMENTS:
//- 	          handle PARAM_INOUT  NI_HANDLE
//- 		Connection handle to the board
//- 		DEFAULT: 
//- 		OPTIONAL: False
//-
//-
//- RETURN [int]
//- 	Return if the function has been succesfully executed
//- 		0) Success
//- 		-1) Error
//-
//-----------------------------------------------------------------

SCILIB int OSCILLOSCOPE_Oscilloscope_1_START(NI_HANDLE *handle)
;
//-----------------------------------------------------------------
//-
//- OSCILLOSCOPE_Oscilloscope_1_SET_PARAMETERS
//-
//- Configure oscilloscope parameters
//-
//- ARGUMENTS:
//- 	       decimator   PARAM_IN    int32_t
//- 		Set decimator value. 0: no decimation, 1: divide by two, ...
//- 		DEFAULT: 
//- 		OPTIONAL: False
//-
//- 	             pre   PARAM_IN    int32_t
//- 		Set the length in samples of pre-trigger buffer
//- 		DEFAULT: 
//- 		OPTIONAL: False
//-
//- 	software_trigger   PARAM_IN    int32_t
//- 		Generate software trigger to force start acquisition (1:generate trigger)
//- 		DEFAULT: 
//- 		OPTIONAL: False
//-
//- 	  analog_trigger   PARAM_IN    int32_t
//- 		Enable threshold trigger on analog input of selected channel
//- 		DEFAULT: 
//- 		OPTIONAL: False
//- 		0) Disable
//- 		1) Enable
//-
//- 	digital0_trigger   PARAM_IN    int32_t
//- 		Enable digital trigger on digital in 0 of selected channel
//- 		DEFAULT: 
//- 		OPTIONAL: False
//- 		0) Disable
//- 		1) Enable
//-
//- 	digital1_trigger   PARAM_IN    int32_t
//- 		Enable digital trigger on digital in 1 of selected channel
//- 		DEFAULT: 
//- 		OPTIONAL: False
//- 		0) Disable
//- 		1) Enable
//-
//- 	digital2_trigger   PARAM_IN    int32_t
//- 		Enable digital trigger on digital in 2 of selected channel
//- 		DEFAULT: 
//- 		OPTIONAL: False
//- 		0) Disable
//- 		1) Enable
//-
//- 	digital3_trigger   PARAM_IN    int32_t
//- 		Enable digital trigger on digital in 3 of selected channel
//- 		DEFAULT: 
//- 		OPTIONAL: False
//- 		0) Disable
//- 		1) Enable
//-
//- 	 trigger_channel   PARAM_IN    int32_t
//- 		Select channel of the oscilloscope connected to the trigger logic
//- 		DEFAULT: 
//- 		OPTIONAL: False
//-
//- 	    trigger_edge   PARAM_IN    int32_t
//- 		Select channel of the oscilloscope connected to the trigger logic
//- 		DEFAULT: 
//- 		OPTIONAL: False
//- 		0) Rising
//- 		1) Falling
//-
//- 	   trigger_level   PARAM_IN    int32_t
//- 		Level in LSB of the leading edge comparator on analog input. Use only with analog_trigger=1
//- 		DEFAULT: 
//- 		OPTIONAL: False
//-
//- 	          handle PARAM_INOUT  NI_HANDLE
//- 		Connection handle to the board
//- 		DEFAULT: 
//- 		OPTIONAL: False
//-
//-
//- RETURN [int]
//- 	Return if the function has been succesfully executed
//- 		0) Success
//- 		-1) Error
//-
//-----------------------------------------------------------------

SCILIB int OSCILLOSCOPE_Oscilloscope_1_SET_PARAMETERS(int32_t decimator, int32_t pre, int32_t software_trigger, int32_t analog_trigger, int32_t digital0_trigger, int32_t digital1_trigger, int32_t digital2_trigger, int32_t digital3_trigger, int32_t trigger_channel, int32_t trigger_edge, int32_t trigger_level, NI_HANDLE *handle);
//-----------------------------------------------------------------
//-
//- OSCILLOSCOPE_Oscilloscope_1_STATUS
//-
//- Get Oscilloscope status
//-
//- ARGUMENTS:
//- 	          status  PARAM_OUT    int32_t
//- 		Return the oscilloscope status
//- 		DEFAULT: 
//- 		OPTIONAL: False
//- 		0) No data available
//- 		1) Data available
//-
//- 	          handle PARAM_INOUT  NI_HANDLE
//- 		Connection handle to the board
//- 		DEFAULT: 
//- 		OPTIONAL: False
//-
//-
//- RETURN [int]
//- 	Return if the function has been succesfully executed
//- 		0) Success
//- 		-1) Error
//-
//-----------------------------------------------------------------

SCILIB int OSCILLOSCOPE_Oscilloscope_1_STATUS(uint32_t *status,NI_HANDLE *handle);
//-----------------------------------------------------------------
//-
//- OSCILLOSCOPE_Oscilloscope_1_POSITION
//-
//- Get Oscilloscope trigger position. The trigger position indicate the position in the output buffer of each channels where the sample at t0 occureed. PRE-TRIGGER samples before t0 is the pre-trigger data.
//-
//- ARGUMENTS:
//- 	        position  PARAM_OUT    int32_t
//- 		Return the trigger position in the data set in order to correct recustruct the pre-prigger and post trigger data
//- 		DEFAULT: 
//- 		OPTIONAL: False
//-
//- 	          handle PARAM_INOUT  NI_HANDLE
//- 		Connection handle to the board
//- 		DEFAULT: 
//- 		OPTIONAL: False
//-
//-
//- RETURN [int]
//- 	Return if the function has been succesfully executed
//- 		0) Success
//- 		-1) Error
//-
//-----------------------------------------------------------------

SCILIB int OSCILLOSCOPE_Oscilloscope_1_POSITION(int32_t *position,NI_HANDLE *handle);
//-----------------------------------------------------------------
//-
//- OSCILLOSCOPE_Oscilloscope_1_DOWNLOAD
//-
//- Download data from oscilloscope buffer. Please note that downloaded data is not time ordered and the trigger position info data must be obtained using the OSCILLOSCOPE_Oscilloscope_1POSITION function 
//- 
//- USAGE: 
//-     OSCILLOSCOPE_Oscilloscope_1_DOWNLOAD(data_buffer, BUFFER_SIZE_Oscilloscope_1, 1000, handle, rd, vp);
//- 
//-
//- ARGUMENTS:
//- 	             val  PARAM_OUT   uint32_t
//- 		uint32_t buffer data with preallocated size of at list 'size' parameters + 16 word
//- 		DEFAULT: 
//- 		OPTIONAL: False
//-
//- 	             val   PARAM_IN       size
//- 		number of word to download from the buffer. Use macro BUFFER_SIZE_Oscilloscope_1 to get actual oscilloscope buffer size on FPGA
//- 		DEFAULT: 
//- 		OPTIONAL: False
//-
//- 	             val   PARAM_IN    int32_t
//- 		timeout in ms
//- 		DEFAULT: 
//- 		OPTIONAL: False
//-
//- 	          handle PARAM_INOUT  NI_HANDLE
//- 		Connection handle to the board
//- 		DEFAULT: 
//- 		OPTIONAL: False
//-
//- 	       read_data  PARAM_OUT    int32_t
//- 		number of word read from the buffer
//- 		DEFAULT: 
//- 		OPTIONAL: False
//-
//- 	      valid_data  PARAM_OUT    int32_t
//- 		number of word valid in the buffer
//- 		DEFAULT: 
//- 		OPTIONAL: False
//-
//-
//- RETURN [int]
//- 	Return if the function has been succesfully executed
//- 		0) Success
//- 		-1) Error
//-
//-----------------------------------------------------------------

SCILIB int OSCILLOSCOPE_Oscilloscope_1_DOWNLOAD(uint32_t *val, uint32_t size, int32_t timeout, NI_HANDLE *handle, uint32_t *read_data, uint32_t *valid_data);
//-----------------------------------------------------------------
//-
//- OSCILLOSCOPE_Oscilloscope_1_RECONSTRUCT
//-
//- Take as input the downloaded buffer and decode the the different track for each channels. Channel order is the following: [0...1023] Channel 1, [1024...2047] Channel2
//- 
//- 
//-
//- ARGUMENTS:
//- 	        data_osc   PARAM_IN   uint32_t
//- 		uint32_t buffer containing the raw data download with the DOWNLOAD function
//- 		DEFAULT: 
//- 		OPTIONAL: False
//-
//- 	        position   PARAM_IN   uint32_t
//- 		Position of the trigger obtained with the POSITION function
//- 		DEFAULT: 
//- 		OPTIONAL: False
//-
//- 	     pre_trigger   PARAM_IN    int32_t
//- 		Length of the pre-trigger
//- 		DEFAULT: 
//- 		OPTIONAL: False
//-
//- 	     read_analog  PARAM_OUT   uint32_t
//- 		Analog track reordered in time. Data are encoded in unsigned data format between -32576 and 32576
//- 		DEFAULT: 
//- 		OPTIONAL: False
//-
//- 	   read_digital0  PARAM_OUT   uint32_t
//- 		Digital track 0 reordered
//- 		DEFAULT: 
//- 		OPTIONAL: False
//-
//- 	   read_digital1  PARAM_OUT   uint32_t
//- 		Digital track 1 reordered
//- 		DEFAULT: 
//- 		OPTIONAL: False
//-
//- 	   read_digital2  PARAM_OUT   uint32_t
//- 		Digital track 2 reordered
//- 		DEFAULT: 
//- 		OPTIONAL: False
//-
//- 	   read_digital3  PARAM_OUT   uint32_t
//- 		Digital track 3 reordered
//- 		DEFAULT: 
//- 		OPTIONAL: False
//-
//-
//- RETURN [int]
//- 	Return if the function has been succesfully executed
//- 		0) Success
//- 		-1) Error
//-
//-----------------------------------------------------------------

SCILIB int OSCILLOSCOPE_Oscilloscope_1_RECONSTRUCT(uint32_t *data_osc, uint32_t position, int32_t pre_trigger, uint32_t *read_analog, uint32_t *read_digital0, uint32_t *read_digital1, uint32_t *read_digital2, uint32_t *read_digital3);
//-----------------------------------------------------------------
//-
//- OSCILLOSCOPE_Oscilloscope_2_START
//-
//- Start Oscilloscope acquisition.
//-
//- ARGUMENTS:
//- 	          handle PARAM_INOUT  NI_HANDLE
//- 		Connection handle to the board
//- 		DEFAULT: 
//- 		OPTIONAL: False
//-
//-
//- RETURN [int]
//- 	Return if the function has been succesfully executed
//- 		0) Success
//- 		-1) Error
//-
//-----------------------------------------------------------------

SCILIB int OSCILLOSCOPE_Oscilloscope_2_START(NI_HANDLE *handle)
;
//-----------------------------------------------------------------
//-
//- OSCILLOSCOPE_Oscilloscope_2_SET_PARAMETERS
//-
//- Configure oscilloscope parameters
//-
//- ARGUMENTS:
//- 	       decimator   PARAM_IN    int32_t
//- 		Set decimator value. 0: no decimation, 1: divide by two, ...
//- 		DEFAULT: 
//- 		OPTIONAL: False
//-
//- 	             pre   PARAM_IN    int32_t
//- 		Set the length in samples of pre-trigger buffer
//- 		DEFAULT: 
//- 		OPTIONAL: False
//-
//- 	software_trigger   PARAM_IN    int32_t
//- 		Generate software trigger to force start acquisition (1:generate trigger)
//- 		DEFAULT: 
//- 		OPTIONAL: False
//-
//- 	  analog_trigger   PARAM_IN    int32_t
//- 		Enable threshold trigger on analog input of selected channel
//- 		DEFAULT: 
//- 		OPTIONAL: False
//- 		0) Disable
//- 		1) Enable
//-
//- 	digital0_trigger   PARAM_IN    int32_t
//- 		Enable digital trigger on digital in 0 of selected channel
//- 		DEFAULT: 
//- 		OPTIONAL: False
//- 		0) Disable
//- 		1) Enable
//-
//- 	digital1_trigger   PARAM_IN    int32_t
//- 		Enable digital trigger on digital in 1 of selected channel
//- 		DEFAULT: 
//- 		OPTIONAL: False
//- 		0) Disable
//- 		1) Enable
//-
//- 	digital2_trigger   PARAM_IN    int32_t
//- 		Enable digital trigger on digital in 2 of selected channel
//- 		DEFAULT: 
//- 		OPTIONAL: False
//- 		0) Disable
//- 		1) Enable
//-
//- 	digital3_trigger   PARAM_IN    int32_t
//- 		Enable digital trigger on digital in 3 of selected channel
//- 		DEFAULT: 
//- 		OPTIONAL: False
//- 		0) Disable
//- 		1) Enable
//-
//- 	 trigger_channel   PARAM_IN    int32_t
//- 		Select channel of the oscilloscope connected to the trigger logic
//- 		DEFAULT: 
//- 		OPTIONAL: False
//-
//- 	    trigger_edge   PARAM_IN    int32_t
//- 		Select channel of the oscilloscope connected to the trigger logic
//- 		DEFAULT: 
//- 		OPTIONAL: False
//- 		0) Rising
//- 		1) Falling
//-
//- 	   trigger_level   PARAM_IN    int32_t
//- 		Level in LSB of the leading edge comparator on analog input. Use only with analog_trigger=1
//- 		DEFAULT: 
//- 		OPTIONAL: False
//-
//- 	          handle PARAM_INOUT  NI_HANDLE
//- 		Connection handle to the board
//- 		DEFAULT: 
//- 		OPTIONAL: False
//-
//-
//- RETURN [int]
//- 	Return if the function has been succesfully executed
//- 		0) Success
//- 		-1) Error
//-
//-----------------------------------------------------------------

SCILIB int OSCILLOSCOPE_Oscilloscope_2_SET_PARAMETERS(int32_t decimator, int32_t pre, int32_t software_trigger, int32_t analog_trigger, int32_t digital0_trigger, int32_t digital1_trigger, int32_t digital2_trigger, int32_t digital3_trigger, int32_t trigger_channel, int32_t trigger_edge, int32_t trigger_level, NI_HANDLE *handle);
//-----------------------------------------------------------------
//-
//- OSCILLOSCOPE_Oscilloscope_2_STATUS
//-
//- Get Oscilloscope status
//-
//- ARGUMENTS:
//- 	          status  PARAM_OUT    int32_t
//- 		Return the oscilloscope status
//- 		DEFAULT: 
//- 		OPTIONAL: False
//- 		0) No data available
//- 		1) Data available
//-
//- 	          handle PARAM_INOUT  NI_HANDLE
//- 		Connection handle to the board
//- 		DEFAULT: 
//- 		OPTIONAL: False
//-
//-
//- RETURN [int]
//- 	Return if the function has been succesfully executed
//- 		0) Success
//- 		-1) Error
//-
//-----------------------------------------------------------------

SCILIB int OSCILLOSCOPE_Oscilloscope_2_STATUS(uint32_t *status,NI_HANDLE *handle);
//-----------------------------------------------------------------
//-
//- OSCILLOSCOPE_Oscilloscope_2_POSITION
//-
//- Get Oscilloscope trigger position. The trigger position indicate the position in the output buffer of each channels where the sample at t0 occureed. PRE-TRIGGER samples before t0 is the pre-trigger data.
//-
//- ARGUMENTS:
//- 	        position  PARAM_OUT    int32_t
//- 		Return the trigger position in the data set in order to correct recustruct the pre-prigger and post trigger data
//- 		DEFAULT: 
//- 		OPTIONAL: False
//-
//- 	          handle PARAM_INOUT  NI_HANDLE
//- 		Connection handle to the board
//- 		DEFAULT: 
//- 		OPTIONAL: False
//-
//-
//- RETURN [int]
//- 	Return if the function has been succesfully executed
//- 		0) Success
//- 		-1) Error
//-
//-----------------------------------------------------------------

SCILIB int OSCILLOSCOPE_Oscilloscope_2_POSITION(int32_t *position,NI_HANDLE *handle);
//-----------------------------------------------------------------
//-
//- OSCILLOSCOPE_Oscilloscope_2_DOWNLOAD
//-
//- Download data from oscilloscope buffer. Please note that downloaded data is not time ordered and the trigger position info data must be obtained using the OSCILLOSCOPE_Oscilloscope_2POSITION function 
//- 
//- USAGE: 
//-     OSCILLOSCOPE_Oscilloscope_2_DOWNLOAD(data_buffer, BUFFER_SIZE_Oscilloscope_2, 1000, handle, rd, vp);
//- 
//-
//- ARGUMENTS:
//- 	             val  PARAM_OUT   uint32_t
//- 		uint32_t buffer data with preallocated size of at list 'size' parameters + 16 word
//- 		DEFAULT: 
//- 		OPTIONAL: False
//-
//- 	             val   PARAM_IN       size
//- 		number of word to download from the buffer. Use macro BUFFER_SIZE_Oscilloscope_2 to get actual oscilloscope buffer size on FPGA
//- 		DEFAULT: 
//- 		OPTIONAL: False
//-
//- 	             val   PARAM_IN    int32_t
//- 		timeout in ms
//- 		DEFAULT: 
//- 		OPTIONAL: False
//-
//- 	          handle PARAM_INOUT  NI_HANDLE
//- 		Connection handle to the board
//- 		DEFAULT: 
//- 		OPTIONAL: False
//-
//- 	       read_data  PARAM_OUT    int32_t
//- 		number of word read from the buffer
//- 		DEFAULT: 
//- 		OPTIONAL: False
//-
//- 	      valid_data  PARAM_OUT    int32_t
//- 		number of word valid in the buffer
//- 		DEFAULT: 
//- 		OPTIONAL: False
//-
//-
//- RETURN [int]
//- 	Return if the function has been succesfully executed
//- 		0) Success
//- 		-1) Error
//-
//-----------------------------------------------------------------

SCILIB int OSCILLOSCOPE_Oscilloscope_2_DOWNLOAD(uint32_t *val, uint32_t size, int32_t timeout, NI_HANDLE *handle, uint32_t *read_data, uint32_t *valid_data);
//-----------------------------------------------------------------
//-
//- OSCILLOSCOPE_Oscilloscope_2_RECONSTRUCT
//-
//- Take as input the downloaded buffer and decode the the different track for each channels. Channel order is the following: [0...1023] Channel 1, [1024...2047] Channel2
//- 
//- 
//-
//- ARGUMENTS:
//- 	        data_osc   PARAM_IN   uint32_t
//- 		uint32_t buffer containing the raw data download with the DOWNLOAD function
//- 		DEFAULT: 
//- 		OPTIONAL: False
//-
//- 	        position   PARAM_IN   uint32_t
//- 		Position of the trigger obtained with the POSITION function
//- 		DEFAULT: 
//- 		OPTIONAL: False
//-
//- 	     pre_trigger   PARAM_IN    int32_t
//- 		Length of the pre-trigger
//- 		DEFAULT: 
//- 		OPTIONAL: False
//-
//- 	     read_analog  PARAM_OUT   uint32_t
//- 		Analog track reordered in time. Data are encoded in unsigned data format between -32576 and 32576
//- 		DEFAULT: 
//- 		OPTIONAL: False
//-
//- 	   read_digital0  PARAM_OUT   uint32_t
//- 		Digital track 0 reordered
//- 		DEFAULT: 
//- 		OPTIONAL: False
//-
//- 	   read_digital1  PARAM_OUT   uint32_t
//- 		Digital track 1 reordered
//- 		DEFAULT: 
//- 		OPTIONAL: False
//-
//- 	   read_digital2  PARAM_OUT   uint32_t
//- 		Digital track 2 reordered
//- 		DEFAULT: 
//- 		OPTIONAL: False
//-
//- 	   read_digital3  PARAM_OUT   uint32_t
//- 		Digital track 3 reordered
//- 		DEFAULT: 
//- 		OPTIONAL: False
//-
//-
//- RETURN [int]
//- 	Return if the function has been succesfully executed
//- 		0) Success
//- 		-1) Error
//-
//-----------------------------------------------------------------

SCILIB int OSCILLOSCOPE_Oscilloscope_2_RECONSTRUCT(uint32_t *data_osc, uint32_t position, int32_t pre_trigger, uint32_t *read_analog, uint32_t *read_digital0, uint32_t *read_digital1, uint32_t *read_digital2, uint32_t *read_digital3);
//-----------------------------------------------------------------
//-
//- OSCILLOSCOPE_Oscilloscope_3_START
//-
//- Start Oscilloscope acquisition.
//-
//- ARGUMENTS:
//- 	          handle PARAM_INOUT  NI_HANDLE
//- 		Connection handle to the board
//- 		DEFAULT: 
//- 		OPTIONAL: False
//-
//-
//- RETURN [int]
//- 	Return if the function has been succesfully executed
//- 		0) Success
//- 		-1) Error
//-
//-----------------------------------------------------------------

SCILIB int OSCILLOSCOPE_Oscilloscope_3_START(NI_HANDLE *handle)
;
//-----------------------------------------------------------------
//-
//- OSCILLOSCOPE_Oscilloscope_3_SET_PARAMETERS
//-
//- Configure oscilloscope parameters
//-
//- ARGUMENTS:
//- 	       decimator   PARAM_IN    int32_t
//- 		Set decimator value. 0: no decimation, 1: divide by two, ...
//- 		DEFAULT: 
//- 		OPTIONAL: False
//-
//- 	             pre   PARAM_IN    int32_t
//- 		Set the length in samples of pre-trigger buffer
//- 		DEFAULT: 
//- 		OPTIONAL: False
//-
//- 	software_trigger   PARAM_IN    int32_t
//- 		Generate software trigger to force start acquisition (1:generate trigger)
//- 		DEFAULT: 
//- 		OPTIONAL: False
//-
//- 	  analog_trigger   PARAM_IN    int32_t
//- 		Enable threshold trigger on analog input of selected channel
//- 		DEFAULT: 
//- 		OPTIONAL: False
//- 		0) Disable
//- 		1) Enable
//-
//- 	digital0_trigger   PARAM_IN    int32_t
//- 		Enable digital trigger on digital in 0 of selected channel
//- 		DEFAULT: 
//- 		OPTIONAL: False
//- 		0) Disable
//- 		1) Enable
//-
//- 	digital1_trigger   PARAM_IN    int32_t
//- 		Enable digital trigger on digital in 1 of selected channel
//- 		DEFAULT: 
//- 		OPTIONAL: False
//- 		0) Disable
//- 		1) Enable
//-
//- 	digital2_trigger   PARAM_IN    int32_t
//- 		Enable digital trigger on digital in 2 of selected channel
//- 		DEFAULT: 
//- 		OPTIONAL: False
//- 		0) Disable
//- 		1) Enable
//-
//- 	digital3_trigger   PARAM_IN    int32_t
//- 		Enable digital trigger on digital in 3 of selected channel
//- 		DEFAULT: 
//- 		OPTIONAL: False
//- 		0) Disable
//- 		1) Enable
//-
//- 	 trigger_channel   PARAM_IN    int32_t
//- 		Select channel of the oscilloscope connected to the trigger logic
//- 		DEFAULT: 
//- 		OPTIONAL: False
//-
//- 	    trigger_edge   PARAM_IN    int32_t
//- 		Select channel of the oscilloscope connected to the trigger logic
//- 		DEFAULT: 
//- 		OPTIONAL: False
//- 		0) Rising
//- 		1) Falling
//-
//- 	   trigger_level   PARAM_IN    int32_t
//- 		Level in LSB of the leading edge comparator on analog input. Use only with analog_trigger=1
//- 		DEFAULT: 
//- 		OPTIONAL: False
//-
//- 	          handle PARAM_INOUT  NI_HANDLE
//- 		Connection handle to the board
//- 		DEFAULT: 
//- 		OPTIONAL: False
//-
//-
//- RETURN [int]
//- 	Return if the function has been succesfully executed
//- 		0) Success
//- 		-1) Error
//-
//-----------------------------------------------------------------

SCILIB int OSCILLOSCOPE_Oscilloscope_3_SET_PARAMETERS(int32_t decimator, int32_t pre, int32_t software_trigger, int32_t analog_trigger, int32_t digital0_trigger, int32_t digital1_trigger, int32_t digital2_trigger, int32_t digital3_trigger, int32_t trigger_channel, int32_t trigger_edge, int32_t trigger_level, NI_HANDLE *handle);
//-----------------------------------------------------------------
//-
//- OSCILLOSCOPE_Oscilloscope_3_STATUS
//-
//- Get Oscilloscope status
//-
//- ARGUMENTS:
//- 	          status  PARAM_OUT    int32_t
//- 		Return the oscilloscope status
//- 		DEFAULT: 
//- 		OPTIONAL: False
//- 		0) No data available
//- 		1) Data available
//-
//- 	          handle PARAM_INOUT  NI_HANDLE
//- 		Connection handle to the board
//- 		DEFAULT: 
//- 		OPTIONAL: False
//-
//-
//- RETURN [int]
//- 	Return if the function has been succesfully executed
//- 		0) Success
//- 		-1) Error
//-
//-----------------------------------------------------------------

SCILIB int OSCILLOSCOPE_Oscilloscope_3_STATUS(uint32_t *status,NI_HANDLE *handle);
//-----------------------------------------------------------------
//-
//- OSCILLOSCOPE_Oscilloscope_3_POSITION
//-
//- Get Oscilloscope trigger position. The trigger position indicate the position in the output buffer of each channels where the sample at t0 occureed. PRE-TRIGGER samples before t0 is the pre-trigger data.
//-
//- ARGUMENTS:
//- 	        position  PARAM_OUT    int32_t
//- 		Return the trigger position in the data set in order to correct recustruct the pre-prigger and post trigger data
//- 		DEFAULT: 
//- 		OPTIONAL: False
//-
//- 	          handle PARAM_INOUT  NI_HANDLE
//- 		Connection handle to the board
//- 		DEFAULT: 
//- 		OPTIONAL: False
//-
//-
//- RETURN [int]
//- 	Return if the function has been succesfully executed
//- 		0) Success
//- 		-1) Error
//-
//-----------------------------------------------------------------

SCILIB int OSCILLOSCOPE_Oscilloscope_3_POSITION(int32_t *position,NI_HANDLE *handle);
//-----------------------------------------------------------------
//-
//- OSCILLOSCOPE_Oscilloscope_3_DOWNLOAD
//-
//- Download data from oscilloscope buffer. Please note that downloaded data is not time ordered and the trigger position info data must be obtained using the OSCILLOSCOPE_Oscilloscope_3POSITION function 
//- 
//- USAGE: 
//-     OSCILLOSCOPE_Oscilloscope_3_DOWNLOAD(data_buffer, BUFFER_SIZE_Oscilloscope_3, 1000, handle, rd, vp);
//- 
//-
//- ARGUMENTS:
//- 	             val  PARAM_OUT   uint32_t
//- 		uint32_t buffer data with preallocated size of at list 'size' parameters + 16 word
//- 		DEFAULT: 
//- 		OPTIONAL: False
//-
//- 	             val   PARAM_IN       size
//- 		number of word to download from the buffer. Use macro BUFFER_SIZE_Oscilloscope_3 to get actual oscilloscope buffer size on FPGA
//- 		DEFAULT: 
//- 		OPTIONAL: False
//-
//- 	             val   PARAM_IN    int32_t
//- 		timeout in ms
//- 		DEFAULT: 
//- 		OPTIONAL: False
//-
//- 	          handle PARAM_INOUT  NI_HANDLE
//- 		Connection handle to the board
//- 		DEFAULT: 
//- 		OPTIONAL: False
//-
//- 	       read_data  PARAM_OUT    int32_t
//- 		number of word read from the buffer
//- 		DEFAULT: 
//- 		OPTIONAL: False
//-
//- 	      valid_data  PARAM_OUT    int32_t
//- 		number of word valid in the buffer
//- 		DEFAULT: 
//- 		OPTIONAL: False
//-
//-
//- RETURN [int]
//- 	Return if the function has been succesfully executed
//- 		0) Success
//- 		-1) Error
//-
//-----------------------------------------------------------------

SCILIB int OSCILLOSCOPE_Oscilloscope_3_DOWNLOAD(uint32_t *val, uint32_t size, int32_t timeout, NI_HANDLE *handle, uint32_t *read_data, uint32_t *valid_data);
//-----------------------------------------------------------------
//-
//- OSCILLOSCOPE_Oscilloscope_3_RECONSTRUCT
//-
//- Take as input the downloaded buffer and decode the the different track for each channels. Channel order is the following: [0...1023] Channel 1, [1024...2047] Channel2
//- 
//- 
//-
//- ARGUMENTS:
//- 	        data_osc   PARAM_IN   uint32_t
//- 		uint32_t buffer containing the raw data download with the DOWNLOAD function
//- 		DEFAULT: 
//- 		OPTIONAL: False
//-
//- 	        position   PARAM_IN   uint32_t
//- 		Position of the trigger obtained with the POSITION function
//- 		DEFAULT: 
//- 		OPTIONAL: False
//-
//- 	     pre_trigger   PARAM_IN    int32_t
//- 		Length of the pre-trigger
//- 		DEFAULT: 
//- 		OPTIONAL: False
//-
//- 	     read_analog  PARAM_OUT   uint32_t
//- 		Analog track reordered in time. Data are encoded in unsigned data format between -32576 and 32576
//- 		DEFAULT: 
//- 		OPTIONAL: False
//-
//- 	   read_digital0  PARAM_OUT   uint32_t
//- 		Digital track 0 reordered
//- 		DEFAULT: 
//- 		OPTIONAL: False
//-
//- 	   read_digital1  PARAM_OUT   uint32_t
//- 		Digital track 1 reordered
//- 		DEFAULT: 
//- 		OPTIONAL: False
//-
//- 	   read_digital2  PARAM_OUT   uint32_t
//- 		Digital track 2 reordered
//- 		DEFAULT: 
//- 		OPTIONAL: False
//-
//- 	   read_digital3  PARAM_OUT   uint32_t
//- 		Digital track 3 reordered
//- 		DEFAULT: 
//- 		OPTIONAL: False
//-
//-
//- RETURN [int]
//- 	Return if the function has been succesfully executed
//- 		0) Success
//- 		-1) Error
//-
//-----------------------------------------------------------------

SCILIB int OSCILLOSCOPE_Oscilloscope_3_RECONSTRUCT(uint32_t *data_osc, uint32_t position, int32_t pre_trigger, uint32_t *read_analog, uint32_t *read_digital0, uint32_t *read_digital1, uint32_t *read_digital2, uint32_t *read_digital3);
