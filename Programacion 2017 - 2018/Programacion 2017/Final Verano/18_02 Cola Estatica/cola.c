#include <stdio.h>
#include <stdlib.h>
#include "cola.h"

void crear_cola(T_cola* pc)
{
    pc->fr = 0;
    pc->fo = -1;
    pc->ce = 0;
}

int poner_en_cola(T_cola* pc, const T_dato* d)
{
    if(pc->ce == TAM)
    {
        return 0;
    }
    pc->fo = (pc->fo+1)%TAM;
    pc->vcola[pc->fo] = *d;
    pc->ce++;
    return 1;
}

int sacar_de_cola(T_cola* pc, T_dato* d)
{
    if(pc->ce == 0)
    {
        return 0;
    }
    *d = pc->vcola[pc->fr];
    pc->fr = (pc->fr+1)%TAM;
    pc->ce--;
    return 1;
}

int cola_vacia(const T_cola* pc)
{
    if(pc->ce == 0)
    {
        return 1;
    }
    return 0;
}
