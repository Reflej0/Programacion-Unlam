#include <iostream>
#include "string.h"
#include "cadenas.h"

Cadena::Cadena(const char* cadena)
{
    int longitud = strlen(cadena);
    if(longitud == 0)
    {
        this->cadena = new char[1];
        this->cadena[0] = '\0';
    }
    else
    {
        this->cadena = new char [longitud+1];
        strcpy(this->cadena, cadena);
        this->cadena[longitud] = '\0';
    }
}

Cadena::Cadena(int capacidad)
{
    this->cadena = new char[capacidad];
}

Cadena&Cadena::operator=(const Cadena &otra)
{
    int thislong = strlen(this->cadena);
    int otralong = strlen(otra.cadena);
    if(thislong == otralong)
    {
        strcpy(this->cadena, otra.cadena);
        this->cadena[thislong] = '\0';
    }
    else
    {
        delete[]this->cadena;
        this->cadena = new char[otralong+1];
        strcpy(this->cadena, otra.cadena);
        this->cadena[otralong] = '\0';
    }
    return *this;
}

Cadena Cadena::operator+(const char* otra)
{
    int thislong = strlen(this->cadena);
    int otralong = strlen(otra);
    Cadena retorno(thislong+otralong+1);
    strcpy(retorno.cadena, this->cadena);
    strcat(retorno.cadena, otra);
    retorno.cadena[thislong+otralong+1] = '\0';
    return retorno;
}

Cadena Cadena::operator+(char c)
{
    int thislong = strlen(this->cadena);
    Cadena retorno(thislong+2);
    strcpy(retorno.cadena, this->cadena);
    retorno.cadena[thislong] = c;
    retorno.cadena[thislong+1] = '\0';
    return retorno;
}

Cadena Cadena::operator+(const Cadena &otra)
{
    int thislong = strlen(this->cadena);
    int otralong = strlen(otra.cadena);
    Cadena retorno(thislong+otralong+1);
    strcpy(retorno.cadena, this->cadena);
    strcat(retorno.cadena, otra.cadena);
    retorno.cadena[thislong+otralong+1] = '\0';
    return retorno;
}

Cadena& Cadena::operator+=(const Cadena &otra)
{
    int thislong = strlen(this->cadena);
    int otralong = strlen(otra.cadena);
    Cadena retorno(thislong+otralong+1);
    strcpy(retorno.cadena, this->cadena);
    strcat(retorno.cadena, otra.cadena);
    retorno.cadena[thislong+otralong+1] = '\0';
    strcpy(this->cadena, retorno.cadena);
    return *this;
}

ostream& operator<<(ostream &sal, Cadena &otra)
{
    sal << otra.cadena;
    return sal;
}
