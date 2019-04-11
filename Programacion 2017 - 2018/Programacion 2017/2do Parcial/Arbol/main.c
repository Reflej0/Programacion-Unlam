#include <stdio.h>
#include <stdlib.h>
#include "arbol.h"

int main()
{
    T_arbol arbol;
    crear_arbol_bin(&arbol);
    cargaAutomatica(&arbol, cmp);
    size_t altura_arbol = altura_arbol_bin(&arbol);
    printf("La altura del arbol es: %d", altura_arbol);
    T_dato dato = 5;
    //T_dato no_dato = 99;
    size_t encontrado = buscar_en_arbol_bin(&arbol, &dato, cmp);
    printf("\nEl dato fue encontrado: %d", encontrado);
    printf("\n");
    mostrarPreOrden(&arbol);
    printf("\n");
    mostrarInOrden(&arbol);
    printf("\n");
    mostrarPosOrden(&arbol);
    ///-NO SE DEBE HACER, SOLO ES PARA PROBAR QUE FUNCIONA EL METODO.
    T_nodo** nodo = mayor(&arbol);
    printf("\nEl mayor es: %d", (*nodo)->info);
    nodo = menor(&arbol);
    printf("\nEl menor es: %d", (*nodo)->info);
    ///------------------------------------------------------------
    printf("\n1)Arbol Completo: %d", es_arbol_completo(&arbol));
    printf("\n1)Arbol Balanceado: %d", es_arbol_balanceado(&arbol));
    printf("\n1)Arbol AVL: %d", es_arbol_avl(&arbol));
    ///------------------------------------------------------------
    system("CLS");
    char directorio[100] = "";
    gets(directorio);

    FILE* arch_generado = fopen(directorio, "wb");
    generarArchivoArbol(arch_generado);
    fclose(arch_generado);

    T_arbol arbol_archivo;
    crear_arbol_bin(&arbol_archivo);
    FILE* arch = fopen(directorio, "rb");
    cargar_arbol_de_archivo_ord(&arbol_archivo,arch);
    mostrarInOrden(&arbol_archivo);
    fclose(arch);
}
