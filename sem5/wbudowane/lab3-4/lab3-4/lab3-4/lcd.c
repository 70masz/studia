/*
 * lcd.c
 *
 * Created: 24.10.2022 14:56:29
 *  Author: Student_PL
 */ 
#include "lcd.h"

char spacje[] = {' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '};//do czyszczenia linii tekstu


void wypisz(uint8_t b)
{
	LCD_PORT |= (_BV(LCD_EN));
	LCD_PORT = (b & 0xF0)|(LCD_PORT & 0x0F);
	LCD_PORT &= ~(_BV(LCD_EN));
	asm volatile("nop");
	LCD_PORT |= (_BV(LCD_EN));
	LCD_PORT = ((b & 0x0F) << 4)|(LCD_PORT & 0x0F);
	LCD_PORT &= ~(_BV(LCD_EN));
	_delay_us(50);
}

void LCD_clear()
{
	
	LCD_PORT &= ~(_BV(LCD_RS));
	wypisz(0x01);
	LCD_PORT |= (_BV(LCD_RS));
	_delay_ms(60);

}

void inicjalizacjaLCD()
{
	LCD_DDR = 0xFF;
	LCD_PORT = 0;
	LCD_PORT &= ~(_BV(LCD_RS));
	wypisz(0b00101000);
	LCD_PORT |= _BV(LCD_RS);
	LCD_PORT |= _BV(LCD_RS);
	wypisz(0b00000110);
	LCD_PORT |= _BV(LCD_RS);
	LCD_PORT &= ~(_BV(LCD_RS));
	wypisz(0b00001100);
	LCD_PORT |= _BV(LCD_RS);
	LCD_clear();
}

void ustawKursor(unsigned char w, unsigned char h)
{
	x_kursor = w;
	LCD_PORT &= ~(_BV(LCD_RS));
	wypisz((w*0x40+h)|0x80);
	LCD_PORT |= _BV(LCD_RS);
	_delay_ms(5);
}

void napisz(char *tekst, int8_t dlugosc)
{
	int8_t i = 0;
	while(i < dlugosc)
	{
		if(i == 16)
		ustawKursor(1,0);
		wypisz(tekst[i]);
		i++;
	}
}


void LCDclear_y(unsigned char y)
{
	ustawKursor(x_kursor, y);
	napisz(spacje,15);
	_delay_ms(60);
}

void LCD_clr_1()
{
	LCDclear_y(0);
}

void LCD_clr_2()
{
	LCDclear_y(1);
}

void LCD_clr_xy(unsigned char x,unsigned char y)
{
	ustawKursor(y, x);
	napisz(spacje,15);
	_delay_ms(60);
}

void pisz_1(char *tekst, int8_t dlugosc)
{
	ustawKursor(0,0);
	napisz(tekst, dlugosc);
}

void pisz_2(char *tekst, int8_t dlugosc)
{
	ustawKursor(1,0);
	napisz(tekst, dlugosc);
}

void pisz_xy(char *tekst, int8_t dlugosc, unsigned char x,unsigned char y)
{
	ustawKursor(y,x);
	napisz(tekst, dlugosc);
}