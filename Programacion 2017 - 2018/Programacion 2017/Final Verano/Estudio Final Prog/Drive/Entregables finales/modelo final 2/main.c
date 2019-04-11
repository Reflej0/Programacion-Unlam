
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "main.h"
#include "propialibreria.h"

int main(void)
{
    FILE       *fpEnt,
               *fpSal,
               *fpMal;
    tListaD     lista;

    crearArchivo();

    if(!abrirArchivo(&fpEnt, ARCH_ENT, "rt", CONMSJ))
        return 1;
    if(!abrirArchivo(&fpSal, ARCH_SAL, "wt", CONMSJ))
    {
        fclose(fpEnt);
        return 2;
    }
    if(!abrirArchivo(&fpMal, ARCH_MAL, "wt", CONMSJ))
    {
        fclose(fpSal);
        fclose(fpEnt);
        return 2;
    }
    crearListaD(&lista);

    leerPonerEnListaSacarReemplazarYGrabar(fpEnt, fpSal, fpMal, &lista);

    fclose(fpEnt);
    fclose(fpSal);
    fclose(fpMal);

    mostrarArchivo(ARCH_ENT);
    mostrarArchivo(ARCH_SAL);
    mostrarArchivo(ARCH_MAL);

    return 0;
}

