#ifndef COLA_H_INCLUDED
#define COLA_H_INCLUDED

typedef int T_dato;

typedef struct S_nodo
{
    struct S_nodo* sig;
    T_dato info;
} T_nodo;

typedef T_nodo* T_cola;

void crear_cola(T_cola* pc);

int acolar(T_cola* pc, const T_dato* d);

int desacolar(T_cola* pc, T_dato* d);

int colaVacia(const T_cola* pc);

#endif // COLA_H_INCLUDED
