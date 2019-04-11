#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i = 0;
    int numero1, numero2;
    int resultado = 0;
    printf("Ingrese dos numero:");
    scanf("%d %d", &numero1, &numero2);
    while(numero1>0){
        if(numero1% 2 == 1){
            resultado+= numero2;
        }
        numero1 /=2;
        numero2 *=2;
    }
    printf("\nEl resultado de multiplicar ambos numeros es: %d", resultado);
}
