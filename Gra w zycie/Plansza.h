#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <Windows.h>

class Plansza
{			
	sf::RectangleShape ramka;
	int x1Ramki, x2Ramki, y1Ramki, y2Ramki;

public:
	int rozdzielczoscX = 60;
	int rozdzielczoscY = 30;
	int pixelSpacing    = 15;
	int szerokoscGornegoMenu = 30;
	int szerokoscPrawegoToolbara = 300;
	
	//Granice planszy
	int gorneY, dolneY;
	int leweX, praweX;

	int getSpacing();
	void RysujPlansze(sf::RenderWindow& window);
	void UstawPixelSpacing(int spacing);
	void RysujElementyMenu(sf::RenderWindow& window);
	void RysujLinie(int x1, int y1, int x2, int y2, sf::Color kolor, sf::RenderWindow& window);
	void RysujGranicePlanszy(sf::RenderWindow& window);
	void UstawGranicePlanszy(sf::RenderWindow& window);
	void RysujSiatke(sf::RenderWindow& window);
	void ZmienRozdzielczosc(int roznicaX, int roznicaY);
	void TworzRamkePrzyciskowGlownych(sf::RenderWindow& window);
	void RysujRamkePrzyciskowGlownych(sf::RenderWindow& window);
	void RysujRamkeZmianyRozmiaru(sf::RenderWindow& window, int id, int x, int y);
	void PoprawRozdzielczosc();
};

 