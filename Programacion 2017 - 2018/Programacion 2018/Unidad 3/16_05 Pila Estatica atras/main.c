#include <stdio.h>
#include <stdlib.h>
#include "pila.h"
///Tamaño de pila 5 elementos en pila.h

int main()
{
    T_pila pila; // Pila.
    T_dato mensaje = 100000000; // T_dato #1
    T_dato mensaje2 = 200000000; // T_dato #2
    T_dato mensaje3 = 300000000; //T_dato #3
    T_dato mensaje4 = 400000000; //T_dato #4
    T_dato mensaje5 = 500000000; //T_dato #5
    T_dato mensaje6 = 600000000; //T_dato #6
    T_dato mensaje7 = 700000000; //T_dato #6
    T_dato aux;
    crear_pila(&pila);
    apilar(&pila, &mensaje);
    ver_tope(&pila, &aux);
    printf("Tengo que ver el 100000000: %ld", aux);
    //-----------------------------------------------
    apilar(&pila, &mensaje2);
    ver_tope(&pila, &aux);
    printf("\nTengo que ver el 200000000: %ld", aux);
    //------------------------------------------------
    apilar(&pila, &mensaje3);
    ver_tope(&pila, &aux);
    printf("\nTengo que ver el 300000000: %ld", aux);
    apilar(&pila, &mensaje4);
    apilar(&pila, &mensaje5);
    apilar(&pila, &mensaje6);
    apilar(&pila, &mensaje7);
    ///Porque la pila es de tamaño maximo 5 elementos.
    desapilar(&pila, &aux);
    printf("\nTengo que ver el 500000000: %ld", aux);
    desapilar(&pila, &aux);
    printf("\nTengo que ver el 400000000: %ld", aux);
    desapilar(&pila, &aux);
    printf("\nTengo que ver el 300000000: %ld", aux);
    desapilar(&pila, &aux);
    printf("\nTengo que ver el 200000000: %ld", aux);
    desapilar(&pila, &aux);
    printf("\nTengo que ver el 100000000: %ld", aux);
    desapilar(&pila, &aux);
    return 1;
}
