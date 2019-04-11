#include <stdio.h>
#include <stdlib.h>
#include "fecha.h"

int es_bisiesto(T_fecha* f)
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

int cant_dias_ano(int ano)
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

int cant_dias_mes(T_fecha* f)
{
    int cantdias[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if(es_bisiesto(f) == 1)
    {
        cantdias[2]++;
    }
    return cantdias[f->mes];
}

int ValidarFecha(T_fecha* f)
{
    if(f->ano > 0)
    {
        if(f->mes >= 1 && f->mes <= 12)
        {
            if(f->dia >= 1 && f->dia <= cant_dias_mes(f))
            {
                return 1;
            }
        }
    }
    return 0;
}

int FechaaDias(T_fecha* f)
{
    T_fecha aux;
    aux.ano = 1900;
    aux.mes = 1;
    int dias = 0;
    while(aux.ano<f->ano)
    {
        dias+= cant_dias_ano(aux.ano);
        aux.ano++;
    }
    while(aux.mes<f->mes)
    {
        dias+=cant_dias_mes(&aux);
        aux.mes++;
    }
    dias+= f->dia;
    return dias; //COINCIDE CON EL FORMATO DE EXCEL.
}

T_fecha SumarDias(T_fecha* f, int dias)
{
    int fdias = FechaaDias(f);
    fdias+= dias;
    T_fecha f_resultado = DiasaFechas(fdias);
    return f_resultado;
}

T_fecha DiasaFechas(int fdias)
{
    T_fecha resu;
    resu.dia = 0;
    resu.mes = 1;
    resu.ano = 1900;
    int dias = fdias;
    while(dias > cant_dias_ano(resu.ano))
    {
        resu.ano++;
        dias-=cant_dias_ano(resu.ano);
    }
    while(dias > cant_dias_mes(&resu))
    {
        resu.mes++;
        dias-=cant_dias_mes(&resu);
    }
    resu.dia += dias;
    //PARCHE.
    if(resu.dia == 0)
    {
        resu.dia = 1;
    }
    return resu;
}

void NombreDia(T_fecha* f)
{
    int dias = FechaaDias(f);
    int residuo = dias % 7;
    switch(residuo)
    {
    case 0:
        printf("\nDOMINGO");
        break;
    case 1:
        printf("\nLUNES");
        break;
    case 2:
        printf("\nMARTES");
        break;
    case 3:
        printf("\nMIERCOLES");
        break;
    case 4:
        printf("\nJUEVES");
        break;
    case 5:
        printf("\nVIERNES");
        break;
    case 6:
        printf("\nSABADO");
        break;
    }
}

