#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED

typedef int (*T_cmp)(const void*, const void*);

typedef void (*T_show) (const void*);

typedef int T_dato;

typedef struct S_nodo
{
   struct S_nodo* sig;
   T_dato info;
} T_nodo;

typedef T_nodo* T_lista;

void crear_lista(T_lista* pl);

int agregar_al_principio(T_lista* pl, const T_dato* d);

int agregar_al_final(T_lista* pl, const T_dato* d);

int agregar_ordenado(T_lista* pl, const T_dato* d, T_cmp cmp);

int eliminar_principio(T_lista* pl, T_dato* d);

int eliminar_final(T_lista* pl, T_dato* d);

int buscar_clave(const T_lista* pl, T_dato* d, T_cmp cmp);

void mostrar_lista(const T_lista* pl, T_show);

size_t contar_elementos_lista(const T_lista* pl);


#endif // LISTA_H_INCLUDED
