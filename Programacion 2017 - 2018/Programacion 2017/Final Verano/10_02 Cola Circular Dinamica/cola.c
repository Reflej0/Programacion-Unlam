#include <stdio.h>
#include <stdlib.h>
#include "cola.h"

void crear_cola(T_cola* pc)
{
    *pc = NULL;
}

int acolar(T_cola* pc, T_dato* d)
{
    T_nodo* nue = (T_nodo*)malloc(sizeof(T_nodo));
    if(!nue)
    {
        return -1;
    }
    nue->info = *d;
    if(!*pc)
    {
        nue->siguiente = nue;
        *pc = nue;
        return 1;
    }
    else
    {
        nue->siguiente = (*pc)->siguiente;
        (*pc)->siguiente = nue;
        *pc = nue;
        return 1;
    }
}

int desacolar(T_cola* pc, T_dato* d)
{
    if(!*pc)
    {
        return 0;
    }
    if((*pc) == (*pc)->siguiente)
    {
        *d = (*pc)->info;
        free(*pc);
        *pc = NULL;
        return 1;
    }
    else
    {
        pc = &(*pc)->siguiente;
        T_nodo* nae = *pc;
        *d = nae->info;
        *pc = nae->siguiente;
        free(nae);
        return 1;
    }
}

int colaVacia(T_cola* pc)
{
    if(!*pc)
    {
        return 1;
    }
    return 0;
}
