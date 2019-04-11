#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int DNI;
    char nombre[20];
} Empleado;

void Ingresar_Empleados(Empleado *Empleados)
{
    int i = 0;
    for(i=0;i<3;i++)
    {
        printf("\nIngrese DNI:");
        scanf("%d", &Empleados[i].DNI);
        fflush(stdin);
        printf("\nIngrese Nombre:");
        gets(Empleados[i].nombre);
    }
}

void Imprimir_Empleados(Empleado *Empleados)
{
    int i = 0;
    for(i=0;i<3;i++)
    {
        printf("\nDNI: %d NOMBRE:%s", Empleados[i].DNI, Empleados[i].nombre);
    }
}

int main()
{
    Empleado Empleados[3];
    Ingresar_Empleados(&Empleados);
    Imprimir_Empleados(&Empleados);
}
