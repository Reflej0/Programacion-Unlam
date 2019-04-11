#include <stdio.h>
#include <stdlib.h>
#include "seleccion_enteros.h"

void ord_seleccion_asc(float *v, int ce)
{
    float *i;
    float *m;
    float *ult = v + (ce - 1);
    for(i=v; i<ult; i++)
    {
        m = buscar_menor(i, ult);
        if(m!=i)
        {
            change(m, i);
        }
    }
}

float* buscar_menor(float *ini, float*fin)
{
    float *act = ini;
    float *m = ini;
    while(act<=fin)
    {
        if(*act<*m)
        {
            m = act;
        }
        act++;
    }
    return m;
}

void change(float *a,float *b)
{
    float aux;
    aux = *a;
    *a = *b;
    *b = aux;
}
