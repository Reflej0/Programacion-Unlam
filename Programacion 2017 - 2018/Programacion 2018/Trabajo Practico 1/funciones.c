#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
#include "header.h"
#include "fecha.h"
#define ES_LETRA(c) (((c>='a' && c<='z') ||(c>='A' && c<='Z')) ? 1 : 0)

//Esta funcion "devuelve" la fecha actual en formato dd/mm/yy en formato string(char*).

void fecha_actual(tFecha *f_actual)
{
    char auxiliar[5]; // Este es el buffer auxiliar.
    time_t rawtime;
    struct tm *timeinfo;
    time (&rawtime);
    timeinfo = localtime(&rawtime);
    strftime(auxiliar, 3, "%d", timeinfo);
    f_actual->dia = atoi(auxiliar);
    strftime(auxiliar, 3, "%m", timeinfo);
    f_actual->mes = atoi(auxiliar);
    strftime(auxiliar, 5, "%Y", timeinfo);
    f_actual->anio = atoi(auxiliar);
}

//Esta funcion es la principal.

int txt_a_bin_var(FILE *txt, FILE *bin, FILE *error, tFecha const *f_actual)
{
    int errores = 0;
    rewind(txt);
    rewind(bin);
    rewind(error);
    t_alumno alu; // Variable auxiliar t_alumno.
    fscanf(txt, "%ld|%40[^|]|%d/%d/%d|%c|%d/%d/%d|%40[^|]|%d|%d/%d/%d|%c|%d/%d/%d",
     &alu.dni, alu.ayn, &alu.fnac.dia, &alu.fnac.mes, &alu.fnac.anio, &alu.sexo,
     &alu.fing.dia, &alu.fing.mes, &alu.fing.anio, alu.carrera, &alu.mataprobadas, &alu.ultmat.dia,
     &alu.ultmat.mes, &alu.ultmat.anio, &alu.estado, &alu.fbaja.dia, &alu.fbaja.mes, &alu.fbaja.anio);
    //Si el primer alumno tiene todos sus campos correctos, procedo a normalizar el nombre y apellido.
    if(validar_alumno(&alu, f_actual) == 1)
    {
        normalizar_nombre_apellido(alu.ayn);
        fwrite(&alu, sizeof(t_alumno), 1, bin);
    }
    //Si el primer alumno tiene algun campo incorrecto, procedo a guardarlo en el archivo de errores.
    else
    {
        fprintf(error, "%ld|%s|%d/%d/%d|%c|%d/%d/%d|%s|%d|%d/%d/%d|%c|%d/%d/%d",
        alu.dni, alu.ayn, alu.fnac.dia, alu.fnac.mes, alu.fnac.anio, alu.sexo,
        alu.fing.dia, alu.fing.mes, alu.fing.anio, alu.carrera, alu.mataprobadas, alu.ultmat.dia,
        alu.ultmat.mes, alu.ultmat.anio, alu.estado, alu.fbaja.dia, alu.fbaja.mes, alu.fbaja.anio);
        fprintf(error, "\n"); // El salto de linea.
        errores++;
    }
    char auxiliar[1];
    while(fscanf(txt, "%c", auxiliar) != EOF) // Se prefiere esta condicion antes que el FEOF.
    {
    //    fseek(txt, -1, SEEK_CUR); //Retrocedo lo que lei.
        //Leo la linea siguiente, el proximo alumno.
        fscanf(txt, "%ld|%[^|]|%d/%d/%d|%c|%d/%d/%d|%[^|]|%d|%d/%d/%d|%c|%d/%d/%d",
        &alu.dni, alu.ayn, &alu.fnac.dia, &alu.fnac.mes, &alu.fnac.anio, &alu.sexo,
        &alu.fing.dia, &alu.fing.mes, &alu.fing.anio, alu.carrera, &alu.mataprobadas, &alu.ultmat.dia,
        &alu.ultmat.mes, &alu.ultmat.anio, &alu.estado, &alu.fbaja.dia, &alu.fbaja.mes, &alu.fbaja.anio);
        //Verifico que el alumno tenga sus campos correctos.
        if(validar_alumno(&alu, f_actual) == 1)
        {
            normalizar_nombre_apellido(alu.ayn);
            fwrite(&alu, sizeof(t_alumno), 1, bin);
        }
        //Si no tiene sus campos correctos.
        else
        {
            fprintf(error, "%ld|%s|%d/%d/%d|%c|%d/%d/%d|%s|%d|%d/%d/%d|%c|%d/%d/%d",
            alu.dni, alu.ayn, alu.fnac.dia, alu.fnac.mes, alu.fnac.anio, alu.sexo,
            alu.fing.dia, alu.fing.mes, alu.fing.anio, alu.carrera, alu.mataprobadas, alu.ultmat.dia,
            alu.ultmat.mes, alu.ultmat.anio, alu.estado, alu.fbaja.dia, alu.fbaja.mes, alu.fbaja.anio);
            fprintf(error, "\n"); // El salto de linea.
            errores++;
        }
    }
    return errores;
}

//Esta funcion recibe un t_alumno como parametro.
//Devuelve 1 si el alumno tiene correctos todos sus campos.

int validar_alumno(t_alumno const *alumno, tFecha const *f_actual)
{
    int campos_correctos = 0;
    campos_correctos+=validar_dni(alumno->dni);
    campos_correctos+=validar_fecha_nac(&(alumno->fnac), (f_actual));
    campos_correctos+=validar_sexo(alumno->sexo);
    campos_correctos+=validar_fecha_ing(&(alumno->fing), (f_actual), &(alumno->fnac));
    campos_correctos+=validar_carrera(alumno->carrera);
    campos_correctos+=validar_fecha_aprobacion_ult_mat(&(alumno->ultmat), (f_actual), &(alumno->fing));
    campos_correctos+=validar_estado(alumno->estado);
    campos_correctos+=validar_fecha_baja(&(alumno->fbaja));
    //printf("\nCampos correctos:%d", campos_correctos);
    if(campos_correctos == 8)
        return 1;
    return 0;
}

//Devuelve 1 si el DNI se encuentra en el rango especificado.
int validar_dni(long int const dni)
{
    if((dni >10000) && (dni<100000000))
        return 1;
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
    if(es_Fecha_Valida((tFecha*)fecha_nac))
        if(compare_fecha(&fecha_10anos, f_actual)<=0)
            return 1;
    return 0;
}

//Devuelve 1 si el Sexo es F o M.
int validar_sexo(char const c)
{
    if((c == 'M') || (c == 'F'))
        return 1;
    return 0;
}

//Devuelve 1 si la fecha de ingreso es menor a la fecha actual, pero mayor a la fecha de nacimiento.
int validar_fecha_ing(tFecha const *fecha, tFecha const *f_actual, tFecha const *f_nac)
{
    if(es_Fecha_Valida((tFecha*)fecha) && es_Fecha_Valida((tFecha*)f_actual) && es_Fecha_Valida((tFecha*)f_nac))
        if((compare_fecha(fecha, f_actual) <= 0) && compare_fecha(fecha, f_nac) > 0)
            return 1;
    return 0;
}

//Devuelve 1 si la carrera es la correcta.
int validar_carrera(const char *c)
{
    if((strcmp(c, "INF"))==0 || (strcmp(c, "ELE"))==0 || (strcmp(c, "IND"))==0 || (strcmp(c, "ECO"))==0 || (strcmp(c, "DER"))==0 || (strcmp(c, "ADM"))==0 || (strcmp(c, "MED"))==0 || (strcmp(c, "EDF"))==0 || strcmp(c, "FIL") == 0)
        return 1;
    return 0;
}

//Devuelve 1 si la cantidad de materias es mayor o igual a cero.
int validar_cant_materias(int const cant_materias)
{
    if(cant_materias >= 0)
        return 1;
    return 0;
}
//Devuelve 1 si la fecha de la aprobacion de la ultima materia es mayor a la fecha de ingreso y menor o igual a la fecha actual.
int validar_fecha_aprobacion_ult_mat(tFecha const *fecha, tFecha const *f_actual, tFecha const *f_ing)
{
    if(es_Fecha_Valida((tFecha*)fecha) && es_Fecha_Valida((tFecha*)f_actual) && es_Fecha_Valida((tFecha*)f_ing))
        if((compare_fecha(fecha, f_ing) > 0) && compare_fecha(fecha, f_actual) <= 0)
            return 1;
    return 0;
}

//Devuelve 1 si el estado es R
int validar_estado(char const c)
{
    if(c == 'R')
        return 1;
    return 0;
}

//Devuelve 1 si la fecha es igual a 31/12/9999.
int validar_fecha_baja(tFecha const *fecha)
{
    if((fecha->dia == 31) && (fecha->mes == 12) && (fecha->anio == 9999))
        return 1;
    return 0;
}

char* _strtoupper(char* cad)
{
    if(!cad || !*cad) return cad;
    char* inicio = cad;
    while(*cad)
    {
        *cad = toupper(*cad);
        cad++;
    }
    return inicio;
}

void intercambio(char *c, char *d)
{
    char aux = *c;
    *c = *d;
    *d = aux;
}

//Normalizo el nombre y el apellido segun los criterios del TP.
char* normalizar_nombre_apellido(char *nya)
{
    char* inicio = nya;
    char* escritura = nya;
    int primeraletra = 1;
    char* coma = NULL;
    while(!ES_LETRA(*nya)) //Sacar los espacios al inicio.
        nya++;
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
//Este método sirve para comprobar que realmente se guardaron bien los alumnos.
//Imprimo el campo nombre a ver si además de bien guardados, la normalización se realizó correctamente.
void leer_alumnos(FILE *_bin)
{
    rewind(_bin);
    t_alumno alu; // Variable auxiliar t_alumno.
    fread(&alu, sizeof(t_alumno), 1, _bin);
    while(!feof(_bin))
    {
        if(alu.estado != 'B')
            printf("\nNombre del alumno:%s", alu.ayn);
        fread(&alu, sizeof(t_alumno), 1, _bin);
    }
}

void leer_alumnos_baja(FILE *_bin)
{
    rewind(_bin);
    t_alumno alu; // Variable auxiliar t_alumno.
    fread(&alu, sizeof(t_alumno), 1, _bin);
    while(!feof(_bin))
    {
        if(alu.estado == 'B')
            printf("\nNombre del alumno:%s", alu.ayn);
        fread(&alu, sizeof(t_alumno), 1, _bin);
    }
}
