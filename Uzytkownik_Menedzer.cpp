#include "Uzytkownik_Menedzer.h"

void UzytkownikMenedzer::rejestracjaUzytkownika() {

    Uzytkownik uzytkownik = podajDaneNowegoUzytkownika();

    uzytkownicy.push_back(uzytkownik);
    plikZUzytkownikami.dopiszUzytkownikaDoPliku(uzytkownik);

    cout << "Konto zalozono pomyslnie" << endl;
    system("pause");

}

Uzytkownik UzytkownikMenedzer::podajDaneNowegoUzytkownika() {
    Uzytkownik uzytkownik;

    uzytkownik.ustaw_id(pobierzIdNowegoUzytkownika());

    string login;
    do {
        cout << endl << "Podaj login: ";
        cin >> login;
        uzytkownik.ustaw_login(login);

    } while (czyIstniejeLogin(uzytkownik.pobierz_login()) == true);

    string haslo;
    cout << "Podaj haslo: ";
    cin >> haslo;

    uzytkownik.ustaw_haslo(haslo);

    return uzytkownik;
}

int UzytkownikMenedzer::pobierzIdNowegoUzytkownika() {

    if (uzytkownicy.empty() == true)
        return 1;
    else
        return uzytkownicy.back().pobierz_Id() + 1;

}

bool UzytkownikMenedzer::czyIstniejeLogin(string login) {

    for (unsigned int i = 0; i < uzytkownicy.size(); i++) {

        if(uzytkownicy[i].pobierz_login() == login) {
            cout << endl << "Istnieje uzytkownik o takim loginie." << endl;
            return true;
        }

    }
    return false;
}

void UzytkownikMenedzer::wypisz_wszystkich_uzytkownikow(){

    for (unsigned int i = 0; i < uzytkownicy.size(); i++){

        cout << uzytkownicy[i].pobierz_Id() << endl;
        cout << uzytkownicy[i].pobierz_login() << endl;
        cout << uzytkownicy[i].pobierz_haslo() << endl;

    }
}

void UzytkownikMenedzer::wczytajUzytkownikowZPliku(){

  uzytkownicy = plikZUzytkownikami.wczytajUzytkownikowZPliku();

}

void UzytkownikMenedzer::zmianaHaslaZalogowanegoUzytkownika()
{

    string noweHaslo = "";
    cout << "Podaj nowe haslo: ";

    noweHaslo = Metody_pomocnicze::wczytajLinie();

    int idZalogowanegoUzytkownika = pobierzIdZalogowanegoUzytkownika();

    for (vector <Uzytkownik>::iterator itr = uzytkownicy.begin(); itr != uzytkownicy.end(); itr++)
    {
        if (itr -> pobierz_Id() == idZalogowanegoUzytkownika)
        {
     //       cout << "id zalogowanego: " << idZalogowanegoUzytkownika << endl; // sprawdzenie czy faktycznie tu jest moj uzytkownik.
            itr -> ustaw_haslo(noweHaslo);
            cout << "Haslo zostalo zmienione." << endl << endl;
            system("pause");
        }
      //  else{
       //     cout << "couldnt find user" << endl;
       // }
    }
    plikZUzytkownikami.zapiszWszystkichUzytkownikowDoPliku(uzytkownicy);
}


void UzytkownikMenedzer::logowanieUzytkownika()
{
    Uzytkownik uzytkownik;
    vector <Uzytkownik> uzytkownicy;

    string login = "", haslo = "";

    uzytkownicy = plikZUzytkownikami.wczytajUzytkownikowZPliku(); // musze wrzucic  wektor uzytkownikow, inaczej sie nie zaloguje.

    cout << endl << "Podaj login: ";
    login = Metody_pomocnicze::wczytajLinie();

    vector <Uzytkownik>::iterator itr = uzytkownicy.begin();
    while (itr != uzytkownicy.end())
    {
        if (itr -> pobierz_login() == login)
        {
            for (int iloscProb = 3; iloscProb > 0; iloscProb--)
            {
                cout << "Podaj haslo. Pozostalo prob: " << iloscProb << ": ";
                haslo = Metody_pomocnicze::wczytajLinie();

                if (itr -> pobierz_haslo() == haslo)
                {
                    cout << endl << "Zalogowales sie." << endl << endl;
                    system("pause");
                    idZalogowanegoUzytkownika = itr -> pobierz_Id(); // w tym miejscu musze przypierdolic idzalogowanego jelopa, inaczej nie bedzie moglo pobrac pozniej id'ka do zmiany hasla
                    return; // musze zwrocic returna, inaczej bym sie zapetlal tylko.
                }
            }
            cout << "Wprowadzono 3 razy bledne haslo. :)) " << endl;
            system("pause");
       //     return 0;  tutaj wypieprzyc return 0 - void w koncu
            exit (0);
        }
        itr++;
    }


    cout << "Nie ma uzytkownika z takim loginem" << endl << endl;
    system("pause");
    // return 0; to samo co wyzej.

}

int UzytkownikMenedzer::pobierzIdZalogowanegoUzytkownika(){

    return idZalogowanegoUzytkownika;

}

void UzytkownikMenedzer::wylogowanie_Uzytkownika(){

    idZalogowanegoUzytkownika = 0;
}
