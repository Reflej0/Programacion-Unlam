#include "racionales.h"

Racional::Racional(int x,int y)
{
    numerador=x;
    denominador=y;
    simplificar();
}
void Racional::mostrar()const
{
    cout<<(numerador)<<"/"<<(denominador)<<endl;
}

int Racional::encontrar_mcd()
{
    int u=numerador,
        v=denominador,
        r;
     while(v!=0)
     {
          r=u%v;
          u=v;
          v=r;
     }
     return u;
}
void Racional::simplificar()
{
int mcd=encontrar_mcd();
    numerador/=mcd;
    denominador/=mcd;
}
Racional Racional::operator*(const Racional& x)const
{
    Racional aux(numerador*x.numerador,denominador*x.denominador);
    aux.simplificar();
    return aux;
}
Racional Racional::operator+(const Racional& x)const
{
    Racional aux(numerador*x.denominador+x.numerador*denominador,denominador*x.denominador);
    aux.simplificar();
    return aux;
}
Racional Racional::operator/(const Racional& x)const
{
    Racional aux(numerador*x.denominador,denominador*x.numerador);
    aux.simplificar();
    return aux;
}
