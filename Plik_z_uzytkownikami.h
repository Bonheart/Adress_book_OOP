#include <iostream>
#include <vector>
#include <fstream>
#include "Uzytkownik.h"
#include "Metody_pomocnicze.h"

using namespace std;

class Plik_z_uzytkownikami {


private:
    string nazwaPlikuZUzytkownikami;
    string zamienDaneUzytkownikaNaLinieZDanymiOddzielonaPionowymiKreskami(Uzytkownik uzytkownik);


public:
    Plik_z_uzytkownikami();
    bool czyPlikJestPusty(fstream &plikTekstowy);
    void dopiszUzytkownikaDoPliku(Uzytkownik uzytkownicy);



};
