#include "OLED.h"
#include "IIC.h"
#include "font.h"
void setPos(unsigned char x, unsigned char y) 
{ 
	writeCommand(0xb0+y);
	writeCommand(((x&0xf0)>>4)|0x10);
	writeCommand(x&0x0f); 
} 
void writeCommand(unsigned char cmd)
{
	startIIC();
	sendIICByte(0x78); //???????????('0')
	waitAck();
	sendIICByte(0x00); //??????
	waitAck();	
	sendIICByte(cmd); 
	waitAck();	
	stopIIC();
}
void writeData(unsigned char Data1)
{
	startIIC();
	sendIICByte(0x78);	//???????????('0')
	waitAck();
	sendIICByte(0x40);	//??????
	waitAck();	
	sendIICByte(Data1);
	waitAck();	
	stopIIC();
}

void initOLED(void)
{ 	 
	writeCommand(0xAE);   //display off
	writeCommand(0x20);	//Set Memory Addressing Mode	
	writeCommand(0x10);	//00,Horizontal Addressing Mode;01,Vertical Addressing Mode;10,Page Addressing Mode (RESET);11,Invalid
	writeCommand(0xb0);	//Set Page Start Address for Page Addressing Mode,0-7
	writeCommand(0xc8);	//Set COM Output Scan Direction
	writeCommand(0x00);//---set low column address
	writeCommand(0x10);//---set high column address
	writeCommand(0x40);//--set start line address
	writeCommand(0x81);//--set contrast control register
	writeCommand(0xdf);
	writeCommand(0xa1);//--set segment re-map 0 to 127
	writeCommand(0xa6);//--set normal display
	writeCommand(0xa8);//--set multiplex ratio(1 to 64)
	writeCommand(0x3F);//
	writeCommand(0xa4);//0xa4,Output follows RAM content;0xa5,Output ignores RAM content
	writeCommand(0xd3);//-set display offset
	writeCommand(0x00);//-not offset
	writeCommand(0xd5);//--set display clock divide ratio/oscillator frequency
	writeCommand(0xf0);//--set divide ratio
	writeCommand(0xd9);//--set pre-charge period
	writeCommand(0x22); //
	writeCommand(0xda);//--set com pins hardware configuration
	writeCommand(0x12);
	writeCommand(0xdb);//--set vcomh
	writeCommand(0x20);//0x20,0.77xVcc
	writeCommand(0x8d);//--set DC-DC enable
	writeCommand(0x14);//
	writeCommand(0xaf);//--turn on oled panel 
} 
void formatScreen(unsigned char format_data)  
{  
	unsigned short x,y;		    
	for(y=0;y<8;++y)  
	{  
		writeCommand(0xb0+y);    //?????(0~7)
		writeCommand(0x00);      //??????—????
		writeCommand(0x10);      //??????—????   
		for(x=0;x<132;++x)
		{
			writeData(format_data); 
		}	
	} 
}
// 0  1  2  3  4  5  6  7  8  9  :  D  i  s  t  e  n  c  m .
// 0  1  2  3  4  5  6  7  8  9  10 11 12 13 14 15 16 17 18 19
void showChar(unsigned char x,unsigned char y,unsigned char order)
{      	
		unsigned char i;
		
		if(x > 127 || y > 7) 			//??????
		{
			x = 0;
			y = 0;
		}
		setPos(x,y);	
		for(i=0;i<8;++i)		
		{
			writeData(ANSIC0816[order*16+i]);
		}
		setPos(x,y+1);				
		for(i=8;i<16;++i)			
		{
			writeData(ANSIC0816[order*16+i]);
		}
}  
void showString(unsigned char x,unsigned char y,char * str)
{
	unsigned char order = 0;
	unsigned char i = 0;
	while(*(str+i)!='\r')
	{
		switch(*(str+i))
		{
			case '0':order = 0;break;
			case '1':order = 1;break;
			case '2':order = 2;break;
			case '3':order = 3;break;
			case '4':order = 4;break;
			case '5':order = 5;break;
			case '6':order = 6;break;
			case '7':order = 7;break;
			case '8':order = 8;break;
			case '9':order = 9;break;
			case ':':order = 10;break;
			case 'D':order = 11;break;
			case 'i':order = 12;break;
			case 's':order = 13;break;
			case 't':order = 14;break;
			case 'e':order = 15;break;
			case 'n':order = 16;break;
			case 'c':order = 17;break;
			case 'm':order = 18;break;
			case '.':order = 19;break;
			case 'g':order = 20;break;
			case 'r':order = 21;break;
			case 'H':order = 22;break;
			case 'u':order = 23;break;
			case 'd':order = 24;break;
			case 'y':order = 25;break;
			case '`':order = 26;break;
			case ' ':order = 27;break;
			case 'P':order = 28;break;
			case 'M':order = 29;break;
			case '!':order = 30;break;
			case 'N':order = 31;break;
			case 'w':order = 32;break;
			case 'o':order = 33;break;
			case 'k':order = 34;break;
			case 'C':order = 35;break;
		}
		showChar(x,y,order);	
		x += 8;		//?????.
		i++;
	}

}		
