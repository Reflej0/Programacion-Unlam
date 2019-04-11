#include <stdio.h>
#include <stdlib.h>
#include "matrices.h"
#define ORDEN 3

int main()
{
    float cuadrada3[3][3] = {{1, 4, 7}, {2, 5, 8}, {3, 6, 9}};
    float identidad3[3][3] = {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}};
    float simetrica3[3][3] = {{1, 2, 3},{2, 4, 5},{3, 5, 8}};
    float matriz[3][2] = {{1, 4}, {2, 5}, {3, 6}};
    float matriz_transpuesta[2][3];
    float matriz_producto[3][3];
    int opcion = 0;
    printf("1)Ejercicio 29\n2)Ejercicio 30\n3)Ejercicio 31\n4)Ejercicio 32\n5)Ejercicio 33\n6)Ejercicio 34\n7)Ejercicio 35\n8)Ejercicio 36\nOpcion:");
    scanf("%d", &opcion);
    switch(opcion)
    {
    case 1:
        system("CLS");
        printf("\nMATRIZ DE PRUEBA\n");
        imprimir_matriz(3, 3, cuadrada3);
        printf("\nLa sumatoria encima principal es:%.1f", sumatoria_por_encima_principal(ORDEN, cuadrada3));
        printf("\nLa sumatoria debajo principal es:%.1f", sumatoria_por_debajo_principal(ORDEN, cuadrada3));
        printf("\nLa sumatoria encima secundaria es:%.1f", sumatoria_por_encima_secundaria(ORDEN, cuadrada3));
        printf("\nLa sumatoria debajo secundaria es:%.1f", sumatoria_por_debajo_secundaria(ORDEN, cuadrada3));
        break;
    case 2:
        system("CLS");
        printf("\nMATRIZ DE PRUEBA\n");
        imprimir_matriz(ORDEN, ORDEN, cuadrada3);
        printf("\nLa traza principal es: %.1f", traza_principal(ORDEN, cuadrada3));
        printf("\nLa traza principal es: %.1f", traza_secundaria(ORDEN, cuadrada3));
        break;
    case 3:
        system("CLS");
        printf("\nMATRIZ DE PRUEBA\n");
        imprimir_matriz(ORDEN, ORDEN, identidad3);
        printf("\nLa matriz es diagonal: %d", esDiagonal(ORDEN, identidad3));
        break;
    case 4:
        system("CLS");
        printf("\nMATRIZ DE PRUEBA\n");
        imprimir_matriz(ORDEN, ORDEN, identidad3);
        printf("\nLa matriz es identidad: %d", esIdentidad(ORDEN, identidad3));
        break;
    case 5:
        system("CLS");
        printf("\nMATRIZ DE PRUEBA\n");
        imprimir_matriz(ORDEN, ORDEN, simetrica3);
        printf("\nLa matriz es simetrica: %d", esSimetrica(ORDEN, simetrica3));
        break;
    case 6:
        system("CLS");
        printf("\nMATRIZ DE PRUEBA\n");
        imprimir_matriz(ORDEN, ORDEN, cuadrada3);
        printf("\nLa matriz transpuesta es:\n");
        trasponer_cuadrada(ORDEN, cuadrada3);
        imprimir_matriz(ORDEN, ORDEN, cuadrada3);
        break;
    case 7:
        system("CLS");
        printf("\nMATRIZ DE PRUEBA\n");
        imprimir_matriz(3, 2, matriz);
        printf("\nLa matriz transpuesta es:\n");
        trasponer_matriz(3, 2, matriz, matriz_transpuesta);
        imprimir_matriz(2, 3, matriz_transpuesta);
        break;
    case 8:
        system("CLS");
        printf("\nMATRIZ 1\n");
        imprimir_matriz(3, 2, matriz);
        trasponer_matriz(3, 2, matriz, matriz_transpuesta);
        printf("\nMATRIZ 2\n");
        imprimir_matriz(2, 3, matriz_transpuesta);
        printf("\nMATRIZ PRODUCTO\n");
        multiplicacion_matriz(3, 2, matriz, matriz_transpuesta, matriz_producto);
        imprimir_matriz(3, 3, matriz_producto);
    }

}
