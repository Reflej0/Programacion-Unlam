#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tp3.h"
#include "fecha.h"

void ingresar_directorio(char* directoriodat, char* directorioidx)
{
    char directorio[100] = "";
    printf("Ingrese el directorio del archivo de alumnos:");
    gets(directorio);
    strcpy(directoriodat, directorio);
    strcpy(directorioidx, directorio);
    strcat(directoriodat, "alumnos.dat");
    strcat(directorioidx, "alumnos.idx");
}

int comprobar_existencia(FILE* arch)
{
    if(arch)
    {
        return 1;
    }
    return 0;
}

int crear_alumno(t_alumno* alu, T_indice* ind, tFecha* fact)
{
    t_reg_indice reg;
    printf("Ingrese DNI:");
    scanf("%ld", &alu->dni);


    ///COMPROBACION SI EL DNI YA EXISTE.
    reg.dni = alu->dni;
    reg.nro_reg = -1;
    int existe = ind_buscar(ind, &reg);
    if(existe == 0)
    {
        return -1; //EL ALUMNO YA EXISTE.
    }


    ///COMPROBACION SI EL DNI ES VALIDO.
    int dni_valido = validar_dni(alu->dni);
    if(dni_valido == 0)
    {
        return -2; //EL DNI ES INCORRECTO.
    }
    fflush(stdin);
    printf("\nIngrese nombre y apellido:");
    gets(alu->ayn);

    ///NORMALIZACION DE NOMBRE Y APELLIDO.
    normalizar_nombre_apellido(alu->ayn);

    ///COMPROBACION FECHA NACIMIENTO VALIDA.
    printf("\nIngresar fecha de nacimiento:");
    scanf("%d/%d/%d", &alu->fnac.dia, &alu->fnac.mes, &alu->fnac.anio);
    int fnac_valida = validar_fecha_nac(&alu->fnac, fact);
    if(fnac_valida == 0)
    {
        return -3; //LA FECHA DE NACIMIENTO NO ES VALIDA.
    };


    ///COMPROBACION SEXO.
    fflush(stdin);
    printf("\nIngrese el sexo:");
    alu->sexo = getchar();
    int sexo_valido = validar_sexo(alu->sexo);
    if(sexo_valido == 0){
        return -4; //EL SEXO NO ES VALIDO.
    }


    ///COMPROBACION FECHA DE INGRESO.
    printf("\nIngrese fecha de ingreso:");
    scanf("%d/%d/%d", &alu->fing.dia, &alu->fing.mes, &alu->fing.anio);
    int fing_valida = validar_fecha_ing(&alu->fing, fact, &alu->fnac);
    if(fing_valida == 0)
    {
        return -5; //LA FECHA DE INGRESO NO ES VALIDA.
    }


    ///COMPROBACION DE MATERIAS APROBADAS.
    printf("\nIngrese la cantidad de materias aprobadas:");
    scanf("%d", &alu->mataprobadas);
    int mat_valida = validar_cant_materias(alu->mataprobadas);
    if(mat_valida == 0)
    {
        return -6; //LA CANTIDAD DE MATERIAS NO ES VALIDA.
    }

    ///COMPROBACION DE FECHA DE APROBACION DE ULTIMA MATERIA
    printf("\nIngrese la fecha de aprobacion de la ultima materia:");
    scanf("%d/%d/%d", &alu->ultmat.dia, &alu->ultmat.mes, &alu->ultmat.anio);
    int fult_valida = validar_fecha_aprobacion_ult_mat(&alu->ultmat, fact, &alu->fing);
    if(fult_valida == 0)
    {
        return -7; //LA FECHA DE LA APROBACION DE ULTIMA MATERIA NO ES VALIDA.
    }
    alu->estado = 'R'; // Si lo doy de alta, no esta de baja.
    alu->fbaja.dia = 31;
    alu->fbaja.mes = 12;
    alu->fbaja.anio = 9999;
    return 1;
}

void eliminar_alumno(FILE* arch, const long dni, tFecha* fact)
{
    rewind(arch);
    t_alumno alu;
    fread(&alu, sizeof(t_alumno), 1, arch);
    while(!feof(arch))
    {
        if(alu.dni == dni)
        {
            printf("REGISTRO %ld", alu.dni);
            alu.estado = 'B';
            alu.fbaja = *fact;
            fseek(arch, -1*sizeof(t_alumno), SEEK_CUR);
            fwrite(&alu, sizeof(t_alumno), 1, arch);
            printf("REGISTRO %ld", alu.dni);
            fseek(arch, 0, SEEK_CUR);
        }
        fread(&alu, sizeof(t_alumno), 1, arch);
    }
}
