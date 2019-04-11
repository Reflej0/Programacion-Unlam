#include <stdio.h>
#include <stdlib.h>

int main()
{
    int vector[10] = {};
    int posicion;
    int elemento = 1;
    int i = 0;
    printf("Ingrese la posicion:");
    scanf("%d", &posicion);
    vector[posicion-1] = elemento;
    for(i=0;i<10;i++){
        printf("\n%d", vector[i]);
    }
}
