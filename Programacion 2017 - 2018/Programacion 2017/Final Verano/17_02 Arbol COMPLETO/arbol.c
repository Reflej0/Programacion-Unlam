#include <stdio.h>
#include <stdlib.h>
#include "arbol.h"

void crear_arbol(T_arbol* pa)
{
    *pa = NULL;
}

int cargar_arbol_de_archivo_ord(T_arbol* pa, FILE* arch)
{
    fseek(arch, 0L, SEEK_END);
    int i = 0;
    int d = (ftell(arch) / sizeof(T_dato))-1;
    return cargar_arbol_rec(pa, arch, i, d);
}

int cargar_arbol_rec(T_arbol* pa, FILE* arch, int i, int d)
{
    if(i>d)
    {
        return 1;
    }
    T_dato dt;
    long m = (i+d)/2;
    fseek(arch, sizeof(T_dato)*m, SEEK_SET);
    fread(&dt, sizeof(T_dato), 1, arch);
    *pa = (T_nodo*)malloc(sizeof(T_nodo));
    (*pa)->info = dt;
    (*pa)->Hizq = NULL;
    (*pa)->Hder = NULL;
    int resp;
    resp = cargar_arbol_rec(&(*pa)->Hizq, arch, i, m-1);
    if(resp != 1)
    {
        return resp;
    }
    else
    {
        return cargar_arbol_rec(&(*pa)->Hder, arch, m+1, d);
    }
}

int buscar_en_arbol(T_arbol* pa, T_dato* d, T_cmp cmp)
{
    if(!*pa)
    {
        return 0;
    }
    int comp = cmp(d, &(*pa)->info);
    if(comp == 0)
    {
        *d = (*pa)->info;
        return 1;
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
    printf("%d\n", (*pa)->info);
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
    printf("%d\n", (*pa)->info);
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
    printf("%d\n", (*pa)->info);
}

void eliminar_arbol(T_arbol *pa)
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

int eliminar_de_arbol(T_arbol* pa, const T_dato* d, T_cmp cmp)
{
    T_nodo** nae = buscar_nodo(pa, d, cmp);
    if(!nae)
    {
        return 0;
    }
    eliminar_nodo(nae);
    return 1;
}

T_nodo** buscar_nodo(T_arbol* pa, const T_dato* d, T_cmp cmp)
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

void eliminar_nodo(T_nodo** nae)
{
    if(!(*nae)->Hizq && !(*nae)->Hder)
    {
        free(*nae);
        *nae = NULL;
        return;
    }
    int hi = altura_arbol(&(*nae)->Hizq);
    int hd = altura_arbol(&(*nae)->Hizq);
    T_nodo** nr = (hi>hd?mayor(&(*nae)->Hizq):menor(&(*nae)->Hder));
    (*nae)->info = (*nr)->info;
    eliminar_nodo(nr);
}

T_nodo** mayor(T_arbol* pa)
{
    if(!*pa || &(*pa)->Hder)
    {
        return pa;
    }
    return mayor(&(*pa)->Hder);
}

T_nodo** menor(T_arbol* pa)
{
    if(!*pa || &(*pa)->Hizq)
    {
        return pa;
    }
    return mayor(&(*pa)->Hizq);
}

int es_arbol_completo(const T_arbol* pa)
{
    if(!*pa)
    {
        return 1;
    }
    int hi = altura_arbol(&(*pa)->Hizq);
    int hd = altura_arbol(&(*pa)->Hder);
    if(hi-hd != 0)
    {
        return 0;
    }
    return es_arbol_completo(&(*pa)->Hizq) && es_arbol_completo(&(*pa)->Hder);
}

int es_arbol_avl(const T_arbol* pa)
{
    if(!*pa)
    {
        return 1;
    }
    int hi = altura_arbol(&(*pa)->Hizq);
    int hd = altura_arbol(&(*pa)->Hder);
    if(abs(hi-hd) > 1)
    {
        return 0;
    }
    return es_arbol_avl(&(*pa)->Hizq) && es_arbol_avl(&(*pa)->Hder);
}

int es_arbol_balanceado(const T_arbol* pa)
{
    int n = altura_arbol(pa) - 2;
    if(n < 0)
    {
        return 1;
    }
    return es_arbol_balanceado_hasta_nivel(pa, n);
}

int es_arbol_balanceado_hasta_nivel(const T_arbol* pa, int nivel)
{
    if(!*pa || nivel == 0)
    {
        return 1;
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
        eliminar_arbol(pa);
        return;
    }
    podar_arbol_dde_nivel(&(*pa)->Hizq, nivel-1);
    podar_arbol_dde_nivel(&(*pa)->Hder, nivel-1);
    return;
}

int cant_nodos(T_arbol* pa)
{
    if(!*pa)
    {
        return 0;
    }
    return cant_nodos(&(*pa)->Hizq) + cant_nodos(&(*pa)->Hder)+1;
}

int cant_nodos_internos(T_arbol* pa)
{
    if(!*pa)
    {
        return 0;
    }
    if(!(*pa)->Hizq && !(*pa)->Hder)
    {
        return 0;
    }
    return cant_nodos_internos(&(*pa)->Hizq) + cant_nodos_internos(&(*pa)->Hder)+1;
}

int cant_hojas(T_arbol* pa)
{
    if(!*pa)
    {
        return 0;
    }
    if(!(*pa)->Hizq && !(*pa)->Hder)
    {
        return cant_hojas(&(*pa)->Hizq) + cant_hojas(&(*pa)->Hder)+1;
    }
    else
    {
        return cant_hojas(&(*pa)->Hizq) + cant_hojas(&(*pa)->Hder);
    }
}

int ver_arbol_y_nodos(T_arbol* pa, int i)
{
    ++i;
    if(!*pa)
    {
        return i-1;
    }
    printf("%d) %d\n", i, (*pa)->info);
    i = ver_arbol_y_nodos(&(*pa)->Hizq, i);
    i = ver_arbol_y_nodos(&(*pa)->Hder, i);
}
