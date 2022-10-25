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
	
	int y = 0; // zerowanie zmiennej y odpowiadaj�cej za ilo�� przyci�ni�tych przycisk�w podczas wszystkich obrot�w p�tli
	int wynik = 0; // zerowanie zmiennej wynik odpowiada jaka wartosc ostatecznie jest zwracana z funkcji
	int x = 0;

	for(int i=4;i<8;i++) // p�tla odpowiadaj�ca za szukanie po kolumnach klawiatury
	{

		keypadPORT = ~_BV(i); // wybranie (i-3)�tej kolumny
		_delay_ms(1);// opoznienie 1ms
		x = SW_odczyt(); // odczytaj i zapami�taj stan klawiatury
		//PORTC = x;
		_delay_ms(1);// opoznienie 1ms

		switch(x) // wybor po odczytanym stanie klawiatury

		{
			case 0b00001110: // pierwszy wiersz
			y=y+1; // zwi�kszenie zmiennej pomocniczej o 1
			if(y>1) // je�li zosta� ju� przyci�ni�ty jaki� przycisk klawiatury zwr�� warto�� 255

			{return 255;
			}
			else{
				wynik = i-3;  // zapisz warto�� przycisku
			}
			break;
			case 0b00001101: // drugi wiersz
			y=y+1; // zwi�kszenie zmiennej pomocniczej o 1
			if(y>1) // je�li zosta� ju� przyci�ni�ty jaki� przycisk klawiatury zwr�� warto�� 255
			{return 255;
			}
			else{
				wynik = i+1; // zapisz warto�� przycisku
			}
			break;
			case 0b00001011: // trzeci wiersz
			y=y+1; ; // zwi�kszenie zmiennej pomocniczej o 1
			if(y>1) // je�li zosta� ju� przyci�ni�ty jaki� przycisk klawiatury zwr�� warto�� 255
			{return 255;
			}
			else{
				wynik = i+5; // zapisz warto�� przycisku
			}
			break;
			case 0b00000111: // czwarty wiersz
			y=y+1; // zwi�kszenie zmiennej pomocniczej o 1

			if(y>1)// je�li zosta� ju� przyci�ni�ty jaki� przycisk klawiatury zwr�� warto�� 255
			{return 255;
			}
			else{
				wynik =i+9; // zapisz warto�� przycisku
			}
			break;
			default: // wykona si� gdy nie wykryto �adnego case z powy�szych

			if(x!=0b00001111) // je�li warto�� odczytana jest r�na od warto�ci braku przyci�ni�tych przycisk�w. Warunek ten stosujemy w celu uzyskania informacji czy przyci�ni�to wi�cej ni� jeden przycisk w kolumnie
			{

				wynik = 255; // je�li warunek zosta� spe�niony zapisz w zmiennej wynik warto�� 255
			}

		}


	}



	return wynik; // zwr�� nr naci�ni�tego przycisku lub kod zgodny z tre�ci� zadania

}