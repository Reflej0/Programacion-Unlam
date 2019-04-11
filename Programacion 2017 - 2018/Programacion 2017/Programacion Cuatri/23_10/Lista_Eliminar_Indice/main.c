#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

int main()
{
    T_dato mensaje = 3;
    T_dato mensaje2 = 5;
    T_dato mensaje3 = 4;
    T_lista lista;
    T_lista lista_ordenada;
    crear_lista(&lista);
    crear_lista(&lista_ordenada);
    poner_en_lista_principio(&lista, &mensaje);
    poner_en_lista_principio(&lista, &mensaje2);
    poner_en_lista_principio(&lista, &mensaje3);
    ordenar_lista(&lista, cmp_int, &lista_ordenada);
    T_dato aux;
    eliminar_indice(&lista, &aux, 1);
    mostrar_lista(&lista); // Debe mostrar 4, 5, 3
    printf("\n--------------LISTA ORDENADA---------------");
    mostrar_lista(&lista_ordenada);
    //T_dato respuesta = 0;
    //buscar_en_lista_por_posicion(&lista, 2, &respuesta);
    //printf("%d", respuesta);
    //int posicion = buscar_en_lista_por_clave(&lista, &mensaje);
    //printf("%d", posicion);
}
