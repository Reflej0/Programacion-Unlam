#include <iostream>


#include "main.h"
using namespace std;

void probarPersonas(const char *ape1, const char *nom1, char sex1,
                    int edad1, double imp1)
{
    Persona  p1(ape1, nom1, sex1, edad1, imp1),
             p2(p1),
             p3;

    cout << "Valores iniciales:" << endl
         << "p1" << endl << p1 << endl
         << "p2" << endl << p2 << endl
         << "p3" << endl << p3 << endl << endl;

    p3 = p1++;               /// modifica la edad
    double imp2 = 90.75;
    Persona p4 = p1 = imp2;

    cout << "Valores finales:" << endl
         << "p1" << endl << p1 << endl
         << "p2" << endl << p2 << endl
         << "p3" << endl << p3 << endl
         << "p4" << endl << p4 << endl << endl;
    if(p1 == p4)
        cout << "Probando la comparacion" << endl
             << p1 << (p1 == p4 ? "Es Identico a" : "Difiere de")
             << endl << p4 << endl;
}


int main()
{
    probarPersonas("Martinez Rodriguez del Rio",
                   "Ernestina Maria de los Angeles",
                   'F',  22,  33.9);

    return 0;
}

