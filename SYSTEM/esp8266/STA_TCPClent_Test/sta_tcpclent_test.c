#include "sta_tcpclent_test.h"
#include "delay.h"
#include "usart.h"
#include "esp8266_drive.h"
#include "DataCollection.h"
#include "OLED.h"
volatile u8 TcpClosedFlag = 0;
void ESP8266_STA_TCPClient_Test(void)
{
	u8 res;
	char str1[20]={0};
	double time = 0;
	ESP8266_AT_Test();
	ESP8266_Net_Mode_Choose(STA);
	//while(!ESP8266_JoinAP(User_ESP8266_SSID, User_ESP8266_PWD));
	ESP8266_Enable_MultipleId ( DISABLE );
	while(!ESP8266_Link_Server(enumTCP, User_ESP8266_TCPServer_IP, User_ESP8266_TCPServer_PORT, Single_ID_0));
	while(!ESP8266_UnvarnishSend());
	formatScreen(0x00);
	showString(112,0,"!\r:");
	showString(112,2,"`\r:");
	showString(112,4,"cm\r:");
	while ( 1 )
	{
		Collect_Frame();
		sprintf(str1,"Humidity:%2.2f\r:",Humidity);
		showString(0,0,str1);
		sprintf(str1,"Degree  :%2.2f\r:",Temperature);
		showString(0,2,str1);
		sprintf(str1,"Distence:%2.1f\r:",a);
		showString(0,4,str1);
		sprintf(str1,"PM2.5   :%2.2f\r:",dust);
		showString(0,6,str1);
		sprintf(str,"$\ndbw123\n%.1f\n10.6\n%.2f\n%.2f\n%.1f\n%.1f\r",time,Humidity,Temperature,dust,a);
		ESP8266_SendString ( ENABLE, str, 0, Single_ID_0 );	
		delay_ms(1000);
		time+=5;
		if(TcpClosedFlag) //检测是否失去连接
			{
				ESP8266_ExitUnvarnishSend(); //退出透传模式
				do
				{
					res = ESP8266_Get_LinkStatus();     //获取连接状态
				} 	
				while(!res);
				
				if(res == 4)                     //确认失去连接后重连
				{
//					printf ( "\r\n请稍等，正在重连热点和服务器...\r\n" );
					while (!ESP8266_JoinAP(User_ESP8266_SSID, User_ESP8266_PWD ) );
					while (!ESP8266_Link_Server(enumTCP, User_ESP8266_TCPServer_IP, User_ESP8266_TCPServer_PORT, Single_ID_0 ) );
//					printf ( "\r\n重连热点和服务器成功\r\n" );
				} 
				while(!ESP8266_UnvarnishSend());					
			}
			delay_ms(10000);
	}
}


