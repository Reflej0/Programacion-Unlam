#include <stdio.h>
#include <stdlib.h>
#include "cola.h"

void crear_cola(T_cola* c)
{
    c->frente = NULL;
    c->fondo = NULL;
}

int acolar(T_cola* c, const T_dato* d)
{
    T_nodo *nue = malloc(sizeof(T_nodo));
    if(!nue)
    {
        return 1; //Memoria llena.
    }
    nue->dato = *d;
    nue->siguiente = NULL;
    if(!c->frente)
    {
        c->frente = nue;
    }
    else
    {
        c->fondo->siguiente = nue;
    }
    c->fondo = nue;
    return 0;
}

int desacolar(T_cola* c, T_dato* d)
{
    if(!c->frente)
    {
        return 1; //Cola vacia.
    }
    T_nodo* nae = c->frente;
    c->frente = nae->siguiente;
    free(nae);
    if(!c->frente)
    {
        c->fondo = NULL;
    }
    return 0;
}

int ver_frente(const T_cola *c, T_dato *d)
{
    if(!c->frente)
    {
        return 1; //Cola vacia.
    }
    *d = c->frente->dato;
    return 0;
}
