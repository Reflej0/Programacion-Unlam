#include <stdio.h>
#include <stdlib.h>
#include "cola.h"

int main()
{
    T_dato alumno;
    alumno.dni = 100;
    T_dato alumno2;
    alumno2.dni = 500;
    T_dato alumno3;
    alumno3.dni = 900;
    T_cola cola;
    crear_cola(&cola);
    acolar(&cola, &alumno);
    acolar(&cola, &alumno2);
    acolar(&cola, &alumno3);
    T_dato aux;
    desacolar(&cola, &aux);
    ver_frente(&cola, &aux);
    printf("Frente:%d", aux.dni);
}
