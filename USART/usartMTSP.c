#include "usartMTSP.h"

void InitUSART(int baudRate)
{
	USART_InitTypeDef USART_ini;
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1, ENABLE);
	USART_ini.USART_BaudRate = baudRate;
	USART_ini.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
	USART_ini.USART_Mode = USART_Mode_Tx|USART_Mode_Rx;
	USART_ini.USART_Parity = USART_Parity_No;
	USART_ini.USART_StopBits = USART_StopBits_1;
	USART_ini.USART_WordLength = USART_WordLength_8b;
	USART_Init(USART1, &USART_ini);
	
	NVIC_EnableIRQ (USART1_IRQn);
	USART_ITConfig (USART1, USART_IT_RXNE, ENABLE);
	USART_ITConfig (USART1, USART_IT_TC, ENABLE);
	USART_Cmd(USART1, ENABLE);
}

void InitDMA()
{
	DMA_InitTypeDef DMA_ini;
	
	DMA_ini.DMA_Channel = DMA_Channel_4;
	DMA_ini.DMA_PeripheralBaseAddr = (uint32_t)&(USART1->DR);
	DMA_ini.DMA_Memory0BaseAddr = (uint32_t)bufferTx_Master;
	DMA_ini.DMA_DIR = DMA_DIR_MemoryToPeripheral;
	DMA_ini.DMA_BufferSize = BUFFER_TX_MASTER_SIZE;
	DMA_ini.DMA_PeripheralInc = DMA_PeripheralInc_Disable;
	DMA_ini.DMA_MemoryInc = DMA_MemoryInc_Enable;
	DMA_ini.DMA_PeripheralDataSize = DMA_PeripheralDataSize_Byte;
	DMA_ini.DMA_MemoryDataSize = DMA_MemoryDataSize_Byte;
	DMA_ini.DMA_Mode = DMA_Mode_Normal;
	DMA_ini.DMA_Priority = DMA_Priority_Medium;
	DMA_ini.DMA_FIFOMode = DMA_FIFOMode_Disable;	
	DMA_ini.DMA_FIFOThreshold = DMA_FIFOThreshold_1QuarterFull;
	DMA_ini.DMA_MemoryBurst = DMA_MemoryBurst_Single;
	DMA_ini.DMA_PeripheralBurst = DMA_PeripheralBurst_Single;
	DMA_Init(DMA2_Stream7, &DMA_ini);
	
	USART_DMACmd(USART1, USART_DMAReq_Tx, ENABLE);
	
	NVIC_EnableIRQ (DMA2_Stream7_IRQn);
	DMA_ITConfig(DMA2_Stream7, DMA_IT_TC, ENABLE);
}

void InitGPIO()
{
	GPIO_InitTypeDef GPIO_ini;
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOB, ENABLE);
	
	GPIO_ini.GPIO_Pin = GPIO_Pin_6|GPIO_Pin_7;
	GPIO_ini.GPIO_Mode = GPIO_Mode_AF;
	GPIO_ini.GPIO_Speed = GPIO_Speed_25MHz;
	GPIO_ini.GPIO_OType = GPIO_OType_PP;
	GPIO_ini.GPIO_PuPd = GPIO_PuPd_UP;
	GPIO_Init(GPIOB, &GPIO_ini);
	
	GPIO_PinAFConfig(GPIOB, GPIO_PinSource6, GPIO_AF_USART1);
	GPIO_PinAFConfig(GPIOB, GPIO_PinSource7, GPIO_AF_USART1);
}

void InitAllForUSART(int baudRate)
{
	InitGPIO();
	InitUSART(baudRate);
	InitDMA();
}