#include <stdio.h>
#include <stdlib.h>
#include "ejercicio12.h"

int main()
{
    char alumnos[100][50];
    float calificaciones[100][7];
    inicializar_matriz(alumnos);
    inicializar_matriz_float(calificaciones);
    int cantidad_alumnos = ingresar_alumnos(alumnos);
    visualizar_alumnos(alumnos, cantidad_alumnos);
    ingresar_notas(calificaciones, cantidad_alumnos);
    promediar_notas(calificaciones, cantidad_alumnos);
}
