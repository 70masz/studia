/*
 * lcd.h
 *
 * Created: 24.10.2022 14:56:42
 *  Author: Student_PL
 */ 


#ifndef LCD_H_
#define LCD_H_
#include <avr/io.h>
#include <util/delay.h>
#include <string.h>
#define LCD_DDR DDRA
#define LCD_PORT PORTA
#define LCD_RS 0
#define LCD_EN 1

unsigned char x_kursor;


void wypisz(uint8_t b);

void LCD_clear();

void inicjalizacjaLCD();

void ustawKursor(unsigned char w, unsigned char h);

void napisz(char *tekst, int8_t dlugosc);

char spacje[];
void LCDclear_y(unsigned char y);

void LCD_clr_1();

void LCD_clr_2();

void LCD_clr_xy(unsigned char x,unsigned char y);

void pisz_1(char *tekst, int8_t dlugosc);

void pisz_2(char *tekst, int8_t dlugosc);

void pisz_xy(char *tekst, int8_t dlugosc, unsigned char x,unsigned char y);




#endif /* LCD_H_ */