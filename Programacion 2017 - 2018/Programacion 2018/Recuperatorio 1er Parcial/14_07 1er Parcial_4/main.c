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

int es_simetrica(int n, int m[n][n])
{
    int i, j;
    for(i=1; i<n; i++)
    {
        for(j=0;j<=i-1; j++)
            if(m[i][j] != m[j][i])
                return 0;
    }
    return 1;
}

char* _strstr(const char* donde, const char* que)
{
    if(!donde || !*donde || !que || !*que) return (char*)donde;
    char* inicio = (char*)que;
    while(*donde)
    {
        if(*donde == *que)
        {
            que++;
            if(*que == '\0')
                return (char*)donde;
        }
        else
            que = inicio;
        donde++;
    }
    return NULL;
}

int main()
{
    int m[5][5] = {{1, 34, 99, 11, 88},{34, 7, 77, 66, 0},{99, 77, 3, 8, 55},{11, 66, 8, 9, 4},{88, 0, 55, 4, 5}};
    //mostrar_matriz_cuadrada(5, m);
    //printf("Es simetrica: %d", es_simetrica(5, m));
    char cad[50]="CASA BLANCA, BLANCA CASA";
    char que1[10]="BANCA";
    char que2[10]="ANCA";
    char que3[10]="OVAL";
    char que4[10]="A BLA";
    char que5[10]="";
    printf("%s", _strstr(cad, que4));
    return 0;
}
