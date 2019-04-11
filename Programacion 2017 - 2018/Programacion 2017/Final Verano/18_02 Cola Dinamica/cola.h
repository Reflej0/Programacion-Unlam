#ifndef COLA_H_INCLUDED
#define COLA_H_INCLUDED

typedef int T_dato;

typedef struct S_nodo
{
    struct S_nodo* sig;
    T_dato info;
} T_nodo;

typedef struct
{
    T_nodo* fr;
    T_nodo* fo;
} T_cola;

void crear_cola(T_cola* pc);

int poner_en_cola(T_cola* pc, const T_dato* d);

int sacar_de_cola(T_cola* pc, T_dato *d);

int cola_vacia(const T_cola* pc);

#endif // COLA_H_INCLUDED
