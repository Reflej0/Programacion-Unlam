#include <stdio.h>
#include <stdlib.h>
#include "fecha.h"

int main()
{
    T_Fecha Fecha;
    int dias;
    Ingresar_fecha(&Fecha);
    dias = Ingresar_dia();
    T_Fecha Fmasdias = Sumar_dias_a_fecha(&Fecha, dias);
    printf("La fecha + %d dias es: %d/%d/%d\n", dias, Fmasdias.d, Fmasdias.m, Fmasdias.a);
    return 0;
}
