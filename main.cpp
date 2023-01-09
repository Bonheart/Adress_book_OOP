#include <iostream>
#include "Ksiazka_adresowa.h"

using namespace std;

int main() {
  Ksiazka_adresowa ksiazkaAdresowa("Uzytkownicy.txt");

  // Ksiazka_adresowa ksiazkaAdresowa("Adresat.txt");


 //   ksiazkaAdresowa.rejestracjaUzytkownika();
    ksiazkaAdresowa.logowanieUzytkownika();
    ksiazkaAdresowa.zmianaHaslaZalogowanegoUzytkownika();
    ksiazkaAdresowa.wylogowanie_uzytkownika();
    ksiazkaAdresowa.wypisz_wszystkich_uzytkownikow();


/*
    ksiazkaAdresowa.wyswietlWszystkichAdresatow();
    ksiazkaAdresowa.dodajAdresata();
    ksiazkaAdresowa.wyswietlWszystkichAdresatow();
*/
    return 0;
}
