#ifndef COLA_H_INCLUDED
#define COLA_H_INCLUDED

#define TAM 10

typedef int T_dato;

typedef struct
{
    int frente;
    int fondo;
    int ce;
    int vec[TAM];
} T_cola;

void crear_cola(T_cola *c);

int acolar(T_cola *c, const T_dato *d);

int desacolar(T_cola *c, T_dato *d);

void vaciar_cola(T_cola *c);

int ver_frente(const T_cola *c, T_dato *d);

#endif // COLA_H_INCLUDED
