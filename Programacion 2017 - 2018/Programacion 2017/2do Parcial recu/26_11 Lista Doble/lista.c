#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

int cmp(const void* e1, const void* e2)
{
    T_dato* d1 = (T_dato*)e1;
    T_dato* d2 = (T_dato*)e2;
    return (*d1)-(*d2);
}

void crear_lista(T_lista* lista)
{
    *lista = NULL;
}

int agregar_ordenado(T_lista* pl, T_dato* d, T_cmp cmp)
{
    T_nodo *nue, *act, *sig, *ant;
    nue = (T_nodo*)malloc(sizeof(T_nodo));
    nue->info = *d;
    ///SI LA LISTA NO TIENE ELEMENTOS LA INSERCION ES NORMAL.
    if(!*pl)
    {
        nue->anterior = NULL;
        nue->siguiente = NULL;
        *pl = nue;
        return 1;
    }
    act = *pl;
    while(act && act->siguiente && cmp(d, &(act)->info) > 0)
    {
        act = act->siguiente;
    }
    while(act && act->anterior && cmp(d, &(act)->info) < 0)
    {
        act = act->anterior;
    }
    if(act && cmp(d, &(act->info)) > 0)
    {
        ant = act;
        sig = ant->siguiente;
    }
    else
    {
        sig = act;
        ant = sig->siguiente;
    }
    nue->anterior = ant;
    nue->siguiente = sig;
    if(ant)
    {
        ant->siguiente = nue;
    }
    if(sig)
    {
        sig->anterior = nue;
    }
    *pl = nue;
    return 1;
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
