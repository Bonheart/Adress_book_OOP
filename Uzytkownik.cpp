#include "Uzytkownik.h"

void Uzytkownik::ustaw_id(int nowe_id) { // setter

    if(nowe_id >= 0)
        id = nowe_id;

}

void Uzytkownik::ustaw_haslo(string nowe_haslo) { // setter

    haslo = nowe_haslo;

}

void Uzytkownik::ustaw_login(string nowy_login) { // setter

    login = nowy_login;
}


int  Uzytkownik::pobierz_Id() { //  getter

    return id;

}
string Uzytkownik::pobierz_login() { // getter

    return login;

}

string Uzytkownik::pobierz_haslo() { // getter

    return haslo;

}
