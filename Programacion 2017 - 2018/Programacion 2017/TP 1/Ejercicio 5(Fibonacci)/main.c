#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i = 1;
    int j = 0;
    int k = 0;
    int numero = 0;
    printf("Ingrese un numero:");
    scanf("%d", &numero);
    while(i<numero){
        if(i!=1){
            k=i;
            i+=j;
            j=k;
        }
        else{ // Esto es para la primera vez que itero.
            i++;
            j++;
        }
            printf("\n%d", i); // Voy imprimiendo la serie Fibonacci por pantalla.
    }
    if(i==numero){
        printf("\nEl numero pertenece a la serie Fibonacci");
    }
}
