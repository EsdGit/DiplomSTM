#include "stm32f4xx.h"

uint16_t CRC16_calc(uint8_t *Message, uint8_t MessageLenght);
uint8_t CRC8_calc(uint8_t *Message, uint8_t MessageLenght);
uint8_t Height (uint16_t Data);
uint8_t Low (uint16_t Data);
