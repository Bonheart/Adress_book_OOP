#include "Plik_z_uzytkownikami.h"
#include <fstream>

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


vector <Uzytkownik> Plik_z_uzytkownikami::wczytajUzytkownikowZPliku()
{
    Uzytkownik uzytkownik;
    vector <Uzytkownik> uzytkownicy;
    string daneJednegoUzytkownikaOddzielonePionowymiKreskami = "";

    fstream plikTekstowy;
    plikTekstowy.open(nazwaPlikuZUzytkownikami.c_str(), ios::in);

    if (plikTekstowy.good() == true)
    {
        while (getline(plikTekstowy, daneJednegoUzytkownikaOddzielonePionowymiKreskami))
        {
            uzytkownik = pobierzDaneUzytkownika(daneJednegoUzytkownikaOddzielonePionowymiKreskami);
            uzytkownicy.push_back(uzytkownik);
        }
    }
    plikTekstowy.close();
    return uzytkownicy;
}


Uzytkownik Plik_z_uzytkownikami::pobierzDaneUzytkownika(string daneJednegoUzytkownikaOddzielonePionowymiKreskami)
{
    Uzytkownik uzytkownik;
    string pojedynczaDanaUzytkownika = "";
    int numerPojedynczejDanejUzytkownika = 1;

    for (unsigned int pozycjaZnaku = 0; pozycjaZnaku < daneJednegoUzytkownikaOddzielonePionowymiKreskami.length(); pozycjaZnaku++)
    {
        if (daneJednegoUzytkownikaOddzielonePionowymiKreskami[pozycjaZnaku] != '|')
        {
            pojedynczaDanaUzytkownika += daneJednegoUzytkownikaOddzielonePionowymiKreskami[pozycjaZnaku];
        }
        else
        {
            switch(numerPojedynczejDanejUzytkownika)
            {
            case 1:
                uzytkownik.ustaw_id(atoi(pojedynczaDanaUzytkownika.c_str()));
                break;
            case 2:
                uzytkownik.ustaw_login(pojedynczaDanaUzytkownika);
                break;
            case 3:
                uzytkownik.ustaw_haslo(pojedynczaDanaUzytkownika);
                break;
            }
            pojedynczaDanaUzytkownika = "";
            numerPojedynczejDanejUzytkownika++;
        }
    }
    return uzytkownik;
}

void Plik_z_uzytkownikami::zapiszWszystkichUzytkownikowDoPliku(vector <Uzytkownik> uzytkownicy)
{
    fstream plikTekstowy;
    string liniaZDanymiUzytkownika = "";
    vector <Uzytkownik>::iterator itrKoniec = --uzytkownicy.end();

    plikTekstowy.open(nazwaPlikuZUzytkownikami.c_str(), ios::out);

    if (plikTekstowy.good() == true)
    {
        for (vector <Uzytkownik>::iterator itr = uzytkownicy.begin(); itr != uzytkownicy.end(); itr++)
        {
            liniaZDanymiUzytkownika = zamienDaneUzytkownikaNaLinieZDanymiOddzielonaPionowymiKreskami(*itr);

            if (itr == itrKoniec)
            {
               plikTekstowy << liniaZDanymiUzytkownika;
            }
            else
            {
                plikTekstowy << liniaZDanymiUzytkownika << endl;
            }
            liniaZDanymiUzytkownika = "";
        }
    }
    else
    {
        cout << "Nie mozna otworzyc pliku " << nazwaPlikuZUzytkownikami << endl;
    }
    plikTekstowy.close();
}
