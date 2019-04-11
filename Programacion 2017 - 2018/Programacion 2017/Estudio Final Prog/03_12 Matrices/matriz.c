#include <stdio.h>
#include <stdlib.h>
#include "matriz.h"

int sumatoria_encima_principal(int n, int cuadrada[n][n])
{
    int sumatoria = 0;
    int i, j;
    for(i=0; i < n; i++)
    {
        for(j=0; j < n; j++)
        {
            if(i>j)
            {
                sumatoria+= cuadrada[i][j];
            }
        }
    }
    return sumatoria;
}

int sumatoria_diagonal_secundaria(int n, int cuadrada[n][n])
{
    int sumatoria = 0;
    int i, j;
    for(i=0; i < n; i++)
    {
        for(j=0; j < n; j++)
        {
            if((i+j+1) < n)
            {
                sumatoria+= cuadrada[i][j];
            }
        }
    }
    return sumatoria;
}

int traza(int n, int cuadrada[n][n])
{
    int traza = 0;
    int i;
    for(i = 0; i < n; i++)
    {
        traza+=cuadrada[i][i];
    }
    return traza;
}

int traza_secundaria(int n, int cuadrada[n][n])
{
    int traza = 0;
    int i;
    for(i = 1; i <= n; i++)
    {
        traza+=cuadrada[n-i][n-i];
    }
    return traza;
}

int es_diagonal(int n, int cuadrada[n][n])
{
    int i, j;
    for(i=0; i<n; i++)
    {
        for(j=0; j<n;j++)
        {
            if(i != j && cuadrada[i][j] != 0)
            {
                return 0;
            }
        }
    }
    return 1;
}

int es_identidad(int n, int cuadrada[n][n])
{
    int i, j;
    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {
            if(i != j && cuadrada[i][j] != 0)
            {
                return 0;
            }
            if(i == j && cuadrada[i][j] != 1)
            {
                return 0;
            }
        }
    }
    return 1;
}

int es_simetrica(int n, int cuadrada[n][n])
{
    int i, j;
    for(i=0; i<n;i++)
    {
        for(j=0; j<n; j++)
        {
            if(i!=j && cuadrada[i][j] != cuadrada[j][i])
            {
                return 0;
            }
        }
    }
    return 1;
}
///MODIFICA SIN RETURN, LA MATRIZ YA SE PASA POR REFERENCIA.
void transponer_cuadrada(int n, int cuadrada[n][n])
{
    int i,j;
    int aux;
    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {
            if(i<j)
            {
                aux = cuadrada[i][j];
                cuadrada[i][j] = cuadrada[j][i];
                cuadrada[j][i] = aux;
            }

        }
    }
}

void transponer_matriz(int f, int c, int m[f][c], int t[c][f])
{
    int i, j;
    for(i=0; i<f;i++)
    {
        for(j=0;j<c;j++)
        {
            t[j][i] = m[i][j];
        }
    }
}

void multiplicar_matriz(int f, int c, int m[f][c], int m2[c][f], int r[f][f])
{
    int i, j, k;
    for(i=0; i<f; i++)
    {
        for(j=0; j<f;j++)
        {
            r[i][j] = 0;
            for(k=0; k<c; k++)
            {
                r[i][j]+=m[i][k]*m2[k][j];
            }
        }
    }
}
