#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int dni;
    char apellido[20];
    char nombre[20];
    float sueldo;
} Empleado;

/* Cosas a arreglar o revisar:
1) El FEOF devuelve un registro de más, al revisar en internet no recomiendan su uso en algunas situaciones junto con fgets.
2) Al reemplazar la condicion de FEOF por fscanf, se necesita el if y el else.
3) El fgets(auxiliar) funciona pero no se porque, mas claro imposible.
*/

void txt_a_bin_fijo(FILE *txt, FILE *bin)
{
    int i = 0;
    fseek(txt, 0, SEEK_SET); // Al manipular archivos abiertos en otra función es altamente recomendable volver al inicio del archivo.
    fseek(bin, 0, SEEK_SET); // Al manipular archivos abiertos en otra función es altamente recomendable volver al inicio del archivo.
    Empleado emp; // Variable auxiliar para realizar la conversion txt -> bin.
    char dni[9]; // Variable auxiliar para realizar el atoi.
    char sueldo[9]; // Variable auxiliar para realizar el atof.
    char auxiliar[1]; // Variable auxiliar para realizar el reemplazo del FEOF.
    //fgets(dni, 9, txt);
    while(fscanf(txt, "%c", auxiliar) == 1) // Se prefiere utilizar esta condición antes que el FEOF.
    {
        if(i==0) // Si es la primera leo el archivo con esto me evito el fgets afuera.
        {
            fseek(txt, 0, SEEK_SET);
        }
        else // Con esto retrocedo el fscanf de un caracter.
        {
            fseek(txt, -1, SEEK_CUR);
        }
        fgets(dni, 9, txt);
        fgets(emp.nombre, 20, txt);
        fgets(emp.apellido, 20, txt);
        fgets(sueldo, 9, txt);
        emp.dni = atoi(dni);
        emp.sueldo = atof(sueldo);
        fgets(auxiliar, 5, txt);
        //printf("DNI:%d, NOMBRE:%s, APELLIDO:%s, SUELDO:%.2f", emp.dni, emp.nombre, emp.apellido, emp.sueldo);
        //printf("\n");
        fwrite(&emp, sizeof(Empleado), 1, bin);
        i++;
    }
}

void mostrar_empleados(FILE *f_empleados)
{
    fseek(f_empleados, 0, SEEK_SET); // Al manipular archivos abiertos en otra función es altamente recomendable volver al inicio del archivo.
    Empleado emp;
    if(!f_empleados)
    {
        return;
    }
    fread(&emp, sizeof(Empleado), 1, f_empleados);
    while(!feof(f_empleados))
    {
        printf("Dni: %d, Sueldo: %f\n", emp.dni, emp.sueldo);
        fread(&emp, sizeof(Empleado), 1, f_empleados);
    }
}

int main()
{
    FILE *f_empleados = fopen("empleados.txt", "rt+");
    FILE *f_empleados_bin = fopen("empleados.dat", "wb+"); // El archivo primero se escribe y despues se lee para verificar.
    txt_a_bin_fijo(f_empleados, f_empleados_bin); // Realizo la conversion.
    mostrar_empleados(f_empleados_bin); // Leo el archivo a ver si lo guardo bien.
    fclose(f_empleados);
    fclose(f_empleados_bin);
}
