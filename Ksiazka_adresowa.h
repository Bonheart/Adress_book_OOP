#include <iostream>
#include "Uzytkownik_Menedzer.h"
#include "Adresat_Menedzer.h"

using namespace std;

class Ksiazka_adresowa {

    UzytkownikMenedzer uzytkownikMenedzer;
    AdresatMenedzer adresat_menedzer;

public:

    Ksiazka_adresowa(string nazwaPlikuZUzytkownikami): uzytkownikMenedzer(nazwaPlikuZUzytkownikami) {

        uzytkownikMenedzer.wczytajUzytkownikowZPliku();
    };



    void rejestracjaUzytkownika();
    void wypisz_wszystkich_uzytkownikow();

    void  podajDaneNowegoAdresata();
    void dodajAdresata();
    void wyswietlWszystkichAdresatow();
    void wyswietlDaneAdresata();


};
