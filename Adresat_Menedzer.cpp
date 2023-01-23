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
