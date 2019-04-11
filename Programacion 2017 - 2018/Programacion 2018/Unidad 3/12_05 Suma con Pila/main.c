#include <stdio.h>
#include <stdlib.h>
#include "pila.h"
#include "funciones.h"

int main()
{
    FILE* arch = fopen("numeros.txt", "rt");
    if(!arch) exit(1);
    T_pila p1, p2, pr;
    crear_pila(&p1);
    crear_pila(&p2);
    crear_pila(&pr);
    cargar_primer_operando_archivo_en_pila(&p1, arch);
    cargar_segundo_operando_archivo_en_pila(&p2, arch);
    fclose(arch); // A esta altura ya no necesito mas el archivo.
    sumar_pilas(&p1, &p2, &pr);
    mostrar_pila(&pr);
    return 0;
}
