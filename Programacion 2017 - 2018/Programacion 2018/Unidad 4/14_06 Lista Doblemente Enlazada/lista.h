#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED
#define NO_DUPLICADO 0
#define SIN_MEMORIA 0
#define LISTA_VACIA 0
#define NO_ENCONTRADO 0

typedef int T_dato;

typedef int (*T_cmp) (const void*, const void*);

typedef void (*T_do) (const void*);

typedef void (*T_show) (const void*);

int comp_int(const void* a, const void* b);

void mostrar_int(const void* a);

typedef struct S_nodo
{
    struct S_nodo* sig;
    struct S_nodo* ant;
    T_dato d;
} T_nodo;

typedef T_nodo* T_lista;

void crear_lista(T_lista* pl);

size_t _count(const T_lista* pl);

int agregar_ordenado_lista(T_lista* pl, const T_dato* pd, T_cmp cmp);

int eliminar_de_lista(T_lista* pl, T_dato* pd, T_cmp cmp);

void eliminar_duplicados(T_lista* pl, T_cmp cmp);

void vaciar_lista(T_lista* pl);

void mostrar_adelante_desde_actual(const T_lista* pl, T_show show);

void mostrar_atras_desde_actual(const T_lista* pl, T_show show);

void mostrar_desde_principio(const T_lista* pl, T_show show);

void mostrar_desde_final(const T_lista* pl, T_show show);

#endif // LISTA_H_INCLUDED
