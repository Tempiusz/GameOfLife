#pragma once
#include <iostream>
#include "Plansza.h"
#include "Stan.h"
#include "Komorka.h"
#include <string>

class ListaNapisow
{
	sf::Font czcionka;
	sf::Text tekst;
	std::vector<sf::Text> listaNapisow;

public:
	void DodajNapisy();
	void WyswietlNapisy(sf::RenderWindow& window, Stan& stan, int kroki, Komorka& komorka,Plansza plansza);
	void UstawCzcionke();
};

