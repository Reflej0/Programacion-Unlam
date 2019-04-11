#include <stdio.h>
#include <stdlib.h>
#include "cadenas.h"

size_t _strlen(const char* cadena)
{
    size_t i = 0;
    while(*cadena)
    {
        cadena++;
        i++;
    }
    return i;
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
        origen++;
        destino++;
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

char* _strstr(char* cadena, const char* abuscar)
{
    size_t longitudbuscada = _strlen(abuscar);
    unsigned i = 0;
    while(*cadena)
    {
        i = 0;
        while(*cadena == *abuscar)
        {
            i++;
            if(i == longitudbuscada)
            {
                return cadena;
            }
            cadena++;
            abuscar++;
        }
        cadena++;
    }
    return NULL;
}

int _strcmp(const char* c1, const char* c2)
{
    size_t s1 = _strlen(c1);
    size_t s2 = _strlen(c2);
    if(s1 < s2)
    {
        return -1;
    }
    if(s1 > s2)
    {
        return 1;
    }
    if(s1 == s2)
    {
        while(*c1)
        {
            if(*c1 < *c2)
            {
                return -1;
            }
            if(*c1 > *c2)
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

void invertir(char* invertida, const char* cadena)
{
    size_t longitud = _strlen(cadena);
    longitud--;
    for(; longitud > 0; longitud--)
    {
        *invertida = cadena[longitud];
        invertida++;
    }
    *invertida = cadena[longitud];
}

void normalizar(char* salida, const char* entrada)
{
    while(*entrada)
    {
        if((*entrada >= 'a' && *entrada <= 'z') || (*entrada >= 'A' && *entrada <= 'Z'))
        {
            *salida = *entrada;
            salida++;
        }
        entrada++;
    }
}
