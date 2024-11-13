#include "Szablon.h"
#include <fstream>
#include <sstream>

Szablon::Szablon()
{
	komorka.setSize(sf::Vector2f(10, 10));
	komorka.setFillColor(sf::Color(100, 100, 100));
	px = 10;
}

void Szablon::WczytajSzablonyZPliku(const std::string& filename) {
	std::ifstream file(filename);
	if (!file.is_open()) {
		std::cerr << "Nie mo¿na otworzyæ pliku do odczytu.\n";
		return;
	}

	listaSzablonow.clear();
	std::vector<std::pair<int, int>> wspolrzedne;

	std::string line;
	int id, x, y;
	while (std::getline(file, line)) {
		std::istringstream iss(line);
		if (!(iss >> id >> x >> y)) {
			std::cerr << "B³¹d podczas odczytu linii: " << line << "\n";
			continue;
		}

		// Dodaj nowe wektory dla nowych id
		if (id >= listaSzablonow.size()) {
			listaSzablonow.resize(id + 1);
		}

		listaSzablonow[id].push_back(std::make_pair(x * px, y * px));
	}

	file.close();
}

void Szablon::TworzSzablony() 
{
	komorka.setSize(sf::Vector2f(px, px));
	WczytajSzablonyZPliku("baza.txt");

}

void Szablon::NadajID(int id) 
{
	this->id = id;
}

void Szablon::UstawiajSzablon(PozycjaKursora pozycja, int id, Plansza plansza)
{
	for (std::pair<int, int>& para : listaSzablonow[id-141]) {

		if (obrot == 0) wyswietlanySzablon.push_back(std::make_pair(pozycja.px_x + para.first, pozycja.px_y + para.second));
		else if (obrot == 1) wyswietlanySzablon.push_back(std::make_pair(pozycja.px_x - para.second, pozycja.px_y + para.first));
		else if (obrot == 2) wyswietlanySzablon.push_back(std::make_pair(pozycja.px_x - para.first, pozycja.px_y - para.second));
		else if (obrot == 3) wyswietlanySzablon.push_back(std::make_pair(pozycja.px_x + para.second, pozycja.px_y - para.first));
	}
}

void Szablon::WyswietlajSzablon(sf::RenderWindow& window, Plansza plansza)
{
	for (std::pair<int, int>& para : wyswietlanySzablon) {
		if (para.first < plansza.praweX && 
			para.second < plansza.dolneY && 
			para.first > plansza.leweX - plansza.getSpacing() &&
			para.second > plansza.gorneY - plansza.getSpacing()) {
			komorka.setPosition(para.first, para.second);
			window.draw(komorka);
		}
		
	}
	UsunWyswietlane();
}

void Szablon::UmiescSzablon(Komorka& komorka, Plansza plansza)
{	
	for (const auto& para : wyswietlanySzablon) {
		if (para.first < plansza.praweX &&
			para.second < plansza.dolneY &&
			para.first > plansza.leweX - plansza.getSpacing() &&
			para.second > plansza.gorneY - plansza.getSpacing()) {
			komorka.DodajKomorke(para.first, para.second, 'A');
		}
	}

	maksX = 0;
	maksY = 0;
}

void Szablon::ObsluzUmieszczanieSzablonu(sf::RenderWindow& window, Plansza& plansza, PozycjaKursora& pozycja, Stan& stan, Komorka& komorka)
{
	if (pozycja.CzyNadPlansza(plansza)) {

		//Obsluga obracania
		if (stan.ZwrocStan(16) == 1) {
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::R) == 0) {		
				stan.UstawStan(16, 0);
			}
		}

		if (stan.ZwrocStan(16) == 0) {
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::R)) {
				Obroc();
				stan.UstawStan(16, 1);
			}
		}

		UstawiajSzablon(pozycja, ZwrocID(), plansza);
		
		if (stan.ZwrocStan(9) == 1) {
			if (pozycja.czyKliknietoLPM() == 0) stan.UstawStan(9, 0);
		}	

		if (stan.ZwrocStan(9) == 0 && stan.ZwrocStan(15) == 0 && stan.ZwrocStan(11) == 0) {		
			
			if (pozycja.czyKliknietoLPM() == 1) {
				UmiescSzablon(komorka, plansza);
				stan.UstawStan(9, 1);
			}
		}
		WyswietlajSzablon(window, plansza);
	}
	
}

void Szablon::UsunWyswietlane() 
{
	wyswietlanySzablon.clear();
}

int Szablon::ZwrocID()
{
	return id;
}

void Szablon::UstawPx(Plansza plansza)
{
	px = plansza.getSpacing();
}

void Szablon::Obroc()
{
	if (obrot == 0) obrot = 1;
	else if (obrot == 1) obrot = 2;
	else if (obrot == 2) obrot = 3;
	else if (obrot == 3) obrot = 0;
}