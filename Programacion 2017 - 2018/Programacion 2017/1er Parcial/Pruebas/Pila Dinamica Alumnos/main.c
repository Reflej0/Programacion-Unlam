#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

int main()
{
   T_dato alumno1;
   T_dato alumno2;
   T_dato alumno3;
   T_dato aux;
   alumno1.dni = 1;
   _strcmp(alumno1.nya, "Juan", 4);
   alumno2.dni = 9;
   _strcmp(alumno2.nya, "Carlos", 6);
   alumno3.dni = 3;
   _strcmp(alumno3.nya, "Choper", 6);
   T_pila pila;
   crear_pila(&pila);
   apilar(&pila, &alumno1);
   apilar(&pila, &alumno2);
   apilar(&pila, &alumno3);
   desapilar(&pila, &aux);
   ver_tope(&pila, &aux);
   printf("Alumno en el tope: %s", aux.nya);
}

void _strcmp(char* dest, const char* src, size_t cant)
{
    int i;
    for(i = 0; i < cant; i++)
    {
        dest[i] = src[i];
    }
    dest[i] = '\0';
}
