#include <stdio.h>
#include <stdlib.h>
#include "cola.h"

void crear_cola(T_cola* pc)
{
    pc->frente = NULL;
    pc->fondo = NULL;
}

int poner_en_cola(T_cola* pc, const T_dato* d)
{
    T_nodo* nue = (T_nodo*)malloc(sizeof(T_nodo));
    nue->info = *d;
    if(!pc->frente)
    {
        nue->sig = NULL;
        pc->frente = nue;
        pc->fondo = nue;
        return 1;
    }
    else
    {
        pc->fondo->sig = nue;
        nue->sig = NULL;
        pc->fondo = nue;
        return 1;
    }
}

int sacar_de_cola(T_cola* pc, T_dato* d)
{
    if(!pc->frente)
    {
        return 0;
    }
    *d = pc->frente->info;
    T_nodo* nae = pc->frente;
    pc->frente = nae->sig;
    free(nae);
    if(pc->frente == NULL || pc->fondo == NULL)
    {
        pc->frente  = NULL;
        pc->fondo = NULL;
    }
    return 1;
}

int cola_vacia(T_cola* pc)
{
    if(pc->frente == NULL || pc->fondo == NULL)
    {
        return 1;
    }
    return 0;
}
