#ifndef PILA_H_INCLUDED
#define PILA_H_INCLUDED

typedef int T_dato;

typedef struct S_nodo
{
    struct S_nodo *siguiente;
    T_dato dato;
}   T_nodo;

typedef T_nodo* T_pila;

void crear_pila(T_pila *p);

int apilar(T_pila *p, const T_dato *dato);

int desapilar(T_pila *p, T_dato *dato);

int ver_tope(const T_pila *p, T_dato *dato);

void vaciar_pila(T_pila *p);

int pila_vacia(T_pila *p);

#endif // PILA_H_INCLUDED
