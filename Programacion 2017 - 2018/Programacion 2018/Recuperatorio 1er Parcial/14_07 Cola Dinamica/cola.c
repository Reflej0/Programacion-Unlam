#include <stdio.h>
#include <stdlib.h>
#include "auxiliar.h"
#include "cola.h"

void crear_cola(T_cola* pc)
{
    pc->inicio = NULL;
    pc->fin = NULL;
}

int acolar(T_cola* pc, const T_dato* d)
{
    T_nodo* nue = (T_nodo*)malloc(sizeof(T_nodo));
    if(!nue) return 0; //MEMORIA LLENA.
    nue->info = *d;
    if(!pc->inicio)
    {
        pc->inicio = nue;
        pc->fin = nue;
        return 1;
    }
    pc->fin->sig = nue;
    pc->fin = nue;
    return 1;
}

int desacolar(T_cola* pc, T_dato* d)
{
    if(!pc->inicio) return 0; //COLA VACIA.
    *d = pc->inicio->info;
    if(pc->inicio == pc->fin)
    {
        free(pc->inicio);
        pc->inicio = pc->fin = NULL;
        return 1;
    }
    T_nodo* nae = pc->inicio;
    pc->inicio = pc->inicio->sig;
    free(nae);
    return 1;
}

int ver_frente(const T_cola* pc, T_dato* d)
{
    if(!pc->inicio) return 0; //COLA VACIA.
    *d = pc->inicio->info;
    return 1;
}

void vaciar_cola(T_cola* pc)
{
    if(!pc->inicio) return;
    T_nodo* nae;
    while(pc->inicio != pc->fin)
    {
        nae = pc->inicio;
        pc->inicio = pc->inicio->sig;
        free(nae);
    }
    free(nae);
    pc->inicio = pc->fin = NULL;
    return;
}

int esta_vacia_cola(const T_cola* pc)
{
    return (!pc->inicio) ? 1 : 0;
}

int esta_llena_cola(const T_cola* pc)
{
    T_nodo* nue = (T_nodo*)malloc(sizeof(T_nodo));
    if(!nue) return 1; //ESTA LLENA.
    free(nue);
    return 0;
}
