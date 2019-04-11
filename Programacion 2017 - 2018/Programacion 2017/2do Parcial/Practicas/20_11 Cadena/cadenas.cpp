#include <iostream>
#include "cadenas.h"

Cadena::Cadena(int capacidad)
{
    this->cadena = new char[capacidad];
}

Cadena::Cadena (const char* cadena)
{
    if(!cadena)
    {
        this->cadena = new char[1];
        this->cadena[0] = '\0';
        return;
    }
    this->cadena = new char[strlen(cadena)+1];
    strcpy(this->cadena, cadena);
    return;
}

Cadena::Cadena(const Cadena &otra)
{
    this->cadena = new char[strlen(otra.cadena)+1];
    strcpy(this->cadena, otra.cadena);
    return;
}

Cadena::~Cadena()
{
    delete[]this->cadena;
    return;
}

Cadena&Cadena::operator=(const Cadena &otra)
{
    unsigned longOtra = strlen(otra.cadena);
    if(strlen(this->cadena)!=longOtra)
    {
        delete[]this->cadena;
        this->cadena = new char[longOtra+1];
    }
    strcpy(this->cadena, otra.cadena);
    return *this;
}

Cadena Cadena::operator+(const Cadena &c2)const
{
    unsigned longOtra = strlen(c2.cadena);
    unsigned longThis = strlen(this->cadena);
    Cadena respuesta = new char[longOtra+longThis+1];
    strcpy(respuesta.cadena, this->cadena);
    strcat(respuesta.cadena, c2.cadena);
    return respuesta;
}

Cadena Cadena::operator+(const char* c2)const
{
    unsigned longOtra = strlen(c2);
    unsigned longThis = strlen(this->cadena);
    Cadena respuesta = new char[longOtra+longThis+1];
    strcpy(respuesta.cadena, this->cadena);
    strcat(respuesta.cadena, c2);
    return respuesta;
}

Cadena Cadena::operator+(char c)const
{
    unsigned longThis = strlen(this->cadena);
    Cadena respuesta = new char[longThis+2];
    strcpy(respuesta.cadena, this->cadena);
    respuesta.cadena[longThis] = c;
    respuesta.cadena[longThis+1]= '\0';
    return respuesta;
}

Cadena &Cadena::operator+=(const Cadena &c2)
{
    unsigned longThis = strlen(this->cadena);
    unsigned longOtra = strlen(c2.cadena);
    Cadena Suma = new char[longThis + longOtra + 1];
    strcpy(Suma.cadena, this->cadena);
    strcat(Suma.cadena, c2.cadena);
    delete[]this->cadena;
    this->cadena = Suma.cadena;
    return *this;
}

ostream& operator<<(ostream &sal, Cadena &c)
{
    sal<<c.cadena;
    return sal;
}
