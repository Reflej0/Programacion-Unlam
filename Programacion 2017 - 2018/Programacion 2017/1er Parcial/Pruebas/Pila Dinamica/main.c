#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

int main()
{
    T_pila pila;
    crear_pila(&pila);
    T_dato dato = 5;
    apilar(&pila, &dato);
    T_dato dato2 = 6;
    apilar(&pila, &dato2);
    T_dato aux;
    ver_tope(&pila, &aux);
    printf("%d", aux);
    vaciar_pila(&pila);
    printf("\nPila Vacia:%d", pila_vacia(&pila));
}
