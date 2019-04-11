#include <stdio.h>
#include <stdlib.h>
#include "cola.h"

int main()
{
    t_cola cola;
    crear_cola(&cola);
    t_dato dato = 2;
    t_dato dato2 = 5;
    t_dato dato3 = 9;
    poner_en_cola(&cola, &dato);
    poner_en_cola(&cola, &dato2);
    poner_en_cola(&cola, &dato3);
    t_dato aux;
    sacar_de_cola(&cola, &aux);
    frente_de_cola(&cola, &aux);
    printf("Frente de cola:%d", aux);
}
