#include <stdio.h>
#include <stdlib.h>
#define ABS(a) ((a<0) ? ((a)*-1) : a)

float raiz_cuadrada(float a, float cota)
{
    float base = 1;
    float sig;
    do
    {
        sig = 0.5*(base+(a/base));
        if(ABS(base-sig)<cota) break;
        base = sig;
    }
    while(1);
    return sig;
}

int es_simetrica(int n, int m[n][n])
{
    int i, j;
    for(i=1; i<n; i++)
        for(j=0; j<=i-1; j++)
            if(m[i][j]!=m[j][i])
                return 0;
            //printf("%d\n", m[i][j]);
    return 1;
}

int main()
{
    int m[4][4] = {{1, 2, 3, 4},{2, 7, 8, 9},{3, 8, 0, 6},{4, 9, 6, 5}};
    //float resultado = raiz_cuadrada(16, 0.1);
    //printf("Raiz cuadrada: %f", resultado);
    printf("Es simetrica: %d", es_simetrica(4, m));
    return 0;
}
