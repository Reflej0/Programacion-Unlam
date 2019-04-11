#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

void crear_lista(T_lista* pl)
{
    *pl = NULL;
}

void ver_lista_desde_principio(const T_lista* pl)
{
    if(!*pl)
    {
        return;
    }
    T_nodo* act = *pl;
    while(act->ant)
    {
        act = act->ant;
    }
    while(act)
    {
        printf("%d\n", act->info);
        act = act->sig;
    }
}

int agregar_ordenado(T_lista* pl, const T_dato* d, T_cmp cmp)
{
    T_nodo* nue = (T_nodo*)malloc(sizeof(T_nodo));
    if(!nue)
    {
        return -1;
    }
    nue->info = *d;
    ///SI LA LISTA ESTA VACIA.
    if(!*pl)
    {
        nue->ant = NULL;
        nue->sig = NULL;
        *pl = nue;
        return 1;
    }
    T_nodo* act = *pl;
    ///SI EL ELEMENTO QUE VOY A AGREGAR ES MENOR QUE EL PRIMERO DE LA LISTA.
    if(cmp(d, &act->info) <= 0)
    {
        nue->ant = NULL;
        nue->sig = act;
        act->ant = nue;
        *pl = nue;
        return 1;
    }
    ///BIFURCACIONES.
    else
    {
        while(act->sig && cmp(d, &act->info) >= 0)
        {
            act = act->sig;
        }
        ///EL ELEMENTO QUE VOY A AGREGAR ES MAYOR QUE EL ULTIMO DE LA LISTA.
        if(!act->sig && cmp(d, &act->info) >= 0)
        {
            nue->sig = NULL;
            nue->ant = act;
            act->sig = nue;
            return 1;
        }
        ///EL ELEMENTO QUE VOY A AGREGAR ESTA EN EL MEDIO.
        else
        {
            nue->sig = act;
            nue->ant = act->ant;
            act->ant->sig = nue;
            act->ant = nue;
            return 1;
        }
    }
}

int eliminar_valor_lista(T_lista* pl, T_dato* d, T_cmp cmp)
{
    if(!*pl)
    {
        return 0;
    }
    T_nodo* act = *pl;
    ///UNICO ELEMENTO DE LA LISTA.
    if(!act->sig)
    {
        free(*pl);
        *pl = NULL;
        return 1;
    }
    ///QUIZA LA LISTA NO ESTA ORDENADA POR ESO EL !=
    while(act->sig && cmp(d, &act->info)!=0)
    {
        act = act->sig;
    }
    ///SI EL ELEMENTO A ELIMINAR ES EL ULTIMO.
    if(!act->sig && cmp(d, &act->info) == 0)
    {
        act->ant->sig = NULL;
        free(act);
        return 1;
    }
    /// SI EL ELEMENTO A ELIMINAR ESTA EN EL MEDIO.
    if(act->sig && cmp(d, &act->info) == 0)
    {
        act->ant->sig = act->sig;
        act->sig->ant = act->ant;
        free(act);
        return 1;
    }
    return 0;
}

int agregar_al_principio(T_lista* pl, const T_dato* d)
{
    T_nodo* nue = (T_nodo*)malloc(sizeof(T_nodo));
    if(!nue)
    {
        return -1;
    }
    nue->info = *d;
    nue->ant = NULL;
    if(!*pl)
    {
        nue->sig = NULL;
    }
    else
    {
        nue->sig = *pl;
    }
    *pl = nue;
    return 1;
}

int eliminar_al_principio(T_lista* pl, T_dato* d)
{
    if(!*pl)
    {
        return 0;
    }
    T_nodo* act = *pl;
    *d = act->info;
    if(!act->sig)
    {
        free(*pl);
        *pl = NULL;
        return 1;
    }
    else
    {
        *pl = act->sig;
        (*pl)->ant = NULL;
        free(act);
        return 1;
    }
}

void ordenar_lista(T_lista* pl, T_cmp cmp)
{
    T_lista* l_ord = (T_lista*)malloc(sizeof(T_lista));
    crear_lista(l_ord);
    T_dato d;
    while(eliminar_al_principio(pl,&d)!=0)
    {
        agregar_ordenado(l_ord, &d, cmp);
    }
    *pl = *l_ord;
}

void eliminar_duplicados(T_lista* pl, T_cmp cmp)
{
    if(!*pl)
    {
        return;
    }
    T_nodo* act = *pl;
    if(!act->sig)
    {
        return;
    }
    T_nodo* sig = act->sig;
    while(act && sig)
    {
        while(cmp(&act->info, &sig->info) == 0)
        {
            if(sig->sig)
            {
                act->sig = sig->sig;
                sig->sig->ant = act;
            }
            else
            {
                act->sig = NULL;
            }
            free(sig);
            sig = act->sig;
        }
        act = act->sig;
        sig = act->sig;
    }
}
