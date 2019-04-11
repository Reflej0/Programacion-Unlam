#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED

typedef void (*T_show) (const void*);

typedef int (*T_cmp) (const void*, const void*);

void mostrar_normal(const void* a);

int comp_int(const void* a, const void* b);

typedef int T_dato;

typedef struct S_nodo
{
    struct S_nodo* sig;
    T_dato d;
} T_nodo;

typedef T_nodo* T_lista;

void crear_lista(T_lista* l);

int agregar_al_principio(T_lista* l, const T_dato* d);

void mostrar_lista(const T_lista* l, T_show show);

void ordenar_lista(T_lista* l, T_cmp cmp);

#endif // LISTA_H_INCLUDED
