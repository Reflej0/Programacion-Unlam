#include <stdio.h>
#include <stdlib.h>
#include "cola.h"

int main()
{
   T_cola cola;
   T_dato dato = "Palabra";
   T_dato dato2= "Words";
   T_dato aux[20];
   crear_cola(&cola);
   poner_en_cola(&cola, &dato);
   poner_en_cola(&cola, &dato2);
   ver_frente_de_cola(&cola, &aux);
   printf("El frente de la cola es: %s", *aux); //Porque tengo que desreferenciar aux ?
   //--------------------------------------------
   vaciar_cola(&cola);
   printf("\n0)Si la cola esta vacia:%d", cola_vacia(&cola));
}
