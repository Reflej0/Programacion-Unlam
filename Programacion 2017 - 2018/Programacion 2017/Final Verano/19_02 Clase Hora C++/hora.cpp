#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include "hora.h"

Hora::Hora()
{
    this->segundos = 0;
    this->minutos = 0;
    this->horas = 0;
}

Hora::Hora(int segundos)
{
    this->horas = (int)segundos/3600;
    segundos -= (this->horas*3600);
    this->minutos = (int)segundos/60;
    segundos -= (this->minutos*60);
    this->segundos = segundos;
    this->horas = (this->horas % 24);
}

Hora Hora::operator+(Hora& otra)
{
    int thissegundos = (this->horas*3600)+(this->minutos*60)+(this->segundos);
    int otrasegundos = (otra.horas*3600)+(otra.minutos*60)+(otra.segundos);
    Hora retorno((thissegundos+otrasegundos));
    return retorno;
}

Hora& Hora::operator++()
{
    int thissegundos = (this->horas*3600)+(this->minutos*60)+(this->segundos);
    Hora aux((thissegundos+1));
    *this = aux;
    return *this;
}

ostream& operator<<(ostream& sal, Hora& h)
{
    sal << h.horas << ':' << h.minutos << ':' << h.segundos;
    return sal;
}
