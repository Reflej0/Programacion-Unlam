#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> //Para usar tipos de datos bool.
#include "vector_dinamico.h"

struct vector
{
    size_t tam;
    void** datos;
};

vector_t* vector_crear(size_t tam_inicial)
{
    int i; // Contador para el ciclo.
    //Pido memoria para la estructura.
    vector_t* vector = malloc(sizeof(vector_t));
    if(vector==NULL)
    {
        return NULL;
    }
    vector->tam = tam_inicial; //Guardo el tamaño.
    //Pido memoria por el tipo de dato void* multiplicado el tamaño inicial.
    vector->datos = malloc(sizeof(void*)*tam_inicial);
    if(vector->datos==NULL)
    {
        free(vector); //No es necesario.
        return NULL;
    }
    //Limpieza del vector
    for(i=0;i<tam_inicial;i++){
        vector->datos[i] = NULL;
    }
    return vector;
}

bool vector_agregar(vector_t* vector, size_t indice, void* elemento)
{
    //Constatar que el indice esta dentro del rango.
    if(indice<0 || indice>= (vector->tam))
    {
        return false;
    }
    vector->datos[indice] = elemento;
    return true;
}

size_t vector_obtener_tam(vector_t* vector)
{
    //Devuelve el tamaño actual del vector.
    return vector->tam;
}

void* vector_obtener(vector_t* vector, size_t indice)
{
    //Constatar que el indice esta dentro del rango.
    if(indice<0 || indice>= vector->tam)
    {
        return NULL;
    }
    return vector->datos[indice];
}

bool vector_redimensionar(vector_t* vector, size_t nuevotam)
{
    //Esto es debido a que no se permite que el vector se achique.
    if(nuevotam<(vector->tam))
    {
        return false;
    }
    //Se crea un vector temporal.
    void** datos_nuevos = realloc(vector->datos, nuevotam*sizeof(void*));
    if(datos_nuevos==NULL)
    {
        return false;
    }
    //Se libera el anterior.
    free(vector->datos);
    vector->datos = datos_nuevos;
    vector->tam = nuevotam;
    return true;
}

void vector_destruir(vector_t* vector)
{
    free(vector->datos);
    free(vector);
}


