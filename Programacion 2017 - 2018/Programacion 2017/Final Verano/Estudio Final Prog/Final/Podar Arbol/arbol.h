#ifndef ARBOL_H_INCLUDED
#define ARBOL_H_INCLUDED

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

void crear_arbol(T_arbol* pa);

int cargar_arbol_de_archivo_ord(T_arbol* pa, FILE* arch);

int cargar_arbol_rec(T_arbol* pa, FILE* arch, long i, long d);

void mostrarPreOrden(T_arbol* pa);

///FUNCION/ES PEDIDA.

int contar_nodos_internos(T_arbol *pa);

void podar_arbol_dde_nivel(T_arbol* pa, int nivel);

int cant_nodos(T_arbol* pa);

int podar_arbol_dde_nivel_cant_nodos(T_arbol* pa, int nivel);

int cant_nodos_hoja(T_arbol* pa);

#endif // ARBOL_H_INCLUDED
