#ifndef ESTRUCTURAS_H_INCLUDED
#define ESTRUCTURAS_H_INCLUDED
#include "fechas.h"
typedef struct
{
    char apellido[21];
    char nombre[21];
    T_fecha fnac;
    double sueldo;
} T_empleado;

#endif // ESTRUCTURAS_H_INCLUDED
