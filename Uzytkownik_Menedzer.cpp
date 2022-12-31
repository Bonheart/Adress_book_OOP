#include "Uzytkownik_Menedzer.h"

void Uzytkownik_Menedzer::rejestracjaUzytkownika() {

    Uzytkownik uzytkownik = podajDaneNowegoUzytkownika();

    uzytkownicy.push_back(uzytkownik);
    Plik_z_uzytkownikami plikZUzytkownikami;
    plikZUzytkownikami.dopiszUzytkownikaDoPliku(uzytkownik);

    cout << "Konto zalozono pomyslnie" << endl;
    system("pause");

}

Uzytkownik Uzytkownik_Menedzer::podajDaneNowegoUzytkownika() {
    Uzytkownik uzytkownik;

    uzytkownik.ustaw_id(pobierzIdNowegoUzytkownika());

    string login;
    do {
        cout << endl << "Podaj login: ";
        cin >> login;
        uzytkownik.ustaw_login(login);

    } while (czyIstniejeLogin( uzytkownik.pobierz_login()) == true);

    string haslo;
    cout << "Podaj haslo: ";
    cin >> haslo;

    uzytkownik.ustaw_haslo(haslo);

    return uzytkownik;
}

int Uzytkownik_Menedzer::pobierzIdNowegoUzytkownika() {

    if (uzytkownicy.empty() == true)
        return 1;
    else
        return uzytkownicy.back().pobierz_Id() + 1;

}



bool Uzytkownik_Menedzer::czyIstniejeLogin( string login) {

    for (int i = 0; i < uzytkownicy.size(); i++) {

        if(uzytkownicy[i].pobierz_login() == login) {
            cout << endl << "Istnieje uzytkownik o takim loginie." << endl;
            return true;
        }

    }
    return false;
}

void Uzytkownik_Menedzer::wypisz_wszystkich_uzytkownikow(){

    for (int i = 0; i < uzytkownicy.size(); i++){

        cout << uzytkownicy[i].pobierz_Id() << endl;
        cout << uzytkownicy[i].pobierz_login() << endl;
        cout << uzytkownicy[i].pobierz_haslo() << endl;

    }
}

