#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

void crear_pila(T_pila *p)
{
    p->capacidad = 10;
    p->v_pila = malloc(sizeof(T_dato)*10); // El 10 puede variar.
    p->tope = -1;
}

int poner_en_pila(T_pila *p, const T_dato *d)
{
    p->tope = d;
    p->capacidad++;
}
