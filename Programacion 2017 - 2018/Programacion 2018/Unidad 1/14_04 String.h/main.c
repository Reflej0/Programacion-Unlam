#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "_string.h"

int main()
{
    ///PRUEBA STRCAT.
    printf("PRUEBA STRCAT");
    char cad1[20] = "Hola";
    char cad2[10] = "Chau";
    printf("\nCadena: %s", _strcat(cad1, cad2));

    ///PRUEBA STRCHR.
    printf("\nPRUEBA STRCHR");
    char cad3[20] = "Hola, como estas?";
    char c = 'x';
    printf("\nCadena: %s", _strchr(cad3, c));

    ///PRUEBA STRCMP.
    printf("\nPRUEBA STRCMP");
    char cad4[20] = "Murcielago";
    char cad5[20] = "Murcielago";
    printf("\nCadena 1: %s\nCadena 2: %s", cad4, cad5);
    printf("\nCadena mas grande: %d", _strcmp(cad4, cad5));

    ///PRUEBA STRCPY.
    printf("\nPRUEBA STRCPY");
    char cad6[25] = "Basura";
    char cad7[28] = "Enviado correctamente";
    printf("\nCopia: %s", _strcpy(cad7, cad6));

    ///PRUEBA STRSTR.
    printf("\nPRUEBA STRSTR");
    char cad8[25] = "Necesaria Persona Nueva";
    char cad9[28] = "Persona";
    printf("\nResultado: %s", _strstr(cad8, cad9));
}
