#include <stdio.h>
#include <stdlib.h>
#include "ejercicio3.h"

int main()
{
    suma_promedio resultado;
    int* vector = NULL;
    vector = malloc(5*sizeof(int));
    int tam = ingresar_numeros(vector);
    suma_elementos(vector,tam,&resultado);
    printf("La suma de los elementos es: %d\nEl promedio de los elementos es: %.2f", resultado.suma, resultado.promedio);
}
