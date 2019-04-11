#include <stdio.h>
#include <stdlib.h>
#include "_string.h"
#define CANT_CADENAS 20
#define LONG_CADENA 30

int main()
{
    char cadenas[CANT_CADENAS][LONG_CADENA];
    char cad1[LONG_CADENA];
    char cad2[LONG_CADENA];
    int comp;
    int i = 0;
    printf("Ingrese la primera cadena:");
    gets(cad1);
    fflush(stdin);
    printf("\nIngrese la segunda cadena:");
    gets(cad2);
    while((comp = strcmpi_(cad1, cad2)) !=0)
    {
        if(comp>0)
        {
            strcpy_(cadenas[i], cad2);
            i++;
            strcpy_(cadenas[i], cad1);
            i++;
        }
        else
        {
            strcpy_(cadenas[i], cad1);
            i++;
            strcpy_(cadenas[i], cad2);
            i++;
        }
        printf("\nIngrese la primera cadena:");
        gets(cad1);
        fflush(stdin);
        printf("\nIngrese la segunda cadena:");
        gets(cad2);
    }
    int j = 0;
    ///Visualizar por pantalla las cadenas ingresadas.
    for(j=0; j<i; j++)
    {
        printf("%s\n", cadenas[j]);
    }
    return 1;
}
