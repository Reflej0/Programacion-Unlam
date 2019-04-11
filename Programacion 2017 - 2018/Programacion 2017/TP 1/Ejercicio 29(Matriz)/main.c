#include <stdio.h>
#include <stdlib.h>

int main()
{
    int orden = 0;
    int i, j;
    float encimadeladiagonal = 0;
    float debajodeladiagonal = 0;
    printf("Ingrese el orden de la matriz cuadrada:");
    scanf("%d", &orden);
    float matriz[orden][orden];
    for(i=0;i<orden;i++){
        for(j=0;j<orden;j++){
            printf("\nIngrese un numero:");
            scanf("%f", &matriz[i][j]);
            if(i<j){
                encimadeladiagonal+= matriz[i][j];
            }
            if(i>j){
                debajodeladiagonal+=matriz[i][j];
            }
        }
    }
    printf("\nLa suma de los elementos encima de la diagonal es: %.2f", encimadeladiagonal);
    printf("\nLa suma de los elementos debajo de la diagonal es: %.2f", debajodeladiagonal);
}
