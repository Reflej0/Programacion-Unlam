#ifndef CADENA_H_INCLUDED
#define CADENA_H_INCLUDED

#include "string.h"

using namespace std;

class Cadena
{
private:
    char * cadena;
    Cadena (const int capacidad);
public:
    Cadena(const char* cadena);
    Cadena(const Cadena &cadena);
    ~Cadena();
    Cadena& operator=(const Cadena &otra);
    Cadena operator+(const char* cadena)const;
    Cadena operator+(const Cadena &otra)const;
    Cadena operator+(char c)const;
    Cadena& operator+=(const Cadena &otra);
    friend ostream& operator<<(ostream& sal, Cadena& cadena);
};

#endif // CADENA_H_INCLUDED
