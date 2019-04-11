#ifndef FECHA_H_INCLUDED
#define FECHA_H_INCLUDED

typedef struct
{
    int dia;
    int mes;
    int ano;
} T_fecha;

int es_bisiesto(T_fecha* f);

int cant_dias_mes(T_fecha* f);

int ValidarFecha(T_fecha* f);

int cant_dias_ano(int ano);

int FechaaDias(T_fecha* f);

T_fecha SumarDias(T_fecha* f, int dias);

T_fecha DiasaFechas(int fdias);

void NombreDia(T_fecha* f);

#endif // FECHA_H_INCLUDED
