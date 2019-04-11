#include <stdio.h>
#include <stdlib.h>
#include "ejercicio8.h"


int main()
{
    char text[TAM] = {0};
    int tamano = ingresar_texto(text);
    primera_palabra(text);
    palabras_texto(text);
}
