#include <stdio.h>
#include <stdlib.h>
#include "cola.h"

void crear_cola(T_cola* pc)
{
    pc->frente = 0;
    pc->fondo = -1;
    pc->ce = 0;
}

int acolar(T_cola* pc, const T_dato* d)
{
    if(pc->ce == TAM)
    {
        return 1; //Cola llena.
    }
    pc->fondo = (pc->fondo+1)%TAM;
    pc->vcola[pc->fondo] = *d;
    pc->ce++;
    return 0;
}

int desacolar(T_cola* pc, T_dato* d)
{
    if(pc->ce == 0)
    {
        return 1; //Cola vacia.
    }
    *d = pc->vcola[pc->frente];
    pc->frente = (pc->frente+1)%TAM;
    pc->ce--;
    return 0;
}

int ver_tope(const T_cola* pc, T_dato* d)
{
    if(pc->ce == 0)
    {
        return 1; //Cola vacia.
    }
    *d = pc->vcola[pc->frente];
    return 0;
}
