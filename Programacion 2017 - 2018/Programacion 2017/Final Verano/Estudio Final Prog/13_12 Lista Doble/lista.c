#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

int cmp(const void* n1, const void* n2)
{
    T_dato* d1 = (T_dato*)n1;
    T_dato* d2 = (T_dato*)n2;
    return (*d1)-(*d2);
}

void crear_lista(T_lista* lista)
{
    *lista = NULL;
}

int eliminar_valor_lista(T_lista* pl, T_dato* d, T_cmp cmp)
{
    T_nodo* elim = *pl;
    if(elim && cmp(d, &elim->info) < 0)
    {
        elim = elim->anterior;
    }
    if(elim && cmp(d, &elim->info) > 0)
    {
        elim = elim->siguiente;
    }
    if(!elim)
    {
        return 0;
    }
    if(elim == *pl)
    {
        if(elim->anterior)
        {
            *pl = elim->anterior;
        }
        else
        {
            *pl = elim->siguiente;
        }
    }
    else
    {
        if(elim->siguiente)
        {
            *pl = elim->siguiente;
        }
        else
        {
            *pl = elim->anterior;
        }
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
    T_nodo *act, *nue, *ant, *sig;
    if(!*pl)
    {
        nue = (T_nodo*)malloc(sizeof(T_nodo));
        nue->info = *d;
        nue->anterior = NULL;
        nue->siguiente = NULL;
        *pl = nue;
        return 1;
    }
    act = *pl;
    while(act && act->siguiente && cmp(d, &act->info) > 0)
    {
        act = act->siguiente;
    }
    while(act && act->anterior && cmp(d, &act->info) < 0)
    {
        act = act->anterior;
    }
    nue = malloc(sizeof(T_nodo));
    nue->info = *d;
    if(act && cmp(d, &act->info) > 0)
    {
        ant = act;
        sig = ant->siguiente;
    }
    else
    {
        sig = act;
        ant = sig->anterior;
    }
    nue->siguiente = sig;
    nue->anterior = ant;
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

int agregar_al_principio(T_lista* pl, T_dato* d)
{
    T_nodo* nue = (T_nodo*)malloc(sizeof(T_nodo));
    nue->info = *d;
    nue->anterior = NULL;
    if(!*pl)
    {

        nue->siguiente = NULL;
        *pl = nue;
        return 1;
    }
    else
    {
        nue->siguiente = *pl;
        *pl = nue;
        return 1;
    }
}


void ver_lista_desde_principio(T_lista* pl)
{
    if(!*pl)
    {
        return;
    }
    T_nodo* act = *pl;
    while(act && act->anterior)
    {
        act = act->anterior;
    }
    while(act)
    {
        printf("NUM: %d\n", act->info);
        act = act->siguiente;
    }
}

void ordenar_lista(T_lista* pl, T_cmp cmp)
{
    T_lista ordenada;
    crear_lista(&ordenada);
    if(!*pl)
    {
        return;
    }
    T_dato dato;
    while(eliminar_ultimo(pl, &dato) != 0)
    {
        agregar_ordenado(&ordenada, &dato, cmp);
    }
    *pl = ordenada;
}

int eliminar_primero(T_lista* pl, T_dato* d)
{
    if(!*pl)
    {
        return 0;
    }
    while((*pl)->anterior)
    {
        pl = &(*pl)->anterior;
    }
    *d = (*pl)->info;
    if((*pl)->siguiente)
    {
        pl = &(*pl)->siguiente;
        (*pl)->anterior = NULL;
        free((*pl)->anterior);
        return 1;
    }
    free(*pl);
    *pl = NULL;
    return 1;
}

int eliminar_ultimo(T_lista* pl, T_dato* d)
{
    if(!*pl)
    {
        return 0;
    }
    while((*pl)->siguiente)
    {
        pl = &(*pl)->siguiente;
    }
    *d = (*pl)->info;
    if((*pl)->anterior)
    {
        pl = &(*pl)->anterior;
        (*pl)->siguiente = NULL;
        free((*pl)->siguiente);
        return 1;
    }
    free(*pl);
    *pl = NULL;
    return 1;
}
