#include <stdio.h>
#include <stdlib.h>

int main()
{
    int numero = 0;
    int i = 1;
    int sumadivisores = 0;
    printf("Ingrese un numero: ");
    scanf("%d", &numero);
    for(i=1;i<=(numero/2);i++){ // Para optimizar el numero de iteraciones realizadas el numero/2.
        if(numero % i == 0){
            sumadivisores+=i;
        }
    }
    if(numero==sumadivisores){
        printf("El numero es PERFECTO");
    }
    if(numero>sumadivisores){
        printf("El numero es DEFICIENTE");
    }
    if(numero<sumadivisores){
        printf("El numero es ABUNDANTE");
    }
}
