#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

void crear_pila(T_pila* p)
{
    p->tope = -1;
}

int apilar(T_pila* p, const T_dato* d)
{
    if(p->tope == TAM-1)
    {
        return 0;
    }
    p->tope +=1;
    p->vpila[p->tope] = *d;
    return 1;
}

int ver_tope(const T_pila* p, T_dato *d)
{
    if(p->tope == -1)
    {
        return 0;
    }
    *d = p->vpila[p->tope];
    return 1;
}

int desapilar(T_pila* p, T_dato* d)
{
    if(p->tope == -1)
    {
        return 0;
    }
    *d = p->vpila[p->tope];
    p->tope-=1;
    return 1;
}

int pila_llena(T_pila* p)
{
    if(p->tope == TAM-1)
    {
        return 1;
    }
    return 0;
}
