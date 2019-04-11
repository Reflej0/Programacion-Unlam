#include <stdio.h>
#include <stdlib.h>
#include "ejercicio1.h"

int main()
{
    //Inicializo un puntero que me va a ser util para manejar mi vector dinamico.
    void *vector_din = NULL;
    //Inicializo otro puntero que me va a ser util para manejar el tipo de datos de mi vector dinamico.
    float *vector_convertido = NULL;
    //Le doy un tamaño inicial a mi puntero, en este caso 5 espacios para almacenar floats.
    vector_din = malloc(5*sizeof(float));
    //Convierto el vector a float.
    vector_convertido = (float*) vector_din;
    //El método llenar vector recibe el vector casteado como parámetro.
    int size = llenar_vector(vector_convertido);
    //Accedo al método menú y guardo la eleccion del usuario en una variable.
    int opcion = menu();
    //La opción elegida por el usuario pasa al método opciones, junto con el vector dinámico y su longitud.
    opciones(opcion, vector_convertido, size);
    //Guardar el array de números en un archivo de texto.
    guardar(vector_convertido, size);
}
