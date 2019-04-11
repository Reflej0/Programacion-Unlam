#ifndef PERSONA_H_INCLUDED
#define PERSONA_H_INCLUDED
#include "fecha.h"
#include "cadenas.h"
#include <iostream>
#include <istream>

using namespace std;

class Persona
{
private:
    int dni;
    Cadena apyn;
    char sexo;
    Fecha Fnac;

public:
    Persona(int dni = 0, const Cadena &apyn=Cadena(), char sexo='M', const Fecha &Fnac=Fecha());
    void setDni(int dni);
    void setApyn(const Cadena &apyn);
    const char*getApyn()const;
    int getDni()const;
    int getEdad(const Fecha&f)const;
    Fecha getFnac()const;
    friend ostream&operator<<(ostream &Sal, const Persona &P);
    friend istream&operator>>(istream &En, Persona &);
};

#endif // PERSONA_H_INCLUDED
