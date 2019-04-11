#include <stdio.h>
#include <stdlib.h>

int suma_triangulo_derecha(int n, int m[n][n])
{
    int i, j, suma = 0;
    for(i=n-1; i>(n-1)/2; i--)
        for(j=i-1; j>n-1-i; j--)
            suma+=m[j][i];
    return suma;
}

int suma_triangulo_izquierda(int n, int m[n][n])
{
    int i, j, suma = 0;
    for(i=0; i<(n-1)/2; i++)
        for(j=i+1; j<n-1-i; j++)
            suma+=m[j][i];
    return suma;
}

int suma_triangulo_superior(int n, int m[n][n])
{
    int i, j, suma = 0;
    for(i=0; i<(n-1)/2; i++)
        for(j=i+1; j<n-1-i; j++)
            suma+=m[i][j];
    return suma;
}

int suma_triangulo_inferior(int n, int m[n][n])
{
    int i, j, suma = 0;
    for(i=n-1; i>(n-1)/2; i--)
        for(j=i-1; j>n-1-i; j--)
            suma+=m[i][j];
    return suma;
}

int main()
{
    int m3[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int m4[4][4] = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 1, 2, 3}, {4, 5, 6, 7}};
    int m5[5][5] = {{1, 2, 3, 4, 5}, {6, 7, 8, 9, 1}, {2, 3, 4, 5, 6}, {7, 8, 9, 1, 2}, {3, 4, 5, 6, 7}};
    int m6[6][6] = {{1, 2, 3, 4, 5, 6}, {6, 7, 8, 9, 1, 2}, {2, 3, 4, 5, 6, 3}, {7, 8, 9, 1, 2, 4}, {3, 4, 5, 6, 7, 8}, {3, 4, 5, 6, 7, 9}};
    int m7[7][7] = {{1, 2, 3, 4, 5, 6, 7}, {6, 7, 8, 9, 1, 2, 3}, {2, 3, 4, 5, 6, 3, 4}, {7, 8, 9, 1, 2, 4, 5}, {3, 4, 5, 6, 7, 8, 9}, {3, 4, 5, 6, 7, 9, 1}, {1, 2, 3, 4, 5, 6, 7}};
    int suma_derecha = suma_triangulo_derecha(7, m7);
    int suma_izquierda = suma_triangulo_izquierda(7, m7);
    int suma_superior = suma_triangulo_superior(7, m7);
    int suma_inferior = suma_triangulo_inferior(7, m7);
    printf("%d - %d - %d - %d", suma_derecha, suma_izquierda, suma_superior, suma_inferior);
    return 0;
}
