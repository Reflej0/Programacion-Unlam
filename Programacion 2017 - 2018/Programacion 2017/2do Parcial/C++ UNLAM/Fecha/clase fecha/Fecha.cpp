#include "Fecha.h"
int esFechaValida(int,int,int);
int esBisiesto(int);

int esBisiesto(int a)
{
    return ((a%4==0 && a%100!=0) || (a%400==0));
}

int esFechaValida(int d, int m, int a)
{
    int vec[12]={31,28,31,30,31,30,31,31,30,31,30,31};
    vec[1]+= esBisiesto(a);
    if( (m>0&&m<13) && (d>0&&d<=vec[m-1]) && (a>1600&&a<9999))
        return 1;
    return 0;
}

Fecha::~Fecha()
{
    //dtor
}

Fecha::Fecha(int d, int m, int a)
{
    Dia=d;
    Mes=m;
    Anio=a;
}

Fecha::Fecha(const Fecha& obj)
{
   Dia = obj.Dia;
   Mes = obj.Mes;
   Anio = obj.Anio;
}

Fecha& Fecha::operator=(const Fecha& fec)
{
    Dia=fec.Dia;
    Mes=fec.Mes;
    Anio=fec.Anio;
    return *this;
}

ostream& operator<<(ostream& salida, Fecha& fec)
{
    salida<<fec.Dia<<"/"<<fec.Mes<<"/"<<fec.Anio<<endl;
    return salida;
}

istream& operator>>(istream& entrada, Fecha& fec)
{
    do
    {
        cout<<"\nIngrese el dia: ";
        cin>>fec.Dia;
        cout<<"\nIngrese el mes: ";
        cin>>fec.Mes;
        cout<<"\nIngrese el anio: ";
        cin>>fec.Anio;
    }
    while(!(esFechaValida(fec.Dia,fec.Mes,fec.Anio)));
    return entrada;
}
