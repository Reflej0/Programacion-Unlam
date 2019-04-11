#include <stdio.h>
#include <stdlib.h>

void mostrar_matriz_cuadrada(int n, int m[n][n])
{
    int i, j;
    for(i=0; i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("%d ", m[i][j]);
        }
        printf("\n");
    }
}

int sumatoria_triangulo_superior_incluido_diagonal(int n, int m[n][n])
{
    int i, j, sumatoria =0;
    for(i=0; i<n-1;i++)
        for(j=i; j<n-i; j++)
            sumatoria+=m[i][j];
    return sumatoria;
}

int sumatoria_triangulo_inferior_incluido_diagonal(int n, int m[n][n])
{
    int i, j, sumatoria =0, x=0;
    for(i=n-1; i>=n/2;i--)
    {
       for(j=i; j>=x; j--)
            sumatoria+=m[i][j];
        x++;
    }
    return sumatoria;
}

int sumatoria_filapar_columnaimpar(int n, int m[n][n])
{
    int i, j, sumatoria=0;
    for(i=0; i<=n-1; i+=2)
        for(j=1; j<=n-1; j+=2)
            sumatoria+=m[i][j];
    return 1;
}

void _swap(int* a, int* b)
{
    *a += (*b);
    *b = (*a) - (*b);
    *a -= (*b);
}

void transponer_matriz_respecto_diagonal_secundaria(int n, int m[n][n])
{
    int i, j;
    for(i=0; i<n; i++)
        for(j=0; j<n-1-i;j++)
            _swap(&m[i][j], &m[n-j-1][n-i-1]);
}

void recorrer_matriz_espiral(int f, int c, int matriz[f][c]) {
    int fmin=0;
    int cmin=0;
    int i=0;
    int j=-1;
    while (fmin<f && cmin<c) {
        for (j++;j<c;j++)
            printf ("%d ",matriz[i][j]);
        j--;
        for (i++;i<f;i++)
            printf ("%d ",matriz[i][j]);
        i--;
        for (j--;j>=cmin;j--)
            printf ("%d ",matriz[i][j]);
        j++;
        fmin = ++cmin;
        for (i--;i>=fmin;i--)
            printf ("%d ",matriz[i][j]);
        i++;
        c--;
        f--;
    }
}

int main()
{
    int m3[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int m4[4][4] = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 1, 2, 3}, {4, 5, 6, 7}};
    int m4_3[4][3] = {{11, 22, 33}, {55, 66, 77}, {9, 1, 2}, {4, 5, 6}};
    int m5[5][5] = {{1, 2, 3, 4, 5}, {6, 7, 8, 9, 1}, {2, 3, 4, 5, 6}, {7, 8, 9, 1, 2}, {3, 4, 5, 6, 7}};
    int m6[6][6] = {{1, 2, 3, 4, 5, 6}, {6, 7, 8, 9, 1, 2}, {2, 3, 4, 5, 6, 3}, {7, 8, 9, 1, 2, 4}, {3, 4, 5, 6, 7, 8}, {3, 4, 5, 6, 7, 9}};
    int m7[7][7] = {{1, 2, 3, 4, 5, 6, 7}, {6, 7, 8, 9, 1, 2, 3}, {2, 3, 4, 5, 6, 3, 4}, {7, 8, 9, 1, 2, 4, 5}, {3, 4, 5, 6, 7, 8, 9}, {3, 4, 5, 6, 7, 9, 1}, {1, 2, 3, 4, 5, 6, 7}};
    //printf("Resultado: %d\n",sumatoria_triangulo_superior_incluido_diagonal(4, m4));
    //sumatoria_triangulo_inferior_incluido_diagonal(7, m7);
    //sumatoria_filapar_columnaimpar(6, m6);
    /*mostrar_matriz_cuadrada(5, m5);
    transponer_matriz_respecto_diagonal_secundaria(5, m5);
    printf("\n");
    mostrar_matriz_cuadrada(5, m5);*/
    recorrer_matriz_espiral(4, 3, m4_3);
    return 0;
}
