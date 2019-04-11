#include <stdio.h>
#include <stdlib.h>
#include "ejercicio2.h"

int busqueda(int* vector, int dato, size_t tam)
{
    int i;
    for(i=0;i<tam;i++)
    {
        if(dato == vector[i])
        {
            return &vector[i];
        }
    }
    return 0;
}
