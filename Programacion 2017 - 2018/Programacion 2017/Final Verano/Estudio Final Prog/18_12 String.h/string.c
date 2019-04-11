#include <stdio.h>
#include <stdlib.h>
#include "string.h"

size_t _strlen(const char* cadena)
{
    size_t longitud = 0;
    while(*cadena)
    {
        cadena++;
        longitud++;
    }
    return longitud++;
}

void _strcpy(char* destino, const char *origen)
{
    while(*origen)
    {
        *destino = *origen;
        origen++;
        destino++;
    }
}

void _strcat(char* destino, const char* origen)
{
    while(*destino)
    {
        destino++;
    }
    while(*origen)
    {
        *destino = *origen;
        destino++;
        origen++;
    }
}

char* _strchr(char* cadena, int c)
{
    while(*cadena)
    {
        if(*cadena == c)
        {
            return cadena;
        }
        cadena++;
    }
    return NULL;
}

char* _strstr(char* cadena, char* abuscar)
{
    int similitud = 0;
    char* copia = abuscar;
    while(*cadena)
    {
        if(*cadena == *abuscar)
        {
            similitud++;
            abuscar++;
        }
        else
        {
            abuscar = copia;
        }
        if(similitud == _strlen(abuscar))
        {
            return --cadena;
        }
        cadena++;
    }
    return NULL;
}

int _strcmp(const char* c1, const char* c2)
{
    size_t l1 = _strlen(c1);
    size_t l2 = _strlen(c2);
    if(l1<l2)
    {
        return -1;
    }
    if(l1>l2)
    {
        return 1;
    }
    if(l1 == l2)
    {
        while(*c1)
        {
            if(*c1<*c2)
            {
                return -1;
            }
            if(*c2>*c2)
            {
                return 1;
            }
            if(*c1 == *c2)
            {
                c1++;
                c2++;
            }
        }
    }
    return 0;
}

void invertir(char* invertida, char* cadena)
{
    int i;
    size_t l = _strlen(cadena);
    char aux;
    for(i=0; i<l/2; i++)
    {
        aux = cadena[i];
        cadena[i] = cadena[l-i-1];
        cadena[l-i-1] = aux;
    }
    _strcpy(invertida, cadena);
}

void normalizar(char* salida, const char* entrada)
{

}
