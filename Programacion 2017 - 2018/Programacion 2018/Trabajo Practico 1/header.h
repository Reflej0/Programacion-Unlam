#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED

#include "fecha.h"

///ESTRUCTURA DE ALUMNO

typedef struct
{
    long int dni;
    char ayn[40];
    tFecha fnac;
    char sexo;
    tFecha fing;
    char carrera[4];
    int mataprobadas;
    tFecha ultmat;
    char estado;
    tFecha fbaja;
} t_alumno;

///OBTENER LA FECHA ACTUAL.

void fecha_actual(tFecha *f_actual);

///VALIDACIONES.

int validar_alumno(t_alumno const *alumno, tFecha const *f_actual);

int validar_dni(long const dni);

int validar_fecha_nac(tFecha const *fecha, tFecha const *f_actual);

int validar_sexo(char const c);

int validar_fecha_ing(tFecha const *fecha, tFecha const *f_actual, tFecha const *f_nac);

int validar_carrera(char const *c);

int validar_cant_materias(int const cant_materias);

int validar_fecha_aprobacion_ult_mat(tFecha const *fecha, tFecha const *f_actual, tFecha const *f_ing);

int validar_estado(char const c);

int validar_fecha_baja(tFecha const *fecha);

///NORMALIZACION.

char* normalizar_nombre_apellido(char *nya);

///TRATAMIENTO DE ARCHIVOS.

void introducir_directorio(char *directoriotxt, char *directoriobin, char *directorioerror);

int txt_a_bin_var(FILE *txt, FILE *bin, FILE *error, tFecha const *f_actual);

void leer_alumnos(FILE *_bin);

void leer_alumnos_baja(FILE *_bin);

#endif // HEADER_H_INCLUDED
