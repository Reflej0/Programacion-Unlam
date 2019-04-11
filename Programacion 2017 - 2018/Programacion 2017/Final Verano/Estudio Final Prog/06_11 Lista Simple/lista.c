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
        printf("Dato:%d\n", (*pl)->dato);
        pl = &(*pl)->siguiente;
    }
}

int cmp(const void* num, const void* num2)
{
    T_dato* n1 = (T_dato*)num;
    T_dato* n2 = (T_dato*)num2;
    return (*n1-*n2);
}

void crear_lista(T_lista* pl)
{
    *pl = NULL;
}

int agregar_principio(T_lista* pl, const T_dato* d)
{
    T_nodo* nue = (T_nodo*)malloc(sizeof(T_nodo));
    nue->dato = *d;
    nue->siguiente = *pl;
    *pl = nue;
    return 1;
}

int agregar_final(T_lista* pl, const T_dato* d)
{
    T_nodo* nue = (T_nodo*)malloc(sizeof(T_nodo));
    nue->dato = *d;
    nue->siguiente = NULL;
    //SI ES EL PRIMER ELEMENTO.
    if(!*pl)
    {
        *pl = nue;
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
    T_nodo* atras;
    nue->dato = *d;
    //SI ES EL PRIMER ELEMENTO.
    if(!*pl)
    {
        nue->siguiente = NULL;
        *pl = nue;
        return 1;
    }
    //SI ES MENOR QUE EL PRIMERO.
    if(*pl && cmp(d, &(*pl)->dato) < 0)
    {
        nue->siguiente = *pl;
        *pl = nue;
        return 1;
    }
    while(*pl && cmp(d, &(*pl)->dato) > 0)
    {
        atras = *pl;
        pl = &(*pl)->siguiente;
    }
    nue->siguiente = *pl; // *pl = atras->siguiente.
    atras->siguiente = nue;
    return 1;
}

int eliminar_principio(T_lista* pl, T_dato *d)
{
    if(!*pl)
    {
        return 0;
    }
    T_nodo* nae = *pl;
    *d = nae->dato;
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
    *d = (*pl)->dato;
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
    if(*pl && cmp(d, &(*pl)->dato) == 0)
    {
        T_nodo* nae = *pl;
        *pl = nae->siguiente;
        free(nae);
        return 1;
    }
    while(*pl && (*pl)->siguiente && cmp(d, &(*pl)->siguiente->dato)>0)
    {
        pl = &(*pl)->siguiente;
    }
    if(cmp(d, &(*pl)->siguiente->dato) != 0)
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
        *pl= nae->siguiente;
        free(nae);
        nae = NULL;
        return 1;
    }
    while(i < indice-1 && (*pl)->siguiente)
    {
        pl = &(*pl)->siguiente;
        i++;
    }
    if(!(*pl)->siguiente)
    {
        return -1; // NO ENCONTRADO.
    }
    T_nodo* nae = (*pl)->siguiente;
    (*pl)->siguiente = nae->siguiente;
    free(nae);
    return 1;
}
