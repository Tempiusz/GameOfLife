#include "Uchwyt.h"

Uchwyt::Uchwyt(int id)
{
	this->id = id;
	uchwyt.setFillColor(sf::Color::White);
}

void Uchwyt::WyswietlUchwyt(sf::RenderWindow& window, PozycjaKursora pozycja)
{
	UstawRozmiar(window, pozycja);
	window.draw(uchwyt);
}





bool Uchwyt::CzyKliknieto(sf::RenderWindow& window, PozycjaKursora pozycja, Stan& stan, int& tenUchwyt)
{ 
	if (CzyNadUchwytem(window, pozycja) == 1 && pozycja.czyKliknietoLPM()) {		
		if (stan.ZwrocStan(11) == 0) {
			stan.UstawStan(11, 1);
			stan.UstawWartosc(7, 3);
			tenUchwyt = id;
		}
		return true;
	}
	return false;
}

bool Uchwyt::CzyNadUchwytem(sf::RenderWindow& window, PozycjaKursora pozycja)
{
	sf::FloatRect granice = pobierzGranice(uchwyt);
	if (granice.contains(pozycja.x, pozycja.y)) {	
		return id;		
	}
	else { return 0; }
}

void Uchwyt::ZmieniajRozmiarPlanszy(
	sf::RenderWindow& window,	Plansza& plansza, 
	PozycjaKursora pozycja,		int id, Komorka& komorka, 
	Stan& stan,					int& kroki
)

{
	pozycja.PobierzPozycje(window);

	if (stan.ZwrocStan(11) == 1) {
		switch (id) {
		case 21:
			poz1_x = plansza.leweX;
			poz2_x = pozycja.x;
			poz1_y = plansza.dolneY;
			poz2_y = pozycja.y;
			roznicaX = poz1_x - poz2_x;
			roznicaY = -(poz1_y - poz2_y);
			break;
		case 22:
			poz1_x = plansza.leweX;
			poz2_x = pozycja.x;
			roznicaX = poz1_x - poz2_x;
			break;
		case 23:
			poz1_x = plansza.leweX;
			poz2_x = pozycja.x;
			poz1_y = plansza.gorneY;
			poz2_y = pozycja.y;
			roznicaX = poz1_x - poz2_x;
			roznicaY = poz1_y - poz2_y;
			break;
		case 24:
			poz1_y = plansza.gorneY;
			poz2_y = pozycja.y;
			roznicaY = poz1_y - poz2_y;
			break;
		case 25:
			poz1_x = plansza.praweX;
			poz2_x = pozycja.x;
			poz1_y = plansza.gorneY;
			poz2_y = pozycja.y;
			roznicaX = -(poz1_x - poz2_x);
			roznicaY = poz1_y - poz2_y;
			break;
		case 26:
			poz1_x = plansza.praweX;
			poz2_x = pozycja.x;
			roznicaX = -(poz1_x - poz2_x);
			break;
		case 27:
			poz1_x = plansza.praweX;
			poz2_x = pozycja.x;
			poz1_y = plansza.dolneY;
			poz2_y = pozycja.y;
			roznicaX = -(poz1_x - poz2_x);
			roznicaY = -(poz1_y - poz2_y);
			break;
		case 28:
			poz1_y = plansza.dolneY;
			poz2_y = pozycja.y;
			roznicaY = -(poz1_y - poz2_y);
			break;

		}

		if (pozycja.czyKliknietoLPM() == 0) {		
			stan.UstawStan(11, 0);
			stan.UstawWartosc(7, 1);
			plansza.ZmienRozdzielczosc(roznicaX, roznicaY);
			roznicaY = ((roznicaY - (roznicaY % plansza.getSpacing())) / plansza.getSpacing());
			roznicaX = ((roznicaX - (roznicaX % plansza.getSpacing())) / plansza.getSpacing());
			if ((roznicaX != 0 || roznicaY != 0)) komorka.UsunWszystko(kroki);
		}
	}
}

sf::FloatRect Uchwyt::pobierzGranice(sf::RectangleShape& ramka)
{
	return ramka.getGlobalBounds();
}

int Uchwyt::zwrocID()
{
	return id;
}

void Uchwyt::UstawUchwyt(Plansza& plansza)
{
	if (id == 21) uchwyt.setPosition(plansza.leweX - 4 - p_x, plansza.dolneY - p_x);
	if (id == 22) uchwyt.setPosition(plansza.leweX - 4 - p_x, plansza.gorneY - (plansza.gorneY-plansza.dolneY) / 2 - p_x);
	if (id == 23) uchwyt.setPosition(plansza.leweX - 4 - p_x, plansza.gorneY - 4 - p_x);
	if (id == 24) uchwyt.setPosition(plansza.leweX + (plansza.praweX- plansza.leweX) / 2 - p_x, plansza.gorneY - 4 - p_x);
	if (id == 25) uchwyt.setPosition(plansza.praweX - p_x, plansza.gorneY - 4 - p_x);
	if (id == 26) uchwyt.setPosition(plansza.praweX - p_x, plansza.gorneY - (plansza.gorneY - plansza.dolneY) / 2 - p_x);
	if (id == 27) uchwyt.setPosition(plansza.praweX - p_x, plansza.dolneY - p_x );
	if (id == 28) uchwyt.setPosition(plansza.leweX + (plansza.praweX - plansza.leweX) / 2 - p_x, plansza.dolneY - p_x);
}

void Uchwyt::UstawRozmiar(sf::RenderWindow& window, PozycjaKursora pozycja)
{
	if (CzyNadUchwytem(window, pozycja) == 0) {
		uchwyt.setSize(sf::Vector2f(6, 6));
		p_x = 0; p_y = 0;
	}
	else {
		uchwyt.setSize(sf::Vector2f(10, 10));
		p_x = 2; p_y = 2;
	}
}
