#include <stdio.h>
#include <stdlib.h>
#include "cola.h"

int main()
{
    T_cola cola;
    crear_cola(&cola);
    T_dato dato = 5;
    acolar(&cola, &dato);
    T_dato dato2 = 8;
    acolar(&cola, &dato2);
    T_dato aux;
    desacolar(&cola, &aux);
    ver_frente(&cola, &aux);
    printf("%d", aux);
}
