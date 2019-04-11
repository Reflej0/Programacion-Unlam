#include <iostream>
#include "ejemplo.h"

///CONSTRUCTORES.

Entero::Entero(int num)
{
    if(num < 0)
    {
        this->signo = -1;
        this->numero = num*-1;
    }
    else
    {
        this->signo = 1;
        this->numero = num;
    }
}

Entero::Entero()
{
    this->signo = 1;
    this->numero = 1;
}

///ARITMETICOS SIMPLE, SUMA, RESTA, PRODUCTO, DIVISION ENTRE OBJ ENTEROS.

Entero Entero::operator+(Entero otro)
{
    int resp = (this->signo*this->numero)+(otro.signo*otro.numero);
    Entero retorno(resp);
    return retorno;
}

Entero Entero::operator-(Entero otro)
{
    int resp = (this->signo*this->numero)-(otro.signo*otro.numero);
    Entero retorno(resp);
    return retorno;
}

Entero Entero::operator*(Entero otro)
{
    int resp = (this->signo*this->numero)*(otro.signo*otro.numero);
    Entero retorno(resp);
    return retorno;
}

Entero Entero::operator/(Entero otro)
{
    int resp = (this->signo*this->numero)/(otro.signo*otro.numero);
    Entero retorno(resp);
    return retorno;
}

///+ o - ANTEPUESTO.

Entero& Entero::operator-()
{
    this->signo = this->signo * -1;
    return *this;
}

Entero& Entero::operator+()
{
    this->signo = this->signo * 1;
    return *this;
}

bool Entero::operator==(Entero otro)
{
    int _this = this->signo * this->numero;
    int _otro = otro.signo * otro.numero;
    if(_this == _otro)
    {
        return true;
    }
    else
    {
        return false;
    }
}

///PROBANDO []

Entero& Entero::operator[](int otro)
{
    this->numero+=otro;
    return *this;
}

///FRIENDS.

ostream& operator<<(ostream& sal, Entero otro)
{
    char c;
    if(otro.signo == -1)
    {
        c = '-';
    }
    else
    {
        c = '+';
    }
    sal << c << otro.numero;
    return sal;
}

istream& operator>>(istream& sal, Entero& otro)
{
    sal >> otro.numero;
    if(otro.numero < 0)
    {
        otro.numero*=-1;
        otro.signo = -1;
    }
    else
    {
        otro.signo = 1;
    }
    return sal;
}
