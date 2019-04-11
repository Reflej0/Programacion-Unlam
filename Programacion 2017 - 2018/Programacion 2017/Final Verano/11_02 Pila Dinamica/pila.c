#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

void crear_pila(T_pila* p)
{
    *p = NULL;
}

int poner_en_pila(T_pila* p, const T_dato* d)
{
    T_nodo* nue = (T_nodo*)malloc(sizeof(T_nodo));
    if(!nue)
        return 0;
    nue->info = *d;
    nue->sig = *p;
    *p = nue;
    return 1;
}

int ver_tope_de_pila(const T_pila* p, T_dato* d)
{
    if(!*p)
        return 0;
    *d = (*p)->info;
    return 1;
}

int sacar_de_pila(T_pila* p, T_dato* d)
{
    if(!*p)
        return 0;
    *d = (*p)->info;
    T_nodo* nae = *p;
    *p = nae->sig;
    free(nae);
    nae = NULL;
    return 1;
}

int pila_llena(const T_pila* p)
{
    T_nodo* nue = (T_nodo*)malloc(sizeof(T_nodo));
    if(!nue)
        return 1;
    free(nue);
    return 0;
}
