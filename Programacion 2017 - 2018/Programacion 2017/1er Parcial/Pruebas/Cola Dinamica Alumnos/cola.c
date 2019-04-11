#include <stdio.h>
#include <stdlib.h>
#include "cola.h"

void crear_cola(T_cola* pc)
{
    pc->frente = NULL;
    pc->fondo = NULL;
}

int acolar(T_cola* pc, const T_dato* d)
{
    T_nodo* nue = malloc(sizeof(T_nodo));
    if(!nue)
    {
        return 1; //Memoria llena.
    }
    nue->dato = *d;
    nue->siguiente = NULL;
    if(!(pc->frente)) // Si no hay nada en el fondo, osea es el primer elemento que acolo.
    {
        pc->frente = nue;
    }
    else
    {
        pc->fondo->siguiente = nue;
    }
    pc->fondo = nue;
    return 0;
}

int desacolar(T_cola* pc, T_dato* d)
{
    if(!(pc->fondo))
    {
        return 1; //Cola vacia.
    }
    T_nodo *nae = pc->frente;
    *d = nae->dato;
    pc->frente = nae->siguiente;
    free(nae);
    return 0;
}

int ver_frente(const T_cola* pc, T_dato* d)
{
    if(!(pc->fondo))
    {
        return 1; //Cola vacia.
    }
    *d = pc->frente->dato;
    return 0;
}

