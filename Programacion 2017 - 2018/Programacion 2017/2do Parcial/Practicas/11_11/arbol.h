#ifndef ARBOL_H_INCLUDED
#define ARBOL_H_INCLUDED

#define VERDADERO 1
#define FALSO 0
#define DUPLICADO -1
#define FALTA_MEMORIA -2

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

#endif // ARBOL_H_INCLUDED
