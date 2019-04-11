#include <stdio.h>
#include <stdlib.h>

int es_identidad(int n, int m[n][n])
{
    int i, j;
    for(i=0; i<n; i++)
        for(j=0;j<n;j++)
            if((i==j && m[i][j]!=1) || (i!=j && m[i][j]!=0))
            return 0;
    return 1;
}

int main()
{
    int m[5][5] = {{1, 0, 0, 0, 0},{0, 1, 0, 0, 0},{0, 0, 1, 0, 0},{0, 0, 0, 1, 0},{0, 0, 0, 0, 1}};
    printf("Es identidad: %d", es_identidad(5, m));
    return 0;
}
