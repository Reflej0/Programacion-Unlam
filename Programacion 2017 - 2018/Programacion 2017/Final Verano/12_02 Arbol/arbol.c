#include <stdio.h>
#include <stdlib.h>
#include "arbol.h"

void crear_arbol(T_arbol* pa)
{
    *pa = NULL;
}

int cmp(const void* e1, const void* e2)
{
    T_dato* d1 = (T_dato*)e1;
    T_dato* d2 = (T_dato*)e2;
    return *d1-*d2;
}

int buscar_en_arbol(const T_arbol* pa, T_dato* d, T_cmp cmp)
{
    if(!*pa)
    {
        return -1;
    }
    int comp = cmp(d, &(*pa)->info);
    if(comp == 0)
    {
        *d = (*pa)->info;
        return ENCONTRADO;
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
        T_nodo* nue = (T_nodo*)malloc(sizeof(T_nodo));
        nue->info = *d;
        nue->Hizq = NULL;
        nue->Hder = NULL;
        *pa = nue;
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
    return (hi>hd?hi:hd)+1;
}

void mostrar_arbol_pre(const T_arbol* pa)
{
    if(!*pa)
    {
        return;
    }
    printf("DATO:%d\n", (*pa)->info);
    mostrar_arbol_pre(&(*pa)->Hizq);
    mostrar_arbol_pre(&(*pa)->Hder);
}

void mostrar_arbol_in(const T_arbol* pa)
{
    if(!*pa)
    {
        return;
    }
    mostrar_arbol_in(&(*pa)->Hizq);
    printf("DATO:%d\n", (*pa)->info);
    mostrar_arbol_in(&(*pa)->Hder);
}

void mostrar_arbol_pos(const T_arbol* pa)
{
    if(!*pa)
    {
        return;
    }
    mostrar_arbol_pos(&(*pa)->Hizq);
    mostrar_arbol_pos(&(*pa)->Hder);
    printf("DATO:%d\n", (*pa)->info);
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
    return;
}

int eliminar_de_arbol(T_arbol* pa, T_dato* d, T_cmp cmp)
{
    T_nodo** nae = buscar_nodo(pa, d, cmp);
    if(!nae)
    {
        return NO_ENCONTRADO;
    }
    eliminar_nodo(nae);
    return VERDADERO;
}

T_nodo** buscar_nodo(T_arbol* pa, T_dato* d, T_cmp cmp)
{
    if(!*pa)
    {
        return NULL;
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
    if(!(*nae)->Hizq && !(*nae)->Hder)
    {
        free(*nae);
        *nae = NULL;
        return;
    }
    int hi = altura_arbol(&(*nae)->Hizq);
    int hd = altura_arbol(&(*nae)->Hder);
    T_nodo** nr = (hi>hd?mayor(&(*nae)->Hizq):menor(&(*nae)->Hder));
    (*nae)->info = (*nr)->info;
    eliminar_nodo(nr);
}

T_nodo** mayor(T_arbol* pa)
{
    if(!*pa || !(*pa)->Hder)
    {
        return pa;
    }
    return mayor(&(*pa)->Hder);
}

T_nodo** menor(T_arbol* pa)
{
    if(!*pa || !(*pa)->Hizq)
    {
        return pa;
    }
    return menor(&(*pa)->Hizq);
}

int es_arbol_completo(const T_arbol* pa)
{
    if(!*pa)
    {
        return VERDADERO;
    }
    int hi = altura_arbol(&(*pa)->Hizq);
    int hd = altura_arbol(&(*pa)->Hder);
    if(hi-hd!=0)
    {
        return FALSO;
    }
    return es_arbol_completo(&(*pa)->Hizq) && es_arbol_completo(&(*pa)->Hder);
}

int es_arbol_avl(const T_arbol* pa)
{
    if(!*pa)
    {
        return VERDADERO;
    }
    int hi = altura_arbol(&(*pa)->Hizq);
    int hd = altura_arbol(&(*pa)->Hder);
    if(abs(hi-hd)>1)
    {
        return FALSO;
    }
    return es_arbol_avl(&(*pa)->Hizq) && es_arbol_avl(&(*pa)->Hder);
}

int es_arbol_balanceado(const T_arbol* pa)
{
    int nivel = altura_arbol(pa) - 2;
    if(nivel < 0)
    {
        return VERDADERO;
    }
    return es_arbol_balanceado_hasta_nivel(pa, nivel);
}

int es_arbol_balanceado_hasta_nivel(const T_arbol* pa, int nivel)
{
    if(!*pa || nivel == 0)
    {
        return VERDADERO;
    }
    return es_arbol_balanceado_hasta_nivel(&(*pa)->Hizq, nivel-1) && es_arbol_balanceado_hasta_nivel(&(*pa)->Hder, nivel-1);
}

void podar_arbol_dde_nivel(T_arbol* pa, int nivel)
{
    if(!*pa)
    {
        return;
    }
    if(nivel == 0)
    {
        free(*pa);
        *pa = NULL;
        return;
    }
    podar_arbol_dde_nivel(&(*pa)->Hizq, nivel-1);
    podar_arbol_dde_nivel(&(*pa)->Hder, nivel-1);
}

int cargar_arbol_de_archivo_ord(T_arbol* pa, FILE* arch)
{
    long d, i;
    i = 0;
    fseek(arch, 0L, SEEK_END);
    d = (ftell(arch) / sizeof(T_dato))-1;
    return cargar_arbol_rec(pa, arch, i, d);
}

int cargar_arbol_rec(T_arbol* pa, FILE* arch, long i, long d)
{
    T_dato dato;
    if(i>d)
    {
        return 1;
    }
    long m = (i+d)/2;
    fseek(arch, m*sizeof(T_dato), SEEK_SET);
    fread(&dato, sizeof(T_dato), 1, arch);
    *pa = (T_nodo*)malloc(sizeof(T_nodo));
    (*pa)->Hizq = NULL;
    (*pa)->Hder = NULL;
    (*pa)->info = dato;
    int resp = cargar_arbol_rec(&(*pa)->Hizq, arch, i, m-1);
    if(resp != 1)
    {
        return resp;
    }
    else
    {
        return cargar_arbol_rec(&(*pa)->Hder, arch, m+1, d);
    }
}
