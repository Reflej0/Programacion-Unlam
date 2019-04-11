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
    ///SI ES EL PRIMERO QUE AGREGO A LA COLA.
    if(!*pc)
    {
        nue->sig = nue;
        *pc = nue;
        return 1;
    }
    ///SI YA TENGO OTROS ELEMENTOS EN LA COLA.
    nue->sig = (*pc)->sig;
    (*pc)->sig = nue;
    *pc = nue;
    return 1;
}

int desacolar(T_cola* pc, T_dato* d)
{
    if(!*pc)
    {
        return 0;
    }
    ///SI ES EL UNICO DATO DE LA COLA>
    if(*pc == (*pc)->sig)
    {
        *d = (*pc)->info;
        (*pc)->sig = NULL;
        free(*pc);
        *pc = NULL;
        return 1;
    }
    ///OBTENGO EL FRENTE.
    pc = &(*pc)->sig;
    T_nodo* aux = *pc; //NODO A ELIMINAR, EL PRIMERO.
    *d = (*pc)->info;
    *pc = aux->sig;
    free(aux);
    return 1;

}

int verfrente(T_cola* pc, T_dato* d)
{
    if(!*pc)
    {
        return 0;
    }
    pc = &(*pc)->sig;
    *d = (*pc)->info;
    return 1;
}

int colaVacia(T_cola* pc)
{
    if(!*pc)
    {
        return 1;
    }
    return 0;
}

int colaLlena(T_cola* pc)
{
    T_nodo* aux = (T_nodo*)malloc(sizeof(T_nodo));
    if(!aux)
    {
        return 1;
    }
    free(aux);
    return 0;
}
