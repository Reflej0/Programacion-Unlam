#include <stdio.h>
#include <stdlib.h>
#include "cola.h"

void crear_cola(T_cola* c)
{
    c->frente = 0;
    c->fondo = -1;
    c->ce = 0;
}

int acolar(T_cola *c, const T_dato *d)
{
    if(c->ce == TAM)
    {
        return 1; //Cola llena.
    }
    c->fondo = (c->fondo+1)%TAM;
    c->vec[c->fondo] = *d;
    c->ce++;
    return 0;
}

int desacolar(T_cola *c, T_dato *d)
{
    if(c->ce == 0)
    {
        return 1; //Cola vacia.
    }
    *d = c->vec[c->frente];
    c->frente = (c->frente+1)%TAM;
    c->ce--;
    return 0;
}

void vaciar_cola(T_cola *c)
{
    c->frente = 0;
    c->fondo = -1;
    c->ce = 0;
}

int ver_frente(const T_cola *c, T_dato *d)
{
    if(c->ce == 0)
    {
        return 1; //Cola vacia.
    }
    *d = c->vec[c->frente];
    return 0;
}
