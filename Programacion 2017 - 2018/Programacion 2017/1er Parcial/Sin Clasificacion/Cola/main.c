#include <stdio.h>
#include <stdlib.h>
#include "cola.h"

int main()
{
    elemento *uno = malloc(sizeof(elemento));
    elemento *dos = malloc(sizeof(elemento));
    elemento *tres = malloc(sizeof(elemento));
    uno->nombre = "Analisis 1";
    dos->nombre = "Analisis 2";
    tres->nombre = "Fisica 1";
    agregar(uno);
    agregar(dos);
    agregar(tres);

    elemento *i = extraer();

    while(i != NULL)
    {
        printf("%s\n", i->nombre);
        i = extraer();
    }
}
