#pragma once
#include "Komorka.h"
#include "Plansza.h"
#include "Stan.h"
#include "PozycjaKursora.h"
 
class Szablon
{
	std::vector<std::vector<std::pair<int, int>>> listaSzablonow;
	std::vector<std::pair<int, int>> wyswietlanySzablon;
	sf::RectangleShape komorka;
	int px;
	int id;
	int maksX = 0, maksY = 0;
	int obrot = 0;

public:
	Szablon();
	void WczytajSzablonyZPliku(const std::string& filename);
	void TworzSzablony();
	void NadajID(int id);
	void UstawiajSzablon(PozycjaKursora pozycja, int id, Plansza plansza);
	void WyswietlajSzablon(sf::RenderWindow& window, Plansza plansza);
	void UsunWyswietlane();
	void UmiescSzablon(Komorka& komorka, Plansza plansza);
	void ObsluzUmieszczanieSzablonu(
		sf::RenderWindow& window, Plansza& plansza, 
		PozycjaKursora& pozycja, Stan& stan, 
		Komorka& komorka
	);
	int ZwrocID();
	void UstawPx(Plansza plansza);
	void Obroc();
};

