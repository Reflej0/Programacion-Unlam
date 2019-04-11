#ifndef ARBOL_H_INCLUDED
#define ARBOL_H_INCLUDED

typedef int (*T_cmp)(const void*, const void*);

typedef int T_dato;

typedef struct S_nodo
{
    struct S_nodo* Hizq;
    struct S_nodo* Hder;
    T_dato info;
} T_nodo;

typedef T_nodo* T_arbol;

void crear_arbol(T_arbol* pa);

int buscar_en_arbol(T_arbol* pa, T_dato* d, T_cmp cmp);

int altura_arbol(const T_arbol* pa);

void mostrar_arbol_pre(const T_arbol* pa);

void mostrar_arbol_in(const T_arbol* pa);

void mostrar_arbol_pos(const T_arbol* pa);

void eliminar_arbol(T_arbol *pa);

int eliminar_de_arbol(T_arbol* pa, const T_dato* d, T_cmp cmp);

T_nodo** buscar_nodo(T_arbol* pa, const T_dato* d, T_cmp cmp);

void eliminar_nodo(T_nodo** nae);

T_nodo** mayor(T_arbol* pa);

T_nodo** menor(T_arbol* pa);

int es_arbol_completo(const T_arbol* pa);

int es_arbol_avl(const T_arbol* pa);

int es_arbol_balanceado(const T_arbol* pa);

int es_arbol_balanceado_hasta_nivel(const T_arbol* pa, int nivel);

void podar_arbol_dde_nivel(T_arbol* pa, int nivel);

int cargar_arbol_de_archivo_ord(T_arbol* pa, FILE* arch);

int cargar_arbol_rec(T_arbol* pa, FILE* arch, int i, int d);

int cant_nodos(T_arbol* pa);

#endif // ARBOL_H_INCLUDED
