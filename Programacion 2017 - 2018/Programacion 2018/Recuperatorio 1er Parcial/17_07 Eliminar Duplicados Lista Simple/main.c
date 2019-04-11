#include <stdio.h>
#include <stdlib.h>
#include "auxiliares.h"
#include "lista.h"

int main()
{
    T_dato a1 = {1, 101};
    T_dato a2 = {99, 303};
    T_dato a3 = {145, 1010};
    T_dato a4 = {77, 404};
    T_dato a5 = {3, 202};
    T_dato a6 = {88, 202};
    T_dato a7 = {30, 202};
    T_lista lista;
    crear_lista(&lista);
    agregar_al_final(&lista, &a1);
    agregar_al_final(&lista, &a2);
    agregar_al_final(&lista, &a3);
    agregar_al_final(&lista, &a4);
    agregar_al_final(&lista, &a5);
    agregar_al_final(&lista, &a6);
    agregar_al_final(&lista, &a7);
    /*agregar_ordenado(&lista, &a1, cmp_dato);
    agregar_ordenado(&lista, &a2, cmp_dato);
    agregar_ordenado(&lista, &a3, cmp_dato);*/
    /*eliminar_final(&lista, &a1);
    eliminar_final(&lista, &a1);
    eliminar_final(&lista, &a1);*/
    //eliminar_info(&lista, &a1, cmp_dato);
    ordenar_lista(&lista, cmp_dato);
    //eliminar_duplicados(&lista, cmp_dato);
    T_dato mejores[3];
    mejores_n_lista(&lista, 3, mejores, cmp_dato);
    printf("PRIMERO: %d\n", mejores[0].clave);
    printf("SEGUNDO: %d\n", mejores[1].clave);
    printf("TERCERO: %d\n", mejores[2].clave);
    //mostrar_lista(&lista, show);
    return 0;
}
