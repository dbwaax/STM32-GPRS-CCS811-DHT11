#include "DataCollection.h"
#include "Str2float.h"
#include "adc.h"
#include "delay.h"
#include "usart.h"
#include "DHT11.h"
char str[100];
float a;
float temp;
float dust;
float Humidity;
float Temperature;
void Collect_Frame(void)
{
	u16 adcx;
	a = Get_float(buff,100);
	memset(buff,0,200);
	delay_ms(10);
	Wave_L;
	delay_us(280);
	//adcx=Get_Adc(ADC_Channel_1);								//通道一获取 ad转换值
	delay_us(19);
	Wave_H;
	delay_us(9680);                             //产生周期位10ms 占空比0.032的方波 驱动程传感器
	temp=(float)adcx*(3.3/4096);								
	dust= (0.17*temp-0.1)*1000+100;               // 电压AQI转换公式
	delay_ms(10);
	if(DHT11_GetArray(array))
	{
		Humidity = array[0] + array[1]/10.0;
		Temperature = array[2] + array[3]/10.0;
	}
	delay_ms(10);
	if(Humidity!=0&&Temperature!=0&&dust!=0&&a!=0)
	{
		//sprintf (str,"$\ndbw123\n%.2f\n10.6\n%.2f\n%.2f\n",time,Humidity,Temperature);
		sprintf(str,"%.2f %.2f %.2f %.2f\r",Humidity,Temperature,a,dust);
	}
}
