#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cadena.h"

int main()
{
    char* s = "Hola soy una cadena un poco larga";
    char s1[11];
    char s2[30] = "Pajaro";
    char s3[15] = "HOLAxxx";
    char s4[10] = "ZHOLA";
    char nombre[] = "    *!@#(!*#j!#!#uAN    Ig123-nACIO     ";
    char numero[11];
    _strncpy(s1, s, 10);
    _strncat(s2, s, 5);
    ///SALIDAS POR PANTALLA.
    //printf("Son iguales: %d", _strncmp(s3, s4, 4));
    printf("_strcspn: %d", _strcspn("ABCDEF4960910", "013"));
    printf("\n_strpbrk: %s", _strpbrk("Este es un texto Simple.", "me"));
    printf("\n_strstr: %s", _strstr("Este es un texto Simple.", "tex"));
    printf("\nNombre normalizado:%s", normalizar_nombre(nombre));
    printf("\nCoincidencias: %d", _strstrcantidad("analavalalanadelanagrama", "ana"));
    printf("\nBusco ana y lo reemplazo por STRUCT:%s", reemplazar_identicos("analavalalanadelanagrama", "ana", "STRUCT"));
    printf("\nNumero 10405: %s", __itoa(10405, numero, 2));
    //puts(s2);
    return 0;
}
