#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

void crear_pila(T_pila *p)
{
    *p = NULL;
}

int poner_en_pila(T_pila *p, const T_dato *d)
{
    T_nodo* nue = (T_nodo*)malloc(sizeof(T_nodo));
    if(!nue)
    {
        return -1; // SIN MEMORIA;
    }
    nue->dato = *d;
    nue->siguiente = *p;
    *p = nue;
    return 1;
}

int sacar_de_pila(T_pila *p, T_dato *d)
{
    if(!*p)
    {
        return 0; // PILA VACIA.
    }
    T_nodo* nae = *p;
    *d = nae->dato;
    *p = nae->siguiente;
    free(nae);
    return 1;
}

int pila_vacia(const T_pila *p)
{
    if(!*p)
    {
        return 1;
    }
    return 0;
}

int pila_llena(const T_pila *p)
{
    T_nodo* nue = (T_nodo*)malloc(sizeof(T_nodo));
    if(!nue)
    {
        return 1;
    }
    free(nue);
    return 0;
}

int ver_tope_de_pila(const T_pila *p, T_dato *d)
{
    if(!*p)
    {
        return 0;
    }
    *d = (*p)->dato;
    return 1;
}

void vaciar_pila(T_pila *p)
{
    if(!*p)
    {
        return;
    }
    T_nodo *nae = *p;
    *p = nae->siguiente;
    vaciar_pila(p);
}
