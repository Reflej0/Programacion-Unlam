#include <stdio.h>
#include <stdlib.h>

char* _strchr(const char* s, int c)
{
    if(!s || !*s) return (char*)s;
    while(*s)
    {
        if(*s == c)
            return (char*)s;
        s++;
    }
    return NULL;
}

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

void _swap(int* a, int* b)
{
    *a += *b;
    *b = *a - *b;
    *a -= *b;
}

void transponer_matriz(int n, int m[n][n])
{
    int i, j;
    for(i=0; i<=n-2; i++)
        for(j=i+1; j<=n-1; j++)
            _swap(&m[j][i], &m[i][j]);

}

int main()
{
    int m3[3][3] = {{1, 2, 3},{4, 5, 6},{7, 8, 9}};
    mostrar_matriz_cuadrada(3, m3);
    transponer_matriz(3, m3);
    printf("\n");
    mostrar_matriz_cuadrada(3, m3);
    return 0;
}

/*int main()
{
    char lote1[50] = "Murcielago";
    char lote2[50] = "";
    char* lote3 = NULL;
    printf("%s", _strchr(lote1, 'o'));
    return 0;
}*/
