#include <stdio.h>
#include <stdlib.h>

int main()
{
    int numero = 0;
    int numero2 = 0;
    int i = 0;
    int cociente = 0;
    printf("Ingrese dos numeros:");
    scanf("%d %d", &numero, &numero2);
    for(i=numero;i>0;i-=numero2){
        cociente++;
    }
    printf("El cociente es: %d", cociente);
    printf("\nEl resto es: %d", numero%numero2);
}
