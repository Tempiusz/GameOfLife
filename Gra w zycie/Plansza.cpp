#include "Plansza.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <Windows.h>

int Plansza::getSpacing()
{
    return pixelSpacing;
}

void Plansza::UstawPixelSpacing(int spacing)
{
    pixelSpacing = spacing;
}

void Plansza::RysujPlansze(sf::RenderWindow& window)
{   
    
    PoprawRozdzielczosc(); 
    UstawGranicePlanszy(window);     
    RysujGranicePlanszy(window);
    RysujElementyMenu(window);        
}

void Plansza::RysujElementyMenu(sf::RenderWindow& window)
{
    for (int i = 0; i < 4; i++) {
        RysujLinie(window.getSize().x - szerokoscPrawegoToolbara + i, 0,
            window.getSize().x - szerokoscPrawegoToolbara + i, window.getSize().y,
            sf::Color(50, 50, 50), window);
    }

    // Ramka do gornego menu
    sf::RectangleShape ramkaMenuBar;
    ramkaMenuBar.setFillColor(sf::Color(50, 50, 50));
    ramkaMenuBar.setPosition(0, 0);
    ramkaMenuBar.setSize(sf::Vector2f(window.getSize().x, 32));
    window.draw(ramkaMenuBar);
}

void Plansza::RysujGranicePlanszy(sf::RenderWindow& window) 
{          
    sf::VertexArray square(sf::LinesStrip, 5);
    for (int i = 0; i < 5; ++i)
        square[i].color = sf::Color(120, 120, 120);

    for (int i = 0; i < 3; i++) {       
        square[0].position = sf::Vector2f(leweX - i, dolneY + i);
        square[1].position = sf::Vector2f(leweX - i, gorneY - i);
        square[2].position = sf::Vector2f(praweX + i, gorneY - i);
        square[3].position = sf::Vector2f(praweX + i, dolneY + i);
        square[4].position = sf::Vector2f(leweX - i, dolneY + i);           
        window.draw(square);
    }
}

void Plansza::UstawGranicePlanszy(sf::RenderWindow& window) 
{
    leweX = (window.getSize().x - szerokoscPrawegoToolbara - rozdzielczoscX * pixelSpacing) / 2;
    praweX = (window.getSize().x - szerokoscPrawegoToolbara - rozdzielczoscX * pixelSpacing) / 2 + rozdzielczoscX * pixelSpacing;
    gorneY = (window.getSize().y + 30 - rozdzielczoscY * pixelSpacing) / 2;
    dolneY = (window.getSize().y + 30 - rozdzielczoscY * pixelSpacing) / 2 + rozdzielczoscY * pixelSpacing;
}

void Plansza::RysujSiatke(sf::RenderWindow& window)
{
    for (int x = leweX; x <= praweX; x += pixelSpacing) {
        RysujLinie(x, dolneY, x, gorneY, sf::Color(100, 100, 100), window);
    }
    for (int y = gorneY; y <= dolneY; y += pixelSpacing) {
        RysujLinie(leweX, y, praweX, y, sf::Color(100, 100, 100), window);
    }
}

void Plansza::ZmienRozdzielczosc(int roznicaX, int roznicaY)
{
    roznicaX -= roznicaX % pixelSpacing;
    roznicaY -= roznicaY % pixelSpacing;

    roznicaX /= pixelSpacing;
    roznicaY /= pixelSpacing;

    rozdzielczoscX += roznicaX;
    rozdzielczoscY += roznicaY;    
}

void Plansza::TworzRamkePrzyciskowGlownych(sf::RenderWindow& window)
{    
    ramka.setPosition(window.getSize().x - szerokoscPrawegoToolbara, 0);
    ramka.setSize(sf::Vector2f(szerokoscPrawegoToolbara, window.getSize().y));
    ramka.setFillColor(sf::Color(20, 20, 30));
}

void Plansza::RysujRamkePrzyciskowGlownych(sf::RenderWindow& window)
{
    window.draw(ramka);
}

void Plansza::RysujRamkeZmianyRozmiaru(sf::RenderWindow& window, int id, int x, int y)
{
    //ograniczenia X i Y ramki

    switch (id) {
    case 21:
        if (x > praweX) x = praweX;
        if (y < gorneY) y = gorneY;     
        break;
    case 22:
        if (x > praweX) x = praweX;
        break;
    case 23:
        if (x > praweX) x = praweX;
        if (y > dolneY) y = dolneY;
        if (y < 32) y = 32;
        break;
    case 24:
        if (y > dolneY) y = dolneY;
        if (y < 32) y = 32;
        break;
    case 25:
        if (x < leweX) x = leweX;
        if (y > dolneY) y = dolneY;
        if (x > window.getSize().x - szerokoscPrawegoToolbara) x = window.getSize().x - szerokoscPrawegoToolbara;
        if (y < 32) y = 32;
        break;
    case 26:
        if (x < leweX) x = leweX;
        if (x > window.getSize().x - szerokoscPrawegoToolbara) x = window.getSize().x - szerokoscPrawegoToolbara;
        break;
    case 27:
        if (x < leweX) x = leweX;
        if (y < gorneY) y = gorneY;
        if (x > window.getSize().x - szerokoscPrawegoToolbara) x = window.getSize().x - szerokoscPrawegoToolbara;
        break;
    case 28:
        if (y < gorneY) y = gorneY;
        break;
    }

    //rysowanie ramki
    sf::VertexArray square(sf::LinesStrip, 5);
    if (id == 21) {     
        square[0].position = sf::Vector2f(x, y);
        square[1].position = sf::Vector2f(x, gorneY);
        square[2].position = sf::Vector2f(praweX, gorneY);
        square[3].position = sf::Vector2f(praweX, y);
        square[4].position = square[0].position;
    }
    if (id == 22) {
        square[0].position = sf::Vector2f(x, dolneY);
        square[1].position = sf::Vector2f(x, gorneY);
        square[2].position = sf::Vector2f(praweX, gorneY);
        square[3].position = sf::Vector2f(praweX, dolneY);
        square[4].position = square[0].position;
    }
    if (id == 23) {
        square[0].position = sf::Vector2f(x, dolneY);
        square[1].position = sf::Vector2f(x, y);
        square[2].position = sf::Vector2f(praweX, y);
        square[3].position = sf::Vector2f(praweX, dolneY);
        square[4].position = square[0].position;
    }
    if (id == 24) {
        square[0].position = sf::Vector2f(leweX, dolneY);
        square[1].position = sf::Vector2f(leweX, y);
        square[2].position = sf::Vector2f(praweX, y);
        square[3].position = sf::Vector2f(praweX, dolneY);
        square[4].position = square[0].position;
    }
    if (id == 25) {
        square[0].position = sf::Vector2f(leweX, dolneY);
        square[1].position = sf::Vector2f(leweX, y);
        square[2].position = sf::Vector2f(x, y);
        square[3].position = sf::Vector2f(x, dolneY);
        square[4].position = square[0].position;
    }
    if (id == 26) {
        square[0].position = sf::Vector2f(leweX, dolneY);
        square[1].position = sf::Vector2f(leweX, gorneY);
        square[2].position = sf::Vector2f(x, gorneY);
        square[3].position = sf::Vector2f(x, dolneY);
        square[4].position = square[0].position;
    }
    if (id == 27) {
        square[0].position = sf::Vector2f(leweX, y);
        square[1].position = sf::Vector2f(leweX, gorneY);
        square[2].position = sf::Vector2f(x, gorneY);
        square[3].position = sf::Vector2f(x, y);
        square[4].position = square[0].position;
    }
    if (id == 28) {
        square[0].position = sf::Vector2f(leweX, y);
        square[1].position = sf::Vector2f(leweX, gorneY);
        square[2].position = sf::Vector2f(praweX, gorneY);
        square[3].position = sf::Vector2f(praweX, y);
        square[4].position = square[0].position;
    }

    // Ustawienia koloru linii obwodu
    for (int i = 0; i < 5; ++i)
        square[i].color = sf::Color(150, 150, 150);

    window.draw(square);
}

void Plansza::PoprawRozdzielczosc()
{
    if (rozdzielczoscX * pixelSpacing > 1300) rozdzielczoscX = (1300 - 1300 % pixelSpacing) / pixelSpacing;
    if (rozdzielczoscY * pixelSpacing > 770) rozdzielczoscY = (770 - 770 % pixelSpacing) / pixelSpacing;

    if (rozdzielczoscX * pixelSpacing < 5) rozdzielczoscX = 5;
    if (rozdzielczoscY * pixelSpacing < 5) rozdzielczoscY = 5;

    if (pixelSpacing > 30) pixelSpacing = 30;
    if (pixelSpacing < 2) pixelSpacing = 2;

}

void Plansza::RysujLinie(int x1, int y1, int x2, int y2, sf::Color kolor, sf::RenderWindow& window)
{
    sf::Vertex line[] = {
           sf::Vertex(sf::Vector2f(x1, y1), sf::Color(kolor)),
           sf::Vertex(sf::Vector2f(x2, y2), sf::Color(kolor))
    };
    window.draw(line, 2, sf::Lines);
}