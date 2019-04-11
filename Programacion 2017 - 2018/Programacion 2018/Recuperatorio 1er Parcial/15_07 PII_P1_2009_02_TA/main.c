#include <stdio.h>
#include <stdlib.h>
#include "cola.h"

unsigned eliminar_apariciones(char* cad, char c)
{
    if(!cad || !*cad) return 0;
    unsigned eliminados = 0;
    char* escritura = cad;
    while(*cad)
    {
        if(*cad != c)
        {
            *escritura = *cad;
            escritura++;
        }
        else
            eliminados++;
        cad++;
    }
    *escritura = '\0';
    return eliminados;
}

int main()
{
    //char lote[50] = "Habia un abaco con muchas aaa pero murio";
    //printf("Lote: %s\nEliminados: %d", lote, eliminar_apariciones(lote, 'a'));
    T_cola cola;
    T_dato uno = 1;
    T_dato dos = 2;
    T_dato tres = 3;
    T_dato cuatro = 4;
    T_dato cinco = 5;
    T_dato aux;
    crear_cola(&cola);
    acolar(&cola, &uno);
    acolar(&cola, &dos);
    acolar(&cola, &tres);
    acolar(&cola, &cuatro);
    acolar(&cola, &cinco);
    desacolar(&cola, &aux);
    desacolar(&cola, &aux);
    desacolar(&cola, &aux);
    acolar(&cola, &tres);
    acolar(&cola, &cuatro);
    acolar(&cola, &cinco);
    desacolar(&cola, &aux);
    desacolar(&cola, &aux);
    desacolar(&cola, &aux);
    printf("Frente: %d", aux);
    return 0;
}
