#ifndef ADRESAT_MENEDZER.H
#define ADRESAT_MENEDZER.H

#include <iostream>
#include <vector>
#include "Adresat_Menedzer.h"
#include "Adresaci.h"



class AdresatMenedzer {

private:

    vector <Adresat> adresaci;

public:
    Adresat dodajAdresata();
    Adresat podajDaneNowegoAdresata();
    int idOstatniegoAdresata();

};




#endif // ADRESAT_MENEDZER
