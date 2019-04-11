#include <stdio.h>
#include <stdlib.h>
#include "auxiliares.h"
#include "lista.h"

int main()
{
    T_dato a1 = {1, 101};
    T_dato a2 = {3, 303};
    T_dato a3 = {10, 1010};
    T_dato a4 = {4, 404};
    T_dato a5 = {2, 202};
    T_lista lista;
    crear_lista(&lista);
    agregar_al_final(&lista, &a1);
    agregar_al_final(&lista, &a2);
    agregar_al_final(&lista, &a3);
    agregar_al_final(&lista, &a4);
    agregar_al_final(&lista, &a5);
    /*agregar_ordenado(&lista, &a1, cmp_dato);
    agregar_ordenado(&lista, &a2, cmp_dato);
    agregar_ordenado(&lista, &a3, cmp_dato);*/
    /*eliminar_final(&lista, &a1);
    eliminar_final(&lista, &a1);
    eliminar_final(&lista, &a1);*/
    //eliminar_info(&lista, &a1, cmp_dato);
    ordenar_lista(&lista, cmp_dato);
    mostrar_lista(&lista, show);
    return 0;
}
