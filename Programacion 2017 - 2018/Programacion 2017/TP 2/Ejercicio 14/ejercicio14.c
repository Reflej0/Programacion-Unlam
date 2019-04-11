#include <stdio.h>
#include <stdlib.h>
#include "ejercicio14.h"

/*
Similar a strlen.
*/

size_t _strlen(char *c)
{
    size_t longitud = 0;
    while(*c)
    {
        c++;
        longitud++;
    }
    return longitud;
}

/* Posibles retornos:

-1: Si la primera cadena tiene menos caracteres que la segunda cadena.
0 : Si ambas cadenas son idénticas.
1 : Si la primera cadena tiene mas caracteres que la segunda cadena.
2 : Si ambas cadenas tienen la misma cantidad de caracteres pero son distintas.

*/

int _strcmp(char c[], char c2[])
{
    int i;
    int coincidencias = 0;
    size_t longitud = _strlen(c);
    size_t longitud2 = _strlen(c2);
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
    size_t longitud = _strlen(c);
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
}

int ingresar_cadenas(char c[][PALABRA])
{
    int i = 0;
    char palabra[PALABRA];
    char palabra2[PALABRA];
    do
    {
        printf("Ingrese la primera cadena:");
        gets(palabra);
        printf("Ingrese la segunda cadena:");
        gets(palabra2);
        if(_strcmp(palabra, palabra2) == -1)
        {
            sprintf(c[i], palabra); //Para no usar strcpy.
            //c[i] = palabra;
            i++;
            sprintf(c[i], palabra2);
            //c[i] = palabra2;
            i++;
        }
        if(_strcmp(palabra, palabra2) == 1)
        {
            sprintf(c[i], palabra2);
            //*c[i] = palabra2;
            i++;
            sprintf(c[i], palabra);
            //*c[i] = palabra;
            i++;
        }
        if(_strcmp(palabra, palabra2) == 2)
        {
            if(comparacion_lexicografica(palabra, palabra2) == -1)
            {
                sprintf(c[i], palabra);
                //*c[i] = palabra;
                i++;
                sprintf(c[i], palabra2);
                //*c[i] = palabra2;
                i++;
            }
            if(comparacion_lexicografica(palabra, palabra2) == 1)
            {
                sprintf(c[i], palabra2);
                //*c[i] = palabra2;
                i++;
                sprintf(c[i], palabra);
                //*c[i] = palabra;
                i++;
            }
        }
    }
    while(_strcmp(palabra, palabra2));
    return i;
}

void imprimir(char c[][PALABRA], int const cantidad)
{
    system("CLS");
    printf("Cantidad:%d\n", cantidad);
    int i = 0;
    for(i=0;i<cantidad;i++)
    {
        printf("%s\n", c[i]);
    }
}
