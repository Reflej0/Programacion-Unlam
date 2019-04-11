#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "recursivo.h"

int factorial(int numero)
{
    if(numero<0) return -1;
    if(numero == 0) return 1;
    return (numero*factorial(numero-1));
}

void printf_r(char* cad)
{
    if(!*cad) return;
    printf("%c", *cad);
    return printf_r(++cad);
}

void printf_inv(char* cad, int n)
{
    int i = strlen(cad);
    if(i == 0) return;
    printf("%c", cad[i-n]);
    return printf_inv(++cad, ++n);
}

int suma(char* cad)
{
    if(!*cad) return;
    if(*cad>='0' && *cad<='9') return
}
