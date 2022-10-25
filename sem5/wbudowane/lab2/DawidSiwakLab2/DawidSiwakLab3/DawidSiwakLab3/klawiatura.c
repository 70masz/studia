/*
 * klawiatura.c
 *
 * Created: 17.10.2022 14:22:42
 *  Author: Student_PL
 */ 
#include "klawiatura.h"

void SW_konf()
{
	keypadDDR = 0xF0; // Konfiguracja DDR do prawidlowej obslugi i pracy klawiatury
	keypadPORT = 0x0F; // Konfiguracja PORT do prawidlowej obslugi i pracy klawiatury
}

int SW_odczyt()
{
	return keypadPIN&0x0F;
}

int SW_czytaj() // funkcja getkey
{
	
	int y = 0; // zerowanie zmiennej y odpowiadaj¹cej za iloœæ przyciœniêtych przycisków podczas wszystkich obrotów pêtli
	int wynik = 0; // zerowanie zmiennej wynik odpowiada jaka wartosc ostatecznie jest zwracana z funkcji
	int x = 0;

	for(int i=4;i<8;i++) // pêtla odpowiadaj¹ca za szukanie po kolumnach klawiatury
	{

		keypadPORT = ~_BV(i); // wybranie (i-3)’tej kolumny
		_delay_ms(1);// opoznienie 1ms
		x = SW_odczyt(); // odczytaj i zapamiêtaj stan klawiatury
		//PORTC = x;
		_delay_ms(1);// opoznienie 1ms

		switch(x) // wybor po odczytanym stanie klawiatury

		{
			case 0b00001110: // pierwszy wiersz
			y=y+1; // zwiêkszenie zmiennej pomocniczej o 1
			if(y>1) // jeœli zosta³ ju¿ przyciœniêty jakiœ przycisk klawiatury zwróæ wartoœæ 255

			{return 255;
			}
			else{
				wynik = i-3;  // zapisz wartoœæ przycisku
			}
			break;
			case 0b00001101: // drugi wiersz
			y=y+1; // zwiêkszenie zmiennej pomocniczej o 1
			if(y>1) // jeœli zosta³ ju¿ przyciœniêty jakiœ przycisk klawiatury zwróæ wartoœæ 255
			{return 255;
			}
			else{
				wynik = i+1; // zapisz wartoœæ przycisku
			}
			break;
			case 0b00001011: // trzeci wiersz
			y=y+1; ; // zwiêkszenie zmiennej pomocniczej o 1
			if(y>1) // jeœli zosta³ ju¿ przyciœniêty jakiœ przycisk klawiatury zwróæ wartoœæ 255
			{return 255;
			}
			else{
				wynik = i+5; // zapisz wartoœæ przycisku
			}
			break;
			case 0b00000111: // czwarty wiersz
			y=y+1; // zwiêkszenie zmiennej pomocniczej o 1

			if(y>1)// jeœli zosta³ ju¿ przyciœniêty jakiœ przycisk klawiatury zwróæ wartoœæ 255
			{return 255;
			}
			else{
				wynik =i+9; // zapisz wartoœæ przycisku
			}
			break;
			default: // wykona siê gdy nie wykryto ¿adnego case z powy¿szych

			if(x!=0b00001111) // jeœli wartoœæ odczytana jest ró¿na od wartoœci braku przyciœniêtych przycisków. Warunek ten stosujemy w celu uzyskania informacji czy przyciœniêto wiêcej ni¿ jeden przycisk w kolumnie
			{

				wynik = 255; // jeœli warunek zosta³ spe³niony zapisz w zmiennej wynik wartoœæ 255
			}

		}


	}



	return wynik; // zwróæ nr naciœniêtego przycisku lub kod zgodny z treœci¹ zadania

}