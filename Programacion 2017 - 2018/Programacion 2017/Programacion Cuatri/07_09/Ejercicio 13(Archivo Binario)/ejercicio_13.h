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

int hayDatos();

void mostrar_empleados(FILE *f_empleados);

int guardar_empleados(Empleado *Empleados, int tam);

int guardar_estudiantes(Estudiante *Estudiantes, int tam);

void ingresar_empleados(Empleado *Empleados);

void ingresar_estudiantes();

void Actualizar_Sueldo(FILE *f_empleados, FILE *f_estudiantes);

void parsetxt(FILE *bin, FILE *txt);

#endif // EJERCICIO_13_H_INCLUDED
