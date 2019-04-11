#include <iostream>
#include <istream>
#include "fecha.h"
#include <stdlib.h>

Fecha::Fecha(int dia, int mes, int ano)
{
    if(validarFecha(dia, mes, ano) == true)
    {
        this->dia = dia;
        this->mes = mes;
        this->ano = ano;
        return;
    }
    else
    {
        cout << "Fecha invalida";
        system("PAUSE");
        throw 1;
    }

}

Fecha::Fecha()
{
    this->dia = 1;
    this->mes = 1;
    this->ano = 1900;
}

ostream& operator<<(ostream& sal,const Fecha& otra)
{
    sal << otra.dia << '/' << otra.mes << '/' << otra.ano;
    return sal;
}

istream& operator>>(istream& ent, Fecha& otra)
{
    int dia, mes, ano;
    char c;
    ent >> dia >> c >> mes >> c >> ano;
    Fecha retorno(dia, mes, ano);
    otra = retorno;
    return ent;
}

Fecha Fecha::operator+(int dias)const
{
    int thisdias = this->FechaaDias();
    thisdias+=dias;
    return DiasaFecha(thisdias);
}

int Fecha::FechaaDias()const
{
    int mes = 1;
    int ano = 1900;
    int dias = 1;
    while(ano < this->ano)
    {
        dias+=cantDiasAno(ano);
        ano++;
    }
    while(mes < this->mes)
    {
        dias+=cantDiasMes(mes, ano);
        mes++;
    }
    dias+=this->dia;
    return dias;
}

///ESTATICAS.

bool Fecha::esBisiesto(int ano)
{
    if(ano % 4 == 0 && ano % 100 != 0)
    {
        return true;
    }
    if(ano % 400 == 0)
    {
        return true;
    }
    return false;
}

Fecha Fecha::DiasaFecha(int dias)
{
    int ano = 1900;
    int mes = 1;
    while(dias > cantDiasAno(ano))
    {
        dias-=cantDiasAno(ano);
        ano++;
    }
    while(dias > cantDiasMes(mes, ano))
    {
        dias-=cantDiasMes(mes, ano);
        mes++;
    }
    dias--;
    Fecha retorno(dias, mes, ano);
    return retorno;
}

bool Fecha::validarFecha(int dia, int mes, int ano)
{
    if(ano > 0)
    {
        if(mes >= 1 && mes <=12)
        {
            if(dia >= 1 && dia <= cantDiasMes(mes, ano))
            {
                return true;
            }
        }
    }
    return false;
}

int Fecha::cantDiasMes(int mes, int ano)
{
    int cantdias[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if(esBisiesto(ano))
    {
        cantdias[2]++;
    }
    return cantdias[mes];
}

int Fecha::cantDiasAno(int ano)
{
    if(ano % 4 == 0 && ano % 100 != 0)
    {
        return 366;
    }
    if(ano % 400 == 0)
    {
        return 366;
    }
    return 365;
}
