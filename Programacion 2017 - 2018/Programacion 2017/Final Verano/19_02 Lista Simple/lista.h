#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED

typedef int T_dato;

typedef struct S_nodo
{
    struct S_nodo* sig;
    T_dato info;
} T_nodo;

typedef T_nodo* T_lista;

typedef int (*T_cmp)(const void*, const void*);

void crear_lista(T_lista* pl);

int agregar_principio(T_lista* pl, const T_dato* d);

void mostrar_lista(const T_lista* pl);

int agregar_final(T_lista* pl, const T_dato* d);

int agregar_ordenado(T_lista* pl, const T_dato* d, T_cmp comp);

int eliminar_principio(T_lista* pl, T_dato* d);

void ordenar_lista(T_lista* pl, T_cmp comp);

#endif // LISTA_H_INCLUDED
