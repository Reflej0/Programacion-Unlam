#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int dia,
        mes,
        anio;
}   tFecha;


int DiferenciaDias(tFecha Fecha1, tFecha Fecha2) // Una aproximacion rápida.
{
    int anos, meses, dias;
    anos = Fecha1.anio - Fecha2.anio;
    meses = Fecha2.mes - Fecha2.mes;
    dias = Fecha1.dia - Fecha2.dia;
    return ((anos*365)+(meses*30)+dias);
}

int main()
{
    tFecha Fecha1, Fecha2;
    printf("Ingrese dia, mes y año:");
    scanf("%d %d %d", &Fecha1.dia, &Fecha1.mes, &Fecha1.anio);
    printf("\n------------------------------------------------");
    printf("\nIngrese dia, mes y año:");
    scanf("%d %d %d", &Fecha2.dia, &Fecha2.mes, &Fecha2.anio);
    printf("\nLa diferencia en dias entre las fechas ingresadas es %d", DiferenciaDias(Fecha1, Fecha2));
}
