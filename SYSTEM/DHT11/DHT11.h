#ifndef __DHT11_H
#define __DHT11_H
#include "stm32f10x_gpio.h"
#include "stm32f10x.h"
#include "sys.h"
#include "delay.h"
#define DATA_GPIO_TYPE GPIOA
#define DATA_PIN  GPIO_Pin_7
#define DATA_RCC RCC_APB2Periph_GPIOA
#define DATA_H GPIO_SetBits(DATA_GPIO_TYPE,DATA_PIN)
#define DATA_L GPIO_ResetBits(DATA_GPIO_TYPE,DATA_PIN)
#define DATA_IN GPIO_ReadInputDataBit(DATA_GPIO_TYPE,DATA_PIN)
extern unsigned char array[5];
void mode_output(void);
void mode_input(void);
void DHT11_RESET(void);
u16 DHT11_ReadBit(void);
u16 DHT11_ReadByte(void);
u16 DHT11_GetArray(u8 array[5]);
#endif
