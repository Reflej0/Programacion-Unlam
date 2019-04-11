#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED
#include "fecha.h"
#define CAMPOS 8

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

tFecha fecha_actual();

void ingresar_alumno(t_alumno* alu);

int validar_alumno(t_alumno const *alumno, tFecha const *f_actual, int* vec_errores);

int validar_dni(long const dni);

int validar_fecha_nac(tFecha const *fecha, tFecha const *f_actual);

int validar_sexo(char const c);

int validar_fecha_ing(tFecha const *fecha, tFecha const *f_actual, tFecha const *f_nac);

int validar_carrera(char const *c);

int validar_cant_materias(int const cant_materias);

int validar_fecha_aprobacion_ult_mat(tFecha const *fecha, tFecha const *f_actual, tFecha const *f_ing);

int validar_estado(char const c);

int validar_fecha_baja(tFecha const *fecha);

char* normalizar_nya(char *nya);

void intercambio(char* c, char* d);

//---------------------------PARTE 2

void procesar_archivo_alumnos_txt(char* dir, tFecha* fact);

void escribir_alumno_correcto(FILE* arch, t_alumno* alu);

void escribir_alumno_incorrecto(FILE* arch, t_alumno* alu, int* vector_errores, size_t tam);

#endif // HEADER_H_INCLUDED
