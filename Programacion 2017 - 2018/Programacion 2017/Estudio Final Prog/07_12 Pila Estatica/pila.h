#ifndef PILA_H_INCLUDED
#define PILA_H_INCLUDED

#define TAM 10

typedef char* T_dato;

typedef struct
{
    T_dato datos[TAM];
    int tope;
} T_pila;

void crear_pila(T_pila* pila);

void vaciar_pila(T_pila* pila);

int apilar(T_pila* pila, const T_dato* d);

int desapilar(T_pila* pila, T_dato* d);

int ver_tope(T_pila* pila, T_dato* d);

int pila_llena(T_pila* pila);

int pila_vacia(T_pila* pila);

#endif // PILA_H_INCLUDED
