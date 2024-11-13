#pragma once
#include "Komorka.h"
#include "Plansza.h"
#include "PozycjaKursora.h"
#include "Komorka.h"
#include "Stan.h"

class Uchwyt
{
	int id;
	sf::RectangleShape uchwyt;

	int p_x, p_y;
	int poz1_x, poz1_y, poz2_x, poz2_y;
	int roznicaX = 0, roznicaY = 0;

public:

	Uchwyt(int id);
	void UstawUchwyt(Plansza& plansza);
	void UstawRozmiar(sf::RenderWindow& window, PozycjaKursora pozycja);
	void WyswietlUchwyt(sf::RenderWindow& window, PozycjaKursora pozycja);
	bool CzyKliknieto(sf::RenderWindow& window, PozycjaKursora pozycja, Stan& stan, int& tenUchwyt);
	bool CzyNadUchwytem(sf::RenderWindow& window, PozycjaKursora pozycja);
	void ZmieniajRozmiarPlanszy(
		sf::RenderWindow& window,	Plansza& plansza, 
		PozycjaKursora pozycja,		int id, Komorka& komorka, 
		Stan& stan,					int& kroki
	);
	sf::FloatRect pobierzGranice(sf::RectangleShape& ramka);
	int zwrocID();
};

