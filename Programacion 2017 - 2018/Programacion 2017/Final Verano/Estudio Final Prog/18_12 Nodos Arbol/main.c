#include <stdio.h>
#include <stdlib.h>
#include "arbol.h"

int main()
{
    T_arbol arbol;
    crear_arbol(&arbol);
    printf("Introduzca el directorio del archivo para crear el arbol:\n");
    //EJ C:\carpeta\arbol_arch.dat
    char dir[200] = "";
    FILE* arch = fopen(gets(dir), "rb");
    cargar_arbol_de_arch(&arbol, arch);
    printf("La cantidad de nodos totales: %d\n", contar_nodos_totales(&arbol));
    printf("La cantidad de hojas totales: %d\n", contar_nodos_hojas(&arbol));
    printf("La cantidad de nodos internos: %d\n", contar_nodos_internos(&arbol));
}
