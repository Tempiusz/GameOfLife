#include "Stan.h"
#include <iostream>

Stan::Stan()
{
	szybkosc = 20;
	aktualnySzablon = 0;
	trybModyfikacji = 1;
	czyWysunieto = 0;

	czyZatrzymano = 1;
	czyWizualizowacOptymalizacje = 1;
	czyRysowacSiatke = 1;
	czyPlanszaAktualizowana = 0;
	czyRysowacDynamicznie = 0;
	trybModyfikacji = 1;
	czyOptymalizowac = 1;
	czyDodawanySzablon = 0;
	czyZmienianyRozmiarPlanszy = 0;
	czyZmienionoRozmiarPlanszy = 0;
	czyBrakGranic = 1;
	czyDodawaneSzablony = 0;
	czyNadPrzyciskiem = 0;
	czyObracac = 0;

}

void Stan::UstawStan(int idStanu, bool stan)
{
	if (idStanu == 1) czyZatrzymano					= stan;
	
	if (idStanu == 3) czyWizualizowacOptymalizacje	= stan;
	if (idStanu == 4) czyRysowacSiatke				= stan;
	if (idStanu == 5) czyPlanszaAktualizowana		= stan;
	if (idStanu == 6) czyRysowacDynamicznie			= stan;

	if (idStanu == 8) czyOptymalizowac				= stan;
	if (idStanu == 9) czyDodawanySzablon			= stan;
	if (idStanu == 10) czyZmienionoRozmiarPlanszy	= stan;
	if (idStanu == 11) czyZmienianyRozmiarPlanszy	= stan;
	if (idStanu == 12) czyBrakGranic				= stan;
	if (idStanu == 13) czyDodawaneSzablony			= stan;

	if (idStanu == 15) czyNadPrzyciskiem			= stan; 
	if (idStanu == 16)  czyObracac					= stan; 	 	
}

void Stan::UstawWartosc(int idWartosci, int wartosc)
{
	if (idWartosci == 2) czyWysunieto				= wartosc;
	if (idWartosci == 14) aktualnySzablon			= wartosc;
	if (idWartosci == 7) trybModyfikacji			= wartosc;
	if (idWartosci == 17) szybkosc					= wartosc;
}



int Stan::ZwrocStan(int idStanu)
{
	if (idStanu == 1) return czyZatrzymano;
	if (idStanu == 2) return czyWysunieto;
	if (idStanu == 3) return czyWizualizowacOptymalizacje;
	if (idStanu == 4) return czyRysowacSiatke;
	if (idStanu == 5) return czyPlanszaAktualizowana;
	if (idStanu == 6) return czyRysowacDynamicznie;
	if (idStanu == 7) return trybModyfikacji;
	if (idStanu == 8) return czyOptymalizowac;
	if (idStanu == 9) return czyDodawanySzablon;
	if (idStanu == 10) return czyZmienionoRozmiarPlanszy;
	if (idStanu == 11) return czyZmienianyRozmiarPlanszy;
	if (idStanu == 12) return czyBrakGranic;
	if (idStanu == 13) return czyDodawaneSzablony;
	if (idStanu == 14) return aktualnySzablon;
	if (idStanu == 15) return czyNadPrzyciskiem;
	if (idStanu == 16) return czyObracac;
	if (idStanu == 17) return szybkosc;
}

void Stan::Przelacz(int idStanu)
{
	if (ZwrocStan(idStanu) == 0) {
		UstawStan(idStanu, 1);
	} else { UstawStan(idStanu, 0); }
}


