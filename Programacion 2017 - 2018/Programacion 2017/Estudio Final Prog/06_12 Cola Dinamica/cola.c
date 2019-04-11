#include <stdio.h>
#include <stdlib.h>
#include "cola.h"

void crear_cola(T_cola *pc)
{
    pc->fr = NULL;
    pc->fo = NULL;
}

int poner_en_cola(T_cola *pc, T_dato *d)
{
    T_nodo* nue = (T_nodo*)malloc(sizeof(T_nodo));
    nue->dato = *d;
    //SI ES EL PRIMERO.
    if(!pc->fr && !pc->fo)
    {
        nue->siguiente = pc->fo;
        pc->fr = nue;
        pc->fo = nue;
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

int ver_frente_de_cola(T_cola const *pc, T_dato *d)
{
    if(!pc->fr)
    {
        return 0;
    }
    *d = pc->fr->dato;
    return 1;
}

void vaciar_cola(T_cola *pc)
{
    if(!pc->fr && !pc->fo)
    {
        while(pc->fo)
        {
            T_nodo* nae = pc->fo;
            pc->fo = nae->siguiente;
            free(nae);
        }
        pc->fr = NULL;
    }
}

int cola_vacia(const T_cola *pc)
{
    if(!pc->fr && !pc->fo)
    {
        return 1;
    }
    return 0;
}

int sacar_de_cola(T_cola *pc, T_dato *d)
{
    if(!pc->fo && !pc->fr)
    {
        return 0;
    }
    if(pc->fr == pc->fo)
    {
        *d = pc->fr->dato;
        pc->fr = NULL;
        pc->fo = NULL;
        return 1;
    }
    else
    {
        T_nodo* nae = pc->fr;
        *d = nae->dato;
        pc->fr = nae->siguiente;
        free(nae);
        return 1;
    }
}
