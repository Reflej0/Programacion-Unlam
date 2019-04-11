#ifndef COLA_H_INCLUDED
#define COLA_H_INCLUDED

typedef struct S_nodo
{
    struct S_nodo* sig;
    T_dato info;
} T_nodo;

typedef struct
{
   T_nodo* inicio;
   T_nodo* fin;
} T_cola;

void crear_cola(T_cola* pc);

int acolar(T_cola* pc, const T_dato* d);

int desacolar(T_cola* pc, T_dato* d);

int ver_frente(const T_cola* pc, T_dato* d);

void vaciar_cola(T_cola* pc);

int esta_vacia_cola(const T_cola* pc);

int esta_llena_cola(const T_cola* pc);

#endif // COLA_H_INCLUDED
