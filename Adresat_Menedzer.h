#ifndef ADRESATMENEDZER_H
#define ADRESATMENEDZER_H

#include <iostream>
#include <vector>

#include "Adresaci.h"
#include "Plik_z_Adresatami.h"


class AdresatMenedzer {

    Plik_z_adresatami pliczek_z_adresatami; // zapytac Paw³a o to - kiedy dam ta klase pod Adresata, wywala b³êdy. <<<--- zapytaæ.

    const int ID_ZALOGOWANEGO_UZYTKOWNIKA; // powstala stala aby zadna metoda nie zmienila jej.
    vector <Adresat> adresaci;
    void wyswietlDaneAdresata(Adresat adresat);
    Adresat podajDaneNowegoAdresata();
    Adresat pobierzDaneAdresata();

public:

    AdresatMenedzer (string nazwaPlikuZAdresatami, int idZalogowanegoUzytkownika) : pliczek_z_adresatami(nazwaPlikuZAdresatami), ID_ZALOGOWANEGO_UZYTKOWNIKA(idZalogowanegoUzytkownika){

        adresaci = pliczek_z_adresatami.wczytajAdresatowZalogowanegoUzytkownikaZPliku(ID_ZALOGOWANEGO_UZYTKOWNIKA);

    };
    void dodajAdresata();
    void wyswietlWszystkichAdresatow();
    void wczytajAdresatowZalogowanegoUzytkownikaZPliku(int idZalogowanegoUzytkownika);
    void ustaw_id_zalogowanego_uzytkownika(int idZalogowanegoUzytkownika);
    int ustawIdOstatniegoAdresata (int noweIdOstatniegoAdresata);
    void wyszukajAdresatowPoImieniu();
    void wyswietlIloscWyszukanychAdresatow(int iloscAdresatow);
    void wyszukajAdresatowPoNazwisku();
    int usunAdresata();
    int podajIdWybranegoAdresata();
    void edytujAdresata();
    void zaktualizujDaneWybranegoAdresata(Adresat adresat);
};

#endif // ADRESAT_MENEDZER
