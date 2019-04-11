#include <stdio.h>
#include <stdlib.h>
#include "lista.h"
#include "auxiliares_lista.h"

int main()
{
    T_lista lista;
    crear_lista(&lista);
    T_dato dos = 2;
    T_dato tres = 3;
    T_dato menosuno = -1;
    T_dato veinte = 20;
    T_dato aux;
    //agregar_al_final(&lista, &uno);
    //agregar_al_final(&lista, &dos);
    //agregar_al_final(&lista, &tres);
    //agregar_al_principio(&lista, &menosuno);
    //printf("Cantidad: %d\n", contar_elementos_lista(&lista));
    //printf("Se encuentra el numero en la lista: %d\n", buscar_clave(&lista, &aux, comp_int));
    //eliminar_principio(&lista, &aux);
    agregar_ordenado(&lista, &veinte, comp_int);
    agregar_ordenado(&lista, &tres, comp_int);
    agregar_ordenado(&lista, &menosuno, comp_int);
    agregar_ordenado(&lista, &dos, comp_int);
    mostrar_lista(&lista, mostrar_int);
    return 0;
}
