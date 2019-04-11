#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

void crear_lista(T_lista* pl)
{
    *pl = NULL;
}

int agregar_principio(T_lista* pl, const T_dato* d)
{
    T_nodo* nue = (T_nodo*)malloc(sizeof(T_nodo));
    if(!nue)
    {
        return -1;
    }
    nue->info = *d;
    nue->sig = *pl;
    *pl = nue;
    return 1;
}

int agregar_final(T_lista* pl, const T_dato* d)
{
    T_nodo* nue = (T_nodo*)malloc(sizeof(T_nodo));
    if(!nue)
    {
        return -1;
    }
    nue->info = *d;
    nue->sig = NULL;
    if(!*pl)
    {
        *pl = nue;
        return 1;
    }
    T_nodo* act = *pl;
    while(act && act->sig)
    {
        act = act->sig;
    }
    act->sig = nue;
    return 1;
}

void mostrar_lista(const T_lista* pl)
{
    if(!*pl)
    {
        return;
    }
    T_nodo* act = *pl;
    while(act)
    {
        printf("DATO: %d\n", act->info);
        act = act->sig;
    }
}

int agregar_ordenado(T_lista* pl, const T_dato* d, T_cmp comp)
{
    T_nodo* nue = (T_nodo*)malloc(sizeof(T_nodo));
    if(!nue)
    {
        return -1;
    }
    nue->info = *d;
    if(!*pl)
    {
        nue->sig = NULL;
        *pl = nue;
        return 1;
    }
    else
    {
        T_nodo* act = *pl;
        if(comp(d, &act->info) <= 0)
        {
            nue->sig = *pl;
            *pl = nue;
            return 1;
        }
        else
        {
            T_nodo* atras;
            while(act->sig && comp(d, &act->info) >= 0)
            {
                atras = act;
                act = act->sig;
            }
            if(!act->sig && comp(d, &act->info) >= 0)
            {
                act->sig = nue;
                nue->sig = NULL;
                return 1;
            }
            else
            {
                atras->sig = nue;
                nue->sig = act;
                return 1;
            }
        }
    }
}

int eliminar_principio(T_lista* pl, T_dato* d)
{
    if(!*pl)
    {
        return 0;
    }
    T_nodo* nae = *pl;
    *d = nae->info;
    *pl = nae->sig;
    free(nae);
    nae = NULL;
    return 1;
}

void ordenar_lista(T_lista* pl, T_cmp comp)
{
    T_lista* l_ord = (T_lista*)malloc(sizeof(T_lista));
    crear_lista(l_ord);
    T_dato d;
    while(eliminar_principio(pl, &d) != 0)
    {
        agregar_ordenado(l_ord, &d, comp);
    }
    *pl = *l_ord;
}
