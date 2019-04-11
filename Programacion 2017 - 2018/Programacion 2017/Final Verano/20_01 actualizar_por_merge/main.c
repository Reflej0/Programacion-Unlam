#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int main()
{
    Empleado Empleados[10];
    Estudiante Estudiantes[10];
    //ingresar_empleados(Empleados);
    //ingresar_estudiantes(Estudiantes);
    FILE *f_empleados = fopen("empleados.dat", "rb+"); // Archivo donde estan almacenados los empleados ingresados.
    FILE *f_estudiantes = fopen("estudiantes.dat", "rb+");
    printf("EMPLEADOS:\n");
    mostrar_empleados(f_empleados);
    printf("ESTUDIANTES:\n");
    mostrar_estudiantes(f_estudiantes);
    Actualizar_Sueldo(f_empleados, f_estudiantes);
    printf("EMPLEADOS:\n");
    mostrar_empleados(f_empleados);
    printf("ESTUDIANTES:\n");
    mostrar_estudiantes(f_estudiantes);
    fclose(f_empleados);
    fclose(f_estudiantes);
}
