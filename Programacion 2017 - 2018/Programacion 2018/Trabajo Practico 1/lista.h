#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED

#include "iterador.h"

typedef int (*T_cmp)(const void*, const void*);

int cmp(const void* a, const void* b);

typedef T_nodo* T_lista;

void crear_lista(T_lista* pl);

int agregar_principio(T_lista* pl, const T_dato* d);

int agregar_final(T_lista* pl, const T_dato* d);

int agregar_ordenado(T_lista* pl, const T_dato* d, T_cmp cmp, T_iterador* ite);

int eliminar_principio(T_lista* pl, T_dato *d);

int eliminar_ultimo(T_lista* pl, T_dato *d);

int eliminar_lista(T_lista* pl);

int eliminar_valor(T_lista* pl, const T_dato *d);

int eliminar_indice(T_lista* pl, T_dato *d, const int indice);

void intercambiar_punteros(void** p1, void** p2);

int cantidad_elementos(T_lista* pl);

void mostrar_lista(T_lista* pl);

int eliminardelista(T_lista* pl, T_dato* d);

#endif // LISTA_H_INCLUDED
