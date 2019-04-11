#ifndef CADENA_H_INCLUDED
#define CADENA_H_INCLUDED

#include "string.h"

using namespace std;

class Cadena
{
private:
    char* cadena;
    Cadena(int capacidad);
public:
    Cadena(const char* cadena);
    Cadena(const Cadena &cadena);
    ~Cadena();
    Cadena& operator=(const Cadena &otra);
    Cadena operator+(const Cadena &otra)const;
    Cadena operator+(const char* cadena)const;
    Cadena operator+(const char c)const;
    Cadena& operator+=(const Cadena &otra);
    friend ostream& operator<<(ostream& sal, Cadena& Cadena);
};

#endif // CADENA_H_INCLUDED
