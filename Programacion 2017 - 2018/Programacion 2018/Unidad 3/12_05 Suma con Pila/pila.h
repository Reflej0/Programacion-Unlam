#ifndef PILA_H_INCLUDED
#define PILA_H_INCLUDED

typedef char T_dato;

typedef struct S_nodo
{
    struct S_nodo* sig;
    T_dato d;
} T_nodo;

typedef T_nodo* T_pila;

void crear_pila(T_pila* p);

int apilar(T_pila* p, const T_dato* d);

int desapilar(T_pila* p, T_dato* d);

int pila_vacia(const T_pila* p);

#endif // PILA_H_INCLUDED
