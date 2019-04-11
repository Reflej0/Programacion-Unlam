#include "complejo.h"

Complejo::Complejo()
{
    //ctor
}

Complejo::~Complejo()
{
    //dtor
}

Complejo::Complejo(float x,float y)
{
    real=x;
    comp=y;
}

void calcular(int nUno,int nDos,float fTre,float fCua,int nCin)
{
    Complejo c0,
    c2(nUno,nDos),
    c3(fTre,fCua);

cout<<"valores iniciales"<<endl
    <<"c0="<<c0<<endl<<"c1="<<c1<<endl;

    c0=nCin*c3;
    c1=c2*c3;

    cout<<"valores finales"<<endl
    <<"c0="<<c0<<endl<<"c1="<<c1<<endl;
}


Complejo operator=(const float x)const
{
    return Complejo(x*comp
}

Complejo operator*(const float x)const
{
    return Complejo(x*real,x+comp);
}
