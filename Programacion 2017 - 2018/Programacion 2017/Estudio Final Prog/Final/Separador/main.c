#include <stdio.h>
#include <stdlib.h>
#include "separador.h"

int main()
{
    char frase[500];
    printf("Ingrese una frase:");
    gets(frase);
    reemplazar_separador(frase);
    printf("\n%s", frase);
}
