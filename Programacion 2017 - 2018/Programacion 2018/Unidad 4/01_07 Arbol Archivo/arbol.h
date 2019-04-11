#ifndef ARBOL_H_INCLUDED
#define ARBOL_H_INCLUDED

#define NOVALIDO -1

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

void crear_arbol(T_arbol* pa);

void mostrar_arbol_pre(const T_arbol* pa);

void guardar_arbol_archivo_bin(T_arbol* pa, FILE* arch);

void leer_arbol_archivo_bin(T_arbol* pa, FILE* arch);

void guardar_arbol_archivo_txt(T_arbol* pa, FILE* arch);

void leer_arbol_archivo_txt(T_arbol* pa, FILE* arch);

#endif // ARBOL_H_INCLUDED
