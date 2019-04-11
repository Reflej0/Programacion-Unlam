#include <iostream>
#include "cadena.h"

Cadena::Cadena(int capacidad)
{
    this->cadena = new char[capacidad];
}

Cadena::Cadena(const char* cadena)
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

Cadena&Cadena:: operator=(const Cadena &otra)
{
    int longThis = strlen(this->cadena);
    int longOtra = strlen(otra.cadena);
    if(longThis != longOtra)
    {
        delete[]this->cadena;
        this->cadena = new char[longOtra+1];
    }
    strcpy(this->cadena, otra.cadena);
    return *this;
}

Cadena Cadena::operator+(const Cadena &otra)const
{
    int longThis = strlen(this->cadena);
    int longOtra = strlen(otra.cadena);
    Cadena suma(longThis+longOtra+1);
    strcpy(suma.cadena, this->cadena);
    strcat(suma.cadena, otra.cadena);
    return suma;
}

Cadena Cadena::operator+(const char* cadena)const
{
    int longThis = strlen(this->cadena);
    int longOtra = strlen(cadena);
    Cadena suma(longThis+longOtra+1);
    strcpy(suma.cadena, this->cadena);
    strcat(suma.cadena, cadena);
    return suma;
}

Cadena Cadena::operator+(const char c)const
{
    int longThis = strlen(this->cadena);
    Cadena suma(longThis+2);
    strcpy(suma.cadena, this->cadena);
    suma.cadena[longThis] = c;
    suma.cadena[longThis+1] = '\0';
    return suma;
}

Cadena& Cadena::operator+=(const Cadena &otra)
{
    int longThis = strlen(this->cadena);
    int longOtra = strlen(otra.cadena);
    Cadena suma(longThis+longOtra+1);
    strcpy(suma.cadena, this->cadena);
    strcat(suma.cadena, otra.cadena);
    delete[]this->cadena;
    this->cadena = new char[longThis+longOtra+1];
    strcpy(this->cadena, suma.cadena);
    return *this;
}

ostream& operator<<(ostream& sal, Cadena& Cadena)
{
    sal << Cadena.cadena;
    return sal;
}
