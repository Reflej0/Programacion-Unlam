#ifndef TP_H_INCLUDED
#define TP_H_INCLUDED

#include "header.h"
#include "indice.h"
#include "fecha.h"

///FUNCIONES DE ALTA_BAJA TP4.

void ingresar_directorio(char* directoriodat, char* directorioidx);

int comprobar_existencia(FILE* arch);

int crear_alumno(t_alumno* alu, T_indice* indice, tFecha* fact);

void eliminar_alumno(FILE* arch, const long dni, tFecha* fact);

#endif // TP_H_INCLUDED
