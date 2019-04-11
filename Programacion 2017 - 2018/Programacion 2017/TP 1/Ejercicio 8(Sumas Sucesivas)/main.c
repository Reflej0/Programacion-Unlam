#include <stdio.h>
#include <stdlib.h>

int main()
{
    int numero = 0;
    int numero2 = 0;
    int resultado = 0;
    int i = 0;
    printf("Ingrese dos numeros:");
    scanf("%d %d", &numero, &numero2);
    for(i=0; i<numero2;i++){
        resultado+=numero;
    }
    printf("%dX%d=%d", numero, numero2, resultado);
}
