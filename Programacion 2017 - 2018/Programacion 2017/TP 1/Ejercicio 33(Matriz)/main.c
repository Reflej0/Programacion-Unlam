#include <stdio.h>
#include <stdlib.h>

int main()
{
    int orden = 0;
    int i, j;
    int simetrica = 0;
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
                if((i<j) && (matriz[i][j] == matriz[j][i]))
                    {
                        simetrica++;
                }

        }
    }
    if(simetrica == orden){
        printf("La matriz es simetrica");
    }
    else{
        printf("La matriz no es simetrica");
    }
}
