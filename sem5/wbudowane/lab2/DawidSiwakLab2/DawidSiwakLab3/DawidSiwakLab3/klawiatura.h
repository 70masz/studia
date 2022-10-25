/*
 * klawiatura.h
 *
 * Created: 17.10.2022 14:23:07
 *  Author: Student_PL
 */ 

#include <avr/io.h>
#include <util/delay.h>

#ifndef KLAWIATURA_H_
#define KLAWIATURA_H_
#define keypadDDR DDRC
#define keypadPIN PINC
#define keypadPORT PORTC

void SW_konf();
int SW_czytaj();
int SW_odczyt();


#endif /* KLAWIATURA_H_ */