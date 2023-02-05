#ifndef POCHODNAPLIKU_H
#define POCHODNAPLIKU_H

#include <iostream>
#include <fstream>

using namespace std;

class Pochodna {


    const string NOWY_PLIK_JAKO_POCHODNA; // tworze nowa stala ktora pozniej bedzie dziedziczona przez wszystkie classy


public:

    Pochodna(string nazwa_pliku):NOWY_PLIK_JAKO_POCHODNA(nazwa_pliku) {};
    string pobieranie_nazwy_pliku();
    bool czyPlikJestPusty();

};



#endif
