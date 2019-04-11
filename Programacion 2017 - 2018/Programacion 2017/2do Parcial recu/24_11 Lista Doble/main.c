#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

int main()
{
    T_lista lista;
    crear_lista(&lista);
    ///LOTE DE DATOS.
    T_dato n1 = 5;
    T_dato n2 = 10;
    T_dato n3 = 15;
    T_dato n4 = 25;
    T_dato n5 = 50;
    T_dato aux;
    ///AGREGAR AL PRINCIPIO.
    /*agregar_al_principio(&lista, &n1);
    agregar_al_principio(&lista, &n2);
    agregar_al_principio(&lista, &n3);*/
    ///AGREGAR AL FINAL.
    /*agregar_al_final(&lista, &n1);
    agregar_al_final(&lista, &n2);
    agregar_al_final(&lista, &n3);
    agregar_al_final(&lista, &n4);
    agregar_al_final(&lista, &n5);*/
    ///AGREGAR ORDENADO
    agregar_ordenado(&lista, &n1, cmp);
    agregar_ordenado(&lista, &n2, cmp);
    agregar_ordenado(&lista, &n3, cmp);
    agregar_ordenado(&lista, &n4, cmp);
    agregar_ordenado(&lista, &n5, cmp);
    ///ELIMINAR DATOS.
    /*
    eliminar_primero(&lista, &aux);
    eliminar_ultimo(&lista, &aux);*/
    printf("\nINGRESE UN NUMERO A ELIMINAR: ");
    scanf("%d", &aux);
    eliminar_valor_lista(&lista, &aux, cmp);
    T_dato numero;
    printf("\nINGRESE UN NUMERO A AGREGAR:");
    scanf("%d", &numero);
    agregar_ordenado(&lista, &numero, cmp);
    ///VER LISTA.
    ver_lista_desde_principio(&lista);
    //ver_lista_desde_final(&lista);
    ///BUSQUEDA EN LA LISTA.
    printf("\nINGRESE UN NUMERO A BUSCAR: ");
    scanf("%d", &aux);
    int encontrado = buscar_valor_lista(&lista, &aux, cmp);
    printf("\nEl valor fue encontrado: %d", encontrado);
}
