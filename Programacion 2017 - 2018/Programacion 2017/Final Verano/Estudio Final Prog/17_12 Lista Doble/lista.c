#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

int cmp(const void* n1, const void* n2)
{
    T_dato* num1 = (T_dato*)n1;
    T_dato* num2 = (T_dato*)n2;
    return (*num1)-(*num2);
}

void crear_lista(T_lista* lista)
{
    *lista = NULL;
}

int agregar_ordenado(T_lista* pl, T_dato* d, T_cmp cmp)
{
    if(!*pl)
    {
        T_nodo* nue = (T_nodo*)malloc(sizeof(T_nodo));
        nue->info = *d;
        nue->anterior = NULL;
        nue->siguiente = NULL;
        *pl = nue;
        return 1;
    }
    T_nodo *act, *nue, *sig, *ant;
    act = *pl;
    while(act && act->siguiente && cmp(d, &act->info) > 0)
    {
        act = act->siguiente;
    }
    while(act && act->anterior && cmp(d, &act->info) < 0)
    {
        act = act->anterior;
    }
    nue = (T_nodo*)malloc(sizeof(T_nodo));
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
    nue->anterior = ant;
    nue->siguiente = sig;
    if(sig)
    {
        sig->anterior = nue;
    }
    if(ant)
    {
        ant->siguiente = nue;
    }
    *pl = nue;
    return 1;
}

void ver_lista_desde_principio(T_lista* pl)
{
    if(!*pl)
    {
        return;
    }
    T_nodo* act = *pl;
    while(act->anterior)
    {
        act = act->anterior;
    }
    while(act)
    {
        printf("NUM: %d\n", act->info);
        act = act->siguiente;
    }
}

int eliminar_valor_lista(T_lista* pl, T_dato* d, T_cmp cmp)
{
    T_nodo* elim = *pl;
    while(elim && cmp(d, &elim->info) < 0)
    {
        elim = elim->anterior;
    }
    while(elim && cmp(d, &elim->info) > 0)
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

int eliminar_primero(T_lista* pl, T_dato* d)
{
    if(!*pl)
    {
        return 0;
    }
    T_nodo* elim = *pl;
    *d = elim->info;
    if(elim->siguiente)
    {
        *pl = elim->siguiente;
    }
    else
    {
        *pl = NULL;
    }
    free(elim);
    return 1;
}

int agregar_al_principio(T_lista* pl, T_dato* d)
{
    T_nodo* nue = (T_nodo*)malloc(sizeof(T_nodo));
    nue->info = *d;
    nue->anterior = NULL;
    nue->siguiente = *pl;
    *pl = nue;
    return 1;
}

void ordenar_lista(T_lista* pl, T_cmp cmp)
{
    T_lista* lista_ord = (T_lista*)malloc(sizeof(T_lista));
    crear_lista(lista_ord);
    T_dato dato;
    while(eliminar_primero(pl, &dato)!=0)
    {
        agregar_ordenado(lista_ord, &dato, cmp);
    }
    *pl = *lista_ord;
    return;
}

void eliminar_duplicados(T_lista* pl, T_cmp cmp)
{
    if(!*pl)
    {
        return;
    }
    T_nodo* act = *pl;
    T_nodo* sig = act->siguiente;;
    while(act->anterior)
    {
        act = act->anterior;
    }
    while(act)
    {
        while(sig && cmp(&act->info, &sig->info) == 0)
        {
            if(sig->siguiente)
            {
                act->siguiente = sig->siguiente;
                sig->siguiente->anterior = act;
                free(sig);
                sig = act->siguiente;
            }
            else
            {
                act->siguiente = NULL;
                free(sig);
                return;
            }
        }
        act = act->siguiente;
        sig = act->siguiente;
    }
}
