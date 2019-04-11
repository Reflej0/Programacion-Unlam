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
    if(!nue) return 0; //MEMORIA LLENA.
    nue->info = *d;
    if(!*pc)
    {
        nue->sig = nue; //SI ES EL PRIMERO SE APUNTA A SI MISMO.
        *pc = nue;
        return 1;
    }
    nue->sig = (*pc)->sig;
    (*pc)->sig = nue;
    *pc = nue;
    return 1;
}

int desacolar(T_cola* pc, T_dato* d)
{
    if(!*pc) return 0; //COLA VACIA.
    T_nodo* nae = (*pc)->sig;
    (*pc)->sig = nae->sig;
    if(nae == *pc) *pc = NULL;
    free(nae);
    return 1;
}

int ver_frente(const T_cola* pc, T_dato* d)
{
    if(!*pc) return 0; //COLA VACIA.
    *d = (*pc)->sig->info;
    return 1;
}

void vaciar_cola(T_cola* pc)
{
    if(!*pc) return;
    T_nodo* nae = (*pc)->sig;
    while(nae != *pc)
    {
        (*pc)->sig = nae->sig;
        free(nae);
        nae = (*pc)->sig;
    }
    free(*pc);
    *pc = NULL;
}

int esta_cola_llena(const T_cola* pc)
{
    T_nodo* nue = (T_nodo*)malloc(sizeof(T_nodo));
    if(!nue) return 1;
    free(nue);
    return 0;
}

int esta_cola_vacia(const T_cola* pc)
{
    return (!*pc) ? 1 : 0;
}
