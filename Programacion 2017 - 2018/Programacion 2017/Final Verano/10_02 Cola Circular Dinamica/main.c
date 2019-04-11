#include <stdio.h>
#include <stdlib.h>
#include "cola.h"

int main()
{
    T_cola cola;
    crear_cola(&cola);
    T_dato dato = 5;
    T_dato dato2 = 8;
    T_dato dato3 = 13;
    T_dato dato4 = -9;
    T_dato dato5 = 35;
    acolar(&cola, &dato);
    acolar(&cola, &dato2);
    acolar(&cola, &dato3);
    acolar(&cola, &dato4);
    acolar(&cola, &dato5);
    T_dato aux;
    while(colaVacia(&cola)!=1)
    {
        desacolar(&cola, &aux);
        printf("%d\n", aux);
    }
}
