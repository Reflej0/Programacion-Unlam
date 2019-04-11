#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int dni;
} T_alu;

typedef struct
{
    int dni;
} T_emp;

int main()
{
    FILE *alu = fopen("alu.dat", "rb+");
    FILE *emp = fopen("emp.dat", "rb+");
    T_alu alumno;
    T_emp empleado;

    fread(&alumno, sizeof(T_alu), 1, alu);
    fread(&empleado, sizeof(T_emp), 1, emp);

    int diferencia = 0;

    while(!feof(alu) && !feof(emp))
    {
        diferencia = alumno.dni - empleado.dni;
        if(diferencia == 0)
        {
            //TRATATIVA DE COINCIDENCIA.
            fread(&alumno, sizeof(T_alu), 1, alu);
            fread(&empleado, sizeof(T_emp), 1, emp);
        }
        if(diferencia > 0)
        {
            fread(&empleado, sizeof(T_emp), 1, emp);
        }
        if(diferencia < 0) // Si el dni del empleado es mayor que el del alumno.
        {
            fread(&alumno, sizeof(T_alu), 1, alu);
        }
    }
}
