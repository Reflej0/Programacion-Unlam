#include <stdio.h>
#include <stdlib.h>

typedef struct // OK !
{
    int d,
        m,
        a;
}   T_Fecha;

int es_Bisiesto(int a) // OK !
{
    if(a % 400 == 0 || (a % 4 == 0 && a % 100!=0)){
        return 1;
    }
    else{
        return 0;
    }
}

int Ingresar_dia() // OK !
{
    int dias;
    puts("Ingrese la cantidad de dias");
    scanf("%d", &dias);
    while(dias<0)
    {
        puts("Ingrese un dia no negativo");
        scanf("%d", &dias);
    }
    return dias;
}

T_Fecha Sumar_dias_a_fecha(T_Fecha *Fini, int dias) // OK !
{
    T_Fecha Ffin = *Fini;
    Ffin.d += dias;
    int cdm;
    while(Ffin.d>(cdm = cant_dias(Ffin.m, Ffin.a)))
    {
        Ffin.d-=cant_dias(Ffin.m, Ffin.a);
        Ffin.m++;
        if(Ffin.m>12)
        {
            Ffin.m=1;
            Ffin.a++;
        }

    }
    return Ffin;
}

int cant_dias(int m, int a) // OK !
{
    int vec1[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int vec2[12] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if(es_Bisiesto(a)){
        return vec1[m-1];
    }
    else{

        return vec2[m-1];
    }
}

int es_Fecha_Valida(T_Fecha *F) // OK !
{
    if((F->a)>1600){
        if(((F->m) > 0) && ((F->m)<13)){
            if((F->d)>=1 && (F->d)<=cant_dias((F->m), (F->a))){
                return 1;
            }

        }

    }
    return 0;
}

void Ingresar_fecha(T_Fecha *F) //OK !
{
    puts("Ingrese una fecha");
    scanf("%d/%d/%d", &F->d, &F->m, &F->a);
    while(!es_Fecha_Valida(F))
    {
        puts("Fecha invalida, ingrese de nuevo");
        scanf("%d/%d/%d", &F->d, &F->m, &F->a);
    }
}

int main()
{
    T_Fecha Fecha;
    int dias;
    Ingresar_fecha(&Fecha);
    dias = Ingresar_dia();
    T_Fecha Fmasdias = Sumar_dias_a_fecha(&Fecha, dias);
    printf("La fecha + %d dias es: %d/%d/%d\n", dias, Fmasdias.d, Fmasdias.m, Fmasdias.a);
    return 0;
}
