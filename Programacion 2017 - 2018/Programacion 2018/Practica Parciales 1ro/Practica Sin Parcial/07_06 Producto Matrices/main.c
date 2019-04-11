#include <stdio.h>
#include <stdlib.h>

void multiplicar_matrices(const int f1, const int c1, const int c2, int m[f1][c1], int m2[c1][c2], int r[f1][c2])
{
    int i, j, k;
    for(i=0; i<c2; i++)
    {
        for(j=0; j<f1; j++)
        {
            r[i][j] = 0;
            for(k=0; k<c1; k++)
            {
                r[i][j] += m[i][k] * m2[k][j];
            }
        }
    }
}

void mostrar_matriz(const int f, const int c, int m[f][c])
{
    int i, j;
    for(i=0;i<f;i++)
    {
        for(j=0;j<c;j++)
        {
            printf("%d ", m[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int m[3][2] = {{1, 4},{2, 5},{3, 6}};
    int m2[2][3] = {{1, 2, 3},{4, 5, 6}};
    int r[3][3] = {};
    multiplicar_matrices(3, 2, 3, m, m2, r);
    mostrar_matriz(3, 3, r);
    return 1;
}
