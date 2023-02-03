#ifndef PLIKZADRESATAMI_H
#define PLIKZADRESATAMI_H

#include <iostream>
#include <vector>
#include <fstream>


#include "Adresaci.h"
#include "Metody_pomocnicze.h"
#include "Pochodna_pliku.h"



using namespace std;



class Plik_z_adresatami: public Pochodna
{

   // const string NAZWA_PLIKU_Z_ADRESATAMI;
    string NAZWA_PLIKU_Z_ADRESATAMI_TYMCZASOWY;
    fstream plikTekstowy;
    bool czyPlikJestPusty(fstream &plikTekstowy);
    Adresat pobierzDaneAdresata(string daneAdresataOddzielonePionowymiKreskami);
    int pobierzIdAdresataZDanychOddzielonychPionowymiKreskami(string daneJednegoAdresataOddzielonePionowymiKreskami);
    int pobierzIdUzytkownikaZDanychOddzielonychPionowymiKreskami(string daneJednegoAdresataOddzielonePionowymiKreskami);
    int idOstatniegoAdresata;
    void zmienNazwePliku(string stara_nazwa, string nowa_nazwa);


public:

    Plik_z_adresatami(string nazwa_pliku) : Pochodna(nazwa_pliku){ // zamiast sta³ej NAZWA_PLIKU_Z_ADRESATAMI wrzucam moja pochodna do konstruktora, a do jego cia³a, to co chce mieæ.

        NAZWA_PLIKU_Z_ADRESATAMI_TYMCZASOWY = "Adresat2.txt";

        idOstatniegoAdresata = 0;

    };

    vector <Adresat> wczytajAdresatowZalogowanegoUzytkownikaZPliku(int idZalogowanegoUzytkownika);
    string zamienDaneAdresataNaLinieZDanymiOddzielonymiPionowymiKreskami(Adresat adresat);
    bool dopiszAdresataDoPliku(Adresat adresat);
    int pobierz_ostatnie_id_adresata();
    int usun_adresata_z_pliku(int id_usuwanego_adresata);
    void zaktualizujDaneWybranegoAdresataWPliku(Adresat adresat);

};

#endif // PLIK_Z_ADRESATAMI
