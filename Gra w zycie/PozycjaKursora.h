#pragma once
#include <SFML/Graphics.hpp>
#include "Plansza.h" 
#include <iostream>

class PozycjaKursora
{
	

public:
	bool pojedynczyKlik = 0;
	int x;
	int y;
	int px_x;
	int px_y;

	void PobierzPozycje(sf::RenderWindow& window);
	void PobierzZaokraglonaPozycje(sf::RenderWindow& window, Plansza& plansza);
	bool czyKliknietoLPM();
	bool czyRazKliknieto();
	bool czyKliknietoPPM();
	bool CzyNadPlansza(Plansza plansza);
	bool CzyNadObszaremEdycji(Plansza plansza, sf::RenderWindow& window);
};

