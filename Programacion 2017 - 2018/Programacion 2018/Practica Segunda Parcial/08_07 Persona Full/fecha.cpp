#include <iostream>
#include "fecha.h"

bool Fecha::esBisiesto(int a)
{
    return ((a % 4 == 0 && a % 100 != 0) || a % 400 == 0) ? true : false;
}

int Fecha::cantDiasMes(int m, int a)
{
    int v[12]={31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if(esBisiesto(a))
        v[1]++;
    return v[m+1];
}

bool Fecha::validarFecha(int d, int m, int a)
{
    if(a>0)
        if(m>=1 && m<=12)
            if(d>=1&&d<=cantDiasMes(m, a))
                return true;
    return false;
}

Fecha::Fecha(int d, int m, int a)
{
    //if(!validarFecha(d, m, a))
        //cout << "Fecha invalida";
    this->d = d;
    this->m = m;
    this->a = a;
}

ostream& operator<<(ostream&sal, const Fecha&f)
{
    sal<<f.d<<'/'<<f.m<<'/'<<f.a;
    return sal;
}

istream& operator>>(istream&ent, Fecha&f)
{
    char c;
    ent>>f.d>>c>>f.m>>c>> f.a;
    return ent;
}

int Fecha::getDia()const
{
    return this->d;
}

int Fecha::getMes()const
{
    return this->m;
}

int Fecha::getAnio()const
{
    return this->a;
}
