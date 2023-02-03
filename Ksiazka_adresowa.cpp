#include "Ksiazka_adresowa.h"


void Ksiazka_adresowa::rejestracjaUzytkownika() {

    uzytkownikMenedzer.rejestracjaUzytkownika();

}

void Ksiazka_adresowa::wypisz_wszystkich_uzytkownikow() {

    uzytkownikMenedzer.wypisz_wszystkich_uzytkownikow();

}

void Ksiazka_adresowa::zmianaHaslaZalogowanegoUzytkownika() {

    uzytkownikMenedzer.zmianaHaslaZalogowanegoUzytkownika();

}

void Ksiazka_adresowa::logowanieUzytkownika() {

    uzytkownikMenedzer.logowanieUzytkownika();

    if (uzytkownikMenedzer.czyUzytkownikJestZalogowany()) {

        adresat_menedzer = new AdresatMenedzer(NAZWA_PLIKU_Z_ADRESATAMI, uzytkownikMenedzer.pobierzIdZalogowanegoUzytkownika());

    }
}

int Ksiazka_adresowa::pobierzIdZalogowanegoUzytkownika() {

    return uzytkownikMenedzer.pobierzIdZalogowanegoUzytkownika();
}

void Ksiazka_adresowa::wylogowanie_uzytkownika() {

    cout << "user logged out" << endl;
    uzytkownikMenedzer.wylogowanie_Uzytkownika();
    delete adresat_menedzer;
    adresat_menedzer = NULL;

}


void Ksiazka_adresowa::dodajAdresata() {

    if(uzytkownikMenedzer.czyUzytkownikJestZalogowany()) {

        adresat_menedzer->dodajAdresata(); // jezeli pracuje na wskazniku, zeby wywolac metode na ktory wskazuje wskaznik, musze uzyc tej strzalki zamiast kropki.
    }

    else {
        cout << "najpierw sie zaloguj." << endl;
        system("pause");
    }
}

void Ksiazka_adresowa::wyswietlWszystkichAdresatow() {

    if(uzytkownikMenedzer.czyUzytkownikJestZalogowany()) {

        adresat_menedzer->wyswietlWszystkichAdresatow();

    }

    else {
        cout << "uzytkownik niezalogowany" << endl;
    }

}

char Ksiazka_adresowa::wybierzOpcjeZMenuUzytkownika() {

    return Metody_pomocnicze::wybierzOpcjeZMenuUzytkownika();

}

bool Ksiazka_adresowa::czyUzytkownikJestZalogowany() {

    return uzytkownikMenedzer.czyUzytkownikJestZalogowany();

}

char Ksiazka_adresowa::wybierzOpcjeZMenuGlownego() {

    return Metody_pomocnicze::wybierzOpcjeZMenuGlownego();

}

void Ksiazka_adresowa::wyszukajAdresatowPoImieniu() {

    if(uzytkownikMenedzer.czyUzytkownikJestZalogowany()==true)

        adresat_menedzer->wyszukajAdresatowPoImieniu();

    else
        cout << "uzytkownik niezalogowany" << endl;

}

void Ksiazka_adresowa::wyszukajAdresatowPoNazwisku() {

    if(uzytkownikMenedzer.czyUzytkownikJestZalogowany())

        adresat_menedzer->wyszukajAdresatowPoNazwisku();

    else
        cout << "uzytkownik niezalogowany" << endl;


}

int Ksiazka_adresowa::usunAdresata() {

    return adresat_menedzer->usunAdresata();

}

void Ksiazka_adresowa::edytujAdresata() {

    return adresat_menedzer -> edytujAdresata();

}
