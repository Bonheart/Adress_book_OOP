#include <iostream>
#include <vector>
#include "Uzytkownik.h"
#include "Plik_z_uzytkownikami.h"
#include <fstream>

using namespace std;

class Uzytkownik_Menedzer{

private:

    Uzytkownik podajDaneNowegoUzytkownika();
    int idZalogowanegoUzytkownika;
    vector <Uzytkownik> uzytkownicy;
    int pobierzIdNowegoUzytkownika();
    bool czyIstniejeLogin( string login);
    Plik_z_uzytkownikami PlikZUzytkownikami;

public:

    void rejestracjaUzytkownika();

    void wypisz_wszystkich_uzytkownikow();


};
