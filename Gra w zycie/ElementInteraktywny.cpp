#include "ElementInteraktywny.h"

void ElementInteraktywny::ObsluzElementyInteraktywne(
    Komorka& komorka, Plansza& plansza, sf::RenderWindow& window, Stan& stan, PozycjaKursora& pozycja, int& kroki)
{
    if (pozycja.CzyNadObszaremEdycji(plansza, window) == 0) { // nie skanuj przyciskow, jezeli kursor nie jest blisko nich
        for (Przycisk& przyciskStatyczny : listaPrzyciskow.ZwrocZbiorPrzyciskowStatycznych()) {
            if (przyciskStatyczny.CzyKliknieto(window, pozycja, stan)) {
                ObsluzPrzycisk(przyciskStatyczny.zwrocID(), komorka, plansza, window, stan, kroki);
            }
        }
    }
    if (stan.ZwrocStan(2) > 0) { //przyciski sa skanowane tylko gdy s¹ wysuniête aby oszczêdzaæ zasoby
        for (Przycisk& przyciskMenu : listaPrzyciskow.ZwrocZbiorPrzyciskowMenu()) {
            if (przyciskMenu.CzyKliknieto(window, pozycja, stan)) {
                ObsluzPrzycisk(przyciskMenu.zwrocID(), komorka, plansza, window, stan, kroki);
            }
        }      
    }
    for (Uchwyt& uchwyt : listaPrzyciskow.ZwrocListeUchwytow()) {  
        
        if (stan.ZwrocStan(11) == 0) {
            uchwyt.CzyKliknieto(window, pozycja, stan, tenUchwyt);        
        }        

        uchwyt.ZmieniajRozmiarPlanszy(window, plansza, pozycja, tenUchwyt, komorka, stan, kroki);
    }
}

void ElementInteraktywny::ObsluzPrzycisk(
    int id, Komorka& komorka, Plansza& plansza, 
    sf::RenderWindow& window, Stan& stan, 
    int& kroki)
{
    switch (id) {
    case 1:
        stan.UstawStan(1, 0);
        break;
    case 2:
        stan.UstawStan(6, 0);
        stan.UstawStan(1, 1);
        break;
    case 3:
        stan.UstawStan(6, 0);
        stan.UstawStan(1, 1);
        komorka.Krok(window, plansza, stan, kroki);
        break;
    case 4:       
        if (stan.ZwrocStan(17) > 1) {
            stan.szybkosc = stan.szybkosc - 5;
        }
        if (stan.ZwrocStan(17) == 0) {
            stan.szybkosc = 1;
        }
        break;
    case 5:
        if (stan.ZwrocStan(17) == 1) {
            stan.szybkosc = 5;
        }
        else if (stan.ZwrocStan(17) < 100) {
            stan.szybkosc = stan.szybkosc + 5;
        }
        break;
    case 6:
        komorka.UsunWszystko(kroki);
        stan.UstawStan(1, 1);
        stan.UstawStan(6, 0);
        break;
    case 7:
        stan.Przelacz(12);
        break;
    case 51:
    case 52:
        if (stan.ZwrocStan(2) == 0) {
            DodajPrzyciskiWysuwane(id);
            stan.UstawWartosc(2, 1);
        }
        else { stan.UstawWartosc(2, 0); listaPrzyciskow.usunZbiorPrzyciskowMenu(); }
        break;
    case 54:
        exit(0);    
    case 83:
        exit(0);        
    case 101:
        if (stan.ZwrocStan(2) == 1) {            
            listaPrzyciskow.DodajPrzycisk(84, 53, 180, 20, 141, "Glider");
            listaPrzyciskow.DodajPrzycisk(84, 74, 180, 20, 142, "Hammerhead");
            listaPrzyciskow.DodajPrzycisk(84, 95, 180, 20, 143, "Glider Factory");
            listaPrzyciskow.DodajPrzycisk(84, 116, 180, 20, 144, "Cloverleaf");
            listaPrzyciskow.DodajPrzycisk(84, 137, 180, 20, 145, "Vampire");
            listaPrzyciskow.DodajPrzycisk(84, 158, 180, 20, 146, "Slow Spaceship");
            listaPrzyciskow.DodajPrzycisk(84, 179, 180, 20, 147, "Canada Goose");
            listaPrzyciskow.DodajPrzycisk(84, 200, 180, 20, 148, "Converter");
            listaPrzyciskow.DodajPrzycisk(84, 221, 180, 20, 149, "Short Wire");
            listaPrzyciskow.DodajPrzycisk(84, 242, 180, 20, 150, "Glider Mess");
            listaPrzyciskow.DodajPrzycisk(84, 263, 180, 20, 151, "Very Big Spaceship");
            listaPrzyciskow.DodajPrzycisk(84, 284, 180, 20, 152, "Horizontal spaceship");
            listaPrzyciskow.DodajPrzycisk(84, 305, 180, 20, 153, "Cup");
            stan.UstawWartosc(2, 2);
            
        }        
        break;
    case 105:
        exit(0);
        break;
    case 111:
        stan.Przelacz(3);
        break; 
    case 113:
        stan.UstawStan(1, 1);
        komorka.UsunWszystko(kroki);
        stan.UstawStan(10, 1);
        if (plansza.rozdzielczoscX * plansza.getSpacing() < 1600 && plansza.rozdzielczoscY * plansza.getSpacing() < 800) {
            plansza.pixelSpacing += 1;
        }
        if (plansza.getSpacing() <= 30) szablon.UstawPx(plansza);
        break;
    case 114:
        stan.UstawStan(1, 1);
        stan.UstawStan(10, 1);
        komorka.UsunWszystko(kroki);
        if (plansza.pixelSpacing > 2) {
            plansza.pixelSpacing -= 1;
        }
        if (plansza.getSpacing() <= 30) szablon.UstawPx(plansza);
        break;

    case 115:
        stan.Przelacz(4);
        break;

    case 116:
        stan.Przelacz(8);
        break;
    case 141:
    case 142:
    case 143:
    case 144:
    case 145:     
    case 146:
    case 147:
    case 148:
    case 149:
    case 150:
    case 151:
    case 152:
    case 153:
        szablon.NadajID(id);
        stan.UstawStan(13, 1);
        stan.UstawWartosc(14, id - 140);
        break;        
    }
}

void ElementInteraktywny::DodajPrzyciskiWysuwane(int id)
{
    switch (id) {
    case 51:
        listaPrzyciskow.usunZbiorPrzyciskowMenu();
        listaPrzyciskow.DodajPrzycisk(3, 33, 80, 20, 101, "Szablony");
        listaPrzyciskow.DodajPrzycisk(3, 54, 80, 20, 105, "Zakoncz");        
        break;

    case 52:
        listaPrzyciskow.usunZbiorPrzyciskowMenu();
        listaPrzyciskow.DodajPrzycisk(47, 33, 180, 20, 111, "Wizualizacja optymalizacji");
        listaPrzyciskow.DodajPrzycisk(47, 54, 180, 20, 113, "Powieksz"); 
        listaPrzyciskow.DodajPrzycisk(47, 75, 180, 20, 114, "Pomniejsz");
        listaPrzyciskow.DodajPrzycisk(47, 96, 180, 20, 115, "Rysuj siatke");
        listaPrzyciskow.DodajPrzycisk(47, 117, 180, 20, 116, "Optymalizacja");
        break;
    }
}

int ElementInteraktywny::zwrocTenUchwyt()
{
    return tenUchwyt;
}
