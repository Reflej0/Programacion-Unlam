#include <stdio.h>
#include <stdlib.h>
#include <string.h> // Para el strcmp del while.
#include "ejercicio_13.h"

int guardar_empleados(Empleado *Empleados, int tam)
{
    FILE *f_empleados = fopen("empleados.dat", "wb");
    int i = 0;
    if(!f_empleados)
    {
        return 0;
    }
    while(i<tam)
    {
        fwrite(&Empleados[i], sizeof(Empleado), 1, f_empleados);
        i++;
    }
    fclose(f_empleados);
    return 1;
}

int guardar_estudiantes(Estudiante *Estudiantes, int tam)
{
    FILE *f_estudiantes = fopen("estudiantes.dat", "wb");
    if(!f_estudiantes)
    {
        return 0;
    }
    int i = 0;
    while(i<tam)
    {
        fwrite(&Estudiantes[i], sizeof(Estudiante), 1, f_estudiantes);
        i++;
    }
    fclose(f_estudiantes);
    return 1;
}

void ingresar_empleados(Empleado *Empleados)
{
    system("CLS");
    int i = 0;
    int seguir = 1;
    printf("Ingreso de empleados");
    while(seguir==1)
    {
        printf("\nDesea introducir un nuevo empleado?\n1)SI2)NO\nOpcion:");
        scanf("%d", &seguir);
        fflush(stdin);
        printf("\nIngrese el nombre del empleado:");
        gets(Empleados[i].nombre);
        fflush(stdin);
        printf("\nIngrese el apellido del empleado:");
        gets(Empleados[i].apellido);
        fflush(stdin);
        printf("\nIngrese el DNI del empleado:");
        scanf("%d", &Empleados[i].dni);
        printf("\nIngrese el Sueldo del empleado:");
        scanf("%lf", &Empleados[i].sueldo);
        i++;
    }
    guardar_empleados(Empleados, i); // No tengo que poner el & porque Empleados ya es direccion de memoria.
}

void ingresar_estudiantes(Estudiante *Estudiantes)
{
    system("CLS");
    int i = 0;
    int seguir = 1;
    printf("Ingreso de estudiantes");
    while(seguir==1)
    {
        printf("\nDesea introducir un nuevo estudiante?\n1)SI2)NO\nOpcion:");
        scanf("%d", &seguir);
        fflush(stdin);
        printf("\nIngrese el nombre del estudiante:");
        gets(Estudiantes[i].nombre);
        fflush(stdin);
        printf("\nIngrese el apellido del estudiante:");
        gets(Estudiantes[i].apellido);
        fflush(stdin);
        printf("\nIngrese el DNI del estudiante:");
        scanf("%d", &Estudiantes[i].dni);
        printf("\nIngrese el promedio del estudiante:");
        scanf("%f", &Estudiantes[i].promedio);
        i++;
    }
    guardar_estudiantes(Estudiantes, i); // No tengo que poner el & porque Empleados ya es direccion de memoria.
}

void mostrar_empleados(FILE *f_empleados)
{
    Empleado emp;
    if(!f_empleados)
    {
        return;
    }
    fread(&emp, sizeof(Empleado), 1, f_empleados);
    while(!feof(f_empleados))
    {
        printf("Dni: %d, Sueldo: %f\n", emp.dni, emp.sueldo);
        fread(&emp, sizeof(Empleado), 1, f_empleados);
    }
}

void mostrar_estudiantes(FILE *f_estudiantes)
{
    Estudiante est;
    if(!f_estudiantes)
    {
        return;
    }
    fread(&est, sizeof(Estudiante), 1, f_estudiantes);
    while(!feof(f_estudiantes))
    {
        printf("Dni: %d, Promedio: %f\n", est.dni, est.promedio);
        fread(&est, sizeof(Estudiante), 1, f_estudiantes);
    }
}

void Actualizar_Sueldo(FILE *f_empleados, FILE *f_estudiantes)
{
    Empleado emp;
    Estudiante est;
    fread(&emp, sizeof(Empleado), 1, f_empleados);
    fread(&est, sizeof(Estudiante), 1, f_estudiantes);
    while(!feof(f_empleados) && !feof(f_estudiantes))
    {
        if(emp.dni == est.dni)
        {
            if(est.promedio>7)
            {
                printf("DNI Del empleado: %d", emp.dni);
                emp.sueldo*=1.0728;
                fseek(f_empleados, -sizeof(Empleado), SEEK_CUR);
                fwrite(&emp, sizeof(Empleado), 1, f_empleados);
                fseek(f_empleados, 0, SEEK_CUR);
            }
            fread(&emp, sizeof(Empleado), 1, f_empleados);
            fread(&est, sizeof(Estudiante), 1, f_estudiantes);
        }
        if(emp.dni > est.dni)
        {
            fread(&est, sizeof(Estudiante), 1, f_estudiantes);
        }
        if(emp.dni < est.dni)
        {
            fread(&emp, sizeof(Empleado), 1, f_empleados);
        }
    }
}
