#ifndef EJERCICIO_13_H_INCLUDED
#define EJERCICIO_13_H_INCLUDED

typedef struct
{
    int dni;
    char apellido[20];
    char nombre[20];
    double sueldo;
} Empleado;

typedef struct
{
    int dni;
    char apellido[20];
    char nombre[20];
    float promedio;
} Estudiante;

void mostrar_empleados(FILE *f_empleados);

void mostrar_estudiantes(FILE *f_estudiantes);

int guardar_empleados(Empleado *Empleados, int tam);

int guardar_estudiantes(Estudiante *Estudiantes, int tam);

void ingresar_empleados(Empleado *Empleados);

void ingresar_estudiantes(Estudiante *Estudiantes);

void Actualizar_Sueldo(FILE *f_empleados, FILE *f_estudiantes);

#endif // EJERCICIO_13_H_INCLUDED
