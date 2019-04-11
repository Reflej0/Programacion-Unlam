#include <stdio.h>
#include <stdlib.h>
#include "fecha.h"

int es_Bisiesto(int a)
{
    if(a % 400 == 0 || (a % 4 == 0 && a % 100!=0)){
        return 1;
    }
    else{
        return 0;
    }
}

int cant_dias(int m, int a)
{
    //int i;
    int vec1[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30};
    int vec2[12] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30};
    if(es_Bisiesto(a)){
        return vec1[m-1];
    }
    else{

        return vec2[m-1];
    }
}

int es_Fecha_Valida(tFecha F)
{
    if(F.anio>1600){
        if(F.mes >=1 && F.mes<=12){
            if(F.dia>=1 && F.dia<=cant_dias(F.mes, F.anio)){
                return 1;
            }
        }
    }
    return 0;
}

int compare_fecha(tFecha const *Fecha1, tFecha const *Fecha2)
{
    int int_Fecha1 = ((Fecha1->anio*10000)+(Fecha1->mes*100)+(Fecha1->dia));
    int int_Fecha2 = ((Fecha2->anio*10000)+(Fecha2->mes*100)+(Fecha2->dia));
    return (int_Fecha1 - int_Fecha2);
}
