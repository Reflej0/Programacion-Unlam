#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED

typedef int (*T_cmp)(const void*, const void*);

typedef void (*T_show)(const void*);

typedef int T_dato;

typedef struct S_nodo
{
    struct S_nodo* sig;
    struct S_nodo* ant;
    T_dato info;
} T_nodo;

typedef T_nodo* T_lista;

void crear_lista(T_lista* pl);

///IMPORTANTES

int agregar_ordenado_duplicados(T_lista* pl, const T_dato* d, T_cmp cmp);

int eliminar_ordenado(T_lista* pl, T_dato* d, T_cmp cmp);

void eliminar_duplicados(T_lista* pl, T_cmp cmp);

int agregar_ordenado_no_duplicados(T_lista* pl, const T_dato* d, T_cmp cmp);

void ordenar_lista(T_lista* pl, T_cmp cmp);

///NO COMPLICADOS

void mostrar_lista_desde_principio(const T_lista* pl, T_show show);

int agregar_al_principio(T_lista* pl, const T_dato* d);

int eliminar_del_principio(T_lista* pl, T_dato* d);

void ordenar_lista_sin_seleccion(T_lista* pl, T_cmp comp);

void los_n_mejores(const T_lista* pl, T_dato* vec, T_cmp cmp, size_t n);

void eliminar_lista(T_lista* pl);

#endif // LISTA_H_INCLUDED
