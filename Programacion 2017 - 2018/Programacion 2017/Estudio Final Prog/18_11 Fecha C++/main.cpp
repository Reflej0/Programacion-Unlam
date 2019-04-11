#include <iostream>
#include <istream>
#include "fecha.h"

using namespace std;

int main()
{
    Fecha f_teclado;
    cout << "Ingrese una fecha:";
    cin >> f_teclado;
    cout << f_teclado+1;
    //cout << 1+f_teclado;
}
