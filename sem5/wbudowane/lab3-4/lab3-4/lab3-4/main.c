/*
 * lab3-4.c
 *
 * Created: 24.10.2022 14:16:25
 * Author : Student_PL
 */ 

#include <avr/io.h>
#include <util/delay.h>
#include <string.h>
#include "lcd.h"




int main(void)
{
	char tekst[] = {'b','U','b','L','i','N'};
	char tekst2[] = {'j','E','c','H','a','N','e'};
	inicjalizacjaLCD();
	pisz_1(tekst,6);
	pisz_2(tekst2, 7);
	while (1)
	{
	}
}