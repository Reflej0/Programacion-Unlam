#include <stdio.h>
#include <stdlib.h>
#include "arbol.h"

int cmp(const void* e1, const void* e2)
{
    T_dato* d1 = (T_dato*)e1;
    T_dato* d2 = (T_dato*)e2;
    return (*d1)-(*d2);
}

void crear_arbol(T_arbol* pa)
{
    *pa = NULL;
}

int buscar_en_arbol(const T_arbol* pa, T_dato* d, T_cmp cmp)
{
    if(!*pa)
    {
        return ARBOL_VACIO;
    }
    int resp = cmp(d, &(*pa)->info);
    if(resp == 0)
    {
        *d = (*pa)->info;
        return ENCONTRADO;
    }
    if(resp < 0)
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
        *pa = (T_nodo*)malloc(sizeof(T_nodo));
        (*pa)->info = *d;
        (*pa)->Hizq = NULL;
        (*pa)->Hder = NULL;
    }
    int resp = cmp(d, &(*pa)->info);
    if(resp == 0)
    {
        return DUPLICADO;
    }
    if(resp < 0)
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
        return ARBOL_VACIO;
    }
    int hi = altura_arbol(&(*pa)->Hizq);
    int hd = altura_arbol(&(*pa)->Hder);
    return (hi > hd ? hi:hd)+1;
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
    int resp = cmp(d, &(*pa)->info);
    if(resp == 0)
    {
        *d = (*pa)->info;
        return pa;
    }
    if(resp < 0)
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
    T_nodo** nr = (hi > hd ? mayor(&(*nae)->Hizq) : menor(&(*nae)->Hder));
    (*nae)->info = (*nr)->info;
    eliminar_nodo(nr);
}

T_nodo** mayor(T_arbol* pa)
{
    if(!(*pa)->Hder)
    {
        return pa;
    }
    return mayor(&(*pa)->Hder);
}

T_nodo** menor(T_arbol* pa)
{
    if(!(*pa)->Hizq)
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
    if(hi-hd != 0)
    {
        return FALSO;
    }
    else
    {
        return es_arbol_completo(&(*pa)->Hizq) && es_arbol_completo(&(*pa)->Hder);
    }
}

int es_arbol_avl(const T_arbol* pa)
{
    if(!*pa)
    {
        return VERDADERO;
    }
    int hi = altura_arbol(&(*pa)->Hizq);
    int hd = altura_arbol(&(*pa)->Hder);
    if(abs(hi-hd) > 1)
    {
        return FALSO;
    }
    else
    {
        return es_arbol_avl(&(*pa)->Hizq) && es_arbol_avl(&(*pa)->Hder);
    }
}

int es_arbol_balanceado(const T_arbol* pa)
{
    int n = altura_arbol(pa) - 2;
    if(n<0)
    {
        return VERDADERO;
    }
    return es_arbol_balanceado_hasta_nivel(pa, n);
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
        eliminar_arbol(pa);
        return;
    }
    podar_arbol_dde_nivel(&(*pa)->Hizq, nivel-1);
    podar_arbol_dde_nivel(&(*pa)->Hder, nivel-1);
}

int cargar_arbol_de_archivo_ord(T_arbol* pa, FILE* arch)
{
    fseek(arch, 0L, SEEK_END);
    long i = 0;
    long d = (ftell(arch)/sizeof(T_dato))-1;
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
    int resp;
    resp = cargar_arbol_rec(&(*pa)->Hizq, arch, i, m-1);
    if(resp !=1)
    {
        return resp;
    }
    return cargar_arbol_rec(&(*pa)->Hder, arch, m+1, d);
}

int cargaAutomatica(T_arbol* pa, T_cmp cmp)
{
    //int arbol_nada[20]={22,15,3,8,40,45,13,20,30,1,7,34,48,53,9,23,12,51,4,10}; //No completo,no balanceado, no avl

    //int arbol_avl[7]={12,8,5,4,11,18,17}; //avl

    //int arbol_avl_bal[11]={50,17,12,9,14,23,19,72,76,54,67}; //balanceado,avl

    //int arbol_avl_bal_comp[7]={50,17,12,23,72,76,54}; //completo,balanceado,avl
    ///LA CARGA TIENE QUE SER ORDENADA.
    //ARBOL COMPLETO
    int arr[3]={11, 12, 10};
    int i=0;
    T_dato d;
    for(i=0;i<3;i++){
        d = arr[i];
        if(!insertar_en_arbol(pa,&d, cmp)){
            return 0;
        }
    }
    //ARBOL NO COMPLETO.
    /*int arr[9]={9,4,2,7,5,8,11,15,14};
    int i=0;
    T_dato d;
    for(i=0;i<9;i++){
        d = arr[i];
        if(!insertar_en_arbol_bin(pa,&d, cmp)){
            return 0;
        }
    }*/
    return 1;
}

void generarArchivoArbol(FILE* arch)
{
    //int arbol_nada[20]={22,15,3,8,40,45,13,20,30,1,7,34,48,53,9,23,12,51,4,10}; //No completo,no balanceado, no avl
    //int arbol_avl[7]={12,8,5,4,11,18,17}; //avl
    //int arbol_avl_bal[11]={50,17,12,9,14,23,19,72,76,54,67}; //balanceado,avl
    int arbol_avl_bal_comp[7]={12, 17, 23, 50, 54, 72, 76}; //completo,balanceado,avl
    unsigned i = 0;
    T_dato registro;
    for(i = 0; i < 7; i++)
    {
        registro = arbol_avl_bal_comp[i];
        fwrite(&registro, sizeof(T_dato), 1, arch);
    }
}
