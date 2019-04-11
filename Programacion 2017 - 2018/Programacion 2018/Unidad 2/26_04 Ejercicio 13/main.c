#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int main()
{
    char* directorio_est = "estudiantes.dat";
    char* directorio_emp = "empleados.dat";
    generacion_estudiantes(directorio_est);
    //mostrar_estudiantes(directorio_est);
    generacion_empleados(directorio_emp);
    //mostrar_empleados(directorio_emp);
    int actualizados = actualizacion_sueldo(directorio_est, directorio_emp);
    printf("Cantidad de sueldos actualizados: %d", actualizados);
    return 1;
}
