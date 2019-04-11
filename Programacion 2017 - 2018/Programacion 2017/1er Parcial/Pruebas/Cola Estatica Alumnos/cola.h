#ifndef COLA_H_INCLUDED
#define COLA_H_INCLUDED

#define TAM 10

typedef struct
{
    int dni;
} T_dato;

typedef struct
{
    int frente;
    int fondo;
    T_dato vcola[TAM];
    size_t ce;
} T_cola;

void crear_cola(T_cola* pc);

int acolar(T_cola* pc, const T_dato* d);

int desacolar(T_cola* pc, T_dato* d);

int ver_tope(const T_cola* pc, T_dato* d);

#endif // COLA_H_INCLUDED
