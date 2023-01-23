#ifndef UZYTKOWNIKMENEDZER_H
#define UZYTKOWNIKMENEDZER_H


#include <iostream>
#include <vector>
#include "Uzytkownik.h"
#include "Plik_z_uzytkownikami.h"
#include <fstream>

using namespace std;

class UzytkownikMenedzer{

private:

    Uzytkownik podajDaneNowegoUzytkownika();
    int idZalogowanegoUzytkownika;

    vector <Uzytkownik> uzytkownicy;
    int pobierzIdNowegoUzytkownika();

    bool czyIstniejeLogin(string login);
    Uzytkownik  pobierzDaneUzytkownika(string daneJednegoUzytkownikaOddzielonePionowymiKreskami);
    Plik_z_uzytkownikami plikZUzytkownikami;

public:

    UzytkownikMenedzer(string nazwaPlikuZUzytkownikami) : plikZUzytkownikami(nazwaPlikuZUzytkownikami){

        idZalogowanegoUzytkownika = 0;
        uzytkownicy = plikZUzytkownikami.wczytajUzytkownikowZPliku();

    };
    void rejestracjaUzytkownika();
    void zmianaHaslaZalogowanegoUzytkownika();
    void wypisz_wszystkich_uzytkownikow();
    int pobierzIdZalogowanegoUzytkownika();
    int logowanieUzytkownika();
    void wylogowanie_Uzytkownika();
    bool czyUzytkownikJestZalogowany();


};


#endif // UZYTKOWNIK_MENEDZER
