#include "Plik_z_Adresatami.h"



Adresat Plik_z_adresatami::pobierzDaneAdresata(string daneAdresataOddzielonePionowymiKreskami) {
    Adresat adresat;

    string pojedynczaDanaAdresata = "";
    int numerPojedynczejDanejAdresata = 1;

    for (unsigned int pozycjaZnaku = 0; pozycjaZnaku < daneAdresataOddzielonePionowymiKreskami.length(); pozycjaZnaku++) {
        if (daneAdresataOddzielonePionowymiKreskami[pozycjaZnaku] != '|') {
            pojedynczaDanaAdresata += daneAdresataOddzielonePionowymiKreskami[pozycjaZnaku];
        } else {
            switch(numerPojedynczejDanejAdresata) {
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


int Plik_z_adresatami::pobierzIdAdresataZDanychOddzielonychPionowymiKreskami(string daneJednegoAdresataOddzielonePionowymiKreskami) {

    int pozycjaRozpoczeciaIdAdresata = 0;
    int idAdresata =  Metody_pomocnicze::konwersjaStringNaInt( Metody_pomocnicze::pobierzLiczbe(daneJednegoAdresataOddzielonePionowymiKreskami, pozycjaRozpoczeciaIdAdresata));
    return idAdresata;
}


vector <Adresat> Plik_z_adresatami::wczytajAdresatowZalogowanegoUzytkownikaZPliku(int idZalogowanegoUzytkownika) {
    Adresat adresat;
    vector <Adresat> adresaci;
    string daneJednegoAdresataOddzielonePionowymiKreskami = "";
    string daneOstaniegoAdresataWPliku = "";
    fstream plikTekstowy;
    plikTekstowy.open(NAZWA_PLIKU_Z_ADRESATAMI.c_str(), ios::in);

    if (plikTekstowy.good() == true) {
        while (getline(plikTekstowy, daneJednegoAdresataOddzielonePionowymiKreskami)) {
            if(idZalogowanegoUzytkownika == pobierzIdUzytkownikaZDanychOddzielonychPionowymiKreskami(daneJednegoAdresataOddzielonePionowymiKreskami)) {

                adresat = pobierzDaneAdresata(daneJednegoAdresataOddzielonePionowymiKreskami);
                adresaci.push_back(adresat);
            }
        }
        daneOstaniegoAdresataWPliku = daneJednegoAdresataOddzielonePionowymiKreskami;
    } else
        cout << "Nie udalo sie otworzyc pliku i wczytac danych." << endl;

    plikTekstowy.close();

    if (daneOstaniegoAdresataWPliku != "") {

        idOstatniegoAdresata = pobierzIdAdresataZDanychOddzielonychPionowymiKreskami(daneOstaniegoAdresataWPliku);

    }
    return adresaci;

}

int Plik_z_adresatami::pobierzIdUzytkownikaZDanychOddzielonychPionowymiKreskami(string daneJednegoAdresataOddzielonePionowymiKreskami) {


    int pozycjaRozpoczeciaIdUzytkownika = daneJednegoAdresataOddzielonePionowymiKreskami.find_first_of('|') + 1;
    int idUzytkownika = Metody_pomocnicze::konwersjaStringNaInt( Metody_pomocnicze::pobierzLiczbe(daneJednegoAdresataOddzielonePionowymiKreskami, pozycjaRozpoczeciaIdUzytkownika));

    return idUzytkownika;
}

string Plik_z_adresatami::zamienDaneAdresataNaLinieZDanymiOddzielonymiPionowymiKreskami(Adresat adresat) {
    string liniaZDanymiAdresata = "";

    liniaZDanymiAdresata +=  Metody_pomocnicze::konwerjsaIntNaString(adresat.pobierz_id()) + '|';
    liniaZDanymiAdresata +=  Metody_pomocnicze::konwerjsaIntNaString(adresat.pobierz_id_zalogowanego_uzytkownika()) + '|';
    liniaZDanymiAdresata += adresat.pobierz_imie()+ '|';
    liniaZDanymiAdresata += adresat.pobierz_nazwisko() + '|';
    liniaZDanymiAdresata += adresat.pobierz_nr_telefonu() + '|';
    liniaZDanymiAdresata += adresat.pobierz_email() + '|';
    liniaZDanymiAdresata += adresat.pobierz_adres() + '|';

    return liniaZDanymiAdresata;
}

bool Plik_z_adresatami::dopiszAdresataDoPliku(Adresat adresat) {

    string liniaZDanymiAdresata = "";
    fstream plikTekstowy;
    plikTekstowy.open(NAZWA_PLIKU_Z_ADRESATAMI.c_str(), ios::out | ios::app);

    if (plikTekstowy.good() == true) {
        liniaZDanymiAdresata = zamienDaneAdresataNaLinieZDanymiOddzielonymiPionowymiKreskami(adresat);

        if (czyPlikJestPusty(plikTekstowy) == true) {
            plikTekstowy << liniaZDanymiAdresata;
        } else {
            plikTekstowy << endl << liniaZDanymiAdresata ;
        }

    idOstatniegoAdresata++;
    plikTekstowy.close();
    return true;
}
return false;
}

/*
int Plik_z_adresatami::pobierzZPlikuIdOstatniegoAdresata() { // to bylo na poczatku, przed tworzeniem MENU i opieraniu sie na wskaznikach.
    int idOstatniegoAdresata = 0;
    string daneJednegoAdresataOddzielonePionowymiKreskami = "";
    string daneOstaniegoAdresataWPliku = "";
    fstream plikTekstowy;
    plikTekstowy.open(nazwaPlikuZAdresatami.c_str(), ios::in);

    if (plikTekstowy.good() == true) {
        while (getline(plikTekstowy, daneJednegoAdresataOddzielonePionowymiKreskami)) {}
        daneOstaniegoAdresataWPliku = daneJednegoAdresataOddzielonePionowymiKreskami;
        plikTekstowy.close();
    } else
        cout << "Nie udalo sie otworzyc pliku i wczytac danych." << endl;

    if (daneOstaniegoAdresataWPliku != "") {
        idOstatniegoAdresata = pobierzIdAdresataZDanychOddzielonychPionowymiKreskami(daneOstaniegoAdresataWPliku);
    }
    return idOstatniegoAdresata;
}
*/

int Plik_z_adresatami::pobierz_ostatnie_id_adresata(){

    return idOstatniegoAdresata;
}

bool Plik_z_adresatami::czyPlikJestPusty(fstream &plikTekstowy) {
    plikTekstowy.seekg(0, ios::end);
    if (plikTekstowy.tellg() == 0)
        return true;
    else
        return false;
}

int Plik_z_adresatami::usun_adresata_z_pliku(int id_usuwanego_adresata){

    fstream plikTekstowy, plik_tymczasowy;

    int id_adresata_do_usuniecia = 0;

    string dane_adresata = "";

    plikTekstowy.open(NAZWA_PLIKU_Z_ADRESATAMI,ios::in);
    plik_tymczasowy.open(NAZWA_PLIKU_Z_ADRESATAMI_TYMCZASOWY, ios::out | ios::app);

    if(plikTekstowy.good()){

        while(getline(plikTekstowy,dane_adresata)){

            id_adresata_do_usuniecia = pobierzIdAdresataZDanychOddzielonychPionowymiKreskami(dane_adresata);

            if(id_adresata_do_usuniecia != id_usuwanego_adresata){

                plik_tymczasowy << dane_adresata << endl;

            }
        }
    }
    plikTekstowy.close();
    plik_tymczasowy.close();

    remove(NAZWA_PLIKU_Z_ADRESATAMI);
    rename(NAZWA_PLIKU_Z_ADRESATAMI_TYMCZASOWY,NAZWA_PLIKU_Z_ADRESATAMI);
    return id_usuwanego_adresata;

}
