#include <stdio.h>
#include <stdlib.h>
#include "fecha.h"
#include "header.h"
#include "tp.h"
#include "indice.h"

int main()
{
    ///INGRESO DE DIRECTORIO
    ///EJ: C:\Users\Juanjo\Desktop\UNLAM\Programacion\Programacion 2018\Trabajo Practico 1\alumnos\ */
    char directoriodat[200] = "";
    char directorioidx[200] = "";
    ingresar_directorio(directoriodat, directorioidx);

    ///COMPROBACION DE EXISTENCIA DE ARCHIVO .DAT
    FILE* arch = fopen(directoriodat, "rb");
    int existencia = comprobar_existencia(arch);
    if(!existencia)
    {
        printf("El archivo(dat) no existe");
        fclose(arch);
        exit(-1);
    }
    fclose(arch);

    ///COMPROBACION DE EXISTENCIA DE ARCHIVO .IDX
    FILE* idx = fopen(directorioidx, "rb");
    existencia = comprobar_existencia(idx);
    if(!existencia)
    {
        printf("El indice(idx) no existe");
        fclose(arch);
        return -1;
    }
    fclose(idx);

    ///CARGA DE INDICE DESDE ARCHIVO.
    T_indice indice;
    ind_crear(&indice);
    ind_cargar(&indice, directorioidx);

    ///OBTENCION DE FECHA ACTUAL.
    tFecha f_actual;
    fecha_actual(&f_actual);

    unsigned short opcion = 0;
    do
    {
        printf("1)Dar de alta\n2)Dar de Baja\n3)Listar dado de baja\n4)Listar todos\n5)Salir\nOpcion:");
        scanf("%hu", &opcion);
        system("CLS");
        switch(opcion)
        {
            case 1:;
            t_alumno alu;
            int validacion = crear_alumno(&alu, &indice, &f_actual);
            if(validacion == -1)
            {
                printf("EL ALUMNO YA EXISTE\n");
                printf("\n");
                system("PAUSE");
                system("CLS");
            }
            ///SI EL ALUMNO ES VALIDO.
            if(validacion == 1)
            {
                ///APPEND DEL ALUMNO.
                FILE* arch = fopen(directoriodat, "ab");
                if(!arch) return -1;
                fwrite(&alu,sizeof(t_alumno), 1, arch);
                fclose(arch);
                t_reg_indice reg;
                reg.dni = alu.dni;
                reg.nro_reg = ind_nro(&indice);
                ///ACTUALIZACION DEL INDICE EN MEMORIA.
                ind_insertar(&indice, &reg);
            }
            break;
            case 2:;

            ///BUSQUEDA DEL DNI EN EL INDICE.
            t_reg_indice reg;
            printf("Ingrese el DNI a eliminar:");
            scanf("%ld", &reg.dni);
            int existe = ind_buscar(&indice, &reg);

            ///SI NO EXISTE.
            if(!existe)
            {
                printf("EL DNI INGRESADO NO EXISTE");
                printf("\n");
                system("PAUSE");
                system("CLS");
            }
            ///SI EXISTE.
            else
            {
                ///LO ELIMINO DEL INDICE.
                ind_eliminar(&indice, &reg);
                //ind_leer_archivo(directorioidx);
                ///LO ELIMINO(BAJA LOGICA) DEL ARCHIVO.
                FILE* arch = fopen(directoriodat, "rb+");
                eliminar_alumno(arch, reg.dni, &f_actual);
                fclose(arch);
            }
            break;

            case 3:;
            FILE* archi = fopen(directoriodat, "rb");
            if(!archi) return -1;
            leer_alumnos_baja(archi);
            fclose(archi);
            printf("\n");
            system("PAUSE");
            system("CLS");
            break;

            case 4:;
            FILE* arch = fopen(directoriodat, "rb");
            if(!arch) return -1;
            leer_alumnos(arch);
            fclose(arch);
            printf("\n");
            system("PAUSE");
            system("CLS");
            break;
        }
    }
    while(opcion != 5);
    ///GUARDADO DEL INDICE.
    ind_grabar(&indice, directorioidx);
    return 1;
}
