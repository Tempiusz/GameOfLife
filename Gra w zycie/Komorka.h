#pragma once
#include <SFML/Graphics.hpp>
#include <iostream> 
#include <vector>
#include "Plansza.h"
#include <Windows.h>
#include "Stan.h"

#include <SFML/Graphics.hpp>

class Komorka {

	int xLewe, yGorny, xPrawe, yDolny;

	sf::RectangleShape komorka;

	//ponizsze zbiory przechowuj¹ wspolrzedne komorek
	std::vector<std::pair<int, int>> zbiorKomorek;
	std::vector<std::pair<int, int>> zbiorDodaj;
	std::vector<std::pair<int, int>> zbiorUsun;

public:
	Komorka();
	void DodajKomorke(int x, int y, char zbior);
	void UsunKomorke(int x, int y, char zbior);
	int  IleSasiadow(int x, int y, Plansza plansza, Stan& stan);
	void WyswietlKomorki(sf::RenderWindow& window);
	void Skanuj(sf::RenderWindow& window, Plansza plansza, Stan& stan);
	void Aktualizuj();	
	void UsunWszystko(int& kroki);
	void UstawRozmiar(Plansza plansza);
	void WizualizujOptymalizacje(sf::RenderWindow& window, Plansza& plansza, Stan& stan);
	std::pair<std::pair<int, int>, std::pair<int, int>> Optymalizuj(sf::RenderWindow& window, Plansza plansza, Stan& stan);
	void Krok(sf::RenderWindow& window, Plansza plansza, Stan& stan, int& kroki);

	std::vector<std::pair<int, int>>& PobierzZbiorKomorek();
	std::vector<std::pair<int, int>>& PobierzZbiorD();
	std::vector<std::pair<int, int>>& PobierzZbiorU();

	void WypiszKomorkiNaKonsoli(int id, Plansza plansza); //Przydatne do tworzenia szablonow

};

