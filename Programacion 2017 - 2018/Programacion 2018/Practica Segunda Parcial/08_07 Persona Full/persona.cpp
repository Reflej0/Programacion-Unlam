#include <iostream>
#include <stdlib.h>
#include "persona.h"

Persona::Persona(const long dni, const Cadena&nya, const Fecha&f)
{
    this->dni = dni;
    this->nya = nya;
    this->fnac = f;
}

ostream& operator<<(ostream&sal, const Persona&p)
{
    sal << "Dni:" << p.dni << " Nya:" << p.nya.getCad() << " Fnac:" << p.fnac <<endl;
    return sal;
}
