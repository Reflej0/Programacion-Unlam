#ifndef PILA_H_INCLUDED
#define PILA_H_INCLUDED

typedef struct
{
    char nya[40];
    int dni;
} T_dato;

typedef struct S_nodo
{
    struct S_nodo* siguiente;
    T_dato dato;
} T_nodo;

typedef T_nodo* T_pila;

void crear_pila(T_pila* pp);

int apilar(T_pila *pp, const T_dato *d);

int desapilar(T_pila *pp, T_dato *d);

int ver_tope(T_pila *pp, T_dato *d);

int pila_llena(T_pila *pp);

int pila_vacia(T_pila *pp);

void vaciar_pila(T_pila *pp);

#endif // PILA_H_INCLUDED
