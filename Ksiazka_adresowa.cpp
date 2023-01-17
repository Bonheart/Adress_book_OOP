#include "Ksiazka_adresowa.h"


void Ksiazka_adresowa::rejestracjaUzytkownika(){

    uzytkownikMenedzer.rejestracjaUzytkownika();

}

void Ksiazka_adresowa::wypisz_wszystkich_uzytkownikow(){

    uzytkownikMenedzer.wypisz_wszystkich_uzytkownikow();

}

void Ksiazka_adresowa::zmianaHaslaZalogowanegoUzytkownika(){

    uzytkownikMenedzer.zmianaHaslaZalogowanegoUzytkownika();

}

void Ksiazka_adresowa::logowanieUzytkownika(){

    uzytkownikMenedzer.logowanieUzytkownika();
    int id_zalogowanego_uzytkownika = uzytkownikMenedzer.pobierzIdZalogowanegoUzytkownika(); // sta�a ktora do ktorej zgarne idka zalogowanego uzytkownika.
    adresat_menedzer.ustaw_id_zalogowanego_uzytkownika(id_zalogowanego_uzytkownika);
}

void Ksiazka_adresowa::wylogowanie_uzytkownika(){

cout << "user logged out" << endl;
    uzytkownikMenedzer.wylogowanie_Uzytkownika();

}


void Ksiazka_adresowa::dodajAdresata(){

    adresat_menedzer.dodajAdresata();
}

void Ksiazka_adresowa::wyswietlWszystkichAdresatow(){

    adresat_menedzer.wyswietlWszystkichAdresatow();

}
