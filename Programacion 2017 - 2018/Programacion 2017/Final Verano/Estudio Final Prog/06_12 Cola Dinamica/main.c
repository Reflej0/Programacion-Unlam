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
    poner_en_cola(&cola, &dato);
    poner_en_cola(&cola, &dato2);
    poner_en_cola(&cola, &dato3);
    poner_en_cola(&cola, &dato4);
    poner_en_cola(&cola, &dato5);
    T_dato aux;
    while(cola_vacia(&cola) == 0)
    {
        sacar_de_cola(&cola, &aux);
        printf("%d\n", aux);
    }
}
