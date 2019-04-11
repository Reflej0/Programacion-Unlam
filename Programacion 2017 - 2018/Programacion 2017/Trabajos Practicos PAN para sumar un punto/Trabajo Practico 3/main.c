#include <stdio.h>
#include <stdlib.h>
#include "fecha.h"
#include "header.h"
#include "tp3.h"
#include "indice.h"

int main()
{
    ///INGRESO DE DIRECTORIO
    char directoriodat[100] = "";
    char directorioidx[100] = "";
    ingresar_directorio(directoriodat, directorioidx);

    ///COMPROBACION DE EXISTENCIA DE ARCHIVO .DAT
    FILE* arch = fopen(directoriodat, "rb");
    int existencia = comprobar_existencia(arch);
    if(existencia == 0)
    {
        printf("El archivo(dat) no existe");
        return -1;
        fclose(arch);
    }
    fclose(arch); // LO CIERRO YA QUE POSTERIORMENTE QUIZA SOLAMENTE LO LEO, REALIZO UN APPEND AL FINAL O ELIMINO ALGO.

    ///COMPROBACION DE EXISTENCIA DE ARCHIVO .IDX
    FILE* idx = fopen(directorioidx, "rb");
    existencia = comprobar_existencia(idx);
    if(existencia == 0)
    {
        printf("El indice(idx) no existe");
        return -1;
        fclose(arch);
    }
    fclose(idx); // LO CIERRO YA QUE POSTERIORMENTE QUIZA SOLAMENTE LO LEO, REALIZO UN APPEND AL FINAL O ELIMINO ALGO.

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
                system("PAUSE");
            }
            ///SI EL ALUMNO ES VALIDO.
            if(validacion == 1)
            {
                ///APPEND DEL ALUMNO.
                FILE* arch = fopen(directoriodat, "ab");
                fwrite(&alu,sizeof(t_alumno), 1, arch);
                fclose(arch);

                ///APPEND DEL INDICE.
                FILE* idx = fopen(directorioidx, "wb");
                fseek(idx, 0, SEEK_END);
                int nro_indice = ftell(idx) / sizeof(t_reg_indice);
                rewind(idx);
                t_reg_indice reg;
                reg.dni = alu.dni;
                reg.nro_reg = nro_indice;
                fwrite(&reg, sizeof(t_reg_indice), 1, idx);
                fclose(idx);

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
            if(existe == 1) //Esta al reves.
            {
                printf("EL DNI INGRESADO NO EXISTE");
                system("PAUSE");
                system("CLS");
            }
            ///SI EXISTE.
            else
            {
                ///LO ELIMINO DEL INDICE.
                ind_eliminar(&indice, &reg);
                ind_grabar(&indice, directorioidx);
                //ind_leer_archivo(directorioidx);
                ///LO ELIMINO(BAJA LOGICA) DEL ARCHIVO.
                FILE* arch = fopen(directoriodat, "rb+");
                eliminar_alumno(arch, reg.dni, &f_actual);
                fclose(arch);
            }
            break;


            case 3:;
            FILE* archi = fopen(directoriodat, "rb");
            leer_alumnos_baja(archi);
            fclose(archi);
            system("PAUSE");
            system("CLS");
            break;


            case 4:;
            FILE* arch = fopen(directoriodat, "rb");
            leer_alumnos(arch);
            fclose(arch);
            system("PAUSE");
            system("CLS");
            break;
        }
    }
    while(opcion != 5);
}
