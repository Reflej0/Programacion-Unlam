#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

int cmp(const void* n1, const void* n2)
{
    T_dato* num1 = (T_dato*) n1;
    T_dato* num2 = (T_dato*) n2;
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
    T_nodo *act, *nue, *ant, *sig;
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
        sig = act->siguiente;
    }
    else
    {
        sig = act;
        ant = act->anterior;
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
        *pl = elim->anterior;
    }
    else
    {
        *pl = elim->siguiente;
        //PARCHE.
        if(!elim->siguiente)
        {
            *pl = elim->anterior;
        }
    }
    if(elim->siguiente)
    {
        elim->siguiente->anterior = elim->anterior;
    }
    if(elim->anterior)
    {
        elim->anterior->siguiente = elim->siguiente;
    }
    free(elim);
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
        printf("DATO: %d\n", act->info);
        act = act->siguiente;
    }
}
