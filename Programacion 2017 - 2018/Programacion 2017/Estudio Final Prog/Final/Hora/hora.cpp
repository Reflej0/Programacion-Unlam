#include <iostream>
#include <stdlib.h>
#include "hora.h"

Hora::Hora(int horas, int minutos, int segundos)
{
    this->segundos = segundos;
    this->minutos = minutos;
    this->horas = horas;
}

Hora::Hora(int segundos)
{
    ///Si proviene de una resta.
    if(segundos < 0)
    {
        this->segundos = (segundos*-1) % 86400;
    }
    else
    {
        this->segundos = segundos;
    }
    this->horas = 0;
    this->minutos = 0;
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

Hora::Hora(const Hora& otra)
{
    this->segundos = otra.segundos;
    this->minutos = otra.minutos;
    this->horas = otra.horas;
}

Hora::Hora()
{
    this->segundos = 0;
    this->minutos = 0;
    this->horas = 0;
}

Hora& Hora::operator=(const Hora &otra)
{
    this->segundos = otra.segundos;
    this->minutos = otra.minutos;
    this->horas = otra.horas;
    return *this;
}

Hora& Hora::operator+=(const Hora &otra)
{
    this->segundos += otra.segundos;
    this->minutos += otra.minutos;
    this->horas += otra.horas;
    ///Para usar los whiles del constructor y no repetirlos.
    Hora retorno(this->horas, this->minutos, this->segundos);
    *this = retorno;
    return *this;
}

Hora& Hora::operator+=(int segundos)
{
    this->segundos += segundos;
    ///Para usar los whiles del constructor y no repetirlos.
    Hora retorno(this->horas, this->minutos, this->segundos);
    *this = retorno;
    return *this;
}

Hora Hora::operator-(Hora &otra)
{
    int segundosthis = this->HoraaSegundos();
    int segundosotra = otra.HoraaSegundos();
    Hora retorno(segundosthis-segundosotra);
    return retorno;
}

Hora Hora::operator*(int numero)
{
    int segundosthis = this->HoraaSegundos();
    int multi = segundosthis*numero;
    Hora retorno(multi);
    return retorno;
}

Hora operator*(int n,Hora& otra)
{
    int segundos = otra.HoraaSegundos();
    int multi = n * segundos;
    Hora retorno(multi);
    return retorno;
}

int Hora::HoraaSegundos()
{
    int segundos = this->segundos + (this->minutos*60) + (this->horas*3600);
    return segundos;
}

ostream& operator<<(ostream& sal, const Hora& otra)
{
    sal << otra.horas << ":" << otra.minutos << ":" << otra.segundos;
    return sal;
}
