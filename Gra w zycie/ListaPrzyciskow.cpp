#include "ListaPrzyciskow.h"

void ListaPrzyciskow::DodajPrzycisk(int x, int y, int szerokosc, int wysokosc, int id, const char* napis)
{
	Przycisk przycisk(id);
	przycisk.TworzPrzycisk(x, y, szerokosc, wysokosc, id, napis);		

	if (id < 100) { zbiorPrzyciskowStatycznych.push_back(przycisk); }
	else zbiorPrzyciskowMenu.push_back(przycisk);
}

void ListaPrzyciskow::DodajUchwyt(int id, Plansza& plansza)
{
	Uchwyt uchwyt(id);
	uchwyt.UstawUchwyt(plansza);
	listaUchwytow.push_back(uchwyt);
}

void ListaPrzyciskow::WyswietlPrzyciski(sf::RenderWindow& window, PozycjaKursora& pozycja, Stan& stan)
{
	for (Przycisk& przycisk : zbiorPrzyciskowStatycznych) {				
		przycisk.WyswietlPrzycisk(window, pozycja, stan);	
	}
}

void ListaPrzyciskow::WyswietlPrzyciskiMenu(sf::RenderWindow& window, PozycjaKursora& pozycja, Stan& stan)
{
	for (Przycisk& przycisk : zbiorPrzyciskowMenu) {
		przycisk.WyswietlPrzycisk(window, pozycja, stan);
	}
}

void ListaPrzyciskow::WyswietlUchwyty(sf::RenderWindow& window, Plansza& plansza, PozycjaKursora& pozycja)
{	
	for (Uchwyt& uchwyt : listaUchwytow) {		
		uchwyt.UstawUchwyt(plansza);	
		uchwyt.WyswietlUchwyt(window, pozycja);
	}
}

std::vector<Przycisk> ListaPrzyciskow::ZwrocZbiorPrzyciskowStatycznych()
{
	return zbiorPrzyciskowStatycznych;
}

std::vector<Przycisk> ListaPrzyciskow::ZwrocZbiorPrzyciskowMenu()
{
	return zbiorPrzyciskowMenu;
}

std::vector<Uchwyt> ListaPrzyciskow::ZwrocListeUchwytow()
{
	return listaUchwytow;
}

void ListaPrzyciskow::usunZbiorPrzyciskowMenu()
{
	zbiorPrzyciskowMenu.clear();
}

