#include "Metody_pomocnicze.h"
#include <sstream>


string Metody_pomocnicze::konwerjsaIntNaString(int liczba)
{
    ostringstream ss;
    ss << liczba;
    string str = ss.str();
    return str;
}
