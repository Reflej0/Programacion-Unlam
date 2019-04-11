#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED

int cmp(const void* n1, const void* n2);

typedef int (*T_cmp)(const void*, const void*);

typedef int T_dato;

typedef struct S_nodo
{
    struct S_nodo* siguiente;
    struct S_nodo* anterior;
    T_dato info;
} T_nodo;

typedef T_nodo* T_lista;

void crear_lista(T_lista* lista);

///MAS DIFICILES

int agregar_ordenado(T_lista* pl, T_dato* d, T_cmp cmp);

int eliminar_valor_lista(T_lista* pl, T_dato* d, T_cmp cmp);

void eliminar_duplicados(T_lista* pl, T_cmp cmp);

///-----------------------------------------------------------

int agregar_al_principio(T_lista* pl, T_dato* d);

int agregar_al_final(T_lista* pl, T_dato* d);

int eliminar_primero(T_lista* pl, T_dato* d);

int eliminar_ultimo(T_lista* pl, T_dato* d);

int buscar_valor_lista(T_lista* pl, T_dato* d, T_cmp cmp);

void ver_lista_desde_principio(T_lista* pl);

void ver_lista_desde_final(T_lista* pl);



#endif // LISTA_H_INCLUDED
