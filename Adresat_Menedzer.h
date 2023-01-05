#ifndef ADRESAT_MENEDZER.H
#define ADRESAT_MENEDZER.H

#include <iostream>
#include <vector>
#include "Adresaci.h"
#include "Plik_z_Adresatami.h"


class AdresatMenedzer {

private:
    vector <Adresat> adresaci;
    Adresat podajDaneNowegoAdresata();

    void wyswietlDaneAdresata(Adresat adresat);

    Adresat pobierzDaneAdresata();
    Plik_z_adresatami pliczek_z_adresatami;


public:

  //  AdresatMenedzer(string nazwaPlikuZAdresatami) : pliczek_z_adresatami(nazwaPlikuZAdresatami){};
    void dodajAdresata();
    int idZalogowanegoUzytkownika;
    void wyswietlWszystkichAdresatow();

};

#endif // ADRESAT_MENEDZER
