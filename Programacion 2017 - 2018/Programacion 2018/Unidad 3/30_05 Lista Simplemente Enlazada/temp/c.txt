#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

int comp_dato(const void* a, const void* b)
{
    return *(T_dato*)a - *(T_dato*)b;
}

void crear_lista(T_lista* l)
{
    *l = NULL;
}

///Si deseo mostrar el T_dato de alguna forma especial o es struct y deseo mostrar solo algunos campos.
void mostrar_dato(const T_dato* d)
{
    printf("Dato: %d\n", *d);
}

///Mostrar el dato pasado por parametro con la leyenda dato repetido.
void tratamiento(const T_dato* d)
{
    printf("Dato repetido: %d\n", *d);
}

void mostrar_lista(const T_lista* l, T_show show)
{
    while(*l)
    {
        show(&(*l)->d);
        l = &(*l)->sig;
    }
}

int agregar_al_principio(T_lista* l, const T_dato* d)
{
    T_nodo* n = (T_nodo*)malloc(sizeof(T_nodo));
    if(!n)
        return FALSO;
    n->d = *d;
    n->sig = *l;
    *l = n;
    return VERDADERO;
}

int agregar_al_final(T_lista* l, const T_dato* d)
{
    while(*l)
    {
        l = &(*l)->sig;
    }
    *l = (T_nodo*)malloc(sizeof(T_nodo));
    if(!*l)
        return FALSO;
    (*l)->d = *d;
    (*l)->sig = NULL;
    return VERDADERO;
}

int agregar_en_pos(T_lista* l, const T_dato* d, int pos)
{
    ///El usuario no puede ingresar en una posicion negativa o cero. La primera posicion es 1.
    if(pos<=0)
        return FALSO;
    while(*l && pos>0)
    {
        l = &(*l)->sig;
        pos--;
    }
    if(pos != 1)
        return FALSO;
    *l = (T_nodo*)malloc(sizeof(T_nodo));
    if(!*l)
        return FALSO;
    (*l)->d = *d;
    (*l)->sig = NULL;
    return VERDADERO;
}

int agregar_ordenado_duplicados(T_lista* l, const T_dato* d, T_cmp comp)
{
    while(*l && comp(d, &(*l)->d) >0)
    {
        l = &(*l)->sig;
    }
    T_nodo* n = (T_nodo*)malloc(sizeof(T_nodo));
    if(!n)
        return FALSO;
    n->d = *d;
    n->sig = *l;
    *l = n;
    return VERDADERO;
}

int agregar_ordenado_no_duplicados(T_lista* l, const T_dato* d, T_cmp comp, T_do hacer)
{
    int resultado ;
    while(*l && (resultado = comp(d, &(*l)->d)) >0)
    {
        l = &(*l)->sig;
    }
    if(*l && resultado == 0)
    {
        hacer(&(*l)->d); ///Si quiero hacer un tratamiento con el dato duplicado de la lista.
        return FALSO;
    }
    T_nodo* n = (T_nodo*)malloc(sizeof(T_nodo));
    if(!n)
        return FALSO;
    n->d = *d;
    n->sig = *l;
    *l = n;
    return VERDADERO;
}

int eliminar_del_principio(T_lista* l, T_dato* d)
{
    if(!*l)
        return FALSO;
    T_nodo* e = *l;
    *l = e->sig;
    free(e);
    return VERDADERO;
}

int eliminar_del_final(T_lista* l, T_dato* d)
{
    if(!*l)
        return FALSO;
    while(*l && (*l)->sig)
    {
        l = &(*l)->sig;
    }
    *l = NULL;
    free(*l);
    return VERDADERO;
}

int eliminar_segun_pos(T_lista* l, T_dato* d, int pos)
{
    ///El usuario no puede ingresar en una posicion negativa o cero. La primera posicion es 1.
    if(pos<=0)
        return FALSO;
    while(*l && pos>1)
    {
        l = &(*l)->sig;
        pos--;
    }
    if(pos >1 || !*l)
        return FALSO;
    T_nodo* e = *l;
    *l = e->sig;
    free(e);
    return VERDADERO;
}

int eliminar_segun_comp(T_lista* l, T_dato* d, T_cmp cmp)
{
    if(!*l)
        return FALSO;
    int resultado;
    while(*l && (resultado = cmp(d, &(*l)->d)) != 0)
    {
        l = &(*l)->sig;
    }
    if(resultado != 0)
        return FALSO;
    T_nodo* e = *l;
    *l = e->sig;
    free(e);
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

int buscar_por_posicion(const T_lista* l, T_dato* d, int pos)
{
    if(!*l || pos <=0)
        return FALSO;
    while(*l && pos>1)
    {
        l = &(*l)->sig;
        pos--;
    }
    if(pos!=1 || !*l)
        return FALSO;
    *d = (*l)->d;
    return VERDADERO;
}

int buscar_por_comp(const T_lista* l, T_dato* d, T_cmp cmp)
{
    if(!*l)
        return FALSO;
    int resultado;
    while(*l && (resultado = cmp(d, &(*l)->d)) != 0)
    {
        l = &(*l)->sig;
    }
    if(resultado != 0)
        return FALSO;
    *d = (*l)->d;
    return 1;
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