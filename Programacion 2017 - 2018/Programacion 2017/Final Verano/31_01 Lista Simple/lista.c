#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

void crear_lista(T_lista* pl)
{
    *pl = NULL;
}

void mostrar_lista(T_lista* pl)
{
    if(!*pl)
    {
        return;
    }
    while(*pl)
    {
        printf("DATO: %d\n", (*pl)->dato);
        pl = &(*pl)->siguiente;
    }
}

int agregar_principio(T_lista* pl, const T_dato* d)
{
    T_nodo* nue = (T_nodo*)malloc(sizeof(T_nodo));
    if(!nue)
    {
        return -1;
    }
    nue->dato = *d;
    nue->siguiente = *pl;
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
    nue->dato = *d;
    nue->siguiente = NULL;
    if(!*pl)
    {
        *pl = nue;
        return 1;
    }
    else
    {
        while((*pl)->siguiente)
        {
            pl = &(*pl)->siguiente;
        }
        (*pl)->siguiente = nue;
        return 1;
    }
}

int cmp(const void* num, const void* num2)
{
    T_dato* n1 = (T_dato*)num;
    T_dato* n2 = (T_dato*)num2;
    return *n1-*n2;
}

int agregar_ordenado(T_lista* pl, const T_dato* d, T_cmp cmp)
{
    T_nodo* nue = (T_nodo*)malloc(sizeof(T_nodo));
    if(!nue)
    {
        return -1;
    }
    nue->dato = *d;
    if(!*pl)
    {
        nue->siguiente = NULL;
        *pl = nue;
        return 1;
    }
    if(cmp(d, &(*pl)->dato) < 0)
    {
        nue->siguiente = *pl;
        *pl = nue;
        return 1;
    }
    else
    {
        T_nodo* atras;
        T_nodo* act = *pl;
        while(act && cmp(d, &act->dato) > 0)
        {
            atras = act;
            act = act->siguiente;
        }
        atras->siguiente = nue;
        nue->siguiente = act;
        return 1;
    }
}

int eliminar_principio(T_lista* pl, T_dato *d)
{
    if(!*pl)
    {
        return -1;
    }
    T_nodo* nae = (T_nodo*)malloc(sizeof(T_nodo));
    nae = *pl;
    *pl = nae->siguiente;
    *d = nae->dato;
    free(nae);
    nae = NULL;
    return 1;
}

int eliminar_ultimo(T_lista* pl, T_dato *d)
{
    if(!*pl)
    {
        return 0;
    }
    while((*pl)->siguiente)
    {
        pl = &(*pl)->siguiente;
    }
    *d = (*pl)->dato;
    free(*pl);
    *pl = NULL;
    return 1;
}

int eliminar_valor(T_lista* pl, const T_dato *d, T_cmp cmp)
{
    if(!*pl)
    {
        return -1;
    }
    if(cmp(d, &(*pl)->dato)==0) // ELIMINAR EL PRIMERO.
    {
        T_nodo* nae = *pl;
        *pl = nae->siguiente;
        free(nae);
        return 1;
    }
    T_nodo* atras = *pl;
    while(*pl && cmp(d, &(*pl)->dato)!=0)
    {
        atras = *pl;
        pl = &(*pl)->siguiente;
    }
    if(cmp(d, &(*pl)->dato)==0)
    {
        T_nodo* nae = *pl;
        atras->siguiente = nae->siguiente;
        free(nae);
        return 1;
    }
    return 0;
}

int eliminar_indice(T_lista* pl, T_dato *d, const int indice)
{
    if(!*pl)
    {
        return -1;
    }
    if(indice == 0)
    {
        T_nodo* nae = *pl;
        *pl = nae->siguiente;
        free(nae);
        return 1;
    }
    else
    {
        int i = 0;
        T_nodo* atras;
        while(*pl && i<indice)
        {
            atras = *pl;
            pl = &(*pl)->siguiente;
            i++;
        }
        T_nodo* nae = *pl;
        atras->siguiente = nae->siguiente;
        free(nae);
        return 1;
    }
}

void ordenar_lista(T_lista* pl, T_cmp cmp)
{
    T_lista* l_ord = (T_lista*)malloc(sizeof(T_lista));
    crear_lista(l_ord);
    T_dato aux;
    while(eliminar_principio(pl, &aux) == 1)
    {
        agregar_ordenado(l_ord, &aux, cmp);
    }
    *pl = *l_ord;
}
