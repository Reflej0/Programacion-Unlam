#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
#include "header.h"
#include "fecha.h"

//Esta funcion devuelve la fecha actual en formato dd/mm/yy en formato tFecha.
tFecha fecha_actual()
{
    tFecha f_actual;
    char auxiliar[5]; // Este es el buffer auxiliar.
    time_t rawtime;
    struct tm *timeinfo;
    time (&rawtime);
    timeinfo = localtime(&rawtime);
    strftime(auxiliar, 3, "%d", timeinfo);
    f_actual.dia = atoi(auxiliar);
    strftime(auxiliar, 3, "%m", timeinfo);
    f_actual.mes = atoi(auxiliar);
    strftime(auxiliar, 5, "%Y", timeinfo);
    f_actual.anio = atoi(auxiliar);
    return f_actual;
}

//El retorno es void ya que la salida de esta funcion es un alumno validado.
void ingresar_alumno(t_alumno* alu)
{
    ///Declaracion de variables para la estructura t_alumno.
    ///Datos AUTOGENERADOS.
    alu->estado = 'R';
    tFecha f_baja = {31, 12, 9999};
    alu->fbaja = f_baja;
    tFecha f_actual = fecha_actual();


    //Hasta que no introduzca un DNI valido no finaliza el ciclo.
    do
    {
        printf("Ingrese DNI:");
        scanf("%ld", &alu->dni);
    }
    while(!validar_dni(alu->dni));

    //Debo normalizar el apellido y nombre, que no es lo mismo que validar.
    fflush(stdin);
    printf("\nIngrese apellido y nombre:");
    fgets(alu->ayn, 40, stdin);
    normalizar_nya(alu->ayn);

    //Hasta que no se introduzca una fecha de nacimiento valida no finaliza el ciclo.
    do
    {
        printf("\nIngrese fecha de nacimiento dd/mm/aaaa:");
        scanf("%d/%d/%d", &alu->fnac.dia, &alu->fnac.mes, &alu->fnac.anio);
    }
    while(!validar_fecha_nac(&alu->fnac, &f_actual));

    //Hasta que no se introduzca un sexo valido no finaliza el ciclo.
    do
    {
        fflush(stdin);
        printf("\nIngrese sexo M o F:");
        alu->sexo = getchar();
    }
    while(!validar_sexo(alu->sexo));

    //Hasta que no se introduzca una fecha de ingreso valida no finaliza el ciclo.
    do
    {
        printf("\nIngrese fecha de ingreso dd/mm/aaaa:");
        scanf("%d/%d/%d", &alu->fing.dia, &alu->fing.mes, &alu->fing.anio);
    }
    while(!validar_fecha_ing(&alu->fing, &f_actual, &alu->fnac));

    //Hasta que no se introduzca una carrera valida no finaliza el ciclo.
    do
    {
        fflush(stdin);
        printf("\nIngrese las iniciales de su carrera:");
        fgets(alu->carrera, 4, stdin);
    }
    while(!validar_carrera(alu->carrera));

    //Hasta que no se introduzca una cantidad de materias aprobadas valida no finaliza el ciclo.
    do
    {
        printf("\nIngrese la cantidad de materias aprobadas:");
        scanf("%d", &alu->mataprobadas);
    }
    while(!validar_cant_materias(alu->mataprobadas));


    //Hasta que no se introduzca una fecha de de aprobacion de la ultima materia valida no finaliza el ciclo.
    do
    {
        printf("\nIngrese fecha de aprobacion de la ultima materia dd/mm/aaaa:");
        scanf("%d/%d/%d", &alu->ultmat.dia, &alu->ultmat.mes, &alu->ultmat.anio);
    }
    while(!validar_fecha_aprobacion_ult_mat(&alu->ultmat, &f_actual, &alu->fing));
}

//Esta funcion recibe un t_alumno como parametro.
//Devuelve por vec_errores.
void validar_alumno(t_alumno const *alumno, tFecha const *f_actual, int* vec_errores)
{
    vec_errores[0]=validar_dni(alumno->dni);
    vec_errores[1]=validar_fecha_nac(&(alumno->fnac), (f_actual));
    vec_errores[2]=validar_sexo(alumno->sexo);
    vec_errores[3]=validar_fecha_ing(&(alumno->fing), (f_actual), &(alumno->fnac));
    vec_errores[4]=validar_carrera(alumno->carrera);
    vec_errores[5]=validar_fecha_aprobacion_ult_mat(&(alumno->ultmat), (f_actual), &(alumno->fing));
    vec_errores[6]=validar_estado(alumno->estado);
    vec_errores[7]=validar_fecha_baja(&(alumno->fbaja));
}

//Devuelve 1 si el DNI se encuentra en el rango especificado.
int validar_dni(long int const dni)
{
    if((dni >10000) && (dni<100000000))
    {
        return 1;
    }
    return 0;
}

//Devuelve 1 si el alumno tiene por lo menos 10 años.
int validar_fecha_nac(tFecha const *fecha_nac, tFecha const *f_actual)
{
    tFecha fecha_10anos = *fecha_nac; // Copio el valor de la fecha de nacimiento en una variable local.
    fecha_10anos.anio += 10; // Le sumo 10 años a la fecha de nacimiento.
    /*
    Si a la fecha de nacimiento le sumo 10 años y aún así es menor o igual que la fecha actual, entonces
    tiene por lo menos 10 años.
    */
    if(es_Fecha_Valida(*fecha_nac) && compare_fecha(&fecha_10anos, f_actual)<=0)
    {
        return 1;
    }
    return 0;
}

//Devuelve 1 si el Sexo es F o M.
int validar_sexo(char const c)
{
    if((toupper(c) == 'M') || (toupper(c) == 'F'))
    {
        return 1;
    }
    return 0;
}

//Devuelve 1 si la fecha de ingreso es menor a la fecha actual, pero mayor a la fecha de nacimiento.
int validar_fecha_ing(tFecha const *fecha, tFecha const *f_actual, tFecha const *f_nac)
{
    if((compare_fecha(fecha, f_actual) <= 0) && compare_fecha(fecha, f_nac) > 0)
    {
        return 1;
    }
    return 0;
}

//Devuelve 1 si la carrera es la correcta.
int validar_carrera(const char *c)
{
    if((strcmp(c, "INF"))==0 || (strcmp(c, "ELE"))==0 || (strcmp(c, "IND"))==0 || (strcmp(c, "ECO"))==0 || (strcmp(c, "DER"))==0 || (strcmp(c, "ADM"))==0 || (strcmp(c, "MED"))==0 || (strcmp(c, "EDF"))==0 || strcmp(c, "FIL") == 0)
    {
        return 1;
    }
    return 0;
}

//Devuelve 1 si la cantidad de materias es mayor o igual a cero.
int validar_cant_materias(int const cant_materias)
{
    if(cant_materias >= 0)
    {
        return 1;
    }
    return 0;
}
//Devuelve 1 si la fecha de la aprobacion de la ultima materia es mayor a la fecha de ingreso y menor o igual a la fecha actual.
int validar_fecha_aprobacion_ult_mat(tFecha const *fecha, tFecha const *f_actual, tFecha const *f_ing)
{
    if((compare_fecha(fecha, f_ing) > 0) && compare_fecha(fecha, f_actual) <= 0)
    {
        return 1;
    }
    return 0;
}

//Devuelve 1 si el estado es R
int validar_estado(char const c)
{
    if(c == 'R')
    {
        return 1;
    }
    return 0;
}

//Devuelve 1 si la fecha es igual a 31/12/9999.
int validar_fecha_baja(tFecha const *fecha)
{
    if((fecha->dia == 31) && (fecha->mes == 12) && (fecha->anio == 9999))
    {
        return 1;
    }
    return 0;
}

char* normalizar_nya(char* nya)
{
    char* inicio = nya;
    char* escritura = nya;
    int primeraletra = 1;
    char* coma = NULL;
    while(*nya == ' ') //Sacar los espacios al inicio.
    {
        nya++;
    }
    while(*nya)
    {
        if(((*nya>='a' && *nya<='z') || (*nya>='A' && *nya<='Z')))
        {
            if(primeraletra == 1){*escritura = toupper(*nya); primeraletra = 0;}
            else *escritura = tolower(*nya);
            escritura++;
        }
        else if(*nya == ' ' && *(nya+1)!=' ' && *(nya+1)!='\0')
        {
            primeraletra = 1;
            *escritura = ',';
            escritura++;
            coma = escritura;
        }
        nya++;
    }
    *escritura = '\0';
    if(coma) //Insertar el espacio despues de la coma y desplazar a la derecha.
    {
        char c = ' ';
        intercambio(coma, &c);
        while(*coma)
        {
            coma++;
            intercambio(coma, &c);
        }
    }
    return inicio;
}

void intercambio(char *c, char *d)
{
    char aux = *c;
    *c = *d;
    *d = aux;
}
