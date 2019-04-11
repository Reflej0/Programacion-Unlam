#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

int cmp(const void* e1, const void* e2)
{
    T_dato* d1 = (T_dato*) e1;
    T_dato* d2 = (T_dato*) e2;
    return (*d1)-(*d2);
}

void crear_lista(T_lista* lista)
{
    *lista = NULL;
}

void ver_lista_desde_principio(T_lista* pl)
{
    while(*pl && (*pl)->anterior)
    {
        pl = &(*pl)->anterior;
    }
    while(*pl)
    {
        printf("%d\n", (*pl)->info);
        pl = &(*pl)->siguiente;
    }
}

int buscar_valor_lista(T_lista* pl, T_dato* d, T_cmp cmp)
{
    if(!*pl)
    {
        return 0;
    }
    int comp = cmp(d, &(*pl)->info);
    if(comp < 0 && (*pl)->anterior)
    {
        pl = &(*pl)->anterior;
        comp = cmp(d, &(*pl)->info);
    }
    if(comp > 0 && (*pl)->siguiente)
    {
        pl = &(*pl)->siguiente;
        comp = cmp(d, &(*pl)->info);
    }
    if(comp == 0)
    {
        *d = (*pl)->info;
        return 1;
    }
    return -1;
}

int eliminar_valor_lista(T_lista* pl, T_dato* d, T_cmp cmp)
{
    T_nodo* elim = *pl;
    while(elim && cmp(d, &(elim)->info) < 0)
    {
        elim = elim->anterior;
    }
    while(elim && cmp(d, &(elim)->info) > 0)
    {
        elim = elim->siguiente;
    }
    if(!elim)
    {
        return 0;
    }
    if(elim == *pl)
    {
        *pl = elim->anterior;
    }
    else
    {
        *pl = elim->siguiente;
    }
    if(elim->anterior)
    {
        elim->anterior->siguiente = elim->siguiente;
    }
    if(elim->siguiente)
    {
        elim->siguiente->anterior = elim->anterior;
    }
    free(elim);
    return 1;
}

int agregar_ordenado(T_lista* pl, T_dato* d, T_cmp cmp)
{
    T_nodo *nuevo, *act, *ant, *sig;
    act = *pl;

    if(!*pl)
    {
        nuevo = (T_nodo*)malloc(sizeof(T_nodo));
        nuevo->info = *d;
        nuevo->siguiente = nuevo->anterior = NULL;
        *pl = nuevo;
        return 1;
    }
    while(act && act->siguiente && cmp(d, &(act)->info) > 0)
    {
        act = act->siguiente;
    }
    while(act && act->anterior && cmp(d, &(act)->info) < 0)
    {
        act = act->anterior;
    }

    nuevo = (T_nodo*)malloc(sizeof(T_nodo));
    nuevo->info = *d;
    if(act && cmp(d, &(act)->info) > 0)
    {
        ant = act;
        sig = ant->siguiente;
    }
    else
    {
        sig = act;
        ant = sig->siguiente;
    }

    nuevo->anterior = ant;
    nuevo->siguiente = sig;

    if(ant)
    {
        ant->siguiente = nuevo;
    }
    if(sig)
    {
        sig->anterior = nuevo;
    }
    *pl = nuevo;
    return 1;
}
