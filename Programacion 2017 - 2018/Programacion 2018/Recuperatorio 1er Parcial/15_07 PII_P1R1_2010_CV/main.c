#include <stdio.h>
#include <stdlib.h>

char* ocurrencia_rec(const char* cad, char c, char* ocurrencia)
{
    if(!cad || !*cad) return ocurrencia;
    if(*cad == c)
        ocurrencia = (char*)cad;
    ocurrencia_rec(cad+1, c, ocurrencia);
}

char* ocurrencia(const char* cad, char c)
{
    if(!cad || !*cad) return (char*)cad;
    char* ocurrencia = NULL;
    return ocurrencia_rec(cad, c, ocurrencia);
}

void multiplicar_matrices(int f1, int c1, int f2, int c2, int m1[f1][c1], int m2[f2][c2], int m[f1][c2])
{
    int i, j, k;
    for(i=0; i<f1; i++)
    {
        for(j=0; j<c2; j++)
        {
            m[i][j] = 0;
            for(k=0;k<c1; k++)
                m[i][j] += m1[i][k]*m2[k][j];
        }
    }
}

void mostrar_matriz(int f, int c, int m[f][c])
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
    int m1[2][3] = {{1, 2, 3},{4, 5, 6}};
    int m2[3][4] = {{1, 2, 3, 4},{4, 5, 6, 7}, {7, 8, 9, 0}};
    int m[2][4];
    multiplicar_matrices(2, 3, 3, 4, m1, m2, m);
    mostrar_matriz(2, 4, m);
    char lote[50] = "Camello con joroba curvada";
    printf("Ocurrencia: %s", ocurrencia(lote, 'c'));
    return 0;
}
