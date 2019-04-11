#ifndef PILA_H_INCLUDED
#define PILA_H_INCLUDED

#define TAM 10

typedef char* T_dato;

typedef struct
{
    char* vpila[TAM];
    int tope;
} T_pila;

void crear_pila(T_pila* p);

int apilar(T_pila* p, const T_dato* d);

int ver_tope(const T_pila* p, T_dato *d);

int desapilar(T_pila* p, T_dato* d);

int pila_llena(T_pila* p);

#endif // PILA_H_INCLUDED
