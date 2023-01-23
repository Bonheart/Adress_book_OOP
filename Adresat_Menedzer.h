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
    const int ID_ZALOGOWANEGO_UZYTKOWNIKA; // powstala stala aby zadna metoda nie zmienila jej.

public:

    AdresatMenedzer (string nazwaPlikuZAdresatami, int idZalogowanegoUzytkownika) : pliczek_z_adresatami(nazwaPlikuZAdresatami), ID_ZALOGOWANEGO_UZYTKOWNIKA(idZalogowanegoUzytkownika){

        adresaci = pliczek_z_adresatami.wczytajAdresatowZalogowanegoUzytkownikaZPliku(ID_ZALOGOWANEGO_UZYTKOWNIKA);

    };
    void dodajAdresata();
    void wyswietlWszystkichAdresatow();
    void wczytajAdresatowZalogowanegoUzytkownikaZPliku(int idZalogowanegoUzytkownika);
    void ustaw_id_zalogowanego_uzytkownika(int idZalogowanegoUzytkownika);
    int ustawIdOstatniegoAdresata (int noweIdOstatniegoAdresata);
};

#endif // ADRESAT_MENEDZER
