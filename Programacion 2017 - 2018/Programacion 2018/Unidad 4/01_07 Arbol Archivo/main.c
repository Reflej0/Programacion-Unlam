#include <stdio.h>
#include <stdlib.h>
#include "arbol.h"

int main()
{
    ///CREACION DEL ARBOL.
    T_arbol arbol;
    crear_arbol(&arbol);
    ///CARGA DEL ARBOL DESDE ARCHIVO.
    FILE* arch = fopen("arbol_arch.txt", "rt");
    leer_arbol_archivo_txt(&arbol, arch);
    fclose(arch);
    ///RECORRIDA DEL ARBOL EN PREORDEN.
    mostrar_arbol_pre(&arbol);
    return 1;
}
