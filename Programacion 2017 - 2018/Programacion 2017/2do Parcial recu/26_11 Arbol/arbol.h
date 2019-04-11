#ifndef ARBOL_H_INCLUDED
#define ARBOL_H_INCLUDED

#define VERDADERO 1
#define FALSO 0
#define DUPLICADO -1
#define FALTA_MEMORIA -2
#define ARBOL_VACIO 0
#define NO_ENCONTRADO 0
#define ENCONTRADO 1

#include "stdio.h"

///T_CMP
typedef int (*T_cmp) (const void*, const void*);

///FUNCION DE COMPARACION
int cmp(const void* e1, const void* e2);

///T_DATO
typedef int T_dato;

///NODO DEL ARBOL
typedef struct S_nodo
{
    struct S_nodo* Hizq;
    struct S_nodo* Hder;
    T_dato info;
} T_nodo;

typedef T_nodo* T_arbol;

///--------------YA MEMORIZADO-----------------------

void crear_arbol(T_arbol* pa);

int buscar_en_arbol(const T_arbol* pa, T_dato* d, T_cmp cmp);

int insertar_en_arbol(T_arbol* pa, const T_dato* d, T_cmp cmp);

int altura_arbol(const T_arbol* pa);

void mostrar_arbol_pre(const T_arbol* pa);

void mostrar_arbol_in(const T_arbol* pa);

void mostrar_arbol_pos(const T_arbol* pa);

void eliminar_arbol(T_arbol* pa);

int eliminar_de_arbol(T_arbol* pa, T_dato* d, T_cmp cmp);

T_nodo** buscar_nodo(T_arbol* pa, T_dato* d, T_cmp cmp);

void eliminar_nodo(T_arbol* nae);

T_nodo** mayor(T_arbol* pa);

T_nodo** menor(T_arbol* pa);

int es_arbol_completo(const T_arbol* pa);

int es_arbol_avl(const T_arbol* pa);

int es_arbol_balanceado(const T_arbol* pa);

int es_arbol_balanceado_hasta_nivel(const T_arbol* pa, int nivel);

void podar_arbol_dde_nivel(T_arbol* pa, int nivel);

int cargar_arbol_de_archivo_ord(T_arbol* pa, FILE* arch);

int cargar_arbol_rec(T_arbol* pa, FILE* arch, long i, long d);

void generarArchivoArbol(FILE* arch);

int cargaAutomatica(T_arbol* pa, T_cmp cmp);

#endif // ARBOL_H_INCLUDED
