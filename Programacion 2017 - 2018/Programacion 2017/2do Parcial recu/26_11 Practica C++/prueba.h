#ifndef PRUEBA_H_INCLUDED
#define PRUEBA_H_INCLUDED
#include <iostream>

class Prueba
{
private:
    int numero;
public:
    Prueba(int numero);
    friend int operator+(int numero, const Prueba& prueba);
    int operator+(int numero)const;
    int getNumero()const;
};

#endif // PRUEBA_H_INCLUDED
