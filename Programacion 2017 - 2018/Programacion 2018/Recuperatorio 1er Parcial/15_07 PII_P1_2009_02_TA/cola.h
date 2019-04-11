#ifndef COLA_H_INCLUDED
#define COLA_H_INCLUDED
#define TAM 3

typedef int T_dato;

typedef struct
{
    int inicio;
    int fin;
    int nro_ele;
    T_dato vcola[TAM];
} T_cola;

void crear_cola(T_cola* c);

int acolar(T_cola* c, const T_dato* d);

int desacolar(T_cola* c, T_dato* d);

int esta_cola_llena(const T_cola* c);

int esta_cola_vacia(const T_cola* c);

int ver_frente(const T_cola* c, T_dato* d);

void vaciar_cola(T_cola* c);

#endif // COLA_H_INCLUDED
