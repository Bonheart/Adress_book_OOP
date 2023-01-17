#ifndef ADRESATMENEDZER_H
#define ADRESATMENEDZER_H

#include <iostream>
#include <vector>

#include "Adresaci.h"
#include "Plik_z_Adresatami.h"


class AdresatMenedzer {

    Adresat podajDaneNowegoAdresata();

    void wyswietlDaneAdresata(Adresat adresat);

    Adresat pobierzDaneAdresata();
    Plik_z_adresatami pliczek_z_adresatami;
    vector <Adresat> adresaci;
    int idZalogowanegoUzytkownika;

public:

    AdresatMenedzer (string nazwaPlikuZAdresatami) : pliczek_z_adresatami(nazwaPlikuZAdresatami){};
    void dodajAdresata();
    void wyswietlWszystkichAdresatow();
    void wczytajAdresatowZalogowanegoUzytkownikaZPliku(int idZalogowanegoUzytkownika);
    void ustaw_id_zalogowanego_uzytkownika(int idZalogowanegoUzytkownika);


};

#endif // ADRESAT_MENEDZER
