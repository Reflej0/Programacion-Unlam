#ifndef FECHA_H_INCLUDED
#define FECHA_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int d,
        m,
        a;
} t_fecha;

int esfechavalida(t_fecha);
int cantdiames(int,int);
int esbisiesto(int);
t_fecha incrementarundia(t_fecha);
t_fecha sumardiasafecha(t_fecha, int);
size_t restarFecha(t_fecha fnac,t_fecha factual);
#endif // FECHA_H_INCLUDED
