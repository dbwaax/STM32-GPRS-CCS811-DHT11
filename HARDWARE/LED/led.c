#include "led.h"

//////////////////////////////////////////////////////////////////////////////////	 
//������ֻ��ѧϰʹ�ã�δ��������ɣ��������������κ���;
//ALIENTEKս��STM32������
//LED��������	   
//����ԭ��@ALIENTEK
//������̳:www.openedv.com
//�޸�����:2012/9/2
//�汾��V1.0
//��Ȩ���У�����ؾ���
//Copyright(C) ������������ӿƼ����޹�˾ 2009-2019
//All rights reserved									  
////////////////////////////////////////////////////////////////////////////////// 	   

//��ʼ��PB5��PE5Ϊ�����.��ʹ���������ڵ�ʱ��		    
//LED IO��ʼ��
void LED_Init(void)//��ɫ������
{
 
 GPIO_InitTypeDef  GPIO_InitStructure;// pin speed mode
 	
 RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);	 //ʹ��PB,PC�˿�ʱ��
	
 GPIO_InitStructure.GPIO_Pin = GPIO_Pin_7;			
 GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 	
 GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;		
 GPIO_Init(GPIOB, &GPIO_InitStructure);					
 GPIO_SetBits(GPIOB,GPIO_Pin_7);				
}
 
