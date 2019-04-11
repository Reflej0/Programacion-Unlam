#ifndef FECHA_H_INCLUDED
#define FECHA_H_INCLUDED

typedef struct
{
    int dia;
    int mes;
    int ano;
} T_fecha;


int ValidarFecha(T_fecha* f);

///Solo necesito el año.
int EsBisiesto(const T_fecha* f);

///Cantidad de dias del mes.
int CantidadDiasMes(const T_fecha* f);

///Cantidad de dias del año.
int CantidadDiasAno(const T_fecha* f);

///Devuelvo una fecha que es resultado de sumar n dias a la fecha pasada por parametro.
T_fecha SumarDias(const T_fecha* f, const int dias);

///Devuelvo una fecha que es resultado de restar n dias a la fecha pasada por parametro.
T_fecha RestarDias(const T_fecha* f, int dias);

///Devuelve en dias una fecha expresada en dd/mm/aaaa
int FechaaDias(const T_fecha* f);

///Devuelve una fecha expresada en dd/mm/aaaa en base a dias.
void DiasaFecha(T_fecha* f, int dias);

///Imprime el nombre del dia de una fecha ingresada.
void NombreDia(const T_fecha* f);

#endif // FECHA_H_INCLUDED
