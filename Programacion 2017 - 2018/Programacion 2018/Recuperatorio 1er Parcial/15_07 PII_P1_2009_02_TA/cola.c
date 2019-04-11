#include <stdio.h>
#include <stdlib.h>
#include "cola.h"

void crear_cola(T_cola* c)
{
    c->inicio = 0;
    c->fin = -1;
    c->nro_ele = 0;
}

int acolar(T_cola* c, const T_dato* d)
{
    if(c->nro_ele == TAM) return 0;
    c->fin++; c->fin %=TAM;
    c->vcola[c->fin] = *d;
    c->nro_ele++;
    return 1;
}

int desacolar(T_cola* c, T_dato* d)
{
    if(c->nro_ele==0)return 0;
    *d = c->vcola[c->inicio];
    c->inicio++; c->inicio %=TAM;
    c->nro_ele--;
    return 1;
}

int esta_cola_llena(const T_cola* c)
{
    return (c->nro_ele==TAM) ? 1 : 0;
}

int esta_cola_vacia(const T_cola* c)
{
    return (c->nro_ele == 0) ? 1 : 0;
}

void vaciar_cola(T_cola* c)
{
    c->inicio = 0;
    c->fin = -1;
    c->nro_ele = 0;
}

int ver_frente(const T_cola* c, T_dato* d)
{
    if(c->nro_ele==0)return 0;
    *d = c->vcola[c->inicio];
    return 1;
}
