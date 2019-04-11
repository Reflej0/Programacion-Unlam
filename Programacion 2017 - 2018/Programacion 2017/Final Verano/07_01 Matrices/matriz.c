#include <stdio.h>
#include <stdlib.h>
#include "matriz.h"

int sumatoria_encima_principal(int n, int matriz[n][n])
{
    int i, j;
    int sumatoria = 0;
    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {
            if(i>j)
            {
                sumatoria+= matriz[i][j];
            }
        }
    }
    return sumatoria;
}

int sumatoria_diagonal_secundaria(int n, int matriz[n][n])
{
    int i, j;
    int sumatoria = 0;
    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {
            if((i+j)<n-1)
            {
                sumatoria+= matriz[i][j];
            }
        }
    }
    return sumatoria;
}

int traza(int n, int matriz[n][n])
{
    int trazar = 0;
    int i;
    for(i=0; i<n; i++)
    {
        trazar+=matriz[i][i];
    }
    return trazar;
}

int traza_secundaria(int n, int matriz[n][n])
{
    int trazar = 0;
    int i, j;
    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {
            if((i+j)==n-1)
            {
                trazar+= matriz[i][j];
            }
        }
    }
    return trazar;
}

int es_diagonal(int n, int matriz[n][n])
{
    int i, j;
    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {
            if(i!=j)
            {
                if(matriz[i][j] != 0)
                {
                    return 0;
                }
            }
        }
    }
    return 1;
}

int es_identidad(int n, int matriz[n][n])
{
    int i, j;
    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {
            if(i!=j)
            {
                if(matriz[i][j] != 0)
                {
                    return 0;
                }
            }
            if(i==j)
            {
                if(matriz[i][j] != 1)
                {
                    return 0;
                }
            }
        }
    }
    return 1;
}

int es_simetrica(int n, int matriz[n][n])
{
    int i, j;
    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {
            if(matriz[i][j] != matriz[j][i])
            {
                return 0;
            }
        }
    }
    return 1;
}

void transponer_cuadrada(int n, int matriz[n][n])
{
    int i, j;
    int aux;
    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {
            if(i>j)
            {
                aux = matriz[i][j];
                matriz[i][j] = matriz[j][i];
                matriz[j][i] = aux;
            }
        }
    }
}

void transponer_matriz(int f, int c, int matriz[f][c], int matriz_transpuesta[c][f])
{
    int i, j;
    for(i=0; i<f; i++)
    {
        for(j=0; j<c; j++)
        {
            matriz_transpuesta[j][i] = matriz[i][j];
        }
    }
}

void multiplicar_matriz(int f, int c, int matriz[f][c], int matriz_transpuesta[c][f], int matriz_producto[f][f])
{
    int i, j, k;
    for(i=0;i<f; i++)
    {
        for(j=0; j<f; j++)
        {
            matriz_producto[i][j] = 0;
            for(k=0; k<c; k++)
            {
                matriz_producto[i][j] += matriz[i][k] * matriz_transpuesta[k][j];
            }
        }
    }
}
