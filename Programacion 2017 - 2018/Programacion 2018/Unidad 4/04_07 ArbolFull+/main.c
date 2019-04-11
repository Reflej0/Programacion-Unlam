#include <stdio.h>
#include <stdlib.h>
#include "arbol.h"

int main()
{
    ///CREAR ARBOL.
    T_arbol a;
    crear_arbol(&a);
    ///APERTURA ARCHIVO.
    FILE* arch = fopen("arbol_arch.dat", "rb");
    if(!arch) return 0; // ERROR.
    ///CARGAR ARBOL
    cargar_arbol_de_archivo_ord(&a, arch);
    ///FUNCIONES ARBOL
    printf("Cantidad de nodos del arbol: %d", contar_mostrar_nodos(&a));
    system("CLS");
    printf("Cantidad de hojas del arbol: %d", contar_mostrar_hojas(&a));
    system("CLS");
    printf("Cantidad de no-hojas del arbol: %d", contar_mostrar_nohojas(&a));
    system("CLS");
    printf("Cantidad de nodos con hijo izq: %d", contar_nodos_hijos_izq(&a));
    system("CLS");
    printf("Cantidad de nodos con hijo der: %d", contar_nodos_hijos_der(&a));
    system("CLS");
    printf("Cantidad de nodos de nivel 1: %d", mostrar_contar_nodos_de_altura(&a, 1));
    system("CLS");
    printf("Cantidad de nodos hasta nivel 2: %d", mostrar_contar_nodos_hasta_altura(&a, 2));
    system("CLS");
    printf("Cantidad de hojas podadas: %d", contar_podar_hojas(&a));
    return 1;
}
