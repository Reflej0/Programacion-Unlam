#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int factorial(int numero)
{
    int i = 0;
    int factorial = 1;
    for(i = numero; i>0; i--){
        factorial *=i;
    }
    return factorial;
}

float elevado(float numero, int ala)
{
    int i = 0;
    for(i=0;i<ala;i++){
        numero*=numero;
    }
    return numero;
}

int main()
{
    int i = 1; // Es la potencia de la x.
    int j = 0; // Me ayuda a determinar el signo de la operacion.
    int k = 0; // Variable temporal.
    float numero = 0;
    float tolerancia = 0;
    float resultado = 1;
    float termino = 0;
    printf("Ingrese un numero:");
    scanf("%f", &numero);
    printf("\nIngrese la tolerancia:");
    scanf("%f", &tolerancia);
    do{
        if(j % 2 == 0){
            k=i+2;
            termino = factorial(i) - elevado(numero, k);
            if(i==0){
                resultado = termino;
            }
            else{
                resultado /= termino;
            }
        }
        else{
            k=i+2;
            termino = factorial(i) + elevado(numero, k);
            resultado /= termino;
        }
        i+=2; // Va subiendo de dos en dos.
        j++;
    }
    while(abs(termino)>tolerancia);
    printf("DEBUG %d\n", i);
    printf("DEBUG %d\n", j);
    printf("DEBUG %d\n", k);
    printf("DEBUG %f\n", termino);
    printf("El seno de %.2f es:%f", numero, resultado);
}


