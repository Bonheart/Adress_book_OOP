#include <iostream>
#ifndef METODY_POMOCNICZE.H
#define METODY_POMOCNICZE.H

#include "Adresaci.h"

using namespace std;


class Metody_pomocnicze {

public:
    static string konwerjsaIntNaString(int liczba);
    string wczytajLinie();
    string zamienPierwszaLitereNaDuzaAPozostaleNaMale(string tekst);
    int konwersjaStringNaInt(string liczba);
    Metody_pomocnicze metoda_pomocnicza();
    string pobierzLiczbe(string tekst, int pozycjaZnaku);

};


#endif
