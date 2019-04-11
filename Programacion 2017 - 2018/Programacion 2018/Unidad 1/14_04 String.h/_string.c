#include <stdio.h>
#include <stdlib.h>
#include "_string.h"

char* _strcat(char* dest, const char* src)
{
    unsigned i = 0;
    while(*dest)
    {
        dest++;
        i++;
    }
    while(*src)
    {
        *dest = *src;
        src++;
        dest++;
        i++;
    }
    *dest = '\0';
    return (dest-i);
}

char* _strchr(char* cad, char c)
{
    while(*cad)
    {
        if(*cad == c)
        {
            return cad;
        }
        cad++;
    }
    return NULL;
}

int _strcmp(const char* cad1, const char* cad2)
{
    size_t l1 = _strlen(cad1);
    size_t l2 = _strlen(cad2);
    if(l1>l2)
    {
        return -1;
    }
    if(l1<l2)
    {
        return 1;
    }
    while(*cad1) // Se obvia cad2 ya que tienen la misma longitud.
    {
        if(*cad1 > *cad2)
        {
            return -1;
        }
        if(*cad1 < *cad2)
        {
            return 1;
        }
        cad1++;
        cad2++;
    }
    return 0;
}

char* _strcpy(char *dest, const char *src)
{
    unsigned i = 0;
    while(*src)
    {
        *dest = *src;
        dest++;
        src++;
        i++;
    }
    *dest = '\0';
    return (dest-i);
}

char* _strstr(char *donde, const char *buscar)
{
    size_t l = _strlen(buscar);
    int i = 0;
    while(*donde)
    {
        if(i == l)
        {
            return (donde-l);
        }
        if(*donde == *buscar)
        {
            i++;
            buscar++;
        }
        else
        {
            buscar-=i;
        }
        donde++;
    }
    return NULL;
}

size_t _strlen(const char* cad)
{
    size_t i = 0;
    while(*cad)
    {
        i++;
        cad++;
    }
    return i;
}
