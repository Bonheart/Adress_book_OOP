#include <iostream>
#include <sstream>
#include <algorithm>

#ifndef METODYPOMOCNICZE_H
#define METODYPOMOCNICZE_H

#include "Adresaci.h"

using namespace std;


class Metody_pomocnicze {

public:
    static string konwerjsaIntNaString(int liczba);
    static string wczytajLinie();
    static string zamienPierwszaLitereNaDuzaAPozostaleNaMale(string tekst);
    static int konwersjaStringNaInt(string liczba);
    static string pobierzLiczbe(string tekst, int pozycjaZnaku);
    static char wybierzOpcjeZMenuUzytkownika();
    static char wczytajZnak();
    static char wybierzOpcjeZMenuGlownego();


};


#endif
