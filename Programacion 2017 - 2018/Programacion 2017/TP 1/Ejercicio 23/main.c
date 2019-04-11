#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i = 0;
    int j = 0;
    int aux;
    int vector[10] = {1, 9, 3, 90, 5, 8, 23, 11, 100};
    int numero;
    printf("Ingrese un numero:");
    scanf("%d", &numero);
    vector[9] = numero;
    for(i=1;i<10;i++){
        for(j=0;j<10-i;j++){
            if(vector[j] > vector[j+1]){
            aux = vector[j];
            vector[j] = vector[j+1];
            vector[j+1] = aux;
            }
        }
    }
    for(i=0;i<10;i++){
        printf("\n%d", vector[i]);
    }
}
