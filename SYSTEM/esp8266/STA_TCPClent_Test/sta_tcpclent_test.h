#ifndef _sta_tcpclent_test_H
#define _sta_tcpclent_test_H


#include "system.h"

#define User_ESP8266_SSID	  "Dbw.."	      //Ҫ���ӵ��ȵ������
#define User_ESP8266_PWD	  "nf895637396"	  //Ҫ���ӵ��ȵ������

#define User_ESP8266_TCPServer_IP	  "47.95.238.162"	  //Ҫ���ӵķ�������IP
#define User_ESP8266_TCPServer_PORT	  "6999"	  //Ҫ���ӵķ������Ķ˿�


extern volatile uint8_t TcpClosedFlag;  //����һ��ȫ�ֱ���


void ESP8266_STA_TCPClient_Test(void);



#endif
