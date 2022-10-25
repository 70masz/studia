/*
 * GccApplication2.c
 *
 * Created: 10.10.2022 14:28:17
 * Author : Student_PL
 */ 

#include <avr/io.h>
#include <avr/delay.h>

void z1()
{
	PORTA &= 0x00;
	for(int i = 7; i > 0; i--)
	{
		PORTA |= (1<<i)|(1<<(i-1));
		_delay_ms(500);
		PORTA &= (0<<i)|(0<<(i-1));
	}
	PORTA &= 0x00;
	for(int i = 0; i < 7; i++)
	{
		PORTA |= (1<<i)|(1<<(i+1));
		_delay_ms(1000);
		PORTA &= (0<<i)|(0<<(i+1));
	}
}

	void z1v2()
	{
		PORTA = 0xC0;
		for(int i = 6; i > 0; i--)
		{
			PORTA ^= (1<<(i+1))|(1<<(i-1));
			_delay_ms(500);
		}
		for(int i = 1; i < 7; i++)
		{
			PORTA ^= (1<<(i-1))|(1<<(i+1));
			_delay_ms(500);
		}
	}

	void z2()
	{
		//zadanie2
		PORTA &= 0x00;
		for(int i = 7; i > 3; i--)
		{
			PORTA |= (1<<i);
			_delay_ms(1000);
		}
		for(int i = 4; i < 7; i++)
		{
			PORTA &= ~(1<<i);
			_delay_ms(1000);
		}
	}

	void z3()
	{
		PORTA &= 0x00;
		for(int i = 7; i >= 0; i--)
		{
			PORTA |= (1<<i);
			_delay_ms(1000);
		}
	}


	void z4()
	{
		PORTA &= 0x00;
		for(int i = 3; i >= 0; i--)
		{
			PORTA |= (1<<i);
			_delay_ms(1000);
		}
		PORTA &= 0x00;
		for(int i = 4; i < 8; i++)
		{
			{
				PORTA |= (1<<i);
				_delay_ms(1000);
			}
		}
	}

	void z5()
	{
		PORTA &= 0x00;
		for(int i = 0; i < 4; i++)
		{
			PORTA |= (1<<i);
			_delay_ms(1000);
		}
		PORTA &= 0x00;
		for(int i = 7; i >= 4; i--)
		{
			PORTA |= (1<<i);
			_delay_ms(1000);
		}
	}
int main(void)
{  
    DDRA = 0xFF;
    while (1) 
    {
		z1();
		z2();
		z3();
		z4();
		z5();
	}
}

