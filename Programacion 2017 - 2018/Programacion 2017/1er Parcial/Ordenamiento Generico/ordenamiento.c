#include <stdio.h>
#include <stdlib.h>
#include "ordenamiento.h"

void ingresar_lote_alumnos(T_alumno *alumnos)
{
    alumnos[0].dni = 4000000;
    alumnos[0].nombre = "Juan";
    alumnos[1].dni = 1000000;
    alumnos[1].nombre = "Pedro";
    alumnos[2].dni = 5000000;
    alumnos[2].nombre = "Carla";
    alumnos[3].dni = 2000000;
    alumnos[3].nombre = "Ernesto";
    alumnos[4].dni = 3000000;
    alumnos[4].nombre = "Maximiliano";
}

int cmp_alu(const void* alu1, const void* alu2)
{
    T_alumno* alumno1 = (T_alumno*) alu1;
    T_alumno* alumno2 = (T_alumno*) alu2;
    return (alumno1->dni) - (alumno2->dni);
}

void intercambiar_punteros(void** p1, void** p2)
{
    void* aux;
    aux = *p1;
    *p1 = *p2;
    *p2 = aux;
}

void ordenar_alumnos(T_alumno *alumnos, size_t cantidad_alumnos, T_cmp cmp_alu)
{
    int i, j;
    for(i = 0; i<cantidad_alumnos; i++)
    {
        for(j=0; j<i;j++)
        {
            if(cmp_alu((void*)&alumnos[i], (void*)&alumnos[j]) < 0)
            {
                intercambiar_punteros((void**)&(alumnos[i]), (void**)&(alumnos[j]));
            }
        }
    }
}

void mostrar_alumnos(T_alumno *alumnos, size_t cantidad_alumnos)
{
    int i = 0;
    while(i < cantidad_alumnos)
    {
        printf("\nDNI: %d, Nombre: %s", alumnos[i].dni, alumnos[i].nombre);
        i++;
    }
}
