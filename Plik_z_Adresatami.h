#ifndef PLIKZADRESATAMI_H
#define PLIKZADRESATAMI_H

#include <iostream>
#include <vector>
#include <fstream>


#include "Adresaci.h"
#include "Metody_pomocnicze.h"



using namespace std;



class Plik_z_adresatami{

    const string NAZWA_PLIKU_Z_ADRESATAMI ;
    fstream plikTekstowy;
    bool czyPlikJestPusty(fstream &plikTekstowy);
    Adresat pobierzDaneAdresata(string daneAdresataOddzielonePionowymiKreskami);
    int pobierzIdAdresataZDanychOddzielonychPionowymiKreskami(string daneJednegoAdresataOddzielonePionowymiKreskami);
    int pobierzIdUzytkownikaZDanychOddzielonychPionowymiKreskami(string daneJednegoAdresataOddzielonePionowymiKreskami);
    int idOstatniegoAdresata;

public:

    Plik_z_adresatami(string nazwaPlikuZAdresatami) : NAZWA_PLIKU_Z_ADRESATAMI(nazwaPlikuZAdresatami){

        idOstatniegoAdresata = 0;

    };
    vector <Adresat> wczytajAdresatowZalogowanegoUzytkownikaZPliku(int idZalogowanegoUzytkownika);
    string zamienDaneAdresataNaLinieZDanymiOddzielonymiPionowymiKreskami(Adresat adresat);
    bool dopiszAdresataDoPliku(Adresat adresat);
    int pobierz_ostatnie_id_adresata();
};

#endif // PLIK_Z_ADRESATAMI
