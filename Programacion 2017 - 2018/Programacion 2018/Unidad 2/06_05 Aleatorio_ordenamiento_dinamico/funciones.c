#include <sys/time.h>
#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

//Funcion para generar la semilla a partir de la hora actual expresada en milisegundos.
void generar_semilla()
{
    struct timeval start;
    gettimeofday(&start, NULL); // Obtiene el tiempo actual.
    srand(start.tv_usec); //Start.tv_usec contiene el tiempo en milisegundos.
}

int generar_int_aleatorio(int menor, int mayor)
{
    /// ERROR.
    if(menor>mayor)
    {
        return 0;
    }
    ///Intervalo [menor, mayor).
    return rand()%(mayor - menor)+menor;
}

float generar_float_aleatorio(int menor, int mayor)
{
    /// ERROR.
    if(menor>mayor)
    {
        return 0;
    }
    ///Intervalo [menor, mayor).
    return menor + (float)(rand() / (float) RAND_MAX) * (mayor - menor);
}

char generar_caracter_aleatorio()
{
    return rand()%(127 - 33)+33;
}

/*
tipo = 0. INT.
tipo = 1. FLOAT.
tipo = 2. CHAR.
*/
void llenar_vector(void* v, size_t tam, int tipo)
{
    int i = 0;
    if(tipo == ENTERO)
    {
        for(; i<tam; i++)
        {
            *(int*)v = generar_int_aleatorio(-100, 100);
            v+=sizeof(int);
        }
    }
    else if(tipo == REAL)
    {
        for(; i<tam; i++)
        {
            *(float*)v = generar_float_aleatorio(-100, 100);
            v+=sizeof(float);
        }
    }
    else if(tipo == CARACTER)
    {
        for(; i<tam; i++)
        {
            *(char*)v = generar_caracter_aleatorio();
            v+=sizeof(char);
        }
    }
}

/*
tipo = 0. INT.
tipo = 1. FLOAT.
tipo = 2. CHAR.
*/
void mostrar_vector(void* v, size_t tam, int tipo)
{
    int i = 0;
    if(tipo == ENTERO)
    {
        for(; i<tam; i++)
        {
            printf("%d\n", *(int*)v);
            v+=sizeof(int);
        }
    }
    else if(tipo == REAL)
    {
        for(; i<tam; i++)
        {
            printf("%f\n", *(float*)v);
            v+=sizeof(float);
        }
    }
    else if(tipo == CARACTER)
    {
        for(; i<tam; i++)
        {
            printf("%c\n", *(char*)v);
            v+=sizeof(char);
        }
    }
}

int comp_int(const void* a, const void* b)
{
    return *(int*)a-*(int*)b;
}

int comp_float(const void* a, const void* b)
{
    ///Para cumplir con el prototipo que recibe qsort que es int* no float*
    float comp = *(float*)a-*(float*)b;
    if(comp<0)
    {
        return -1;
    }
    else if(comp > 0)
    {
        return 1;
    }
    return 0;
}

int comp_char(const void* a, const void* b)
{
    return *(char*)a-*(char*)b;
}

