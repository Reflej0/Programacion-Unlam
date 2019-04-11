#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED

typedef int (*T_cmp)(const void*, const void*);

typedef void (*T_show)(const void*);

int cmp_dato(const void* a, const void* b);

void show(const void* a);

typedef struct S_nodo
{
    struct S_nodo* sig;
    T_dato info;
}T_nodo;

typedef T_nodo* T_lista;

void crear_lista(T_lista* l);

void mostrar_lista(const T_lista* l, T_show show);

int agregar_al_principio(T_lista* l,  const T_dato* d);

int agregar_al_final(T_lista* l,  const T_dato* d);

int agregar_ordenado(T_lista* l,  const T_dato* d, T_cmp cmp);

int eliminar_principio(T_lista* l,  T_dato* d);

int eliminar_final(T_lista* l,  T_dato* d);

int eliminar_info(T_lista* l,  T_dato* d, T_cmp cmp);

void ordenar_lista(T_lista* l, T_cmp cmp);

T_nodo** buscar_menor(const T_lista* l, T_cmp cmp);

void eliminar_duplicados(T_lista* l, T_cmp cmp);

int mejores_n_lista(const T_lista* l, int n, T_dato* v, T_cmp cmp);

void _swap(T_nodo** a, T_nodo** b);

#endif // LISTA_H_INCLUDED
