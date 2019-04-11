#include <stdio.h>
#include <stdlib.h>
#include "dia_semana.h"

//Esta función me permite corroborar si un año es bisiesto o no.
int es_Bisiesto(int a)
{
    if(a % 400 == 0 || (a % 4 == 0 && a % 100!=0)){
        return 1;
    }
    else{
        return 0;
    }
}

//Este método convierte una fecha (dd/mm/aaaa) -> dd
int Fecha_a_Dias(T_Fecha *Fecha)
{
    int dias = 0; //Esta variable es la que almacena la fecha convertida a dias.
    int auxiliar; // Esta variable la voy a usar para dos ciclos diferentes, pero su uso es claro.
    auxiliar = Fecha->a; // Guardo el valor de los años de la estructura fecha en auxiliar.
    while(auxiliar>1900) //Voy recorriendo los años, hasta llegar a 1900 mi año 0 (Coincide con el usado por Excel).
    {
        if(es_Bisiesto(auxiliar)) // Si el año es bisiesto sumo 366 dias.
        {
            dias+=366;
        }
        else // Si el año no es bisiesto sumo 365 dias.
        {
            dias+=365;
        }
        auxiliar--;
    }
    auxiliar = 1; //Ahora auxiliar empieza desde 1 (Enero).
    while(auxiliar<(Fecha->m)) //Mientras que la variable auxiliar no llegue al mes de la fecha.
    {
        if(auxiliar == 2 && es_Bisiesto(Fecha->a)) // Si estoy en febrero y el año es bisiesto.
        {
            dias+=29;
        }
        if(auxiliar == 2 && !es_Bisiesto(Fecha->a)) // Si estoy en febrero y el año no es bisiesto.
        {
            dias+=28;
        }
        if(auxiliar == 4 || auxiliar == 6 || auxiliar == 9 || auxiliar == 11) // Si estoy en un mes con 30 dias.
        {
            dias+=30;
        }
        if(auxiliar == 1 || auxiliar == 3 || auxiliar == 5 || auxiliar == 7 || auxiliar == 8 || auxiliar == 10 || auxiliar == 12)
        {
            dias+=31;
        }
        auxiliar++;
    }
    dias+=Fecha->d; // Por último sumo los días que es lo mas fácil.
    return dias;
}

void Dia_Semana(T_Fecha *Fecha)
{
    T_Fecha Fecha_Standard;
    Fecha_Standard.d = 1;
    Fecha_Standard.m = 1;
    Fecha_Standard.a = 1900;
    //LUNES.

    int int_Fecha_Standard = Fecha_a_Dias(&Fecha_Standard);
    int int_Fecha = Fecha_a_Dias(Fecha);
    switch((int_Fecha-int_Fecha_Standard)%7)
    {
    case 0:
        puts("LUNES");
    break;
    case 1:
        puts("MARTES");
    break;
    case 2:
        puts("MIERCOLES");
    break;
    case 3:
        puts("JUEVES");
    break;
    case 4:
        puts("VIERNES");
    break;
    case 5:
        puts("SABADO");
    break;
    case 6:
        puts("DOMINGO");
    break;
    }
}
