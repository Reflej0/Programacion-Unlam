#include <stdio.h>
#include <stdlib.h>
#include "arbol.h"

void crear_arbol(T_arbol* pa)
{
    *pa = NULL;
}

int cargar_arbol_de_arch(T_arbol* pa, FILE* arch)
{
    fseek(arch, 0L, SEEK_END);
    int i = 0;
    int d = (ftell(arch)/sizeof(T_dato)) -1;
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
    (*pa)->info = dato;
    (*pa)->Hizq = NULL;
    (*pa)->Hder = NULL;
    int comp;
    comp = cargar_arbol_rec(&(*pa)->Hizq, arch, i, m-1);
    if(comp != 1)
    {
        return comp;
    }
    else
    {
        return cargar_arbol_rec(&(*pa)->Hder, arch, m+1, d);
    }
}

int contar_nodos_totales(const T_arbol* pa)
{
    if(!*pa)
    {
        return 0;
    }
    else
    {
        return contar_nodos_totales(&(*pa)->Hizq) + contar_nodos_totales(&(*pa)->Hder) + 1;
    }

}

int contar_nodos_hojas(const T_arbol* pa)
{
    if(!*pa)
    {
        return 0;
    }
    if(!(*pa)->Hizq && !(*pa)->Hder)
    {
        return 1;
    }
    return contar_nodos_hojas(&(*pa)->Hizq) + contar_nodos_hojas(&(*pa)->Hder);
}

int contar_nodos_internos(const T_arbol* pa)
{
    if(!*pa)
    {
        return 0;
    }
    if(!(*pa)->Hizq && !(*pa)->Hder)
    {
        return 0;
    }
    return contar_nodos_internos(&(*pa)->Hizq) + contar_nodos_internos(&(*pa)->Hder)+1;
}
