#include <stdio.h>
#include <stdlib.h>
#include "ejercicio14.h"

int main()
{
    char cadenas[TAM][PALABRA];
    int palabras = ingresar_cadenas(cadenas);
    imprimir(cadenas, palabras);
}
