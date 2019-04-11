#include <stdio.h>
#include <stdlib.h>
#include "cola.h"

void crear_cola(T_cola* pc)
{
    pc->fr = NULL;
    pc->fo = NULL;
}

int poner_en_cola(T_cola* pc, const T_dato* d)
{
    T_nodo* nue = (T_nodo*)malloc(sizeof(T_nodo));
    nue->info = *d;
    if(!pc->fr && !pc->fo)
    {
        pc->fr = nue;
        pc->fo = nue;
        return 1;
    }
    else
    {
        pc->fo->sig = nue;
        nue->sig = pc->fo;
        pc->fo = nue;
        return 1;
    }
}

int sacar_de_cola(T_cola* pc, T_dato *d)
{
    if(!pc->fr && !pc->fo)
    {
        return 0;
    }
    if(pc->fr == pc->fo)
    {
        *d = pc->fr->info;
        free(pc->fr);
        pc->fr = pc->fo = NULL;
        return 1;
    }
    else
    {
        *d = pc->fr->info;
        T_nodo* nae = pc->fr;
        pc->fr = nae->sig;
        free(nae);
        return 1;
    }
}

int cola_vacia(const T_cola* pc)
{
    if(!pc->fr)
    {
        return 1;
    }
    return 0;
}
