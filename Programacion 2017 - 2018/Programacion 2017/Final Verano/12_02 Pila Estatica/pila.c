#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

void crear_pila(T_pila* p)
{
    p->tope = -1;
}

int apilar(T_pila* p, const T_dato *d)
{
    if(p->tope == TAM-1)
    {
        return -1;
    }
    p->tope++;
    p->vtope[p->tope] = *d;
    return 1;
}

int ver_tope(const T_pila* p, T_dato *d)
{
    if(p->tope == -1)
    {
        return -1;
    }
    *d = p->vtope[p->tope];
    return 1;
}

int desapilar(T_pila* p, T_dato *d)
{
    if(p->tope == -1)
    {
        return -1;
    }
    *d = p->vtope[p->tope];
    p->tope--;
    return 1;
}

int pila_llena(const T_pila* p)
{
    if(p->tope == TAM-1)
    {
        return 1;
    }
    return 0;
}
