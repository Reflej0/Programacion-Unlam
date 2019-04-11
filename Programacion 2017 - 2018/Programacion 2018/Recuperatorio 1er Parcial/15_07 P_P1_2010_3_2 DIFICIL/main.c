#include <stdio.h>
#include <stdlib.h>

int coinciden_sumatoria_triangulos(int n, int m[n][n])
{
    int i, j, suma1=0, suma2=0;
    for(i=0; i<n; i++)
        for(j=0; j<=i%(n-i); j++)
            suma1+=m[j][i];
    for(i=0; i<n; i++)
    {
        for(j=n-1; j>=; j--)
            printf("%d-%d\n", i, j);
    }
    return 1;
}

int main()
{
    int m5[5][5] = {{1, 2, 3, 4, 5},{6, 7, 8, 9, 0},{1, 2, 3, 4, 5},{6, 7, 8, 9, 0},{1, 2, 3, 4, 5}};
    int m3[3][3] = {{1, 2, 3},{4, 5, 6},{7, 8, 9}};
    coinciden_sumatoria_triangulos(5, m5);
    return 0;
}
