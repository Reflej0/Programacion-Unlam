#include <stdio.h>
#include <stdlib.h>
#include "auxiliares.h"
#include "lista.h"

int cmp_dato(const void* a, const void* b)
{
    T_dato a_ = *(T_dato*)a;
    T_dato b_ = *(T_dato*)b;
    return a_.clave - b_.clave;
}

void show(const void* a)
{
    printf("Clave: %d\nDNI: %d\n", ((T_dato*)a)->clave, ((T_dato*)a)->dni);
}

void mostrar_lista(const T_lista* l, T_show show)
{
    if(!*l) return;
    while(*l)
    {
        show(&(*l)->info);
        l = &(*l)->sig;
    }
}

void crear_lista(T_lista* l)
{
    *l = NULL;
}

int agregar_al_principio(T_lista* l,  const T_dato* d)
{
    T_nodo* nue = (T_nodo*)malloc(sizeof(T_nodo));
    if(!nue) return 0;
    nue->info = *d;
    nue->sig = *l;
    *l = nue;
    return 1;
}

int agregar_al_final(T_lista* l,  const T_dato* d)
{
    while(*l)
        l = &(*l)->sig;
    *l = (T_nodo*)malloc(sizeof(T_nodo));
    if(!*l) return 0;
    (*l)->info = *d;
    (*l)->sig = NULL;
    return 1;
}

int agregar_ordenado(T_lista* l,  const T_dato* d, T_cmp cmp)
{
    while(*l && cmp(d, &(*l)->info)>0)
        l = &(*l)->sig;
    if(*l && cmp(d, &(*l)->info) == 0)
        return -1;
    T_nodo* nue = (T_nodo*)malloc(sizeof(T_nodo));
    if(!nue) return 0;
    nue->info = *d;
    nue->sig = (*l) ? (*l)->sig : NULL;
    *l = nue;
    return 1;
}

int eliminar_principio(T_lista* l,  T_dato* d)
{
    if(!*l) return 0;
    *d = (*l)->info;
    T_nodo* nae = *l;
    (*l) = nae->sig;
    free(nae);
    return 1;
}

int eliminar_final(T_lista* l,  T_dato* d)
{
    if(!*l) return 0;
    while(*l && (*l)->sig)
        l = &(*l)->sig;
    free(*l);
    *l = NULL;
    return 1;
}

int eliminar_info(T_lista* l,  T_dato* d, T_cmp cmp)
{
    if(!*l) return 0;
    while(*l && cmp(d, &(*l)->info)!=0)
        l = &(*l)->sig;
    while(cmp(d, &(*l)->info)!=0)
        return -1;
    T_nodo* nae = *l;
    *l = nae->sig;
    free(nae);
    return 1;
}

void eliminar_todos_elementos_lista(T_lista* l)
{
    while(*l)
    {
        T_nodo* e = *l;
        *l = e->sig;
        free(e);
    }
}

void ordenar_lista(T_lista* l, T_cmp cmp)
{
    if(!*l || !(*l)->sig) return;
    T_nodo** menor;
    while(*l)
    {
        menor = l;
        menor = buscar_menor(l, cmp);
        if(l!=menor)
            _swap(l, menor);
        l = &(*l)->sig;
    }
}

T_nodo** buscar_menor(const T_lista* l, T_cmp cmp)
{
    T_nodo** menor = (T_nodo**)l;
    while(*l)
    {
        if(cmp(&(*menor)->info, &(*l)->info) > 0)
            menor = (T_nodo**)l;
        l = &(*l)->sig;
    }
    return menor;
}

void _swap(T_nodo** a, T_nodo** b)
{
    T_nodo* aux;
    aux = *b;
    *b = aux->sig;
    aux->sig = *a;
    *a = aux;
}
