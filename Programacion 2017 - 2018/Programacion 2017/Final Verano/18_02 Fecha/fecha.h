#ifndef FECHA_H_INCLUDED
#define FECHA_H_INCLUDED

typedef struct
{
    int ano;
    int mes;
    int dia;
} T_fecha;

int esBisiesto(int ano);

int CantDiasMes(int mes, int ano);

int CantDiasAno(int ano);

T_fecha DiasaFechas(int dias);

int ValidarFecha(T_fecha* f);

int FechaaDias(T_fecha* f);

T_fecha SumarDias(T_fecha* f, int dias);

void NombreDia(T_fecha* f);

#endif // FECHA_H_INCLUDED
