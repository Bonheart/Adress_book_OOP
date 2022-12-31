#include "Plik_z_uzytkownikami.h"

Plik_z_uzytkownikami::Plik_z_uzytkownikami(){

    nazwaPlikuZUzytkownikami = "Uzytkownicy.txt";

}

bool Plik_z_uzytkownikami::czyPlikJestPusty(fstream &plikTekstowy)
{
    plikTekstowy.seekg(0, ios::end);
    if (plikTekstowy.tellg() == 0)
        return true;
    else
        return false;
}

void Plik_z_uzytkownikami::dopiszUzytkownikaDoPliku(Uzytkownik uzytkownik)
{
    fstream plikTekstowy;
    string liniaZDanymiUzytkownika = "";
    plikTekstowy.open(nazwaPlikuZUzytkownikami.c_str(), ios::app);

    if (plikTekstowy.good() == true)
    {
        liniaZDanymiUzytkownika = zamienDaneUzytkownikaNaLinieZDanymiOddzielonaPionowymiKreskami(uzytkownik);

        if (czyPlikJestPusty(plikTekstowy) == true)
        {
            plikTekstowy << liniaZDanymiUzytkownika;
        }
        else
        {
            plikTekstowy << endl << liniaZDanymiUzytkownika ;
        }
    }
    else
        cout << "Nie udalo sie otworzyc pliku " << nazwaPlikuZUzytkownikami << " i zapisac w nim danych." << endl;
    plikTekstowy.close();
}


string Plik_z_uzytkownikami::zamienDaneUzytkownikaNaLinieZDanymiOddzielonaPionowymiKreskami(Uzytkownik uzytkownik)
{
    string liniaZDanymiUzytkownika = "";

    liniaZDanymiUzytkownika += Metody_pomocnicze::konwerjsaIntNaString(uzytkownik.pobierz_Id())+ '|';
    liniaZDanymiUzytkownika += uzytkownik.pobierz_login() + '|';
    liniaZDanymiUzytkownika += uzytkownik.pobierz_haslo() + '|';

    return liniaZDanymiUzytkownika;
}
