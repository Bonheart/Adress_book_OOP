#ifndef ADRESACI.H
#define ADRESACI.H

#include <iostream>

using namespace std;

class Adresat{

private:
    int id;
    int idUzytkownika;
    string imie;
    string nazwisko;
    string email;
    string nr_telefonu;
    string adres;

public:

    int ustaw_id(int nowe_id_adresata);
    int ustaw_id_zalogowanego_uzytkownika(int nowe_id_zalogowanego_uzytkownika);
    string ustaw_imie(string nowe_imie);
    string ustaw_nazwisko(string nowe_nazwisko);
    string ustaw_nr_telefonu(string nowy_numer_telefonu);
    string ustaw_email(string nowy_email);
    string ustaw_adres(string nowy_adres);

    int pobierz_id();
    int pobierz_id_zalogowanego_uzytkownika();
    string pobierz_imie();
    string pobierz_nazwisko();
    string pobierz_nr_telefonu();
    string pobierz_email();
    string pobierz_adres();


};
#endif // ADRESACI
