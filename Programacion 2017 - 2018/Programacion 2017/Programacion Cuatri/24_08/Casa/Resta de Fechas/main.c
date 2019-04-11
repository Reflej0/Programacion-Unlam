#include <stdio.h>
#include <stdlib.h>
#include "resta_fechas.h"

int main()
{
    T_Fecha Fecha;
    int dias;
    printf("Ingrese una fecha dd/mm/aaaa:");
    scanf("%d/%d/%d", &Fecha.d, &Fecha.m, &Fecha.a);
    printf("\nIngrese la cantidad de días a restar:");
    scanf("%d", &dias);
    Restar_Fecha(&Fecha, dias);
    printf("%d/%d/%d", Fecha.d, Fecha.m, Fecha.a);
}
