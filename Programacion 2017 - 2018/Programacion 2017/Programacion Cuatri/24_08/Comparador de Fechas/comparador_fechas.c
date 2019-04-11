#include <stdio.h>
#include <stdlib.h>
#include "comparador_fechas.h"

/* Comparación de Fechas mas óptimo.
Como interpretar las salidas.
MAYOR a 0, FECHA1 MAYOR.
IGUAL a 0, FECHAS IGUALES.
MENOR a 0, FECHA1 MENOR.
*/


int compare_optimizado(t_Fecha *Fecha1, t_Fecha *Fecha2)
{
    int int_Fecha1 = ((Fecha1->a*10000)+(Fecha1->m*100)+(Fecha1->d));
    int int_Fecha2 = ((Fecha2->a*10000)+(Fecha2->m*100)+(Fecha2->d));
    return (int_Fecha1 - int_Fecha2);
}

/* POSIBLE SALIDAS

1) Fecha1 es mayor.
0) Las fechas son iguales.
-1) Fecha2 es mayor.

*/
int compare(t_Fecha *Fecha1, t_Fecha *Fecha2)
{
    if((Fecha1->a)>(Fecha2->a)) // Si el año de Fecha1 es mayor a Fecha2 entonces Fecha1 es mayor.
    {
        return 1;
    }
    if((Fecha1->a)<(Fecha2->a)) // Si el año de Fecha1 es menor a Fecha2 entonces Fecha1 es menor.
    {
        return -1;
    }
    if((Fecha1->a)==(Fecha2->a)) // Si estoy en el mismo año debo comparar meses.
    {
        if((Fecha1->m) > (Fecha2->m)) // Si el mes de Fecha1 es mayor al mes de Fecha2.
        {
            return 1;
        }
        if((Fecha1->m) < (Fecha2->m))
        {
            return -1;
        }
        if((Fecha1->m) == (Fecha2->m))  // Si estoy en el mismo mes.
        {
            if((Fecha1->d) > (Fecha2->d))
            {
                return 1;
            }
            if((Fecha1->d) < (Fecha2->d))
            {
                return -1;
            }
            if((Fecha1->d) == (Fecha2->d))
            {
                return 0;
            }
        }
    }
}
