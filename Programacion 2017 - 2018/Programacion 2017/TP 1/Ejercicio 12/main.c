#include <stdio.h>
#include <stdlib.h>

int main()
{
    int numero = 0;
    int i = 0;
    int resultado = 0;
    printf("Ingrese un numero:");
    scanf("%d", &numero);
    for(i=0;i<numero;i++){
        resultado+=i;

    }
    printf("La suma de los numeros pares hasta %d, es: %d", numero, resultado);
}
