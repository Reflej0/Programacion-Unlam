#include <stdio.h>
#include <stdlib.h>
#include "normalizacion_cadenas.h"

int expresion_regular(char *c)
{
    if((c>='a') && (c<='z') || (c>='A') && (c<='Z'))
    {
        return 1;
    }
    return 0;
}

void normalizar_cadena(char *cadena)
{
    char palabra[100];
    size_t longitud;
    while(*cadena)
    {
        if(expresion_regular(*cadena))
        {
            palabra[longitud] = *cadena;
            printf("%c", palabra[longitud]);
        }
        cadena++;
        longitud++;
    }
}
