#include <iostream>
#include "Hora.h"
#include <stdlib.h>
#include <stdio.h>

using namespace std;

Hora::Hora()
{
    this->segundos = 0;
    this->minutos = 0;
    this->horas = 0;
}

Hora::Hora(int segundos)
{
    this->horas = 0;
    this->minutos = 0;
    this->segundos = segundos;
    while(this->segundos>59)
    {
        this->minutos+=1;
        this->segundos-=60;
    }
    while(this->minutos>59)
    {
        this->horas+=1;
        this->minutos-=60;
    }
    if(this->horas>=24)
    {
        this->horas = horas % 24;
    }
}

Hora& Hora::operator=(const Hora &otra)
{
    this->segundos = otra.segundos;
    this->minutos = otra.minutos;
    this->horas = otra.horas;
    return *this;
}

Hora Hora::operator+(const Hora &otra)
{
    Hora hora;
    hora = *this;
    hora.segundos = otra.segundos;
    hora.minutos = otra.minutos;
    hora.horas = otra.horas;
    while(hora.segundos>59)
    {
        hora.minutos++;
        hora.segundos-=60;
    }
    while(hora.minutos>59)
    {
        hora.horas++;
        hora.minutos-=60;
    }
    if(hora.horas>=24)
    {
        hora.horas = hora.horas % 24;
    }
    hora.segundos--; //PARCHE.
    return hora;
}

Hora& Hora::operator++()
{
    this->segundos++;
    while(segundos>59)
    {
        this->minutos++;
        segundos-=60;
    }
    while(this->minutos>59)
    {
        this->horas++;
        this->minutos-=60;
    }
    if(this->horas>=24)
    {
        this->horas = horas % 24;
    }
    return *this;
}

ostream& operator<<(ostream&sal, Hora &h)
{
    sal << h.horas << ":" << h.minutos << ":" << h.segundos;
    return sal;
}
