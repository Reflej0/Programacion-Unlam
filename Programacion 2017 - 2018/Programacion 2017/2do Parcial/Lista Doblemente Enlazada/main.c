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
    agregar_al_final(&lista, &n1);
    agregar_al_final(&lista, &n2);
    agregar_al_final(&lista, &n3);
    agregar_al_final(&lista, &n4);
    agregar_al_final(&lista, &n5);
    T_dato numero;
    printf("Ingrese un numero:");
    scanf("%d", &numero);
    agregar_ordenado(&lista, &numero, cmp);
    ///ELIMINAR DATOS.
    /*
    eliminar_primero(&lista, &aux);
    eliminar_ultimo(&lista, &aux);*/
    //eliminar_valor_lista(&lista, &n4, cmp);
    ///VER LISTA.
    ver_lista_desde_principio(&lista);
    //ver_lista_desde_final(&lista);
    ///BUSQUEDA EN LA LISTA.
    printf("\nINGRESE UN NUMERO A BUSCAR: ");
    scanf("%d", &aux);
    int encontrado = buscar_valor_lista(&lista, &aux, cmp);
    printf("\nEl valor fue encontrado: %d", encontrado);
}
