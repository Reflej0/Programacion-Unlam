#include <stdio.h>
#include <stdlib.h>
#include "header.h"
#define TAM 5

int main()
{
    int enteros[TAM] = {5, 10, -5, 30, -10};
    float reales[TAM] = {1.2, -4.3, 4.1, 4.9, -0.1};
    char letras[TAM] = {'a', 'z', 't', 'w', 'e'};
    //ENTEROS
    printf("Antes del ordenamiento:\n");
    mostrar_vector(enteros, TAM, INT);
    ordenamiento_generico(enteros, TAM, sizeof(int), SELECCION, ASC, comp_int);
    printf("Despues del ordenamiento:\n");
    mostrar_vector(enteros, TAM, INT);
    //REALES
    printf("Antes del ordenamiento:\n");
    mostrar_vector(reales, TAM, FLOAT);
    ordenamiento_generico(reales, TAM, sizeof(float), BURBUJA, DESC, comp_float);
    printf("Despues del ordenamiento:\n");
    mostrar_vector(reales, TAM, FLOAT);
    //LETRAS
    printf("Antes del ordenamiento:\n");
    mostrar_vector(letras, TAM, CHAR);
    ordenamiento_generico(letras, TAM, sizeof(char), SELECCION, DESC, comp_letras);
    printf("Despues del ordenamiento:\n");
    mostrar_vector(letras, TAM, CHAR);
    return 0;
}
