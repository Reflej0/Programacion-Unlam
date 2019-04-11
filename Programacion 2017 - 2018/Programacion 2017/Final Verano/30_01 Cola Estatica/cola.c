#include <stdio.h>
#include <stdlib.h>
#include "cola.h"

void crear_cola(T_cola* pc)
{
    pc->fr = -1;
    pc->fo = -1;
    pc->ce = 0;
}

int poner_en_cola(T_cola* pc, T_dato* d)
{
    if(pc->ce == TAM)
    {
        return -1; //COLA LLENA.
    }
    if(pc->fr == -1)
    {
        pc->fr++;
    }
    pc->ce++;
    pc->fo = (pc->fo+1)%TAM;
    pc->vcola[pc->fo] = *d;
    return 1;
}

int frente_de_cola(T_cola* pc, T_dato* d)
{
    if(pc->ce == 0)
    {
        return -1; //COLA VACIA.
    }
    *d = pc->vcola[pc->fr];
    return 1;
}

int sacar_de_cola(T_cola* pc, T_dato* d)
{
    if(pc->ce == 0)
    {
        return -1; //COLA VACIA.
    }
    pc->ce--;
    *d = pc->vcola[pc->fr];
    pc->vcola[pc->fr] = 0;
    pc->fr = (pc->fr+1)%TAM;
    return 1;
}

void vaciar_cola(T_cola* pc)
{
    pc->fr = 0;
    pc->fo = -1;
    pc->ce = 0;
}

int cola_vacia(T_cola* pc)
{
    if(pc->ce == 0)
    {
        return 1; //COLA VACIA.
    }
    return 0;
}
