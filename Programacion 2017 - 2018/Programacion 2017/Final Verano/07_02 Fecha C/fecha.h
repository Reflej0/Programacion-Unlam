#ifndef FECHA_H_INCLUDED
#define FECHA_H_INCLUDED

typedef struct
{
    int dia;
    int mes;
    int ano;
} T_fecha;

int Es_Bisiesto(int ano);

int Cant_Dias_Mes(int ano, int mes);

int Cant_Dias_Ano(int ano);

int ValidarFecha(T_fecha* f);

int FechaaDias(T_fecha* f);

T_fecha SumarDias(T_fecha* f, int dias);

T_fecha DiasaFecha(int dias);

void NombreDia(T_fecha* f);

#endif // FECHA_H_INCLUDED
