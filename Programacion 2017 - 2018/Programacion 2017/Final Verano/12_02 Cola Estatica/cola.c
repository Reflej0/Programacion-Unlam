#include <stdio.h>
#include <stdlib.h>
#include "cola.h"

void crear_cola(T_cola* pc)
{
    pc->fr = 0;
    pc->fo = -1;
    pc->ce = -1;
}

int poner_en_cola(T_cola* pc, const T_dato* d)
{
    if(pc->ce == TAM-1)
    {
        return -1;
    }
    pc->fo = (pc->fo % TAM)+1;
    pc->vcola[pc->fo] = *d;
    pc->ce++;
    return 1;
}

int sacar_de_cola(T_cola* pc, T_dato* d)
{
    if(pc->ce == -1)
    {
        return -1;
    }
    *d = pc->vcola[pc->fr];
    pc->fr = (pc->fr % TAM)+1;
    pc->ce--;
    return 1;
}

int cola_vacia(const T_cola* pc)
{
    if(pc->ce == -1)
    {
        return 1;
    }
    return 0;
}
