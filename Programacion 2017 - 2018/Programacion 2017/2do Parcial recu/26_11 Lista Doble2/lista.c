#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

int cmp(const void* n1, const void* n2)
{
    T_dato* d1 = (T_dato*) n1;
    T_dato* d2 = (T_dato*) n2;
    return (*d1)-(*d2);
}

void crear_lista(T_lista* lista)
{
    *lista = NULL;
}

int agregar_al_principio(T_lista* pl, T_dato* d)
{
    T_nodo* nue = (T_nodo*)malloc(sizeof(T_nodo));
    if(!nue)
    {
        return -1;
    }
    nue->info = *d; //Copio el dato.
    nue->anterior = NULL; // El anterior al primero siempre es null.
    ///Si la lista esta vacia.
    if(!*pl)
    {
        nue->siguiente = NULL;
    }
    else
    {
        nue->siguiente = *pl;
        (*pl)->anterior = nue;
    }
    *pl = nue; //El puntero de la lista ahora apunta a un nuevo primero.
    return 1;
}

int agregar_al_final(T_lista* pl, T_dato* d)
{
    T_nodo* nue = (T_nodo*)malloc(sizeof(T_nodo));
    if(!nue)
    {
        return -1;
    }
    nue->info = *d; //Copio el dato.
    nue->siguiente = NULL; //El siguiente al ultimo siempre va a ser null.
    ///Si la lista esta vacia.
    if(!*pl)
    {
        nue->anterior = NULL;
    }
    else
    {
        while((*pl)->siguiente)
        {
            pl = &(*pl)->siguiente;
        }
        nue->anterior = *pl;
        (*pl)->siguiente = nue;
    }
    *pl = nue;
    return 1;
}

int agregar_ordenado(T_lista* pl, T_dato* d, T_cmp cmp)
{
    T_nodo *nue, *act, *sig, *ant;
    nue = (T_nodo*)malloc(sizeof(T_nodo));
    nue->info = *d;
    ///Si la lista esta vacia.
    if(!*pl)
    {
        nue->anterior = NULL;
        nue->siguiente = NULL;
        *pl = nue;
        return 1;
    }
    act = *pl;
    while(act && act->siguiente && cmp(d, &act->info)>0)
    {
        act = act->siguiente;
    }
    while(act && act->anterior && cmp(d, &act->info)<0)
    {
        act = act->anterior;
    }
    if(act && cmp(d, &act->info)>0)
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

void ver_lista_desde_principio(T_lista* pl)
{
    if (!*pl)
    {
        return;
    }
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

int buscar_valor_lista(T_lista* pl, T_dato* d, T_cmp cmp)
{
    if(!*pl)
    {
        return 0;
    }
    while(*pl && (*pl)->anterior && cmp(d, &(*pl)->info) < 0)
    {
        pl = &(*pl)->anterior;
    }
    while(*pl && (*pl)->siguiente && cmp(d, &(*pl)->info) > 0)
    {
        pl = &(*pl)->siguiente;
    }
    if(*pl && cmp(d, &(*pl)->info) == 0)
    {
        *d = (*pl)->info;
        return 1;
    }
    return 0;
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

void ver_lista_desde_final(T_lista* pl)
{
    if (!*pl)
    {
        return;
    }
    while(*pl && (*pl)->siguiente)
    {
        pl = &(*pl)->siguiente;
    }
    while(*pl)
    {
        printf("%d\n", (*pl)->info);
        pl = &(*pl)->anterior;
    }
}

void eliminar_duplicados(T_lista* pl, T_cmp cmp)
{
    if (!*pl)
    {
        return;
    }
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
                return;
            }

        }
        act = act->siguiente;
        sig = act->siguiente;
    }
}
