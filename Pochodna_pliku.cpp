#include "Pochodna_pliku.h"

string Pochodna::pobieranie_nazwy_pliku(){

    return NOWY_PLIK_JAKO_POCHODNA;

}


bool Pochodna::czyPlikJestPusty() {

    bool czy_plik_jest_pusty = true;
    fstream plikTekstowy;
    plikTekstowy.open(pobieranie_nazwy_pliku().c_str(), ios ::app);

    if(plikTekstowy.good() == true){
    plikTekstowy.seekg(0, ios::end);
    if (plikTekstowy.tellg() == 0)
        czy_plik_jest_pusty = false;
    }
    plikTekstowy.close();
    return czy_plik_jest_pusty;

}
