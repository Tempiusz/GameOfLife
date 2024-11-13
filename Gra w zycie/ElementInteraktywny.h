#pragma once
#include <SFML/Graphics.hpp>
#include "ListaPrzyciskow.h"
#include "Plansza.h" 
#include "Komorka.h"
#include "Stan.h"
#include "PozycjaKursora.h"
#include "Uchwyt.h"
#include "Szablon.h"

class ElementInteraktywny
{
	int tenUchwyt = 0;

public:
	ListaPrzyciskow listaPrzyciskow;
	Szablon szablon;
	
	void ObsluzElementyInteraktywne(Komorka& komorka, Plansza& plansza, sf::RenderWindow& window, Stan& stan, PozycjaKursora& pozycja, int& kroki);
	void ObsluzPrzycisk(int id, Komorka& komorka, Plansza& plansza, sf::RenderWindow& window, Stan& stan, int& kroki);
	void DodajPrzyciskiWysuwane(int id);
	int	 zwrocTenUchwyt();

};

