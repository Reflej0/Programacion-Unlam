#include <stdio.h>
#include <stdlib.h>
#include "cola.h"

int main()
{
    T_dato primero = 1;
    T_dato segundo = 2;
    T_dato tercero = 3;
    T_dato cuarto = 4;
    T_dato quinto = 5;
    T_dato sexto = 6;
    T_dato septimo = 7;
    T_cola cola;
    crear_cola(&cola);
    acolar(&cola, &primero);
    acolar(&cola, &segundo);
    acolar(&cola, &tercero);
    acolar(&cola, &cuarto);
    acolar(&cola, &quinto);
    acolar(&cola, &sexto);
    acolar(&cola, &septimo);
    T_dato respuesta;
    while(colaVacia(&cola) != 1)
    {
        desacolar(&cola, &respuesta);
        printf("Orden de llegada: %d\n", respuesta);
    }

}
