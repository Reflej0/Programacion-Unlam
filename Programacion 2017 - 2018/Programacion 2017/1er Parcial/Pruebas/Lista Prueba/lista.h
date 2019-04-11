#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED

typedef int(*T_cmp)(const void*, const void*);

int cmp_alu(const void* alu1, const void* alu2);

typedef struct
{
    int dni;
    char apyn[41];
}T_dato;

typedef struct S_nodo
{
    struct S_nodo* siguiente;
    T_dato dato;
} T_nodo;

typedef T_nodo* T_lista;

void crear_lista(T_lista* pl);

int agregar_principio(T_lista* pl, const T_dato *d);

int agregar_final(T_lista* pl, const T_dato *d);

int agregar_ordenado(T_lista* pl, const T_dato *d, T_cmp cmp);

int eliminar_principio(T_lista* pl, T_dato *d);

int eliminar_indice(T_lista* pl, T_dato *d, size_t indice);

int buscar_indice(T_lista* pl, T_dato *d, size_t indice);

size_t cantidad_elementos(T_lista *pl);

void ordenar_lista(T_lista* pl);

void ordenar_datos(T_dato* vec, size_t longitud);

void intercambiar_punteros(void** a, void** b);

void mostrar_lista(T_lista* pl);

#endif // LISTA_H_INCLUDED
