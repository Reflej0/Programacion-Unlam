#include <stdio.h>
#include <stdlib.h>
#include "arbol.h"

int main()
{
    ///CREACION DEL ARBOL Y LOTE DE PRUEBA.
    T_arbol arbol;
    crear_arbol(&arbol);
    printf("Introduzca el directorio del archivo para crear el arbol:\n");
    //EJ C:\carpeta\arbol_arch.dat
    char dir[200] = "";
    FILE* arch = fopen(gets(dir), "rb");
    cargar_arbol_de_archivo_ord(&arbol, arch);
    int cant_nodos_hoj = cant_nodos_hoja(&arbol);
    int cant_nodos_int = contar_nodos_internos(&arbol);
    printf("La cantidad de nodos internos antes de podar:%d", cant_nodos_int);
    system("PAUSE");
    printf("La cantidad de nodos hoja antes de podar:%d", cant_nodos_hoj);
    printf("\n");
    printf("ANTES DE PODAR:\n");
    mostrarPreOrden(&arbol);
    int cant_nodos = podar_arbol_dde_nivel_cant_nodos(&arbol, 1);
    printf("DESPUES DE PODAR:\n");
    mostrarPreOrden(&arbol);
    printf("NODOS PODADOS: %d", cant_nodos);
}
