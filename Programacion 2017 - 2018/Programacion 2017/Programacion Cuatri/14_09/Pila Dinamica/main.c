#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

int main()
{
    T_pila pila;
    T_dato dato;
    dato.numero = 5;
    crear_pila(&pila);
    poner_en_pila(&pila, &dato);
    printf("%d", pila.tope->numero);
}
