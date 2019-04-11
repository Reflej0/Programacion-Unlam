#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

int main()
{
    T_lista lista;
    crear_lista(&lista);
    ///LOTE DE DATOS.
    T_dato n1 = 5;
    T_dato n2 = 5;
    T_dato n3 = 15;
    T_dato n4 = 25;
    T_dato n5 = 25;
    T_dato aux;
    ///AGREGAR AL PRINCIPIO.
    agregar_al_principio(&lista, &n1);
    agregar_al_principio(&lista, &n2);
    agregar_al_principio(&lista, &n3);
    agregar_al_principio(&lista, &n4);
    agregar_al_principio(&lista, &n5);
    ///AGREGAR AL FINAL.
    /*agregar_al_final(&lista, &n1);
    agregar_al_final(&lista, &n2);
    agregar_al_final(&lista, &n3);
    agregar_al_final(&lista, &n4);
    agregar_al_final(&lista, &n5);
    ver_lista_desde_principio(&lista);*/
    ///ELIMINAR DATOS.
    eliminar_duplicados(&lista, cmp);
    ver_lista_desde_principio(&lista);
}
