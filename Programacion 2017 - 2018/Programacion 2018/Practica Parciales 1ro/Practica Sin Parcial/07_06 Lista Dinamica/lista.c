#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

void crear_lista(T_lista* l)
{
    *l = NULL;
}

int agregar_al_principio(T_lista* l, const T_dato* d)
{
    T_nodo* nue = malloc(sizeof(T_nodo));
    if(!nue)
        return -1;
    nue->d = *d;
    nue->sig = *l;
    *l = nue;
    return 1;
}

void mostrar_normal(const void* a)
{
    printf("Dato: %d\n", ((T_nodo*)a)->d);
}

int comp_int(const void* a, const void* b)
{
    return (*(T_dato*)a-*(T_dato*)b);
}

void mostrar_lista(const T_lista* l, T_show show)
{
    while(*l)
    {
        mostrar_normal(*l);
        l = &(*l)->sig;
    }
}

void intercambiar(T_nodo** a, T_nodo** b)
{
    T_nodo* aux;
    aux = *b;
    *b = aux->sig;
    aux->sig = *a;
    *a = aux;
}

T_nodo** buscarMenor(T_lista* l, T_cmp comp)
{
    if(!(*l)->sig)
        return l;
    T_nodo** menor = &(*l)->sig;
    while(*l)
    {
        if(comp(&(*l)->d, &(*menor)->d) < 0)
            menor = l;
        l = &(*l)->sig;
    }
    return menor;
}

void ordenar_lista(T_lista* l, T_cmp comp)
{
    T_nodo** menor;
    while(*l)
    {
        menor = l;
        menor = buscarMenor(l, comp);
        if(l != menor)
            intercambiar(l, menor);
        l = &(*l)->sig;
    }
}
