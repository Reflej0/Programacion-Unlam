#ifndef COLA_H_INCLUDED
#define COLA_H_INCLUDED

#include "def.h"

//typedef int T_dato;

typedef struct
{
    T_nodo* frente;
    T_nodo* fondo;
} T_cola;

void crear_cola(T_cola* c);

int acolar(T_cola* c, const T_dato* d);

int desacolar(T_cola* c, T_dato* d);

int ver_frente(const T_cola* c, T_dato* d);

#endif // COLA_H_INCLUDED
