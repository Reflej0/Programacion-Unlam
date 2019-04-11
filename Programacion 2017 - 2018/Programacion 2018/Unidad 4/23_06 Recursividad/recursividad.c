#include <stdio.h>
#include <stdlib.h>
#include "recursividad.h"

size_t _strlen(const char* s)
{
    if(s == NULL ||*s == '\0')
        return 0;
    return _strlen(s+1)+1;
}

long long _factorial(long long n)
{
    if(n<0)
        return -1; ///ERROR.
    if(n == 0)
        return 1;
    return n*_factorial(n-1);
}

long long _primeros_n_cuadrado(long long n)
{
    if(n<0)
        return -1; ///ERROR.
    if(n==0)
        return 1;
    return (n*n)+_primeros_n_cuadrado(n-1);
}

void _mostrar_cadena_menos_caracter(const char* s, const char c)
{
    if(s == NULL ||*s == '\0')
        return;
    if(*s != c)
        printf("%c", *s);
    _mostrar_cadena_menos_caracter(s+1, c);
}

/**Funcion intermedia no recursiva necesaria para la declaracion
de la variable inicio que no debe ser declarada en el main
y no puede ser declarada dentro de la funcion recursiva.
/*/
void _mostrar_cadena_escalonada(const char* s)
{
    if(s == NULL ||*s == '\0')
        return;
    char* inicio = (char*)s;
    _mostrar_cadena_escalonada_recursivo(s, inicio);
}

void _mostrar_cadena_escalonada_recursivo(const char* s, const char* inicio)
{
    if(*s == '\0')
        return;
    char* ini = (char*)inicio;
    while(inicio <= s)
    {
        printf("%c", *inicio);
        inicio++;
    }
    printf("\n");
    _mostrar_cadena_escalonada_recursivo(s+1, ini);
}

void _print_vector_int(const int* v, size_t l, const char separador)
{
    if(v == NULL || l == 0)
        return;
    _print_vector_int_recursivo(v, v+l, separador);
}

void _print_vector_int_recursivo(const int* v, const int* fin, const char separador)
{
    if(v == NULL || v >= fin)
        return;
    printf("%d%c", *v, separador);
    _print_vector_int_recursivo(v+1, fin, separador);
}
