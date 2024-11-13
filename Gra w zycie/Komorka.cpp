#include "Komorka.h"
#include <utility>
#include <iostream>

//konstruktor inicjuj¹cy rozmiar komórki 
Komorka::Komorka() 
{
	komorka.setSize(sf::Vector2f(10, 10));
}

//Dodawanie wspolrzednych do zbioru wszystkich komorek
void Komorka::DodajKomorke(int x, int y, char zbior)
{
	if (zbior == 'A') {
		std::pair<int, int> nowyElement = std::make_pair(x, y); 
		if (std::find(zbiorKomorek.begin(), zbiorKomorek.end(), nowyElement) == zbiorKomorek.end()) {
			zbiorKomorek.push_back(nowyElement);
		}
	}
	else if (zbior == 'D') { zbiorDodaj.push_back(std::make_pair(x, y)); }
	else if (zbior == 'U') { zbiorUsun.push_back(std::make_pair(x, y)); }
	
}

void Komorka::UsunKomorke(int x, int y, char zbior)
{
	if (zbior == 'A') {
		std::pair<int, int> pair = std::make_pair(x, y);
		zbiorKomorek.erase(std::remove(zbiorKomorek.begin(), zbiorKomorek.end(), pair), zbiorKomorek.end());
	}
}

void Komorka::WyswietlKomorki(sf::RenderWindow& window)
{
	for (const auto& pair : zbiorKomorek) {
		int x = pair.first;
		int y = pair.second;

		komorka.setPosition(x, y);
		window.draw(komorka);
	}
}

void Komorka::Skanuj(sf::RenderWindow& window, Plansza plansza, Stan& stan)
{
	//z optymalizacj¹
	if (stan.ZwrocStan(8) == 1) {
		std::pair<std::pair<int, int>, std::pair<int, int>> skrajnePunkty = Optymalizuj(window, plansza, stan);
		xLewe = skrajnePunkty.first.first;
		yGorny = skrajnePunkty.first.second;
		xPrawe = skrajnePunkty.second.first;
		yDolny = skrajnePunkty.second.second;
	
		//skanowanie bez brzegow
		for (int x = xLewe; x <= xPrawe; x += plansza.getSpacing()) {			
			for (int y = yGorny; y <= yDolny; y += plansza.getSpacing()) {
				int ile = IleSasiadow(x, y, plansza,stan);
				if (ile == 3) { DodajKomorke(x, y, 'D'); }
				if (ile < 2 || ile > 3) { DodajKomorke(x, y, 'U'); }
			}
		}

		// --- skanowanie brzegow ---
		//prawy i lewy brzeg
		for (int x = plansza.leweX; x <= plansza.praweX - plansza.getSpacing(); x += plansza.getSpacing() * (plansza.rozdzielczoscX-1)) {
			for (int y = plansza.gorneY; y <= plansza.dolneY - plansza.getSpacing(); y += plansza.getSpacing()) {							
				int ile = IleSasiadow(x, y, plansza, stan);
				if (ile == 3) { DodajKomorke(x, y, 'D'); }
				if (ile < 2 || ile > 3) { DodajKomorke(x, y, 'U'); }
			}
		}

		//gorny i dolny brzeg
		for (int y = plansza.gorneY; y <= plansza.dolneY; y+= plansza.getSpacing() * (plansza.rozdzielczoscY-1)) {
			for (int x = plansza.leweX + plansza.getSpacing(); x <= plansza.praweX - (2 * plansza.getSpacing()); x += plansza.getSpacing()) {				
				int ile = IleSasiadow(x, y, plansza, stan);
				if (ile == 3) { DodajKomorke(x, y, 'D'); }
				if (ile < 2 || ile > 3) { DodajKomorke(x, y, 'U'); }
			}
		}
	}
	else {
	//bez optymalizacji
		for (int x=plansza.leweX; x <= plansza.praweX - plansza.getSpacing(); x += plansza.getSpacing()) {
			for (int y = plansza.gorneY; y <= plansza.dolneY - plansza.getSpacing(); y += plansza.getSpacing()) {
				int ile = IleSasiadow(x, y, plansza, stan);
				if (ile == 3) { DodajKomorke(x, y, 'D'); }
				if (ile < 2 || ile > 3) { DodajKomorke(x, y, 'U'); }
			}
		}
	}
}

void Komorka::Aktualizuj()
{
	for (const auto& pair : zbiorDodaj) {
		DodajKomorke(pair.first, pair.second, 'A');
	}
	for (const auto& pair : zbiorUsun) {		
		UsunKomorke(pair.first, pair.second, 'A');
	}

	zbiorDodaj.clear();
	zbiorUsun.clear();
}

std::vector<std::pair<int, int>>& Komorka::PobierzZbiorKomorek() 
{
	return zbiorKomorek;
}

std::vector<std::pair<int, int>>& Komorka::PobierzZbiorD()
{
	return zbiorDodaj;
}

std::vector<std::pair<int, int>>& Komorka::PobierzZbiorU()
{
	return zbiorUsun;
}

void Komorka::WypiszKomorkiNaKonsoli(int id, Plansza plansza) //Przyspiesza tworzenie szablonow
{
	std::cout<<"\n\n\n\nlistaSzablonow.push_back(wspolrzedne);";
	for (const auto& pair : zbiorKomorek) {
		std::cout<<"\nlistaSzablonow["<<id<<"].push_back(std::make_pair("<< (pair.first) / plansza.getSpacing() - 13<<" * px, "<< (pair.second) / plansza.getSpacing() - 11<< " * px));";
	}
}

int Komorka::IleSasiadow(int x, int y, Plansza plansza, Stan& stan)
{
	int ile = 0, _x, _y;

	for (const auto& pair : zbiorKomorek) {
		_x = pair.first;
		_y = pair.second;

		//Podstawowe skanowanie
		if (x - plansza.getSpacing() == _x && y                        == _y) { ile++; }
		if (x - plansza.getSpacing() == _x && y - plansza.getSpacing() == _y) { ile++; }
		if (x                        == _x && y - plansza.getSpacing() == _y) { ile++; }
		if (x + plansza.getSpacing() == _x && y - plansza.getSpacing() == _y) { ile++; }
		if (x + plansza.getSpacing() == _x && y                        == _y) { ile++; }
		if (x + plansza.getSpacing() == _x && y + plansza.getSpacing() == _y) { ile++; }
		if (x                        == _x && y + plansza.getSpacing() == _y) { ile++; }
		if (x - plansza.getSpacing() == _x && y + plansza.getSpacing() == _y) { ile++; }

		//Skanowanie z w³¹czonym zawijaniem planszy
		//kolejno dolny i gorny brzeg
		
		if (stan.ZwrocStan(12) == 1) {
			if (y == plansza.dolneY - plansza.getSpacing()) {

				//Sprawdzanie gornej czeœci planszy gdy skanowana jest komorka na dolnym brzegu
				if (x + plansza.getSpacing() == _x && plansza.gorneY == _y) { ile++; }
				if (x == _x && plansza.gorneY == _y) { ile++; }
				if (x - plansza.getSpacing() == _x && plansza.gorneY == _y) { ile++; }

				//Sprawdzanie rogow planszy
				if (x + plansza.getSpacing() > plansza.praweX - plansza.getSpacing()) {
					if (plansza.leweX == _x && plansza.gorneY == _y) ile++;
				}
				if (x - plansza.getSpacing() < plansza.leweX) {
					if (plansza.praweX - plansza.getSpacing() == _x && plansza.gorneY == _y) { ile++; }
				}

			}
			if (y == plansza.gorneY) {
				if (x + plansza.getSpacing() == _x && plansza.dolneY - plansza.getSpacing() == _y) { ile++; }
				if (x == _x && plansza.dolneY - plansza.getSpacing() == _y) { ile++; }
				if (x - plansza.getSpacing() == _x && plansza.dolneY - plansza.getSpacing() == _y) { ile++; }


				//Sprawdzanie rogow mapy
				if (x + plansza.getSpacing() > plansza.praweX - plansza.getSpacing()) {
					if (plansza.leweX == _x && plansza.dolneY - plansza.getSpacing() == _y) ile++;
				}
				if (x - plansza.getSpacing() < plansza.leweX) {
					if (plansza.praweX - plansza.getSpacing() == _x && plansza.dolneY - plansza.getSpacing() == _y) ile++;
				}
			}
			//lewy i prawy brzeg
			if (x == plansza.leweX) {
				if (plansza.praweX - plansza.getSpacing() == _x && y + plansza.getSpacing() == _y) { ile++; }
				if (plansza.praweX - plansza.getSpacing() == _x && y == _y) { ile++; }
				if (plansza.praweX - plansza.getSpacing() == _x && y - plansza.getSpacing() == _y) { ile++; }
			}
			if (x == plansza.praweX - plansza.getSpacing()) {
				if (plansza.leweX == _x && y + plansza.getSpacing() == _y) { ile++; }
				if (plansza.leweX == _x && y == _y) { ile++; }
				if (plansza.leweX == _x && y - plansza.getSpacing() == _y) { ile++; }
			}
		}
	}
	return ile;
}



void Komorka::UsunWszystko(int& kroki) 
{
	zbiorKomorek.clear();
	kroki = 0;
}

void Komorka::UstawRozmiar(Plansza plansza)
{
	komorka.setSize(sf::Vector2f(plansza.getSpacing(), plansza.getSpacing()));
}

void Komorka::WizualizujOptymalizacje(sf::RenderWindow& window, Plansza& plansza, Stan& stan)
{
	std::pair<std::pair<int, int>, std::pair<int, int>> skrajne = Optymalizuj(window, plansza, stan);

	int xMin  =  skrajne.first.first;
	int yMin  =  skrajne.first.second;
	int xMaks =  skrajne.second.first + plansza.getSpacing();
	int yMaks =  skrajne.second.second + plansza.getSpacing();

	sf::VertexArray square(sf::LinesStrip, 5);

	square[0].position = sf::Vector2f(xMin, yMin);
	square[1].position = sf::Vector2f(xMin, yMaks);
	square[2].position = sf::Vector2f(xMaks, yMaks);
	square[3].position = sf::Vector2f(xMaks, yMin);
	square[4].position = sf::Vector2f(xMin, yMin);

	// Ustawienia koloru linii obwodu
	for (int i = 0; i < 5; ++i)
		square[i].color = sf::Color::Cyan;

	window.draw(square);
}

std::pair<std::pair<int, int>, std::pair<int, int>> Komorka::Optymalizuj(sf::RenderWindow& window, Plansza plansza, Stan& stan) {
	
	int minX = plansza.praweX - plansza.getSpacing();
	int maksX  = plansza.leweX;
	int minY = plansza.dolneY - plansza.getSpacing();
	int maksY  = plansza.gorneY;

	for (auto& pair : zbiorKomorek) {		
		if (pair.first > maksX - plansza.getSpacing())  { maksX  = pair.first  + plansza.getSpacing();
		}
		if (pair.first < minX + plansza.getSpacing())   { minX   = pair.first  - plansza.getSpacing();
		}
		if (pair.second > maksY - plansza.getSpacing()) { maksY  = pair.second + plansza.getSpacing();
		}
		if (pair.second < minY + plansza.getSpacing())  { minY   = pair.second - plansza.getSpacing();
		}
	}

	//zapobieganie skanowaniu poza granicami planszy i brzegow
	if (stan.ZwrocStan(12) == 1) {
		if (maksX > plansza.praweX - 2 * plansza.getSpacing()) {
			maksX = plansza.praweX - 2 * plansza.getSpacing();
		}
		if (minY < plansza.gorneY + plansza.getSpacing()) {
			minY = plansza.gorneY + plansza.getSpacing();
		}
		if (minX < plansza.leweX + plansza.getSpacing()) {
			minX = plansza.leweX + plansza.getSpacing();
		}
		if (maksY > plansza.dolneY - 2 * plansza.getSpacing()) {
			maksY = plansza.dolneY - 2 * plansza.getSpacing();
		}
	}
	else {
		if (maksX > plansza.praweX - plansza.getSpacing()) {
			maksX = plansza.praweX - plansza.getSpacing();
		}
		if (minY < plansza.gorneY) {
			minY = plansza.gorneY;
		}
		if (minX < plansza.leweX) {
			minX = plansza.leweX;
		}
		if (maksY > plansza.dolneY - plansza.getSpacing()) {
			maksY = plansza.dolneY - plansza.getSpacing();
		}
	}
	
	std::pair<int, int> ograniczenieDolne = std::make_pair(minX, minY);
	std::pair<int, int> ograniczenieGorne = std::make_pair(maksX, maksY);	

	std::pair<std::pair<int, int>, std::pair<int, int>> ograniczenie = make_pair(ograniczenieDolne, ograniczenieGorne);

	maksX = 0;
	minX = 0;
	maksY = 0;
	minY = 0;

	return ograniczenie;
}

void Komorka::Krok(sf::RenderWindow& window, Plansza plansza, Stan& stan, int& kroki)
{
	Skanuj(window, plansza, stan);
	Aktualizuj();
	kroki++;
}
