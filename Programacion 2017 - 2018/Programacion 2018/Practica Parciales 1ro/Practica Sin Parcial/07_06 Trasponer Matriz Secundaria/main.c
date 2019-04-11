#include <stdio.h>
#include <stdlib.h>

void intercambio_int(int *a, int *b)
{
    *a+=*b;
    *b = *a-*b;
    *a-=*b;
}

void transponer_matriz_secundaria(const int orden, int m[orden][orden])
{
    int i, j;
    for(j=orden-1; j>=0; j--)
    {
        for(i=orden-j; i<orden;i++)
        {
            intercambio_int(&m[i][j], &m[orden-j-1][orden-i-1]);
        }
    }
}

void mostrar_matriz_cuadrada(const int orden, int m[orden][orden])
{
    int i, j;
    for(i=0; i<orden;i++)
    {
        for(j=0;j<orden;j++)
        {
            printf("%d ", m[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int matriz[3][3] = {{1, 4, 7},{2, 5, 8},{3, 6, 9}};
    int orden = 3;
    mostrar_matriz_cuadrada(orden, matriz);
    transponer_matriz_secundaria(orden, matriz);
    printf("TRANSPUESTA:\n");
    mostrar_matriz_cuadrada(orden, matriz);
    return 1;
}
