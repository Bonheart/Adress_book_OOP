#include <iostream>
#include "Uzytkownik_Menedzer.h"
#include "Adresat_Menedzer.h"


using namespace std;

class Ksiazka_adresowa {

    UzytkownikMenedzer uzytkownikMenedzer;
  // AdresatMenedzer adresat_menedzer;

public:

    Ksiazka_adresowa(string nazwaPlikuZUzytkownikami): uzytkownikMenedzer(nazwaPlikuZUzytkownikami) {

        uzytkownikMenedzer.wczytajUzytkownikowZPliku();

   };

/*
Ksiazka_adresowa(string nazwaPlikuZAdresatami):adresat_menedzer(nazwaPlikuZAdresatami) {

 adresat_menedzer.wczytajAdresatowZalogowanegoUzytkownikaZPliku();

 };
*/

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
