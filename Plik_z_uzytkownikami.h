#ifndef PLIKZUZYTKOWNIKAMI_H
#define PLIKZUZYTKOWNIKAMI_H

#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>

#include "Uzytkownik.h"
#include "Metody_pomocnicze.h"
#include "Pochodna_pliku.h"

using namespace std;

class Plik_z_uzytkownikami: public Pochodna {

   // const string NAZWA_PLIKU_Z_UZYTKOWNIKAMI;
   // fstream plikTekstowy;

   // bool czyPlikJestPusty(fstream &plikTekstowy);
    string zamienDaneUzytkownikaNaLinieZDanymiOddzielonaPionowymiKreskami(Uzytkownik uzytkownik);
    Uzytkownik pobierzDaneUzytkownika(string daneJednegoUzytkownikaOddzielonePionowymiKreskami);

public:
    Plik_z_uzytkownikami(string nazwa_pliku): Pochodna(nazwa_pliku){}; // to samo co w przypadku pliku z adresatami.
    void dopiszUzytkownikaDoPliku(Uzytkownik uzytkownik);
    vector <Uzytkownik> wczytajUzytkownikowZPliku();
    void zapiszWszystkichUzytkownikowDoPliku(vector <Uzytkownik> uzytkownicy);

};
#endif
