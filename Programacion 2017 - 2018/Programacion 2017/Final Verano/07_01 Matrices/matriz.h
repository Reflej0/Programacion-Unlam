#ifndef MATRIZ_H_INCLUDED
#define MATRIZ_H_INCLUDED

int sumatoria_encima_principal(int n, int matriz[n][n]);

int sumatoria_diagonal_secundaria(int n, int matriz[n][n]);

int traza(int n, int matriz[n][n]);

int traza_secundaria(int n, int matriz[n][n]);

int es_diagonal(int n, int matriz[n][n]);

int es_identidad(int n, int matriz[n][n]);

int es_simetrica(int n, int matriz[n][n]);

void transponer_cuadrada(int n, int matriz[n][n]);

void transponer_matriz(int f, int c, int matriz[f][c], int matriz_transpuesta[c][f]);

void multiplicar_matriz(int f, int c, int matriz[f][c], int matriz_transpuesta[c][f], int matriz_producto[f][f]);

#endif // MATRIZ_H_INCLUDED
