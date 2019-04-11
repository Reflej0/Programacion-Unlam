#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
#include "header.h"
#include "fecha.h"

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

//Esta funcion "devuelve" los directorios de cada archivo.

void introducir_directorio(char *directoriotxt, char *directoriobin, char *directorio_txt, char *directorio_indice)
{
    char directorio[100] = "";
    printf("Ingrese el directorio del archivo:");
    gets(directorio);
    strcpy(directoriotxt, directorio);
    strcpy(directoriobin, directorio);
    strcpy(directorio_txt, directorio);
    strcpy(directorio_indice, directorio);
    strcat(directoriotxt, "alumnos.txt");
    strcat(directoriobin, "alumnos.dat");
    strcat(directorio_txt, "alumnos_errores.txt");
    strcpy(directorio_indice, "alumnos.idx");
}

//Esta funcion es la principal.

int txt_a_bin_var(FILE *txt, FILE *bin, FILE *error, tFecha const *f_actual, T_indice *pi)
{
    int errores = 0;
    rewind(txt);
    rewind(bin);
    rewind(error);
    t_alumno alu; // Variable auxiliar t_alumno.
    ///VARIABLE PARA EL POSTERIOR GUARDADO DEL INDICE.
    t_reg_indice reg;
    unsigned nro_alu = 0;
    fscanf(txt, "%ld|%40[^|]|%d/%d/%d|%c|%d/%d/%d|%40[^|]|%d|%d/%d/%d|%c|%d/%d/%d",
     &alu.dni, alu.ayn, &alu.fnac.dia, &alu.fnac.mes, &alu.fnac.anio, &alu.sexo,
     &alu.fing.dia, &alu.fing.mes, &alu.fing.anio, alu.carrera, &alu.mataprobadas, &alu.ultmat.dia,
     &alu.ultmat.mes, &alu.ultmat.anio, &alu.estado, &alu.fbaja.dia, &alu.fbaja.mes, &alu.fbaja.anio);
    //Si el primer alumno tiene todos sus campos correctos, procedo a normalizar el nombre y apellido.
    if(validar_alumno(&alu, f_actual) == 1)
    {
        normalizar_nombre_apellido(alu.ayn);
        fwrite(&alu, sizeof(t_alumno), 1, bin);
        ///EL REGISTRO DEL INDICE TOMA SUS VALORES DE ACUERDO AL ALUMNO.
        reg.dni = alu.dni;
        reg.nro_reg = nro_alu;
        ///INSERTO EN EL INDICE.
        ind_insertar(pi,&reg);
        nro_alu++;
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
            ///EL REGISTRO DEL INDICE TOMA SUS VALORES DE ACUERDO AL ALUMNO.
            reg.dni = alu.dni;
            reg.nro_reg = nro_alu;
            ///INSERTO EN EL INDICE.
            ind_insertar(pi,&reg);
            nro_alu++;
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
    {
        return 1;
    }
    return 0;
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
    if((c == 'M') || (c == 'F'))
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

//Normalizo el nombre y el apellido segun los criterios del TP.
void normalizar_nombre_apellido(char *nya)
{
        char aux[40]; // Variable auxiliar.
        strcpy(aux, nya); // Se realiza una copia
        int i = 0; // Variable auxiliar para recorrer el char[]
        int primerapalabra = 0; // Variable auxiliar que me ayuda a identificar si me encuentro en la primera palabra.
        //Normalizo la primera letra a Mayuscula.
        if(nya[i] >='a' && nya[i]<='z')
        {
            nya[i]-=32;
        }
        i++; // Paso a estar en la primera letra después de la mayuscula.
        while(i < strlen(nya)+1) // Esto es porque como le agrego la , y desplazo todas las letras un espacio.
        {
            if(nya[i] >='A' && nya[i]<='Z') // Si las letras de la palabra estan en mayuscula se pasan a minuscula.
            {
                nya[i]+=32;
            }
            if(primerapalabra>0) // Si no estoy en la primera palabra, tengo que desplazar porque agregue la ,
            {
                nya[i] = aux[i-1];
                if(nya[i] >='A' && nya[i]<='Z') // Si las letras de la palabra estan en mayuscula se pasan a minuscula.
                {
                    nya[i]+=32;
                }
            }
            if(nya[i] == ' ' && primerapalabra == 0) // Si cambie de palabra, es decir si detecte un espacio.
            {

                nya[i] = ','; // Reemplazo el espacio por la coma.
                i++; // Salto al siguiente caracter.
                nya[i] = ' '; // Agrego un espacio, estoy pisando una letra, pero no la pierdo porque la tiene aux.
                i++; // Salto al siguiente caracter, osea donde esta la primera letra despues del espacio.
                nya[i] = aux[i-1]; // La variable aux tiene la primera letra.
                if(nya[i]>='a' && nya[i]<='z') // Pregunto si la letra que le sigue al espacio es minuscula.
                {
                    nya[i]-=32; // Si fuese minuscula se transforma en mayuscula.
                }
                primerapalabra++; // A partir de ahora ya no me encuentro en la primera palabra.
            }
            i++;
        }
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
        printf("\nNombre del alumno:%s", alu.ayn);
        fread(&alu, sizeof(t_alumno), 1, _bin);
    }
}
