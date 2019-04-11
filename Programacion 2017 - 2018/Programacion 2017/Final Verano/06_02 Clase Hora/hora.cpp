#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include "Hora.h"

Hora::Hora()
{
    this->segundos = 0;
    this->minutos = 0;
    this->horas = 0;
}

Hora::Hora(int segundos)
{
    this->horas = segundos/3600;
    if(this->horas > 0)
    {
        segundos-=(this->horas)*3600;
    }
    this->minutos = segundos/60;
    if(this->minutos > 0)
    {
        segundos-=(this->minutos)*60;
    }
    this->segundos = segundos;
    this->horas = this->horas % 24;
}

ostream& operator<<(ostream& sal, Hora otro)
{
    sal << otro.horas << ':' << otro.minutos << ':' << otro.segundos;
    return sal;
}

Hora Hora::operator+(Hora otro)
{
    int _thissegundos = (this->horas*3600)+(this->minutos*60)+this->segundos;
    int _otrosegundos = (otro.horas*3600)+(otro.minutos*60)+otro.segundos;
    Hora retorno(_thissegundos + _otrosegundos);
    return retorno;
}

Hora& Hora::operator++()
{
    int _thissegundos = (this->horas*3600)+(this->minutos*60)+this->segundos;
    _thissegundos++;
    Hora aux(_thissegundos);
    *this = aux;
    return *this;
}
