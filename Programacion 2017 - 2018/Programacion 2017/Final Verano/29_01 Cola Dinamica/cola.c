#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cola.h"

void crear_cola(T_cola *pc)
{
    pc->fr = NULL;
    pc->fo = NULL;
}

int poner_en_cola(T_cola *pc, T_dato *d)
{
    T_nodo* nue = (T_nodo*)malloc(sizeof(T_nodo));
    if(!nue)
    {
        return -1; //SIN MEMORIA.
    }
    nue->dato = *d;
    if(!pc->fr)
    {
        pc->fr = nue;
        pc->fo = nue;
        nue->siguiente = NULL;
        return 1;
    }
    else
    {
        pc->fo->siguiente = nue;
        nue->siguiente = pc->fo;
        pc->fo = nue;
        return 1;
    }
}

int cola_vacia(const T_cola *pc)
{
    if(!pc->fr)
    {
        return 1;
    }
    return 0;
}

int sacar_de_cola(T_cola *pc, T_dato *d)
{
    if(!pc->fr)
    {
        return 0;
    }
    *d = pc->fr->dato;
    if(pc->fr == pc->fo)
    {
        free(pc->fr);
        pc->fr = NULL;
        pc->fo = NULL;
        return 1;
    }
    else
    {
        T_nodo* nae = pc->fr;
        pc->fr = nae->siguiente;
        free(nae);
        nae = NULL;
        return 1;
    }
}
