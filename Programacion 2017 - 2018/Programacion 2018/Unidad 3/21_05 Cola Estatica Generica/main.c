#include <stdio.h>
#include <stdlib.h>
#include "cola.h"

//La cola es de tamaño 4. es cola.h.
int main()
{
    ///LOTE.
    T_dato uno = '1';
    T_dato dos = '2';
    T_dato tres = '3';
    T_dato cuatro = '4';
    T_dato cinco = '5';
    T_dato aux;
    T_cola cola;
    crear_cola(&cola);

    ///ACOLAR 5 ELEMENTOS, CON TAMANO DE COLA 4.
    acolar(&cola, &uno);
    acolar(&cola, &dos);
    acolar(&cola, &tres);
    acolar(&cola, &cuatro);
    acolar(&cola, &cinco); // Este elemento no se acolará.

    ///PRUEBAS.
    ver_frente(&cola, &aux);
    printf("Frente de cola: %c", aux); // Esta entrada debe mostrar 1.

    if(cola_llena(&cola)) //Debe imprimir cola llena.
        printf("\nCola llena");

    printf("\nDesacolo un elemento...");
    desacolar(&cola, &aux);
    ver_frente(&cola, &aux);
    printf("\nFrente de cola: %c", aux); // Esta entrada debe mostrar 2.

    if(!cola_llena(&cola)) // Debe imprimir cola con espacio.
        printf("\nCola con espacio");

    printf("\nAcolo un elemento...");
    acolar(&cola, &cinco); //Acolo el 5, ahora si puedo.
    if(cola_llena(&cola)) //Debe imprimir cola llena.
        printf("\nCola llena");

    printf("\nDesacolo todos los elementos...");
    //Desacolo los 4 elementos de la cola.
    desacolar(&cola, &aux);
    desacolar(&cola, &aux);
    desacolar(&cola, &aux);
    desacolar(&cola, &aux);
    if(cola_vacia(&cola)) //Debe imprimir cola vacia.
        printf("\nCola vacia");
    return 1;
}
