#include <iostream>
#include "persona.h"

using namespace std;

int main()
{
    Persona p1;
    cout<<p1;
    Fecha f1(12, 5, 2004);
    char nombre[500]="Juan Perez";
    Persona p2(12345, nombre, f1);
    cout<<p2;
    p1 = p2;
    cout<<p1;
    return 0;
}
