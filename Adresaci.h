#ifndef ADRESACI_H
#define ADRESACI_H

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

    void ustaw_id(int nowe_id_adresata);
    void ustaw_id_zalogowanego_uzytkownika(int nowe_id_zalogowanego_uzytkownika);
    void ustaw_imie(string nowe_imie);
    void ustaw_nazwisko(string nowe_nazwisko);
    void ustaw_nr_telefonu(string nowy_numer_telefonu);
    void ustaw_email(string nowy_email);
    void ustaw_adres(string nowy_adres);

    int pobierz_id();
    int pobierz_id_zalogowanego_uzytkownika();
    string pobierz_imie();
    string pobierz_nazwisko();
    string pobierz_nr_telefonu();
    string pobierz_email();
    string pobierz_adres();


};
#endif // ADRESACI
