#include <iostream>
#include "Uzytkownik_Menedzer.h"
#include "Adresat_Menedzer.h"
#include "Adresaci.h"


using namespace std;

class Ksiazka_adresowa {

    UzytkownikMenedzer uzytkownikMenedzer;
    AdresatMenedzer adresat_menedzer;

public:

    Ksiazka_adresowa(string nazwaPlikuZUzytkownikami, string nazwaPlikuZAdresatami): uzytkownikMenedzer(nazwaPlikuZUzytkownikami), adresat_menedzer(nazwaPlikuZAdresatami) {

        uzytkownikMenedzer.wczytajUzytkownikowZPliku();

    };

    void rejestracjaUzytkownika();
    void wypisz_wszystkich_uzytkownikow();
    void logowanieUzytkownika();

    void  podajDaneNowegoAdresata();
    void dodajAdresata();
    void wyswietlWszystkichAdresatow();
    void wyswietlDaneAdresata();
    void wczytajAdresatowZalogowanegoUzytkownikaZPliku(int idZalogowanegoUzytkownika);
    void zmianaHaslaZalogowanegoUzytkownika();
    void wylogowanie_uzytkownika();
};
