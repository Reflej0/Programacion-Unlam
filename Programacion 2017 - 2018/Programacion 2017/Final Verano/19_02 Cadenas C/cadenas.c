#include <stdio.h>
#include <stdlib.h>
#include "cadenas.h"

char* _strcpy(char* dest, const char* src)
{
    int i = 0;
    while(*src)
    {
        *dest = *src;
        i++;
        src++;
        dest++;
    }
    *dest = '\0';
    return (dest-i);
}

char* _strcat(char* dest, const char* src)
{
    int i = 0;
    while(*dest)
    {
        i++;
        dest++;
    }
    while(*src)
    {
        *dest = *src;
        i++;
        src++;
        dest++;
    }
    *dest = '\0';
    return (dest-i);
}

int _strlen(char* c)
{
    int l = 0;
    while(*c)
    {
        l++;
        c++;
    }
    return l;
}

int _toUpper(char c)
{
    if(c >= 'a' && c <= 'z')
    {
        c -=32;
    }
    return c;
}

int comparador(char* aux, char* cad)
{
    int l = _strlen(cad);
    char c;
    char d;
    int i = 0;
    while(*aux)
    {
        c = _toUpper(*aux);
        d = _toUpper(*cad);
        if(c == d)
        {
            i++;
            cad++;
        }
        else
        {
            cad-=i;
        }
        if(i == l)
        {
            return 1;
        }
        aux++;
    }
    return 0;
}
