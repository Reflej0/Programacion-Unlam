#include <iostream>
#include <string.h>
#include "cadenas.h"

Cadena::Cadena(int tam)
{
    this->cad = new char[tam];
}

Cadena::Cadena(const char* cad)
{
    int longcad = strlen(cad);
    if(longcad == 0)
    {
        this->cad = new char[1];
        this->cad[0] = '\0';
        return;
    }
    else
    {
        this->cad = new char[longcad+1];
        strcpy(this->cad, cad);
        this->cad[longcad] = '\0';
        return;
    }
}

Cadena& Cadena::operator=(const Cadena& otra)
{
    int thislong = strlen(this->cad);
    int otralong = strlen(otra.cad);
    if(thislong == otralong)
    {
        strcpy(this->cad, otra.cad);
        return *this;
    }
    else
    {
        delete[]this->cad;
        this->cad = new char[otralong];
        strcpy(this->cad, otra.cad);
        return *this;
    }
}

Cadena::~Cadena()
{
    delete[]this->cad;
}

Cadena Cadena::operator+(const char c)const
{
    int thislong = strlen(this->cad);
    Cadena temp(thislong+2);
    strcpy(temp.cad, this->cad);
    temp.cad[thislong] = c;
    temp.cad[thislong+1] = '\0';
    return temp;
}

Cadena Cadena::operator+(const char* otra)const
{
    int thislong = strlen(this->cad);
    int otralong = strlen(otra);
    Cadena temp(thislong+otralong+1);
    strcpy(temp.cad, this->cad);
    strcat(temp.cad, cad);
    temp.cad[thislong+otralong] = '\0';
    return temp;
}

Cadena Cadena::operator+(const Cadena& otra)const
{
    int thislong = strlen(this->cad);
    int otralong = strlen(otra.cad);
    Cadena temp(thislong+otralong+1);
    strcpy(temp.cad, this->cad);
    strcat(temp.cad, otra.cad);
    temp.cad[thislong+otralong] = '\0';
    return temp;
}

Cadena& Cadena::operator+=(const Cadena&otra)
{
    int thislong = strlen(this->cad);
    int otralong = strlen(otra.cad);
    Cadena temp(thislong+otralong+1);
    strcpy(temp.cad, this->cad);
    strcat(temp.cad, otra.cad);
    *this = temp;
    return *this;
}

ostream& operator<<(ostream& sal, Cadena& cad)
{
    sal << cad.cad;
    return sal;
}
