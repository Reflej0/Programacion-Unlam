#include <stdio.h>
#include <stdlib.h>
#include "string.h"

int main()
{
    char cadena[] = "Hola Mundo";
    char cadena2[] = "Adios Mundo";
    char cadena3[20] = "";
    printf("%d", strlen(cadena));
    printf("%d", strcmp(cadena, cadena2));
    strcpy(cadena, cadena3);
    printf("%s", cadena3);
    printf("%d", strchr(cadena, 'M'));
}
