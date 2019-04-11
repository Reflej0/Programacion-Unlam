#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED

typedef int (*T_cmp) (const void*, const void*);

int cmp_int(const void* num, const void* num2);

typedef int T_dato;

typedef struct S_nodo
{
    struct S_nodo* siguiente;
    T_dato dato;
} T_nodo;

typedef T_nodo* T_lista;

void crear_lista(T_lista* lista);

int poner_en_lista_principio(T_lista* lista, T_dato* dato);

int poner_en_lista_final(T_lista* lista, T_dato* dato);

int poner_en_lista_ord(T_lista* lista, const T_dato* dato, T_cmp cmp);

void mostrar_lista(T_lista* lista);

int buscar_en_lista_por_posicion(T_lista* lista, const int posicion, T_dato* respuesta);

int buscar_en_lista_por_clave(T_lista* lista, const T_dato* dato);

#endif // LISTA_H_INCLUDED
