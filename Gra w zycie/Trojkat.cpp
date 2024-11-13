#include "Trojkat.h"
//NIEZWI¥ZANE Z PROGRAMEM

Trojkat::Trojkat()
{
	
}

void Trojkat::RysujTenPierdolonyTrojkat(std::pair<int, int> a, std::pair<int, int> b, std::pair<int, int> c, int n, sf::RenderWindow& window)
{
	std::pair<int, int> v1, v2, v3;
	int j;

	if (n > 0) 
	{
		v1.first = 0.5 * (a.first + b.first);
		v2.first = 0.5 * (a.first + c.first);
		v3.first = 0.5 * (c.first + b.first);

		v1.second = 0.5 * (a.second + b.second);
		v2.second = 0.5 * (a.second + c.second);
		v3.second = 0.5 * (c.second + b.second);

		

		this->RysujTenPierdolonyTrojkat(a, v2, v1, n - 1,  window);
		this->RysujTenPierdolonyTrojkat(c, v3, v2, n - 1,  window);
		this->RysujTenPierdolonyTrojkat(b, v1, v3, n - 1,  window);
		this->RysujTenPierdolonyTrojkat(v1, v2, v3, n - 1, window);
	}
	else
	{
		sf::VertexArray triangle(sf::LinesStrip, 4);
		triangle[0].position = sf::Vector2f(a.first, a.second);
		triangle[1].position = sf::Vector2f(b.first, b.second);
		triangle[2].position = sf::Vector2f(c.first, c.second);
		triangle[3].position = triangle[0].position;
		window.draw(triangle);
	}
}
