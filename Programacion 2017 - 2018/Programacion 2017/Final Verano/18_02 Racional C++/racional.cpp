#include <iostream>
#include <stdlib.h>
#include "racional.h"
using namespace std;

int Racional::MCD(unsigned int a, unsigned int b)
{
    if(b == 0)
    {
        return a;
    }
    return MCD(b, a%b);
}

int Racional::MCM(unsigned int a, unsigned int b)
{
    if(a == 0 || b == 0)
    {
        return 0;
    }
    return (a / MCD(a,b)*b);
}

Racional::Racional(int num, int den)
{
    if((num*den)<0)
    {
        this->signo = -1;
    }
    else
    {
        this->signo = 1;
    }
    int mcd = MCD(abs(num), abs(den));
    this->num = abs(num) / mcd;
    this->den = abs(den) / mcd;
}

Racional::Racional()
{
    this->signo = 0;
    this->num = 0;
    this->den = 1;
}

Racional Racional::operator+(Racional& otro)
{
    int mcm = MCM(this->den, otro.den);
    int nuevonum = (this->num*mcm/this->den*this->signo) + (otro.num*mcm/otro.den*otro.signo);
    int nuevoden = mcm;
    Racional r(nuevonum, nuevoden);
    return r;
}

ostream& operator<<(ostream& sal, Racional& otro)
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
    sal << c << otro.num << '/' << otro.den;
    return sal;
}


Racional operator+(int e, Racional& r)
{
    int nuevonum = (r.num*r.signo) + (e*r.den);
    int nuevoden = r.den;
    Racional re(nuevonum, nuevoden);
    return re;
}
