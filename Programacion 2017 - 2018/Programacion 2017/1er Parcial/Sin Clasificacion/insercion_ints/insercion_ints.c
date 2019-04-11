#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "insercion_ints.h"

void ord_insercion_asc(int *v, int const ce)
{
    int i;
    int temp;
    int j;
    for(i=1; i<ce; i++) // Arranco i en 1, osea en la posicion siguiente.
    {
        temp = v[i]; // El valor de la posicion siguiente es guardado en tempora.
        j = i - 1; // J empieza en la posicion actual (siguiente - 1).
        while(v[j] > temp && (j >=0)) // Si el elemento actual es mayor a la siguiente.
        {
            v[j+1] = v[j]; // El elemento siguiente pasa a ser actual.
            j--;
        }
        v[j+1] = temp; // Sino queda todo como esta.
    }
}
