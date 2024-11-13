#pragma once
class Stan
{
	int aktualnySzablon;
	int trybModyfikacji;
	int czyWysunieto;

	bool czyZatrzymano;
	bool czyWizualizowacOptymalizacje;
	bool czyRysowacSiatke;
	bool czyPlanszaAktualizowana;
	bool czyRysowacDynamicznie;
	bool czyDodawac;
	bool czyOptymalizowac;
	bool czyDodawanySzablon;
	bool czyZmienianyRozmiarPlanszy;
	bool czyZmienionoRozmiarPlanszy;
	bool czyBrakGranic;
	bool czyDodawaneSzablony;
	bool czyNadPrzyciskiem;
	bool czyObracac;

public:
	int szybkosc;
	Stan();
	void UstawStan(int id, bool stan);
	void UstawWartosc(int idWartosci, int wartosc);
	int ZwrocStan(int idStanu);
	void Przelacz(int idStanu);
};

