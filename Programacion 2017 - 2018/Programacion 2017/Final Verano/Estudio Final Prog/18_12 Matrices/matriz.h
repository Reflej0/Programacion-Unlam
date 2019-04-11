#ifndef MATRIZ_H_INCLUDED
#define MATRIZ_H_INCLUDED

int sumatoria_encima_principal(int n, int cuadrada[n][n]);

int sumatoria_diagonal_secundaria(int n, int cuadrada[n][n]);

int traza(int n, int cuadrada[n][n]);

int traza_secundaria(int n, int cuadrada[n][n]);

int es_diagonal(int n, int cuadrada[n][n]);

int es_identidad(int n, int cuadrada[n][n]);

int es_simetrica(int n, int cuadrada[n][n]);

void transponer_cuadrada(int n, int cuadrada[n][n]);

void transponer_matriz(int f, int c, int m[f][c], int t[c][f]);

void multiplicar_matriz(int f, int c, int m[f][c], int m2[c][f], int r[f][f]);

#endif // MATRIZ_H_INCLUDED
