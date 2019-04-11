#include <stdio.h>
#include <stdlib.h>
#include "arbol.h"

///COMPARACION
int cmp(const void* e1, const void* e2)
{
    T_dato* ele1 = (T_dato*)e1;
    T_dato* ele2 = (T_dato*)e2;
    return *ele1 - *ele2;
}

void crear_arbol(T_arbol* pa)
{
    *pa = NULL;
}

int buscar_en_arbol(const T_arbol* pa, T_dato* d, T_cmp cmp)
{
    if(!*pa)
    {
        return FALSO;
    }
    int comp = cmp(d, &(*pa)->info);
    if(comp == 0)
    {
        *d = (*pa)->info;
        return VERDADERO;
    }
    if(comp < 0)
    {
        return buscar_en_arbol(&(*pa)->Hizq, d, cmp);
    }
    else
    {
        return buscar_en_arbol(&(*pa)->Hder, d, cmp);
    }
}

int insertar_en_arbol(T_arbol* pa, const T_dato* d, T_cmp cmp)
{
    if(!*pa)
    {
        (*pa) = malloc(sizeof(T_nodo));
        (*pa)->info = *d;
        (*pa)->Hizq = NULL;
        (*pa)->Hder = NULL;
        return VERDADERO;
    }
    int comp = cmp(d, &(*pa)->info);
    if(comp == 0)
    {
        return DUPLICADO;
    }
    if(comp < 0)
    {
        return insertar_en_arbol(&(*pa)->Hizq, d, cmp);
    }
    else
    {
        return insertar_en_arbol(&(*pa)->Hder, d, cmp);
    }
}

int altura_arbol(const T_arbol* pa)
{
    if(!*pa)
    {
        return 0;
    }
    int hi = altura_arbol(&(*pa)->Hizq);
    int hd = altura_arbol(&(*pa)->Hder);
    return (hi > hd ? hi : hd) + 1;
}

void mostrar_arbol_pre(const T_arbol* pa)
{
    if(!*pa)
    {
        return;
    }
    printf("\n%d", (*pa)->info);
    mostrar_arbol_pre(&(*pa)->Hizq);
    mostrar_arbol_pre(&(*pa)->Hder);
}

void mostrar_arbol_in(const T_arbol* pa)
{
    if(!*pa)
    {
        return;
    }
    mostrar_arbol_pre(&(*pa)->Hizq);
    printf("\n%d", (*pa)->info);
    mostrar_arbol_pre(&(*pa)->Hder);
}

void mostrar_arbol_pos(const T_arbol* pa)
{
    if(!*pa)
    {
        return;
    }
    mostrar_arbol_pos(&(*pa)->Hizq);
    mostrar_arbol_pos(&(*pa)->Hder);
    printf("\n%d", (*pa)->info);
}

void eliminar_arbol(T_arbol* pa)
{
    if(!*pa)
    {
        return;
    }
    eliminar_arbol(&(*pa)->Hizq);
    eliminar_arbol(&(*pa)->Hder);
    free(*pa);
    *pa = NULL;
}

int eliminar_de_arbol(T_arbol* pa, T_dato* d, T_cmp cmp)
{
    T_nodo** nae = buscar_nodo(pa, d, cmp);
    if(!*nae)
    {
        return FALSO;
    }
    eliminar_nodo(nae);
    return VERDADERO;
}

T_nodo** buscar_nodo(T_arbol* pa, T_dato* d, T_cmp cmp)
{
    if(!*pa)
    {
        return FALSO;
    }
    int comp = cmp(d, &(*pa)->info);
    if(comp == 0)
    {
        return pa;
    }
    if(comp < 0)
    {
        return buscar_nodo(&(*pa)->Hizq, d, cmp);
    }
    else
    {
        return buscar_nodo(&(*pa)->Hder, d, cmp);
    }
}

void eliminar_nodo(T_arbol* nae)
{
    if((*nae)->Hizq == NULL && (*nae)->Hder == NULL)
    {
        free(*nae);
        *nae = NULL;
        return;
    }
    int hi = altura_arbol(&(*nae)->Hizq);
    int hd = altura_arbol(&(*nae)->Hder);
    T_nodo** nr = hi > hd ? mayor(&(*nae)->Hder) : menor(&(*nae)->Hizq);
    (*nae)->info = (*nr)->info;
    eliminar_nodo(nr);
}

T_nodo** mayor(T_arbol* pa)
{
    if(!*pa)
    {
        return pa;
    }
    return mayor(&(*pa)->Hder);
}

T_nodo** menor(T_arbol* pa)
{
    if(!*pa)
    {
        return pa;
    }
    return menor(&(*pa)->Hizq);
}
