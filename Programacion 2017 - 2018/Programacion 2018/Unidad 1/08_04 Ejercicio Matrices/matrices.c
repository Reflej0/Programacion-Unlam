#include <stdio.h>
#include <stdlib.h>
#include "matrices.h"

void imprimir_matriz(int f, int c, float m[c][f])
{
    int i, j;
    for(i=0; i<c; i++)
    {
        for(j=0; j<f; j++)
        {
            printf("%.0f ", m[i][j]);
        }
        printf("\n");
    }
}

float sumatoria_por_encima_principal(int orden, float m[orden][orden])
{
    int i, j;
    float sumatoria = 0;
    for(i=0; i<orden; i++)
    {
        for(j=0; j<orden; j++)
        {
            if(i>j)
            {
                sumatoria+= m[i][j];
            }
        }
    }
    return sumatoria;
}

float sumatoria_por_debajo_principal(int orden, float m[orden][orden])
{
    int i, j;
    float sumatoria = 0;
    for(i=0; i<orden; i++)
    {
        for(j=0; j<orden; j++)
        {
            if(j>i)
            {
                sumatoria+= m[i][j];
            }
        }
    }
    return sumatoria;
}

float sumatoria_por_encima_secundaria(int orden, float m[orden][orden])
{
    int i, j;
    float sumatoria = 0;
    for(i=0; i<orden; i++)
    {
        for(j=0; j<orden; j++)
        {
            if(j+i<(orden-1))
            {
                sumatoria+= m[i][j];
            }
        }
    }
    return sumatoria;
}

float sumatoria_por_debajo_secundaria(int orden, float m[orden][orden])
{
    int i, j;
    float sumatoria = 0;
    for(i=0; i<orden; i++)
    {
        for(j=0; j<orden; j++)
        {
            if(j+i>(orden-1))
            {
                sumatoria+= m[i][j];
            }
        }
    }
    return sumatoria;
}

float traza_principal(int orden, float m[orden][orden])
{
    int i;
    float traza = 0;
    for(i=0; i<orden; i++)
    {
        traza+= m[i][i];
    }
    return traza;
}

float traza_secundaria(int orden, float m[orden][orden])
{
    int i, j;
    float traza = 0;
    for(i=0; i<orden; i++)
    {
        for(j=0; j<orden; j++)
        {
            if(i+j == orden-1)
            {
                traza+= m[i][j];
            }
        }
    }
    return traza;
}

int esDiagonal(int orden, float m[orden][orden])
{
    int i, j;
    for(i=0; i<orden; i++)
    {
        for(j=0; j<orden;j++)
        {
            if(i!=j && m[i][j]!=0)
            {
                return 0;
            }
        }
    }
    return 1;
}

int esIdentidad(int orden, float m[orden][orden])
{
    int i, j;
    for(i=0; i<orden; i++)
    {
        for(j=0; j<orden;j++)
        {
            if(i!=j && m[i][j]!=0)
            {
                return 0;
            }
            if(i == j && m[i][j]!=1)
            {
                return 0;
            }
        }
    }
    return 1;
}

int esSimetrica(int orden, float m[orden][orden])
{
    int i, j;
    for(i=0; i<orden; i++)
    {
        for(j=0; j<orden;j++)
        {
            if(i!=j && m[i][j] != m[j][i])
            {
                return 0;
            }
        }
    }
    return 1;
}

void trasponer_cuadrada(int orden, float m[orden][orden])
{
    int i, j;
    int aux;
    for(i=0; i<orden; i++)
    {
        for(j=0; (j<orden && i > j);j++)
        {
                aux = m[i][j];
                m[i][j] = m[j][i];
                m[j][i] = aux;

        }
    }
}

void trasponer_matriz(int c, int f, float m[c][f], float r[f][c])
{
    int i, j;
    for(i=0; i<c; i++)
    {
        for(j=0; j<f;j++)
        {
            r[j][i] = m[i][j];
        }
    }
}

void multiplicacion_matriz(int c, int f, float m[c][f], float m1[f][c], float r[c][c])
{
    int i, j, k;
    for(i=0; i<c; i++)
    {
        for(j=0; j<c;j++)
        {
            r[i][j] = 0;
            for(k=0; k<f; k++)
            {
                r[i][j] += m[i][k]*m1[k][j];
            }
        }
    }
}
