#ifndef CADENAS_H_INCLUDED
#define CADENAS_H_INCLUDED
#include <iostream>

using namespace std;

class Cadena
{
private:
    char* cadena;
    Cadena(int capacidad);
public:
    Cadena(const char* cadena);
    Cadena&operator=(const Cadena &otra);
    Cadena&operator+=(const Cadena &otra);
    Cadena operator+(const char* otra);
    Cadena operator+(char c);
    Cadena operator+(const Cadena &otra);
    friend ostream& operator<<(ostream &sal, Cadena &otra);
};

#endif // CADENAS_H_INCLUDED
