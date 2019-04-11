#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

int main()
{
    T_dato a = 33;
    T_dato b = -100;
    T_dato c = 99;
    T_dato d = -80;
    T_lista lista;
    crear_lista(&lista);
    agregar_al_principio(&lista, &a);
    agregar_al_principio(&lista, &b);
    agregar_al_principio(&lista, &c);
    agregar_al_principio(&lista, &d);
    ordenar_lista(&lista, comp_int);
    mostrar_lista(&lista, mostrar_normal);
    return 0;
}
