#include "Racional.h"




Racional::Racional(int n,int d)
{
    numerador=n;
    denominador=d;
    simplificar();
}
void Racional:: simplificar()
{
    int mcd=encontrarMCD();
    numerador/=mcd;
    denominador/=mcd;
}
int Racional::encontrarMCD()
{
    int n=numerador,d=denominador,r;
    while(d!=0)
    {
        r=n%d;
        n=d;
        d=r;
    }
    return n;
}
Racional& Racional:: operator=(const int n)
{
    numerador=n;
    denominador=1;
    return *this;
}

Racional Racional:: operator+(const Racional & r)const
{
    return Racional(numerador*r.denominador+denominador*r.numerador,denominador*r.denominador);
}
bool Racional ::operator>(const Racional&r)const
{
    return (((float)numerador/denominador)>((float)r.numerador/r.denominador));
}
Racional operator+ (const int n,const Racional &r)
{
    return Racional(n*r.denominador+r.numerador,r.denominador);
}
ostream& operator<<(ostream& o,const Racional&r)
{
    if(r.denominador==1)
        o<<r.numerador;
    else
        o<<r.numerador<<"/"<<r.denominador;
    return o;
}

istream& operator>>(istream &i,Racional&r)
{
    char barra='/';
    i>>r.numerador>>barra>>r.denominador;
    return i;
}
float Racional:: real()const
{
    return ((float)numerador/denominador);
}
