#include <iostream>
#include "Uzytkownik_Menedzer.h"
#include "Adresat_Menedzer.h"
#include "Adresaci.h"
#include "Metody_pomocnicze.h"


using namespace std;

class Ksiazka_adresowa {

    UzytkownikMenedzer uzytkownikMenedzer;
    AdresatMenedzer *adresat_menedzer;
    const string NAZWA_PLIKU_Z_ADRESATAMI;

public:

    Ksiazka_adresowa(string nazwaPlikuZUzytkownikami, string nazwaPlikuZAdresatami): uzytkownikMenedzer(nazwaPlikuZUzytkownikami), NAZWA_PLIKU_Z_ADRESATAMI(nazwaPlikuZAdresatami) {

        adresat_menedzer = NULL; // w konstruktorze od kopa ustawiam na NULL, zeby nie spocic sie pozniej.

    };
    ~Ksiazka_adresowa(){ //sprzata dana klase po robocie.

        delete adresat_menedzer;
        adresat_menedzer = NULL;

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
    int pobierzIdZalogowanegoUzytkownika();
    bool czyUzytkownikJestZalogowany();
    void wyszukajAdresatowPoImieniu();
    void wyszukajAdresatowPoNazwisku();
    int usunAdresata();

    char wybierzOpcjeZMenuUzytkownika();
    char wybierzOpcjeZMenuGlownego();
};
