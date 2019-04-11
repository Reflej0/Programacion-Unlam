#include <stdio.h>
#include <stdlib.h>
#include "fecha.h"

int ValidarFecha(T_fecha* f)
{
    ///Tomo como referencia al año 1900.
    if(f->ano >= 1900)
    {
        ///El mes tiene que estar entre 1 y 12.
        if(f->mes >= 1 && f->mes <= 12)
        {
            ///Obtengo la cantidad de dias del mes.
            int cantdiasmes = CantidadDiasMes(f);
            if(f->dia >= 1 && f->dia <= cantdiasmes)
            {
                return 1;
            }
        }
    }
    return 0;
}

int CantidadDiasMes(const T_fecha* f)
{
    ///Por comodidad, ya que la posicion 0 no representa un mes.
    int dias_meses[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if(EsBisiesto(f))
    {
        dias_meses[2]++;
    }
    return dias_meses[f->mes];
}

int EsBisiesto(const T_fecha* f)
{
    if(f->ano % 4 == 0 && f->ano % 100 != 0)
    {
        return 1;
    }
    if(f->ano % 400 == 0)
    {
        return 1;
    }
    return 0;
}

int CantidadDiasAno(const T_fecha* f)
{
    if(f->ano % 4 == 0 && f->ano % 100 != 0)
    {
        return 366;
    }
    if(f->ano % 400 == 0)
    {
        return 366;
    }
    return 365;
}

T_fecha SumarDias(const T_fecha* f, int dias)
{
    int diasfechaorigen = FechaaDias(f);
    diasfechaorigen+= dias;
    T_fecha fechafinal;
    DiasaFecha(&fechafinal, diasfechaorigen);
    return fechafinal;
}

T_fecha RestarDias(const T_fecha* f, int dias)
{
    int diasfechaorigen = FechaaDias(f);
    diasfechaorigen -=dias;
    T_fecha fechafinal;
    DiasaFecha(&fechafinal, diasfechaorigen);
    return fechafinal;
}

int FechaaDias(const T_fecha* f)
{
    ///Establezco una fecha desde la cual parto.
    T_fecha inicial;
    inicial.dia = 1;
    inicial.mes = 1;
    inicial.ano = 1900;
    ///-------------------------------------------
    int dias = 0; // Esta variable tiene el resultado de la fecha pasada a dias.
    ///Mientras que no llegue al año de la fecha buscada, voy sumando dias.
    while(inicial.ano < f->ano)
    {
        if(EsBisiesto(&inicial) == 1)
        {
            dias+=366;
        }
        else
        {
            dias+=365;
        }
        inicial.ano++;
    }
    ///Mientras que no llegue al mes de la fecha buscada, voy sumando dias.
    while(inicial.mes < f->mes)
    {
        dias+=CantidadDiasMes(&inicial);
        inicial.mes++;
    }
    dias+= f->dia;
    return dias;
}

void DiasaFecha(T_fecha* f, int dias)
{
    ///Establezco una fecha desde la cual parto.
    T_fecha inicial;
    inicial.dia = 0;
    inicial.mes = 1;
    inicial.ano = 1900;
    while(dias > CantidadDiasAno(&inicial))
    {
        inicial.ano++;
        dias-=CantidadDiasAno(&inicial);
    }
    while(dias > CantidadDiasMes(&inicial))
    {
        inicial.mes++;
        dias-=CantidadDiasMes(&inicial);
    }
    inicial.dia+=dias;
    *f = inicial;
}

void NombreDia(const T_fecha* f)
{
    ///1/1/1900 LUNES
    int dias = FechaaDias(f);
    dias--;
    int resto = dias % 7;
    switch(resto)
    {
    case 0:
        printf("\nLUNES");
        break;
    case 1:
        printf("\nMARTES");
        break;
    case 2:
        printf("\nMIERCOLES");
        break;
    case 3:
        printf("\nJUEVES");
        break;
    case 4:
        printf("\nVIERNES");
        break;
    case 5:
        printf("\nSABADO");
        break;
    case 6:
        printf("\nDOMINGO");
        break;
    }
}
