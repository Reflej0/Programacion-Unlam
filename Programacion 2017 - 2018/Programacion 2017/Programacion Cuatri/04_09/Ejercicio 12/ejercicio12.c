#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ejercicio12.h"

void inicializar_matriz(char matriz[][50])
{
    for(int i = 0; i < 100; i++)
    {
        for(int j = 0; j < 50; j++)
        {
            matriz[i][j] = 0;
        }

    }
}

void inicializar_matriz_float(char matriz[][7])
{
    for(int i = 0; i < 100; i++)
    {
        for(int j = 0; j < 7; j++)
        {
            matriz[i][j] = 0;
        }

    }
}

int ingresar_alumnos(char matriz[][50])
{
    int i = -1;
    puts("En caso de desear de ingresar alumnos, ingrese exit");
    do
    {
        i++;
        printf("Ingrese el nombre y apellido del alumno:");
        gets(matriz[i]);
    }
    while(strcmp(matriz[i], "exit"));
    return i; // El último ingreso es el de salida.
}
void visualizar_alumnos(char matriz[][50], const int cantidad)
{
    printf("%d", cantidad);
    for(int i = 0; i < cantidad; i++)
    {
            printf("\nAlumno: %s", matriz[i]);
    }
}
void ingresar_notas(float notas[][7], const int cantidad)
{
    system("CLS");
    for(int i=0; i< cantidad; i++)
    {
        for(int j=0; j < 6; j++)
        {
            printf("Ingrese la %d nota del alumno %d, Nota:", j+1, i+1);
            scanf("%f", &notas[i][j]);
        }
        system("CLS");
    }
}

void promediar_notas(float notas[][7], const int cantidad)
{
    for(int i=0; i<cantidad;i++)
    {
        for(int j=0; j<6;j++)
        {
            notas[i][6]+= (notas[i][j])/6;
        }
    }
}

void escribir_archivo(char alumnos[][50], float notas[][7], const int cantidad)
{
    int i = 0;
    int j = 0;
    FILE *f = fopen("ejercicio12.txt", "w");
    fprintf(f, "   Apellido/s, Nombre/s\t\t\tP. 1  P. 2  P. 3  P. 4  P. 5  P. 6  - Prome");
    fprintf(f, "\n   ====================\t\t\t===== ===== ===== ===== ===== =====  ======");
    fprintf(f, "\n");
    while(i<cantidad)
    {
        fprintf(f, " %d  %-30s\t", (i+1), alumnos[i]);
        for(j=0; j<7; j++){
            fprintf(f, "%05.2f  ", notas[i][j]);
        }
        fprintf(f, "\n");
        i++;
    }
    fclose(f);
}
