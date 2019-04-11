#include <iostream>
#include "cadena.h"

Cadena::Cadena(const int capacidad)
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
    this->cadena = new char [strlen(otra.cadena)+1];
    strcpy(this->cadena, otra.cadena);
    return;
}

Cadena::~Cadena()
{
    delete[]this->cadena;
    return;
}

Cadena& Cadena:: operator=(const Cadena &otra)
{
    int longThis = strlen(this->cadena);
    int longOtra = strlen(otra.cadena);
    if(longThis != longOtra)
    {
        delete[]this->cadena;
        this->cadena = new char [strlen(otra.cadena)+1];
    }
    strcpy(this->cadena, otra.cadena);
    return *this;
}

Cadena Cadena::operator+(const char* cadena)const
{
    int LongSuma = strlen(this->cadena) + strlen(cadena) + 1;
    Cadena Suma(LongSuma);
    strcpy(Suma.cadena, this->cadena);
    strcat(Suma.cadena, cadena);
    return Suma;
}

Cadena Cadena::operator+(const Cadena &otra)const
{
    int LongSuma = strlen(this->cadena) + strlen(otra.cadena) + 1;
    Cadena Suma(LongSuma);
    strcpy(Suma.cadena, this->cadena);
    strcat(Suma.cadena, otra.cadena);
    return Suma;
}

Cadena Cadena::operator+(char c)const
{
    Cadena Suma(strlen(this->cadena)+2);
    strcpy(Suma.cadena, this->cadena);
    Suma.cadena[strlen(this->cadena)] = c;
    Suma.cadena[strlen(this->cadena)+1] = '\0';
    return Suma;
}

Cadena& Cadena::operator+=(const Cadena &otra)
{
    Cadena Suma(strlen(this->cadena)+strlen(otra.cadena)+1);
    strcpy(Suma.cadena, this->cadena);
    strcat(Suma.cadena, otra.cadena);
    delete[]this->cadena;
    this->cadena = new char[strlen(this->cadena)+strlen(otra.cadena)+1];
    strcpy(this->cadena, Suma.cadena);
    return *this;
}

ostream& operator<<(ostream& sal, Cadena& cadena)
{
    sal << cadena.cadena;
    return sal;
}
