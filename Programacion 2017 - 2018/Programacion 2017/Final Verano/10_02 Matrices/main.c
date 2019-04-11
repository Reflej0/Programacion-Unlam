#include <stdio.h>
#include <stdlib.h>
#include "matriz.h"

int main()
{
    int cuadrada3[3][3] = {{1, 4, 7}, {2, 5, 8}, {3, 6, 9}};
    int identidad3[3][3] = {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}};
    int simetrica3[3][3] = {{1, 2, 3},{2, 4, 5},{3, 5, 8}};
    int matriz[3][2] = {{1, 4}, {2, 5}, {3, 6}};
    int matriz_transpuesta[2][3];
    int matriz_producto[3][3] = {{0, 0, 0},{0, 0, 0},{0, 0, 0}};
    /*int sumatoria = sumatoria_encima_principal(3, cuadrada3);
    printf("La sumatoria es: %d", sumatoria);*/
    /*int sumatoria = sumatoria_diagonal_secundaria(3, cuadrada3);
    printf("La sumatoria es: %d", sumatoria);*/
    /*int trazar = traza(3, cuadrada3);
    printf("La traza es: %d", trazar);*/
    /*int traza = traza_secundaria(3, cuadrada3);
    printf("La traza es: %d", traza);*/
    /*int diagonal = es_diagonal(3, cuadrada3);
    printf("Es diagonal:%d", diagonal);*/
    /*int identidad = es_identidad(3, identidad3);
    printf("Es identidad:%d", identidad);*/
    /*int simetrica = es_simetrica(3, simetrica3);
    printf("Es simetrica:%d", simetrica);*/
    //transponer_cuadrada(3, cuadrada3);
    transponer_matriz(3, 2, matriz, matriz_transpuesta);
    /*int i, j;
     for(i=0;i<3;i++){
        for(j=0;j<2;j++){
            printf("%d\t", matriz[i][j]);
        }
        puts("\n");
    }
    for(i=0;i<2;i++){
        for(j=0;j<3;j++){
            printf("%d\t", matriz_transpuesta[i][j]);
        }
        puts("\n");
    }*/
    multiplicar_matriz(3, 2, matriz, matriz_transpuesta, matriz_producto);
    int i, j;
    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            printf("%d\t", matriz_producto[i][j]);
        }
        puts("\n");
    }

}
