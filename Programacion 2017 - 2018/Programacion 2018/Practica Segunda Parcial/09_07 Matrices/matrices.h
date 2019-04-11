#ifndef MATRICES_H_INCLUDED
#define MATRICES_H_INCLUDED

void mostrar_matriz_cuadrada(int n, int m[n][n]);

int sumatoria_encima_excluida_principal(int n, int m[n][n]);

int sumatoria_encima_incluida_principal(int n, int m[n][n]);

int sumatoria_debajo_excluida_principal(int n, int m[n][n]);

int sumatoria_debajo_incluida_principal(int n, int m[n][n]);

int sumatoria_encima_excluida_secundaria(int n, int m[n][n]);

int sumatoria_encima_incluida_secundaria(int n, int m[n][n]);

int sumatoria_debajo_excluida_secundaria(int n, int m[n][n]);

int sumatoria_debajo_incluida_secundaria(int n, int m[n][n]);

int traza_principal_matriz(int n, int m[n][n]);

int traza_secundaria_matriz(int n, int m[n][n]);

int es_diagonal(int n, int m[n][n]);

int es_identidad(int n, int m[n][n]);

int es_simetrica_respecto_principal(int n, int m[n][n]);

int es_simetrica_respecto_secundaria(int n, int m[n][n]);

void swap_int(int* a, int* b);

void transponer_in_situ_cuadrada(int n, int m[n][n]);

void transponer_matriz(int f, int c, int m[f][c], int mt[c][f]);

void multiplicar_matriz(int f1, int c1, int f2, int c2, int m[f1][c1], int m2[f2][c2], int mr[c1][c2]);

#endif // MATRICES_H_INCLUDED
