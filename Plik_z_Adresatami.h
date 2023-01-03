#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>


#include "Adresaci.h"
#include "Adresat_Menedzer.h"


using namespace std;

class Plik_z_adresatami{

    vector <Adresat> adresaci;
    string nazwaPlikuZAdresatami;
    fstream plikTekstowy;

    bool czyPlikJestPusty(fstream &plikTekstowy);

public:
    void dopiszAdresataDoPliku(Adresat adresat);
    int pobierzIdAdresataZDanychOddzielonychPionowymiKreskami(string daneJednegoAdresataOddzielonePionowymiKreskami);


};
