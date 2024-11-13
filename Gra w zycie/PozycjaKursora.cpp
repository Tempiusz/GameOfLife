#include "PozycjaKursora.h"

void PozycjaKursora::PobierzPozycje(sf::RenderWindow& window)
{
	sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
	x = static_cast<int>(mousePosition.x);
	y = static_cast<int>(mousePosition.y);
}

void PozycjaKursora::PobierzZaokraglonaPozycje(sf::RenderWindow& window, Plansza& plansza)
{
	sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
	int x = static_cast<int>(mousePosition.x) - plansza.leweX % plansza.getSpacing();
	int y = static_cast<int>(mousePosition.y) - plansza.gorneY % plansza.getSpacing();
	int resztaX = (x % plansza.getSpacing() - plansza.leweX % plansza.getSpacing());
	int resztaY = (y % plansza.getSpacing()) - plansza.gorneY % plansza.getSpacing();
	x -= resztaX;
	y -= resztaY;

	px_x = x; px_y = y;
}

bool PozycjaKursora::czyKliknietoLPM()
{
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) { 
		return true;
	}
	return false;
}

bool PozycjaKursora::czyKliknietoPPM()
{
	if (sf::Mouse::isButtonPressed(sf::Mouse::Right)) {
		return true;
	}
	return false;
}

bool PozycjaKursora::czyRazKliknieto()
{
	if (pojedynczyKlik == 0) {
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {			
			pojedynczyKlik = 1;
			return true;
		}
	}
	if (pojedynczyKlik == 1 ) {
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
			return false;
		}
		pojedynczyKlik = 0;
	}
	return false;
}

bool PozycjaKursora::CzyNadPlansza(Plansza plansza)
{
	if ((x < plansza.praweX && x >= plansza.leweX) && (y < plansza.dolneY && y >= plansza.gorneY)) {
		return 1;
	}
	return 0;
}

bool PozycjaKursora::CzyNadObszaremEdycji(Plansza plansza, sf::RenderWindow& window)
{
	if (x > 0 && x < window.getSize().x - plansza.szerokoscPrawegoToolbara && 
		y > plansza.szerokoscGornegoMenu && y < window.getSize().y) {
		return 1;
	}
	else return 0;
}
