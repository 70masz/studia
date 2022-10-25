/*
 * diody.h
 *
 * Created: 17.10.2022 14:34:25
 *  Author: Student_PL
 */ 
#include <avr/io.h>
#include <util/delay.h>

#ifndef DIODY_H_
#define DIODY_H_
#define diodDDR DDRA;
#define diodPORT PORTA;

void LED_konf();
void LED_Set(unsigned int LED_number);
void LED_Clear(unsigned int LED_number);
void LED_Toggle();
unsigned int LED_GetState(unsigned int LED_number);

#endif /* DIODY_H_ */