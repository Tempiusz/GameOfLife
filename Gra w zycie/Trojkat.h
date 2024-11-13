#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
//NIEZWI¥ZANE Z PROGRAMEM

class Trojkat
{
private:
	std::vector<std::pair<int, int>> punkty;
	std::pair<int, int> a, b, c;

public:
	Trojkat();
	void RysujTenPierdolonyTrojkat(std::pair<int, int> a, std::pair<int, int> b, std::pair<int, int> c, int n, sf::RenderWindow& window);
};

