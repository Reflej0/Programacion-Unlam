#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
#include "pila.h"
#include "stdio.h"

void cargar_primer_operando_archivo_en_pila(T_pila* p, FILE* arch);

void cargar_segundo_operando_archivo_en_pila(T_pila* p, FILE* arch);

void sumar_pilas(T_pila* p1, T_pila* p2, T_pila* pr);

void mostrar_pila(T_pila* p);

#endif // FUNCIONES_H_INCLUDED
