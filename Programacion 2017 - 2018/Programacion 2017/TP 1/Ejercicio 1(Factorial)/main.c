#include <stdio.h>
#include <stdlib.h>

int main()
{
    int numero = 0;
    int factorial = 1;
    int i = 0;
    printf("Ingrese un numero:");
    scanf("%d", &numero);
    for(i = numero; i>0; i--){
        factorial *=i;
    }
    printf("El factorial de %d es: %d\n", numero, factorial);
    system("pause");
}

