#include <string.h>

#include "persona.h"

Persona::Persona(const char* apellido,const char* nombre,char sexo,int edad,double importe)
{

    strncpy(ap,apellido,20);
    ap[20]='\0';
    strncpy(nom,nombre,25);
    nom[25]='\0';
    sx=sexo;
    this->edad=edad;
    imp=importe;
}
Persona::Persona(const Persona& p)
{
    strcpy(ap,p.ap);
    strcpy(nom,p.nom);
    sx=p.sx;
    edad=p.edad;
    imp=p.imp;
}
ostream& operator<<(ostream& out,const Persona& p)
{
    out<<"Apellido(s): "<<p.ap<<endl;
    out<<"Nombre(s):   "<<p.nom<<endl;
    out<<"Sexo:        "<<p.sx<<endl;
    out<<"Edad:        "<<p.edad<<endl;
    out<<"Importe:     "<<p.imp<<endl;

    return out;
}
Persona Persona::operator++(int)
{
    Persona aux=*this;
    edad++;
    return aux;
}
Persona& Persona::operator=(const Persona& p)
{
    strcpy(ap,p.ap);
    strcpy(nom,p.nom);
    sx=p.sx;
    edad=p.edad;
    imp=p.imp;
    return *this;
}

Persona& Persona::operator=(const double importe)
{
    imp=importe;
    return *this;
}
bool Persona::operator==(const Persona& p)
{
    return (!strcmp(ap,p.ap))&&(!strcmp(nom,p.nom));
}

