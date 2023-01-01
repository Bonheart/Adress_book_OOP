#include "Uzytkownik_Menedzer.h"
#include "Plik_z_uzytkownikami.h"

void UzytkownikMenedzer::rejestracjaUzytkownika() {

    Uzytkownik uzytkownik = podajDaneNowegoUzytkownika();

    uzytkownicy.push_back(uzytkownik);
    Plik_z_uzytkownikami plikZUzytkownikami;
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

    } while (czyIstniejeLogin( uzytkownik.pobierz_login()) == true);

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

    for (int i = 0; i < uzytkownicy.size(); i++) {

        if(uzytkownicy[i].pobierz_login() == login) {
            cout << endl << "Istnieje uzytkownik o takim loginie." << endl;
            return true;
        }

    }
    return false;
}

void UzytkownikMenedzer::wypisz_wszystkich_uzytkownikow(){

    for (int i = 0; i < uzytkownicy.size(); i++){

        cout << uzytkownicy[i].pobierz_Id() << endl;
        cout << uzytkownicy[i].pobierz_login() << endl;
        cout << uzytkownicy[i].pobierz_haslo() << endl;

    }
}

void UzytkownikMenedzer::wczytajUzytkownikowZPliku(){


  uzytkownicy = PlikZUzytkownikami.wczytajUzytkownikowZPliku(); // obiekt PlikZUzytkownikami

}
