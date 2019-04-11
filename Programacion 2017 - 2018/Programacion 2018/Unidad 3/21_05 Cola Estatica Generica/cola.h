#ifndef COLA_H_INCLUDED
#define COLA_H_INCLUDED
#define TAM_COLA 4
#define VERDADERO 1
#define FALSO 0

typedef char T_dato;

typedef struct
{
    int pri;
    int ult;
    T_dato cola[TAM_COLA];
} T_cola;

void crear_cola(T_cola* c);

int acolar(T_cola* c, const T_dato* d);

int desacolar(T_cola* c, T_dato* d);

int ver_frente(const T_cola* c, T_dato* d);

void vaciar_cola(T_cola* c);

int cola_llena(const T_cola* c);

int cola_vacia(const T_cola* c);

#endif // COLA_H_INCLUDED
