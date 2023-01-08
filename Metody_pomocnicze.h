#include <iostream>
#include <sstream>
#include <algorithm>

#ifndef METODY_POMOCNICZE.H
#define METODY_POMOCNICZE.H

#include "Adresaci.h"

using namespace std;


class Metody_pomocnicze {

public:
    static string konwerjsaIntNaString(int liczba);
    static string wczytajLinie();
    string zamienPierwszaLitereNaDuzaAPozostaleNaMale(string tekst);
    int konwersjaStringNaInt(string liczba);
    string pobierzLiczbe(string tekst, int pozycjaZnaku);

};


#endif
