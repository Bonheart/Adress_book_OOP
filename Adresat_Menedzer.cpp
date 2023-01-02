#ifndef ADRESAT_MENEDZER.CPP
#define ADRESAT_MENEDZER.CPP

#include <iostream>
#include "Adresat_Menedzer.h"
#include "Adresaci.h"
#include "Metody_pomocnicze.h"

Adresat AdresatMenedzer::podajDaneNowegoAdresata(int idOstatniegoAdresata)
{
    Adresat adresat;

    adresat.id = ++idOstatniegoAdresata;
    adresat.idUzytkownika = idZalogowanegoUzytkownika;

    cout << "Podaj imie: ";
    adresat.imie = Metody_pomocnicze::wczytajLinie();
    adresat.imie = zamienPierwszaLitereNaDuzaAPozostaleNaMale(adresat.imie);

    cout << "Podaj nazwisko: ";
    adresat.nazwisko = wczytajLinie();
    adresat.nazwisko = zamienPierwszaLitereNaDuzaAPozostaleNaMale(adresat.nazwisko);

    cout << "Podaj numer telefonu: ";
    adresat.numerTelefonu = wczytajLinie();

    cout << "Podaj email: ";
    adresat.email = wczytajLinie();

    cout << "Podaj adres: ";
    adresat.adres = wczytajLinie();

    return adresat;
}



#endif // ADRESAT_MENEDZER
