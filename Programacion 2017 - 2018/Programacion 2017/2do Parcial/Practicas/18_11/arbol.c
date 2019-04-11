#include <stdio.h>
#include <stdlib.h>
#include "arbol.h"

void crear_arbol(T_arbol* pa)
{
    *pa = NULL;
}
///CORRECTO
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
///CORRECTO
int insertar_en_arbol(T_arbol* pa, const T_dato* d, T_cmp cmp)
{
    if(!*pa)
    {
        *pa = malloc(sizeof(T_nodo));
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
///CORRECTO
int altura_arbol(const T_arbol* pa)
{
    if(!*pa)
    {
        return 0;
    }
    int hi = altura_arbol(&(*pa)->Hizq);
    int hd = altura_arbol(&(*pa)->Hder);
    return (hi > hd ? hi : hd)+1;
}
///CORRECTO
void mostrar_arbol_pre(const T_arbol* pa)
{
    if(!*pa)
    {
        return;
    }
    printf("%d", (*pa)->info);
    return mostrar_arbol_pre(&(*pa)->Hizq);
    return mostrar_arbol_pre(&(*pa)->Hder);
}
///CORRECTO
void mostrar_arbol_in(const T_arbol* pa)
{
    if(!*pa)
    {
        return;
    }
    return mostrar_arbol_in(&(*pa)->Hizq);
    printf("%d", (*pa)->info);
    return mostrar_arbol_in(&(*pa)->Hder);
}
///CORRECTO
void mostrar_arbol_pos(const T_arbol* pa)
{
    if(!*pa)
    {
        return;
    }
    return mostrar_arbol_pos(&(*pa)->Hizq);
    return mostrar_arbol_pos(&(*pa)->Hder);
    printf("%d", (*pa)->info);
}
///CORRECTO
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
///VIENDO PSEUDO
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
///VIENDO PSEUDO
T_nodo** buscar_nodo(T_arbol* pa, T_dato* d, T_cmp cmp)
{
    if(!*pa)
    {
        return FALSO;
    }
    int comp = cmp(d, &(*pa)->info);
    if(comp == 0)
    {
        *d = (*pa)->info;
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
///VIENDO PSEUDO
void eliminar_nodo(T_arbol* nae)
{
    ///HOJA.
    if((*nae)->Hizq == NULL && (*nae)->Hder == NULL)
    {
        free(*nae);
        *nae = NULL;
        return;
    }
    int hi = altura_arbol(&(*nae)->Hizq);
    int hd = altura_arbol(&(*nae)->Hder);
    T_nodo** nr = hi > hd ? mayor(&(*nae)->Hizq) : menor(&(*nae)->Hder);
    (*nae)->info = (*nr)->info;
    eliminar_nodo(nr);
}
///CORRECTO
T_nodo** mayor(T_arbol* pa)
{
    if(!*pa)
    {
        return pa;
    }
    return mayor(&(*pa)->Hder);
}
///CORRECTO
T_nodo** menor(T_arbol* pa)
{
    if(!*pa)
    {
        return pa;
    }
    return menor(&(*pa)->Hizq);
}
///VIENDO PSEUDO
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
    else
    {
        return (es_arbol_completo(&(*pa)->Hizq) && es_arbol_completo(&(*pa)->Hder));
    }
}
///VIENDO PSEUDO
int es_arbol_avl(const T_arbol* pa)
{
    if(!*pa)
    {
        return VERDADERO;
    }
    int hi = altura_arbol(&(*pa)->Hizq);
    int hd = altura_arbol(&(*pa)->Hder);
    if(hi-hd>1)
    {
        return FALSO;
    }
    else
    {
        return (es_arbol_avl(&(*pa)->Hizq) && es_arbol_avl(&(*pa)->Hder));
    }
}
///VIENDO PSEUDO
int es_arbol_balanceado(const T_arbol* pa)
{
    int n = altura_arbol(pa)-2;
    if(n<0)
    {
        return VERDADERO;
    }
    return es_arbol_completo_hasta_nivel(pa, n);
}
///VIENDO PSEUDO
int es_arbol_completo_hasta_nivel(const T_arbol* pa, int nivel)
{
    if(!*pa || nivel == 0)
    {
        return VERDADERO;
    }
    return es_arbol_completo_hasta_nivel(&(*pa)->Hizq, nivel-1) && es_arbol_completo_hasta_nivel(&(*pa)->Hder, nivel-1);
}
///VIENDO PSEUDO
void podar_arbol_dde_nivel(T_arbol* pa, int nivel)
{
    if(!*pa)
    {
        return;
    }
    if(nivel == 0)
    {
        eliminar_arbol(pa);
        *pa = NULL;
    }
    podar_arbol_dde_nivel(&(*pa)->Hizq, nivel-1);
    podar_arbol_dde_nivel(&(*pa)->Hder, nivel-1);
}
