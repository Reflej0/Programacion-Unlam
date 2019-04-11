#include <stdlib.h>
#include <stdio.h>
#include "pila.h"

void crear_pila(T_pila* p)
{
    *p = NULL;
}

int apilar(T_pila* p, const T_dato* d)
{
    T_nodo* nue = malloc(sizeof(T_nodo));
    if(!nue) return 0; //ERROR.
    nue->sig = *p;
    nue->d = *d;
    *p = nue;
    return 1;
}

int desapilar(T_pila* p, T_dato* d)
{
    if(!*p) return 0; //PILA VACIA.
    *d = (*p)->d;
    T_nodo* nae = *p;
    *p = nae->sig;
    free(nae);
    return 1;
}

int pila_vacia(const T_pila* p)
{
    if(!*p) return 1;
    return 0;
}
