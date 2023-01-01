#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>
#include "Uzytkownik.h"
#include "Metody_pomocnicze.h"

#ifndef PLIK_Z_UZYTKOWNIKAMI.H
#define PLIK_Z_UZYTKOWNIKAMI.H

using namespace std;

class Plik_z_uzytkownikami {


private:
    string nazwaPlikuZUzytkownikami;
    string zamienDaneUzytkownikaNaLinieZDanymiOddzielonaPionowymiKreskami(Uzytkownik uzytkownik);
    Uzytkownik pobierzDaneUzytkownika(string daneJednegoUzytkownikaOddzielonePionowymiKreskami);
    bool czyPlikJestPusty(fstream &plikTekstowy);

public:
    Plik_z_uzytkownikami();
    void dopiszUzytkownikaDoPliku(Uzytkownik uzytkownicy);
    vector <Uzytkownik> wczytajUzytkownikowZPliku();

};
#endif
