#include <stdio.h>
#include <stdlib.h>
#include "cola.h"

void crear_cola(T_cola* pc)
{
    pc->frente = 0;
    pc->fondo = 0;
    pc->tope = -1;
}

int acolar(T_cola* pc, const T_dato* pd)
{
    if(pc->tope == TAM-1)
    {
        return 0;
    }
    pc->tope+=1;
    pc->vcola[pc->fondo] = *pd;
    pc->fondo = (pc->fondo % TAM) + 1;
    return 1;
}

int desacolar(T_cola* pc, T_dato* pd)
{
    if(pc->tope == -1)
    {
        return 0;
    }
    *pd = pc->vcola[pc->frente];
    pc->frente = (pc->frente % TAM) + 1;
    pc->tope-=1;
    return 1;
}

int colaVacia(const T_cola* pc)
{
   if(pc->tope == -1)
    {
        return 1;
    }
    return 0;
}
