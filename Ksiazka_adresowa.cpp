#include "Ksiazka_adresowa.h"
#include "Adresaci.h"
#include "Adresat_Menedzer.h"

void Ksiazka_adresowa::rejestracjaUzytkownika(){

    uzytkownikMenedzer.rejestracjaUzytkownika();

}

void Ksiazka_adresowa::wypisz_wszystkich_uzytkownikow(){

    uzytkownikMenedzer.wypisz_wszystkich_uzytkownikow();

}

void Ksiazka_adresowa::dodajAdresata(){

    adresat_menedzer.dodajAdresata();
}

void Ksiazka_adresowa::wyswietlWszystkichAdresatow(){

    adresat_menedzer.wyswietlWszystkichAdresatow();

}


