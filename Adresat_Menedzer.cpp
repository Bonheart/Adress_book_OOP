#include "Adresat_Menedzer.h"
#include "Metody_pomocnicze.h"
#include "Plik_z_Adresatami.h"
#include "Uzytkownik_Menedzer.h"
#include "Adresaci.h"

Adresat AdresatMenedzer::podajDaneNowegoAdresata()
{
    Adresat adresat;

    adresat.ustaw_id(pliczek_z_adresatami.pobierz_ostatnie_id_adresata() + 1);
    adresat.ustaw_id_zalogowanego_uzytkownika(ID_ZALOGOWANEGO_UZYTKOWNIKA);

    string nowe_imie = "";
    cout << "Podaj imie: ";
    nowe_imie = Metody_pomocnicze::wczytajLinie();
    nowe_imie = Metody_pomocnicze::zamienPierwszaLitereNaDuzaAPozostaleNaMale(nowe_imie);
    adresat.ustaw_imie(nowe_imie);

    string nowe_nazwisko= "";
    cout << "Podaj nazwisko: ";
    nowe_nazwisko = Metody_pomocnicze::wczytajLinie();
    nowe_nazwisko = Metody_pomocnicze::zamienPierwszaLitereNaDuzaAPozostaleNaMale(nowe_nazwisko);
    adresat.ustaw_nazwisko(nowe_nazwisko);

    string nowy_nr= "";
    cout << "Podaj numer telefonu: ";
    nowy_nr = Metody_pomocnicze::wczytajLinie();
    adresat.ustaw_nr_telefonu(nowy_nr);

    string nowy_email= "";
    cout << "Podaj email: ";
    nowy_email = Metody_pomocnicze::wczytajLinie();
    adresat.ustaw_email(nowy_email);

    string nowy_adres= "";
    cout << "Podaj adres: ";
    nowy_adres = Metody_pomocnicze::wczytajLinie();
    adresat.ustaw_adres(nowy_adres);

    return adresat;
}

void AdresatMenedzer::dodajAdresata()
{
    Adresat adresat;

    system("cls");
    cout << " >>> DODAWANIE NOWEGO ADRESATA <<<" << endl << endl;
    adresat = podajDaneNowegoAdresata();

    adresaci.push_back(adresat);

    if (pliczek_z_adresatami.dopiszAdresataDoPliku(adresat))
        cout <<"dodano adresata" << endl;
    else
        cout << "nie dodano adresata" << endl;
    system ("pause");

}

void AdresatMenedzer::wyswietlWszystkichAdresatow()
{
    adresaci = pliczek_z_adresatami.wczytajAdresatowZalogowanegoUzytkownikaZPliku(ID_ZALOGOWANEGO_UZYTKOWNIKA);

    system("cls");
    if (!adresaci.empty())
    {
        cout << "             >>> ADRESACI <<<" << endl;
        cout << "-----------------------------------------------" << endl;
        for (vector <Adresat> :: iterator itr = adresaci.begin(); itr != adresaci.end(); itr++)
        {
            wyswietlDaneAdresata(*itr);
        }
        cout << endl;
    }
    else
    {
        cout << endl << "Ksiazka adresowa jest pusta." << endl << endl;
    }
    system("pause");
}

void AdresatMenedzer::wyswietlDaneAdresata(Adresat adresat)
{

    cout << endl << "Id:                 " << adresat.pobierz_id() << endl;
    cout << "Imie:               " << adresat.pobierz_imie() << endl;
    cout << "Nazwisko:           " << adresat.pobierz_nazwisko() << endl;
    cout << "Numer telefonu:     " << adresat.pobierz_nr_telefonu() << endl;
    cout << "Email:              " << adresat.pobierz_email() << endl;
    cout << "Adres:              " << adresat.pobierz_adres() << endl;
}


void AdresatMenedzer::wyszukajAdresatowPoImieniu()
{
    string imiePoszukiwanegoAdresata = "";
    int iloscAdresatow = 0;

    system("cls");
    if (!adresaci.empty())
    {
        cout << ">>> WYSZUKIWANIE ADRESATOW O IMIENIU <<<" << endl << endl;

        cout << "Wyszukaj adresatow o imieniu: ";
        imiePoszukiwanegoAdresata = Metody_pomocnicze::wczytajLinie();
        imiePoszukiwanegoAdresata = Metody_pomocnicze::zamienPierwszaLitereNaDuzaAPozostaleNaMale(imiePoszukiwanegoAdresata);

        for (vector <Adresat>::iterator  itr = adresaci.begin(); itr != adresaci.end(); itr++)
        {
            if (itr -> Adresat::pobierz_imie() == imiePoszukiwanegoAdresata)
            {
                wyswietlDaneAdresata(*itr);
                iloscAdresatow++;
            }
        }
        wyswietlIloscWyszukanychAdresatow(iloscAdresatow);
    }
    else
    {
        cout << endl << "Ksiazka adresowa jest pusta" << endl << endl;
    }
    cout << endl;
    system("pause");
}

void AdresatMenedzer::wyswietlIloscWyszukanychAdresatow(int iloscAdresatow)
{
    if (iloscAdresatow == 0)
        cout << endl << "W ksiazce adresowej nie ma adresatow z tymi danymi." << endl;
    else
        cout << endl << "Ilosc adresatow w ksiazce adresowej wynosi: " << iloscAdresatow << endl << endl;
}

void AdresatMenedzer::wyszukajAdresatowPoNazwisku()
{
    string nazwiskoPoszukiwanegoAdresata;
    int iloscAdresatow = 0;

    system("cls");
    if (!adresaci.empty())
    {
        cout << ">>> WYSZUKIWANIE ADRESATOW O NAZWISKU <<<" << endl << endl;

        cout << "Wyszukaj adresatow o nazwisku: ";
        nazwiskoPoszukiwanegoAdresata = Metody_pomocnicze::wczytajLinie();
        nazwiskoPoszukiwanegoAdresata = Metody_pomocnicze::zamienPierwszaLitereNaDuzaAPozostaleNaMale(nazwiskoPoszukiwanegoAdresata);

        for (vector <Adresat>::iterator itr = adresaci.begin(); itr != adresaci.end(); itr++)
        {
            if (itr -> Adresat::pobierz_nazwisko() == nazwiskoPoszukiwanegoAdresata)
            {
                wyswietlDaneAdresata(*itr);
                iloscAdresatow++;
            }
        }
         wyswietlIloscWyszukanychAdresatow(iloscAdresatow);
    }
    else
    {
        cout << endl << "Ksiazka adresowa jest pusta." << endl << endl;
    }
    cout << endl;
    system("pause");
}

int AdresatMenedzer::usunAdresata()
{
    int idUsuwanegoAdresata = 0;
   // int numerLiniiUsuwanegoAdresata = 0; niepotrzebna zmienna

    system("cls");
    cout << ">>> USUWANIE WYBRANEGO ADRESATA <<<" << endl << endl;
    idUsuwanegoAdresata = podajIdWybranegoAdresata();

    char znak;
    bool czyIstniejeAdresat = false;

    for (vector <Adresat>::iterator itr = adresaci.begin(); itr != adresaci.end(); itr++)
    {
        if (itr -> Adresat::pobierz_id() == idUsuwanegoAdresata)
        {
            czyIstniejeAdresat = true;
            cout << endl << "Potwierdz naciskajac klawisz 't': ";
            znak = Metody_pomocnicze::wczytajZnak();
            if (znak == 't')
            {
        //        numerLiniiUsuwanegoAdresata = zwrocNumerLiniiSzukanegoAdresata(idUsuwanegoAdresata);
        //        usunWybranaLinieWPliku(numerLiniiUsuwanegoAdresata);
                pliczek_z_adresatami.usun_adresata_z_pliku(idUsuwanegoAdresata);
                adresaci.erase(itr);
                cout << endl << endl << "Szukany adresat zostal USUNIETY" << endl << endl;
                system("pause");
                return idUsuwanegoAdresata;
            }
            else
            {
                cout << endl << endl << "Wybrany adresat NIE zostal usuniety" << endl << endl;
                system("pause");
                return 0;
            }
        }
    }
    if (czyIstniejeAdresat == false)
    {
        cout << endl << "Nie ma takiego adresata w ksiazce adresowej" << endl << endl;
        system("pause");
    }
    return 0;
}

void AdresatMenedzer::edytujAdresata()
{
    system("cls");
    Adresat adresat;
    int idEdytowanegoAdresata = 0;
 //   int numerLiniiEdytowanegoAdresata = 0;
    string liniaZDanymiAdresata = "";

    cout << ">>> EDYCJA WYBRANEGO ADRESATA <<<" << endl << endl;
    idEdytowanegoAdresata = podajIdWybranegoAdresata();

    char wybor;
    bool czyIstniejeAdresat = false;

    for (unsigned int i = 0; i < adresaci.size(); i++)
    {
        if (adresaci[i].pobierz_id() == idEdytowanegoAdresata)
        {
            czyIstniejeAdresat = true;
            wybor = Metody_pomocnicze::wybierzOpcjeZMenuEdycja();

            switch (wybor)
            {
            case '1':{

                string nowe_imie = "";
                cout << "Podaj nowe imie: ";
                nowe_imie = Metody_pomocnicze::wczytajLinie();
                nowe_imie = Metody_pomocnicze::zamienPierwszaLitereNaDuzaAPozostaleNaMale(nowe_imie);
                adresaci[i].ustaw_imie(nowe_imie);
                zaktualizujDaneWybranegoAdresata(adresaci[i]);

                break;
            }
            case '2':{

                string nowe_nazwisko = "";
                cout << "Podaj nowe nazwisko: ";
                nowe_nazwisko = Metody_pomocnicze::wczytajLinie();
                nowe_nazwisko = Metody_pomocnicze::zamienPierwszaLitereNaDuzaAPozostaleNaMale(nowe_nazwisko);
                adresaci[i].ustaw_nazwisko(nowe_nazwisko);
                zaktualizujDaneWybranegoAdresata(adresaci[i]);

                break;
            }
            case '3':{

                string numer_telefonu = "";
                cout << "Podaj nowy numer telefonu: ";
                numer_telefonu = Metody_pomocnicze::wczytajLinie();
                numer_telefonu = Metody_pomocnicze::zamienPierwszaLitereNaDuzaAPozostaleNaMale(numer_telefonu);
                adresaci[i].ustaw_nr_telefonu(numer_telefonu);
                zaktualizujDaneWybranegoAdresata(adresaci[i]);

                break;
            }
            case '4':{

                string nowy_email = "";
                cout << "Podaj nowy email: ";
                nowy_email = Metody_pomocnicze::wczytajLinie();
                nowy_email = Metody_pomocnicze::zamienPierwszaLitereNaDuzaAPozostaleNaMale(nowy_email);
                adresaci[i].ustaw_email(nowy_email);
                zaktualizujDaneWybranegoAdresata(adresaci[i]);

                break;
            }
            case '5':{

                string nowy_adres = "";
                cout << "Podaj nowy adres zamieszkania: ";
                nowy_adres = Metody_pomocnicze::wczytajLinie();
                nowy_adres = Metody_pomocnicze::zamienPierwszaLitereNaDuzaAPozostaleNaMale(nowy_adres);
                adresaci[i].ustaw_adres(nowy_adres);
                zaktualizujDaneWybranegoAdresata(adresaci[i]);

                break;
            }
            case '6':
                cout << endl << "Powrot do menu uzytkownika" << endl << endl;
                break;
            default:
                cout << endl << "Nie ma takiej opcji w menu! Powrot do menu uzytkownika." << endl << endl;
                break;
            }
        }
    }
    if (czyIstniejeAdresat == false)
    {
        cout << endl << "Nie ma takiego adresata." << endl << endl;
    }
    system("pause");
}


int AdresatMenedzer::podajIdWybranegoAdresata()
{
    int idWybranegoAdresata = 0;
    cout << "Podaj numer ID Adresata: ";
    idWybranegoAdresata  = Metody_pomocnicze::wczytajLiczbeCalkowita();
    return idWybranegoAdresata;
}

void AdresatMenedzer::zaktualizujDaneWybranegoAdresata(Adresat adresat)
{
    int numerLiniiEdytowanegoAdresata = 0;
    string liniaZDanymiAdresata = "";

    /*
    numerLiniiEdytowanegoAdresata = zwrocNumerLiniiSzukanegoAdresata(idEdytowanegoAdresata);
    liniaZDanymiAdresata = zamienDaneAdresataNaLinieZDanymiOddzielonymiPionowymiKreskami(adresat);
    edytujWybranaLinieWPliku(numerLiniiEdytowanegoAdresata, liniaZDanymiAdresata);
    */


    cout << endl << "Dane zostaly zaktualizowane." << endl << endl;
}
