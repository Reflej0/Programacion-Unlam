#include <stdio.h>
#include <stdlib.h>
#include "fechas.h"

int main()
{
    int dia, mes, anio;
    int opcion;
    T_fecha fecha;
    printf("Ingrese una fecha(dd/mm/aaaa):");
    scanf("%d/%d/%d", &dia, &mes, &anio);
    if(fecha_valida(dia, mes, anio) == 1)
    {
        printf("La fecha ingresada es valida!");
        fecha.dia = dia;
        fecha.mes = mes;
        fecha.anio = anio;
    }
    else
    {
        printf("La fecha ingresada es invalida!");
        return 1; // Termino la ejecucion del programa.
    }
    system("CLS");
    printf("Fecha ingresada: %d/%d/%d", fecha.dia, fecha.mes, fecha.anio);
    printf("\n1)Sumar o restar dias\n2)Diferencias con respecto a otra fecha\n3)Nombre del dia de la fecha ingresada\nOpcion:");
    scanf("%d", &opcion);
    switch(opcion)
    {
    case 1:;
        int suma; // Variable solo utilizada en este case.
        printf("Ingrese la cantidad de dias a sumar o restar: ");
        scanf("%d", &suma);
        T_fecha f = sumar_dias_fecha(&fecha, suma);
        printf("%d/%d/%d", f.dia, f.mes, f.anio);
        break;
    case 2:;
        T_fecha fecha_a; // Variable solo utilizada en este case.
        printf("Ingrese una fecha adicional(dd/mm/aaaa):");
        scanf("%d/%d/%d", &dia, &mes, &anio);
        if(fecha_valida(dia, mes, anio) == 1)
        {
            fecha_a.dia = dia;
            fecha_a.mes = mes;
            fecha_a.anio = anio;
        }
        else
        {
            printf("La fecha ingresada es invalida!");
            return 1;
        }
        printf("La diferencia de dias entre las fechas ingresadas es: %d", fecha_a_dias(&fecha)-fecha_a_dias(&fecha_a));
        break;
    case 3:
        Nombre_Dia(&fecha);
        break;
    default:
        break;
    }
}
