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
    nue->info = *d;
    //Si es el primero.
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
    //El == porque son datos primitivos.
    if((*pc)->info == (*pc)->sig->info)
    {
        *d = (*pc)->info;
        free(*pc);
        *pc = NULL;
    }
    else
    {
        pc = &(*pc)->sig;
        T_nodo* nae = (*pc);
        *d = nae->info;
        *pc = (*pc)->sig;
        free(nae);
    }
    return 1;
}

int colaVacia(T_cola* pc)
{
    if(!*pc)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
