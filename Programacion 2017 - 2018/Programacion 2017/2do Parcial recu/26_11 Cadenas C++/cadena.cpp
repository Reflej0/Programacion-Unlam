#include <iostream>
#include "cadena.h"

Cadena::Cadena(int capacidad)
{
    this->cadena = new char[capacidad];
}

Cadena::Cadena(const Cadena& otra)
{
    size_t longOtra = strlen(otra.cadena);
    this->cadena = new char[longOtra+1];
    strcpy(this->cadena, otra.cadena);
    return;
}

Cadena::Cadena(const char* otra)
{
    if(!otra)
    {
        this->cadena = new char[1];
        this->cadena[0] = '\0';
        return;
    }
    size_t longOtra = strlen(otra);
    this->cadena = new char[longOtra+1];
    strcpy(this->cadena, otra);
}

Cadena::~Cadena()
{
    delete[]this->cadena;
    return;
}

Cadena& Cadena::operator+=(const Cadena& otra)
{
    size_t longThis = strlen(this->cadena);
    size_t longOtra = strlen(otra.cadena);
    Cadena suma(longThis+longOtra+1);
    strcpy(suma.cadena, this->cadena);
    strcat(suma.cadena, otra.cadena);
    delete[]this->cadena;
    this->cadena = new char[longThis+longOtra+1];
    strcpy(this->cadena, suma.cadena);
    return *this;
}

Cadena Cadena::operator+(const char* otra)const
{
    size_t longThis = strlen(this->cadena);
    size_t longOtra = strlen(otra);
    Cadena suma = new char[longThis+longOtra+1];
    strcpy(suma.cadena, this->cadena);
    strcat(suma.cadena, otra);
    return suma;
}

Cadena Cadena::operator+(Cadena& otra)const
{
    size_t longThis = strlen(this->cadena);
    size_t longOtra = strlen(otra.cadena);
    Cadena suma = new char[longThis+longOtra+1];
    strcpy(suma.cadena, this->cadena);
    strcat(suma.cadena, otra.cadena);
    return suma;
}

Cadena Cadena::operator+(char c)const
{
    size_t longThis = strlen(this->cadena);
    Cadena suma = new char[longThis+2];
    strcpy(suma.cadena, this->cadena);
    suma.cadena[longThis+1] = c;
    suma.cadena[longThis+2] = '\0';
    return suma;
}

Cadena& Cadena::operator=(Cadena& otra)
{
    size_t longThis = strlen(this->cadena);
    size_t longOtra = strlen(otra.cadena);\
    if(longThis!=longOtra)
    {
        delete[]this->cadena;
        this->cadena = new char[longOtra+1];
    }
    strcpy(this->cadena, otra.cadena);
    return *this;
}

ostream& operator<<(ostream& sal, Cadena& Cadena)
{
    sal << Cadena.cadena;
    return sal;
}
