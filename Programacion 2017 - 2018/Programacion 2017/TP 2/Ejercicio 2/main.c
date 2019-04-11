#include <stdio.h>
#include <stdlib.h>
#include "ejercicio2.h"

int main()
{
    int *vector = NULL;
    vector = malloc(5*sizeof(int));
    vector[0] = 1;
    vector[1] = 10;
    vector[2] = 99;
    vector[3] = -50;
    vector[4] = 32;
    int dato = 10;
    int resultado = busqueda(vector, dato, 5);
    printf("La direccion de memoria del dato es: %d", resultado);
    scanf("%d", resultado);
    printf("\n%d", vector[1]);
}
