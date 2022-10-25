/*
 * DawidSiwakLab3.c
 *
 * Created: 17.10.2022 14:14:23
 * Author : Student_PL
 */ 

#include <avr/io.h>
#include "klawiatura.h"
#include "diody.h"


int main(void)
{
	LED_konf();
	SW_konf();
    while (1) 
    {
		PORTA = SW_czytaj();
		_delay_ms(2);
    }
}

