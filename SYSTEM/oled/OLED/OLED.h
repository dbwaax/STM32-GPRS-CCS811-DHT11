/******************************************************************
 * ???OLED.h
 * ?????OLED???????
 * ???2018-03-04
 * ???zx
 * ???Ver.1.0 | ????
 * 
 * Copyright (C) 2018 zx. All rights reserved.
*******************************************************************/
#ifndef __OLED_H
#define __OLED_H			  	  
#include "stm32f10x.h"

/**************************??????*****************************/				   
typedef enum
{
    SCREEN_UP = 0,
    SCREEN_DOWN = 1
}SCREEN_DIR;

/**************************??????*****************************/	
typedef enum
{
    SCREEN_NORMAL = 0,
    SCREEN_REVERSE = 1
}SCREEN_SHOW;


/**************************????/????*****************************/	
typedef enum
{
    SCREEN_ON = 0,
    SCREEN_OFF = 1
}SCREEN_SWITCH;


/**************************??????*****************************/	
typedef enum
{
    FONT_8_EN  = 6,
    FONT_16_EN = 8,
    FONT_16_CN = 16
}FONT_SIZE;


/**************************????*****************************/	
typedef enum 
{
    OCT = 8,
    DEC = 10,
    HEX = 16
}RADIX;


/**************************??????*****************************/	
//?????????????????????????????????????????
typedef enum
{
    FM_LOGO_ENUM = 0,
    DIRECT_LOGO_ENUM = 1,
    BRIGHTNESS_LOGO_ENUM = 2,
    REVERSAL_LOGO_ENUM = 3
}IMAGE_INDEX;
void initOLED(void);

void writeCommand(unsigned char cmd);
void writeData(unsigned char data);

void formatScreen(u8 format_data);

void showChar(unsigned char x,unsigned char y,unsigned char order); 
void showString(unsigned char x,unsigned char y,char * str);    
#endif  
	 



