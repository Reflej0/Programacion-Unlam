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
    //cargaAutomatica(&arbol, cmp); // SE PRUEBA TAMBIEN INSERTAR EN ARBOL.
    ///PRUEBA DE BUSQUEDA.
    /*T_dato numero;
    printf("Ingrese el dato a buscar:");
    scanf("%d", &numero);
    int resp = buscar_en_arbol(&arbol, &numero, cmp);
    printf("El dato fue encontrado: %d", resp);*/
    ///PRUEBA DE ALTURA
    //printf("ALTURA DEL ARBOL:%d", altura_arbol(&arbol));
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
    //printf("Es arbol completo:%d", es_arbol_completo(&arbol));
    //printf("\nEs arbol AVL:%d", es_arbol_avl(&arbol));
    //printf("\nEs arbol balanceado:%d", es_arbol_balanceado(&arbol));
    ///PRUEBA PODAR ARBOL.
    podar_arbol_dde_nivel(&arbol, 2);
    mostrar_arbol_in(&arbol);
    //fclose(arch);
}
