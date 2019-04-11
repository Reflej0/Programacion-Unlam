#ifndef RESTA_FECHAS_H_INCLUDED
#define RESTA_FECHAS_H_INCLUDED

typedef struct // OK !
{
    int d,
        m,
        a;
}   T_Fecha;

int es_Bisiesto(int a);

int cant_dias(int m, int a);

void Restar_Fecha(T_Fecha *Fecha, int dias);

int Fecha_a_Dias(T_Fecha *Fecha);

#endif // RESTA_FECHAS_H_INCLUDED
