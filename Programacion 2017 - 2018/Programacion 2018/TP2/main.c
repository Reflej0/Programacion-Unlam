#include <stdio.h>
#include <stdlib.h>
#include "header.h"

int main()
{
    /*Lotes de pruebas*/
    t_alumno mal_todos_campos = {-123, "Tocino, Juan", {27, 10, -1994}, 'X', {45, 12, 2099}, "XAS", -3, {1,1,1900}, 'T', {12, 12, -1999}};
    int opcion;
    printf("1)Ingresar alumno\n2)Validar estructura alumno\n3)Leer archivo de alumnos\nOpcion:");
    scanf("%d", &opcion);
    tFecha factual = fecha_actual();
    switch(opcion)
    {
    case 1:;
        t_alumno alu;
        ingresar_alumno(&alu);
        system("CLS");
        printf("DNI: %ld\nApellido y nombre:%s\nFecha de Nacimiento:%d/%d/%d", alu.dni, alu.ayn, alu.fnac.dia, alu.fnac.mes, alu.fnac.anio);
        printf("\nSexo: %c\nFecha de ingreso: %d/%d/%d\nCarrera:%s", alu.sexo, alu.fing.dia, alu.fing.mes, alu.fing.anio, alu.carrera);
        printf("\nCantidad de materias aprobadas: %d\nFecha de la ult mat aprob:%d/%d/%d", alu.mataprobadas, alu.ultmat.dia, alu.ultmat.mes, alu.ultmat.anio);
        printf("\nEstado:%c\nFecha de Baja:%d/%d/%d", alu.estado, alu.fbaja.dia, alu.fbaja.mes, alu.fbaja.anio);
        break;
    case 2:;
        int vector_errores[8] = {0};
        validar_alumno(&mal_todos_campos, &factual, vector_errores);
        if(vector_errores[0])
        {
            printf("\nEl dni esta mal ingresado");
        }
        if(!vector_errores[1])
        {
            printf("\nLa fecha de nacimiento esta mal ingresada");
        }
        if(!vector_errores[2])
        {
            printf("\nEl sexo esta mal ingresado");
        }
        if(!vector_errores[3])
        {
            printf("\nLa carrera esta mal ingresada");
        }
        if(!vector_errores[4])
        {
            printf("\nLa cantidad de materias aprobadas esta mal ingresada");
        }
        if(!vector_errores[5])
        {
            printf("\nLa fecha de la ultima materia aprobada esta mal ingresada");
        }
        if(!vector_errores[6])
        {
            printf("\nEl estado esta mal ingresado");
        }
        if(!vector_errores[7])
        {
            printf("\nLa fecha de baja esta mal ingresada");
        }
        break;
    case 3:;
        char dir[200];
        fflush(stdin);
        printf("\nIntroduzca la ruta del archivo:");
        gets(dir);
        procesar_archivo_alumnos_txt(dir, &factual);
        break;
    default:
        break;
    }
    return 1;
}
