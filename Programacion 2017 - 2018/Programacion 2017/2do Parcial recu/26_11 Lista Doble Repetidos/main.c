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
    /*T_dato n1 = 5;
    T_dato n2 = 5;
    T_dato n3 = 5;
    T_dato n4 = 5;
    T_dato n5 = 5;
    T_dato n6 = 5;
    T_dato n7 = 5;
    T_dato n8 = 5*/;
    ///LOTE DE PRUEBA 3.
    /*T_dato n1 = 5;
    agregar_al_principio(&lista, &n1);*/
    ///AGREGAR ORDENADO
    agregar_al_principio(&lista, &n1);
    agregar_al_principio(&lista, &n2);
    agregar_al_principio(&lista, &n3);
    agregar_al_principio(&lista, &n4);
    agregar_al_principio(&lista, &n5);
    agregar_al_principio(&lista, &n6);
    agregar_al_principio(&lista, &n7);
    agregar_al_principio(&lista, &n8);
    printf("LISTA CON DUPLICADOS:\n");
    ver_lista_desde_principio(&lista);
    eliminar_duplicados(&lista, cmp);
    ///VER LISTA.
    printf("LISTA SIN DUPLICADOS:\n");
    ver_lista_desde_principio(&lista);

}
