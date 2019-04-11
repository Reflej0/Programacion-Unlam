#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

int main()
{
    T_lista lista;
    crear_lista(&lista);
    ///LOTE DE PRUEBA 1.
    T_dato n1 = 5;
    T_dato n2 = 5;
    T_dato n3 = 10;
    T_dato n4 = 15;
    T_dato n5 = 15;
    T_dato n6 = 15;
    T_dato n7 = 30;
    T_dato n8 = 45;
    ///LOTE DE PRUEBA 2.
    /*T_dato n1 = 9;
    T_dato n2 = 10;
    T_dato n3 = 11;
    T_dato n4 = 33;
    T_dato n5 = 22;
    T_dato n6 = 17;
    T_dato n7 = 19;
    T_dato n8 = 14;*/
    ///LOTE DE PRUEBA 3.
    /*T_dato n1 = 5;
    agregar_al_principio(&lista, &n1);*/
    ///LOTE DE PRUEBA 4.
    /*T_dato n1 = -1;
    T_dato n2 = -2;
    T_dato n3 = 55;
    T_dato n4 = 99;
    T_dato n5 = 14;
    T_dato n6 = 11;
    T_dato n7 = -3;
    T_dato n8 = 100;*/
    ///AGREGAR ORDENADO
    agregar_ordenado(&lista, &n1, cmp);
    agregar_ordenado(&lista, &n2, cmp);
    agregar_ordenado(&lista, &n3, cmp);
    agregar_ordenado(&lista, &n4, cmp);
    agregar_ordenado(&lista, &n5, cmp);
    agregar_ordenado(&lista, &n6, cmp);
    agregar_ordenado(&lista, &n7, cmp);
    agregar_ordenado(&lista, &n8, cmp);
    ///ELIMINAR VALOR DE LISTA.
    /*eliminar_valor_lista(&lista, &n4, cmp);
    eliminar_valor_lista(&lista, &n5, cmp);
    eliminar_valor_lista(&lista, &n1, cmp);
    eliminar_valor_lista(&lista, &n2, cmp);*/
    ///ORDENAR LISTA.
    /*agregar_al_principio(&lista, &n1);
    agregar_al_principio(&lista, &n2);
    agregar_al_principio(&lista, &n3);
    agregar_al_principio(&lista, &n4);
    agregar_al_principio(&lista, &n5);
    agregar_al_principio(&lista, &n6);
    agregar_al_principio(&lista, &n7);
    agregar_al_principio(&lista, &n8);
    ordenar_lista(&lista, cmp);*/
    ///ELIMINAR DUPLICADOS.
    eliminar_duplicados(&lista, cmp);
    printf("LISTA:\n");
    ver_lista_desde_principio(&lista);
}
