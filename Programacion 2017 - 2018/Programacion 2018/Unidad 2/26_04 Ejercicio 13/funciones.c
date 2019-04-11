#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#include "funciones.h"
#define TAM_ESTUDIANTES 5
#define TAM_EMPLEADOS 5

int generacion_estudiantes(char* directorioestudiantes)
{
    ///Lote de prueba en array.
    //Lote ordenado por apellido.
    T_estudiante lote[TAM_ESTUDIANTES];
    lote[0].dni = 31289450;
    strcpy(lote[0].apellido, "Lopez");
    strcpy(lote[0].nombre, "Maximiliano");
    lote[0].promedio = 6.3;
    lote[1].dni = 31660181;
    strcpy(lote[1].apellido, "Perez");
    strcpy(lote[1].nombre, "Carolina");
    lote[1].promedio = 5.4;
    lote[2].dni = 13677935;
    strcpy(lote[2].apellido, "Rodriguez");
    strcpy(lote[2].nombre, "Eduardo");
    lote[2].promedio = 7.4;
    lote[3].dni = 17012950;
    strcpy(lote[3].apellido, "Sanchez");
    strcpy(lote[3].nombre, "Rodrigo");
    lote[3].promedio = 8.9;
    lote[4].dni = 39039711;
    strcpy(lote[4].apellido, "Suarez");
    strcpy(lote[4].nombre, "Micaela");
    lote[4].promedio = 7.1;
    FILE* arch_estudiantes = fopen(directorioestudiantes, "wb");
    if(!arch_estudiantes)
    {
        return 0; /// Problema con el archivo.
    }
    fwrite(lote, sizeof(T_estudiante), TAM_ESTUDIANTES, arch_estudiantes);
    fclose(arch_estudiantes);
    return 1; /// Generacion correcta.
}

int generacion_empleados(char* directorioempleados)
{
    ///Lote de prueba en array.
    //Lote ordenado por apellido.
    T_empleado lote[TAM_EMPLEADOS];
    lote[0].dni = 33012463;
    strcpy(lote[0].apellido, "Bilbao");
    strcpy(lote[0].nombre, "Emilio");
    lote[0].sueldo = 7200.42;
    lote[1].dni = 34568417;
    strcpy(lote[1].apellido, "Pinzon");
    strcpy(lote[1].nombre, "Rodrigo");
    lote[1].sueldo = 9010.34;
    lote[2].dni = 13677935;
    strcpy(lote[2].apellido, "Rodriguez");
    strcpy(lote[2].nombre, "Eduardo");
    lote[2].sueldo = 12000.123;
    lote[3].dni = 32170843;
    strcpy(lote[3].apellido, "Ruffo");
    strcpy(lote[3].nombre, "Sofia");
    lote[3].sueldo = 7412.35;
    lote[4].dni = 39039711;
    strcpy(lote[4].apellido, "Suarez");
    strcpy(lote[4].nombre, "Micaela");
    lote[4].sueldo = 8453.25;
    FILE* arch_empleados = fopen(directorioempleados, "wb");
    if(!arch_empleados)
    {
        return 0; /// Problema con el archivo.
    }
    fwrite(lote, sizeof(T_empleado), TAM_EMPLEADOS, arch_empleados);
    fclose(arch_empleados);
    return 1; /// Generacion correcta.
}

int mostrar_estudiantes(char* directorioestudiantes)
{
    FILE* arch_estudiantes = fopen(directorioestudiantes, "rb");
    if(!arch_estudiantes)
    {
        return 0; ///Problema con archivo.
    }
    T_estudiante est;
    while(fread(&est, sizeof(T_estudiante), 1, arch_estudiantes))
    {
        printf("\nApellido: %s\nNombre: %s\nDNI: %ld\nPromedio: %.2f", est.apellido, est.nombre, est.dni, est.promedio);
    }
    fclose(arch_estudiantes);
    return 1; /// Visualizacion correcta.
}

int mostrar_empleados(char* directorioempleados)
{
    FILE* arch_empleados = fopen(directorioempleados, "rb");
    if(!arch_empleados)
    {
        return 0; ///Problema con archivo.
    }
    T_empleado emp;
    while(fread(&emp, sizeof(T_empleado), 1, arch_empleados))
    {
        printf("\nApellido: %s\nNombre: %s\nDNI: %ld\nSueldo: %.2lf", emp.apellido, emp.nombre, emp.dni, emp.sueldo);
    }
    fclose(arch_empleados);
    return 1; /// Visualizacion correcta.
}

//Retorna la cantidad de empleados a los que se les actualizo el sueldo.
int actualizacion_sueldo(char* directorioestudiantes, char* directorioempleados)
{
    FILE* arch_est = fopen(directorioestudiantes, "rb");
    FILE* arch_emp = fopen(directorioempleados, "rb+");
    T_estudiante est;
    T_empleado emp;
    fread(&est, sizeof(T_estudiante), 1, arch_est);
    fread(&emp, sizeof(T_empleado), 1, arch_emp);
    int actualizados = 0;
    while(!feof(arch_est) && !feof(arch_emp))
    {
        int comp = es_mismo_estudiante_empleado(&est, &emp);
        if(comp == 0)
        {
            if(est.promedio > 7)
            {
                emp.sueldo*=1.0728;
                fseek(arch_emp, -1L*sizeof(T_empleado), SEEK_CUR);
                fwrite(&emp, sizeof(T_empleado), 1, arch_emp);
                fseek(arch_emp, 0, SEEK_CUR);
                actualizados++;
            }
            fread(&est, sizeof(T_estudiante), 1, arch_est);
            fread(&emp, sizeof(T_empleado), 1, arch_emp);
        }
        if(comp < 0)
        {
            fread(&est, sizeof(T_estudiante), 1, arch_est);
        }
        if(comp > 0)
        {
            fread(&emp, sizeof(T_empleado), 1, arch_emp);
        }
    }
    fclose(arch_est);
    fclose(arch_emp);
    return actualizados;
}

/*Retorno:
<0 Si son distintos, y el peso lexicografico y numerico del estudiante es menor.
0 Si es el mismo estudiante y empleado.
>0 Si son distintos, y el peso lexicografico y numerico del estudiante es mayor.
*/
int es_mismo_estudiante_empleado(T_estudiante *est, T_empleado *emp)
{
    int mayor;
    if((mayor = strcmp(est->apellido, emp->apellido)) == 0)
    {
        if((mayor = strcmp(est->nombre, emp->nombre)) == 0)
        {
            if((mayor = (est->dni - emp->dni)) == 0)
            {
                return mayor;
            }
            else
            {
                return mayor;
            }
        }
        else
        {
            return mayor;
        }
    }
    else
    {
        return mayor;
    }
}
