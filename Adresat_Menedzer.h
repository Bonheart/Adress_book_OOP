#ifndef ADRESAT_MENEDZER.H
#define ADRESAT_MENEDZER.H

#include <iostream>
#include <vector>
#include "Adresaci.h"

class AdresatMenedzer {

private:
    vector <Adresat> adresaci;
    Adresat podajDaneNowegoAdresata();
    void wyswietlDaneAdresata(Adresat adresat);


public:

    void dodajAdresata();
    int idOstatniegoAdresata();
    int idZalogowanegoUzytkownika;
    void wyswietlWszystkichAdresatow();

};

#endif // ADRESAT_MENEDZER
