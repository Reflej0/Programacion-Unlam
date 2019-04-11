#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

void crear_lista(T_lista* lista)
{
    *lista = NULL;
}

int cmp(const void* n1, const void* n2)
{
    T_dato* e1 = (T_dato*)n1;
    T_dato* e2 = (T_dato*)n2;
    return *e1-*e2;
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
        printf("DATO:%d\n", act->info);
        act = act->siguiente;
    }
}

int agregar_ordenado(T_lista* pl, T_dato* d, T_cmp cmp)
{
    T_nodo* nue = (T_nodo*)malloc(sizeof(T_nodo));
    nue->info = *d;
    if(!*pl)
    {
        nue->anterior = NULL;
        nue->siguiente = NULL;
        *pl = nue;
        return 1;
    }
    T_nodo* act = *pl;
    if(cmp(d, &act->info) <= 0)
    {
        nue->siguiente = act;
        nue->anterior = NULL;
        act->anterior = nue;
        *pl = nue;
        return 1;
    }
    else
    {
        while(act->siguiente && cmp(d, &act->info) >= 0)
        {
            act = act->siguiente;
        }
        if(cmp(d, &act->info) > 0 && !act->siguiente)
        {
            nue->siguiente = NULL;
            nue->anterior = act;
            act->siguiente = nue;
            return 1;
        }
        else
        {
            nue->siguiente = act;
            nue->anterior = act->anterior;
            act->anterior->siguiente = nue;
            act->anterior = nue;
            return 1;
        }
    }
}

int eliminar_valor_lista(T_lista* pl, T_dato* d, T_cmp cmp)
{
    if(!*pl)
    {
        return -1;
    }
    T_nodo* act = *pl;
    if(!act->siguiente && cmp(d, &act->info) == 0)
    {
        *d = act->info;
        free(*pl);
        *pl = NULL;
        return 1;
    }
    if(act->siguiente && cmp(d, &act->info) == 0)
    {
        *d = act->info;
        act->siguiente->anterior = NULL;
        *pl = act->siguiente;
        free(act);
        return 1;
    }
    else
    {
        while(act->siguiente && cmp(d, &act->info) != 0)
        {
            act = act->siguiente;
        }
        if(cmp(d, &act->info) == 0 && !act->siguiente)
        {
            act->anterior->siguiente = NULL;
            free(act);
            return 1;
        }
        if(cmp(d, &act->info) == 0 && act->siguiente)
        {
            act->anterior->siguiente = act->siguiente;
            act->siguiente->anterior = act->anterior;
            free(act);
            return 1;
        }
        return 0;
    }
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
        (*pl)->anterior = nue;
        *pl = nue;
        return 1;
    }
}

int eliminar_primero(T_lista* pl, T_dato* d)
{
    if(!*pl)
    {
        return -1;
    }
    T_nodo* act = *pl;
    if(!act->siguiente)
    {
        *d = act->info;
        free(*pl);
        *pl = NULL;
        return 1;
    }
    else
    {
        *d = act->info;
        act->siguiente->anterior = NULL;
        *pl = act->siguiente;
        free(act);
        return 1;
    }
}

void ordenar_lista(T_lista* pl, T_cmp cmp)
{
    T_lista* l_ord = (T_lista*)malloc(sizeof(T_lista));
    crear_lista(l_ord);
    T_dato d;
    while(eliminar_primero(pl, &d) != -1)
    {
        agregar_ordenado(l_ord, &d, cmp);
    }
    *pl = *l_ord;
}

void eliminar_duplicados(T_lista* pl, T_cmp cmp)
{
    if(!*pl || !(*pl)->siguiente)
    {
        return;
    }
    else
    {
        T_nodo* act = *pl;
        T_nodo* sig = act->siguiente;
        while(act && sig)
        {
            while(cmp(&act->info, &sig->info) == 0)
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
                    sig = NULL;
                }
            }
            act = act->siguiente;
            sig = act->siguiente;
        }
    }
}
