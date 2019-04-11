#include <stdio.h>
#include <stdlib.h>
#include "cola.h"

int main()
{
    T_cola cola;
    crear_cola(&cola);
    T_dato alumno;
    alumno.dni = 500;
    acolar(&cola, &alumno);
    T_dato alumno2;
    alumno2.dni = 800;
    acolar(&cola, &alumno2);
    T_dato alumno3;
    alumno3.dni = 1500;
    acolar(&cola, &alumno3);
    T_dato aux;
    desacolar(&cola, &aux);
    desacolar(&cola, &aux);
    ver_tope(&cola, &aux);
    printf("Frente:%d", aux.dni);
}
