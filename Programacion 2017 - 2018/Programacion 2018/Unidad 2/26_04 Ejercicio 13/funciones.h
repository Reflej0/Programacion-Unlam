#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

typedef struct
{
    long int dni;
    char apellido[20];
    char nombre[20];
    float promedio;
} T_estudiante;

typedef struct
{
    long int dni;
    char apellido[20];
    char nombre[20];
    double sueldo;
} T_empleado;

int generacion_estudiantes(char* directorioestudiantes);

int generacion_empleados(char* directorioempleados);

int mostrar_estudiantes(char* directorioestudiantes);

int mostrar_empleados(char* directorioempleados);

int actualizacion_sueldo(char* directorioestudiantes, char* directorioempleados);

int es_mismo_estudiante_empleado(T_estudiante *est, T_empleado *emp);

#endif // FUNCIONES_H_INCLUDED
