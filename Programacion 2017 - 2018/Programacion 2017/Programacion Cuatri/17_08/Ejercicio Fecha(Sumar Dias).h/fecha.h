#ifndef FECHA_H_INCLUDED
#define FECHA_H_INCLUDED

typedef struct // OK !
{
    int d,
        m,
        a;
}   T_Fecha;

int es_Bisiesto(int a);

int Ingresar_dia();


T_Fecha Sumar_dias_a_fecha(T_Fecha *Fini, int dias);


int cant_dias(int m, int a);


int es_Fecha_Valida(T_Fecha *F);


void Ingresar_fecha(T_Fecha *F);


#endif // FECHA_H_INCLUDED
