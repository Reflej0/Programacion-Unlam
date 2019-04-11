#include <stdio.h>
#include <stdlib.h>
#include "fecha.h"

int esBisiesto(int ano)
{
    if(ano % 4 == 0 && ano % 100 != 0)
    {
        return 1;
    }
    if(ano % 400 == 0)
    {
        return 1;
    }
    return 0;
}

int CantDiasMes(int mes, int ano)
{
    int vecdias[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if(esBisiesto(ano))
    {
        vecdias[1]++;
    }
    return vecdias[mes-1];
}

int CantDiasAno(int ano)
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

int ValidarFecha(T_fecha* f)
{
    if(f->ano > 0)
    {
        if(f->mes >= 1 && f->mes <=12)
        {
            if(f->dia>=1 && f->dia <= CantDiasMes(f->mes, f->ano))
            {
                return 1;
            }
        }
    }
    return 0;
}

int FechaaDias(T_fecha* f)
{
    int dias = 0;
    int mes = 1;
    int ano = 1900;
    while(ano < f->ano)
    {
        dias+=CantDiasAno(ano);
        ano++;
    }
    while(mes < f->mes)
    {
        dias+=CantDiasMes(mes, ano);
        mes++;
    }
    dias+= f->dia;
    return dias;
}

T_fecha DiasaFechas(int dias)
{
    int dia = 0;
    int mes = 1;
    int ano = 1900;
    while(dias>=CantDiasAno(ano))
    {
        ano++;
        dias-=CantDiasAno(ano);
    }
    while(dias>=CantDiasMes(mes, ano))
    {
        dias-=CantDiasMes(mes, ano);
        mes++;
    }
    dia+=dias;
    T_fecha r;
    r.dia = dia;
    r.mes = mes;
    r.ano = ano;
    return r;
}

T_fecha SumarDias(T_fecha* f, int dias)
{
    int f_dias = FechaaDias(f);
    f_dias+=dias;
    return DiasaFechas(f_dias);
}

void NombreDia(T_fecha* f)
{
    switch(FechaaDias(f)%7)
    {
    case 0:
        printf("DOMINGO");
        break;
    case 1:
        printf("LUNES");
        break;
    case 2:
        printf("MARTES");
        break;
    case 3:
        printf("MIERCOLES");
        break;
    case 4:
        printf("JUEVES");
        break;
    case 5:
        printf("VIERNES");
        break;
    case 6:
        printf("SABADO");
        break;
    }
}
