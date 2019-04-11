#ifndef EJERCICIO12_H_INCLUDED
#define EJERCICIO12_H_INCLUDED

void inicializar_matriz(char matriz[][50]);

void inicializar_matriz_float(char matriz[][7]);

int ingresar_alumnos(char matriz[][50]);

void visualizar_alumnos(char matriz[][50], const int cantidad);

void ingresar_notas(float notas[][7], const int cantidad);

void promediar_notas(float notas[][7], const int cantidad);

void escribir_archivo(char alumnos[][50], float notas[][7], const int cantidad);

#endif // EJERCICIO12_H_INCLUDED
