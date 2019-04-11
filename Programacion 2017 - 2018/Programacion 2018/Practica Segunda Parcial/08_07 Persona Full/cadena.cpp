#include <iostream>
#include "cadena.h"
#include "string.h"

char* Cadena::_strcat(char* dest, const char* src)
{
    char* inicio = dest;
    while(*dest) dest++;
    while(*src)
    {
        *dest = *src;
        dest++;
        src++;
    }
    *dest = '\0';
    return inicio;
}

char* Cadena::_strcpy(char* dest, const char* src)
{
    char* inicio = dest;
    while(*src)
    {
        *dest = *src;
        dest++;
        src++;
    }
    *dest = '\0';
    return inicio;
}

size_t Cadena::_strlen(const char* cad)
{
    size_t l = 0;
    while(*cad)
    {
        l++;
        cad++;
    }
    return l;
}

Cadena::Cadena(size_t l)
{
    this->cad = new char[l+1];
}

Cadena::Cadena(const Cadena& otra)
{
    *this = otra;
}

Cadena::Cadena(const char* cad)
{
    this->cad = new char[_strlen(cad)+1];
    _strcpy(this->cad, cad);
    this->cad[_strlen(cad)] = '\0';
}

Cadena& Cadena::operator=(const char* cad)
{
    delete[]this->cad;
    this->cad = new char[_strlen(cad)+1];
    _strcpy(this->cad, cad);
    return *this;
}

Cadena& Cadena::operator=(const Cadena& otra)
{
    delete[]this->cad;
    this->cad = new char[_strlen(otra.cad)+1];
    _strcpy(this->cad, otra.cad);
    return *this;
}

Cadena& Cadena::operator+=(const Cadena& otra)
{
    Cadena nueva(_strlen(this->cad)+_strlen(otra.cad));
    _strcpy(nueva.cad, this->cad);
    _strcat(nueva.cad, otra.cad);
    nueva.cad[_strlen(nueva.cad)] = '\0';
    return (*this=nueva);
}

Cadena& Cadena::operator+=(const char c)
{
    Cadena nueva(_strlen(this->cad)+1);
    _strcpy(nueva.cad, this->cad);
    nueva.cad[_strlen(nueva.cad)] = c;
    nueva.cad[_strlen(nueva.cad)+1] = '\0';
    return (*this=nueva);
}

Cadena& Cadena::operator+=(const char* otra)
{
    Cadena nueva(_strlen(this->cad)+_strlen(otra));
    _strcpy(nueva.cad, this->cad);
    _strcat(nueva.cad, otra);
    nueva.cad[_strlen(nueva.cad)] = '\0';
    return (*this=nueva);
}

Cadena::~Cadena()
{
    delete[]this->cad;
}

ostream& operator<<(ostream&sal, const Cadena&c)
{
    sal << c.cad;
    return sal;
}

char* Cadena::getCad()const
{
    return this->cad;
}

char* operator+(char* primitivo, Cadena& obj)
{
    return NULL;
    /*char* nueva = (char*)malloc(sizeof(strlen(primitivo)+strlen(obj.getCad())));
    char* inicio = nueva;
    strcpy(nueva, primitivo);
    strcat(nueva, obj.getCad());
    nueva[strlen(nueva)] = '\0';
    return inicio;*/
}
