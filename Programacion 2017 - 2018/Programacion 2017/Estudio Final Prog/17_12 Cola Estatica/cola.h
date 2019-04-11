#ifndef COLA_H_INCLUDED
#define COLA_H_INCLUDED

#define TAM 10

typedef int T_dato;

typedef struct
{
    int frente;
    int fondo;
    int tope;
    T_dato vcola[TAM];
} T_cola;

void crear_cola(T_cola* pc);
int acolar(T_cola* pc, const T_dato* pd);
int desacolar(T_cola* pc, T_dato* pd);
int frente_de_cola(const T_cola* pc, T_dato* pd);
int colaVacia(const T_cola* pc);
int cola_llena(const T_cola* pc);
void vaciar_cola(T_cola* pc);

#endif // COLA_H_INCLUDED
