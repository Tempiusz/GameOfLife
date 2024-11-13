#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <Windows.h>
#include "PozycjaKursora.h"
#include "Stan.h"


#include <SFML/Graphics.hpp>

class Przycisk
{
	sf::Text tekst;
	sf::RectangleShape ramka;	
	sf::Font czcionka;
	int id;

public:
	Przycisk(int id);

	void TworzPrzycisk(int x, int y, int szerokosc, int wysokosc, int id, const char* napis);
	void WyswietlPrzycisk(sf::RenderWindow& window, PozycjaKursora& pozycja, Stan& stan);

	void TworzRamke(int x, int y, int szerokosc, int wysokosc);
	void WycentrujTekst();
	void UstawTekst(const char* napis);
	void ustawKolor(sf::RenderWindow& window, int id, PozycjaKursora& pozycja, Stan& stan);	

	int czyNadPrzyciskiem(sf::RenderWindow& window, PozycjaKursora& pozycja, Stan& stan);
	sf::FloatRect pobierzGranice(sf::RectangleShape& ramka);
	bool CzyKliknieto(sf::RenderWindow& window, PozycjaKursora& pozycja, Stan& stan);
	void UstawID(int noweID);
	int zwrocID();	
};

