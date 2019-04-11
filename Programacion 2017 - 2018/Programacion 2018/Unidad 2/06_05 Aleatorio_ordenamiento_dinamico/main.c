#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include "funciones.h"
int main()
{
    generar_semilla(); // Funcion que genera la semilla para la utilizacion del rand.
    int opcion;
    size_t tamano; // Tamano del vector.
    printf("1)Vector de enteros\n2)Vector de reales\n3)Vector de caracteres");
    printf("\nOpcion:");
    scanf("%d", &opcion);
    printf("Ingrese el tamano:");
    scanf("%u", &tamano);
    if(opcion == 1)
    {
        int v[tamano];
        llenar_vector(v, tamano, ENTERO); // Se llena el vector con enteros aleatorios.
        printf("VECTOR ALEATORIO DESORDENADO:\n");
        mostrar_vector(v, tamano, ENTERO);
        qsort(v, tamano, sizeof(int), comp_int); // Se ordena el vector bajo el criterio comp_int.
        printf("VECTOR ALEATORIO ORDENADO:\n");
        mostrar_vector(v, tamano, ENTERO);
    }
    else if(opcion == 2)
    {
        float v[tamano];
        llenar_vector(v, tamano, REAL); // Se llena el vector con flotantes aleatorios.
        printf("VECTOR ALEATORIO DESORDENADO:\n");
        mostrar_vector(v, tamano, REAL);
        qsort(v, tamano, sizeof(float), comp_float); // Se ordena el vector bajo el criterio comp_float.
        printf("VECTOR ALEATORIO ORDENADO:\n");
        mostrar_vector(v, tamano, REAL);
    }
    else if(opcion == 3)
    {
        char v[tamano];
        llenar_vector(v, tamano, CARACTER); // Se llena el vector con caracteres aleatorios.
        printf("VECTOR ALEATORIO DESORDENADO:\n");
        mostrar_vector(v, tamano, CARACTER);
        qsort(v, tamano, sizeof(char), comp_char); // Se ordena el vector bajo el criterio comp_char.
        printf("VECTOR ALEATORIO ORDENADO:\n");
        mostrar_vector(v, tamano, CARACTER);
    }
    return 0;
}
