#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "header.h"
#include "indice.h"
#include "def.h"
#include "lista.h"


int main()
{
    ///CREACION DEL INDICE.
    T_indice indice;
    ind_crear(&indice);
    ///----------------

    ///FECHA ACTUAL.
    tFecha f_actual;
    fecha_actual(&f_actual);
    ///--------------------

    ///DIRECTORIOS.
    char *directoriotxt = malloc(sizeof(char)*100); // Al pedir tanto lugar(100) prefiero que este en el HEAP.
    char *directoriobin = malloc(sizeof(char)*100); // Al pedir tanto lugar(100) prefiero que este en el HEAP.
    char *directorioerror = malloc(sizeof(char)*100); // Al pedir tanto lugar(100) prefiero que este en el HEAP.
    char *directorioindice = malloc(sizeof(char)*100); // Al pedir tanto lugar(100) prefiero que este en el HEAP.
    //C:\Users\Juanjo\Desktop\UNLAM\Programacion\Trabajo Practico 2_1\/
    introducir_directorio(directoriotxt, directoriobin, directorioerror, directorioindice);
    ///--------------------------------------------------------------------------------------------------

    ///APERTURA DE ARCHIVOS.
    FILE *txt = fopen(directoriotxt, "r"); //Este archivo contiene todos los registros.
    FILE *bin = fopen(directoriobin, "wb+"); //Este archivo contiene los registros correctos.
    FILE *error = fopen(directorioerror, "w+"); // Este archivo contiene los registros mal ingresados.
    ///--------------------------------------------------------------------------------------------------

    ///FUNCION PRINCIPAL TRABAJO PRACTICO 1 + INDICE (TRABAJO PRACTICO 2).
    int errores = txt_a_bin_var(txt, bin, error, &f_actual, &indice); // Esta variable con tiene los alumnos mal ingresados.
    ///-------------------------------------------------------------------------------------------------------------------



    ///GRABACION DEL INDICE (TRABAJO PRACTICO 2)
    ind_grabar(&indice, directorioindice);
    ///-----------------------------------------

    ///CIERRE DE ARCHIVOS Y LIBERACION DE MEMORIA DINAMICA.
    free(directoriotxt);
    free(directorioerror);
    fclose(txt);
    fclose(bin);
    fclose(error);
    ///--------------------------------------------------

    ///COMPROBACION DE ARCHIVOS(TP1).
    printf("\nAlumnos mal ingresados: %d", errores);
    printf("\nNombres de alumnos bien ingresados:");
    FILE *_bin = fopen(directoriobin, "rb"); //Leo los registros correctos guardados.
    leer_alumnos(_bin);
    fclose(_bin);
    free(directoriobin);

    ///COMPROBACION DE INDICE(TP2).
    printf("\nLECTURA DEL INDICE:");
    T_indice indice_arch; //Este indice contendrá los registros cargados desde el archivo.
    T_dato aux; // Este archivo auxiliar sirve para leer los registros que devuelve el indice (iterador).
    ind_crear(&indice_arch); // Se crea el indice.
    ind_cargar(&indice_arch, directorioindice); // Se carga desde el archivo los registros al indice.
    ind_primero(&indice_arch, &aux); // Se obtiene el primer registro del indice.
    while(!ind_fin(&indice_arch)) // Hasta que no llegue al ultimo registro.
    {
        printf("\nREGISTRO: %d - DNI: %ld", aux.nro_reg, aux.dni); //Imprimo el registro.
        ind_siguiente(&indice_arch, &aux); // Avanzo al siguiente.
    }
    free(directorioindice);
    ///----------------------------------------------------------------------------
    return 0;
    ///---------------------------------------------------------------------------------
}
