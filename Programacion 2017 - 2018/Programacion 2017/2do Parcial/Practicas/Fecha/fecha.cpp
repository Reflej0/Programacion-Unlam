#include "fecha.h"

bool Fecha::esFechaValida(int d,int m,int a){

    int dias_mes[12]={31,28,31,30,31,30,31,31,30,31,30,31};

    if(a%400 == 0 || (a%4 == 0 && a%100 !=0)){ //bisiesto

        dias_mes[1]=29;
    }

    if(d<1 || d > dias_mes[m-1]){
        return false;
    }

    if(m<1 || m > 12){
        return false;
    }

    if(a<1600){
        return false;
    }

    return true;
}

Fecha::Fecha()
{
    this->diarel = 1;
}

Fecha::Fecha(int d, int m, int a)
{
    if(!esFechaValida(d,m,a))
    {
        throw false;
    }
    long difanos = a-1601;
    diarel = (difanos*365) + (difanos/4) - (difanos/100) + (difanos/400) + diaJuliano(d,m,a);
}

int Fecha::diaJuliano(int d, int m, int a)const
{
    int dias_mes[12]={31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int dias = 0;
    int i;
    if((a%400 == 0) || (a%4 == 0 && a%100!=0))
    {
        dias_mes[1] = 29;
    }
    dias+=d;
    for(i=0;i<m-1;i++)
    {
        dias+=dias_mes[i];
    }
    return dias;
}

void Fecha::operator+=(int dias)
{
    this->diarel = (this->diarel) + dias;
}

void Fecha::operator-=(int dias)
{
    this->diarel = (this->diarel) - dias;
}

void Fecha::operator-=(const Fecha &otra)
{
    this->diarel = (this->diarel) - otra.diarel;
}

Fecha Fecha::operator+(int dias)const
{
    ///YO.
    Fecha fecha = *this;
    fecha.diarel = (fecha.diarel) + dias;
    return fecha;
}

void Fecha::getDMA(int &d, int&m, int&a)const
{
    int difanos = (diarel/365);
    long diarelcalc = (difanos*365)+(difanos/4)-(difanos/100)+(difanos/400);
    while(diarelcalc >= diarel)
    {
        difanos--;
        diarelcalc = (difanos*365)+(difanos/4)-(difanos/100)+(difanos/400);
    }
    a = difanos + 1601;
    julianoaGregoriano(diarel - diarelcalc, a, d, m);
}

void Fecha::julianoaGregoriano(int diajul,int a,int&d,int&m){

    int dias_mes[12]={31,28,31,30,31,30,31,31,30,31,30,31};
    int i=0;
    m=0;
    d=0;

    if(a%400 == 0 || (a%4 == 0 && a%100 !=0)){ //bisiesto

        dias_mes[1]=29;
    }

    while(diajul > dias_mes[i]){
        m++;

        diajul-=dias_mes[i];

        i++;
    }

    m= m+1;

    d = diajul;
}

istream &operator>>(istream&ent, Fecha&f)
{
    int d, m, a;
    char c;
    ent>>d>>c>>m>>c>>a;
    f = Fecha(d, m, a);
    return ent;
}

ostream&operator<<(ostream&sal, const Fecha &f)
{
    int d, m, a;
    f.getDMA(d, m, a);
    sal << d << '/' << m << '/' << a;
    return sal;
}
