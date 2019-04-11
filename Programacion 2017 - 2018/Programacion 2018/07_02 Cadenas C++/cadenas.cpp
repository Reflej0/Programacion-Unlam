#include <iostream>
#include "cadenas.h"
#include "string.h"

Cadena::Cadena(int capacidad)
{
    this->cadena = new char[capacidad];
}

Cadena::Cadena(const char* otra)
{
    if(strlen(otra) == 0)
    {
        this->cadena = new char[1];
        this->cadena[0] = '\0';
        return;
    }
    else
    {
        this->cadena = new char[strlen(otra)+1];
        strcpy(this->cadena, otra);
        this->cadena[strlen(otra)] = '\0';
    }
}

Cadena& Cadena::operator=(Cadena &otra)
{
    if(strlen(this->cadena) == strlen(otra.cadena))
    {
        strcpy(this->cadena, otra.cadena);
        return *this;
    }
    else
    {
        delete[]this->cadena;
        this->cadena = new char[strlen(otra.cadena)+1];
        strcpy(this->cadena, otra.cadena);
        this->cadena[strlen(otra.cadena)] = '\0';
        return *this;
    }
}

Cadena Cadena::operator+(Cadena &otra)
{
    Cadena retorno(strlen(this->cadena)+strlen(otra.cadena)+1);
    strcpy(retorno.cadena, this->cadena);
    strcat(retorno.cadena, otra.cadena);
    retorno.cadena[strlen(this->cadena)+strlen(otra.cadena)] = '\0';
    return retorno;
}

Cadena Cadena::operator+(char* otra)
{
    Cadena retorno(strlen(this->cadena)+strlen(otra)+1);
    strcpy(retorno.cadena, this->cadena);
    strcat(retorno.cadena, otra);
    retorno.cadena[strlen(this->cadena)+strlen(otra)] = '\0';
    return retorno;
}

Cadena Cadena::operator+(char c)
{
    Cadena retorno(strlen(this->cadena)+2);
    strcpy(retorno.cadena, this->cadena);
    retorno.cadena[strlen(this->cadena)] = c;
    retorno.cadena[strlen(this->cadena)+1] = '\0';
    return retorno;
}

Cadena& Cadena::operator+=(Cadena &otra)
{
    Cadena retorno(strlen(this->cadena)+strlen(otra.cadena)+1);
    strcpy(retorno.cadena, this->cadena);
    strcat(retorno.cadena, otra.cadena);
    retorno.cadena[strlen(this->cadena)+strlen(otra.cadena)] = '\0';
    *this = retorno;
    return *this;
}

ostream& operator<<(ostream& sal, Cadena& otra)
{
    sal << otra.cadena;
    return sal;
}
