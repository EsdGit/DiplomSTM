#include "stm32f4xx_gpio.h"
#include "stm32f4xx_usart.h"
#include "stm32f4xx_dma.h"

#define BUFFER_TX_MASTER_SIZE                       50
#define BUFFER_RX_MASTER_SIZE                       50

uint8_t bufferTx_Master[BUFFER_TX_MASTER_SIZE];
uint8_t bufferRx_Master[BUFFER_RX_MASTER_SIZE];

void InitUSART(int baudRate);

void InitDMA();

void InitGPIO();

void InitAllForUSART(int baudRate);