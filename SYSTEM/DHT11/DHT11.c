#include "DHT11.h"
unsigned char array[5];
void mode_output(void)
{
	GPIO_InitTypeDef DHT11_DATA;
  RCC_APB2PeriphClockCmd(DATA_RCC, ENABLE);
  DHT11_DATA.GPIO_Pin = DATA_PIN;
  DHT11_DATA.GPIO_Speed = GPIO_Speed_50MHz;
  DHT11_DATA.GPIO_Mode = GPIO_Mode_Out_PP; 
  GPIO_Init(DATA_GPIO_TYPE, &DHT11_DATA);
}
void mode_input(void)
{
	GPIO_InitTypeDef DHT11_DATA;
  RCC_APB2PeriphClockCmd(DATA_RCC, ENABLE);
  DHT11_DATA.GPIO_Pin = DATA_PIN;
  DHT11_DATA.GPIO_Speed = GPIO_Speed_50MHz;
  DHT11_DATA.GPIO_Mode = GPIO_Mode_IN_FLOATING; 
  GPIO_Init(DATA_GPIO_TYPE, &DHT11_DATA);
}
void DHT11_RESET(void)
{
	mode_output();
	DATA_L;
	delay_us(19000);
	DATA_H;
	delay_us(30);
	mode_input();
}

u16 DHT11_ReadBit(void)
{
	while(DATA_IN == 0);
	delay_us(40);
	if(DATA_IN == 1)
	{
		while(DATA_IN == 1);
		return 1;
	}
	else
	{
		return 0;
	}
}

u16 DHT11_ReadByte(void)
{
	u16 i;
	u16 res = 0;
	for(i = 0;i<8;i++)
	{
		res <<=1;
		res |= DHT11_ReadBit();
	}
	return res;
}

u16 DHT11_GetArray(u8 array[5])
{
	u16 i;
	u8 check;
	DHT11_RESET();
	if(DATA_IN == 0)
	{
		while(DATA_IN == 0);
		while(DATA_IN == 1);
		for(i = 0;i<5;i++)
		{
			array[i] = DHT11_ReadByte();
		}
		while(DATA_IN == 0);
		mode_output();
		DATA_H;
		check = array[0]+array[1]+array[2]+array[3];
		if(check == array[4])
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
	return 0;
}
