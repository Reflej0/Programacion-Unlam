#include <stdio.h>
#include <stdlib.h>
#include "recursivo.h"

int main()
{
    ///FACTORIAL.
    /*
    int numero;
    printf("Ingrese un numero:");
    scanf("%d", &numero);
    printf("Factorial:%d", factorial(numero));
    */
    ///IMPRIMIR CADENA.
    /*
    char cad[20];
    printf("Ingrese una cadena:");
    gets(cad);
    printf_r(cad);
    */
    ///IMPRIMIR CADENA AL REVES.
    char cad[20];
    printf("Ingrese una cadena:");
    gets(cad);
    printf_inv(cad, 1);
    return 0;
}
