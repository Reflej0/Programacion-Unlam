#include <stdio.h>
#include <stdlib.h>
#include "arbol.h"

int main()
{
    ///CREACION DEL ARBOL Y LOTE DE PRUEBA.
    T_arbol arbol;
    crear_arbol(&arbol);
    //FILE* arch = fopen("arbol_arch.dat", "rb"); //APERTURA DE ARCHIVO.
    //cargar_arbol_de_archivo_ord(&arbol, arch);
    //fclose(arch); //CIERRE DE ARCHIVO.
    FILE* arch = fopen("arbol_arch_new.dat", "rb");
    leer_arbol_archivo(&arbol, arch);
    fclose(arch);
    int i = 0;
    ver_arbol_y_nodos(&arbol, i);
    printf("La cantidad de nodos del arbol es: %d", cant_nodos(&arbol));
    printf("\nLa cantidad de nodos internos del arbol es: %d", cant_nodos_internos(&arbol));
    printf("\nLa cantidad de hojas del arbol es: %d", cant_hojas(&arbol));
    //cargaAutomatica(&arbol, cmp); // SE PRUEBA TAMBIEN INSERTAR EN ARBOL.
    ///PRUEBA DE BUSQUEDA.
    /*T_dato numero;
    printf("Ingrese el dato a buscar:");
    scanf("%d", &numero);
    int resp = buscar_en_arbol(&arbol, &numero, cmp);
    printf("El dato fue encontrado: %d", resp);*/
    ///PRUEBA DE ALTURA
    printf("\nALTURA DEL ARBOL:%d\n", altura_arbol(&arbol));
    ///PRUEBA DE PRE, IN, POS.
    //mostrar_arbol_pre(&arbol);
    //mostrar_arbol_in(&arbol);
    //mostrar_arbol_pos(&arbol);
    ///PRUEBA ELIMINAR ARBOL.
    /*eliminar_arbol(&arbol);
    mostrar_arbol_pre(&arbol);*/
    ///PRUEBA ELIMINAR DEL ARBOL
    /*T_dato numero;
    printf("Ingrese el dato a eliminar:");
    scanf("%d", &numero);
    eliminar_de_arbol(&arbol, &numero, cmp);
    mostrar_arbol_pre(&arbol);*/
    ///PRUEBA  TIPOS DE ARBOL.
    /*printf("Es arbol completo:%d", es_arbol_completo(&arbol));
    printf("\nEs arbol AVL:%d", es_arbol_avl(&arbol));
    printf("\nEs arbol balanceado:%d", es_arbol_balanceado(&arbol));*/
    ///PRUEBA PODAR ARBOL.
    podar_arbol_dde_nivel(&arbol, 2);
    mostrar_arbol_pre(&arbol);
    return 1;
}
