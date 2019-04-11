#include <stdio.h>
#include <stdlib.h>
#include "fechas.h"

int es_bisiesto(int anio)
{
    if((anio % 4 == 0 && anio % 100 != 0) || (anio % 400 == 0))
        return 1;
    return 0;
}

int cant_dias_anio(int anio)
{
    if((anio % 4 == 0 && anio % 100 != 0) || (anio % 400 == 0))
        return 366;
    return 365;
}

int cant_dias_mes(int mes, int anio)
{
    int dias[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if(es_bisiesto(anio))
        dias[1]++;
    //EJ: ultimo elemento del vector en la posicion 11, ultimo mes 12.
    return dias[--mes];
}

///Excel considera el 29/02/1900 valido, por ende esta funcion.
///http://javiermozo-excel-explicado.blogspot.com.ar/2011/11/el-error-del-29-de-febrero-de-1900.html
int cant_dias_mes_excel(int mes, int anio)
{
    int dias[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if(es_bisiesto(anio))
        dias[1]++;
    if(anio == 1900 && mes == 2)
        dias[1]++;
    //EJ: ultimo elemento del vector en la posicion 11, ultimo mes 12.
    return dias[--mes];
}

///Excel considera el 29/02/1900 valido, por ende esta funcion.
///http://javiermozo-excel-explicado.blogspot.com.ar/2011/11/el-error-del-29-de-febrero-de-1900.html
int cant_dias_anio_excel(int anio)
{
    if((anio % 4 == 0 && anio % 100 != 0) || (anio % 400 == 0))
        return 366;
    if(anio == 1900)
        return 366;
    return 365;
}

///Podria pasar T_fecha, pero prefiero que todas las estructuras T_fecha esten validadas anteriormente.
///Es decir que no haya T_fecha no validas.
int fecha_valida(int dia, int mes, int anio)
{
    //La condicion minima es que el anio sea mayor a 0.
    if(anio>0)
        if(mes>=1 && mes <=12)
            if(dia>= 1 && dia <=cant_dias_mes(mes, anio))
                return 1;
    return 0;
}

///Utiliza la funcion cant_dias_anio_excel.
int fecha_a_dias(T_fecha *f)
{
    int dias = 0; // Variable que tiene la cantidad total de dias que representa la fecha.
    int mes = 1; // Mes de partida.
    int anio = 1900; // Anio de partida.
    ///Mismo procedimiento que en Excel. Fecha 01/01/1900 = dia 1.
    while(anio < f->anio)
    {
        dias+=cant_dias_anio_excel(anio);
        anio++;
    }
    while(mes < f->mes)
    {
        dias+=cant_dias_mes_excel(mes, anio);
        mes++;
    }
    dias+= f->dia;
    return dias;
}

///Utiliza la funcion cant_dias_anio_excel.
T_fecha dias_a_fechas(int dias)
{
    int dia = 0;
    int mes = 1;
    int anio = 1900;
    while(dias>cant_dias_anio_excel(anio))
    {
        dias-=cant_dias_anio_excel(anio);
        anio++;
    }
    while(dias>cant_dias_mes_excel(mes, anio))
    {
        dias-=cant_dias_mes_excel(mes, anio);
        mes++;
    }
    dia+=dias;
    T_fecha f;
    f.dia = dia;
    f.mes = mes;
    f.anio = anio;
    return f;
}

T_fecha sumar_dias_fecha(T_fecha *f, int dias)
{
    int f_dias = fecha_a_dias(f);
    f_dias+=dias;
    return dias_a_fechas(f_dias);
}

void Nombre_Dia(T_fecha *f)
{
    int dias = fecha_a_dias(f);
    switch(dias%7)
    {
    case 0:
        printf("SABADO");
        break;
    case 1:
        printf("DOMINGO");
        break;
    case 2:
        printf("LUNES");
        break;
    case 3:
        printf("MARTES");
        break;
    case 4:
        printf("MIERCOLES");
        break;
    case 5:
        printf("JUEVES");
        break;
    case 6:
        printf("VIERNES");
        break;
    }
}
