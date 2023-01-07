#ifndef ADRESAT_MENEDZER.H
#define ADRESAT_MENEDZER.H

#include <iostream>
#include <vector>
#include "Adresaci.h"
#include "Plik_z_Adresatami.h"
#include "Uzytkownik_Menedzer.h"


class AdresatMenedzer {

    vector <Adresat> adresaci;
    Adresat podajDaneNowegoAdresata();

    void wyswietlDaneAdresata(Adresat adresat);

    Adresat pobierzDaneAdresata();
    Plik_z_adresatami pliczek_z_adresatami;

public:

    const int idZalogowanegoUzytkownika;
    AdresatMenedzer(string nazwaPlikuZAdresatami) : pliczek_z_adresatami(nazwaPlikuZAdresatami){};
    void dodajAdresata();
    void wyswietlWszystkichAdresatow();
    int wczytajAdresatowZalogowanegoUzytkownikaZPliku();

};

#endif // ADRESAT_MENEDZER
