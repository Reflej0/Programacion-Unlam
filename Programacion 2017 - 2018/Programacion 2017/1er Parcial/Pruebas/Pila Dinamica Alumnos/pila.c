#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

void crear_pila(T_pila* pp)
{
    *pp = NULL;
}

int apilar(T_pila *pp, const T_dato *d)
{
    T_nodo* nue = malloc(sizeof(T_nodo));
    if(!nue)
    {
        return 1; //Memoria llena.
    }
    nue->dato = *d;
    nue->siguiente = *pp;
    *pp = nue;
    return 0; // OK.
}

int desapilar(T_pila *pp, T_dato *d)
{
    if(!*pp)
    {
        return 1; //Pila vacia.
    }
    T_nodo* nae = *pp;
    *d = nae->dato;
    *pp = nae->siguiente;
    free(nae);
    return 0; //OK.
}

int ver_tope(T_pila *pp, T_dato *d)
{
    if(!*pp)
    {
        return 1; //Pila vacia.
    }
    *d = (*pp)->dato;
    return 0;
}

int pila_llena(T_pila *pp)
{
    T_nodo* nue = malloc(sizeof(T_nodo));
    if(!nue)
    {
        return 1; //Memoria llena.
    }
    free(nue);
    return 0; //OK.
}

int pila_vacia(T_pila *pp)
{
    if(!*pp)
    {
        return 1; //Pila vacia.
    }
    return 0;
}

void vaciar_pila(T_pila *pp)
{
    while(!*pp)
    {
        T_nodo* nae = *pp;
        *pp = nae->siguiente;
        free(nae);
    }
}
