#include <stdio.h>
#include <stdlib.h>
#include "archivo.h"

bool archivoValido(FILE* archivo, char ruta[])
{
    archivo = fopen(ruta, "r");
    if(archivo == NULL)
    {
        return false;
    }
    else
    {
        return true;
    }
}
