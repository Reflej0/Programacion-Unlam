#ifndef COLA_H_INCLUDED
#define COLA_H_INCLUDED

typedef struct
{
    int dni;
    char nyap[41];
} T_dato;

typedef struct S_nodo
{
    struct S_nodo* siguiente;
    T_dato dato;
} T_nodo;

typedef struct
{
    T_nodo* frente;
    T_nodo* fondo;
} T_cola;

void crear_cola(T_cola* pc);

int acolar(T_cola* pc, const T_dato *d);

int desacolar(T_cola* pc, T_dato *d);

int ver_frente(const T_cola* pc, T_dato *d);

void vaciar_cola(T_cola* pc);

int cola_llena(T_cola *pc);

int cola_vacia(T_cola *pc);


#endif // COLA_H_INCLUDED
