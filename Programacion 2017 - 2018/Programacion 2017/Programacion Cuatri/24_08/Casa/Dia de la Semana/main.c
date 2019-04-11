#include <stdio.h>
#include <stdlib.h>
#include "dia_semana.h"

int main()
{
    T_Fecha Fecha;
    printf("Ingrese la fecha dd/mm/aaaa:");
    scanf("%d/%d/%d", &Fecha.d, &Fecha.m, &Fecha.a);
    Dia_Semana(&Fecha);
}
