#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ejercicio3.h"

int ingresar_numeros(int* vector)
{
    int i = 0;
    char numero[5];
    puts("Ingrese una serie de numeros, cuando desee terminar la serie ingrese exit");
    while(strcmp(numero, "exit"))
    {
        printf("Numero %d:",(i+1));
        scanf("%s", &numero);
        if (strcmp(numero, "exit"))
        {
          vector[i] = atoi(numero);
        }
        i++;
        if(i%5==0)
        {
            realloc(vector, (i+5));
        }
    }
    return (i-1);
}

void suma_elementos(int* vector, size_t tam, suma_promedio* resultado)
{
    int i;
    int suma = 0;
    for(i=0;i<tam;i++)
    {
        suma+=vector[i];
    }
    resultado->suma=suma;
    resultado->promedio=((float)suma/i);
}
