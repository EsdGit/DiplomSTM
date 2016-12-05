#include "mtsp.h"

MTSP::MTSP(int baudRate, uint8_t startByte, uint8_t address)
{
	InitAllForUSART(baudRate);
	bufferRx_Master[START_BYTE_INDEX] = startByte;
	
	bufferTx_Master[START_BYTE_INDEX] = startByte;
	bufferTx_Master[SLAVE_ADD_INDEX] = address;

}