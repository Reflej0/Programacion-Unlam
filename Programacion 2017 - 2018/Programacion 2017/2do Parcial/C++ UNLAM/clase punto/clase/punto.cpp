#include "punto.h"
#include <iostream>
Punto::~Punto()
{
    //dtor
}

Punto::Punto(const Punto& p)
{
    x=p.x;
    y=p.y;
}

Punto::Punto(int a, int b)
{
    x=a;
    y=b;
}

void Punto::mostrar()
{
    cout<<"("<<x<<","<<y<<")"<<endl;
}

Punto& Punto::operator =(const Punto&p)
{
    x=p.x;
    y=p.y;
    return *this;
}

Punto& Punto::operator +=(const Punto&p)
{
    x+=p.x;
    y+=p.y;
    return *this;
}

Punto& Punto::operator -=(const Punto&p)
{
    x-=p.x;
    y-=p.y;
    return *this;
}

Punto Punto::operator +(const Punto&p)const
{
    return Punto(x+p.x,y+p.y);
}

Punto Punto::operator -(const Punto&p)const
{
    return Punto(x-p.x,y-p.y);
}

bool Punto::operator == (const Punto&p)const
{
    return x==p.x&&y==p.y?true:false;
}

bool Punto::operator>(const Punto&p)const
{
    return x>p.x&&y>p.y?true:false;
}

bool Punto::operator<(const Punto&p)const
{
    return x<p.x&&y<p.y?true:false;
}

bool Punto::operator>=(const Punto&p)const
{
    return x>=p.x&&y>=p.y?true:false;
}

bool Punto::operator<=(const Punto&p)const
{
    return x<=p.x&&y<=p.y?true:false;
}

Punto Punto::operator++(int) //posfijo
{
     Punto aux=(*this);
     x++;
     y++;
     return aux;
}

Punto& Punto::operator++() //prefijo
{
    x++;
    y++;
    return *this;
}

Punto Punto::operator+(const int&n)const
{
    return Punto(x+n,y+n);
}

/**friends**/

Punto operator+(const int&n,const Punto&p)
{
    return Punto(p.x+n,p.y+n);
}

ostream& operator<<(ostream&o,const Punto&p)
{
    return o<<"("<<p.x<<","<<p.y<<")";
}

istream& operator>>(istream&i, Punto&p)
{
    cout<<"Ingrese el valor de x: ";
    i>>p.x;
    cout<<"Ingrese el valor de y: ";
    i>>p.y;
    return i;
}
