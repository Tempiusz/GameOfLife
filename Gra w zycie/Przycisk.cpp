#include "Przycisk.h"
#include <string>

Przycisk::Przycisk(int id)
{
	this->id = id;
}

void Przycisk::TworzPrzycisk(int x, int y, int szerokosc, int wysokosc, int id, const char* napis)
{	
	if (id < 50) { //Przyciski o ID ponizej 50 s¹ STATYCZNE
		ramka.setOutlineColor(sf::Color(150, 0, 0));
		ramka.setOutlineThickness(4.0f);
		TworzRamke(x, y, szerokosc, wysokosc);		

		tekst.setOutlineColor(sf::Color::Black); 
		tekst.setOutlineThickness(2.0f);		
	}
	else { //Reszta to przyciski DYNAMICZNE
		TworzRamke(x, y, szerokosc, wysokosc);			  		
	}

	
	UstawTekst(napis);	
}

void Przycisk::WyswietlPrzycisk(sf::RenderWindow& window, PozycjaKursora& pozycja, Stan& stan)
{
	ustawKolor(window, id, pozycja, stan);
	window.draw(ramka);	
	tekst.setFont(czcionka);
	WycentrujTekst();
	window.draw(tekst);
}

void Przycisk::TworzRamke(int x, int y, int szerokosc, int wysokosc)
{
	ramka.setPosition(sf::Vector2f(x, y));
	ramka.setSize(sf::Vector2f(szerokosc, wysokosc));	
}

void Przycisk::UstawTekst(const char* napis)
{
	if (!czcionka.loadFromFile("arial.ttf")) {
		std::cout << "Nie zaladowano czcionki";
		exit(0);
	}	
	tekst.setString(napis);
	if ( id < 50) tekst.setCharacterSize( 25 ); //standardowy = 25
	else tekst.setCharacterSize(14);
	tekst.setFillColor(sf::Color::White);	
}

void Przycisk::WycentrujTekst() {
	int x = ramka.getPosition().x;
	int y = ramka.getPosition().y;
	int szerTekstu = tekst.getGlobalBounds().width;
	int wysTekstu = tekst.getGlobalBounds().height;
	int szerPrzycisku = ramka.getSize().x;
	int wysPrzycisku = ramka.getSize().y - 8;
	
	if (id > 0 && id < 100) {
		tekst.setPosition(x + ((szerPrzycisku - szerTekstu) / 2), y + ((wysPrzycisku - wysTekstu) / 2));
	}
	else {
		tekst.setPosition(x + 3, y + ((wysPrzycisku - wysTekstu) / 2));
	}
}

void Przycisk::ustawKolor(sf::RenderWindow& window, int id, PozycjaKursora& pozycja, Stan& stan)
{	
	if (czyNadPrzyciskiem(window, pozycja, stan) == 0) {		
		ramka.setFillColor(sf::Color(50, 50, 50));
		ramka.setOutlineColor(sf::Color::Transparent);
		ramka.setOutlineThickness(0.0f);

		switch (id) {
		case 1:
			if (stan.ZwrocStan(1) == 0) {
				ramka.setFillColor(sf::Color(50, 50, 70));
			}
			else {
				ramka.setFillColor(sf::Color(50, 50, 50));
			}
			break;
		case 2:
			if (stan.ZwrocStan(1) == 1) {
				ramka.setFillColor(sf::Color(50, 50, 70));
			}
			else {
				ramka.setFillColor(sf::Color(50, 50, 50));
			}
			break;
		case 7:
			if (stan.ZwrocStan(12) == 1) {
				ramka.setFillColor(sf::Color(50, 50, 70));
			}
			else {
				ramka.setFillColor(sf::Color(50, 50, 50));
			}
			break;
		case 141:
			if (stan.ZwrocStan(13) == 1 && stan.ZwrocStan(14) == 1) {
				ramka.setFillColor(sf::Color(50, 50, 70));
			}
			else {
				ramka.setFillColor(sf::Color(50, 50, 50));
			}
			break;
		case 142:
			if (stan.ZwrocStan(13) == 1 && stan.ZwrocStan(14) == 2) {
				ramka.setFillColor(sf::Color(50, 50, 70));
			}
			else {
				ramka.setFillColor(sf::Color(50, 50, 50));
			}
			break;
		case 143:
			if (stan.ZwrocStan(13) == 1 && stan.ZwrocStan(14) == 3) {
				ramka.setFillColor(sf::Color(50, 50, 70));
			}
			else {
				ramka.setFillColor(sf::Color(50, 50, 50));
			}
			break;
		case 144:
			if (stan.ZwrocStan(13) == 1 && stan.ZwrocStan(14) == 4) {
				ramka.setFillColor(sf::Color(50, 50, 70));
			}
			else {
				ramka.setFillColor(sf::Color(50, 50, 50));
			}
			break;
		case 145:
			if (stan.ZwrocStan(13) == 1 && stan.ZwrocStan(14) == 5) {
				ramka.setFillColor(sf::Color(50, 50, 70));
			}
			else {
				ramka.setFillColor(sf::Color(50, 50, 50));
			}
			break;
		case 146:
			if (stan.ZwrocStan(13) == 1 && stan.ZwrocStan(14) == 6) {
				ramka.setFillColor(sf::Color(50, 50, 70));
			}
			else {
				ramka.setFillColor(sf::Color(50, 50, 50));
			}
			break;
		case 147:
			if (stan.ZwrocStan(13) == 1 && stan.ZwrocStan(14) == 7) {
				ramka.setFillColor(sf::Color(50, 50, 70));
			}
			else {
				ramka.setFillColor(sf::Color(50, 50, 50));
			}
			break;
		case 148:
			if (stan.ZwrocStan(13) == 1 && stan.ZwrocStan(14) == 8) {
				ramka.setFillColor(sf::Color(50, 50, 70));
			}
			else {
				ramka.setFillColor(sf::Color(50, 50, 50));
			}
			break;
		case 149:
			if (stan.ZwrocStan(13) == 1 && stan.ZwrocStan(14) == 9) {
				ramka.setFillColor(sf::Color(50, 50, 70));
			}
			else {
				ramka.setFillColor(sf::Color(50, 50, 50));
			}
			break;
		case 150:
			if (stan.ZwrocStan(13) == 1 && stan.ZwrocStan(14) == 10) {
				ramka.setFillColor(sf::Color(50, 50, 70));
			}
			else {
				ramka.setFillColor(sf::Color(50, 50, 50));
			}
			break;
		case 151:
			if (stan.ZwrocStan(13) == 1 && stan.ZwrocStan(14) == 11) {
				ramka.setFillColor(sf::Color(50, 50, 70));
			}
			else {
				ramka.setFillColor(sf::Color(50, 50, 50));
			}
			break;
		case 152:
			if (stan.ZwrocStan(13) == 1 && stan.ZwrocStan(14) == 12) {
				ramka.setFillColor(sf::Color(50, 50, 70));
			}
			else {
				ramka.setFillColor(sf::Color(50, 50, 50));
			}
			break;		
		}


	}
	else {		
		if (id > 100) {
			stan.UstawStan(15, 1);
		}
		ramka.setOutlineColor(sf::Color(200, 200, 200));
		ramka.setOutlineThickness(1.0f);
		ramka.setFillColor(sf::Color(120, 120, 120));
	}
}

int Przycisk::czyNadPrzyciskiem(sf::RenderWindow& window, PozycjaKursora& pozycja, Stan& stan)
{
	sf::FloatRect granice = pobierzGranice(ramka);
	if (granice.contains(pozycja.x, pozycja.y)) {
		return id;	
	}
	else {
		return 0;
	}
}

sf::FloatRect Przycisk::pobierzGranice(sf::RectangleShape& ramka)
{
	return ramka.getGlobalBounds();
}

bool Przycisk::CzyKliknieto(sf::RenderWindow& window, PozycjaKursora& pozycja, Stan& stan) {
	
	if (czyNadPrzyciskiem(window, pozycja, stan) != 0 && pozycja.czyRazKliknieto()) {		
		return true;
	}
	return false;
}

void Przycisk::UstawID(int noweID)
{
	id = noweID;
}

int Przycisk::zwrocID()
{
	return id;
}