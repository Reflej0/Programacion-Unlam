#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

int main()
{
    T_dato pri = 99;
    T_dato sec = -100;
    T_dato ter = 55;
    T_dato cuar = 88;
    T_dato qui = 0;
    T_dato sex = 99;
    T_dato sep = 0;
    T_dato oct = 0;
    T_dato nov = 1200;
    T_dato die = -100;
    T_dato onc = -100;
    T_dato doc = 2500;
    T_dato eliminar = 55;
    T_lista lista;
    crear_lista(&lista);
    agregar_ordenado_lista(&lista, &pri, comp_int);
    agregar_ordenado_lista(&lista, &sec, comp_int);
    agregar_ordenado_lista(&lista, &ter, comp_int);
    agregar_ordenado_lista(&lista, &cuar, comp_int);
    agregar_ordenado_lista(&lista, &qui, comp_int);
    agregar_ordenado_lista(&lista, &sex, comp_int);
    agregar_ordenado_lista(&lista, &sep, comp_int);
    agregar_ordenado_lista(&lista, &oct, comp_int);
    agregar_ordenado_lista(&lista, &nov, comp_int);
    agregar_ordenado_lista(&lista, &die, comp_int);
    agregar_ordenado_lista(&lista, &onc, comp_int);
    agregar_ordenado_lista(&lista, &doc, comp_int);
    eliminar_de_lista(&lista, &eliminar, comp_int);
    eliminar_duplicados(&lista, comp_int);
    mostrar_desde_principio(&lista, mostrar_int);
    return 1;
}
