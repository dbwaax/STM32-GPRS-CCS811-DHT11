#include "sys.h"
#include "delay.h"
#include "usart.h"
#include "esp8266_drive.h"
#include "sta_tcpclent_test.h"
#include "adc.h"
#include "IIC.h"
#include "OLED.h"
 int main(void)
 {
	delay_init();	  
	Uart1_init(9600);
	Uart2_init(115200);
	PWM_init();
	Adc_Init();
	initIIC();
  initOLED();
	formatScreen(0x00);
	showString(32,2,"Network\r:");
	showString(15,4,"Connecting...\r:");
	ESP8266_Init();
	ESP8266_STA_TCPClient_Test();		
}


