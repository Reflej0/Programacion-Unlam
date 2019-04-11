#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "cadena.h"

size_t _strlen(const char* s)
{
    size_t l = 0;
    while(*s)
    {
        l++;
        s++;
    }
    return l;
}

char* _strcpy(char* dest, const char* src)
{
    char* inicio = dest;
    while(*src)
    {
        *dest = *src;
        src++;
        dest++;
    }
    *dest = '\0';
    return inicio;
}

char* _strncpy(char *dest, const char* src, size_t n)
{
    char* inicio = dest;
    size_t i = 0;
    while(*src && i < n)
    {
        *dest = *src;
        src++;
        dest++;
        i++;
    }
    *dest = '\0';
    return inicio;
}

char* _strcat(char* dest, const char* src)
{
    char* inicio = dest;
    while(*dest)
        dest++;
    while(*src)
    {
        *dest = *src;
        src++;
        dest++;
    }
    *dest = '\0';
    return inicio;
}

char* _strncat(char* dest, const char* src, size_t n)
{
    char* inicio = dest;
    size_t i = 0;
    while(*dest)
        dest++;
    while(*src && i<n)
    {
        *dest = *src;
        src++;
        dest++;
        i++;
    }
    *dest = '\0';
    return inicio;
}

int _strcmp(const char* s1, const char* s2)
{
    while(*s1 || *s2)
    {
        if(*s1 > *s2)
            return 1;
        else if(*s1 < *s2)
            return -1;
        if(*s1 != '\0')
            s1++;
        if(*s2 != '\0')
            s2++;
    }
    return 0;
}

int _strncmp(const char* s1, const char* s2, size_t n)
{
    size_t i = 0;
    while((*s1 || *s2) && i<n)
    {
        if(*s1 > *s2)
            return 1;
        else if(*s1 < *s2)
            return -1;
        if(*s1 != '\0')
            s1++;
        if(*s2 != '\0')
            s2++;
        i++;
    }
    return 0;
}

size_t _strcspn(const char* s1, const char* s2)
{
    size_t l = 0;
    const char* inicios2 = s2;
    while(*s1)
    {
        if(*s1 == *s2)
            return l;
        else
        {
            s2++;
            if(*s2=='\0')
                s2 = inicios2;
        }
        l++;
        s1++;
    }
    return l;
}

char* _strpbrk(const char* s1, const char* s2)
{
    const char* inicios2 = s2;
    while(*s1)
    {
        while(*s2)
        {
            if(*s1 == *s2)
                return (char*)s1;
            s2++;
        }
        s2 = inicios2;
        s1++;
    }
    return NULL;
}

char* _strstr(const char* s, const char* b)
{
    const char* iniciob = b;
    while(*s)
    {
        if(*s == *b)
            b++;
        else
            b = iniciob;
        if(*b == '\0')
            return (char*)s;
        s++;
    }
    return NULL;
}

char* normalizar_nombre(char* nombre)
{
    char* inicio = nombre;
    char* escritura = nombre;
    while(*nombre == ' ' || !_ESLETRA(*nombre)) ///AVANZO LOS ESPACIOS EN BLANCO Y NO LETRA DEL PRINCIPIO.
        nombre++;
    if(*nombre) ///SI HAY ALGO DESPUES DE LO ANTERIOR ES LA PRIMERA LETRA DEL NOMBRE.
        *escritura = _TOUPPER(*nombre);
    escritura++;
    nombre++;
    while(*nombre)
    {
        if(_ESLETRA(*nombre))
        {
            *escritura = _TOLOWER(*nombre);
            escritura++;
        }
        if(*nombre == ' ')
        {
            while(*nombre == ' ') ///AVANZO LOS ESPACIOS DEL MEDIO.
                nombre++;
            *escritura = ' ';
            escritura++;
            *escritura = _TOUPPER(*nombre);
            escritura++;
        }
        nombre++;
    }
    if(*escritura == '\0') ///COMO MUCHO SI HABIA n ESPACIOS AL FINAL DEJO EL ULTIMO.
        escritura--;
    *escritura = '\0';
    return inicio;
}

int _strstrcantidad(const char* s, const char* b)
{
    size_t coincidencias = 0;
    const char* iniciob = b;
    while(*s)
    {
        if(*s == *b)
            b++;
        else
            b = iniciob;
        if(*b == '\0')
        {
            coincidencias++;
            b = iniciob;
        }
        s++;
    }
    return coincidencias;
}

char* reemplazar_identicos(char* s, const char* b, const char* re)
{
    size_t l = _strlen(b); ///Longitud de la cadena a buscar.
    const char* iniciob = b; ///Comienzo de la cadena a buscar.
    const char* iniciore = re; ///Comienzo de la cadena a reemplazar.
    char* retorno = (char*)malloc(sizeof(_strlen(s))+50); ///APROX.
    if(!retorno) return NULL;
    char* inicio = retorno; ///Puntero de la cadena a devolver.
    while(*s)
    {
        *retorno = *s;
        if(*s == *b)
            b++;
        else
            b = iniciob;
        if(*b == '\0')
        {
            b = iniciob; ///Retrocedo la cadena a buscar.
            retorno-=l-1; ///Retrocedo retorno para hacer el copiado de la cadena a reemplazar.
            while(*re)
            {
                *retorno = *re;
                retorno++;
                re++;
            }
            *retorno='\0';
            retorno--;
            re = iniciore;
        }
        s++;
        retorno++;
    }
    *retorno='\0';
    return inicio;
}

char* invertir_cadena(char* s)
{
        char* inicio = s;
        char* fin = &s[_strlen(s)-1];
        char aux;
        while(s<fin)
        {
            aux = *s;
            *s = *fin;
            *fin = aux;
            s++;
            fin--;
        }
        return inicio;
}

char* __itoa(int n, char* s, int base)
{
    char* inicio = s;
    while(n>0)
    {
        *s = (n % base)+'0';
        n/=base;
        s++;
    }
    *s = '\0';
    invertir_cadena(inicio);
    return inicio;
}
