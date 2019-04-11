#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

void mostrar_lista(T_lista* pl)
{
    if(!*pl)
    {
        return;
    }
    while(*pl)
    {
        printf("DATO: %d\n", (*pl)->info);
        pl = &(*pl)->siguiente;
    }
}

int cmp(const void* num, const void* num2)
{
    T_dato* n1 = (T_dato*)num;
    T_dato* n2 = (T_dato*)num2;
    return (*n1)-(*n2);
}

void crear_lista(T_lista* pl)
{
    *pl = NULL;
}

int agregar_principio(T_lista* pl, const T_dato* d)
{
    T_nodo* nue = (T_nodo*)malloc(sizeof(T_nodo));
    nue->info = *d;
    nue->siguiente = *pl;
    *pl = nue;
    return 1;
}

int agregar_final(T_lista* pl, const T_dato* d)
{
    T_nodo* nue = (T_nodo*)malloc(sizeof(T_nodo));
    nue->info = *d;
    nue->siguiente = NULL;
    if(!*pl)
    {
        (*pl) = nue;
        return 1;
    }
    while((*pl)->siguiente)
    {
        pl = &(*pl)->siguiente;
    }
    (*pl)->siguiente = nue;
    return 1;
}

int agregar_ordenado(T_lista* pl, const T_dato* d, T_cmp cmp)
{
    T_nodo* nue = (T_nodo*)malloc(sizeof(T_nodo));
    nue->info = *d;
    if(!*pl)
    {
        nue->siguiente = NULL;
        *pl = nue;
        return 1;
    }
    if(cmp(d, &(*pl)->info) < 0)
    {
        nue->siguiente = *pl;
        *pl = nue;
        return 1;
    }
    while((*pl)->siguiente && cmp(d, &(*pl)->siguiente->info) > 0)
    {
        pl = &(*pl)->siguiente;
    }
    nue->siguiente = (*pl)->siguiente;
    (*pl)->siguiente = nue;
    return 1;
}

int eliminar_principio(T_lista* pl, T_dato *d)
{
    if(!*pl)
    {
        return 0;
    }
    T_nodo* nae = *pl;
    *d = nae->info;
    *pl = nae->siguiente;
    free(nae);
    return 1;
}

int eliminar_ultimo(T_lista* pl, T_dato *d)
{
    if(!*pl)
    {
        return 0;
    }
    while(*pl && (*pl)->siguiente)
    {
        pl = &(*pl)->siguiente;
    }
    *d = (*pl)->info;
    free(*pl);
    *pl = NULL;
    return 1;
}

int eliminar_valor(T_lista* pl, const T_dato *d, T_cmp cmp)
{
    if(!*pl)
    {
        return 0;
    }
    ///PARCHE.
    if(*pl && cmp(d, &(*pl)->info) == 0)
    {
        T_nodo* nae = *pl;
        *pl = nae->siguiente;
        free(nae);
        return 1;
    }
    while(*pl && (*pl)->siguiente && cmp(d, &(*pl)->siguiente->info)>0)
    {
        pl = &(*pl)->siguiente;
    }
    if(cmp(d, &(*pl)->siguiente->info) != 0)
    {
        return -1; //NO ENCONTRADO;
    }
    T_nodo* nae = (*pl)->siguiente;
    (*pl)->siguiente = nae->siguiente;
    free(nae);
    return 1;
}

int eliminar_indice(T_lista* pl, T_dato *d, const int indice)
{
    if(!*pl || indice < 0)
    {
        return 0;
    }
    int i = 0;
    if(indice == 0)
    {
        T_nodo* nae = *pl;
        *d = nae->info;
        *pl = nae->siguiente;
        free(nae);
        return 1;
    }
    ///ME PARO UN LUGAR ANTES.
    while(*pl && (i < indice-1))
    {
        pl = &(*pl)->siguiente;
        i++;
    }
    if((*pl)->siguiente)
    {
        T_nodo* nae = (*pl)->siguiente;
        *d = nae->info;
        (*pl)->siguiente = nae->siguiente;
        free(nae);
        return 1;
    }
    else
    {
        free(*pl);
        *pl = NULL;
        return 1;

    }
}

void ordenar_lista(T_lista* pl, T_cmp cmp)
{
    T_lista* lista_ordenada = (T_lista*)malloc(sizeof(T_lista));
    crear_lista(lista_ordenada);
    T_dato aux;
    while(eliminar_principio(pl, &aux)!=0)
    {
        agregar_ordenado(lista_ordenada, &aux, cmp);
    }
    *pl = *lista_ordenada;
    return;
}

int cantidad_elementos(T_lista* pl)
{
    if(!*pl)
    {
        return -1;
    }
    int i = 0;
    while(*pl)
    {
        pl = &(*pl)->siguiente;
        i++;
    }
    return i;
}
