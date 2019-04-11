#include <iostream>
#include "racional.h"

using namespace std;

int main()
{
    Racional numero(-1);
    /*if(numero.getSigno() == -1)
    {
        cout << '-' << numero.getNumerador() << '\n' << "-----" << '\n' << numero.getDenominador();
    }
    else
    {
        cout << numero.getNumerador() << '\n' << "-----" << '\n' << numero.getDenominador();
    }*/
    Racional numero2(1);
    numero+=numero2;
    if(numero.getSigno() == -1)
    {
        cout << '-' << numero.getNumerador() << '\n' << "-----" << '\n' << numero.getDenominador();
    }
    else
    {
        cout << numero.getNumerador() << '\n' << "-----" << '\n' << numero.getDenominador();
    }

}
