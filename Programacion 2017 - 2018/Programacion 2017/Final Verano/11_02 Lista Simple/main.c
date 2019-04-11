#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

int main()
{
    T_lista lista;
    crear_lista(&lista);
    T_dato dato = 101;
    T_dato dato2 = 40;
    T_dato dato3 = 200;
    T_dato dato4 = -11;
    T_dato dato5 = 55;
    T_dato aux = 0;
    ///AGREGAR AL PRINCIPIO.
    /*agregar_principio(&lista, &dato);
    agregar_principio(&lista, &dato2);
    agregar_principio(&lista, &dato3);
    agregar_principio(&lista, &dato4);
    mostrar_lista(&lista);*/
    ///AGREGAR AL FINAL.
    /*agregar_final(&lista, &dato);
    agregar_final(&lista, &dato2);
    agregar_final(&lista, &dato3);
    agregar_final(&lista, &dato4);
    mostrar_lista(&lista);*/
    ///AGREGAR ORDENADO.
    /*agregar_ordenado(&lista, &dato, cmp);
    agregar_ordenado(&lista, &dato2, cmp);
    agregar_ordenado(&lista, &dato3, cmp);
    agregar_ordenado(&lista, &dato4, cmp);
    agregar_ordenado(&lista, &dato5, cmp);
    mostrar_lista(&lista);*/
    ///AGREGAR MIXTO.
    /*agregar_principio(&lista, &dato);
    agregar_final(&lista, &dato2);
    agregar_ordenado(&lista, &dato3, cmp);
    mostrar_lista(&lista);*/
    ///ELIMINAR PRINCIPIO.
    /*agregar_principio(&lista, &dato);
    agregar_final(&lista, &dato2);
    agregar_ordenado(&lista, &dato3, cmp);
    eliminar_principio(&lista, &aux);
    mostrar_lista(&lista);
    */
    ///ELIMINAR ULTIMO.
    /*agregar_principio(&lista, &dato);
    agregar_final(&lista, &dato2);
    agregar_ordenado(&lista, &dato3, cmp);
    eliminar_ultimo(&lista, &aux);
    mostrar_lista(&lista);*/
    ///ELIMINAR VALOR.
    /*agregar_principio(&lista, &dato);
    agregar_final(&lista, &dato2);
    agregar_ordenado(&lista, &dato3, cmp);
    eliminar_valor(&lista, &dato, cmp);
    mostrar_lista(&lista);*/
    ///ELIMINAR INDICE
    /*agregar_principio(&lista, &dato);
    agregar_final(&lista, &dato2);
    agregar_ordenado(&lista, &dato3, cmp);
    eliminar_indice(&lista, &dato, 2);
    mostrar_lista(&lista);*/
    ///ORDENAR LISTA (LISTA AUXILIAR Y PRIMITIVAS SACAR E INSERTAR).
    agregar_principio(&lista, &dato);
    agregar_principio(&lista, &dato2);
    agregar_principio(&lista, &dato3);
    agregar_principio(&lista, &dato4);
    agregar_principio(&lista, &dato5);
    mostrar_lista(&lista);
    printf("\n--------------DESPUES DEL ORDENAMIENTO----------------\n");
    ordenar_lista(&lista, cmp);
    mostrar_lista(&lista);
}
