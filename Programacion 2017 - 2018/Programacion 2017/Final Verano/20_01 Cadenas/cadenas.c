#include <stdio.h>
#include <stdlib.h>
#include "cadenas.h"

size_t _strlen(const char* cadena)
{
    size_t longt = 0;
    while(*cadena)
    {
        longt++;
        cadena++;
    }
    return longt;
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
    int lon = _strlen(abuscar);
    int i = 0;
    while(*cadena)
    {
        i = 0;
        while(*cadena == *abuscar)
        {
            i++;
            cadena++;
            abuscar++;
            if(i == lon)
            {
                return cadena-=i; // Si quiero que me muestre a partir de donde lo encontro.
            }
        }
        cadena++;
        abuscar-=i;
    }
    return NULL;
}

int _strcmp(const char* c1, const char* c2)
{
    int l1 = _strlen(c1);
    int l2 = _strlen(c2);
    if(l1<l2)
    {
        return -1;
    }
    if(l1>l2)
    {
        return 1;
    }
    if(l1==l2)
    {
        int avance = 0;
        while(*c1==*c2)
        {
            c1++;
            c2++;
            avance++;
        }
        if(avance-1 == l1)
        {
            return 0;
        }
        if(*c1<*c2)
        {
            return 1;
        }
        if(*c1>*c2)
        {
            return -1;
        }
    }
}

void invertir(char* invertida, const char* cadena)
{
    int lon = _strlen(cadena);
    int i;
    int aux = lon-1;
    for(i=0;i<lon;i++)
    {
        invertida[i] = cadena[aux-i];
    }
}
