#include <stdio.h>
#include <stdlib.h>
#include "cadenas.h"

int main()
{
    char cadena[100] = "";
    char concatenar[] = "Listo";
    char cadena_copiada[100] = "";
    char c;
    char abuscar[10];
    char defaul[] = "HolaListo";
    printf("Ingrese una cadena:");
    scanf("%s", cadena);
    ///FUNCIONES STRING.H
    /*int longitud = _strlen(cadena);
    printf("\nLa longitud de la cadena es: %d", longitud);
    _strcpy(cadena_copiada, cadena);
    printf("\nLa cadena introducida es: %s", cadena_copiada);
    _strcat(cadena, concatenar);
    printf("\nLa concatenacion: %s", cadena);
    printf("\nIngrese una letra a buscar:");
    fflush(stdin);
    scanf("%c", &c);
    printf("El caracter se encontro: %s", _strchr(cadena, c));*/
    /*printf("\nIngrese la cadena a buscar: ");
    scanf("%s", abuscar);
    fflush(stdin);
    printf("\nLa cadena se encontro: %s", _strstr(cadena, abuscar));*/
    //printf("\nstrcmp: %d", _strcmp(cadena, defaul));
    ///FUNCIONES CADENA
    /*invertir(cadena_copiada, cadena);
    printf("Cadena invertida: %s", cadena_copiada);*/
    /*normalizar(cadena_copiada, cadena);
    printf("Cadena normalizada: %s", cadena_copiada);*/

}
