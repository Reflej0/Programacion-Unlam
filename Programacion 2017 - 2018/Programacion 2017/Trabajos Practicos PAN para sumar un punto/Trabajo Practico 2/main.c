#include <stdio.h>
#include <stdlib.h>
#include "indice.h"
#include "def.h"
#include "lista.h"


int main()
{
   ///CREACION DEL INDICE.
   T_indice indice;
   ind_crear(&indice);
   ///DATOS DE PRUEBA.
   T_dato registro;
   registro.dni = 12345678;
   registro.nro_reg = 1;
   ind_insertar(&indice, &registro);
   T_dato registro2;
   registro2.dni = 38567321;
   registro2.nro_reg = 2;
   ind_insertar(&indice, &registro2);
   T_dato registro3;
   registro3.dni = 40512347;
   registro3.nro_reg = 3;
   ind_insertar(&indice, &registro3);
   ///MOSTRAR LISTA.
   printf("3 REGISTROS DE LA LISTA:");
   mostrar_lista(&(indice.l));
   printf("\n");
   printf("\n");
   ///MOSTRAR INICIO DE LA LISTA Y ACTUAL.
   T_dato aux;
   ind_primero(&indice, &aux);
   printf("\nINICIO DE LA LISTA, DNI: %ld", aux.dni);
   printf("\n");
   printf("\n");
   ind_siguiente(&indice, &aux);
   printf("\nSIGUIENTE DE LA LISTA, DNI: %ld", aux.dni);
   printf("\n");
   printf("\n");
   ///BUSCAR EN LA LISTA.
   printf("DEVUELVE 0, SI ENCONTRO EL REGISTRO 3:%d", ind_buscar(&indice, &registro3));
   printf("\n");
   printf("\n");
   ///GUARDAR LISTA.
   printf("Ingrese la ruta del archivo para guardar el indice:");
   char ruta[70] = "";
   gets(ruta);
   ind_grabar(&indice, ruta);
   printf("\n");
   printf("\n");
   ///ABRIR LISTA GUARDADA.
   printf("Ingrese la ruta del archivo para abrir el indice:");
   gets(ruta);
   ind_cargar(&indice, ruta);
   ///ELIMINAR DE LA LISTA.
   ind_eliminar(&indice, &registro2);
   printf("\nLISTA TRAS ELIMINAR EL REGISTRO DEL MEDIO");
   mostrar_lista(&(indice.l));
}
