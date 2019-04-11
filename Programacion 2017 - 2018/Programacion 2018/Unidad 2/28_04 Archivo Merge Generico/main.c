#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

typedef struct
{
    long int dni;
    char nya[40];
    int mat_aprobadas;
} T_alumno;

int actualizar_alumnos(char* diralumnos, char* dirnovedades, char* dirmerge, char* direrrores)
{
    FILE* arch_alumnos = fopen(diralumnos, "rt");
    FILE* arch_novedades = fopen(dirnovedades, "rt");
    FILE* arch_merge = fopen(dirmerge, "wt");
    FILE* arch_errores = fopen(direrrores, "wt");
    if(!arch_alumnos || !arch_novedades || !arch_merge || !arch_errores)
    {
        printf("Error: %s\n", strerror(errno));
        return 0;
    }
    T_alumno alu;
    T_alumno alu_n;
    int registros_errores = 0;
    char estado;
    fscanf(arch_alumnos, "%ld|%[^|]|%d\n", &alu.dni, alu.nya, &alu.mat_aprobadas);
    fscanf(arch_novedades, "%ld|%[^|]|%d|%c\n", &alu_n.dni, alu_n.nya, &alu_n.mat_aprobadas, &estado);
    while(!feof(arch_alumnos) && !feof(arch_novedades))
    {
        int comp = alu.dni-alu_n.dni;
        if(comp == 0)
        {
            if(estado == 'A') // Si estoy intentando de dar un alta a un alumno ya existente.
            {
                //Como medida de seguridad guardo en el merge el que estaba previamente.
                fprintf(arch_merge, "%ld|%s|%d\n", alu.dni, alu.nya, alu.mat_aprobadas);
                fprintf(arch_errores, "%ld\n", alu.dni); // Guardo el dni del alumno con error.
                registros_errores++;
            }
            else if(estado == 'M') // Guardo en el archivo de merge el registro de novedades.
            {
                fprintf(arch_merge, "%ld|%s|%d\n", alu_n.dni, alu_n.nya, alu_n.mat_aprobadas);
            }
            fscanf(arch_alumnos, "%ld|%[^|]|%d\n", &alu.dni, alu.nya, &alu.mat_aprobadas);
            fscanf(arch_novedades, "%ld|%[^|]|%d|%c\n", &alu_n.dni, alu_n.nya, &alu_n.mat_aprobadas, &estado);
            //Si el estado del archivo de novedades es B(borrar) no grabo el registro en el archivo merge.
        }
        else if(comp > 0)
        {
            if(estado == 'A')
            {
                fprintf(arch_merge, "%ld|%s|%d\n", alu_n.dni, alu_n.nya, alu_n.mat_aprobadas);
            }
            else // Estoy intentando modificar o dar de baja un alumno no existente.
            {
                fprintf(arch_errores, "%ld\n", alu_n.dni); // Guardo el dni del alumno con error.
                registros_errores++;
            }
            fscanf(arch_novedades, "%ld|%[^|]|%d|%c\n", &alu_n.dni, alu_n.nya, &alu_n.mat_aprobadas, &estado);
        }
        else
        {
            fprintf(arch_merge, "%ld|%s|%d\n", alu.dni, alu.nya, alu.mat_aprobadas);
            fscanf(arch_alumnos, "%ld|%[^|]|%d\n", &alu.dni, alu.nya, &alu.mat_aprobadas);
        }
    }

    ///Por el FEOF pierdo el ultimo registro de cada archivo, en total pierdo 2 posibles registros validos.
    fscanf(arch_alumnos, "%ld|%[^|]|%d\n", &alu.dni, alu.nya, &alu.mat_aprobadas);
    fscanf(arch_novedades, "%ld|%[^|]|%d|%c\n", &alu_n.dni, alu_n.nya, &alu_n.mat_aprobadas, &estado);
    int comp = alu.dni-alu_n.dni;
    if(comp == 0)
    {
        if(estado == 'A') // Si estoy intentando de dar un alta a un alumno ya existente.
        {
            //Como medida de seguridad guardo en el merge el que estaba previamente.
            fprintf(arch_merge, "%ld|%s|%d\n", alu.dni, alu.nya, alu.mat_aprobadas);
            fprintf(arch_errores, "%ld\n", alu.dni); // Guardo el dni del alumno con error.
            registros_errores++;
        }
        else if(estado == 'M') // Guardo en el archivo de merge el registro de novedades.
        {
            fprintf(arch_merge, "%ld|%s|%d\n", alu_n.dni, alu_n.nya, alu_n.mat_aprobadas);
        }
        fscanf(arch_alumnos, "%ld|%[^|]|%d\n", &alu.dni, alu.nya, &alu.mat_aprobadas);
        fscanf(arch_novedades, "%ld|%[^|]|%d|%c\n", &alu_n.dni, alu_n.nya, &alu_n.mat_aprobadas, &estado);
        //Si el estado del archivo de novedades es B(borrar) no grabo el registro en el archivo merge.
    }
    else if(comp > 0)
    {
        if(estado == 'A')
        {
            fprintf(arch_merge, "%ld|%s|%d\n", alu_n.dni, alu_n.nya, alu_n.mat_aprobadas);
            fprintf(arch_merge, "%ld|%s|%d\n", alu.dni, alu.nya, alu.mat_aprobadas);
        }
        else // Estoy intentando modificar o dar de baja un alumno no existente.
        {
            fprintf(arch_errores, "%ld\n", alu_n.dni); // Guardo el dni del alumno con error.
            registros_errores++;
        }
    }
    else
    {
        fprintf(arch_merge, "%ld|%s|%d\n", alu.dni, alu.nya, alu.mat_aprobadas);
        if(estado == 'A')
        {
            fprintf(arch_merge, "%ld|%s|%d\n", alu_n.dni, alu_n.nya, alu_n.mat_aprobadas);
        }
        else // Estoy intentando modificar o dar de baja un alumno no existente.
        {
            fprintf(arch_errores, "%ld\n", alu_n.dni); // Guardo el dni del alumno con error.
            registros_errores++;
        }
    }
    fclose(arch_alumnos);
    fclose(arch_novedades);
    fclose(arch_merge);
    fclose(arch_errores);
    return registros_errores;
}

int main()
{
    char diralumnos[200] = "C:\\Users\\Juanjo\\Desktop\\UNLAM\\Programacion\\Programacion 2018\\Unidad 2\\28_04 Archivo Merge Generico\\alumnos.txt";
    char dirnovedades[200] = "C:\\Users\\Juanjo\\Desktop\\UNLAM\\Programacion\\Programacion 2018\\Unidad 2\\28_04 Archivo Merge Generico\\novedades.txt";
    char dirmerge[200] = "C:\\Users\\Juanjo\\Desktop\\UNLAM\\Programacion\\Programacion 2018\\Unidad 2\\28_04 Archivo Merge Generico\\merge.txt";
    char direrrores[200] = "C:\\Users\\Juanjo\\Desktop\\UNLAM\\Programacion\\Programacion 2018\\Unidad 2\\28_04 Archivo Merge Generico\\errores.txt";
    /*printf("Ingrese el directorio del arch. de alumnos:");
    gets(diralumnos);
    printf("Ingrese el directorio del arch. de novedades:");
    gets(dirnovedades);
    printf("Ingrese el directorio del arch. de merge:");
    gets(dirmerge);
    printf("Ingrese el directorio del arch. de errores:");
    gets(direrrores);*/
    int registro_errores = actualizar_alumnos(diralumnos, dirnovedades, dirmerge, direrrores);
    printf("El numero de registros con errores es: %d", registro_errores);
    return 1;
}
