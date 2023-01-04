#ifndef UZYTKOWNIK_H
#define UZYTKOWNIK_H
#include <iostream>

using namespace std;


class Uzytkownik {

    int id ;
    string login;
    string haslo ;

    public :
         // settery
    void ustaw_id(int nowe_id);
    void ustaw_login(string nowy_login);
    void ustaw_haslo(string nowe_haslo);

    // gettery
    int pobierz_Id();
    string pobierz_login();
    string pobierz_haslo();


};
#endif // UZYTKOWNIK_H
