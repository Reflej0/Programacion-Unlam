#include <stdio.h>
#include <stdlib.h>

int main()
{
    int orden = 0;
    int i, j;
    int temporal;
    printf("Ingrese el orden de la matriz cuadrada:");
    scanf("%d", &orden);
    int matriz[orden][orden];
    for(i=0;i<orden;i++){
        for(j=0;j<orden;j++){
            printf("\nIngrese un numero:");
            scanf("%d", &matriz[i][j]);
        }
    }
    //Se guarda la matriz transpuesta dentro de la misma matriz, para no tener que usar una matriz auxiliar.
    for(i=0;i<orden;i++){
        for(j=0;j<orden;j++){
                if(i<j){
            temporal = matriz[i][j];
            matriz[i][j] = matriz[j][i];
            matriz[j][i] = temporal;
                }

        }
        //Se imprime la matriz transpuesta.
        for(i=0;i<orden;i++){
            for(j=0;j<orden;j++){
                printf("%d", matriz[i][j]);
            }
                    printf("\n");
        }
    }
}
