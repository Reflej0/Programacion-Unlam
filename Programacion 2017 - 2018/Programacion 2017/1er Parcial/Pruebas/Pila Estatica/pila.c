#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

void crear_pila(T_pila* p)
{
    p->tope = -1;
}

int apilar(T_pila *p, const T_dato *d)
{
    if(p->tope == TAM)
    {
        return 1; //Pila llena.
    }
    p->tope++;
    p->vec[p->tope] = *d;
    return 0;
}

int desapilar(T_pila *p, T_dato *d)
{
    if(p->tope == -1)
    {
        return 1; //Pila vacia.
    }
    *d = p->vec[p->tope];
    p->tope--;
    return 0;
}

void vaciar_pila(T_pila *p)
{
    p->tope = -1;
}

int ver_tope(const T_pila *p, T_dato *d)
{
    if(p->tope == -1)
    {
        return 1; //Pila vacia.
    }
    *d = p->vec[p->tope];
    return 0;
}
