#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

int main()
{
    T_pila pila;
    T_dato dato = 9;
    T_dato dato2 = 11;
    crear_pila(&pila);
    apilar(&pila, &dato);
    apilar(&pila, &dato2);
    T_dato aux;
    ver_tope(&pila, &aux);
    printf("%d", aux);
    desapilar(&pila, &aux);
    ver_tope(&pila, &aux);
    printf("\n%d", aux);
}
