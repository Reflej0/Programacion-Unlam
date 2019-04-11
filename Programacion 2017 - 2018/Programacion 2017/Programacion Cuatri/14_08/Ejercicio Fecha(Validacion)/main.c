#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int d,
        m,
        a;
}   tFecha;

int es_Bisiesto(int a)
{
    if(a % 400 == 0 || (a % 4 == 0 && a % 100!=0)){
        return 1;
    }
    else{
        return 0;
    }
}

int cant_dias(int m, int a)
{
    //int i;
    int vec1[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30};
    int vec2[12] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30};
    if(es_Bisiesto(a)){
        return vec1[m-1];
    }
    else{

        return vec2[m-1];
    }
}

int es_Fecha_Valida(tFecha F)
{
    if(F.a>1600){
        if(F.m >01 && F.m<=12){
            if(F.d>=1 && F.d<=cant_dias(F.m, F.a)){
                return 1;
            }
        }
    }
    return 0;
}

int main()
{
    tFecha Fecha; // Variable tipo tFecha.
    printf("Ingrese el dia, mes y año:");
    scanf("%d %d %d", &Fecha.d, &Fecha.m, &Fecha.a);
    if(es_Fecha_Valida(Fecha)){
        printf("Fecha correcta");
    }
    else{
        printf("Fecha incorrecta");
    }
}
