#include <stdio.h>
#include <stdlib.h>
#include "matrices.h"

void mostrar_matriz_cuadrada(int n, int m[n][n])
{
    int i, j;
    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
            printf("%d ", m[i][j]);
        printf("\n");
    }

}

int sumatoria_encima_excluida_principal(int n, int m[n][n])
{
    int i, j, sumatoria=0;
    for(i=n-1; i>=1; i--)
        for(j=0; j<=n-2; j++)
                if(j!=i)
                sumatoria+=m[j][i];
    return sumatoria;
}

int sumatoria_encima_incluida_principal(int n, int m[n][n])
{
    int i=n-1, j=n-1, sumatoria=0;
    for(; i>=0; i--)
        for(j=i; j>=0; j--)
            sumatoria+=m[j][i];
    return sumatoria;
}

int sumatoria_debajo_excluida_principal(int n, int m[n][n])
{
    int i, j, sumatoria=0;
    for(i=n-1; i>=1; i--)
        for(j=0; j<i; j++)
            sumatoria+=m[i][j];
    return sumatoria;
}

int sumatoria_debajo_incluida_principal(int n, int m[n][n])
{
    int i=n-1, j=n-1, sumatoria=0;
    for(; i>=0; i--)
        for(j=n-1; j>=i; j--)
            sumatoria+=m[j][i];
    return sumatoria;
}

int sumatoria_encima_excluida_secundaria(int n, int m[n][n])
{
    int i, j, sumatoria=0;
    for(i=0; i<=n-2; i++)
        for(j=0; j<=n-2; j++)
            if(i+j!=n-1)
                sumatoria+=m[i][j];
    return sumatoria;
}

int sumatoria_encima_incluida_secundaria(int n, int m[n][n])
{
    int i=0, j, sumatoria=0;
    for(; i<=n-1; i++)
        for(j=n-1-i; j>=0; j--)
            sumatoria+=m[j][i];
    return sumatoria;
}

int sumatoria_debajo_excluida_secundaria(int n, int m[n][n])
{
    int i, j, sumatoria=0;
    for(i=n-1; i>=1; i--)
        for(j=n-1; j>=n-i; j--)
            sumatoria+=m[i][j];
    return sumatoria;

}

int sumatoria_debajo_incluida_secundaria(int n, int m[n][n])
{
    int i, j, sumatoria=0;
    for(i=n-1; i>=0; i--)
        for(j=n-1; j>=n-1-i; j--)
            sumatoria+=m[i][j];
    return sumatoria;
}

int traza_principal_matriz(int n, int m[n][n])
{
    int i, traza = 0;
    for(i=0; i<n; i++)
        traza+=m[i][i];
    return traza;
}

int traza_secundaria_matriz(int n, int m[n][n])
{
    int i, traza = 0;
    for(i=0; i<n; i++)
            traza+=m[i][n-i-1];
    return traza;
}

int es_diagonal(int n, int m[n][n])
{
    int i, j;
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            if((j!=i) && m[i][j]!=0)
                return 0; //FALSO.
    return 1;
}

int es_identidad(int n, int m[n][n])
{
    int i, j;
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            if((j!=i && m[i][j]!=0) || (j==i && m[i][j]!=1))
                return 0; //FALSO.
    return 1;
}

int es_simetrica_respecto_principal(int n, int m[n][n])
{
    int i, j;
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            if(m[i][j]!=m[j][i])
                return 0; //FALSO.
    return 1;
}

int es_simetrica_respecto_secundaria(int n, int m[n][n])
{
    int i, j;
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            if(m[i][j]!=m[n-j-1][n-i-1])
                return 0; //FALSO.
    return 1;
}

void swap_int(int* a, int* b)
{
    *a+=*b;
    *b=*a-*b;
    *a-=*b;
}

void transponer_in_situ_cuadrada(int n, int m[n][n])
{
    int i, j;
    for(i=0; i<n; i++)
        for(j=0; j<n-1; j++)
            if(i>j)
                swap_int(&m[i][j], &m[j][i]);
}

void transponer_matriz(int f, int c, int m[f][c], int mt[c][f])
{
    int i, j;
    for(i=0; i<f; i++)
        for(j=0; j<c; j++)
            mt[j][i] = m[i][j];
}

void multiplicar_matriz(int f1, int c1, int f2, int c2, int m[f1][c1], int m2[f2][c2], int mr[c1][c2])
{
    int i, j, k;
    for(i=0; i<c2; i++)
    {
        for(j=0; j<f1; j++)
        {
            mr[i][j] = 0;
            for(k=0; k<c1; k++)
                mr[i][j] += m[i][k] * m2[k][j];
        }
    }
}
