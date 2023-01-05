#ifndef PLIK_Z_ADRESATAMI.H
#define PLIK_Z_ADRESATAMI.H

#include <iostream>
#include <vector>
#include <fstream>


#include "Adresaci.h"
#include "Metody_pomocnicze.h"


using namespace std;



class Plik_z_adresatami{

    string nazwaPlikuZAdresatami = "Adresat.txt";
    fstream plikTekstowy;
    bool czyPlikJestPusty(fstream &plikTekstowy);
    Adresat pobierzDaneAdresata(string daneAdresataOddzielonePionowymiKreskami);
    int pobierzIdAdresataZDanychOddzielonychPionowymiKreskami(string daneJednegoAdresataOddzielonePionowymiKreskami);
    int pobierzIdUzytkownikaZDanychOddzielonychPionowymiKreskami(string daneJednegoAdresataOddzielonePionowymiKreskami);
    int idOstatniegoAdresata;

public:
    vector <Adresat> wczytajAdresatowZalogowanegoUzytkownikaZPliku(int idZalogowanegoUzytkownika);
    string zamienDaneAdresataNaLinieZDanymiOddzielonymiPionowymiKreskami(Adresat adresat);
    void dopiszAdresataDoPliku(Adresat adresat);
    int pobierz_ostatnie_id_adresata();

};

#endif // PLIK_Z_ADRESATAMI
