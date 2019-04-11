#ifndef CADENAS_H_INCLUDED
#define CADENAS_H_INCLUDED
#include <iostream>
#include <string.h>
using namespace std;

class Cadena
{
private:
    char *cadena;
    Cadena(int capacidad);
public:
    Cadena (const char* Cadena = NULL);
    Cadena (const Cadena &otra);
    ~Cadena(); //DESTRUCTOR
    Cadena &operator=(const Cadena &otra);
    Cadena operator+(const Cadena &c2)const;
    Cadena operator+(const char* c2)const;
    Cadena operator+(char c)const;
    Cadena &operator+=(const Cadena &c2);
    friend ostream& operator<<(ostream &sal, Cadena &c);
};

#endif // CADENAS_H_INCLUDED
