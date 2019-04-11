#ifndef COLA_H_INCLUDED
#define COLA_H_INCLUDED
#define TAM 10

typedef int T_dato;

typedef struct
{
    int fr;
    int fo;
    int ce;
    T_dato vcola[TAM];
} T_cola;

void crear_cola(T_cola* pc);

int poner_en_cola(T_cola* pc, const T_dato* d);

int sacar_de_cola(T_cola* pc, T_dato* d);

int cola_vacia(const T_cola* pc);

#endif // COLA_H_INCLUDED
