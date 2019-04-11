#ifndef COLA_H_INCLUDED
#define COLA_H_INCLUDED

typedef char* T_dato;

typedef struct S_nodo
{
    struct S_nodo *siguiente;
    T_dato dato;
} T_nodo;

typedef struct
{
    T_nodo *fr;
    T_nodo *fo;
} T_cola;


void crear_cola(T_cola *pc);

int poner_en_cola(T_cola *pc, T_dato *d);

int sacar_de_cola(T_cola *pc, T_dato *d);

int ver_frente_de_cola(T_cola const *pc, T_dato *d);

void vaciar_cola(T_cola *pc);

int cola_vacia(const T_cola *pc);

int cola_llena(const T_cola *pc);

#endif // COLA_H_INCLUDED
