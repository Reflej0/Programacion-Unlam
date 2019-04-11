#include <stdio.h>
#include <stdlib.h>
#include "comparador_fechas.h"

int main()
{
    //LAS FECHAS DEBEN SER VALIDADAS PREVIAMENTE.
    t_Fecha Fecha1;
    t_Fecha Fecha2;
    printf("Ingrese dia/mes/año:");
    scanf("%d/%d/%d", &Fecha1.d, &Fecha1.m, &Fecha1.a);
    printf("\nIngrese dia/mes/año:");
    scanf("%d/%d/%d", &Fecha2.d, &Fecha2.m, &Fecha2.a);
    int resultado = compare_optimizado(&Fecha1, &Fecha2);
    if(resultado>0)
    {
        puts("La fecha 1 es mayor a la fecha2");
    }
    if(resultado==0)
    {
        puts("Las fechas son iguales");
    }
    if(resultado<0)
    {
        puts("La fecha 1 es menor a la fecha2");
    }
    /*int resultado = compare(&Fecha1, &Fecha2);
    switch(resultado)
    {
    case 1:
        puts("La primera fecha es mayor a la segunda");
        break;
    case 0:
        puts("Las fechas son iguales");
        break;
    case -1:
        puts("La primera fecha es menor a la segunda");
        break;
    }*/

}
