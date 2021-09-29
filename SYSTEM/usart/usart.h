//#ifndef __USART_H
//#define __USART_H
#include "delay.h"
#include "stdbool.h"
#include "sys.h" 
#include "stdio.h"
#include "string.h"
#include "sta_tcpclent_test.h"
#include "stdarg.h"
extern unsigned char USART_REC_LEN;
extern char buff[100];	  	
extern char USART_RX_BUF[200]; //接收缓冲,最大USART_REC_LEN个字节.末字节为换行符 
extern unsigned char USART_RX_STA;         		//接收状态标记
extern unsigned char flag;
void Uart1_init(u32 bound);
void Uart2_init(u32 bound);
void USART_printf( USART_TypeDef * USARTx, char * Data, ... );
#define ESP8266_USART(fmt, ...)	 USART_printf (USART2, fmt, ##__VA_ARGS__)
//#endif


