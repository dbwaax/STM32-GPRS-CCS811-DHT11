#include "Str2float.h"
#include "string.h"
unsigned int i = 0;
float Decimals_Deal(char c[],unsigned int q)
{
	float ss = 0.1,result = 0;
	for(i = q+1;i<strlen(c);i++)
	{
		result+=ss*c[i];
		ss= ss*0.1;
	}
	return result;
}
float Integer_Deal(char c[],unsigned int k)
{
	float temp = 0,s = 1;
	for(i = 0;i<k;i++)
	{
		temp +=(float)c[k-i-1]*s;
		s *= 10;
	}
	return temp;
}
float Get_float(char c[],unsigned int len)
{
	unsigned int q = 0;
	float a = 0;
	for(i=0;i<len;i++)
	{
		if(c[i]==0x2e)
		{
			q = i;
			break;
		}
	}
	for(i = 0;i<strlen(c);i++)
	{
		if(i!=q)
		{
			c[i] = c[i]-0x30;
		}
	}
	switch(q)
	{
		case 0:
		{
			a += Decimals_Deal(c,q);
		}break;
		case 1:
		{
			a = Integer_Deal(c,q); 
			a += Decimals_Deal(c,q);
		}break;
		case 2:
		{
			a = Integer_Deal(c,q);
			a += Decimals_Deal(c,q);
		}
		case 3:
		{
			a = Integer_Deal(c,q);
			a += Decimals_Deal(c,q);
		}
	}
	return a;
}
