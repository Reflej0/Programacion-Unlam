#include <stdio.h>
#include <stdlib.h>
#include "ejercicio1.h"

int main()
{
    //Inicializo un puntero que me va a ser util para manejar mi vector dinamico.
    void *vector_din = NULL;
    //Inicializo otro puntero que me va a ser util para manejar el tipo de datos de mi vector dinamico.
    float *vector_convertido = NULL;
    //Le doy un tama�o inicial a mi puntero, en este caso 5 espacios para almacenar floats.
    vector_din = malloc(5*sizeof(float));
    //Convierto el vector a float.
    vector_convertido = (float*) vector_din;
    //El m�todo llenar vector recibe el vector casteado como par�metro.
    int size = llenar_vector(vector_convertido);
    //Accedo al m�todo men� y guardo la eleccion del usuario en una variable.
    int opcion = menu();
    //La opci�n elegida por el usuario pasa al m�todo opciones, junto con el vector din�mico y su longitud.
    opciones(opcion, vector_convertido, size);
    //Guardar el array de n�meros en un archivo de texto.
    guardar(vector_convertido, size);
}
