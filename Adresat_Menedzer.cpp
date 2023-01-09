#include "Adresat_Menedzer.h"
#include "Metody_pomocnicze.h"
#include "Plik_z_Adresatami.h"
#include "Uzytkownik_Menedzer.h"

Adresat AdresatMenedzer::podajDaneNowegoAdresata()
{
    Adresat adresat;
//    Plik_z_adresatami pliczek_z_adresatami;

    Metody_pomocnicze metoda_pomocnicza;


    adresat.ustaw_id(pliczek_z_adresatami.pobierz_ostatnie_id_adresata()+1); // hmm??? nie pobieram nic z pliku poki co. moze wartaloby po prostu zadeklarowac nowe_id = 0?
 //   adresat.ustaw_id_zalogowanego_uzytkownika (idZalogowanegoUzytkownika);

    string nowe_imie = "";
    cout << "Podaj imie: ";
    nowe_imie = metoda_pomocnicza.wczytajLinie();
    nowe_imie = metoda_pomocnicza.zamienPierwszaLitereNaDuzaAPozostaleNaMale(nowe_imie);
    adresat.ustaw_imie(nowe_imie);

    string nowe_nazwisko= "";
    cout << "Podaj nazwisko: ";
    nowe_nazwisko = metoda_pomocnicza.wczytajLinie();
    nowe_nazwisko = metoda_pomocnicza.zamienPierwszaLitereNaDuzaAPozostaleNaMale(nowe_nazwisko);
    adresat.ustaw_nazwisko(nowe_nazwisko);

    string nowy_nr= "";
    cout << "Podaj numer telefonu: ";
    nowy_nr = metoda_pomocnicza.wczytajLinie();
    adresat.ustaw_nr_telefonu(nowy_nr);

    string nowy_email= "";
    cout << "Podaj email: ";
    nowy_email = metoda_pomocnicza.wczytajLinie();
    adresat.ustaw_email(nowy_email);

    string nowy_adres= "";
    cout << "Podaj adres: ";
    nowy_adres = metoda_pomocnicza.wczytajLinie();
    adresat.ustaw_adres(nowy_adres);

    return adresat;
}

void AdresatMenedzer::dodajAdresata()
{
    Adresat adresat;
  //  Plik_z_adresatami pliczek_z_adresatami;

    system("cls");
    cout << " >>> DODAWANIE NOWEGO ADRESATA <<<" << endl << endl;
    adresat = podajDaneNowegoAdresata();

    adresaci.push_back(adresat);
    pliczek_z_adresatami.dopiszAdresataDoPliku(adresat);

}

void AdresatMenedzer::wyswietlWszystkichAdresatow()
{

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

void AdresatMenedzer::wczytajAdresatowZalogowanegoUzytkownikaZPliku(){

    adresaci = pliczek_z_adresatami.wczytajAdresatowZalogowanegoUzytkownikaZPliku(AdresatMenedzer::idZalogowanegoUzytkownika);

}
