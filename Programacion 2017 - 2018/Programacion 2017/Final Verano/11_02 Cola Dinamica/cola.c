#include <stdio.h>
#include <stdlib.h>
#include "cola.h"

void crear_cola(T_cola* c)
{
    c->fr = NULL;
    c->fo = NULL;
}

int poner_en_cola(T_cola* c, const T_dato* d)
{
    T_nodo* nue = (T_nodo*)malloc(sizeof(T_nodo));
    if(!nue)
    {
        return -1;
    }
    nue->info = *d;
    if(!c->fr)
    {
        nue->sig = NULL;
        c->fr = nue;
        c->fo = nue;
        return 1;
    }
    else
    {
        c->fo->sig = nue;
        nue->sig = c->fo;
        c->fo = nue;
        return 1;
    }
}

int sacar_de_cola(T_cola* c, T_dato* d)
{
    if(!c->fr)
    {
        return -1;
    }
    if(c->fr == c->fo)
    {
        *d = c->fr->info;
        free(c->fr);
        c->fr = NULL;
        c->fo = NULL;
        return 1;
    }
    else
    {
        T_nodo* nae = c->fr;
        *d = nae->info;
        c->fr = nae->sig;
        free(nae);
        return 1;
    }

}

int cola_vacia(const T_cola* c)
{
    if(!c->fr)
    {
        return 1;
    }
    return 0;
}
