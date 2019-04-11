#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

int main()
{
    T_dato mensaje = 3;
    T_dato mensaje2 = 5;
    T_dato mensaje3 = 4;
    T_lista lista;
    crear_lista(&lista);
    poner_en_lista_principio(&lista, &mensaje); //Primero pongo el 3.
    poner_en_lista_final(&lista, &mensaje2); // Despues pongo el 5 al final.
    poner_en_lista_ord(&lista, &mensaje3, cmp_int); // Despues pongo el 4 en el medio.
    mostrar_lista(&lista); // Debe mostrar 3, 4, 5.
    /*T_dato respuesta = 0;
    buscar_en_lista_por_posicion(&lista, 2, &respuesta);
    //printf("%d", respuesta);
    int posicion = buscar_en_lista_por_clave(&lista, &mensaje);
    printf("%d", posicion);*/
}
