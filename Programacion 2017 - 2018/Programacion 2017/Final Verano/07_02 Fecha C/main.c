#include <stdio.h>
#include <stdlib.h>
#include "fecha.h"

int main()
{
    T_fecha f_teclado;
    printf("Ingrese una fecha:");
    scanf("%d/%d/%d", &f_teclado.dia, &f_teclado.mes, &f_teclado.ano);
    int esValido = ValidarFecha(&f_teclado);
    if(esValido == 1)
    {
       printf("\nLa fecha ingresada es valida");
    }
    else
    {
        printf("\nLa fecha ingresada no es valida");
    }

    int dias = FechaaDias(&f_teclado);
    printf("\nLa fecha a dias es: %d", dias);

    int d_teclado;
    printf("\nIngrese dias para sumar/restar a la fecha:");
    scanf("%d", &d_teclado);
    T_fecha f_resultado = SumarDias(&f_teclado, d_teclado);
    printf("\nFecha Resultante:%d/%d/%d", f_resultado.dia, f_resultado.mes, f_resultado.ano);
    NombreDia(&f_teclado);
}
