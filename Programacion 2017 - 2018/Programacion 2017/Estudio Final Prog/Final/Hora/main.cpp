#include <iostream>
#include <stdlib.h>
#include "hora.h"

using namespace std;

void probarHora(int hh, int mm, int ss, int segundos)
{
    Hora h1(hh, mm, ss);
    Hora h2(segundos);
    Hora h3(h1 * 3);
    Hora h4(3 * h3);
    Hora h5;

    cout << "h1 = " << h1 << endl << "h2 = " << h2 << endl << "h3 = " << h3 << endl << "h4 = " << h4 << endl << "h5 = " << h5 << endl << endl;
    h5 = h2 += h3 += h4 +=ss;
    cout << "h1 - h2 =" << h1 - h2 << endl;
    cout << "h1 = " << h1 << endl << "h2 = " << h2 << endl << "h3 = " << h3 << endl << "h4 = " << h4 << endl << "h5 = " << h5 << endl << endl;
}

int main()
{
    cout << "Una prueba" << endl;
    probarHora(10, 20, 30, -30000);
    cout << "Otra prueba" << endl;
    probarHora(-10, -20, -30, 300000);
    cout << "Prueba Final" << endl;
    probarHora(10, 200, -300, 0);
    return 0;
}
