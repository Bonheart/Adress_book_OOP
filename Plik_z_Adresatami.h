#ifndef PLIKZADRESATAMI_H
#define PLIKZADRESATAMI_H

#include <iostream>
#include <vector>
#include <fstream>


#include "Adresaci.h"
#include "Metody_pomocnicze.h"



using namespace std;



class Plik_z_adresatami{

    const string nazwaPlikuZAdresatami ;
    fstream plikTekstowy;
    bool czyPlikJestPusty(fstream &plikTekstowy);
    Adresat pobierzDaneAdresata(string daneAdresataOddzielonePionowymiKreskami);
    int pobierzIdAdresataZDanychOddzielonychPionowymiKreskami(string daneJednegoAdresataOddzielonePionowymiKreskami);
    int pobierzIdUzytkownikaZDanychOddzielonychPionowymiKreskami(string daneJednegoAdresataOddzielonePionowymiKreskami);
    int idOstatniegoAdresata;

public:

    Plik_z_adresatami(string NOWY) : nazwaPlikuZAdresatami(NOWY){};
    vector <Adresat> wczytajAdresatowZalogowanegoUzytkownikaZPliku(int idZalogowanegoUzytkownika);
    string zamienDaneAdresataNaLinieZDanymiOddzielonymiPionowymiKreskami(Adresat adresat);
    void dopiszAdresataDoPliku(Adresat adresat);
    int pobierz_ostatnie_id_adresata();
    int pobierzZPlikuIdOstatniegoAdresata();

};

#endif // PLIK_Z_ADRESATAMI
