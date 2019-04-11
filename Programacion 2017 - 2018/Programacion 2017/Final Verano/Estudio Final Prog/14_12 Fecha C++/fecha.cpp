#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include "fecha.h"

Fecha::Fecha()
{
    this->dia = 1;
    this->mes = 1;
    this->ano = 1900;
}

Fecha::Fecha(int dia, int mes, int ano)
{
    if(ValidarFecha(dia, mes, ano) == true)
    {
        this->dia = dia;
        this->mes = mes;
        this->ano = ano;
        return;
    }
    else
    {
        cout << "Fecha invalida";
    }
}

bool Fecha::ValidarFecha(int dia, int mes, int ano)
{
    int cantdias[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if(EsBisiesto(ano) == true)
    {
        cantdias[2]++;
    }
    if(ano > 0)
    {
        if(mes >= 1 && mes <= 12)
        {
            if(dia >= 1 && dia <= cantdias[mes])
            {
                return true;
            }
        }
    }
    return false;
}

bool Fecha::EsBisiesto(int ano)
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

Fecha& Fecha::operator=(const Fecha& otra)
{
    this->dia = otra.dia;
    this->mes = otra.mes;
    this->ano = otra.ano;
    return *this;
}

Fecha Fecha::operator+(int dias)const
{
    int thisdias = FechaaDias();
    thisdias+=dias;
    Fecha retorno = DiasaFechas(thisdias);
    return retorno;
}

int Fecha::FechaaDias()const
{
    int ano = 1900;
    int mes = 1;
    int diastotales = 0;
    int cantdias[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if(EsBisiesto(this->ano) == true)
    {
        cantdias[2]++;
    }
    while(ano < this->ano)
    {
        if(EsBisiesto(ano) == true)
        {
            diastotales+=366;
        }
        else
        {
            diastotales+=365;
        }
        ano++;
    }
    while(mes < this->mes)
    {
        diastotales+= cantdias[mes];
        mes++;
    }
    diastotales+= this->dia-1;
    return diastotales;
}

Fecha Fecha::DiasaFechas(int dias)
{
    int cantdias[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int ano = 1900;
    int mes = 1;
    int dia = 1;
    while(dias >= cantdiasano(ano))
    {
        ano++;
        dias-=cantdiasano(ano);
    }
    if(EsBisiesto(ano) == true)
    {
        cantdias[2]++;
    }
    while(dias >= cantdias[mes])
    {
        mes++;
        dias-= cantdias[mes];
    }
    dia+=dias;
    Fecha retorno(dia, mes, ano);
    return retorno;
}

int Fecha::cantdiasano(int ano)
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

ostream& operator<<(ostream& sal, const Fecha& otra)
{
    sal << otra.dia << '/' << otra.mes << '/' << otra.ano;
    return sal;
}

istream& operator>>(istream& ent, Fecha &otra)
{
    char c;
    int dia, mes, ano;
    ent >> dia >> c >> mes >> c >> ano;
    Fecha retorno(dia, mes, ano);
    otra = retorno;
    return ent;
}
