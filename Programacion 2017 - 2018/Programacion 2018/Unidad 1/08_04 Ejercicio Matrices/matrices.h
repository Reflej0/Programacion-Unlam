#ifndef MATRICES_H_INCLUDED
#define MATRICES_H_INCLUDED

void imprimir_matriz(int f, int c, float m[c][f]);

float sumatoria_por_encima_principal(int orden, float m[orden][orden]);

float sumatoria_por_debajo_principal(int orden, float m[orden][orden]);

float sumatoria_por_encima_secundaria(int orden, float m[orden][orden]);

float sumatoria_por_debajo_secundaria(int orden, float m[orden][orden]);

float traza_principal(int orden, float m[orden][orden]);

float traza_secundaria(int orden, float m[orden][orden]);

int esDiagonal(int orden, float m[orden][orden]);

int esIdentidad(int orden, float m[orden][orden]);

int esSimetrica(int orden, float m[orden][orden]);

void trasponer_cuadrada(int orden, float m[orden][orden]);

void trasponer_matriz(int c, int f, float m[c][f], float r[f][c]);

void multiplicacion_matriz(int c, int f, float m[c][f], float m1[f][c], float r[c][c]);

#endif // MATRICES_H_INCLUDED
