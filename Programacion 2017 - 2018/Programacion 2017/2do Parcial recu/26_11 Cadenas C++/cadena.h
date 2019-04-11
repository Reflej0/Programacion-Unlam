#ifndef CADENA_H_INCLUDED
#define CADENA_H_INCLUDED

#include <string.h>

using namespace std;

class Cadena
{
private:
    char* cadena;
    Cadena(int cantidad);
public:
    Cadena(const char* cadena);
    Cadena(const Cadena& otra);
    ~Cadena();
    Cadena& operator+=(const Cadena& otra);
    Cadena operator+(const char* otra)const;
    Cadena operator+(Cadena& otra)const;
    Cadena operator+(char c)const;
    Cadena& operator=(Cadena& otra);
    friend ostream& operator<<(ostream& sal, Cadena& Cadena);
};

#endif // CADENA_H_INCLUDED
