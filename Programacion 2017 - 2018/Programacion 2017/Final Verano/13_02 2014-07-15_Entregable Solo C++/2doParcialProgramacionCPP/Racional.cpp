#include "C:\Users\Juanjo\Desktop\Final Verano\13_02 2014-07-15_Entregable\include\Racional.h"
#include <stdlib.h>

Racional:: Racional (int num, int den)
{
    int num_signo = 1;
    int den_signo = 1;
    if(num < 0)
    {
        num_signo = -1;
    }
    if(den < 0)
    {
        den_signo = -1;
    }
    int _mcd = MCD(abs(num), abs(den));
    this->num = (abs(num) / _mcd) * num_signo;
    this->den = (abs(den) / _mcd) * den_signo;
    return;
}

///Método estático, no necesito de un objeto racional para invocarlo.
int Racional::MCD(int a, int b)
{
    if(b==0)
    {
        return a;
    }
    return MCD(b, a%b);
}
///Método estático, no necesito de un objeto racional para invocarlo.
int Racional::MCM(int a, int b)
{
    if(a== 0 || b==0)
    {
        return 0;
    }
    return (a / MCD(a,b)* b);
}

Racional::Racional()
{
    this->num = 0;
    this->den = 1;
}

Racional Racional::operator+(Racional& otro)
{
    int nuevodenominador = MCM(this->den, otro.den);
    int nuevonumerador = (this->num*nuevodenominador/this->den)+(otro.num*nuevodenominador/otro.den);
    Racional retorno(nuevonumerador, nuevodenominador);
    return retorno;
}

ostream& operator<<(ostream& sal, Racional& r)
{
    char signo;
    if(r.num * r.den < 0)
    {
        signo = '-';
    }
    else
    {
        signo = '+';
    }
    sal << signo << abs(r.num) << '/' << abs(r.den);
    return sal;
}

Racional operator+(int otro, Racional &r)
{
    int nuevodenominador = r.getDenominador();
    int nuevonumerador = (otro*nuevodenominador) + r.getNumerador();
    Racional retorno(nuevonumerador, nuevodenominador);
    return retorno;
}

int Racional::getDenominador()
{
    return this->den;
}

int Racional::getNumerador()
{
    return this->num;
}
