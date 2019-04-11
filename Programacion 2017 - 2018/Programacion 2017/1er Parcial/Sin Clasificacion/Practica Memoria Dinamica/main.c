#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int dni;
    char apellido[20];
} alumno;

int main()
{
    /* Reservo memoria dinámica para un int, y despues libero.
    int *numero = malloc(sizeof(int));
    *numero = 5;
    printf("Numero guardado:%d", *numero);
    free(numero);
    printf("\nNumero guardado:%d", *numero);
    */
    //------------------------------------------------------------
    /* Reservo memoria dinámica para un vector.
    int i = 0;
    int cantidad_numeros = 5;
    int *numeros = malloc(sizeof(int)*cantidad_numeros);
    while(i<cantidad_numeros)
    {
        printf("Ingrese un numero:");
        scanf("%d", &numeros[i]);
        i++;
    }
    printf("\nEl primero numero del vector es:%d", numeros[0]);
    */
    //------------------------------------------------------------
    /* Reservo memoria dinámica para un vector de estructura.
    int i = 0;
    int cantidad_alumnos = 3;
    alumno *alumnos = malloc(sizeof(alumno)*cantidad_alumnos);
    while(i<cantidad_alumnos)
    {
        printf("Ingrese DNI:");
        scanf("%d", &alumnos[i].dni);
        fflush(stdin);
        printf("Ingrese Apellido:");
        gets(alumnos[i].apellido);
        i++;
    }
    printf("\nEl dni del ultimo alumno es: %d", alumnos[2].dni);
    printf("\nEl apellido del primer alumno es: %s", alumnos[0].apellido);
    */
}
