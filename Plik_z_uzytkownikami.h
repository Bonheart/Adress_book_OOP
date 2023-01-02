#ifndef PLIK_Z_UZYTKOWNIKAMI.H
#define PLIK_Z_UZYTKOWNIKAMI.H

#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>

#include "Uzytkownik.h"
#include "Metody_pomocnicze.h"

using namespace std;

class Plik_z_uzytkownikami {

    const string nazwaPlikuZUzytkownikami;
    fstream plikTekstowy;

    bool czyPlikJestPusty(fstream &plikTekstowy);
    string zamienDaneUzytkownikaNaLinieZDanymiOddzielonaPionowymiKreskami(Uzytkownik uzytkownik);
    Uzytkownik pobierzDaneUzytkownika(string daneJednegoUzytkownikaOddzielonePionowymiKreskami);

public:
    Plik_z_uzytkownikami(string NOWY) : nazwaPlikuZUzytkownikami(NOWY){};
    void dopiszUzytkownikaDoPliku(Uzytkownik uzytkownik);
    vector <Uzytkownik> wczytajUzytkownikowZPliku();

};
#endif
