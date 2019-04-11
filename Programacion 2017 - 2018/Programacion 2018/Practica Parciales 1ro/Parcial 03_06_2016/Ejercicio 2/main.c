#include <stdio.h>
#include <stdlib.h>

int comprobar_simetria_secundaria_hardcodeado(int orden, int matriz[orden][orden])
{
    switch(orden)
    {
    case 1:
        return 1;
    case 2:
        if(matriz[0][0]!=matriz[1][1])
            return 0;
    case 3:
        if(matriz[0][0]!=matriz[2][2] || matriz[0][1]!=matriz[1][2] ||  matriz[1][0]!=matriz[2][1])
            return 0;
    case 4:
        if(matriz[0][0]!=matriz[4][4] || matriz[0][1]!=matriz[2][3] ||  matriz[0][2]!=matriz[1][3] || matriz[1][0]!=matriz[3][2] || matriz[1][1]!=matriz[2][2] || matriz[2][0]!=matriz[3][1])
            return 0;
    }
    return 1;
}

int comprobar_simetria_secundaria(int orden, int matriz[orden][orden])
{
    int i, j;
    ///Comprobacion de primer elemento contra ultimo.
    if(matriz[0][0] != matriz[orden-1][orden-1])
        return 0;
    for(i=0;i<orden;i++)
    {
        for(j=0;j<orden;j++)
        {
            if(j+i == orden-1) ///Busco estar en los elementos de la diagonal secundaria.
            {
                if(j==orden-1)
                {
                    if(matriz[i][j-1] != matriz[i+1][j])
                        return 0;
                }
                else if(i==orden -1)
                {
                    if(matriz[i-1][j] != matriz[i][j+1])
                        return 0;
                }
                else
                {
                    if(matriz[i-1][j-1]!=matriz[i+1][j+1])
                        return 0;
                }
            }
        }
    }
    return 1;
}

int main()
{
    ///LOTE.
    int m[3][3] = {{1, 3, 7}, {2, 8, 3}, {9, 2, 1}}; ///ES SIMETRICA RESPECTO DE SU DIAGONAL SECUNDARIA.
    int t[3][3] = {{1, 4, 7}, {4, 2, 8}, {7, 8, 3}}; ///ES SIMETRICA RESPECTO DE SU DIAGONAL PRINCIPAL.
    int x[3][3] = {{1, 9, 13}, {-5, 4, 17}, {33, 12, 4}}; ///NO CUMPLE NINGUNA CARACTERISTICA EN ESPECIAL.
    int r[4][4] = {{4, 5, 10, 9}, {2, 3, 8, 10}, {1, 7, 3,  5}, {6, 1, 2, 4}}; ///ES SIMETRICA RESPECTO DE SU DIAGONAL SECUNDARIA.

    int resultado;
    ///PRUEBAS.

    printf("La matriz 1");
    resultado = comprobar_simetria_secundaria(3, m);
    printf("\nLa matriz es simetrica respecto de su diagonal secundaria: %d", resultado);

    printf("\nLa matriz 2");
    resultado = comprobar_simetria_secundaria(3, t);
    printf("\nLa matriz es simetrica respecto de su diagonal secundaria: %d", resultado);

    printf("\nLa matriz 3");
    resultado = comprobar_simetria_secundaria(3, x);
    printf("\nLa matriz es simetrica respecto de su diagonal secundaria: %d", resultado);

    printf("\nLa matriz 4");
    resultado = comprobar_simetria_secundaria(4, r);
    printf("\nLa matriz es simetrica respecto de su diagonal secundaria: %d", resultado);
    return 1;
}
