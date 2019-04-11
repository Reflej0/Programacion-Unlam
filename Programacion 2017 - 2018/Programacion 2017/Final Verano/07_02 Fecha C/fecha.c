#include <stdio.h>
#include <stdlib.h>
#include "fecha.h"

int Es_Bisiesto(int ano)
{
    if(ano % 4 == 0 && ano % 100 != 0)
    {
        return 1;
    }
    else
    {
        if(ano % 400 == 0)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
}

int Cant_Dias_Mes(int ano, int mes)
{
    int cant_dias[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if(Es_Bisiesto(ano) == 1)
    {
        cant_dias[2]++;
    }
    return cant_dias[mes];
}

int Cant_Dias_Ano(int ano)
{
    if(ano % 4 == 0 && ano % 100 != 0)
    {
        return 366;
    }
    else
    {
        if(ano % 400 == 0)
        {
            return 366;
        }
        else
        {
            return 365;
        }
    }
}

int ValidarFecha(T_fecha* f)
{
    if(f->ano > 0)
    {
        if(f->mes >= 1 && f->mes <= 12)
        {
            if(f->dia >= 1 && f->dia <= Cant_Dias_Mes(f->ano, f->mes))
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
    while(ano<f->ano)
    {
        dias+=Cant_Dias_Ano(ano);
        ano++;
    }
    while(mes<f->mes)
    {
        dias+=Cant_Dias_Mes(ano, mes);
        mes++;
    }
    dias+=f->dia;
    return dias;
}

T_fecha DiasaFecha(int dias)
{
    int c_dias = dias;
    int mes = 1;
    int ano = 1900;
    while(c_dias>Cant_Dias_Ano(ano))
    {
        c_dias-=Cant_Dias_Ano(ano);
        ano++;
    }
    while(c_dias>Cant_Dias_Mes(ano, mes))
    {
        c_dias-=Cant_Dias_Mes(ano, mes);
        mes++;
    }
    printf("C_DIAS:%d", c_dias);
    system("PAUSE");
    T_fecha retorno;
    retorno.dia = c_dias;
    if(retorno.dia == 0)
    {
        retorno.dia = 1;
    }
    retorno.mes = mes;
    retorno.ano = ano;
    return retorno;
}

T_fecha SumarDias(T_fecha* f, int dias)
{
    int fdias = FechaaDias(f);
    fdias+= dias;
    T_fecha f_resultado = DiasaFecha(fdias);
    return f_resultado;
}

void NombreDia(T_fecha* f)
{
    int dias = FechaaDias(f);
    int residuo = dias % 7;
    switch(residuo)
    {
    case 0:
        printf("LUNES");
        break;
    case 1:
        printf("MARTES");
        break;
    case 2:
        printf("MIERCOLES");
        break;
    case 3:
        printf("JUEVES");
        break;
    case 4:
        printf("VIERNES");
        break;
    case 5:
        printf("SABADO");
        break;
    case 6:
        printf("DOMINGO");
        break;
    }
}
