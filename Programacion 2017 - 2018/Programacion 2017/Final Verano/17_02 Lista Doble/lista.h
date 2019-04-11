#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED

typedef int (*T_cmp)(const void*, const void*);

typedef int T_dato;

typedef struct S_nodo
{
    struct S_nodo* sig;
    struct S_nodo* ant;
    T_dato info;
} T_nodo;

typedef T_nodo* T_lista;

void crear_lista(T_lista* pl);

int agregar_ordenado(T_lista* pl, const T_dato* d, T_cmp cmp);

int eliminar_valor_lista(T_lista* pl, T_dato* d, T_cmp cmp);

int agregar_al_principio(T_lista* pl, const T_dato* d);

int eliminar_al_principio(T_lista* pl, T_dato* d);

void ordenar_lista(T_lista* pl, T_cmp cmp);

void ver_lista_desde_principio(const T_lista* pl);

void eliminar_duplicados(T_lista* pl, T_cmp cmp);

#endif // LISTA_H_INCLUDED
