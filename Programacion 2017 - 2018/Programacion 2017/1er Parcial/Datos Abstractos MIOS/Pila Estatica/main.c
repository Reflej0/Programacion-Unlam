#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

int main()
{
    T_pila pila;
    crear_pila(&pila);
    T_alumno alu1;
    alu1.dni = 4000000;
    alu1.nombre = "Juan";
    T_alumno alu2;
    alu2.dni = 3000000;
    alu2.nombre = "Carlos";
    T_alumno alu3;
    alu3.dni = 2000000;
    alu3.nombre = "Pablo";
    apilar(&pila, &alu1);
    apilar(&pila, &alu2);
    apilar(&pila, &alu3);
    T_alumno aux;
    ver_tope(&pila, &aux);
    printf("Nombre:%s, DNI: %d", aux.nombre, aux.dni);
}
