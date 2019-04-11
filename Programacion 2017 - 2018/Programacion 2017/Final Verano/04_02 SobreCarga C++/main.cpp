#include <iostream>
#include "ejemplo.h"


using namespace std;

int main()
{
    Entero e1(21);
    Entero* e2 = new Entero(10); // CON ESTE PUEDO HACER DELETE.
    Entero e3(-7);
    /*cout <<"Introduzca un numero:";
    cin >> e3;
    cout <<"El numero ingresado es:"<<e3;*/
    cout << (e1==e3);
}
