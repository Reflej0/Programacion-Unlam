#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

int main()
{
    elemento* uno = malloc(sizeof(elemento));
    elemento* dos = malloc(sizeof(elemento));
    elemento* tres = malloc(sizeof(elemento));
    elemento* cuatro = malloc(sizeof(elemento));
    uno->nombre = "Analisis 1";
    dos->nombre = "Analisis 2";
    tres->nombre = "Fisica 1";
    cuatro->nombre = "Fisica 2";
    agregar(uno);
    agregar(dos);
    agregar(tres);
    agregar(cuatro);
    elemento* i = extraer();
    while(i !=NULL)
    {
        printf("%s\n", i->nombre);
        i = extraer();
    }
}
