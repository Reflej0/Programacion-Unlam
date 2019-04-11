#include <stdio.h>
#include <stdlib.h>

unsigned eliminar_caracteres(char* cad, const char* car)
{
    if(!cad || !*cad || !car || !*car) return 0;
    char* escritura = cad;
    char* inicio_car = (char*)car;
    unsigned eliminados = 0;
    while(*cad)
    {
        while(*car && *car != *cad)
            car++;
        if(*car == '\0')
        {
            *escritura = *cad;
            escritura++;
        }
        else
            eliminados++;
        car = inicio_car;
        cad++;
    }
    return eliminados;
}

void swap_(int *a, int *b)
{
    int aux = *a;
    *a = *b;
    *b = aux;
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

void transponer_matriz_respecto_diagonal_secundaria(int n, int m[n][n])
{
    int i, j;
    for(i=0; i<=n-2; i++)
    {
        for(j=0; j<n-1-i; j++)
        {
            swap_(&m[j][i], &m[n-1-i][n-1-j]);
        }
    }
}

int main()
{
    int m[5][5] = {{1, 2, 3, 4, 5},{6, 7, 8, 9, 0},{1, 2, 3, 4, 5},{6, 7, 8, 9, 0},{1, 2, 3, 4, 5}};
    mostrar_matriz_cuadrada(5, m);
    transponer_matriz_respecto_diagonal_secundaria(5, m);
    printf("---------------------\n\n");
    mostrar_matriz_cuadrada(5, m);
    return 0;
}

/*int main()
{
    char cad1[50] = "Algo que se me ocurrió";
    char car1[50] = "aeiou";
    char car2[50] = "aeiouAEIOUáéíóú";
    char car3[50] = "EIOU";
    printf("%s\nEliminados: %d", cad1, eliminar_caracteres(cad1, car1));
    return 0;
}*/
