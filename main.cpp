#include <iostream>
#include "Ksiazka_adresowa.h"

using namespace std;

int main() {
 //  Ksiazka_adresowa ksiazkaAdresowa("Uzytkownicy.txt", "Adresaci.txt");
 Ksiazka_adresowa ksiazkaAdresowa("Adresat.txt");

  //  ksiazkaAdresowa.wypisz_wszystkich_uzytkownikow();
   // ksiazkaAdresowa.rejestracjaUzytkownika();
   // ksiazkaAdresowa.wypisz_wszystkich_uzytkownikow();
   ksiazkaAdresowa.dodajAdresata();
   ksiazkaAdresowa.dodajAdresata();
   ksiazkaAdresowa.wyswietlWszystkichAdresatow();



    return 0;
}
