#ifndef ARBOL_H_INCLUDED
#define ARBOL_H_INCLUDED

int cmp(const void* e1, const void* e2);

typedef int T_cmp;

typedef int T_dato;

typedef struct S_nodo
{
    struct S_nodo* Hizq;
    struct S_nodo* Hder;
    T_dato info;
} T_nodo;

typedef T_nodo* T_arbol;

void crear_arbol(T_arbol* pa);

int cargar_arbol_de_arch(T_arbol* pa, FILE* arch);

int cargar_arbol_rec(T_arbol* pa, FILE* arch, long i, long d);

int contar_nodos_totales(const T_arbol* pa);

int contar_nodos_hojas(const T_arbol* pa);

int contar_nodos_internos(const T_arbol* pa);

#endif // ARBOL_H_INCLUDED
