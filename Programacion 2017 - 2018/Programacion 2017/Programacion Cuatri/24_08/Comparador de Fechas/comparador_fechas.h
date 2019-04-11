#ifndef COMPARADOR_FECHAS_H_INCLUDED
#define COMPARADOR_FECHAS_H_INCLUDED

typedef struct // OK !
{
    int d,
        m,
        a;
}   t_Fecha;

int compare(t_Fecha *Fecha1, t_Fecha *Fecha2);
int compare_optimizado(t_Fecha *Fecha1, t_Fecha *Fecha2);


#endif // COMPARADOR_FECHAS_H_INCLUDED
