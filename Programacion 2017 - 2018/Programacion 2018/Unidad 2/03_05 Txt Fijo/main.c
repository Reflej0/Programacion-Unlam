#include <stdio.h>
#include <stdlib.h>
#include "archivo.h"

int main()
{
    ///LEER TXT VARIABLE.
    /*
    char directorio[200];
    printf("Ingrese el directorio:");
    gets(directorio);
    printf("Listado de empleados:\n");
    leer_txt_variable(directorio);
    */
    ///LEER TXT FIJO.

    char directorio[200];
    printf("Ingrese el directorio:");
    gets(directorio);
    printf("Listado de empleados:\n");
    leer_txt_fijo(directorio);


    ///BIN -> TXT VARIABLE.
    /*
    char directorio_bin[200];
    char directorio_txt[200];
    printf("Ingrese el dir bin:");
    gets(directorio_bin);
    printf("Ingrese el dir txt:");
    gets(directorio_txt);
    bin_a_txt_variable(directorio_bin, directorio_txt);
    */

    ///BIN -> TXT FIJO.
    /*
    char directorio_bin[200];
    char directorio_txt[200];
    printf("Ingrese el dir bin:");
    gets(directorio_bin);
    printf("Ingrese el dir txt:");
    gets(directorio_txt);
    bin_a_txt_fijo(directorio_bin, directorio_txt);
    */

    ///TXT VARIABLE -> BIN Y LEER BIN.
    /*
    char directorio_txt[200];
    char directorio_bin[200];
    printf("Ingrese el dir txt:");
    gets(directorio_txt);
    printf("Ingrese el dir bin:");
    gets(directorio_bin);
    txt_variable_a_bin(directorio_txt, directorio_bin);
    printf("Listado de empleados:\n");
    leer_bin(directorio_bin);
    */

    ///TXT FIJO -> BIN Y LEER BIN.
    /*
    char directorio_txt[200];
    char directorio_bin[200];
    printf("Ingrese el dir txt:");
    gets(directorio_txt);
    printf("Ingrese el dir bin:");
    gets(directorio_bin);
    txt_fijo_a_bin(directorio_txt, directorio_bin);
    printf("Listado de empleados:\n");
    leer_bin(directorio_bin);
    */

    return 1;
}
