#include <stdio.h>
#include <stdlib.h>
#include "header.h"
#define TAM 5

int main()
{
    int vector_int[TAM] = {100, 200, -100, -50, 80};
    ordenar(vector_int, sizeof(int), TAM, comp_int, ASC);
    mostrar_vector_int(vector_int, TAM);
    return 1;
}
