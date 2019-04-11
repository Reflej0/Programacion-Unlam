#include <stdio.h>
#include <stdlib.h>
#include "resta_fechas.h"

//Esta función me permite corroborar si un año es bisiesto o no.
int es_Bisiesto(int a)
{
    if(a % 400 == 0 || (a % 4 == 0 && a % 100!=0)){
        return 1;
    }
    else{
        return 0;
    }
}

//Funcion que devuelve la cantidad de dias de un mes y año indicado.
int cant_dias(int m, int a) // OK !
{
    int vec1[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int vec2[12] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if(es_Bisiesto(a)){
        return vec2[m-1];
    }
    else{
        return vec1[m-1];
    }
}

//Funcion que comprueba si la fecha es correcta.
int es_Fecha_Valida(tFecha F)
{
    if(F.anio>1600){
        if(F.mes >01 && F.mes<=12){
            if(F.dia>=1 && F.dia<=cant_dias(F.mes, F.anio)){
                return 1;
            }
        }
    }
    return 0;
}

//Este metodo resta a una fecha determinada una cantidad de dias.
void Restar_Fecha(T_Fecha *Fecha, int dias)
{
    int fecha_dias = Fecha_a_Dias(Fecha); //Primero paso la fecha a dias.
    fecha_dias-=dias; //Resto la fecha pasada a dias, por los dias a restar.
    *Fecha = Dias_a_fecha(fecha_dias); //Paso el resultado de la resta anterior nuevamente a formato fecha.
}

T_Fecha Sumar_dias_a_fecha(T_Fecha *Fini, int dias) // OK !
{
    T_Fecha Ffin = *Fini;
    Ffin.d += dias;
    int cdm;
    while(Ffin.d>(cdm = cant_dias(Ffin.m, Ffin.a)))
    {
        Ffin.d-=cant_dias(Ffin.m, Ffin.a);
        Ffin.m++;
        if(Ffin.m>12)
        {
            Ffin.m=1;
            Ffin.a++;
        }

    }
    return Ffin;
}

//Esta fecha convierte dias a (dd/mm/aaaa) si se ingresa 0 dias, la fecha devuelta sera 01/01/1900
T_Fecha Dias_a_fecha(int dias)
{
    T_Fecha Fecha; //Voy a devolver la fecha.
    Fecha.d = dias-1;
    Fecha.a = 1900; // Año 0 (EXCEL)
    Fecha.m = 1; // Mes 0 (EXCEL)
    int cdm;
    while(Fecha.d>(cdm = cant_dias(Fecha.m, Fecha.a)))
    {
        Fecha.d-=cant_dias(Fecha.m, Fecha.a);
        Fecha.m++;
        if(Fecha.m>12)
        {
            Fecha.m=1;
            Fecha.a++;
        }
    }
    return Fecha;
}

//Este método convierte una fecha (dd/mm/aaaa) -> dd
int Fecha_a_Dias(T_Fecha *Fecha)
{
    int dias = 0; //Esta variable es la que almacena la fecha convertida a dias.
    int auxiliar; // Esta variable la voy a usar para dos ciclos diferentes, pero su uso es claro.
    auxiliar = Fecha->a; // Guardo el valor de los años de la estructura fecha en auxiliar.
    while(auxiliar>1900) //Voy recorriendo los años, hasta llegar a 1900 mi año 0 (Coincide con el usado por Excel).
    {
        if(es_Bisiesto(auxiliar)) // Si el año es bisiesto sumo 366 dias.
        {
            dias+=366;
        }
        else // Si el año no es bisiesto sumo 365 dias.
        {
            dias+=365;
        }
        auxiliar--;
    }
    auxiliar = 1; //Ahora auxiliar empieza desde 1 (Enero).
    while(auxiliar<(Fecha->m)) //Mientras que la variable auxiliar no llegue al mes de la fecha.
    {
        if(auxiliar == 2 && es_Bisiesto(Fecha->a)) // Si estoy en febrero y el año es bisiesto.
        {
            dias+=29;
        }
        if(auxiliar == 2 && !es_Bisiesto(Fecha->a)) // Si estoy en febrero y el año no es bisiesto.
        {
            dias+=28;
        }
        if(auxiliar == 4 || auxiliar == 6 || auxiliar == 9 || auxiliar == 11) // Si estoy en un mes con 30 dias.
        {
            dias+=30;
        }
        if(auxiliar == 1 || auxiliar == 3 || auxiliar == 5 || auxiliar == 7 || auxiliar == 8 || auxiliar == 10 || auxiliar == 12)
        {
            dias+=31;
        }
        auxiliar++;
    }
    dias+=Fecha->d; // Por último sumo los días que es lo mas fácil.
    return dias;
}

void Dia_Semana(T_Fecha *Fecha)
{
    T_Fecha Fecha_Standard;
    Fecha_Standard.d = 1;
    Fecha_Standard.m = 1;
    Fecha_Standard.a = 1900;
    //LUNES.

    int int_Fecha_Standard = Fecha_a_Dias(&Fecha_Standard);
    int int_Fecha = Fecha_a_Dias(Fecha);
    switch((int_Fecha-int_Fecha_Standard)%7)
    {
    case 0:
        puts("LUNES");
    break;
    case 1:
        puts("MARTES");
    break;
    case 2:
        puts("MIERCOLES");
    break;
    case 3:
        puts("JUEVES");
    break;
    case 4:
        puts("VIERNES");
    break;
    case 5:
        puts("SABADO");
    break;
    case 6:
        puts("DOMINGO");
    break;
    }
}
