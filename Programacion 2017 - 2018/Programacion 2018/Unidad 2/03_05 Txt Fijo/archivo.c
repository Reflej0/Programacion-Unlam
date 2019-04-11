#include <stdio.h>
#include "archivo.h"
#include "estructuras.h"

///LECTURA DE ARCHIVOS.

int leer_txt_variable(char* dir)
{
    FILE* arch_txt = fopen(dir, "rt");
    if(!arch_txt)
    {
        return 0;
    }
    T_empleado emp;
    while(fscanf(arch_txt, "%[^|]|%[^|]|%d/%d/%d|%lf\n", emp.apellido, emp.nombre, &emp.fnac.dia, &emp.fnac.mes, &emp.fnac.anio, &emp.sueldo)!=EOF)
    ///while(fscanf(arch_txt, "%[0-9a-zA-Z ]|%[0-9a-zA-Z ]|%d/%d/%d|%lf", emp.apellido, emp.nombre, &emp.fnac.dia, &emp.fnac.mes, &emp.fnac.anio, &emp.sueldo)!=EOF)
    {
        printf("\nApellido:%s\nNombre:%s\nFecha:%d/%d/%d\nSueldo:%lf\n", emp.apellido, emp.nombre, emp.fnac.dia, emp.fnac.mes, emp.fnac.anio, emp.sueldo);
    }
    fclose(arch_txt);
    return 1;
}

int leer_txt_fijo(char* dir)
{
    FILE* arch_txt = fopen(dir, "rt");
    if(!arch_txt)
    {
        return 0;
    }
    T_empleado emp;
    fscanf(arch_txt, "%20c%20c%d/%d/%d%lf", emp.apellido, emp.nombre, &emp.fnac.dia, &emp.fnac.mes, &emp.fnac.anio, &emp.sueldo);
    emp.apellido[20] = '\0';
    emp.nombre[20] = '\0';
    while(!feof(arch_txt))
    {
        printf("\nApellido:%s\nNombre:%s\nFecha:%d/%d/%d\nSueldo:%lf\n", emp.apellido, emp.nombre, emp.fnac.dia, emp.fnac.mes, emp.fnac.anio, emp.sueldo);
        fscanf(arch_txt, "\n%20c%20c%d/%d/%d%lf", emp.apellido, emp.nombre, &emp.fnac.dia, &emp.fnac.mes, &emp.fnac.anio, &emp.sueldo);
        emp.apellido[20] = '\0';
        emp.nombre[20] = '\0';
    }
    fclose(arch_txt);
    return 1;
}

int leer_bin(char* dir)
{
    FILE* arch_bin = fopen(dir, "rb");
    if(!arch_bin)
    {
        return 0;
    }
    T_empleado emp;
    fread(&emp, sizeof(T_empleado), 1, arch_bin);
    while(!feof(arch_bin))
    {
        printf("\nApellido:%s\nNombre:%s\nFecha:%d/%d/%d\nSueldo:%lf\n", emp.apellido, emp.nombre, emp.fnac.dia, emp.fnac.mes, emp.fnac.anio, emp.sueldo);
        fread(&emp, sizeof(T_empleado), 1, arch_bin);
    }
    fclose(arch_bin);
    return 1;
}

///CONVERSIONES DE ARCHIVO.

int txt_variable_a_bin(char* dirtxt, char* dirbin)
{
    FILE* arch_txt = fopen(dirtxt, "rt");
    FILE* arch_bin = fopen(dirbin, "wb");
    if(!arch_txt && !arch_bin)
    {
        return 0;
    }
    T_empleado emp;
    while(fscanf(arch_txt, "%[^|]|%[^|]|%d/%d/%d|%lf\n", emp.apellido, emp.nombre, &emp.fnac.dia, &emp.fnac.mes, &emp.fnac.anio, &emp.sueldo)!=EOF)
    {
        fwrite(&emp, sizeof(T_empleado), 1, arch_bin);
    }
    fclose(arch_txt);
    fclose(arch_bin);
    return 1;
}

int txt_fijo_a_bin(char* dirtxt, char* dirbin)
{
    FILE* arch_txt = fopen(dirtxt, "rt");
    FILE* arch_bin = fopen(dirbin, "wb");
    if(!arch_txt)
    {
        return 0;
    }
    T_empleado emp;
    fscanf(arch_txt, "%19c %19c%d/%d/%d%lf", emp.apellido, emp.nombre, &emp.fnac.dia, &emp.fnac.mes, &emp.fnac.anio, &emp.sueldo);
    emp.apellido[19] = '\0';
    emp.nombre[19] = '\0';
    while(!feof(arch_txt))
    {
        fwrite(&emp, sizeof(T_empleado), 1, arch_bin);
        fscanf(arch_txt, "\n%19c %19c%d/%d/%d%lf", emp.apellido, emp.nombre, &emp.fnac.dia, &emp.fnac.mes, &emp.fnac.anio, &emp.sueldo);
        emp.apellido[19] = '\0';
        emp.nombre[19] = '\0';
    }
    fclose(arch_txt);
    fclose(arch_bin);
    return 1;
}

int bin_a_txt_variable(char* dirbin, char* dirtxt)
{
    FILE* arch_bin = fopen(dirbin, "rb");
    FILE* arch_txt = fopen(dirtxt, "wt");
    if(!arch_txt && !arch_bin)
    {
        return 0;
    }
    T_empleado emp;
    fread(&emp, sizeof(T_empleado), 1, arch_bin);
    while(!feof(arch_bin))
    {
        fprintf(arch_txt, "%s|%s|%d/%d/%d|%.2lf\n", emp.apellido, emp.nombre, emp.fnac.dia, emp.fnac.mes, emp.fnac.anio, emp.sueldo);
        fread(&emp, sizeof(T_empleado), 1, arch_bin);
    }
    fclose(arch_txt);
    fclose(arch_bin);
    return 1;
}

int bin_a_txt_fijo(char* dirbin, char* dirtxt)
{
    FILE* arch_bin = fopen(dirbin, "rb");
    FILE* arch_txt = fopen(dirtxt, "wt");
    if(!arch_txt && !arch_bin)
    {
        return 0;
    }
    T_empleado emp;
    fread(&emp, sizeof(T_empleado), 1, arch_bin);
    while(!feof(arch_bin))
    {
        fprintf(arch_txt, "%-20s%-20s%d/%d/%d%+20.2lf\n", emp.apellido, emp.nombre, emp.fnac.dia, emp.fnac.mes, emp.fnac.anio, emp.sueldo);
        fread(&emp, sizeof(T_empleado), 1, arch_bin);
    }
    fclose(arch_txt);
    fclose(arch_bin);
    return 1;
}


