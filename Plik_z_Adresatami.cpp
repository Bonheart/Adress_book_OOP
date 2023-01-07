#include "Plik_z_Adresatami.h"
#include "Metody_pomocnicze.h"
#include "Adresaci.h"


Adresat Plik_z_adresatami::pobierzDaneAdresata(string daneAdresataOddzielonePionowymiKreskami)
{
    Adresat adresat;
    Metody_pomocnicze metoda_pomocnicza;
    string pojedynczaDanaAdresata = "";
    int numerPojedynczejDanejAdresata = 1;

    for (int pozycjaZnaku = 0; pozycjaZnaku < daneAdresataOddzielonePionowymiKreskami.length(); pozycjaZnaku++)
    {
        if (daneAdresataOddzielonePionowymiKreskami[pozycjaZnaku] != '|')
        {
            pojedynczaDanaAdresata += daneAdresataOddzielonePionowymiKreskami[pozycjaZnaku];
        }
        else
        {
            switch(numerPojedynczejDanejAdresata)
            {
            case 1:
                adresat.ustaw_id(atoi(pojedynczaDanaAdresata.c_str()));
                break;
            case 2:
                adresat.ustaw_id_zalogowanego_uzytkownika(atoi(pojedynczaDanaAdresata.c_str()));
                break;
            case 3:
                adresat.ustaw_imie(pojedynczaDanaAdresata) ;
                break;
            case 4:
                adresat.ustaw_nazwisko(pojedynczaDanaAdresata);
                break;
            case 5:
                adresat.ustaw_nr_telefonu(pojedynczaDanaAdresata) ;
                break;
            case 6:
                adresat.ustaw_email(pojedynczaDanaAdresata) ;
                break;
            case 7:
                adresat.ustaw_adres(pojedynczaDanaAdresata) ;
                break;
            }
            pojedynczaDanaAdresata = "";
            numerPojedynczejDanejAdresata++;
        }
    }
    return adresat;
}


int Plik_z_adresatami::pobierzIdAdresataZDanychOddzielonychPionowymiKreskami(string daneJednegoAdresataOddzielonePionowymiKreskami)
{
    Metody_pomocnicze metodka_pomocnicza;
    int pozycjaRozpoczeciaIdAdresata = 0;
    int idAdresata = metodka_pomocnicza.konwersjaStringNaInt(metodka_pomocnicza.pobierzLiczbe(daneJednegoAdresataOddzielonePionowymiKreskami, pozycjaRozpoczeciaIdAdresata));
    return idAdresata;
}


vector <Adresat> Plik_z_adresatami::wczytajAdresatowZalogowanegoUzytkownikaZPliku(int idZalogowanegoUzytkownika)
{
    Adresat adresat;
    vector <Adresat> adresaci;
    int idOstatniegoAdresata = 0;
    string daneJednegoAdresataOddzielonePionowymiKreskami = "";
    string daneOstaniegoAdresataWPliku = "";
    fstream plikTekstowy;
    plikTekstowy.open(nazwaPlikuZAdresatami.c_str(), ios::in);

    if (plikTekstowy.good() == true)
    {
        while (getline(plikTekstowy, daneJednegoAdresataOddzielonePionowymiKreskami))
        {
            if(idZalogowanegoUzytkownika == pobierzIdUzytkownikaZDanychOddzielonychPionowymiKreskami(daneJednegoAdresataOddzielonePionowymiKreskami))
            {
                adresat = pobierzDaneAdresata(daneJednegoAdresataOddzielonePionowymiKreskami);
                adresaci.push_back(adresat);
            }
        }
        daneOstaniegoAdresataWPliku = daneJednegoAdresataOddzielonePionowymiKreskami;
    }
    else
        cout << "Nie udalo sie otworzyc pliku i wczytac danych." << endl;

    plikTekstowy.close();

    if (daneOstaniegoAdresataWPliku != "")
    {
        idOstatniegoAdresata = pobierzIdAdresataZDanychOddzielonychPionowymiKreskami(daneOstaniegoAdresataWPliku);

    }
    else
        return adresaci;
}

int Plik_z_adresatami::pobierzIdUzytkownikaZDanychOddzielonychPionowymiKreskami(string daneJednegoAdresataOddzielonePionowymiKreskami)
{
     Metody_pomocnicze metodka_pomocnicza;
    int pozycjaRozpoczeciaIdUzytkownika = daneJednegoAdresataOddzielonePionowymiKreskami.find_first_of('|') + 1;
    int idUzytkownika = metodka_pomocnicza.konwersjaStringNaInt(metodka_pomocnicza.pobierzLiczbe(daneJednegoAdresataOddzielonePionowymiKreskami, pozycjaRozpoczeciaIdUzytkownika));

    return idUzytkownika;
}

string Plik_z_adresatami::zamienDaneAdresataNaLinieZDanymiOddzielonymiPionowymiKreskami(Adresat adresat)
{
    string liniaZDanymiAdresata = "";
    Metody_pomocnicze metodka_pomocnicza;

    liniaZDanymiAdresata += metodka_pomocnicza.konwerjsaIntNaString(adresat.pobierz_id()) + '|';
    liniaZDanymiAdresata += metodka_pomocnicza.konwerjsaIntNaString(adresat.pobierz_id_zalogowanego_uzytkownika()) + '|';
    liniaZDanymiAdresata += adresat.pobierz_imie()+ '|';
    liniaZDanymiAdresata += adresat.pobierz_nazwisko() + '|';
    liniaZDanymiAdresata += adresat.pobierz_nr_telefonu() + '|';
    liniaZDanymiAdresata += adresat.pobierz_email() + '|';
    liniaZDanymiAdresata += adresat.pobierz_adres() + '|';

    return liniaZDanymiAdresata;
}

void Plik_z_adresatami::dopiszAdresataDoPliku(Adresat adresat)
{
    string liniaZDanymiAdresata = "";
    fstream plikTekstowy;
    plikTekstowy.open(nazwaPlikuZAdresatami.c_str(), ios::out | ios::app);

    if (plikTekstowy.good() == true)
    {
        liniaZDanymiAdresata = zamienDaneAdresataNaLinieZDanymiOddzielonymiPionowymiKreskami(adresat);

        if (czyPlikJestPusty(plikTekstowy) == true)
        {
            plikTekstowy << liniaZDanymiAdresata;
        }
        else
        {
            plikTekstowy << endl << liniaZDanymiAdresata ;
        }
    }
    else
    {
        cout << "Nie udalo sie otworzyc pliku i zapisac w nim danych." << endl;
    }

    idOstatniegoAdresata++;

    plikTekstowy.close();
    system("pause");
}


int Plik_z_adresatami::pobierz_ostatnie_id_adresata()
{
    return idOstatniegoAdresata;
}

bool Plik_z_adresatami::czyPlikJestPusty(fstream &plikTekstowy)
{
    plikTekstowy.seekg(0, ios::end);
    if (plikTekstowy.tellg() == 0)
        return true;
    else
        return false;
}

