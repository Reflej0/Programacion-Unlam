#ifndef UTILITARIAS_H_INCLUDED
#define UTILITARIAS_H_INCLUDED
#include<stdio.h>
#include<arbol.h>

typedef struct{
    int dni;
    char apyn[40];
    int cant_materias;
    float promedio;
    char estado; ///'A' Activo - 'B' Baja
}t_alumno;

void mostrarAlumno(t_info *i,FILE *pf);
void agregarMateria(t_info*i,FILE *pf);
void cargarArbolBalanceado(t_arbol *a,int incio,int fin,FILE *pf);


int alta_res (t_alumno * alu, FILE * arch, t_arbol* pa);
int alta (t_alumno * alu, FILE * arch, t_arbol* pa);

int baja_res (t_alumno * alu, FILE * arch, t_arbol* pa);
int baja (t_alumno * alu, FILE * arch, t_arbol* pa);

int baja_ultimo_res (FILE * arch, t_arbol* pa);
int baja_ultimo (FILE * arch, t_arbol* pa);

int agregar_materia_res(FILE * arch, t_arbol * pindice);
int agregar_materia(FILE * arch, t_arbol * pindice);

void ingresar_alumno_res(t_alumno* alu);
void ingresar_alumno(t_alumno* alu);
void ingresar_dni_alumno_res(t_alumno* alu);
void ingresar_dni_alumno(t_alumno* alu);
void ingresar_nueva_materia_res(t_alumno* alu);
void ingresar_nueva_materia(t_alumno* alu);
void imprimir_alumno_res(const t_alumno* alu);
void imprimir_alumno(const t_alumno* alu);
void mostrar_dni_res(const t_reg_ind* r);
void mostrar_dni(const t_reg_ind* r);
void imprimir_archivo_res(FILE * arch);
void imprimir_archivo(FILE * arch);

void imprimir_archivo_ordenado_res(FILE * arch, t_arbol* pa);
void imprimir_archivo_ordenado(FILE * arch, t_arbol* pa);
#endif // UTILITARIAS_H_INCLUDED
