#include <string.h>
#include "info.h"
#include "lista.h"
#include "biblioteca.h"
#define TAM 31

int leerArchivoYCargarLista(FILE *fp, t_lista *lista)
{
    int cantidad = 1;
    t_noved dato;
    fscanf(fp, "%6c%13f%10f%1d\n", dato.clave, &dato.canti, &dato.precio, &dato.nroReg);
    dato.clave[6] = '\0';
    while(!feof(fp))
    {
        if(dato.precio==0)
            dato.canti*=-1;
        /*printf("%s\n%f\n%f\n%d\n", dato.clave, dato.canti, dato.precio, dato.nroReg);
        system("PAUSE");*/
        insertarAlFinal(lista, &dato);
        fscanf(fp, "%6c%13f%10f%1d\n", dato.clave, &dato.canti, &dato.precio, &dato.nroReg);
        dato.clave[6] = '\0';
        cantidad++;
    }
    if(dato.precio==0)
            dato.canti*=-1;
    insertarAlFinal(lista, &dato);
    fscanf(fp, "%6c%9f%9f%d\n", dato.clave, &dato.canti, &dato.precio, &dato.nroReg);
    dato.clave[6] = '\0';
    return cantidad;
}
