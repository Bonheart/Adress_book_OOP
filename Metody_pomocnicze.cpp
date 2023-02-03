#include "Metody_pomocnicze.h"
#include <sstream>
#include <algorithm>


string Metody_pomocnicze::konwerjsaIntNaString(int liczba) {

    ostringstream ss;
    ss << liczba;
    string str = ss.str();
    return str;
}

string Metody_pomocnicze::wczytajLinie() {

    string wejscie = "";
    cin.sync();
    getline(cin, wejscie);
    return wejscie;
}

string Metody_pomocnicze::zamienPierwszaLitereNaDuzaAPozostaleNaMale(string tekst) {

    if (!tekst.empty()) {

        transform(tekst.begin(), tekst.end(), tekst.begin(), ::tolower);
        tekst[0] = toupper(tekst[0]);
    }
    return tekst;
}

int Metody_pomocnicze::konwersjaStringNaInt(string liczba) {

    int liczbaInt;
    istringstream iss(liczba);
    iss >> liczbaInt;

    return liczbaInt;
}


string Metody_pomocnicze::pobierzLiczbe(string tekst, int pozycjaZnaku) {

    string liczba = "";

    while(isdigit(tekst[pozycjaZnaku]) == true) {

        liczba += tekst[pozycjaZnaku];
        pozycjaZnaku ++;
    }
    return liczba;
}

char Metody_pomocnicze::wczytajZnak() {

    string wejscie = "";
    char znak  = {0};

    while (true) {
        getline(cin, wejscie);

        if (wejscie.length() == 1) {
            znak = wejscie[0];
            break;
        }
        cout << "To nie jest pojedynczy znak. Wpisz ponownie." << endl;
    }
    return znak;
}

char Metody_pomocnicze::wybierzOpcjeZMenuUzytkownika() {

    char wybor;

    system("cls");
    cout << " >>> MENU UZYTKOWNIKA <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Dodaj adresata" << endl;
    cout << "2. Wyszukaj po imieniu" << endl;
    cout << "3. Wyszukaj po nazwisku" << endl;
    cout << "4. Wyswietl adresatow" << endl;
    cout << "5. Usun adresata" << endl;
    cout << "6. Edytuj adresata" << endl;
    cout << "---------------------------" << endl;
    cout << "7. Zmien haslo" << endl;
    cout << "8. Wyloguj sie" << endl;
    cout << "---------------------------" << endl;
    cout << "Twoj wybor: ";
    wybor = Metody_pomocnicze::wczytajZnak();

    return wybor;
}

char Metody_pomocnicze::wybierzOpcjeZMenuGlownego() {

    char wybor;

    system("cls");
    cout << "    >>> MENU  GLOWNE <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Rejestracja" << endl;
    cout << "2. Logowanie" << endl;
    cout << "9. Koniec programu" << endl;
    cout << "---------------------------" << endl;
    cout << "Twoj wybor: ";
    wybor = wczytajZnak();

    return wybor;
}

int Metody_pomocnicze::wczytajLiczbeCalkowita() {

    string wejscie = "";
    int liczba = 0;

    while (true) {

        getline(cin, wejscie);

        stringstream myStream(wejscie);
        if (myStream >> liczba)
            break;
        cout << "To nie jest liczba. Wpisz ponownie. " << endl;

    }
    return liczba;
}

char Metody_pomocnicze::wybierzOpcjeZMenuEdycja() {
    char wybor;

    cout << endl << "   >>> MENU  EDYCJA <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "Ktore dane zaktualizowac: " << endl;
    cout << "1 - Imie" << endl;
    cout << "2 - Nazwisko" << endl;
    cout << "3 - Numer telefonu" << endl;
    cout << "4 - Email" << endl;
    cout << "5 - Adres" << endl;
    cout << "6 - Powrot " << endl;
    cout << endl << "Twoj wybor: ";
    wybor = wczytajZnak();

    return wybor;
}
