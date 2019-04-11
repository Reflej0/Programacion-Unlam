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

int main()
{
    int numero = 0;
    float tol = 0;
    int i = 1;
    float termino = 0;
    float resultado = 0;
    printf("Ingrese un numero: ");
    scanf("%d", &numero);
    printf("Ingrese la tolerancia: ");
    scanf("%f", &tol);
    do // El do-while es necesario ya que necesito AL MENOS ejecutar el ciclo una vez.
        {
        termino = pow(numero, i) / factorial(i);
        resultado += termino;
        i++;
        }
    while(tol<termino);
    resultado+=1;
    printf("e elevado a %d es: %f\n", numero, resultado);
}
