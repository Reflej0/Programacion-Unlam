#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED

typedef int (*T_cmp)(const void*, const void*);

int cmp(const void* num, const void* num2);

typedef int T_dato;

typedef struct S_nodo
{
    struct S_nodo* siguiente;
    T_dato dato;
} T_nodo;

typedef T_nodo* T_lista;

void crear_lista(T_lista* pl);

int agregar_principio(T_lista* pl, const T_dato* d);

int agregar_final(T_lista* pl, const T_dato* d);

int agregar_ordenado(T_lista* pl, const T_dato* d, T_cmp cmp);

int eliminar_principio(T_lista* pl, T_dato *d);

int eliminar_ultimo(T_lista* pl, T_dato *d);

int eliminar_lista(T_lista* pl);

void mostrar_lista(T_lista* pl);

int eliminar_valor(T_lista* pl, const T_dato *d);

int eliminar_indice(T_lista* pl, T_dato *d, const int indice);

void ordenar_lista(T_lista* pl, T_cmp cmp);

void ordenar_vector(T_dato* vec);

void intercambiar_punteros(void** p1, void** p2);

int cantidad_elementos(T_lista* pl);

#endif // LISTA_H_INCLUDED
