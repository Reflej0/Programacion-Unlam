#include <stdio.h>
#include <stdlib.h>
#include "matrices.h"

int main()
{
    int matriz[3][3] = {{1, 4, 5}, {2, 7, 8}, {3, 6, 9}};
    int identidad[3][3] = {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}};
    int simetrica[3][3] = {{1, 2, 3}, {2, 5, 7}, {3, 7, 9}};
    int simetrica_[3][3] = {{9, 4, 1}, {7, 2, 4}, {3, 7, 9}};
    int matriz2[2][2] = {{1, 4}, {2, 7}};
    //mostrar_matriz_cuadrada(3, matriz);
    //printf("Sumatoria: %d", sumatoria_encima_excluida_principal(3, matriz));
    //printf("Sumatoria: %d", sumatoria_encima_incluida_principal(3, matriz));
    //printf("Sumatoria: %d", sumatoria_debajo_excluida_principal(3, matriz));
    //printf("Sumatoria: %d", sumatoria_debajo_incluida_principal(3, matriz));
    //printf("Sumatoria: %d", sumatoria_encima_excluida_secundaria(3, matriz));
    //printf("Sumatoria: %d", sumatoria_encima_incluida_secundaria(3, matriz));
    //printf("Sumatoria: %d", sumatoria_debajo_excluida_secundaria(3, matriz));
    //printf("Sumatoria: %d", sumatoria_debajo_incluida_secundaria(3, matriz));
    //printf("Traza principal: %d", traza_principal_matriz(3, matriz));
    //printf("Traza secundaria: %d", traza_secundaria_matriz(3, matriz));
    //printf("Es diagonal: %d", es_diagonal(3, identidad));
    //printf("Es identidad: %d", es_identidad(3, identidad));
    //printf("Es simetrica: %d", es_simetrica_respecto_principal(3, simetrica));
    //printf("Es simetrica: %d", es_simetrica_respecto_secundaria(3, simetrica_));
    mostrar_matriz_cuadrada(3, matriz);
    transponer_in_situ_cuadrada(3, matriz);
    mostrar_matriz_cuadrada(3, matriz);
    return 0;
}
