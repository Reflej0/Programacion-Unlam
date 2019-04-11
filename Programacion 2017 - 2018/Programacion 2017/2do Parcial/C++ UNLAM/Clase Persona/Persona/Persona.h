#ifndef PERSONA_H
#define PERSONA_H
#include <iostream>
#include "Fecha.h"

class Persona
{
    public:
        Persona(char*=NULL,char*=NULL,int=0,Fecha):Fecha::Fecha(int=0,int=0,int=0);
        ~Persona();
    protected:
    private:
        char* Nombre;
        char* Apellido;
        int DNI;
        Fecha FechNac;
};

#endif // PERSONA_H
