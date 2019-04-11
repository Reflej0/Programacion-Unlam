#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

void crear_pila(T_pila *p)
{
    *p = NULL;
}

int apilar(T_pila *p, const T_dato *dato)
{
    T_nodo *nue = malloc(sizeof(T_nodo));
    if(!nue)
    {
        return 1; //Memoria llena.
    }
    nue->dato = *dato;
    nue->siguiente = *p;
    *p = nue;
    return 0;
}

int desapilar(T_pila *p, T_dato *dato)
{
    if(!*p)
    {
        return 1; // Pila vacia.
    }
    T_nodo *nae = *p;
    *dato = (*p)->dato;
    *p = nae->siguiente;
    free(nae);
    return 0;
}

int ver_tope(const T_pila *p, T_dato *dato)
{
    if(!*p)
    {
        return 1; // Pila vacia.
    }
    *dato = (*p)->dato;
    return 0;
}

void vaciar_pila(T_pila *p)
{
    while(*p)
    {
    T_nodo *nae = *p;
    *p = nae->siguiente;
    free(nae);
    }
}

int pila_vacia(T_pila *p)
{
    if(!*p)
    {
        return 0; // Pila vacia.
    }
    return 1; // Pila no vacia.
}
