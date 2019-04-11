#include <stdio.h>
#include <stdlib.h>
#include "arbol.h"

int contar_nodos_internos(T_arbol *pa)
{
    if (*pa==NULL)
        {
            return 0;
        }
        if (((*pa)->Hder ==NULL)&&((*pa)->Hizq ==NULL))
        {
               return 0;

        }
        else
        {
            return (contar_nodos_internos(&(*pa)->Hizq) + contar_nodos_internos(&(*pa)->Hder) + 1);
        }
}

int cant_nodos_hoja(T_arbol* pa)
{
    if(!*pa)
    {
        return 0;
    }
    if(*pa && (*pa)->Hizq == NULL && (*pa)->Hder == NULL)
    {
        return 1;
    }
    return cant_nodos_hoja(&(*pa)->Hizq) + cant_nodos_hoja(&(*pa)->Hder);
}

int podar_arbol_dde_nivel_cant_nodos(T_arbol* pa, int nivel)
{
    int cant_nodos_anterior = cant_nodos(pa);
    podar_arbol_dde_nivel(pa, nivel);
    int cant_nodos_nueva = cant_nodos(pa);
    return cant_nodos_anterior-cant_nodos_nueva;
}

int cant_nodos(T_arbol* pa)
{
    if(!*pa)
    {
        return 0;
    }
    else
    {
        return 1 + cant_nodos(&(*pa)->Hizq) + cant_nodos(&(*pa)->Hder);
    }
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
    return;
}

///LOTE DE DATOS (PRUEBA).

void mostrarPreOrden(T_arbol* pa)
{

    if(!*pa)
    {
        return;
    }
    printf(" %d ",(*pa)->info);
    mostrarPreOrden(&(*pa)->Hizq);
    mostrarPreOrden(&(*pa)->Hder);
}

void crear_arbol(T_arbol* pa)
{
    *pa = NULL;
}

int cargar_arbol_de_archivo_ord(T_arbol* pa, FILE* arch)
{
    fseek(arch, 0L, SEEK_END);
    long i = 0;
    long d = (ftell(arch) / sizeof(T_dato))-1;
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
    if(comp !=1)
    {
        return comp;
    }
    else
    {
        return cargar_arbol_rec(&(*pa)->Hder, arch, m+1, d);
    }
}
