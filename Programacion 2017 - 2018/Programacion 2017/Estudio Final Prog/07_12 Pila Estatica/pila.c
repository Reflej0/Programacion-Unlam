#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

void crear_pila(T_pila* pila)
{
    pila->tope = -1;
}

void vaciar_pila(T_pila* pila)
{
    pila->tope = -1;
}

int apilar(T_pila* pila, const T_dato* d)
{
    if(pila->tope == TAM-1)
    {
        return -1;
    }
    pila->tope +=1;
    pila->datos[pila->tope] = *d;
    return 1;
}

int ver_tope(T_pila* pila, T_dato* d)
{
    if(pila->tope == -1)
    {
        return 0;
    }
    *d = pila->datos[pila->tope];
    return 1;
}

int desapilar(T_pila* pila, T_dato* d)
{
    if(pila->tope == -1)
    {
        return 0;
    }
    *d = pila->datos[pila->tope];
    pila->tope -= 1;
    return 1;
}

int pila_vacia(T_pila* pila)
{
    if(pila->tope == -1)
    {
        return 1;
    }
    return 0;
}

int pila_llena(T_pila* pila)
{
    if(pila->tope == TAM-1)
    {
        return 1;
    }
    return 0;
}
