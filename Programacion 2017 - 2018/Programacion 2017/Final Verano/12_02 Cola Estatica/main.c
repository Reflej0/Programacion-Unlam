#include <stdio.h>
#include <stdlib.h>
#include "cola.h"

int main()
{
    T_cola cola;
    T_dato aux;
    crear_cola(&cola);
    T_dato dato = 5;
    T_dato dato2 = 8;
    T_dato dato3 = 13;
    T_dato dato4 = -9;
    T_dato dato5 = 35;
    poner_en_cola(&cola, &dato); // PONGO 5.
    sacar_de_cola(&cola, &aux); // SACO 5.
    poner_en_cola(&cola, &dato); // PONGO 5.
    poner_en_cola(&cola, &dato2); // PONGO 8.
    sacar_de_cola(&cola, &aux); // SACO 5.
    poner_en_cola(&cola, &dato2); // PONGO 8.
    poner_en_cola(&cola, &dato3); // PONGO 13.
    sacar_de_cola(&cola, &aux); // SACO 8.
    poner_en_cola(&cola, &dato4); // PONGO -9.
    sacar_de_cola(&cola, &aux); // SACO 8.
    poner_en_cola(&cola, &dato5); // PONGO 35.
    //QUEDA 13, -9, 35.
    while(cola_vacia(&cola) == 0)
    {
        sacar_de_cola(&cola, &aux);
        printf("%d\n", aux);
    }
}
