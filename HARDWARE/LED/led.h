#ifndef __LED_H
#define __LED_H	 
#include "sys.h"
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
#define LED0 PBout(7)// PB5
#define LED1 PBout(8)// PE5
#define LED2 PBout(9)
#define LED3 PAout(1)
#define LED4 PAout(2)
#define LED5 PAout(3)
#define LED6 PAout(4)
#define LED7 PAout(5)
#define LED8 PAout(6)
#define LED9 PAout(7)
#define LED10 PAout(8)
#define LED11 PAout(9)
void LED_Init(void);//��ʼ��

		 				    
#endif
