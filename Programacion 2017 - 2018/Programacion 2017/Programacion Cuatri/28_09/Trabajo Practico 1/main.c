#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "header.h"

int main()
{
    tFecha f_actual;
    fecha_actual(&f_actual);
    char *directoriotxt = malloc(sizeof(char)*100); // Al pedir tanto lugar(100) prefiero que este en el HEAP.
    char *directoriobin = malloc(sizeof(char)*100); // Al pedir tanto lugar(100) prefiero que este en el HEAP.
    char *directorioerror = malloc(sizeof(char)*100); // Al pedir tanto lugar(100) prefiero que este en el HEAP.
    //C:\Users\Juanjo\Desktop\UNLAM\Programacion\Trabajo Practico 1\/
    introducir_directorio(directoriotxt, directoriobin, directorioerror);
    FILE *txt = fopen(directoriotxt, "r"); //Este archivo contiene todos los registros.
    FILE *bin = fopen(directoriobin, "wb+"); //Este archivo contiene los registros correctos.
    FILE *error = fopen(directorioerror, "w+"); // Este archivo contiene los registros mal ingresados.
    int errores = txt_a_bin_var(txt, bin, error, &f_actual); // Esta variable con tiene los alumnos mal ingresados.
    free(directoriotxt);
    free(directorioerror);
    fclose(txt);
    fclose(bin);
    fclose(error);
    printf("\nAlumnos mal ingresados: %d", errores);
    printf("\nNombres de alumnos bien ingresados:");
    FILE *_bin = fopen(directoriobin, "rb"); //Leo los registros correctos guardados.
    leer_alumnos(_bin);
    fclose(_bin);
    free(directoriobin);

    return 0;
}
