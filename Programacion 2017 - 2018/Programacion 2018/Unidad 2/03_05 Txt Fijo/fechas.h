#ifndef FECHAS_H_INCLUDED
#define FECHAS_H_INCLUDED

typedef struct
{
    int dia;
    int mes;
    int anio;
} T_fecha;

int es_bisiesto(int anio);

int cant_dias_mes(int mes, int anio);

int cant_dias_mes_excel(int mes, int anio);

int cant_dias_anio(int anio);

int cant_dias_anio_excel(int anio);

int fecha_valida(int dia, int mes, int anio);

int fecha_a_dias(T_fecha *f);

T_fecha dias_a_fechas(int dias);

T_fecha sumar_dias_fecha(T_fecha *f, int dias);

void Nombre_Dia(T_fecha *f);

#endif // FECHAS_H_INCLUDED
