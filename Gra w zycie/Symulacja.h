#include <SFML/Graphics.hpp>
#include "Przycisk.h"
#include "Plansza.h"
#include "Komorka.h" 
#include "ListaPrzyciskow.h"
#include "ElementInteraktywny.h"
#include "Stan.h"
#include "PozycjaKursora.h"
#include "ListaNapisow.h"

class Symulacja
{	
	bool czyZmieniacTryb = 0;
	int kroki = 0;
	Plansza plansza;
	Komorka komorka;	
	ElementInteraktywny elementInteraktywny;
	Stan stan;
	PozycjaKursora pozycja;
	ListaNapisow listaNapisow;

public:	
	void Symuluj();
	static sf::RenderWindow window;
	void TworzPrzyciskiStatyczne();
	void TworzUchwyty();
	void RysujDynamicznie();
};
