#ifndef PERSONA_H_
#define PERSONA_H_


#include <iostream>
using namespace std;

class Persona
{
    private:
        char ap[21];
        char nom[26];
        char sx;
        int edad;
        double imp;
    public:
        Persona(const char* apellido="\0",const char* nombre="\0",char sexo='\0',int edad=0,double importe=0);
        Persona(const Persona&);
        friend ostream& operator<<(ostream&,const Persona&);
        Persona operator++(int);
        Persona& operator=(const Persona&);
        Persona& operator=(const double);
        bool operator==(const Persona&);

};

#endif // PERSONA_H_

