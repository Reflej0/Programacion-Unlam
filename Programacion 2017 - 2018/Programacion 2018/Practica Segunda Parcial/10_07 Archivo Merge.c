#include <stdio.h>
#include <stdlib.h>

void actualizar_por_merge(FILE* empleados, FILE* estudiantes, T_cmp cmp)
{
	rewind(empleados);
	rewind(estudiantes);
	T_empleado emp;
	T_estudiante est;
	fread(&emp, sizeof(T_empleado), 1, empleados);
	fread(&est, sizeof(T_estudiante), 1, estudiantes);
	while(!feof(empleados) && !feof(estudiantes))
    {
        int comp = cmp(&emp, &est);
        if(comp == 0)
        {
            if(condicion_de_promedio_o_similar)
            {
                emp.sueldo*=1.10;
                fseek(empleados, -1L*sizeof(T_empleados), SEEK_CUR);
                fwrite(&emp, sizeof(T_empleados), 1, empleados);
                fseek(empleados, 0L, SEEK_CUR);
            }
            fread(&emp, sizeof(T_empleado), 1, empleados);
            fread(&est, sizeof(T_estudiante), 1, estudiantes);
        }
        else if(comp>0)
            fread(&est, sizeof(T_estudiante), 1, estudiantes);
        else
            fread(&emp, sizeof(T_empleado), 1, empleados);
    }
}
