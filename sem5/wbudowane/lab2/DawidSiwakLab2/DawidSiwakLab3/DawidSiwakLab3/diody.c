/*
 * diody.c
 *
 * Created: 17.10.2022 14:34:11
 *  Author: Student_PL
 */ 
#include "diody.h"

void LED_konf()
{
	diodDDR=0xFF;
	diodPORT=0x00;
}

void LED_Set(unsigned int LED_number)
{
	diodPORT=LED_number;
}

void LED_Clear(unsigned int LED_number) 
{
	if(diodPORT!=0b00000000)
		diodPORT=~LED_number;
}

void LED_Toggle(unsigned int LED_number)
{
	diodPORT^=LED_number;
}

unsigned int LED_GetState(unsigned int LED_number)
{
	if(diodPORT==LED_number)
		return 1;
	else
		return 0;
}