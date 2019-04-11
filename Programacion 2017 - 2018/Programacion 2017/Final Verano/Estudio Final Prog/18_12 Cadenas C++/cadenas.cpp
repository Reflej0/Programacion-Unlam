#include <iostream>
#include "cadenas.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

Cadena::Cadena(int capacidad)
{
    this->cadena = new char[capacidad];
}

Cadena::Cadena(const char* cadena)
{
    if(strlen(cadena) == 0)
    {
        this->cadena = new char[1];
        this->cadena[0] = '\0';
        return;
    }
    else
    {
        this->cadena = new char[strlen(cadena)];
        strcpy(this->cadena, cadena);
        this->cadena[strlen(cadena)] = '\0';
        return;
    }
}

Cadena::~Cadena()
{
    delete[]this->cadena;
}

Cadena& Cadena::operator+=(const Cadena& otra)
{
    size_t thislong = strlen(this->cadena);
    size_t otralong = strlen(otra.cadena);
    Cadena suma(thislong+otralong+1);
    strcpy(suma.cadena, this->cadena);
    strcat(suma.cadena, otra.cadena);
    suma.cadena[thislong+otralong+1] = '\0';
    strcpy(this->cadena, suma.cadena);
    return *this;
}

Cadena& Cadena::operator=(const char* otra)
{
    size_t thislong = strlen(this->cadena);
    size_t otralong = strlen(this->cadena);
    if(thislong == otralong)
    {
        strcpy(this->cadena, otra);
        this->cadena[thislong] = '\0';
    }
    else
    {
        delete[]this->cadena;
        this->cadena = new char[otralong+1];
        strcpy(this->cadena, otra);
        this->cadena[otralong] = '\0';
    }
    return *this;
}

Cadena Cadena::operator+(const char* otra)const
{
    size_t thislong = strlen(this->cadena);
    size_t otralong = strlen(cadena);
    Cadena retorno(thislong+otralong+1);
    strcpy(retorno.cadena, this->cadena);
    strcat(retorno.cadena, otra);
    retorno.cadena[thislong+otralong+1] = '\0';
    return retorno;
}

Cadena Cadena::operator+(const Cadena& otra)const
{
    size_t thislong = strlen(this->cadena);
    size_t otralong = strlen(otra.cadena);
    Cadena retorno(thislong+otralong+1);
    strcpy(retorno.cadena, this->cadena);
    strcat(retorno.cadena, otra.cadena);
    retorno.cadena[thislong+otralong+1] = '\0';
    return retorno;
}

Cadena Cadena::operator+(char c)const
{
    size_t thislong = strlen(this->cadena);
    Cadena retorno(thislong+2);
    strcpy(retorno.cadena, this->cadena);
    retorno.cadena[thislong] = c;
    retorno.cadena[thislong+1] = '\0';
    return retorno;
}

ostream& operator<<(ostream& sal, Cadena& otra)
{
    sal << otra.cadena;
    return sal;
}
