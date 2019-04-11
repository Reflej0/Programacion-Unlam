#include <iostream>
#include <istream>
#include "persona.h"
#include "fecha.h"
#include "cadenas.h"

using namespace std;

int main()
{
    Cadena apyn("Juan Tocino");
    Fecha Fnac(27, 10, 1994);
    Persona Yo(38617339, apyn, 'M', Fnac);
    cout << Yo;
}
