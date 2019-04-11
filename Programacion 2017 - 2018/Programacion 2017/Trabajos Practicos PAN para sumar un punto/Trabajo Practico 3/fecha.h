#ifndef FECHA_H_INCLUDED
#define FECHA_H_INCLUDED

typedef struct
{
    int dia,
        mes,
        anio;
}   tFecha;

int es_Bisiesto(int a);

int cant_dias(int m, int a);

int es_Fecha_Valida(tFecha F);

int compare_fecha(tFecha const *Fecha1, tFecha const *Fecha2);

#endif // FECHA_H_INCLUDED
