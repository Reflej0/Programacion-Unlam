#include <stdio.h>
#include <stdlib.h>
#include "ordenamiento.h"

int main()
{
    size_t cantidad_alumnos = 5;
    T_alumno alumnos[cantidad_alumnos];
    ingresar_lote_alumnos(alumnos);
    ordenar_alumnos(alumnos, cantidad_alumnos, cmp_alu);
    mostrar_alumnos(alumnos, cantidad_alumnos);
}
