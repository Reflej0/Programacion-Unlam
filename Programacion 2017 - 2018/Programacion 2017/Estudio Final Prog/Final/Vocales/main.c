#include <stdio.h>
#include <stdlib.h>
#include "vocales.h"

int main()
{
    char frase[500];
    printf("Ingrese una frase:");
    gets(frase);
    int palabras = cantidad_palabras_4_mas_vocales(frase);
    printf("\nLa cantidad de palabras con 4 o mas vocales es: %d", palabras);
}
