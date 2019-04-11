#include <stdio.h>
#include <stdlib.h>
#include "resta_fechas.h"

//Esta funci�n me permite corroborar si un a�o es bisiesto o no.
int es_Bisiesto(int a)
{
    if(a % 400 == 0 || (a % 4 == 0 && a % 100!=0)){
        return 1;
    }
    else{
        return 0;
    }
}

//Este m�todo convierte una fecha (dd/mm/aaaa) -> dd
int Fecha_a_Dias(T_Fecha *Fecha)
{
    int dias = 0; //Esta variable es la que almacena la fecha convertida a dias.
    int auxiliar; // Esta variable la voy a usar para dos ciclos diferentes, pero su uso es claro.
    auxiliar = Fecha->a; // Guardo el valor de los a�os de la estructura fecha en auxiliar.
    while(auxiliar>1900) //Voy recorriendo los a�os, hasta llegar a 1900 mi a�o 0 (Coincide con el usado por Excel).
    {
        if(es_Bisiesto(auxiliar)) // Si el a�o es bisiesto sumo 366 dias.
        {
            dias+=366;
        }
        else // Si el a�o no es bisiesto sumo 365 dias.
        {
            dias+=365;
        }
        auxiliar--;
    }
    auxiliar = 1; //Ahora auxiliar empieza desde 1 (Enero).
    while(auxiliar<(Fecha->m)) //Mientras que la variable auxiliar no llegue al mes de la fecha.
    {
        if(auxiliar == 2 && es_Bisiesto(Fecha->a)) // Si estoy en febrero y el a�o es bisiesto.
        {
            dias+=29;
        }
        if(auxiliar == 2 && !es_Bisiesto(Fecha->a)) // Si estoy en febrero y el a�o no es bisiesto.
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
    dias+=Fecha->d; // Por �ltimo sumo los d�as que es lo mas f�cil.
    return dias;
}
//Funcion que devuelve la cantidad de dias de un mes y a�o indicado.
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

//Esta fecha convierte dias a (dd/mm/aaaa) si se ingresa 0 dias, la fecha devuelta sera 01/01/1900
T_Fecha Dias_a_fecha(int dias)
{
    T_Fecha Fecha; //Voy a devolver la fecha.
    Fecha.d = dias-1;
    Fecha.a = 1900; // A�o 0 (EXCEL)
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
//Este metodo resta a una fecha determinada una cantidad de dias.
void Restar_Fecha(T_Fecha *Fecha, int dias)
{
    int fecha_dias = Fecha_a_Dias(Fecha); //Primero paso la fecha a dias.
    fecha_dias-=dias; //Resto la fecha pasada a dias, por los dias a restar.
    *Fecha = Dias_a_fecha(fecha_dias); //Paso el resultado de la resta anterior nuevamente a formato fecha.
}
