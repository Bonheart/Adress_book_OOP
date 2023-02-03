#include "Adresaci.h"

void Adresat::ustaw_id(int nowe_id_adresata) {

    if(nowe_id_adresata >= 0) {

        id = nowe_id_adresata;
    }
}

void Adresat::ustaw_id_zalogowanego_uzytkownika(int nowe_id_zalogwanego_uzytkownika) {

    if(nowe_id_zalogwanego_uzytkownika >=0 ) {

        idUzytkownika = nowe_id_zalogwanego_uzytkownika;

    }

}

void Adresat::ustaw_imie(string nowe_imie) {

    imie = nowe_imie;

}


void Adresat::ustaw_nazwisko(string nowe_nazwisko) {

    nazwisko = nowe_nazwisko;
}

void Adresat::ustaw_nr_telefonu(string nowy_nr_telefonu) {

    nr_telefonu = nowy_nr_telefonu;
}

void Adresat::ustaw_email(string nowy_email) {

    email = nowy_email;

}

void Adresat::ustaw_adres(string nowy_adres) {

    adres = nowy_adres;

}


int Adresat::pobierz_id() {

    return id;
}

int Adresat::pobierz_id_zalogowanego_uzytkownika() {

    return idUzytkownika;
}

string Adresat::pobierz_imie() {

    return imie;
}

string Adresat::pobierz_nazwisko() {

    return nazwisko;
}

string Adresat::pobierz_nr_telefonu() {

    return nr_telefonu;

}

string Adresat::pobierz_email() {

    return email;
}


string Adresat::pobierz_adres() {

    return adres;

}
