#include <stdio.h>
#include <stdlib.h>
#include "archivo.h"
int main()
{
    bool respuesta;
    FILE *archivo;
    respuesta = archivoValido(&archivo, "archivo.txt");
    if(respuesta)
    {
        printf("El archivo abierto correctamente");
    }
    else
    {
        printf("Hubo un error al abrir el archivo");
    }
}
