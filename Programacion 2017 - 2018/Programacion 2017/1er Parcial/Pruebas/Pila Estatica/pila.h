#ifndef PILA_H_INCLUDED
#define PILA_H_INCLUDED

#define TAM 10

typedef int T_dato;

typedef struct
{
    int tope;
    int vec[TAM];
} T_pila;

void crear_pila(T_pila* p);

int apilar(T_pila *p, const T_dato *d);

int desapilar(T_pila *p, T_dato *d);

void vaciar_pila(T_pila *p);

int ver_tope(const T_pila *p, T_dato *d);


#endif // PILA_H_INCLUDED
