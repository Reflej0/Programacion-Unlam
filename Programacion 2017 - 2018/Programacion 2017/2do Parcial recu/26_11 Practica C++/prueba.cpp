#include <iostream>
#include "prueba.h"

Prueba::Prueba(int numero)
{
    this->numero = numero;
    return;
}

int operator+(int numero, const Prueba& prueba)
{
    int resultado;
    resultado = numero+prueba.getNumero();
    return resultado;
}

int Prueba::operator+(int numero)const
{
    int resultado;
    resultado = this->numero + numero;
    return resultado;
}

int Prueba::getNumero()const
{
    return this->numero;
}
