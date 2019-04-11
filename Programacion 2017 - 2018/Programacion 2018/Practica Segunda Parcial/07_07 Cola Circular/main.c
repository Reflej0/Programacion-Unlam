#include <stdio.h>
#include <stdlib.h>
#include "cola.h"

int main()
{
    T_cola cola;
    crear_cola(&cola);
    T_dato uno = 1;
    T_dato dos = 2;
    T_dato tres = 3;
    T_dato cuatro = 4;
    T_dato aux;
    acolar(&cola, &uno);
    desacolar(&cola, &aux);
    acolar(&cola, &dos);
    desacolar(&cola, &aux);
    acolar(&cola, &tres);
    desacolar(&cola, &aux);
    acolar(&cola, &cuatro);
    ver_frente(&cola, &aux);
    printf("Frente: %d", aux);
    //desacolar(&cola, &aux);
    //desacolar(&cola, &aux);
    //acolar(&cola, &cuatro);
    vaciar_cola(&cola);
    //ver_frente(&cola, &aux);
    printf("Cola vacia: %d", esta_cola_vacia(&cola));
    return 0;
}
