#include <stdio.h>
#include <stdlib.h>
#include "cola.h"

void crear_cola(T_cola* pc)
{
    *pc = NULL;
}

int acolar(T_cola* pc, const T_dato* d)
{
    T_nodo* nue = (T_nodo*)malloc(sizeof(T_nodo));
    nue->info = *d;
    if(!*pc)
    {
        nue->sig = nue;
        *pc = nue;
        return 1;
    }
    else
    {
        nue->sig = (*pc)->sig;
        (*pc)->sig = nue;
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
    if((*pc) == (*pc)->sig)
    {
        *d = (*pc)->info;
        free(*pc);
        *pc = NULL;
        return 1;
    }
    else
    {
        T_nodo* nae = (*pc)->sig;
        *d = nae->info;
        (*pc)->sig = nae->sig;
        free(nae);
        return 1;
    }
}

int colaVacia(const T_cola* pc)
{
    if(!*pc)
    {
        return 1;
    }
    return 0;
}
