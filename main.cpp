#include <iostream>
#include "Ksiazka_adresowa.h"

using namespace std;

int main() {

    Ksiazka_adresowa ksiazkaAdresowa("Uzytkownicy.txt","Adresat.txt");
    char choice;

    while (true) {

        if(ksiazkaAdresowa.czyUzytkownikJestZalogowany() != true) {

            choice = ksiazkaAdresowa.wybierzOpcjeZMenuGlownego();

            switch(choice) {

            case '1':
                ksiazkaAdresowa.rejestracjaUzytkownika();
                break;

            case '2':
                ksiazkaAdresowa.logowanieUzytkownika();
                break;

            case '9':
                exit(0);
            }
        } else {

            choice = ksiazkaAdresowa.wybierzOpcjeZMenuUzytkownika();

            switch (choice) {

        case '1':
            ksiazkaAdresowa.dodajAdresata();
            break;
        case '4':
            ksiazkaAdresowa.wyswietlWszystkichAdresatow();
            break;
        case '7':
            ksiazkaAdresowa.zmianaHaslaZalogowanegoUzytkownika();
            break;
        case '8':
            ksiazkaAdresowa.wylogowanie_uzytkownika();
            break;

            }

        }

    }

    return 0;
}
