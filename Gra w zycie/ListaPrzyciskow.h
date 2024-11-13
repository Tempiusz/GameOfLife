#pragma once
#include "Przycisk.h"
#include "Uchwyt.h"
#include "Stan.h"

class ListaPrzyciskow
{	 
	std::vector<Przycisk> zbiorPrzyciskowStatycznych;
	std::vector<Przycisk> zbiorPrzyciskowMenu;
	std::vector<Uchwyt> listaUchwytow;
	
	bool czyNad;

public:
	void DodajPrzycisk(int x, int y, int szerokosc, int wysokosc, int id, const char* napis);
	void DodajUchwyt(int id, Plansza& plansza);
	void WyswietlPrzyciski(sf::RenderWindow& window, PozycjaKursora& pozycja, Stan& stan);
	void WyswietlPrzyciskiMenu(sf::RenderWindow& window, PozycjaKursora& pozycja, Stan& stan);
	void WyswietlUchwyty(sf::RenderWindow& window, Plansza& plansza, PozycjaKursora& pozycja);
	std::vector<Przycisk> ZwrocZbiorPrzyciskowStatycznych();
	std::vector<Przycisk> ZwrocZbiorPrzyciskowMenu();
	std::vector<Uchwyt> ZwrocListeUchwytow();
	void usunZbiorPrzyciskowMenu();
};

