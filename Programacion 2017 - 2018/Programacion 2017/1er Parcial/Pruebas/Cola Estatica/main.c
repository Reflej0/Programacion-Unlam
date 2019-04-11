#include <stdio.h>
#include <stdlib.h>
#include "cola.h"

int main()
{
    T_cola cola;
    crear_cola(&cola);
    T_dato dato = 5;
    T_dato dato2 = 77;
    acolar(&cola, &dato);
    acolar(&cola, &dato2);
    T_dato aux;
    ver_frente(&cola, &aux);
    printf("%d", aux);
    desacolar(&cola, &aux);
    ver_frente(&cola, &aux);
    printf("\n%d", aux);
}
