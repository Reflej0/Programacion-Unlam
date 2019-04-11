#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "header.h"

void ordenamiento_generico(void* v, size_t nro_elementos, size_t tam, int metodo, int forma, T_cmp comp)
{
    int i;
    switch(metodo)
    {
    case BURBUJA:;
        int j;
        for(i=1; i<nro_elementos; i++)
        {
            for(j=0; j<nro_elementos-1; j++)
            {
                if(comp(v, (v+tam), forma)<0)
                    intercambio_generico(v, (v+tam), tam);
                v+=tam;
            }
            v-=j*tam;
        }
        break;
    case SELECCION:;
        void* pos_menor = v;
        for(i=0; i<nro_elementos-1; i++)
        {
            pos_menor = buscarmenormax(v, i, nro_elementos, tam, forma, comp);

            if(v != pos_menor)
                intercambio_generico(v, pos_menor, tam);

            v+=tam;
        }
        break;
    case INSERCION:
        break;
    }
}

void intercambio_generico(void* a, void* b, size_t tam)
{
    void* aux = malloc(sizeof(tam));
    memcpy(aux, a, tam);
    memcpy(a, b, tam);
    memcpy(b, aux, tam);
    free(aux);
}

void* buscarmenormax(void* v, int pos_ini, size_t nro_elementos, size_t tam, int forma, T_cmp comp)
{
    int i, *pos_menor = v;
    for(i = pos_ini; i < nro_elementos; i++, v+=tam)
    {
        if(comp(v,pos_menor,forma)>0)
            pos_menor = v;
    }
    return pos_menor;
}

/*
tipo = 0. INT.
tipo = 1. FLOAT.
tipo = 2. CHAR.
*/
void mostrar_vector(void* v, size_t nro_elementos, int tipo)
{
    int i = 0;
    if(tipo == INT)
    {
        for(; i<nro_elementos; i++)
        {
            printf("%d\n", *(int*)v);
            v+=sizeof(int);
        }
    }
    else if(tipo == FLOAT)
    {
        for(; i<nro_elementos; i++)
        {
            printf("%f\n", *(float*)v);
            v+=sizeof(float);
        }
    }
    else if(tipo == CHAR)
    {
        for(; i<nro_elementos; i++)
        {
            printf("%c\n", *(char*)v);
            v+=sizeof(char);
        }
    }
}

int comp_int(const void* a, const void* b, int forma)
{
    if(forma == ASC)
        return *(int*)b-*(int*)a;
    else
        return *(int*)a-*(int*)b;
}

int comp_float(const void* a, const void* b, int forma)
{
    if(*(float*)b > *(float*)a)
    {
        if(forma == ASC)
            return 1;
        else
            return -1;
    }
    else if(*(float*)b < *(float*)a)
    {
        if(forma == ASC)
            return -1;
        else
            return 1;
    }
    return 0;
}

int comp_letras(const void* a, const void* b, int forma)
{
    if(forma == ASC)
        return *(char*)b-*(char*)a;
    else
        return *(char*)a-*(char*)b;
}

