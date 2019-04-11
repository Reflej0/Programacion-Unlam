#include <stdio.h>
#include <stdlib.h>
#include "string.h"

size_t strlen(char const *cadena)
{
    size_t longitud = 0;
    while(*cadena)
    {
        longitud++;
        cadena++;
    }
    return longitud;
}


/* Posibles retornos:

-1: Si la primera cadena tiene menos caracteres que la segunda cadena.
0 : Si ambas cadenas son idénticas.
1 : Si la primera cadena tiene mas caracteres que la segunda cadena.
2 : Si ambas cadenas tienen la misma cantidad de caracteres pero son distintas.

*/

int strcmp(char const *c, char const *c2)
{
    int i;
    int coincidencias = 0;
    size_t longitud = strlen(c);
    size_t longitud2 = strlen(c2);
    if(longitud > longitud2)
    {
        return 1;
    }
    if(longitud < longitud2)
    {
        return -1;
    }
    //Si llegue aca significa que tienen la misma cantidad de caracteres.
    for(i=0;i<longitud;i++)
    {
        if(c[i] == c2[i])
        {
            coincidencias++;
        }
    }
    if(coincidencias == longitud)
    {
        return 0;
    }
    else
    {
        return 2;
    }
}

/*  La entrada deben ser dos cadenas con igual longitud y no identicas.
    Posibles retornos:
    -1: Lexicograficamente la primera cadena es menor que la segunda.
    1: Lexicograficamente la primera cadena es mayor que la segunda.
*/

int comparacion_lexicografica(char c[], char c2[])
{
    int i;
    size_t longitud = strlen(c);
    for(i=0;i<longitud;i++)
    {
        if(c[i]<c2[i])
        {
            return -1;
        }
        if(c[i]>c2[i])
        {
            return 1;
        }
    }
    return 0;
}

void strcpy(char const *fuente, char *destino)
{
    int i = 0;
    while(i<strlen(fuente))
    {
        destino[i] = fuente[i];
        i++;
    }
}

int strchr(char const *cadena, char caracter)
{
    int i = 0;
    while(i<strlen(cadena))
    {
        if(cadena[i] == caracter)
        {
            return &cadena[i];
        }
        i++;
    }
}
