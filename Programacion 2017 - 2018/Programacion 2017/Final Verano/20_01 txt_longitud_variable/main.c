#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    char nombre[20];
    char apellido[20];
    int dni;
} T_persona;

int main()
{
    //ESCRITURA ARCHIVO TEXTO, LONG VARIABLE.
    /*FILE* arch = fopen("txt_variable.txt", "wt");
    T_persona aux;
    int i;
    for(i=0;i<3;i++)
    {
        fflush(stdin);
        printf("Ingrese el nombre:");
        gets(aux.nombre);
        fprintf(arch, "%s|", aux.nombre);
        fflush(stdin);
        printf("\nIngrese el apellido:");
        gets(aux.apellido);
        fprintf(arch, "%s|", aux.apellido);
        printf("\nIngrese el DNI:");
        scanf("%d", &aux.dni);
        fprintf(arch, "%d", aux.dni);
        fprintf(arch, "\n");
    }
    fclose(arch);*/
    //LECTURA ARCHIVO TEXTO, LONG VARIABLE. (IMPRESION LINEA).
    /*FILE* arch = fopen("txt_variable.txt", "rt");
    char linea[100];
    fgets(linea, 100, arch);
    while(!feof(arch))
    {
        printf("%s", linea);
        fgets(linea, 100, arch);
    }
    fclose(arch);*/
    //LECTURA ARCHIVO TEXTO, LONG VARIABLE. (MANIPULAR LINEA).
    FILE* arch = fopen("txt_variable.txt", "rt");
    char linea[100];
    fgets(linea, 100, arch);
    T_persona aux;
    while(!feof(arch))
    {
        sscanf(linea, "%[^|]|%[^|]|%d", aux.apellido, aux.nombre, &aux.dni); // IMPORTANTE ESTA LINEA.
        printf("\nApellido: %s\nNombre: %s\nDNI: %d", aux.apellido, aux.nombre, aux.dni);
        fgets(linea, 100, arch);
    }
    fclose(arch);
}
