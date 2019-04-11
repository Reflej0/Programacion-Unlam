#include <stdio.h>
#include <stdlib.h>
#include "vectores.h"

void Mostrar_Vector(int* vec, int tam)
{
    int i;
    for(i=0; i<tam; i++)
    {
        printf("Elemento: %d\n", *vec);
        vec++;
    }
}

int Insertar_Elemento_Vector(int* vec, int tam, int elemento, int posicion)
{
    //Si la posicion donde se desea insertar es mayor al tamaño del vector.
    //Si la posicion donde se desea insertar es negativa.
    if(posicion>=tam || posicion<0)
    {
        return -1;
    }
    else
    {
        int i;
        for(i=0; i<posicion; i++)
        {
            vec++; // Avanzo el puntero que apunta a la posicion a insertar.
        }
        *vec = elemento; // Inserción.
    }
    return 1;
}
///Solucion1.
///Compruebo si el vector tiene espacio disponible, 0 se considera espacio disponible.
///Si es asi se inserta en el primer espacio disponible.
///Se ordena el vector con un algoritmo de ordenamiento.
int Insertar_Elemento_Ordenado_Vector(int* vec, int tam, int elemento)
{
    int i, primer_lugar_disponible, j, aux;
    //Avanzo mientras que no llegue al final del vector o encuentre un lugar disponible.
    //El valor 0 es tomado como lugar disponible dentro del vector.
    for(i=0; (i<tam && *vec !=0); i++)
    {
        vec++;
    }
    ///Llegue al final del vector, es decir esta lleno.
    if(*vec != 0)
    {
        return -1; //Vector sin espacio.
    }
    ///Si el vector no esta lleno.
    /**La variable primer_lugar_disponible es utilizada para que los lugares disponibles (0)
    sigan quedando al final del vector, de no usarse los 0 tambien se ordenarian*/
    primer_lugar_disponible = i; // Guardo la posicion del primer lugar disponible dentro del vector.
    *vec = elemento; // Inserto el elemento en el primer espacio disponible.
    //Una vez insertado el elemento vuelvo a ordenar el vector.
    vec-=i; // Tengo que retroceder las posiciones avanzadas para manejar el ordenamiento.
    ///Método de ordenamiento burbuja.
    for(i=0; i<primer_lugar_disponible; i++)
    {
        for(j=0; j<primer_lugar_disponible-i; j++)
        {
            if(vec[j]>=vec[j+1])
            {
                aux = vec[j];
                vec[j] = vec[j+1];
                vec[j+1] = aux;
            }
        }
    }
    return 1;
}

///Solucion2.
///Primero encuentro la posicion donde tengo que insertar el nuevo elemento.
///Despues voy corriendo a partir de dicha posicion los elementos del vector.
int Insertar_Elemento_Ordenado_Vector_2(int* vec, int tam, int elemento)
{
    int i, pos = -1;
    ///Encuentro la posicion donde tengo que insertar el nuevo elemento.
    for(i=0; (i<tam && *vec < elemento && *vec !=0); i++)
    {
        vec++;
        pos = i;
    }
    vec+=(tam-i); // Avanzo el puntero vec hasta el último elemento del vector.
    for(i=tam-1; i>pos; i--)
    {
        *vec = *(vec-1);
        vec--;
    }
    *vec = elemento;
    return 1;
}

///Similar al Insertar, pero se inserta un 0.
int Eliminar_Elemento_Posicion_Vector(int* vec, int tam, int posicion)
{
    //Si la posicion donde se desea insertar es mayor al tamaño del vector.
    //Si la posicion donde se desea insertar es negativa.
    if(posicion>=tam || posicion<0)
    {
        return -1;
    }
    else
    {
        int i;
        for(i=0; i<posicion; i++)
        {
            vec++; // Avanzo el puntero que apunta a la posicion a insertar.
        }
        *vec = 0; // Inserción.
    }
    return 1;
}

void Eliminar_Primera_Aparicion_Elemento_Vector(int* vec, int tam, int elemento)
{
    int i = 0;
    //Avanzo hasta llegar al final del vector o encontrar la primera aparicion.
    while((*vec!=elemento && i<tam))
    {
        vec++;
        i++;
    }
    //Compruebo que condición fue la que termino la iteracion.
    if(*vec == elemento)
    {
        *vec = 0;
    }
}

int Eliminar_Todas_Apariciones_Elemento_Vector(int* vec, int tam, int elemento)
{
    int eliminados = 0;
    int i;
    for(i=0; i<tam; i++)
    {
        if(*vec == elemento)
        {
            *vec = 0;
            eliminados++;
        }
        vec++;
    }
    return eliminados;
}
