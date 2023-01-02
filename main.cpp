#include <iostream>
#include "Ksiazka_adresowa.h"

using namespace std;

int main() {
    Ksiazka_adresowa KsiazkaAdresowa("Uzytkownicy.txt");
    KsiazkaAdresowa.wypisz_wszystkich_uzytkownikow();
    KsiazkaAdresowa.rejestracjaUzytkownika();
    KsiazkaAdresowa.wypisz_wszystkich_uzytkownikow();

    return 0;
}
