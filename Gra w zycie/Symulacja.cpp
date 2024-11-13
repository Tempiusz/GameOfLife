#include "Symulacja.h"

sf::RenderWindow Symulacja::window(
    sf::VideoMode(1600, 800), 
    "GRA W ZYCIE - CONWAY'S GAME OF LIFE", 
    sf::Style::Close | sf::Style::Titlebar
);

void Symulacja::TworzPrzyciskiStatyczne()
{
    elementInteraktywny.listaPrzyciskow.DodajPrzycisk(window.getSize().x - plansza.szerokoscPrawegoToolbara + 50, 70 , 200, 140, 1, "START"); 
    elementInteraktywny.listaPrzyciskow.DodajPrzycisk(window.getSize().x - plansza.szerokoscPrawegoToolbara + 50, 220, 200, 60, 2, "STOP");
    elementInteraktywny.listaPrzyciskow.DodajPrzycisk(window.getSize().x - plansza.szerokoscPrawegoToolbara + 50, 290, 200, 60, 3, "KROK");
    elementInteraktywny.listaPrzyciskow.DodajPrzycisk(window.getSize().x - plansza.szerokoscPrawegoToolbara + 50, 370, 200, 60, 6, "RESET");
    elementInteraktywny.listaPrzyciskow.DodajPrzycisk(window.getSize().x - plansza.szerokoscPrawegoToolbara + 50, 440, 200, 30, 4, "SZYBKOSC +");
    elementInteraktywny.listaPrzyciskow.DodajPrzycisk(window.getSize().x - plansza.szerokoscPrawegoToolbara + 50, 480, 200, 30, 5, "SZYBKOSC -");
    elementInteraktywny.listaPrzyciskow.DodajPrzycisk(window.getSize().x - 120, 5, 80, 20, 83, "Zakoncz");
    elementInteraktywny.listaPrzyciskow.DodajPrzycisk(window.getSize().x - plansza.szerokoscPrawegoToolbara + 50, 530, 200, 60, 7, "Brak granic");
    elementInteraktywny.listaPrzyciskow.DodajPrzycisk(3, 5, 40, 20, 51, "Plik");
    elementInteraktywny.listaPrzyciskow.DodajPrzycisk(47, 5, 80, 20, 52, "Symulacja");
}

void Symulacja::TworzUchwyty()
{
    for (int i = 21; i < 29; i++) {
        elementInteraktywny.listaPrzyciskow.DodajUchwyt(i, plansza);
    }
}

void Symulacja::RysujDynamicznie()
{   
    if (pozycja.CzyNadPlansza(plansza)) {
        if (pozycja.czyKliknietoLPM() || pozycja.czyKliknietoPPM()) {
            stan.UstawStan(1, 1);
            stan.UstawStan(6, 1);
            if (stan.ZwrocStan(7) == 1 && pozycja.czyKliknietoLPM()) {
                komorka.DodajKomorke(pozycja.px_x, pozycja.px_y, 'A');
            }
            if (stan.ZwrocStan(7) == 0 && pozycja.czyKliknietoPPM()) {
                komorka.UsunKomorke(pozycja.px_x, pozycja.px_y, 'A');
            }
        }
        else { 
            if (stan.ZwrocStan(6) == 1) stan.UstawStan(1, 0);
        }
    }
}


void Symulacja::Symuluj()
{     
    // --- Metody wywolywane tylko raz ---
    TworzPrzyciskiStatyczne();
    plansza.TworzRamkePrzyciskowGlownych(window);
    TworzUchwyty();
    listaNapisow.UstawCzcionke();
    listaNapisow.DodajNapisy();
    komorka.UstawRozmiar(plansza);
    elementInteraktywny.szablon.UstawPx(plansza);
    elementInteraktywny.szablon.TworzSzablony();
    

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            switch (event.type) {
            case sf::Event::Closed:
                window.close();
                break;
            }
            
            //OBSLUGA INTERAKCJI
            pozycja.PobierzPozycje(window);
            pozycja.PobierzZaokraglonaPozycje(window, plansza);
            elementInteraktywny.ObsluzElementyInteraktywne(komorka, plansza, window, stan, pozycja, kroki);
        }

        window.clear();
        plansza.RysujRamkePrzyciskowGlownych(window);
        plansza.RysujPlansze(window);        
        komorka.WyswietlKomorki(window);

        // ---- O B S L U G A     S T A N O W ----     
        if (stan.ZwrocStan(15) == 1) {
            if (czyZmieniacTryb == 0) {
                stan.UstawWartosc(7, 3);
                czyZmieniacTryb = 1;
            }
        }
        else {
            if (czyZmieniacTryb == 1) {
                stan.UstawWartosc(7, 1);
                czyZmieniacTryb = 0;
            }
        }

        // Podczas zmieniania rozmiaru planszy
        if (stan.ZwrocStan(11) == 1) {
            plansza.RysujRamkeZmianyRozmiaru(window, elementInteraktywny.zwrocTenUchwyt(), pozycja.x, pozycja.y);
        }  

        // Gdy rozmiar planszy zostanie zmieniony, szablony sie aktualizuj¹
        if (stan.ZwrocStan(10) == 1) {
            elementInteraktywny.szablon.TworzSzablony();
            komorka.UstawRozmiar(plansza);
            stan.UstawStan(10, 0);
        }

        elementInteraktywny.listaPrzyciskow.WyswietlUchwyty(window, plansza, pozycja);               

        //Zmiana trybu modyfikacji planszy
        if (stan.ZwrocStan(7) < 3) {
            if (pozycja.czyKliknietoLPM() == 1) stan.UstawWartosc(7, 1);
            else if (pozycja.czyKliknietoPPM() == 1) stan.UstawWartosc(7, 0);
        }

        //OBSLUGA SZABLONÓW
        if (stan.ZwrocStan(13) == 1) {
            
            elementInteraktywny.szablon.ObsluzUmieszczanieSzablonu(window, plansza, pozycja, stan, komorka);
            stan.UstawWartosc(7, 3);

            if (pozycja.czyKliknietoPPM() == 1) {
                stan.UstawStan(13, 0);
                stan.UstawWartosc(7, 1);
            }
        }
        
        //Obsluga modyfikacji planszy

        //OBSLUGA DYNAMICZNEGO RYSOWANIA
        if (stan.ZwrocStan(1) == 0) {
            RysujDynamicznie();
        }
        else if (stan.ZwrocStan(1) == 1 && stan.ZwrocStan(6) == 1) {
            RysujDynamicznie();
        }

        // Rysowanie siatki
        if (stan.ZwrocStan(4) == 1) {
            plansza.RysujSiatke(window);
        }



        // OBSLUGA WIZUALIZACJI OBSZARU OPTYMALIZACYJNEGO, rysuje siê na siatce, wiêc musi byæ po rysowaniu na siatce
        if (stan.ZwrocStan(3) == 1 && stan.ZwrocStan(8) == 1) {
            komorka.WizualizujOptymalizacje(window, plansza, stan);
        }

        if (stan.ZwrocStan(1) == 1) {
            if (pozycja.CzyNadPlansza(plansza)) {
                if (stan.ZwrocStan(7) == 1 && pozycja.czyKliknietoLPM()) {
                    komorka.DodajKomorke(pozycja.px_x, pozycja.px_y, 'A');
                }
                if (stan.ZwrocStan(7) == 0 && pozycja.czyKliknietoPPM()) {
                    komorka.UsunKomorke(pozycja.px_x, pozycja.px_y, 'A');
                }
            }
        }

        //SYMULACJA
        if (stan.ZwrocStan(1) == 0) {
            if (komorka.PobierzZbiorKomorek().size() == 0) {
                stan.UstawStan(1, 1);
                stan.UstawStan(6, 0);
            }
            komorka.Krok(window, plansza, stan, kroki);
        }        

        // Musi byæ przed wyœwietlaniem przyciskow poniewa¿ funkcje 
        // wyswietlajace przyciski sprawdzaj¹ czy kursor jest nad przyciskiem
        if (stan.ZwrocStan(15) == 1) {
            stan.UstawStan(15, 0);
        }

        //Wyswietlanie przyciskow i napisow
        if (stan.ZwrocStan(2) > 0) {
            elementInteraktywny.listaPrzyciskow.WyswietlPrzyciskiMenu(window, pozycja, stan);
        }

        elementInteraktywny.listaPrzyciskow.WyswietlPrzyciski(window, pozycja, stan);                           
        listaNapisow.WyswietlNapisy(window, stan, kroki, komorka, plansza);     

        window.display();       

        if (stan.ZwrocStan(1) == 0) {sf::sleep(sf::milliseconds(stan.ZwrocStan(17))); }
        else { sf::sleep(sf::milliseconds(1)); }
    }
}
