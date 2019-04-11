#include"fecha.h"

int esfechavalida(t_fecha f)
{
    if(f.a>=1600)
    {
        if(f.m>=1 && f.m<=12)
        {
            if(f.d>=1 && f.d<=cantdiames)
                return 1;
        }
    }
    else
        return 0;
}

int cantdiames(int m, int a)
{
    int v[]={31,28,31,30,31,30,31,31,30,31};
    if(m==2)
    {
        if(esbisiesto(a))
            return 29;
    }
    else
        return v[m-1];
}

int esbisiesto(int a)
{
    return((a%4==0 && a%100) ||a%400==0);
}

t_fecha incrementarundia(t_fecha f)
{
    if(f.d<cantdiames(f.m,f.a))
    {
            f.d++;
    }
    else
    {
        if(f.m!=12)
        {
            f.m++;
            f.d=1;
        }
        else
        {
            f.d=1;
            f.m=1;
            f.a++;
        }
    }
    return f;
}

size_t restarFecha(t_fecha fnac,t_fecha factual)
{
    unsigned int edad;

    edad=factual.a-fnac.a;
    if((factual.m-fnac.m<0) || (factual.m-fnac.m==0 && factual.d-fnac.d<0))
        edad--;
    return edad;
}

int compararFecha(t_fecha f1,t_fecha f2)
{
    if(f1.a-f2.a==0)
    {
        if(f1.m-f2.m==0)
            return f1.d-f2.d;
        return f1.m-f2.m;
    }
    return f1.a-f2.a;
}

