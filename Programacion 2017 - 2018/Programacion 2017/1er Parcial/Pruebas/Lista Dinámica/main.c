#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

int main()
{
    T_lista lista;
    crear_lista(&lista);
    T_dato dato = 5;
    T_dato dato2 = 3;
    T_dato dato3 = 9;
    T_dato dato4 = 7;
    T_dato dato5 = 2;
    T_dato aux = 0;
    agregar_principio(&lista, &dato); // ANDA OK.
    agregar_principio(&lista, &dato2);// ANDA OK.
    agregar_final(&lista, &dato3); // ANDA OK.
    agregar_ordenado(&lista, &dato4, cmp); // ANDA OK.
    //eliminar_principio(&lista, &aux); // ANDA OK.
    //eliminar_ultimo(&lista, &aux); // ANDA OK.
    //eliminar_lista(&lista);
    //eliminar_indice(&lista, &aux, 0);
    mostrar_lista(&lista);
    //printf("\nElementos de la lista:%d", cantidad_elementos(&lista));
    //agregar_ordenado(&lista, &dato5, cmp);
    printf("\n--------------ANTES DEL ORDENAMIENTO----------------");
    ordenar_lista(&lista, cmp);
    mostrar_lista(&lista);
}
