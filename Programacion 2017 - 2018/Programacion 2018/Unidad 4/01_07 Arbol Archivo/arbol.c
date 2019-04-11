#include <stdio.h>
#include <stdlib.h>
#include "arbol.h"

void crear_arbol(T_arbol* pa)
{
    *pa = NULL;
}

void mostrar_arbol_pre(const T_arbol* pa)
{
    if(!*pa)
        return;
    printf("%d\n", (*pa)->info);
    mostrar_arbol_pre(&(*pa)->Hizq);
    mostrar_arbol_pre(&(*pa)->Hder);
}

void guardar_arbol_archivo_bin(T_arbol* pa, FILE* arch)
{
    if (!*pa)
    {
        T_dato _null = NOVALIDO; //Designo un valor para indicar un registro no valido.
        fwrite(&_null, sizeof(T_dato), 1, arch);
        return;
    }
    fwrite(&(*pa)->info, sizeof(T_dato), 1, arch);
    guardar_arbol_archivo_bin(&(*pa)->Hizq, arch);
    guardar_arbol_archivo_bin(&(*pa)->Hder, arch);
}

void leer_arbol_archivo_bin(T_arbol* pa, FILE* arch)
{
    T_dato d;
    if ( !fread(&d, sizeof(T_dato), 1, arch) || d == NOVALIDO)
       return;

    *pa = (T_nodo*)malloc(sizeof(T_nodo));
    if(!*pa) exit(EXIT_FAILURE);
    (*pa)->info = d;
    (*pa)->Hizq = NULL;
    (*pa)->Hder = NULL;
    leer_arbol_archivo_bin(&(*pa)->Hizq, arch);
    leer_arbol_archivo_bin(&(*pa)->Hder, arch);
}

void guardar_arbol_archivo_txt(T_arbol* pa, FILE* arch)
{
    if (!*pa)
    {
        T_dato _null = NOVALIDO; //Designo un valor para indicar un registro no valido.
        fprintf(arch, "%d ", _null);
        return;
    }
    fprintf(arch, "%d ", (*pa)->info);
    guardar_arbol_archivo_txt(&(*pa)->Hizq, arch);
    guardar_arbol_archivo_txt(&(*pa)->Hder, arch);
}

void leer_arbol_archivo_txt(T_arbol* pa, FILE* arch)
{
    T_dato d;
    if ( !fscanf(arch, "%d", &d) || d == NOVALIDO)
       return;

    *pa = (T_nodo*)malloc(sizeof(T_nodo));
    if(!*pa) exit(EXIT_FAILURE);
    (*pa)->info = d;
    (*pa)->Hizq = NULL;
    (*pa)->Hder = NULL;
    leer_arbol_archivo_txt(&(*pa)->Hizq, arch);
    leer_arbol_archivo_txt(&(*pa)->Hder, arch);
}
