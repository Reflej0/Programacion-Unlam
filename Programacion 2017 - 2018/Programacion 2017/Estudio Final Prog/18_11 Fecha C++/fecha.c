#include <iostream>
#include <istream>
#include "fecha.h"

Fecha::Fecha(int dia, int mes, int ano)
{
    this->dia = dia;
    this->mes = mes;
    this->ano = ano;
}

Fecha::Fecha()
{
    this->dia = 1;
    this->mes = 1;
    this->ano = 1900;
}
