#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

void crear_pila(T_pila* p)
{
    p->vtope = -1; // PILA VACIA.
}

int apilar(T_pila* p, T_dato* d)
{
    if(p->vtope == TAM-1)
    {
        return -1; //PILA LLENA
    }
    p->vtope++;
    p->vpila[p->vtope] = *d;
    return 1;
}

int ver_tope(T_pila* p, T_dato* d)
{
    if(p->vtope == TAM-1)
    {
        return -1; //PILA LLENA
    }
    *d = p->vpila[p->vtope];
    return 1;
}

int desapilar(T_pila* p, T_dato* d)
{
    if(p->vtope == -1)
    {
        return -1; //PILA VACIA.
    }
    *d = p->vpila[p->vtope];
    p->vtope--;
    return 1;
}

int pila_llena(T_pila* p)
{
    if(p->vtope == TAM-1)
    {
        return 1; //PILA LLENA
    }
    return 0;
}
