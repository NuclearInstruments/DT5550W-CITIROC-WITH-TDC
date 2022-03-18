#include "niusb3_core.h"
#include  <stdlib.h>
#include <stdint.h>
#include  <stdbool.h>

#include "RegisterFile.h"

#include  "circular_buffer.h"



#include  "CitirocRedoutFullV_lib.h"

SCILIB int USB3_Init()
{
	return NI_USB3_Init();
}

SCILIB int USB3_ConnectDevice( char *IPAddress_or_SN, NI_HANDLE *handle)
{
	return NI_USB3_ConnectDevice( IPAddress_or_SN, handle);
}

SCILIB int USB3_CloseConnection(NI_HANDLE *handle)
{
	return NI_USB3_CloseConnection(handle);
}

SCILIB int USB3_ListDevices(char *ListOfDevice, char *model,  int *Count)
{
	return NI_USB3_ListDevices(ListOfDevice, model, Count);
}

SCILIB int __abstracted_mem_write(uint32_t *data, uint32_t count, 
										uint32_t address, 
										uint32_t timeout_ms, NI_HANDLE *handle, 
										uint32_t *written_data)
{
	return NI_USB3_WriteData(data,  count,  address, REG_ACCESS, timeout_ms, handle, written_data);
}


SCILIB int __abstracted_mem_read(uint32_t *data, uint32_t count, 
										uint32_t address, 
										uint32_t timeout_ms, NI_HANDLE *handle, 
										uint32_t *read_data, uint32_t *valid_data)
{
	return NI_USB3_ReadData(data,  count, address,  REG_ACCESS, timeout_ms, handle, read_data, valid_data);
}

SCILIB int __abstracted_fifo_write(uint32_t *data, uint32_t count, 
										uint32_t address, 
										uint32_t timeout_ms, NI_HANDLE *handle, 
										uint32_t *written_data)
{
	return NI_USB3_WriteData(data,  count,  address, STREAMING, timeout_ms, handle, written_data);
}
	
SCILIB int __abstracted_fifo_read(uint32_t *data, uint32_t count, 
										uint32_t address, 
										uint32_t address_status, 
										bool blocking,
										uint32_t timeout_ms, NI_HANDLE *handle, 
										uint32_t *read_data, uint32_t *valid_data)
{
	return NI_USB3_ReadData(data,  count, address,  STREAMING, timeout_ms, handle, read_data, valid_data);
}
	
SCILIB int __abstracted_reg_write(uint32_t data, uint32_t address, NI_HANDLE *handle)
{
	return NI_USB3_WriteReg(data, address, handle);
}

SCILIB int __abstracted_reg_read(uint32_t *data, uint32_t address, NI_HANDLE *handle)
{
	return NI_USB3_ReadReg(data,  address,  handle);
}

SCILIB int AFE_USB3_SetOffset(boolean top, uint32_t DACCODE, NI_HANDLE *handle)
{
	return NI_USB3_SetOffset( top,  DACCODE, handle);
}

SCILIB int AFE_USB3_SetImpedance(boolean R50, NI_HANDLE *handle)
{
	return NI_USB3_SetImpedance( R50, handle);
}

SCILIB int AFE_USB3_SetIICControllerBaseAddress(uint32_t ControlAddress, uint32_t StatusAddress, NI_HANDLE *handle)
{
	return NI_USB3_SetIICControllerBaseAddress( ControlAddress,  StatusAddress, handle);
}	


SCILIB int SetHV_A7585D(bool Enable, float voltage, NI_HANDLE *handle)
{
	return NI_USB3_SetHV(Enable, voltage, handle);
}

SCILIB int GetHV_A7585D(bool *Enable, float *voltage, float *current, NI_HANDLE *handle)
{
	return NI_USB3_GetHV(Enable, voltage, current, handle);
}

SCILIB int IICUser_OpenControllerInit(uint32_t ControlAddress, uint32_t StatusAddress, NI_HANDLE *handle, NI_IIC_HANDLE *IIC_Handle)
{
	return NI_USB3_IICUser_OpenController(ControlAddress, StatusAddress, handle, IIC_Handle);
}

SCILIB int IICUser_ReadData(uint8_t address, uint8_t *value, int len, uint8_t *value_read, int len_read, NI_IIC_HANDLE *IIC_Handle)
{
	return NI_USB3_IICUser_ReadData(address, value, len, value_read, len_read, IIC_Handle);
}

SCILIB int IICUser_WriteData(uint8_t address, uint8_t *value, int len, NI_IIC_HANDLE *IIC_Handle)
{
	return NI_USB3_IICUser_WriteData(address, value, len, IIC_Handle);
}
 
SCILIB int GetDT5550WTempSens(int address, float *temp, NI_HANDLE *handle)
{
	return NI_USB3_GetDT5550WTempSens(address, temp, handle);
}

SCILIB char *ReadFirmwareInformation(NI_HANDLE *handle)
{
	return ReadFirmwareInformationApp(handle);
}

SCILIB int ReadSN(uint32_t *SN, NI_HANDLE *handle)
{
	uint64_t UID;
	return SECReadUIDSN(&UID, SN, handle);
}

SCILIB int GetDT5550_DGBoardInfo(char *model, int *asic_count, int *SN, NI_HANDLE *handle)
{
	return NI_USB3_GetDT5550_DGBoardInfo(model, asic_count, SN, handle);
}


uint32_t gray_to_bin(uint32_t num, int nbit)
{
	uint32_t temp = num ^ (num >> 8);
	temp ^= (temp >> 4);
	temp ^= (temp >> 2);
	temp ^= (temp >> 1);
	return temp;
}



//-----------------------------------------------------------------
//-
//-  PETIROC_ALLFIFO_FLUSH
//-
//-	 Clear all FIFOs of the PETIROCFRAME syncronous
//-  ARGUMENTS:
//- 	            buffer_handle   PARAM_OUT   void ** 
//-			Handle to the buffer
//- 		DEFAULT: 
//- 		OPTIONAL: False
//-  
//- 	   
//-  
//-  RETURN [int]
//- 	Return if the function has been succesfully executed
//- 		0) Success
//- 		-1) Error
//-----------------------------------------------------------------

SCILIB int PETIROC_ALLFIFO_FLUSH(NI_HANDLE *handle)
{
	__abstracted_reg_write(1, SCI_REG_ALL_FIFO_RESET, handle);
	return __abstracted_reg_write(0, SCI_REG_ALL_FIFO_RESET, handle);

}




//-----------------------------------------------------------------
//-
//-  Utility_ALLOCATE_DOWNLOAD_BUFFER
//-
//-	 This function take as input a pointer to a buffer handle (not pre-allocated void*) and fill it
//-  with the pointer to the circular buffer to store data acquired from a board FIFO that is waiting
//-  to be processed.
//-  The buffer_size specify the size of the buffer to be allocated
//-  ARGUMENTS:
//- 	            buffer_handle   PARAM_OUT   void ** 
//-			Handle to the buffer
//- 		DEFAULT: 
//- 		OPTIONAL: False
//-  
//- 	            buffer_size   PARAM_IN   uint32_t
//- 		size in word (32 bit) of the buffer to be allocated
//- 		DEFAULT: 
//- 		OPTIONAL: False
//-  
//-  RETURN [int]
//- 	Return if the function has been succesfully executed
//- 		0) Success
//- 		-1) Error
//-
//-  EXAMPLE:
//-
//-		void *BufferDownloadHandler = NULL;
//-		Utility_ALLOCATE_DOWNLOAD_BUFFER(&BufferDownloadHandler, 1024*1024);
//-----------------------------------------------------------------

SCILIB int Utility_ALLOCATE_DOWNLOAD_BUFFER(void **buffer_handle, uint32_t buffer_size)
{
	uint32_t * buffer = malloc(buffer_size * sizeof(uint32_t));
	if (buffer == NULL) return -1;
	cbuf_handle_t cbuf = circular_buf_init(buffer, buffer_size);
	*buffer_handle = cbuf;
	return 0;
}




//-----------------------------------------------------------------
//-
//-  Utility_ENQUEUE_DATA_IN_DOWNLOAD_BUFFER
//-
//-	 This function take as input a pointer to a buffer handle allocated with the function 
//-  Utility_ALLOCATE_DOWNLOAD_BUFFER and fill it with the content of the array val
//-  If the buffer is full the function fails and the output parameter 
//-  The buffer_size specify the size of the buffer to be allocated enqueued_data willl
//-	 contain the number of word that has been enqueued in the buffer
//-
//-  ARGUMENTS:
//- 	            buffer_handle   PARAM_IN   void *
//-			Handle to the buffer
//- 		DEFAULT: 
//- 		OPTIONAL: False
//-  
//- 	            val			   PARAM_IN   uint32_t *
//-			input data vector downloaded from a FIFO from the board
//- 		DEFAULT: 
//- 		OPTIONAL: False
//- 
//- 	            size   			PARAM_IN   uint32_t 
//- 		number of valid word in the val vector
//- 		DEFAULT: 
//- 		OPTIONAL: False
//-  
//- 	            enqueued_data   PARAM_OUT   uint32_t *
//-			number of word of the val vector really enqueued in the circular buffer
//- 		DEFAULT: 
//- 		OPTIONAL: False
//-
//-  RETURN [int]
//- 	Return if the function has been succesfully executed
//- 		0) Success
//- 		-1) Not all word enqueued in the buffer
//-
//-  EXAMPLE:
//-
//-		FRAME_ImageReadout_0_DOWNLOAD(&data_frame, N_Packet * (9+4), timeout_frame, &handle, &read_data_frame, &valid_data_frame);
//-		Utility_ENQUEUE_DATA_IN_DOWNLOAD_BUFFER(BufferDownloadHandler, data_frame, valid_data_frame, &valid_data_enqueued);
//-----------------------------------------------------------------

SCILIB int Utility_ENQUEUE_DATA_IN_DOWNLOAD_BUFFER(void *buffer_handle, int32_t *val, uint32_t size, uint32_t *enqueued_data)
{
	cbuf_handle_t cbuf;
	uint32_t i;
	uint32_t data_counter=0;
	cbuf = ((cbuf_handle_t)buffer_handle);
	for (i = 0; i < size; i++)
	{
		if (circular_buf_full(cbuf))
		{
			*enqueued_data = data_counter;
			return -1;
		}
		data_counter++;
		circular_buf_put(cbuf, val[i]);
	}
	*enqueued_data = data_counter;
	return 0;
}


//-----------------------------------------------------------------
//-
//-  Utility_PEAK_DATA_FORM_DOWNLOAD_BUFFER
//-
//-	 This function take as input a pointer to a buffer handle allocated with the function 
//-  Utility_ALLOCATE_DOWNLOAD_BUFFER and retrive one data from the buffer (head of the FIFO)
//-  If the buffer is rmpty function fails with -1 error
//-  The buffer_size specify the size of the buffer to be allocated enqueued_data willl
//-	 contain the number of word that has been enqueued in the buffer
//-
//-  ARGUMENTS:
//- 	            buffer_handle   PARAM_IN   void *
//-			Handle to the buffer
//- 		DEFAULT: 
//- 		OPTIONAL: False
//-  
//- 	            val			   PARAM_OUT   uint32_t *
//-			head of the buffer
//- 		DEFAULT: 
//- 		OPTIONAL: False
//-
//-  RETURN [int]
//- 	Return if the function has been succesfully executed
//- 		0) Success
//- 		-1) Empty
//-
//-  EXAMPLE:
//-----------------------------------------------------------------


SCILIB int Utility_PEAK_DATA_FORM_DOWNLOAD_BUFFER(void *buffer_handle, int32_t *val)
{
	cbuf_handle_t cbuf;
	cbuf = (cbuf_handle_t)buffer_handle;
	if (circular_buf_empty(cbuf))
		return -1;
	circular_buf_get(cbuf, val);
	return 0;
}

//-----------------------------------------------------------------
//-
//-  free_PETIROCFRAME_packet_collection
//-
//-	 This function take as input a pointer to a decoded packets and release the memory
//-
//-  ARGUMENTS:
//- 	    buffer_handle   PARAM_IN   t_ASIC_packet_collection *
//-			Packet to be released
//- 		DEFAULT: 
//- 		OPTIONAL: False
//-
//-  RETURN [void]
//-
//-  EXAMPLE:
//-		PETIROCFRAME_PetirocFrame0_RECONSTRUCT_DATA(BufferDownloadHandler, &decoded_packets);
//-		... processing code ...
//-		free_PETIROCFRAME_packet_collection(&decoded_packets);
//-----------------------------------------------------------------


SCILIB void free_PETIROCFRAME_packet_collection(t_ASIC_packet_collection *decoded_packets)
{
	int i;
	for (i = 0; i < decoded_packets->allocated_packets; i++)
	{
		free(decoded_packets->packets[i].Charge);
		free(decoded_packets->packets[i].FineTime);
		free(decoded_packets->packets[i].CoarseTime);
		free(decoded_packets->packets[i].Hit);
	}
	free(decoded_packets->packets);
}


//-----------------------------------------------------------------
//-
//-  free_FRAME_packet_collection
//-
//-	 This function take as input a pointer to a decoded packets and release the memory
//-
//-  ARGUMENTS:
//- 	            buffer_handle   PARAM_IN   t_FRAME_packet_collection *
//-			Packet to be released
//- 		DEFAULT: 
//- 		OPTIONAL: False
//-
//-  RETURN [void]
//-
//-  EXAMPLE:
//-		FRAME_ImageReadout_0_RECONSTRUCT_DATA(BufferDownloadHandler, &decoded_packets);
//-		... processing code ...
//-		free_FRAME_packet_collectionvoid(&decoded_packets);
//-----------------------------------------------------------------


SCILIB void free_FRAME_packet_collection (t_FRAME_packet_collection *decoded_packets)
{
	int i;
	for (i = 0; i < decoded_packets->allocated_packets; i++)
	{
		free(decoded_packets->packets[i].Energy);
	}
	free(decoded_packets->packets);
}SCILIB int REG_TRIG_A_SEL_GET(uint32_t *val, NI_HANDLE *handle)
{
     return __abstracted_reg_read(val, SCI_REG_TRIG_A_SEL, handle);
}
SCILIB int REG_TRIG_A_SEL_SET(uint32_t val, NI_HANDLE *handle)
{
     return __abstracted_reg_write(val, SCI_REG_TRIG_A_SEL, handle);
}
SCILIB int REG_VET_A_EN_GET(uint32_t *val, NI_HANDLE *handle)
{
     return __abstracted_reg_read(val, SCI_REG_VET_A_EN, handle);
}
SCILIB int REG_VET_A_EN_SET(uint32_t val, NI_HANDLE *handle)
{
     return __abstracted_reg_write(val, SCI_REG_VET_A_EN, handle);
}
SCILIB int REG_VET_B_EN_GET(uint32_t *val, NI_HANDLE *handle)
{
     return __abstracted_reg_read(val, SCI_REG_VET_B_EN, handle);
}
SCILIB int REG_VET_B_EN_SET(uint32_t val, NI_HANDLE *handle)
{
     return __abstracted_reg_write(val, SCI_REG_VET_B_EN, handle);
}
SCILIB int REG_VET_C_EN_GET(uint32_t *val, NI_HANDLE *handle)
{
     return __abstracted_reg_read(val, SCI_REG_VET_C_EN, handle);
}
SCILIB int REG_VET_C_EN_SET(uint32_t val, NI_HANDLE *handle)
{
     return __abstracted_reg_write(val, SCI_REG_VET_C_EN, handle);
}
SCILIB int REG_VET_D_EN_GET(uint32_t *val, NI_HANDLE *handle)
{
     return __abstracted_reg_read(val, SCI_REG_VET_D_EN, handle);
}
SCILIB int REG_VET_D_EN_SET(uint32_t val, NI_HANDLE *handle)
{
     return __abstracted_reg_write(val, SCI_REG_VET_D_EN, handle);
}
SCILIB int REG_SW_VET_A_GET(uint32_t *val, NI_HANDLE *handle)
{
     return __abstracted_reg_read(val, SCI_REG_SW_VET_A, handle);
}
SCILIB int REG_SW_VET_A_SET(uint32_t val, NI_HANDLE *handle)
{
     return __abstracted_reg_write(val, SCI_REG_SW_VET_A, handle);
}
SCILIB int REG_SW_VET_B_GET(uint32_t *val, NI_HANDLE *handle)
{
     return __abstracted_reg_read(val, SCI_REG_SW_VET_B, handle);
}
SCILIB int REG_SW_VET_B_SET(uint32_t val, NI_HANDLE *handle)
{
     return __abstracted_reg_write(val, SCI_REG_SW_VET_B, handle);
}
SCILIB int REG_SW_VET_C_GET(uint32_t *val, NI_HANDLE *handle)
{
     return __abstracted_reg_read(val, SCI_REG_SW_VET_C, handle);
}
SCILIB int REG_SW_VET_C_SET(uint32_t val, NI_HANDLE *handle)
{
     return __abstracted_reg_write(val, SCI_REG_SW_VET_C, handle);
}
SCILIB int REG_SW_VET_D_GET(uint32_t *val, NI_HANDLE *handle)
{
     return __abstracted_reg_read(val, SCI_REG_SW_VET_D, handle);
}
SCILIB int REG_SW_VET_D_SET(uint32_t val, NI_HANDLE *handle)
{
     return __abstracted_reg_write(val, SCI_REG_SW_VET_D, handle);
}
SCILIB int REG_TRIG_GBL_SEL_GET(uint32_t *val, NI_HANDLE *handle)
{
     return __abstracted_reg_read(val, SCI_REG_TRIG_GBL_SEL, handle);
}
SCILIB int REG_TRIG_GBL_SEL_SET(uint32_t val, NI_HANDLE *handle)
{
     return __abstracted_reg_write(val, SCI_REG_TRIG_GBL_SEL, handle);
}
SCILIB int REG_EXT_DELAY_GET(uint32_t *val, NI_HANDLE *handle)
{
     return __abstracted_reg_read(val, SCI_REG_EXT_DELAY, handle);
}
SCILIB int REG_EXT_DELAY_SET(uint32_t val, NI_HANDLE *handle)
{
     return __abstracted_reg_write(val, SCI_REG_EXT_DELAY, handle);
}
SCILIB int REG_SW_TRIG_FREQ_GET(uint32_t *val, NI_HANDLE *handle)
{
     return __abstracted_reg_read(val, SCI_REG_SW_TRIG_FREQ, handle);
}
SCILIB int REG_SW_TRIG_FREQ_SET(uint32_t val, NI_HANDLE *handle)
{
     return __abstracted_reg_write(val, SCI_REG_SW_TRIG_FREQ, handle);
}
SCILIB int REG_A_RATE_GET(uint32_t *val, NI_HANDLE *handle)
{
     return __abstracted_reg_read(val, SCI_REG_A_RATE, handle);
}
SCILIB int REG_A_RATE_SET(uint32_t val, NI_HANDLE *handle)
{
     return __abstracted_reg_write(val, SCI_REG_A_RATE, handle);
}
SCILIB int REG_B_RATE_GET(uint32_t *val, NI_HANDLE *handle)
{
     return __abstracted_reg_read(val, SCI_REG_B_RATE, handle);
}
SCILIB int REG_B_RATE_SET(uint32_t val, NI_HANDLE *handle)
{
     return __abstracted_reg_write(val, SCI_REG_B_RATE, handle);
}
SCILIB int REG_C_RATE_GET(uint32_t *val, NI_HANDLE *handle)
{
     return __abstracted_reg_read(val, SCI_REG_C_RATE, handle);
}
SCILIB int REG_C_RATE_SET(uint32_t val, NI_HANDLE *handle)
{
     return __abstracted_reg_write(val, SCI_REG_C_RATE, handle);
}
SCILIB int REG_D_RATE_GET(uint32_t *val, NI_HANDLE *handle)
{
     return __abstracted_reg_read(val, SCI_REG_D_RATE, handle);
}
SCILIB int REG_D_RATE_SET(uint32_t val, NI_HANDLE *handle)
{
     return __abstracted_reg_write(val, SCI_REG_D_RATE, handle);
}
SCILIB int REG_T0_COUNT_GET(uint32_t *val, NI_HANDLE *handle)
{
     return __abstracted_reg_read(val, SCI_REG_T0_COUNT, handle);
}
SCILIB int REG_T0_COUNT_SET(uint32_t val, NI_HANDLE *handle)
{
     return __abstracted_reg_write(val, SCI_REG_T0_COUNT, handle);
}
SCILIB int REG_A_TRG_GET(uint32_t *val, NI_HANDLE *handle)
{
     return __abstracted_reg_read(val, SCI_REG_A_TRG, handle);
}
SCILIB int REG_A_TRG_SET(uint32_t val, NI_HANDLE *handle)
{
     return __abstracted_reg_write(val, SCI_REG_A_TRG, handle);
}
SCILIB int REG_B_TRG_GET(uint32_t *val, NI_HANDLE *handle)
{
     return __abstracted_reg_read(val, SCI_REG_B_TRG, handle);
}
SCILIB int REG_B_TRG_SET(uint32_t val, NI_HANDLE *handle)
{
     return __abstracted_reg_write(val, SCI_REG_B_TRG, handle);
}
SCILIB int REG_C_TRG_GET(uint32_t *val, NI_HANDLE *handle)
{
     return __abstracted_reg_read(val, SCI_REG_C_TRG, handle);
}
SCILIB int REG_C_TRG_SET(uint32_t val, NI_HANDLE *handle)
{
     return __abstracted_reg_write(val, SCI_REG_C_TRG, handle);
}
SCILIB int REG_D_TRG_GET(uint32_t *val, NI_HANDLE *handle)
{
     return __abstracted_reg_read(val, SCI_REG_D_TRG, handle);
}
SCILIB int REG_D_TRG_SET(uint32_t val, NI_HANDLE *handle)
{
     return __abstracted_reg_write(val, SCI_REG_D_TRG, handle);
}
SCILIB int REG_RUNSTART_GET(uint32_t *val, NI_HANDLE *handle)
{
     return __abstracted_reg_read(val, SCI_REG_RUNSTART, handle);
}
SCILIB int REG_RUNSTART_SET(uint32_t val, NI_HANDLE *handle)
{
     return __abstracted_reg_write(val, SCI_REG_RUNSTART, handle);
}
SCILIB int REG_RUN_TIME_LSB_GET(uint32_t *val, NI_HANDLE *handle)
{
     return __abstracted_reg_read(val, SCI_REG_RUN_TIME_LSB, handle);
}
SCILIB int REG_RUN_TIME_LSB_SET(uint32_t val, NI_HANDLE *handle)
{
     return __abstracted_reg_write(val, SCI_REG_RUN_TIME_LSB, handle);
}
SCILIB int REG_RUN_TIME_MSB_GET(uint32_t *val, NI_HANDLE *handle)
{
     return __abstracted_reg_read(val, SCI_REG_RUN_TIME_MSB, handle);
}
SCILIB int REG_RUN_TIME_MSB_SET(uint32_t val, NI_HANDLE *handle)
{
     return __abstracted_reg_write(val, SCI_REG_RUN_TIME_MSB, handle);
}
SCILIB int REG_DEAD_TIME_LSB_GET(uint32_t *val, NI_HANDLE *handle)
{
     return __abstracted_reg_read(val, SCI_REG_DEAD_TIME_LSB, handle);
}
SCILIB int REG_DEAD_TIME_LSB_SET(uint32_t val, NI_HANDLE *handle)
{
     return __abstracted_reg_write(val, SCI_REG_DEAD_TIME_LSB, handle);
}
SCILIB int REG_DEAD_TIME_MSB_GET(uint32_t *val, NI_HANDLE *handle)
{
     return __abstracted_reg_read(val, SCI_REG_DEAD_TIME_MSB, handle);
}
SCILIB int REG_DEAD_TIME_MSB_SET(uint32_t val, NI_HANDLE *handle)
{
     return __abstracted_reg_write(val, SCI_REG_DEAD_TIME_MSB, handle);
}
SCILIB int REG_A_LOST_GET(uint32_t *val, NI_HANDLE *handle)
{
     return __abstracted_reg_read(val, SCI_REG_A_LOST, handle);
}
SCILIB int REG_A_LOST_SET(uint32_t val, NI_HANDLE *handle)
{
     return __abstracted_reg_write(val, SCI_REG_A_LOST, handle);
}
SCILIB int REG_B_LOST_GET(uint32_t *val, NI_HANDLE *handle)
{
     return __abstracted_reg_read(val, SCI_REG_B_LOST, handle);
}
SCILIB int REG_B_LOST_SET(uint32_t val, NI_HANDLE *handle)
{
     return __abstracted_reg_write(val, SCI_REG_B_LOST, handle);
}
SCILIB int REG_C_LOST_GET(uint32_t *val, NI_HANDLE *handle)
{
     return __abstracted_reg_read(val, SCI_REG_C_LOST, handle);
}
SCILIB int REG_C_LOST_SET(uint32_t val, NI_HANDLE *handle)
{
     return __abstracted_reg_write(val, SCI_REG_C_LOST, handle);
}
SCILIB int REG_D_LOST_GET(uint32_t *val, NI_HANDLE *handle)
{
     return __abstracted_reg_read(val, SCI_REG_D_LOST, handle);
}
SCILIB int REG_D_LOST_SET(uint32_t val, NI_HANDLE *handle)
{
     return __abstracted_reg_write(val, SCI_REG_D_LOST, handle);
}
SCILIB int REG_T0_SOFT_FREQ_GET(uint32_t *val, NI_HANDLE *handle)
{
     return __abstracted_reg_read(val, SCI_REG_T0_SOFT_FREQ, handle);
}
SCILIB int REG_T0_SOFT_FREQ_SET(uint32_t val, NI_HANDLE *handle)
{
     return __abstracted_reg_write(val, SCI_REG_T0_SOFT_FREQ, handle);
}
SCILIB int REG_T0_SEL_GET(uint32_t *val, NI_HANDLE *handle)
{
     return __abstracted_reg_read(val, SCI_REG_T0_SEL, handle);
}
SCILIB int REG_T0_SEL_SET(uint32_t val, NI_HANDLE *handle)
{
     return __abstracted_reg_write(val, SCI_REG_T0_SEL, handle);
}
SCILIB int REG_HOLD_TIME_GET(uint32_t *val, NI_HANDLE *handle)
{
     return __abstracted_reg_read(val, SCI_REG_HOLD_TIME, handle);
}
SCILIB int REG_HOLD_TIME_SET(uint32_t val, NI_HANDLE *handle)
{
     return __abstracted_reg_write(val, SCI_REG_HOLD_TIME, handle);
}
SCILIB int REG_FR_IFP_GET(uint32_t *val, NI_HANDLE *handle)
{
     return __abstracted_reg_read(val, SCI_REG_FR_IFP, handle);
}
SCILIB int REG_FR_IFP_SET(uint32_t val, NI_HANDLE *handle)
{
     return __abstracted_reg_write(val, SCI_REG_FR_IFP, handle);
}
SCILIB int REG_FR_LIMIT_GET(uint32_t *val, NI_HANDLE *handle)
{
     return __abstracted_reg_read(val, SCI_REG_FR_LIMIT, handle);
}
SCILIB int REG_FR_LIMIT_SET(uint32_t val, NI_HANDLE *handle)
{
     return __abstracted_reg_write(val, SCI_REG_FR_LIMIT, handle);
}
SCILIB int REG_FR_IFP2_GET(uint32_t *val, NI_HANDLE *handle)
{
     return __abstracted_reg_read(val, SCI_REG_FR_IFP2, handle);
}
SCILIB int REG_FR_IFP2_SET(uint32_t val, NI_HANDLE *handle)
{
     return __abstracted_reg_write(val, SCI_REG_FR_IFP2, handle);
}
SCILIB int REG_FR_MODE_GET(uint32_t *val, NI_HANDLE *handle)
{
     return __abstracted_reg_read(val, SCI_REG_FR_MODE, handle);
}
SCILIB int REG_FR_MODE_SET(uint32_t val, NI_HANDLE *handle)
{
     return __abstracted_reg_write(val, SCI_REG_FR_MODE, handle);
}
SCILIB int REG_FR_DBG1_GET(uint32_t *val, NI_HANDLE *handle)
{
     return __abstracted_reg_read(val, SCI_REG_FR_DBG1, handle);
}
SCILIB int REG_FR_DBG1_SET(uint32_t val, NI_HANDLE *handle)
{
     return __abstracted_reg_write(val, SCI_REG_FR_DBG1, handle);
}
SCILIB int REG_FR_DBG2_GET(uint32_t *val, NI_HANDLE *handle)
{
     return __abstracted_reg_read(val, SCI_REG_FR_DBG2, handle);
}
SCILIB int REG_FR_DBG2_SET(uint32_t val, NI_HANDLE *handle)
{
     return __abstracted_reg_write(val, SCI_REG_FR_DBG2, handle);
}
SCILIB int REG_VALIDATION_CFG_GET(uint32_t *val, NI_HANDLE *handle)
{
     return __abstracted_reg_read(val, SCI_REG_VALIDATION_CFG, handle);
}
SCILIB int REG_VALIDATION_CFG_SET(uint32_t val, NI_HANDLE *handle)
{
     return __abstracted_reg_write(val, SCI_REG_VALIDATION_CFG, handle);
}
SCILIB int REG_HV_ON_GET(uint32_t *val, NI_HANDLE *handle)
{
     return __abstracted_reg_read(val, SCI_REG_HV_ON, handle);
}
SCILIB int REG_HV_ON_SET(uint32_t val, NI_HANDLE *handle)
{
     return __abstracted_reg_write(val, SCI_REG_HV_ON, handle);
}
SCILIB int REG_HV_EMERGENCY_GET(uint32_t *val, NI_HANDLE *handle)
{
     return __abstracted_reg_read(val, SCI_REG_HV_EMERGENCY, handle);
}
SCILIB int REG_HV_EMERGENCY_SET(uint32_t val, NI_HANDLE *handle)
{
     return __abstracted_reg_write(val, SCI_REG_HV_EMERGENCY, handle);
}
SCILIB int REG_HV_VOUT_GET(uint32_t *val, NI_HANDLE *handle)
{
     return __abstracted_reg_read(val, SCI_REG_HV_VOUT, handle);
}
SCILIB int REG_HV_VOUT_SET(uint32_t val, NI_HANDLE *handle)
{
     return __abstracted_reg_write(val, SCI_REG_HV_VOUT, handle);
}
SCILIB int REG_HV_ENTCOMP_GET(uint32_t *val, NI_HANDLE *handle)
{
     return __abstracted_reg_read(val, SCI_REG_HV_ENTCOMP, handle);
}
SCILIB int REG_HV_ENTCOMP_SET(uint32_t val, NI_HANDLE *handle)
{
     return __abstracted_reg_write(val, SCI_REG_HV_ENTCOMP, handle);
}
SCILIB int REG_HV_TM_GET(uint32_t *val, NI_HANDLE *handle)
{
     return __abstracted_reg_read(val, SCI_REG_HV_TM, handle);
}
SCILIB int REG_HV_TM_SET(uint32_t val, NI_HANDLE *handle)
{
     return __abstracted_reg_write(val, SCI_REG_HV_TM, handle);
}
SCILIB int REG_HV_TQ_GET(uint32_t *val, NI_HANDLE *handle)
{
     return __abstracted_reg_read(val, SCI_REG_HV_TQ, handle);
}
SCILIB int REG_HV_TQ_SET(uint32_t val, NI_HANDLE *handle)
{
     return __abstracted_reg_write(val, SCI_REG_HV_TQ, handle);
}
SCILIB int REG_HV_TCOEF_GET(uint32_t *val, NI_HANDLE *handle)
{
     return __abstracted_reg_read(val, SCI_REG_HV_TCOEF, handle);
}
SCILIB int REG_HV_TCOEF_SET(uint32_t val, NI_HANDLE *handle)
{
     return __abstracted_reg_write(val, SCI_REG_HV_TCOEF, handle);
}
SCILIB int REG_HV_IMAX_GET(uint32_t *val, NI_HANDLE *handle)
{
     return __abstracted_reg_read(val, SCI_REG_HV_IMAX, handle);
}
SCILIB int REG_HV_IMAX_SET(uint32_t val, NI_HANDLE *handle)
{
     return __abstracted_reg_write(val, SCI_REG_HV_IMAX, handle);
}
SCILIB int REG_HV_RAMP_GET(uint32_t *val, NI_HANDLE *handle)
{
     return __abstracted_reg_read(val, SCI_REG_HV_RAMP, handle);
}
SCILIB int REG_HV_RAMP_SET(uint32_t val, NI_HANDLE *handle)
{
     return __abstracted_reg_write(val, SCI_REG_HV_RAMP, handle);
}
SCILIB int REG_HV_VMAX_GET(uint32_t *val, NI_HANDLE *handle)
{
     return __abstracted_reg_read(val, SCI_REG_HV_VMAX, handle);
}
SCILIB int REG_HV_VMAX_SET(uint32_t val, NI_HANDLE *handle)
{
     return __abstracted_reg_write(val, SCI_REG_HV_VMAX, handle);
}
SCILIB int REG_HV_MSTATUS_GET(uint32_t *val, NI_HANDLE *handle)
{
     return __abstracted_reg_read(val, SCI_REG_HV_MSTATUS, handle);
}
SCILIB int REG_HV_MSTATUS_SET(uint32_t val, NI_HANDLE *handle)
{
     return __abstracted_reg_write(val, SCI_REG_HV_MSTATUS, handle);
}
SCILIB int REG_HV_MVOUT_GET(uint32_t *val, NI_HANDLE *handle)
{
     return __abstracted_reg_read(val, SCI_REG_HV_MVOUT, handle);
}
SCILIB int REG_HV_MVOUT_SET(uint32_t val, NI_HANDLE *handle)
{
     return __abstracted_reg_write(val, SCI_REG_HV_MVOUT, handle);
}
SCILIB int REG_HV_MTEMP_GET(uint32_t *val, NI_HANDLE *handle)
{
     return __abstracted_reg_read(val, SCI_REG_HV_MTEMP, handle);
}
SCILIB int REG_HV_MTEMP_SET(uint32_t val, NI_HANDLE *handle)
{
     return __abstracted_reg_write(val, SCI_REG_HV_MTEMP, handle);
}
SCILIB int REG_HV_MVTARGET_GET(uint32_t *val, NI_HANDLE *handle)
{
     return __abstracted_reg_read(val, SCI_REG_HV_MVTARGET, handle);
}
SCILIB int REG_HV_MVTARGET_SET(uint32_t val, NI_HANDLE *handle)
{
     return __abstracted_reg_write(val, SCI_REG_HV_MVTARGET, handle);
}
SCILIB int REG_HV_MAVTARGET_GET(uint32_t *val, NI_HANDLE *handle)
{
     return __abstracted_reg_read(val, SCI_REG_HV_MAVTARGET, handle);
}
SCILIB int REG_HV_MAVTARGET_SET(uint32_t val, NI_HANDLE *handle)
{
     return __abstracted_reg_write(val, SCI_REG_HV_MAVTARGET, handle);
}
SCILIB int REG_T_SENS1_GET(uint32_t *val, NI_HANDLE *handle)
{
     return __abstracted_reg_read(val, SCI_REG_T_SENS1, handle);
}
SCILIB int REG_T_SENS1_SET(uint32_t val, NI_HANDLE *handle)
{
     return __abstracted_reg_write(val, SCI_REG_T_SENS1, handle);
}
SCILIB int REG_T_SENS2_GET(uint32_t *val, NI_HANDLE *handle)
{
     return __abstracted_reg_read(val, SCI_REG_T_SENS2, handle);
}
SCILIB int REG_T_SENS2_SET(uint32_t val, NI_HANDLE *handle)
{
     return __abstracted_reg_write(val, SCI_REG_T_SENS2, handle);
}
SCILIB int REG_HV_MIOUT_GET(uint32_t *val, NI_HANDLE *handle)
{
     return __abstracted_reg_read(val, SCI_REG_HV_MIOUT, handle);
}
SCILIB int REG_HV_MIOUT_SET(uint32_t val, NI_HANDLE *handle)
{
     return __abstracted_reg_write(val, SCI_REG_HV_MIOUT, handle);
}
SCILIB int REG_TRIGGER_OUT_W_GET(uint32_t *val, NI_HANDLE *handle)
{
     return __abstracted_reg_read(val, SCI_REG_TRIGGER_OUT_W, handle);
}
SCILIB int REG_TRIGGER_OUT_W_SET(uint32_t val, NI_HANDLE *handle)
{
     return __abstracted_reg_write(val, SCI_REG_TRIGGER_OUT_W, handle);
}
SCILIB int REG_T0SW_GET(uint32_t *val, NI_HANDLE *handle)
{
     return __abstracted_reg_read(val, SCI_REG_T0SW, handle);
}
SCILIB int REG_T0SW_SET(uint32_t val, NI_HANDLE *handle)
{
     return __abstracted_reg_write(val, SCI_REG_T0SW, handle);
}
SCILIB int REG_GTS_RESSEL_GET(uint32_t *val, NI_HANDLE *handle)
{
     return __abstracted_reg_read(val, SCI_REG_GTS_RESSEL, handle);
}
SCILIB int REG_GTS_RESSEL_SET(uint32_t val, NI_HANDLE *handle)
{
     return __abstracted_reg_write(val, SCI_REG_GTS_RESSEL, handle);
}
SCILIB int REG_TRIG_MASK_A_GET(uint32_t *val, NI_HANDLE *handle)
{
     return __abstracted_reg_read(val, SCI_REG_TRIG_MASK_A, handle);
}
SCILIB int REG_TRIG_MASK_A_SET(uint32_t val, NI_HANDLE *handle)
{
     return __abstracted_reg_write(val, SCI_REG_TRIG_MASK_A, handle);
}
SCILIB int REG_TRIG_MASK_B_GET(uint32_t *val, NI_HANDLE *handle)
{
     return __abstracted_reg_read(val, SCI_REG_TRIG_MASK_B, handle);
}
SCILIB int REG_TRIG_MASK_B_SET(uint32_t val, NI_HANDLE *handle)
{
     return __abstracted_reg_write(val, SCI_REG_TRIG_MASK_B, handle);
}
SCILIB int REG_TRIG_MASK_C_GET(uint32_t *val, NI_HANDLE *handle)
{
     return __abstracted_reg_read(val, SCI_REG_TRIG_MASK_C, handle);
}
SCILIB int REG_TRIG_MASK_C_SET(uint32_t val, NI_HANDLE *handle)
{
     return __abstracted_reg_write(val, SCI_REG_TRIG_MASK_C, handle);
}
SCILIB int REG_TRIG_MASK_D_GET(uint32_t *val, NI_HANDLE *handle)
{
     return __abstracted_reg_read(val, SCI_REG_TRIG_MASK_D, handle);
}
SCILIB int REG_TRIG_MASK_D_SET(uint32_t val, NI_HANDLE *handle)
{
     return __abstracted_reg_write(val, SCI_REG_TRIG_MASK_D, handle);
}
SCILIB int REG_T0_RESET_ON_START_GET(uint32_t *val, NI_HANDLE *handle)
{
     return __abstracted_reg_read(val, SCI_REG_T0_RESET_ON_START, handle);
}
SCILIB int REG_T0_RESET_ON_START_SET(uint32_t val, NI_HANDLE *handle)
{
     return __abstracted_reg_write(val, SCI_REG_T0_RESET_ON_START, handle);
}
SCILIB int REG_ISRUNNING_GET(uint32_t *val, NI_HANDLE *handle)
{
     return __abstracted_reg_read(val, SCI_REG_ISRUNNING, handle);
}
SCILIB int REG_ISRUNNING_SET(uint32_t val, NI_HANDLE *handle)
{
     return __abstracted_reg_write(val, SCI_REG_ISRUNNING, handle);
}
SCILIB int REG_VETO_WAIT_RUN_GET(uint32_t *val, NI_HANDLE *handle)
{
     return __abstracted_reg_read(val, SCI_REG_VETO_WAIT_RUN, handle);
}
SCILIB int REG_VETO_WAIT_RUN_SET(uint32_t val, NI_HANDLE *handle)
{
     return __abstracted_reg_write(val, SCI_REG_VETO_WAIT_RUN, handle);
}
SCILIB int REG_GBL_EN_VETO_EXT_GET(uint32_t *val, NI_HANDLE *handle)
{
     return __abstracted_reg_read(val, SCI_REG_GBL_EN_VETO_EXT, handle);
}
SCILIB int REG_GBL_EN_VETO_EXT_SET(uint32_t val, NI_HANDLE *handle)
{
     return __abstracted_reg_write(val, SCI_REG_GBL_EN_VETO_EXT, handle);
}
SCILIB int REG_INVETO_GET(uint32_t *val, NI_HANDLE *handle)
{
     return __abstracted_reg_read(val, SCI_REG_INVETO, handle);
}
SCILIB int REG_INVETO_SET(uint32_t val, NI_HANDLE *handle)
{
     return __abstracted_reg_write(val, SCI_REG_INVETO, handle);
}
SCILIB int REG_TRG_OUT_MONOSTABLE_EN_GET(uint32_t *val, NI_HANDLE *handle)
{
     return __abstracted_reg_read(val, SCI_REG_TRG_OUT_MONOSTABLE_EN, handle);
}
SCILIB int REG_TRG_OUT_MONOSTABLE_EN_SET(uint32_t val, NI_HANDLE *handle)
{
     return __abstracted_reg_write(val, SCI_REG_TRG_OUT_MONOSTABLE_EN, handle);
}
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

SCILIB int Citiroc_CitirocCfg0_CONFIG(char *incfg, NI_HANDLE *handle)
{
int i,j;
uint32_t bitstream[1152];
uint32_t cfg[32];
int result;
if (strlen(incfg) != 1144) return -1;
for (i=0;i<1152;i++) bitstream[i] = 0;
for (i=0;i<1144;i++)
{
	bitstream[i] = (incfg[i] == '0' ? 0:1);
}
for (i=0;i<36;i++)
{
	cfg[i]=0;
	for (j=0;j<32;j++)
		cfg[i] += (bitstream[i*32+j] << j);
}
result=0;
	result+=__abstracted_reg_write(cfg[0],SCI_REG_CitirocCfg0_REG_CFG0, handle);
	result+=__abstracted_reg_write(cfg[1],SCI_REG_CitirocCfg0_REG_CFG1, handle);
	result+=__abstracted_reg_write(cfg[2],SCI_REG_CitirocCfg0_REG_CFG2, handle);
	result+=__abstracted_reg_write(cfg[3],SCI_REG_CitirocCfg0_REG_CFG3, handle);
	result+=__abstracted_reg_write(cfg[4],SCI_REG_CitirocCfg0_REG_CFG4, handle);
	result+=__abstracted_reg_write(cfg[5],SCI_REG_CitirocCfg0_REG_CFG5, handle);
	result+=__abstracted_reg_write(cfg[6],SCI_REG_CitirocCfg0_REG_CFG6, handle);
	result+=__abstracted_reg_write(cfg[7],SCI_REG_CitirocCfg0_REG_CFG7, handle);
	result+=__abstracted_reg_write(cfg[8],SCI_REG_CitirocCfg0_REG_CFG8, handle);
	result+=__abstracted_reg_write(cfg[9],SCI_REG_CitirocCfg0_REG_CFG9, handle);
	result+=__abstracted_reg_write(cfg[10],SCI_REG_CitirocCfg0_REG_CFG10, handle);
	result+=__abstracted_reg_write(cfg[11],SCI_REG_CitirocCfg0_REG_CFG11, handle);
	result+=__abstracted_reg_write(cfg[12],SCI_REG_CitirocCfg0_REG_CFG12, handle);
	result+=__abstracted_reg_write(cfg[13],SCI_REG_CitirocCfg0_REG_CFG13, handle);
	result+=__abstracted_reg_write(cfg[14],SCI_REG_CitirocCfg0_REG_CFG14, handle);
	result+=__abstracted_reg_write(cfg[15],SCI_REG_CitirocCfg0_REG_CFG15, handle);
	result+=__abstracted_reg_write(cfg[16],SCI_REG_CitirocCfg0_REG_CFG16, handle);
	result+=__abstracted_reg_write(cfg[17],SCI_REG_CitirocCfg0_REG_CFG17, handle);
	result+=__abstracted_reg_write(cfg[18],SCI_REG_CitirocCfg0_REG_CFG18, handle);
	result+=__abstracted_reg_write(cfg[19],SCI_REG_CitirocCfg0_REG_CFG19, handle);
	result+=__abstracted_reg_write(0,SCI_REG_CitirocCfg0_START_REG_CFG, handle);
	result+=__abstracted_reg_write(1,SCI_REG_CitirocCfg0_START_REG_CFG, handle);
	result+=__abstracted_reg_write(0,SCI_REG_CitirocCfg0_START_REG_CFG, handle);
if (result!=0) return -1; else return 0;

}
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

SCILIB int Citiroc_CitirocCfg0_CONFIG_MON(char *incfg, NI_HANDLE *handle)
{
int i,j;
uint32_t bitstream[1024];
uint32_t cfg[32];
int result;
if (strlen(incfg) != 256) return -1;
for (i=0;i<1024;i++) bitstream[i] = 0;
for (i=0;i<256;i++)
{
	bitstream[i] = (incfg[i] == '0' ? 0:1);
}
for (i=0;i<20;i++)
{
	cfg[i]=0;
	for (j=0;j<32;j++)
		cfg[i] += (bitstream[i*32+j] << j);
}
result=0;
	result+=__abstracted_reg_write(cfg[0],SCI_REG_CitirocCfg0_REG_CFG0, handle);
	result+=__abstracted_reg_write(cfg[1],SCI_REG_CitirocCfg0_REG_CFG1, handle);
	result+=__abstracted_reg_write(cfg[2],SCI_REG_CitirocCfg0_REG_CFG2, handle);
	result+=__abstracted_reg_write(cfg[3],SCI_REG_CitirocCfg0_REG_CFG3, handle);
	result+=__abstracted_reg_write(cfg[4],SCI_REG_CitirocCfg0_REG_CFG4, handle);
	result+=__abstracted_reg_write(cfg[5],SCI_REG_CitirocCfg0_REG_CFG5, handle);
	result+=__abstracted_reg_write(cfg[6],SCI_REG_CitirocCfg0_REG_CFG6, handle);
	result+=__abstracted_reg_write(cfg[7],SCI_REG_CitirocCfg0_REG_CFG7, handle);
	result+=__abstracted_reg_write(cfg[8],SCI_REG_CitirocCfg0_REG_CFG8, handle);
	result+=__abstracted_reg_write(cfg[9],SCI_REG_CitirocCfg0_REG_CFG9, handle);
	result+=__abstracted_reg_write(cfg[10],SCI_REG_CitirocCfg0_REG_CFG10, handle);
	result+=__abstracted_reg_write(cfg[11],SCI_REG_CitirocCfg0_REG_CFG11, handle);
	result+=__abstracted_reg_write(cfg[12],SCI_REG_CitirocCfg0_REG_CFG12, handle);
	result+=__abstracted_reg_write(cfg[13],SCI_REG_CitirocCfg0_REG_CFG13, handle);
	result+=__abstracted_reg_write(cfg[14],SCI_REG_CitirocCfg0_REG_CFG14, handle);
	result+=__abstracted_reg_write(cfg[15],SCI_REG_CitirocCfg0_REG_CFG15, handle);
	result+=__abstracted_reg_write(cfg[16],SCI_REG_CitirocCfg0_REG_CFG16, handle);
	result+=__abstracted_reg_write(cfg[17],SCI_REG_CitirocCfg0_REG_CFG17, handle);
	result+=__abstracted_reg_write(cfg[18],SCI_REG_CitirocCfg0_REG_CFG18, handle);
	result+=__abstracted_reg_write(cfg[19],SCI_REG_CitirocCfg0_REG_CFG19, handle);
	result+=__abstracted_reg_write(0,SCI_REG_CitirocCfg0_START_REG_CFG, handle);
	result+=__abstracted_reg_write(2,SCI_REG_CitirocCfg0_START_REG_CFG, handle);
	result+=__abstracted_reg_write(0,SCI_REG_CitirocCfg0_START_REG_CFG, handle);
if (result!=0) return -1; else return 0;

}
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

SCILIB int Citiroc_CitirocCfg1_CONFIG(char *incfg, NI_HANDLE *handle)
{
int i,j;
uint32_t bitstream[1152];
uint32_t cfg[32];
int result;
if (strlen(incfg) != 1144) return -1;
for (i=0;i<1152;i++) bitstream[i] = 0;
for (i=0;i<1144;i++)
{
	bitstream[i] = (incfg[i] == '0' ? 0:1);
}
for (i=0;i<36;i++)
{
	cfg[i]=0;
	for (j=0;j<32;j++)
		cfg[i] += (bitstream[i*32+j] << j);
}
result=0;
	result+=__abstracted_reg_write(cfg[0],SCI_REG_CitirocCfg1_REG_CFG0, handle);
	result+=__abstracted_reg_write(cfg[1],SCI_REG_CitirocCfg1_REG_CFG1, handle);
	result+=__abstracted_reg_write(cfg[2],SCI_REG_CitirocCfg1_REG_CFG2, handle);
	result+=__abstracted_reg_write(cfg[3],SCI_REG_CitirocCfg1_REG_CFG3, handle);
	result+=__abstracted_reg_write(cfg[4],SCI_REG_CitirocCfg1_REG_CFG4, handle);
	result+=__abstracted_reg_write(cfg[5],SCI_REG_CitirocCfg1_REG_CFG5, handle);
	result+=__abstracted_reg_write(cfg[6],SCI_REG_CitirocCfg1_REG_CFG6, handle);
	result+=__abstracted_reg_write(cfg[7],SCI_REG_CitirocCfg1_REG_CFG7, handle);
	result+=__abstracted_reg_write(cfg[8],SCI_REG_CitirocCfg1_REG_CFG8, handle);
	result+=__abstracted_reg_write(cfg[9],SCI_REG_CitirocCfg1_REG_CFG9, handle);
	result+=__abstracted_reg_write(cfg[10],SCI_REG_CitirocCfg1_REG_CFG10, handle);
	result+=__abstracted_reg_write(cfg[11],SCI_REG_CitirocCfg1_REG_CFG11, handle);
	result+=__abstracted_reg_write(cfg[12],SCI_REG_CitirocCfg1_REG_CFG12, handle);
	result+=__abstracted_reg_write(cfg[13],SCI_REG_CitirocCfg1_REG_CFG13, handle);
	result+=__abstracted_reg_write(cfg[14],SCI_REG_CitirocCfg1_REG_CFG14, handle);
	result+=__abstracted_reg_write(cfg[15],SCI_REG_CitirocCfg1_REG_CFG15, handle);
	result+=__abstracted_reg_write(cfg[16],SCI_REG_CitirocCfg1_REG_CFG16, handle);
	result+=__abstracted_reg_write(cfg[17],SCI_REG_CitirocCfg1_REG_CFG17, handle);
	result+=__abstracted_reg_write(cfg[18],SCI_REG_CitirocCfg1_REG_CFG18, handle);
	result+=__abstracted_reg_write(cfg[19],SCI_REG_CitirocCfg1_REG_CFG19, handle);
	result+=__abstracted_reg_write(0,SCI_REG_CitirocCfg1_START_REG_CFG, handle);
	result+=__abstracted_reg_write(1,SCI_REG_CitirocCfg1_START_REG_CFG, handle);
	result+=__abstracted_reg_write(0,SCI_REG_CitirocCfg1_START_REG_CFG, handle);
if (result!=0) return -1; else return 0;

}
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

SCILIB int Citiroc_CitirocCfg1_CONFIG_MON(char *incfg, NI_HANDLE *handle)
{
int i,j;
uint32_t bitstream[1024];
uint32_t cfg[32];
int result;
if (strlen(incfg) != 256) return -1;
for (i=0;i<1024;i++) bitstream[i] = 0;
for (i=0;i<256;i++)
{
	bitstream[i] = (incfg[i] == '0' ? 0:1);
}
for (i=0;i<20;i++)
{
	cfg[i]=0;
	for (j=0;j<32;j++)
		cfg[i] += (bitstream[i*32+j] << j);
}
result=0;
	result+=__abstracted_reg_write(cfg[0],SCI_REG_CitirocCfg1_REG_CFG0, handle);
	result+=__abstracted_reg_write(cfg[1],SCI_REG_CitirocCfg1_REG_CFG1, handle);
	result+=__abstracted_reg_write(cfg[2],SCI_REG_CitirocCfg1_REG_CFG2, handle);
	result+=__abstracted_reg_write(cfg[3],SCI_REG_CitirocCfg1_REG_CFG3, handle);
	result+=__abstracted_reg_write(cfg[4],SCI_REG_CitirocCfg1_REG_CFG4, handle);
	result+=__abstracted_reg_write(cfg[5],SCI_REG_CitirocCfg1_REG_CFG5, handle);
	result+=__abstracted_reg_write(cfg[6],SCI_REG_CitirocCfg1_REG_CFG6, handle);
	result+=__abstracted_reg_write(cfg[7],SCI_REG_CitirocCfg1_REG_CFG7, handle);
	result+=__abstracted_reg_write(cfg[8],SCI_REG_CitirocCfg1_REG_CFG8, handle);
	result+=__abstracted_reg_write(cfg[9],SCI_REG_CitirocCfg1_REG_CFG9, handle);
	result+=__abstracted_reg_write(cfg[10],SCI_REG_CitirocCfg1_REG_CFG10, handle);
	result+=__abstracted_reg_write(cfg[11],SCI_REG_CitirocCfg1_REG_CFG11, handle);
	result+=__abstracted_reg_write(cfg[12],SCI_REG_CitirocCfg1_REG_CFG12, handle);
	result+=__abstracted_reg_write(cfg[13],SCI_REG_CitirocCfg1_REG_CFG13, handle);
	result+=__abstracted_reg_write(cfg[14],SCI_REG_CitirocCfg1_REG_CFG14, handle);
	result+=__abstracted_reg_write(cfg[15],SCI_REG_CitirocCfg1_REG_CFG15, handle);
	result+=__abstracted_reg_write(cfg[16],SCI_REG_CitirocCfg1_REG_CFG16, handle);
	result+=__abstracted_reg_write(cfg[17],SCI_REG_CitirocCfg1_REG_CFG17, handle);
	result+=__abstracted_reg_write(cfg[18],SCI_REG_CitirocCfg1_REG_CFG18, handle);
	result+=__abstracted_reg_write(cfg[19],SCI_REG_CitirocCfg1_REG_CFG19, handle);
	result+=__abstracted_reg_write(0,SCI_REG_CitirocCfg1_START_REG_CFG, handle);
	result+=__abstracted_reg_write(2,SCI_REG_CitirocCfg1_START_REG_CFG, handle);
	result+=__abstracted_reg_write(0,SCI_REG_CitirocCfg1_START_REG_CFG, handle);
if (result!=0) return -1; else return 0;

}
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

SCILIB int Citiroc_CitirocCfg2_CONFIG(char *incfg, NI_HANDLE *handle)
{
int i,j;
uint32_t bitstream[1152];
uint32_t cfg[32];
int result;
if (strlen(incfg) != 1144) return -1;
for (i=0;i<1152;i++) bitstream[i] = 0;
for (i=0;i<1144;i++)
{
	bitstream[i] = (incfg[i] == '0' ? 0:1);
}
for (i=0;i<36;i++)
{
	cfg[i]=0;
	for (j=0;j<32;j++)
		cfg[i] += (bitstream[i*32+j] << j);
}
result=0;
	result+=__abstracted_reg_write(cfg[0],SCI_REG_CitirocCfg2_REG_CFG0, handle);
	result+=__abstracted_reg_write(cfg[1],SCI_REG_CitirocCfg2_REG_CFG1, handle);
	result+=__abstracted_reg_write(cfg[2],SCI_REG_CitirocCfg2_REG_CFG2, handle);
	result+=__abstracted_reg_write(cfg[3],SCI_REG_CitirocCfg2_REG_CFG3, handle);
	result+=__abstracted_reg_write(cfg[4],SCI_REG_CitirocCfg2_REG_CFG4, handle);
	result+=__abstracted_reg_write(cfg[5],SCI_REG_CitirocCfg2_REG_CFG5, handle);
	result+=__abstracted_reg_write(cfg[6],SCI_REG_CitirocCfg2_REG_CFG6, handle);
	result+=__abstracted_reg_write(cfg[7],SCI_REG_CitirocCfg2_REG_CFG7, handle);
	result+=__abstracted_reg_write(cfg[8],SCI_REG_CitirocCfg2_REG_CFG8, handle);
	result+=__abstracted_reg_write(cfg[9],SCI_REG_CitirocCfg2_REG_CFG9, handle);
	result+=__abstracted_reg_write(cfg[10],SCI_REG_CitirocCfg2_REG_CFG10, handle);
	result+=__abstracted_reg_write(cfg[11],SCI_REG_CitirocCfg2_REG_CFG11, handle);
	result+=__abstracted_reg_write(cfg[12],SCI_REG_CitirocCfg2_REG_CFG12, handle);
	result+=__abstracted_reg_write(cfg[13],SCI_REG_CitirocCfg2_REG_CFG13, handle);
	result+=__abstracted_reg_write(cfg[14],SCI_REG_CitirocCfg2_REG_CFG14, handle);
	result+=__abstracted_reg_write(cfg[15],SCI_REG_CitirocCfg2_REG_CFG15, handle);
	result+=__abstracted_reg_write(cfg[16],SCI_REG_CitirocCfg2_REG_CFG16, handle);
	result+=__abstracted_reg_write(cfg[17],SCI_REG_CitirocCfg2_REG_CFG17, handle);
	result+=__abstracted_reg_write(cfg[18],SCI_REG_CitirocCfg2_REG_CFG18, handle);
	result+=__abstracted_reg_write(cfg[19],SCI_REG_CitirocCfg2_REG_CFG19, handle);
	result+=__abstracted_reg_write(0,SCI_REG_CitirocCfg2_START_REG_CFG, handle);
	result+=__abstracted_reg_write(1,SCI_REG_CitirocCfg2_START_REG_CFG, handle);
	result+=__abstracted_reg_write(0,SCI_REG_CitirocCfg2_START_REG_CFG, handle);
if (result!=0) return -1; else return 0;

}
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

SCILIB int Citiroc_CitirocCfg2_CONFIG_MON(char *incfg, NI_HANDLE *handle)
{
int i,j;
uint32_t bitstream[1024];
uint32_t cfg[32];
int result;
if (strlen(incfg) != 256) return -1;
for (i=0;i<1024;i++) bitstream[i] = 0;
for (i=0;i<256;i++)
{
	bitstream[i] = (incfg[i] == '0' ? 0:1);
}
for (i=0;i<20;i++)
{
	cfg[i]=0;
	for (j=0;j<32;j++)
		cfg[i] += (bitstream[i*32+j] << j);
}
result=0;
	result+=__abstracted_reg_write(cfg[0],SCI_REG_CitirocCfg2_REG_CFG0, handle);
	result+=__abstracted_reg_write(cfg[1],SCI_REG_CitirocCfg2_REG_CFG1, handle);
	result+=__abstracted_reg_write(cfg[2],SCI_REG_CitirocCfg2_REG_CFG2, handle);
	result+=__abstracted_reg_write(cfg[3],SCI_REG_CitirocCfg2_REG_CFG3, handle);
	result+=__abstracted_reg_write(cfg[4],SCI_REG_CitirocCfg2_REG_CFG4, handle);
	result+=__abstracted_reg_write(cfg[5],SCI_REG_CitirocCfg2_REG_CFG5, handle);
	result+=__abstracted_reg_write(cfg[6],SCI_REG_CitirocCfg2_REG_CFG6, handle);
	result+=__abstracted_reg_write(cfg[7],SCI_REG_CitirocCfg2_REG_CFG7, handle);
	result+=__abstracted_reg_write(cfg[8],SCI_REG_CitirocCfg2_REG_CFG8, handle);
	result+=__abstracted_reg_write(cfg[9],SCI_REG_CitirocCfg2_REG_CFG9, handle);
	result+=__abstracted_reg_write(cfg[10],SCI_REG_CitirocCfg2_REG_CFG10, handle);
	result+=__abstracted_reg_write(cfg[11],SCI_REG_CitirocCfg2_REG_CFG11, handle);
	result+=__abstracted_reg_write(cfg[12],SCI_REG_CitirocCfg2_REG_CFG12, handle);
	result+=__abstracted_reg_write(cfg[13],SCI_REG_CitirocCfg2_REG_CFG13, handle);
	result+=__abstracted_reg_write(cfg[14],SCI_REG_CitirocCfg2_REG_CFG14, handle);
	result+=__abstracted_reg_write(cfg[15],SCI_REG_CitirocCfg2_REG_CFG15, handle);
	result+=__abstracted_reg_write(cfg[16],SCI_REG_CitirocCfg2_REG_CFG16, handle);
	result+=__abstracted_reg_write(cfg[17],SCI_REG_CitirocCfg2_REG_CFG17, handle);
	result+=__abstracted_reg_write(cfg[18],SCI_REG_CitirocCfg2_REG_CFG18, handle);
	result+=__abstracted_reg_write(cfg[19],SCI_REG_CitirocCfg2_REG_CFG19, handle);
	result+=__abstracted_reg_write(0,SCI_REG_CitirocCfg2_START_REG_CFG, handle);
	result+=__abstracted_reg_write(2,SCI_REG_CitirocCfg2_START_REG_CFG, handle);
	result+=__abstracted_reg_write(0,SCI_REG_CitirocCfg2_START_REG_CFG, handle);
if (result!=0) return -1; else return 0;

}
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

SCILIB int Citiroc_CitirocCfg3_CONFIG(char *incfg, NI_HANDLE *handle)
{
int i,j;
uint32_t bitstream[1152];
uint32_t cfg[32];
int result;
if (strlen(incfg) != 1144) return -1;
for (i=0;i<1152;i++) bitstream[i] = 0;
for (i=0;i<1144;i++)
{
	bitstream[i] = (incfg[i] == '0' ? 0:1);
}
for (i=0;i<36;i++)
{
	cfg[i]=0;
	for (j=0;j<32;j++)
		cfg[i] += (bitstream[i*32+j] << j);
}
result=0;
	result+=__abstracted_reg_write(cfg[0],SCI_REG_CitirocCfg3_REG_CFG0, handle);
	result+=__abstracted_reg_write(cfg[1],SCI_REG_CitirocCfg3_REG_CFG1, handle);
	result+=__abstracted_reg_write(cfg[2],SCI_REG_CitirocCfg3_REG_CFG2, handle);
	result+=__abstracted_reg_write(cfg[3],SCI_REG_CitirocCfg3_REG_CFG3, handle);
	result+=__abstracted_reg_write(cfg[4],SCI_REG_CitirocCfg3_REG_CFG4, handle);
	result+=__abstracted_reg_write(cfg[5],SCI_REG_CitirocCfg3_REG_CFG5, handle);
	result+=__abstracted_reg_write(cfg[6],SCI_REG_CitirocCfg3_REG_CFG6, handle);
	result+=__abstracted_reg_write(cfg[7],SCI_REG_CitirocCfg3_REG_CFG7, handle);
	result+=__abstracted_reg_write(cfg[8],SCI_REG_CitirocCfg3_REG_CFG8, handle);
	result+=__abstracted_reg_write(cfg[9],SCI_REG_CitirocCfg3_REG_CFG9, handle);
	result+=__abstracted_reg_write(cfg[10],SCI_REG_CitirocCfg3_REG_CFG10, handle);
	result+=__abstracted_reg_write(cfg[11],SCI_REG_CitirocCfg3_REG_CFG11, handle);
	result+=__abstracted_reg_write(cfg[12],SCI_REG_CitirocCfg3_REG_CFG12, handle);
	result+=__abstracted_reg_write(cfg[13],SCI_REG_CitirocCfg3_REG_CFG13, handle);
	result+=__abstracted_reg_write(cfg[14],SCI_REG_CitirocCfg3_REG_CFG14, handle);
	result+=__abstracted_reg_write(cfg[15],SCI_REG_CitirocCfg3_REG_CFG15, handle);
	result+=__abstracted_reg_write(cfg[16],SCI_REG_CitirocCfg3_REG_CFG16, handle);
	result+=__abstracted_reg_write(cfg[17],SCI_REG_CitirocCfg3_REG_CFG17, handle);
	result+=__abstracted_reg_write(cfg[18],SCI_REG_CitirocCfg3_REG_CFG18, handle);
	result+=__abstracted_reg_write(cfg[19],SCI_REG_CitirocCfg3_REG_CFG19, handle);
	result+=__abstracted_reg_write(0,SCI_REG_CitirocCfg3_START_REG_CFG, handle);
	result+=__abstracted_reg_write(1,SCI_REG_CitirocCfg3_START_REG_CFG, handle);
	result+=__abstracted_reg_write(0,SCI_REG_CitirocCfg3_START_REG_CFG, handle);
if (result!=0) return -1; else return 0;

}
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

SCILIB int Citiroc_CitirocCfg3_CONFIG_MON(char *incfg, NI_HANDLE *handle)
{
int i,j;
uint32_t bitstream[1024];
uint32_t cfg[32];
int result;
if (strlen(incfg) != 256) return -1;
for (i=0;i<1024;i++) bitstream[i] = 0;
for (i=0;i<256;i++)
{
	bitstream[i] = (incfg[i] == '0' ? 0:1);
}
for (i=0;i<20;i++)
{
	cfg[i]=0;
	for (j=0;j<32;j++)
		cfg[i] += (bitstream[i*32+j] << j);
}
result=0;
	result+=__abstracted_reg_write(cfg[0],SCI_REG_CitirocCfg3_REG_CFG0, handle);
	result+=__abstracted_reg_write(cfg[1],SCI_REG_CitirocCfg3_REG_CFG1, handle);
	result+=__abstracted_reg_write(cfg[2],SCI_REG_CitirocCfg3_REG_CFG2, handle);
	result+=__abstracted_reg_write(cfg[3],SCI_REG_CitirocCfg3_REG_CFG3, handle);
	result+=__abstracted_reg_write(cfg[4],SCI_REG_CitirocCfg3_REG_CFG4, handle);
	result+=__abstracted_reg_write(cfg[5],SCI_REG_CitirocCfg3_REG_CFG5, handle);
	result+=__abstracted_reg_write(cfg[6],SCI_REG_CitirocCfg3_REG_CFG6, handle);
	result+=__abstracted_reg_write(cfg[7],SCI_REG_CitirocCfg3_REG_CFG7, handle);
	result+=__abstracted_reg_write(cfg[8],SCI_REG_CitirocCfg3_REG_CFG8, handle);
	result+=__abstracted_reg_write(cfg[9],SCI_REG_CitirocCfg3_REG_CFG9, handle);
	result+=__abstracted_reg_write(cfg[10],SCI_REG_CitirocCfg3_REG_CFG10, handle);
	result+=__abstracted_reg_write(cfg[11],SCI_REG_CitirocCfg3_REG_CFG11, handle);
	result+=__abstracted_reg_write(cfg[12],SCI_REG_CitirocCfg3_REG_CFG12, handle);
	result+=__abstracted_reg_write(cfg[13],SCI_REG_CitirocCfg3_REG_CFG13, handle);
	result+=__abstracted_reg_write(cfg[14],SCI_REG_CitirocCfg3_REG_CFG14, handle);
	result+=__abstracted_reg_write(cfg[15],SCI_REG_CitirocCfg3_REG_CFG15, handle);
	result+=__abstracted_reg_write(cfg[16],SCI_REG_CitirocCfg3_REG_CFG16, handle);
	result+=__abstracted_reg_write(cfg[17],SCI_REG_CitirocCfg3_REG_CFG17, handle);
	result+=__abstracted_reg_write(cfg[18],SCI_REG_CitirocCfg3_REG_CFG18, handle);
	result+=__abstracted_reg_write(cfg[19],SCI_REG_CitirocCfg3_REG_CFG19, handle);
	result+=__abstracted_reg_write(0,SCI_REG_CitirocCfg3_START_REG_CFG, handle);
	result+=__abstracted_reg_write(2,SCI_REG_CitirocCfg3_START_REG_CFG, handle);
	result+=__abstracted_reg_write(0,SCI_REG_CitirocCfg3_START_REG_CFG, handle);
if (result!=0) return -1; else return 0;

}
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

{
return __abstracted_reg_write(1,SCI_REG_CP_0_CONFIG, handle);

}
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

{
return __abstracted_reg_write(0,SCI_REG_CP_0_CONFIG, handle);

}
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

SCILIB int CPACK_CP_0_RESET(NI_HANDLE *handle)
{
return __abstracted_reg_write(0,SCI_REG_CP_0_CONFIG, handle);

}
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

SCILIB int CPACK_CP_0_FLUSH(NI_HANDLE *handle)
{
return __abstracted_reg_write(0,SCI_REG_CP_0_CONFIG, handle);

}
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

SCILIB int CPACK_CP_0_STATUS(uint32_t *status,NI_HANDLE *handle)
{
int err;
uint32_t int_status=0;
err= __abstracted_reg_read(&int_status, SCI_REG_CP_0_READ_STATUS, handle);
*status = int_status & 0xF;
return err;

}
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

SCILIB int CPACK_CP_0_DATA_AVAILABLE(uint32_t *status,NI_HANDLE *handle)
{
return __abstracted_reg_read(status, SCI_REG_CP_0_READ_VALID_WORDS, handle);

}
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

SCILIB int CPACK_CP_0_DOWNLOAD(uint32_t *val, uint32_t size, int32_t timeout, NI_HANDLE *handle, uint32_t *read_data, uint32_t *valid_data)
{
return __abstracted_fifo_read(val, size, SCI_REG_CP_0_FIFOADDRESS, SCI_REG_CP_0_READ_STATUS,1, timeout, handle, read_data, valid_data);

}
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

SCILIB int CPACK_CP_0_RECONSTRUCT_DATA(void *buffer_handle, t_generic_event_collection *decoded_packets)
{
	cbuf_handle_t cbuf;
	cbuf = (cbuf_handle_t)buffer_handle;
	int PacketSize =134;
	int in_sync = 0;
	uint64_t event_timecode = 0;
	uint32_t ev_energy = 0;
	uint32_t mpe = 0;
	int ch_index = 0;
	int i = 0,j;
	int k = 0;
	decoded_packets->packets = NULL;
	decoded_packets->allocated_packets = 0;
	decoded_packets->valid_packets = 0;
	
	//check if we have elements in the circular buffer
	int bfsize = circular_buf_size(cbuf);
	if (bfsize < PacketSize + 1) return -1;
	//allocate output
	int possible_packets = (circular_buf_size(cbuf) / PacketSize)+10;
	if (possible_packets < 1) return -1;
	decoded_packets->packets = (t_generic_event *)malloc(possible_packets * sizeof(t_generic_event));
	if (decoded_packets->packets==NULL) return -2;
	decoded_packets->allocated_packets = possible_packets;
	decoded_packets->valid_packets = 0;
	t_CP_0_struct temp_data;
	//process packets
	while (circular_buf_size(cbuf)> 0)
	{
		circular_buf_get(cbuf, &mpe);

		if (in_sync == 0) {
			if (mpe != 0xFFFFFFFF)
			{
				continue;
			}
			in_sync = 1;
		    ch_index =0;
			continue;
		}
		if (in_sync == 1) {
			temp_data.row[0]  =  mpe;
			in_sync = 2;
			continue;
		}
		if (in_sync == 2) {
			temp_data.row[1]  =  mpe;
			in_sync = 3;
			continue;
		}
		if (in_sync == 3) {
			temp_data.row[2]  =  mpe;
			in_sync = 4;
			continue;
		}
		if (in_sync == 4) {
			temp_data.row[3]  =  mpe;
			in_sync = 5;
			continue;
		}
		if (in_sync == 5) {
			temp_data.row[4]  =  mpe;
			in_sync = 6;
			continue;
		}
		if (in_sync == 6) {
			temp_data.row[5]  =  mpe;
			in_sync = 7;
			continue;
		}
		if (in_sync == 7) {
			temp_data.row[6]  =  mpe;
			in_sync = 8;
			continue;
		}
		if (in_sync == 8) {
			temp_data.row[7]  =  mpe;
			in_sync = 9;
			continue;
		}
		if (in_sync == 9) {
			temp_data.row[8]  =  mpe;
			in_sync = 10;
			continue;
		}
		if (in_sync == 10) {
			temp_data.row[9]  =  mpe;
			in_sync = 11;
			continue;
		}
		if (in_sync == 11) {
			temp_data.row[10]  =  mpe;
			in_sync = 12;
			continue;
		}
		if (in_sync == 12) {
			temp_data.row[11]  =  mpe;
			in_sync = 13;
			continue;
		}
		if (in_sync == 13) {
			temp_data.row[12]  =  mpe;
			in_sync = 14;
			continue;
		}
		if (in_sync == 14) {
			temp_data.row[13]  =  mpe;
			in_sync = 15;
			continue;
		}
		if (in_sync == 15) {
			temp_data.row[14]  =  mpe;
			in_sync = 16;
			continue;
		}
		if (in_sync == 16) {
			temp_data.row[15]  =  mpe;
			in_sync = 17;
			continue;
		}
		if (in_sync == 17) {
			temp_data.row[16]  =  mpe;
			in_sync = 18;
			continue;
		}
		if (in_sync == 18) {
			temp_data.row[17]  =  mpe;
			in_sync = 19;
			continue;
		}
		if (in_sync == 19) {
			temp_data.row[18]  =  mpe;
			in_sync = 20;
			continue;
		}
		if (in_sync == 20) {
			temp_data.row[19]  =  mpe;
			in_sync = 21;
			continue;
		}
		if (in_sync == 21) {
			temp_data.row[20]  =  mpe;
			in_sync = 22;
			continue;
		}
		if (in_sync == 22) {
			temp_data.row[21]  =  mpe;
			in_sync = 23;
			continue;
		}
		if (in_sync == 23) {
			temp_data.row[22]  =  mpe;
			in_sync = 24;
			continue;
		}
		if (in_sync == 24) {
			temp_data.row[23]  =  mpe;
			in_sync = 25;
			continue;
		}
		if (in_sync == 25) {
			temp_data.row[24]  =  mpe;
			in_sync = 26;
			continue;
		}
		if (in_sync == 26) {
			temp_data.row[25]  =  mpe;
			in_sync = 27;
			continue;
		}
		if (in_sync == 27) {
			temp_data.row[26]  =  mpe;
			in_sync = 28;
			continue;
		}
		if (in_sync == 28) {
			temp_data.row[27]  =  mpe;
			in_sync = 29;
			continue;
		}
		if (in_sync == 29) {
			temp_data.row[28]  =  mpe;
			in_sync = 30;
			continue;
		}
		if (in_sync == 30) {
			temp_data.row[29]  =  mpe;
			in_sync = 31;
			continue;
		}
		if (in_sync == 31) {
			temp_data.row[30]  =  mpe;
			in_sync = 32;
			continue;
		}
		if (in_sync == 32) {
			temp_data.row[31]  =  mpe;
			in_sync = 33;
			continue;
		}
		if (in_sync == 33) {
			temp_data.row[32]  =  mpe;
			in_sync = 34;
			continue;
		}
		if (in_sync == 34) {
			temp_data.row[33]  =  mpe;
			in_sync = 35;
			continue;
		}
		if (in_sync == 35) {
			temp_data.row[34]  =  mpe;
			in_sync = 36;
			continue;
		}
		if (in_sync == 36) {
			temp_data.row[35]  =  mpe;
			in_sync = 37;
			continue;
		}
		if (in_sync == 37) {
			temp_data.row[36]  =  mpe;
			in_sync = 38;
			continue;
		}
		if (in_sync == 38) {
			temp_data.row[37]  =  mpe;
			in_sync = 39;
			continue;
		}
		if (in_sync == 39) {
			temp_data.row[38]  =  mpe;
			in_sync = 40;
			continue;
		}
		if (in_sync == 40) {
			temp_data.row[39]  =  mpe;
			in_sync = 41;
			continue;
		}
		if (in_sync == 41) {
			temp_data.row[40]  =  mpe;
			in_sync = 42;
			continue;
		}
		if (in_sync == 42) {
			temp_data.row[41]  =  mpe;
			in_sync = 43;
			continue;
		}
		if (in_sync == 43) {
			temp_data.row[42]  =  mpe;
			in_sync = 44;
			continue;
		}
		if (in_sync == 44) {
			temp_data.row[43]  =  mpe;
			in_sync = 45;
			continue;
		}
		if (in_sync == 45) {
			temp_data.row[44]  =  mpe;
			in_sync = 46;
			continue;
		}
		if (in_sync == 46) {
			temp_data.row[45]  =  mpe;
			in_sync = 47;
			continue;
		}
		if (in_sync == 47) {
			temp_data.row[46]  =  mpe;
			in_sync = 48;
			continue;
		}
		if (in_sync == 48) {
			temp_data.row[47]  =  mpe;
			in_sync = 49;
			continue;
		}
		if (in_sync == 49) {
			temp_data.row[48]  =  mpe;
			in_sync = 50;
			continue;
		}
		if (in_sync == 50) {
			temp_data.row[49]  =  mpe;
			in_sync = 51;
			continue;
		}
		if (in_sync == 51) {
			temp_data.row[50]  =  mpe;
			in_sync = 52;
			continue;
		}
		if (in_sync == 52) {
			temp_data.row[51]  =  mpe;
			in_sync = 53;
			continue;
		}
		if (in_sync == 53) {
			temp_data.row[52]  =  mpe;
			in_sync = 54;
			continue;
		}
		if (in_sync == 54) {
			temp_data.row[53]  =  mpe;
			in_sync = 55;
			continue;
		}
		if (in_sync == 55) {
			temp_data.row[54]  =  mpe;
			in_sync = 56;
			continue;
		}
		if (in_sync == 56) {
			temp_data.row[55]  =  mpe;
			in_sync = 57;
			continue;
		}
		if (in_sync == 57) {
			temp_data.row[56]  =  mpe;
			in_sync = 58;
			continue;
		}
		if (in_sync == 58) {
			temp_data.row[57]  =  mpe;
			in_sync = 59;
			continue;
		}
		if (in_sync == 59) {
			temp_data.row[58]  =  mpe;
			in_sync = 60;
			continue;
		}
		if (in_sync == 60) {
			temp_data.row[59]  =  mpe;
			in_sync = 61;
			continue;
		}
		if (in_sync == 61) {
			temp_data.row[60]  =  mpe;
			in_sync = 62;
			continue;
		}
		if (in_sync == 62) {
			temp_data.row[61]  =  mpe;
			in_sync = 63;
			continue;
		}
		if (in_sync == 63) {
			temp_data.row[62]  =  mpe;
			in_sync = 64;
			continue;
		}
		if (in_sync == 64) {
			temp_data.row[63]  =  mpe;
			in_sync = 65;
			continue;
		}
		if (in_sync == 65) {
			temp_data.row[64]  =  mpe;
			in_sync = 66;
			continue;
		}
		if (in_sync == 66) {
			temp_data.row[65]  =  mpe;
			in_sync = 67;
			continue;
		}
		if (in_sync == 67) {
			temp_data.row[66]  =  mpe;
			in_sync = 68;
			continue;
		}
		if (in_sync == 68) {
			temp_data.row[67]  =  mpe;
			in_sync = 69;
			continue;
		}
		if (in_sync == 69) {
			temp_data.row[68]  =  mpe;
			in_sync = 70;
			continue;
		}
		if (in_sync == 70) {
			temp_data.row[69]  =  mpe;
			in_sync = 71;
			continue;
		}
		if (in_sync == 71) {
			temp_data.row[70]  =  mpe;
			in_sync = 72;
			continue;
		}
		if (in_sync == 72) {
			temp_data.row[71]  =  mpe;
			in_sync = 73;
			continue;
		}
		if (in_sync == 73) {
			temp_data.row[72]  =  mpe;
			in_sync = 74;
			continue;
		}
		if (in_sync == 74) {
			temp_data.row[73]  =  mpe;
			in_sync = 75;
			continue;
		}
		if (in_sync == 75) {
			temp_data.row[74]  =  mpe;
			in_sync = 76;
			continue;
		}
		if (in_sync == 76) {
			temp_data.row[75]  =  mpe;
			in_sync = 77;
			continue;
		}
		if (in_sync == 77) {
			temp_data.row[76]  =  mpe;
			in_sync = 78;
			continue;
		}
		if (in_sync == 78) {
			temp_data.row[77]  =  mpe;
			in_sync = 79;
			continue;
		}
		if (in_sync == 79) {
			temp_data.row[78]  =  mpe;
			in_sync = 80;
			continue;
		}
		if (in_sync == 80) {
			temp_data.row[79]  =  mpe;
			in_sync = 81;
			continue;
		}
		if (in_sync == 81) {
			temp_data.row[80]  =  mpe;
			in_sync = 82;
			continue;
		}
		if (in_sync == 82) {
			temp_data.row[81]  =  mpe;
			in_sync = 83;
			continue;
		}
		if (in_sync == 83) {
			temp_data.row[82]  =  mpe;
			in_sync = 84;
			continue;
		}
		if (in_sync == 84) {
			temp_data.row[83]  =  mpe;
			in_sync = 85;
			continue;
		}
		if (in_sync == 85) {
			temp_data.row[84]  =  mpe;
			in_sync = 86;
			continue;
		}
		if (in_sync == 86) {
			temp_data.row[85]  =  mpe;
			in_sync = 87;
			continue;
		}
		if (in_sync == 87) {
			temp_data.row[86]  =  mpe;
			in_sync = 88;
			continue;
		}
		if (in_sync == 88) {
			temp_data.row[87]  =  mpe;
			in_sync = 89;
			continue;
		}
		if (in_sync == 89) {
			temp_data.row[88]  =  mpe;
			in_sync = 90;
			continue;
		}
		if (in_sync == 90) {
			temp_data.row[89]  =  mpe;
			in_sync = 91;
			continue;
		}
		if (in_sync == 91) {
			temp_data.row[90]  =  mpe;
			in_sync = 92;
			continue;
		}
		if (in_sync == 92) {
			temp_data.row[91]  =  mpe;
			in_sync = 93;
			continue;
		}
		if (in_sync == 93) {
			temp_data.row[92]  =  mpe;
			in_sync = 94;
			continue;
		}
		if (in_sync == 94) {
			temp_data.row[93]  =  mpe;
			in_sync = 95;
			continue;
		}
		if (in_sync == 95) {
			temp_data.row[94]  =  mpe;
			in_sync = 96;
			continue;
		}
		if (in_sync == 96) {
			temp_data.row[95]  =  mpe;
			in_sync = 97;
			continue;
		}
		if (in_sync == 97) {
			temp_data.row[96]  =  mpe;
			in_sync = 98;
			continue;
		}
		if (in_sync == 98) {
			temp_data.row[97]  =  mpe;
			in_sync = 99;
			continue;
		}
		if (in_sync == 99) {
			temp_data.row[98]  =  mpe;
			in_sync = 100;
			continue;
		}
		if (in_sync == 100) {
			temp_data.row[99]  =  mpe;
			in_sync = 101;
			continue;
		}
		if (in_sync == 101) {
			temp_data.row[100]  =  mpe;
			in_sync = 102;
			continue;
		}
		if (in_sync == 102) {
			temp_data.row[101]  =  mpe;
			in_sync = 103;
			continue;
		}
		if (in_sync == 103) {
			temp_data.row[102]  =  mpe;
			in_sync = 104;
			continue;
		}
		if (in_sync == 104) {
			temp_data.row[103]  =  mpe;
			in_sync = 105;
			continue;
		}
		if (in_sync == 105) {
			temp_data.row[104]  =  mpe;
			in_sync = 106;
			continue;
		}
		if (in_sync == 106) {
			temp_data.row[105]  =  mpe;
			in_sync = 107;
			continue;
		}
		if (in_sync == 107) {
			temp_data.row[106]  =  mpe;
			in_sync = 108;
			continue;
		}
		if (in_sync == 108) {
			temp_data.row[107]  =  mpe;
			in_sync = 109;
			continue;
		}
		if (in_sync == 109) {
			temp_data.row[108]  =  mpe;
			in_sync = 110;
			continue;
		}
		if (in_sync == 110) {
			temp_data.row[109]  =  mpe;
			in_sync = 111;
			continue;
		}
		if (in_sync == 111) {
			temp_data.row[110]  =  mpe;
			in_sync = 112;
			continue;
		}
		if (in_sync == 112) {
			temp_data.row[111]  =  mpe;
			in_sync = 113;
			continue;
		}
		if (in_sync == 113) {
			temp_data.row[112]  =  mpe;
			in_sync = 114;
			continue;
		}
		if (in_sync == 114) {
			temp_data.row[113]  =  mpe;
			in_sync = 115;
			continue;
		}
		if (in_sync == 115) {
			temp_data.row[114]  =  mpe;
			in_sync = 116;
			continue;
		}
		if (in_sync == 116) {
			temp_data.row[115]  =  mpe;
			in_sync = 117;
			continue;
		}
		if (in_sync == 117) {
			temp_data.row[116]  =  mpe;
			in_sync = 118;
			continue;
		}
		if (in_sync == 118) {
			temp_data.row[117]  =  mpe;
			in_sync = 119;
			continue;
		}
		if (in_sync == 119) {
			temp_data.row[118]  =  mpe;
			in_sync = 120;
			continue;
		}
		if (in_sync == 120) {
			temp_data.row[119]  =  mpe;
			in_sync = 121;
			continue;
		}
		if (in_sync == 121) {
			temp_data.row[120]  =  mpe;
			in_sync = 122;
			continue;
		}
		if (in_sync == 122) {
			temp_data.row[121]  =  mpe;
			in_sync = 123;
			continue;
		}
		if (in_sync == 123) {
			temp_data.row[122]  =  mpe;
			in_sync = 124;
			continue;
		}
		if (in_sync == 124) {
			temp_data.row[123]  =  mpe;
			in_sync = 125;
			continue;
		}
		if (in_sync == 125) {
			temp_data.row[124]  =  mpe;
			in_sync = 126;
			continue;
		}
		if (in_sync == 126) {
			temp_data.row[125]  =  mpe;
			in_sync = 127;
			continue;
		}
		if (in_sync == 127) {
			temp_data.row[126]  =  mpe;
			in_sync = 128;
			continue;
		}
		if (in_sync == 128) {
			temp_data.row[127]  =  mpe;
			in_sync = 129;
			continue;
		}
		if (in_sync == 129) {
			temp_data.row[128]  =  mpe;
			in_sync = 130;
			continue;
		}
		if (in_sync == 130) {
			temp_data.row[129]  =  mpe;
			in_sync = 131;
			continue;
		}
		if (in_sync == 131) {
			temp_data.row[130]  =  mpe;
			in_sync = 132;
			continue;
		}
		if (in_sync == 132) {
			temp_data.row[131]  =  mpe;
			in_sync = 133;
			continue;
		}
		if (in_sync == 133) {
			temp_data.row[132]  =  mpe;
			decoded_packets->packets[k].payload = malloc(sizeof(t_CP_0_struct));
			if (decoded_packets->packets[k].payload != NULL) {
			    *((t_CP_0_struct*)decoded_packets->packets[k].payload) = temp_data;
			    k++;
			    decoded_packets->valid_packets = k;
			}
			if (k > decoded_packets->allocated_packets) return 0;
			
			in_sync = 0;
			if (circular_buf_size(cbuf) >= PacketSize)
			    continue;
			else
			    break;
		}
	}

 return 0;

}
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

SCILIB int CitirocFRAME_CitirocFrame0_GetStatus(uint32_t *is_data_available, uint32_t *word_available, NI_HANDLE *handle)
{
 uint32_t temp;
 int res;
 res = __abstracted_reg_read(&temp, SCI_REG_CitirocFrame0_STATUS, handle);
     *is_data_available = temp & 0x01;
     *word_available = (temp >> 16) & 0xFFFF;
 return res;

}
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

SCILIB int CitirocFRAME_CitirocFrame0_RESET(NI_HANDLE *handle)
{
return __abstracted_reg_write(0x100, SCI_REG_CitirocFrame0_CONTROL, handle);

}
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

SCILIB int CitirocFRAME_CitirocFrame0_START(NI_HANDLE *handle)
{
return __abstracted_reg_write(0, SCI_REG_CitirocFrame0_CONTROL, handle);

}
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

SCILIB int CitirocFRAME_CitirocFrame0_DOWNLOAD(uint32_t *val, uint32_t size, int32_t timeout, NI_HANDLE *handle, uint32_t *read_data, uint32_t *valid_data)
{
return __abstracted_fifo_read(val, size, SCI_REG_CitirocFrame0_FIFOADDRESS, SCI_REG_CitirocFrame0_STATUS, 1, timeout, handle, read_data, valid_data);

}
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

SCILIB int CitirocFRAME_CitirocFrame0_RECONSTRUCT_DATA(void *buffer_handle, t_ASIC_packet_collection *decoded_packets)
{
	cbuf_handle_t cbuf;
	cbuf = (cbuf_handle_t)buffer_handle;
	int n_ch = 32;
	int PacketSize = n_ch + 5;
	int in_sync = 0;
	uint64_t event_timecode = 0;
	uint32_t ev_energy = 0;
	uint32_t datarow[100];
	uint32_t mpe = 0;
	int ch_index = 0;
	int i = 0, j;
	int k = 0;
	//check if we have elements in the circular buffer
	if (circular_buf_size(cbuf) < PacketSize) return -1;
	//allocate output
	int possible_packets = (circular_buf_size(cbuf) / PacketSize) + 10;
	decoded_packets->packets = (t_ASIC_packet *)malloc(possible_packets * sizeof(t_ASIC_packet));
	if (decoded_packets->packets == NULL) return -2;
	for (i = 0; i < possible_packets; i++)
	{
		decoded_packets->packets[i].Hit = (uint32_t *)malloc(n_ch * sizeof(uint32_t));
		decoded_packets->packets[i].ChargeHg = (uint32_t *)malloc(n_ch * sizeof(uint32_t));
		decoded_packets->packets[i].ChargeLg = (uint32_t *)malloc(n_ch * sizeof(uint32_t));
		
		if ((decoded_packets->packets[i].ChargeHg == NULL) ||
			(decoded_packets->packets[i].Hit == NULL) ||
			(decoded_packets->packets[i].ChargeLg == NULL))

		{
			for (j = 0; j < i; j++)
			{
				if (decoded_packets->packets[i].ChargeHg != NULL)
					free(decoded_packets->packets[i].ChargeHg);
				if (decoded_packets->packets[i].ChargeLg != NULL)
					free(decoded_packets->packets[i].ChargeLg);
				if (decoded_packets->packets[i].Hit != NULL)
					free(decoded_packets->packets[i].Hit);
			}
			if (decoded_packets->packets != NULL)
				free(decoded_packets->packets);

			return -2;
		}
	}
	decoded_packets->allocated_packets = possible_packets;
	decoded_packets->valid_packets = 0;

	//process packets
	while (circular_buf_size(cbuf)> PacketSize)
	{
		circular_buf_get(cbuf, &mpe);

		if (in_sync == 0) {
			if (mpe>>4 != 0x8000000)
			{
				decoded_packets->packets[k].AsicID = mpe & 0xf;
				//printf("w");
				continue;
			}
			in_sync = 1;
			continue;
		}
		if (in_sync == 1) {
			decoded_packets->packets[k].Time_Code = mpe ;
			in_sync = 2;
			continue;
		}
		if (in_sync == 2) {
			decoded_packets->packets[k].RunTime_Code = mpe ;
			in_sync = 3;
			continue;
		}
		if (in_sync == 3) {
			decoded_packets->packets[k].RunTime_Code += (mpe<<32L);
			in_sync = 4;
			continue;
		}
		if (in_sync == 4) {
			decoded_packets->packets[k].Pack_Id = mpe;
			in_sync = 5;
			j = 0;
			continue;
		}
		if (in_sync == 5) 
		{
			datarow[j * 3 + 0] = (mpe >> 0) & 0x3FFF;
			datarow[j * 3 + 1] = (mpe >> 14) & 0x3FFF;
			datarow[j * 3 + 2] = (mpe >> 28) & 0x1;
				j++;
				if (j == 32)
					in_sync = 6;
				continue;
		}
		if (in_sync == 6) {
			if ((mpe & 0xc0000000) == 0xc0000000)
			{
				for (i = 0; i < 32; i++)
				{
					decoded_packets->packets[k].Hit [i] = (datarow[(i * 3) + 2] & 0x1);
					decoded_packets->packets[k].ChargeHg[i] = datarow[(i * 3) + 0];
					decoded_packets->packets[k].ChargeLg[i] = datarow[(i * 3) + 1];
				}
					in_sync = 0;
					k++;
					decoded_packets->valid_packets++;
			}
			else
			{
				in_sync = 0;
			}
			continue;
		}
	}
}
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

SCILIB int RATE_METER_RateMeter_1_GET_DATA(uint32_t *val, uint32_t channels, int32_t timeout, NI_HANDLE *handle, uint32_t *read_data, uint32_t *valid_data)
{
return __abstracted_mem_read(val, channels, SCI_REG_RateMeter_1_FIFOADDRESS, timeout, handle, read_data, valid_data);

}
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

SCILIB int RATE_METER_RateMeter_1_GET_DATA_COUNTS(uint32_t *val, uint32_t channels, int32_t timeout, NI_HANDLE *handle, uint32_t *read_data, uint32_t *valid_data)
{
return __abstracted_mem_read(val, channels, SCI_REG_RateMeter_1_FIFOADDRESS+512, timeout, handle, read_data, valid_data);

}
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

SCILIB int RATE_METER_RateMeter_0_GET_DATA(uint32_t *val, uint32_t channels, int32_t timeout, NI_HANDLE *handle, uint32_t *read_data, uint32_t *valid_data)
{
return __abstracted_mem_read(val, channels, SCI_REG_RateMeter_0_FIFOADDRESS, timeout, handle, read_data, valid_data);

}
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

SCILIB int RATE_METER_RateMeter_0_GET_DATA_COUNTS(uint32_t *val, uint32_t channels, int32_t timeout, NI_HANDLE *handle, uint32_t *read_data, uint32_t *valid_data)
{
return __abstracted_mem_read(val, channels, SCI_REG_RateMeter_0_FIFOADDRESS+512, timeout, handle, read_data, valid_data);

}
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

SCILIB int RATE_METER_RateMeter_2_GET_DATA(uint32_t *val, uint32_t channels, int32_t timeout, NI_HANDLE *handle, uint32_t *read_data, uint32_t *valid_data)
{
return __abstracted_mem_read(val, channels, SCI_REG_RateMeter_2_FIFOADDRESS, timeout, handle, read_data, valid_data);

}
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

SCILIB int RATE_METER_RateMeter_2_GET_DATA_COUNTS(uint32_t *val, uint32_t channels, int32_t timeout, NI_HANDLE *handle, uint32_t *read_data, uint32_t *valid_data)
{
return __abstracted_mem_read(val, channels, SCI_REG_RateMeter_2_FIFOADDRESS+512, timeout, handle, read_data, valid_data);

}
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

SCILIB int RATE_METER_RateMeter_3_GET_DATA(uint32_t *val, uint32_t channels, int32_t timeout, NI_HANDLE *handle, uint32_t *read_data, uint32_t *valid_data)
{
return __abstracted_mem_read(val, channels, SCI_REG_RateMeter_3_FIFOADDRESS, timeout, handle, read_data, valid_data);

}
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

SCILIB int RATE_METER_RateMeter_3_GET_DATA_COUNTS(uint32_t *val, uint32_t channels, int32_t timeout, NI_HANDLE *handle, uint32_t *read_data, uint32_t *valid_data)
{
return __abstracted_mem_read(val, channels, SCI_REG_RateMeter_3_FIFOADDRESS+512, timeout, handle, read_data, valid_data);

}
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

{
int r1 = __abstracted_reg_write(0,SCI_REG_Oscilloscope_0_CONFIG_ARM, handle);
int r2 = __abstracted_reg_write(1,SCI_REG_Oscilloscope_0_CONFIG_ARM, handle);
if ((r1 == 0) && (r2 == 0))
    return 0;
else
    return -1;

}
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

SCILIB int OSCILLOSCOPE_Oscilloscope_0_SET_PARAMETERS(int32_t decimator, int32_t pre, int32_t software_trigger, int32_t analog_trigger, int32_t digital0_trigger, int32_t digital1_trigger, int32_t digital2_trigger, int32_t digital3_trigger, int32_t trigger_channel, int32_t trigger_edge, int32_t trigger_level, NI_HANDLE *handle)
{
int32_t triggermode = 0;
int r_decimator = __abstracted_reg_write(decimator, SCI_REG_Oscilloscope_0_CONFIG_DECIMATOR, handle);
int r_pre = __abstracted_reg_write(pre, SCI_REG_Oscilloscope_0_CONFIG_PRETRIGGER, handle);
int r_triglevel = __abstracted_reg_write(trigger_level, SCI_REG_Oscilloscope_0_CONFIG_TRIGGER_LEVEL, handle);
triggermode = (trigger_channel << 8)  + (software_trigger << 7 ) + (trigger_edge << 3) + (software_trigger << 1) + analog_trigger + (digital0_trigger << 2) + (digital1_trigger << 2) + digital1_trigger + (digital2_trigger << 2) + (digital2_trigger << 1) + (digital3_trigger << 2) + (digital3_trigger << 1) + digital3_trigger ; 
int r_triggermode = __abstracted_reg_write(triggermode, SCI_REG_Oscilloscope_0_CONFIG_TRIGGER_MODE, handle);
if (r_decimator == 0 & r_pre == 0 & r_triglevel == 0 & r_triggermode == 0)
    return 0;
else
    return -1;

}
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

SCILIB int OSCILLOSCOPE_Oscilloscope_0_STATUS(uint32_t *status,NI_HANDLE *handle)
{
return __abstracted_reg_read(status, SCI_REG_Oscilloscope_0_READ_STATUS, handle);

}
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

SCILIB int OSCILLOSCOPE_Oscilloscope_0_POSITION(int32_t *position,NI_HANDLE *handle)
{
return __abstracted_reg_read(position, SCI_REG_Oscilloscope_0_READ_POSITION, handle);

}
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

SCILIB int OSCILLOSCOPE_Oscilloscope_0_DOWNLOAD(uint32_t *val, uint32_t size, int32_t timeout, NI_HANDLE *handle, uint32_t *read_data, uint32_t *valid_data)
{
return __abstracted_mem_read(val, size, SCI_REG_Oscilloscope_0_FIFOADDRESS, timeout, handle, read_data, valid_data);

}
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

SCILIB int OSCILLOSCOPE_Oscilloscope_0_RECONSTRUCT(uint32_t *data_osc, uint32_t position, int32_t pre_trigger, uint32_t *read_analog, uint32_t *read_digital0, uint32_t *read_digital1, uint32_t *read_digital2, uint32_t *read_digital3)
{
int n_ch = 2;
int n_samples = 1024;
if (position > n_samples) return -1;
for(int n=0; n< n_ch; n++)
{
	int current = position - pre_trigger;
	if (current > 0)
    {
	    int k = 0;
	    for (int i = current; i < n_samples - 1; i++)
        {
		 read_analog[k + (n_samples*n)] = data_osc[i + (n_samples*n)] & 65535;
		 read_digital0[k + (n_samples*n)] = data_osc[i + (n_samples*n)] >> 16 & 1;
		 read_digital1[k + (n_samples*n)] = data_osc[i + (n_samples*n)] >> 17 & 1;
		 read_digital2[k + (n_samples*n)] = data_osc[i + (n_samples*n)] >> 18 & 1;
		 read_digital3[k + (n_samples*n)] = data_osc[i + (n_samples*n)] >> 19 & 1;
             k++;
        }
	    for (int i = 0; i < current - 1; i++)
        {
		 read_analog[k + (n_samples*n)] = data_osc[i + (n_samples*n)] & 65535;
		 read_digital0[k + (n_samples*n)] = data_osc[i + (n_samples*n)] >> 16 & 1;
		 read_digital1[k + (n_samples*n)] = data_osc[i + (n_samples*n)] >> 17 & 1;
		 read_digital2[k + (n_samples*n)] = data_osc[i + (n_samples*n)] >> 18 & 1;
		 read_digital3[k + (n_samples*n)] = data_osc[i + (n_samples*n)] >> 19 & 1;
             k++;
        }
    }
    else
    {
	    int k = 0;
	    for (int i = n_samples+current; i < n_samples - 1; i++)
        {
		 read_analog[k + (n_samples*n)] = data_osc[i + (n_samples*n)] & 65535;
		 read_digital0[k + (n_samples*n)] = data_osc[i + (n_samples*n)] >> 16 & 1;
		 read_digital1[k + (n_samples*n)] = data_osc[i + (n_samples*n)] >> 17 & 1;
		 read_digital2[k + (n_samples*n)] = data_osc[i + (n_samples*n)] >> 18 & 1;
		 read_digital3[k + (n_samples*n)] = data_osc[i + (n_samples*n)] >> 19 & 1;
             k++;
        }
	    for (int i = 0; i < n_samples + current - 1; i++)
        {
		 read_analog[k + (n_samples*n)] = data_osc[i + (n_samples*n)] & 65535;
		 read_digital0[k + (n_samples*n)] = data_osc[i + (n_samples*n)] >> 16 & 1;
		 read_digital1[k + (n_samples*n)] = data_osc[i + (n_samples*n)] >> 17 & 1;
		 read_digital2[k + (n_samples*n)] = data_osc[i + (n_samples*n)] >> 18 & 1;
		 read_digital3[k + (n_samples*n)] = data_osc[i + (n_samples*n)] >> 19 & 1;
             k++;
        }
    }
}
return 0;

}
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

{
int r1 = __abstracted_reg_write(0,SCI_REG_Oscilloscope_1_CONFIG_ARM, handle);
int r2 = __abstracted_reg_write(1,SCI_REG_Oscilloscope_1_CONFIG_ARM, handle);
if ((r1 == 0) && (r2 == 0))
    return 0;
else
    return -1;

}
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

SCILIB int OSCILLOSCOPE_Oscilloscope_1_SET_PARAMETERS(int32_t decimator, int32_t pre, int32_t software_trigger, int32_t analog_trigger, int32_t digital0_trigger, int32_t digital1_trigger, int32_t digital2_trigger, int32_t digital3_trigger, int32_t trigger_channel, int32_t trigger_edge, int32_t trigger_level, NI_HANDLE *handle)
{
int32_t triggermode = 0;
int r_decimator = __abstracted_reg_write(decimator, SCI_REG_Oscilloscope_1_CONFIG_DECIMATOR, handle);
int r_pre = __abstracted_reg_write(pre, SCI_REG_Oscilloscope_1_CONFIG_PRETRIGGER, handle);
int r_triglevel = __abstracted_reg_write(trigger_level, SCI_REG_Oscilloscope_1_CONFIG_TRIGGER_LEVEL, handle);
triggermode = (trigger_channel << 8)  + (software_trigger << 7 ) + (trigger_edge << 3) + (software_trigger << 1) + analog_trigger + (digital0_trigger << 2) + (digital1_trigger << 2) + digital1_trigger + (digital2_trigger << 2) + (digital2_trigger << 1) + (digital3_trigger << 2) + (digital3_trigger << 1) + digital3_trigger ; 
int r_triggermode = __abstracted_reg_write(triggermode, SCI_REG_Oscilloscope_1_CONFIG_TRIGGER_MODE, handle);
if (r_decimator == 0 & r_pre == 0 & r_triglevel == 0 & r_triggermode == 0)
    return 0;
else
    return -1;

}
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

SCILIB int OSCILLOSCOPE_Oscilloscope_1_STATUS(uint32_t *status,NI_HANDLE *handle)
{
return __abstracted_reg_read(status, SCI_REG_Oscilloscope_1_READ_STATUS, handle);

}
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

SCILIB int OSCILLOSCOPE_Oscilloscope_1_POSITION(int32_t *position,NI_HANDLE *handle)
{
return __abstracted_reg_read(position, SCI_REG_Oscilloscope_1_READ_POSITION, handle);

}
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

SCILIB int OSCILLOSCOPE_Oscilloscope_1_DOWNLOAD(uint32_t *val, uint32_t size, int32_t timeout, NI_HANDLE *handle, uint32_t *read_data, uint32_t *valid_data)
{
return __abstracted_mem_read(val, size, SCI_REG_Oscilloscope_1_FIFOADDRESS, timeout, handle, read_data, valid_data);

}
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

SCILIB int OSCILLOSCOPE_Oscilloscope_1_RECONSTRUCT(uint32_t *data_osc, uint32_t position, int32_t pre_trigger, uint32_t *read_analog, uint32_t *read_digital0, uint32_t *read_digital1, uint32_t *read_digital2, uint32_t *read_digital3)
{
int n_ch = 2;
int n_samples = 1024;
if (position > n_samples) return -1;
for(int n=0; n< n_ch; n++)
{
	int current = position - pre_trigger;
	if (current > 0)
    {
	    int k = 0;
	    for (int i = current; i < n_samples - 1; i++)
        {
		 read_analog[k + (n_samples*n)] = data_osc[i + (n_samples*n)] & 65535;
		 read_digital0[k + (n_samples*n)] = data_osc[i + (n_samples*n)] >> 16 & 1;
		 read_digital1[k + (n_samples*n)] = data_osc[i + (n_samples*n)] >> 17 & 1;
		 read_digital2[k + (n_samples*n)] = data_osc[i + (n_samples*n)] >> 18 & 1;
		 read_digital3[k + (n_samples*n)] = data_osc[i + (n_samples*n)] >> 19 & 1;
             k++;
        }
	    for (int i = 0; i < current - 1; i++)
        {
		 read_analog[k + (n_samples*n)] = data_osc[i + (n_samples*n)] & 65535;
		 read_digital0[k + (n_samples*n)] = data_osc[i + (n_samples*n)] >> 16 & 1;
		 read_digital1[k + (n_samples*n)] = data_osc[i + (n_samples*n)] >> 17 & 1;
		 read_digital2[k + (n_samples*n)] = data_osc[i + (n_samples*n)] >> 18 & 1;
		 read_digital3[k + (n_samples*n)] = data_osc[i + (n_samples*n)] >> 19 & 1;
             k++;
        }
    }
    else
    {
	    int k = 0;
	    for (int i = n_samples+current; i < n_samples - 1; i++)
        {
		 read_analog[k + (n_samples*n)] = data_osc[i + (n_samples*n)] & 65535;
		 read_digital0[k + (n_samples*n)] = data_osc[i + (n_samples*n)] >> 16 & 1;
		 read_digital1[k + (n_samples*n)] = data_osc[i + (n_samples*n)] >> 17 & 1;
		 read_digital2[k + (n_samples*n)] = data_osc[i + (n_samples*n)] >> 18 & 1;
		 read_digital3[k + (n_samples*n)] = data_osc[i + (n_samples*n)] >> 19 & 1;
             k++;
        }
	    for (int i = 0; i < n_samples + current - 1; i++)
        {
		 read_analog[k + (n_samples*n)] = data_osc[i + (n_samples*n)] & 65535;
		 read_digital0[k + (n_samples*n)] = data_osc[i + (n_samples*n)] >> 16 & 1;
		 read_digital1[k + (n_samples*n)] = data_osc[i + (n_samples*n)] >> 17 & 1;
		 read_digital2[k + (n_samples*n)] = data_osc[i + (n_samples*n)] >> 18 & 1;
		 read_digital3[k + (n_samples*n)] = data_osc[i + (n_samples*n)] >> 19 & 1;
             k++;
        }
    }
}
return 0;

}
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

{
int r1 = __abstracted_reg_write(0,SCI_REG_Oscilloscope_2_CONFIG_ARM, handle);
int r2 = __abstracted_reg_write(1,SCI_REG_Oscilloscope_2_CONFIG_ARM, handle);
if ((r1 == 0) && (r2 == 0))
    return 0;
else
    return -1;

}
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

SCILIB int OSCILLOSCOPE_Oscilloscope_2_SET_PARAMETERS(int32_t decimator, int32_t pre, int32_t software_trigger, int32_t analog_trigger, int32_t digital0_trigger, int32_t digital1_trigger, int32_t digital2_trigger, int32_t digital3_trigger, int32_t trigger_channel, int32_t trigger_edge, int32_t trigger_level, NI_HANDLE *handle)
{
int32_t triggermode = 0;
int r_decimator = __abstracted_reg_write(decimator, SCI_REG_Oscilloscope_2_CONFIG_DECIMATOR, handle);
int r_pre = __abstracted_reg_write(pre, SCI_REG_Oscilloscope_2_CONFIG_PRETRIGGER, handle);
int r_triglevel = __abstracted_reg_write(trigger_level, SCI_REG_Oscilloscope_2_CONFIG_TRIGGER_LEVEL, handle);
triggermode = (trigger_channel << 8)  + (software_trigger << 7 ) + (trigger_edge << 3) + (software_trigger << 1) + analog_trigger + (digital0_trigger << 2) + (digital1_trigger << 2) + digital1_trigger + (digital2_trigger << 2) + (digital2_trigger << 1) + (digital3_trigger << 2) + (digital3_trigger << 1) + digital3_trigger ; 
int r_triggermode = __abstracted_reg_write(triggermode, SCI_REG_Oscilloscope_2_CONFIG_TRIGGER_MODE, handle);
if (r_decimator == 0 & r_pre == 0 & r_triglevel == 0 & r_triggermode == 0)
    return 0;
else
    return -1;

}
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

SCILIB int OSCILLOSCOPE_Oscilloscope_2_STATUS(uint32_t *status,NI_HANDLE *handle)
{
return __abstracted_reg_read(status, SCI_REG_Oscilloscope_2_READ_STATUS, handle);

}
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

SCILIB int OSCILLOSCOPE_Oscilloscope_2_POSITION(int32_t *position,NI_HANDLE *handle)
{
return __abstracted_reg_read(position, SCI_REG_Oscilloscope_2_READ_POSITION, handle);

}
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

SCILIB int OSCILLOSCOPE_Oscilloscope_2_DOWNLOAD(uint32_t *val, uint32_t size, int32_t timeout, NI_HANDLE *handle, uint32_t *read_data, uint32_t *valid_data)
{
return __abstracted_mem_read(val, size, SCI_REG_Oscilloscope_2_FIFOADDRESS, timeout, handle, read_data, valid_data);

}
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

SCILIB int OSCILLOSCOPE_Oscilloscope_2_RECONSTRUCT(uint32_t *data_osc, uint32_t position, int32_t pre_trigger, uint32_t *read_analog, uint32_t *read_digital0, uint32_t *read_digital1, uint32_t *read_digital2, uint32_t *read_digital3)
{
int n_ch = 2;
int n_samples = 1024;
if (position > n_samples) return -1;
for(int n=0; n< n_ch; n++)
{
	int current = position - pre_trigger;
	if (current > 0)
    {
	    int k = 0;
	    for (int i = current; i < n_samples - 1; i++)
        {
		 read_analog[k + (n_samples*n)] = data_osc[i + (n_samples*n)] & 65535;
		 read_digital0[k + (n_samples*n)] = data_osc[i + (n_samples*n)] >> 16 & 1;
		 read_digital1[k + (n_samples*n)] = data_osc[i + (n_samples*n)] >> 17 & 1;
		 read_digital2[k + (n_samples*n)] = data_osc[i + (n_samples*n)] >> 18 & 1;
		 read_digital3[k + (n_samples*n)] = data_osc[i + (n_samples*n)] >> 19 & 1;
             k++;
        }
	    for (int i = 0; i < current - 1; i++)
        {
		 read_analog[k + (n_samples*n)] = data_osc[i + (n_samples*n)] & 65535;
		 read_digital0[k + (n_samples*n)] = data_osc[i + (n_samples*n)] >> 16 & 1;
		 read_digital1[k + (n_samples*n)] = data_osc[i + (n_samples*n)] >> 17 & 1;
		 read_digital2[k + (n_samples*n)] = data_osc[i + (n_samples*n)] >> 18 & 1;
		 read_digital3[k + (n_samples*n)] = data_osc[i + (n_samples*n)] >> 19 & 1;
             k++;
        }
    }
    else
    {
	    int k = 0;
	    for (int i = n_samples+current; i < n_samples - 1; i++)
        {
		 read_analog[k + (n_samples*n)] = data_osc[i + (n_samples*n)] & 65535;
		 read_digital0[k + (n_samples*n)] = data_osc[i + (n_samples*n)] >> 16 & 1;
		 read_digital1[k + (n_samples*n)] = data_osc[i + (n_samples*n)] >> 17 & 1;
		 read_digital2[k + (n_samples*n)] = data_osc[i + (n_samples*n)] >> 18 & 1;
		 read_digital3[k + (n_samples*n)] = data_osc[i + (n_samples*n)] >> 19 & 1;
             k++;
        }
	    for (int i = 0; i < n_samples + current - 1; i++)
        {
		 read_analog[k + (n_samples*n)] = data_osc[i + (n_samples*n)] & 65535;
		 read_digital0[k + (n_samples*n)] = data_osc[i + (n_samples*n)] >> 16 & 1;
		 read_digital1[k + (n_samples*n)] = data_osc[i + (n_samples*n)] >> 17 & 1;
		 read_digital2[k + (n_samples*n)] = data_osc[i + (n_samples*n)] >> 18 & 1;
		 read_digital3[k + (n_samples*n)] = data_osc[i + (n_samples*n)] >> 19 & 1;
             k++;
        }
    }
}
return 0;

}
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

{
int r1 = __abstracted_reg_write(0,SCI_REG_Oscilloscope_3_CONFIG_ARM, handle);
int r2 = __abstracted_reg_write(1,SCI_REG_Oscilloscope_3_CONFIG_ARM, handle);
if ((r1 == 0) && (r2 == 0))
    return 0;
else
    return -1;

}
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

SCILIB int OSCILLOSCOPE_Oscilloscope_3_SET_PARAMETERS(int32_t decimator, int32_t pre, int32_t software_trigger, int32_t analog_trigger, int32_t digital0_trigger, int32_t digital1_trigger, int32_t digital2_trigger, int32_t digital3_trigger, int32_t trigger_channel, int32_t trigger_edge, int32_t trigger_level, NI_HANDLE *handle)
{
int32_t triggermode = 0;
int r_decimator = __abstracted_reg_write(decimator, SCI_REG_Oscilloscope_3_CONFIG_DECIMATOR, handle);
int r_pre = __abstracted_reg_write(pre, SCI_REG_Oscilloscope_3_CONFIG_PRETRIGGER, handle);
int r_triglevel = __abstracted_reg_write(trigger_level, SCI_REG_Oscilloscope_3_CONFIG_TRIGGER_LEVEL, handle);
triggermode = (trigger_channel << 8)  + (software_trigger << 7 ) + (trigger_edge << 3) + (software_trigger << 1) + analog_trigger + (digital0_trigger << 2) + (digital1_trigger << 2) + digital1_trigger + (digital2_trigger << 2) + (digital2_trigger << 1) + (digital3_trigger << 2) + (digital3_trigger << 1) + digital3_trigger ; 
int r_triggermode = __abstracted_reg_write(triggermode, SCI_REG_Oscilloscope_3_CONFIG_TRIGGER_MODE, handle);
if (r_decimator == 0 & r_pre == 0 & r_triglevel == 0 & r_triggermode == 0)
    return 0;
else
    return -1;

}
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

SCILIB int OSCILLOSCOPE_Oscilloscope_3_STATUS(uint32_t *status,NI_HANDLE *handle)
{
return __abstracted_reg_read(status, SCI_REG_Oscilloscope_3_READ_STATUS, handle);

}
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

SCILIB int OSCILLOSCOPE_Oscilloscope_3_POSITION(int32_t *position,NI_HANDLE *handle)
{
return __abstracted_reg_read(position, SCI_REG_Oscilloscope_3_READ_POSITION, handle);

}
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

SCILIB int OSCILLOSCOPE_Oscilloscope_3_DOWNLOAD(uint32_t *val, uint32_t size, int32_t timeout, NI_HANDLE *handle, uint32_t *read_data, uint32_t *valid_data)
{
return __abstracted_mem_read(val, size, SCI_REG_Oscilloscope_3_FIFOADDRESS, timeout, handle, read_data, valid_data);

}
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

SCILIB int OSCILLOSCOPE_Oscilloscope_3_RECONSTRUCT(uint32_t *data_osc, uint32_t position, int32_t pre_trigger, uint32_t *read_analog, uint32_t *read_digital0, uint32_t *read_digital1, uint32_t *read_digital2, uint32_t *read_digital3)
{
int n_ch = 2;
int n_samples = 1024;
if (position > n_samples) return -1;
for(int n=0; n< n_ch; n++)
{
	int current = position - pre_trigger;
	if (current > 0)
    {
	    int k = 0;
	    for (int i = current; i < n_samples - 1; i++)
        {
		 read_analog[k + (n_samples*n)] = data_osc[i + (n_samples*n)] & 65535;
		 read_digital0[k + (n_samples*n)] = data_osc[i + (n_samples*n)] >> 16 & 1;
		 read_digital1[k + (n_samples*n)] = data_osc[i + (n_samples*n)] >> 17 & 1;
		 read_digital2[k + (n_samples*n)] = data_osc[i + (n_samples*n)] >> 18 & 1;
		 read_digital3[k + (n_samples*n)] = data_osc[i + (n_samples*n)] >> 19 & 1;
             k++;
        }
	    for (int i = 0; i < current - 1; i++)
        {
		 read_analog[k + (n_samples*n)] = data_osc[i + (n_samples*n)] & 65535;
		 read_digital0[k + (n_samples*n)] = data_osc[i + (n_samples*n)] >> 16 & 1;
		 read_digital1[k + (n_samples*n)] = data_osc[i + (n_samples*n)] >> 17 & 1;
		 read_digital2[k + (n_samples*n)] = data_osc[i + (n_samples*n)] >> 18 & 1;
		 read_digital3[k + (n_samples*n)] = data_osc[i + (n_samples*n)] >> 19 & 1;
             k++;
        }
    }
    else
    {
	    int k = 0;
	    for (int i = n_samples+current; i < n_samples - 1; i++)
        {
		 read_analog[k + (n_samples*n)] = data_osc[i + (n_samples*n)] & 65535;
		 read_digital0[k + (n_samples*n)] = data_osc[i + (n_samples*n)] >> 16 & 1;
		 read_digital1[k + (n_samples*n)] = data_osc[i + (n_samples*n)] >> 17 & 1;
		 read_digital2[k + (n_samples*n)] = data_osc[i + (n_samples*n)] >> 18 & 1;
		 read_digital3[k + (n_samples*n)] = data_osc[i + (n_samples*n)] >> 19 & 1;
             k++;
        }
	    for (int i = 0; i < n_samples + current - 1; i++)
        {
		 read_analog[k + (n_samples*n)] = data_osc[i + (n_samples*n)] & 65535;
		 read_digital0[k + (n_samples*n)] = data_osc[i + (n_samples*n)] >> 16 & 1;
		 read_digital1[k + (n_samples*n)] = data_osc[i + (n_samples*n)] >> 17 & 1;
		 read_digital2[k + (n_samples*n)] = data_osc[i + (n_samples*n)] >> 18 & 1;
		 read_digital3[k + (n_samples*n)] = data_osc[i + (n_samples*n)] >> 19 & 1;
             k++;
        }
    }
}
return 0;

}
