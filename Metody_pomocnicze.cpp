#include "Metody_pomocnicze.h"
#include <sstream>
#include <algorithm>


string Metody_pomocnicze::konwerjsaIntNaString(int liczba)
{
    ostringstream ss;
    ss << liczba;
    string str = ss.str();
    return str;
}

string Metody_pomocnicze::wczytajLinie()
{
    string wejscie = "";
    getline(cin, wejscie);
    return wejscie;
}

string Metody_pomocnicze::zamienPierwszaLitereNaDuzaAPozostaleNaMale(string tekst)
{
    if (!tekst.empty())
    {
        transform(tekst.begin(), tekst.end(), tekst.begin(), ::tolower);
        tekst[0] = toupper(tekst[0]);
    }
    return tekst;
}

int Metody_pomocnicze::konwersjaStringNaInt(string liczba)
{
    int liczbaInt;
    istringstream iss(liczba);
    iss >> liczbaInt;

    return liczbaInt;
}

string Metody_pomocnicze::zamienDaneAdresataNaLinieZDanymiOddzielonymiPionowymiKreskami(Adresat adresat)
{
    string liniaZDanymiAdresata = "";

    liniaZDanymiAdresata += konwerjsaIntNaString(adresat.pobierz_id()) + '|';
    liniaZDanymiAdresata += konwerjsaIntNaString(adresat.pobierz_id_zalogowanego_uzytkownika()) + '|';
    liniaZDanymiAdresata += adresat.pobierz_imie() + '|';
    liniaZDanymiAdresata += adresat.pobierz_nazwisko() + '|';
    liniaZDanymiAdresata += adresat.pobierz_nr_telefonu() + '|';
    liniaZDanymiAdresata += adresat.pobierz_email() + '|';
    liniaZDanymiAdresata += adresat.pobierz_adres() + '|';

    return liniaZDanymiAdresata;
}

string Metody_pomocnicze::pobierzLiczbe(string tekst, int pozycjaZnaku)
{
    string liczba = "";
    while(isdigit(tekst[pozycjaZnaku]) == true)
    {
        liczba += tekst[pozycjaZnaku];
        pozycjaZnaku ++;
    }
    return liczba;
}
