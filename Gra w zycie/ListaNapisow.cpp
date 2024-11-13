#include "ListaNapisow.h"

void ListaNapisow::DodajNapisy()
{
	tekst.setPosition(1350, 600);
	listaNapisow.push_back(tekst);

	tekst.setPosition(1350, 620);
	listaNapisow.push_back(tekst);

	tekst.setPosition(1350, 640);
	listaNapisow.push_back(tekst);

	tekst.setPosition(1350, 660);
	listaNapisow.push_back(tekst);

	tekst.setPosition(1350, 680);
	listaNapisow.push_back(tekst);

	tekst.setPosition(1350, 700);
	listaNapisow.push_back(tekst);

	tekst.setPosition(1350, 730);
	listaNapisow.push_back(tekst);
}

void ListaNapisow::WyswietlNapisy(sf::RenderWindow& window, Stan& stan, int kroki, Komorka& komorka, Plansza plansza)
{
	int licznik = 0;
	for (sf::Text& napis : listaNapisow) {
		licznik++;
		if (licznik == 1) napis.setString("Kroki: " + std::to_string(kroki));
		if (licznik == 2) napis.setString("Ilosc komorek: " + std::to_string(komorka.PobierzZbiorKomorek().size()));
		if (licznik == 3) napis.setString("Rozdzielczosc x: " + std::to_string(plansza.rozdzielczoscX));
		if (licznik == 4) napis.setString("Rozdzielczosc y " + std::to_string(plansza.rozdzielczoscY));
		if (licznik == 5) {
			if (stan.ZwrocStan(8) == 1) {
				napis.setString("Optymalizacja: Tak");
			}
			else {
				napis.setString("Optymalizacja: Nie");  
			}
		}
	
		if (licznik == 6) napis.setString("Szybkosc: " + std::to_string(stan.szybkosc) + "ms na 1 klatke");

		if (licznik == 7) {
			if (stan.ZwrocStan(13) == 0) {
				napis.setString("LLP aby rysowac\nPPM aby uzyc gumki");
			}
			else napis.setString("R aby obrocic\nPPM aby anulowac");
		}

		window.draw(napis);
	}
}

void ListaNapisow::UstawCzcionke()
{
	if (!czcionka.loadFromFile("arial.ttf")) {
		std::cout << "Nie zaladowano czcionki";
		exit(0);
	}
	tekst.setFont(czcionka);
	tekst.setCharacterSize(16);
	tekst.setFillColor(sf::Color::White);
}

