#include <stdio.h>
#include <stdlib.h>
#include "lista.h"
#include <string.h>

int main()
{
    T_dato alu1;
    alu1.dni = 1;
    strcpy(alu1.apyn, "Juan");
    T_dato alu2;
    alu2.dni = 9;
    strcpy(alu2.apyn, "Marcelo");
    T_dato alu3;
    alu3.dni = 5;
    strcpy(alu3.apyn, "Tomas");
    T_lista lista;
    crear_lista(&lista);
    agregar_principio(&lista, &alu1);
    agregar_final(&lista, &alu2);
    agregar_ordenado(&lista, &alu3, cmp_alu);
    /*T_dato aux;
    eliminar_indice(&lista, &aux, 1);
    buscar_indice(&lista, &aux, 1);
    printf("Nombre del alumno: %s", aux.apyn);*/
    mostrar_lista(&lista);
    printf("\n------------LISTA ORDENADA------------------");
    ordenar_lista(&lista);
    mostrar_lista(&lista);
    T_dato aux;
    buscar_indice(&lista, &aux, 1);
}
