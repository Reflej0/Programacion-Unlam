#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

int main()
{
    T_lista lista;
    crear_lista(&lista);
    T_dato a = 99;
    T_dato b = 66;
    T_dato c = -100;
    T_dato d = 44;
    agregar_ordenado_no_duplicados(&lista, &a, comp_dato, tratamiento);
    agregar_ordenado_no_duplicados(&lista, &b, comp_dato, tratamiento);
    agregar_ordenado_no_duplicados(&lista, &c, comp_dato, tratamiento);
    agregar_ordenado_no_duplicados(&lista, &d, comp_dato, tratamiento);
    mostrar_lista(&lista, mostrar_dato);
    return 1;
}
