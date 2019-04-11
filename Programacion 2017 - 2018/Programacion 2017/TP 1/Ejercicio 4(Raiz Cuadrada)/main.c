#include <stdio.h>
#include <stdlib.h>
#include <math.h> // Por la funcion fabs.
int main()
{
    float termino = 1; // Esto empieza asi por el algoritmo.
    float tol = 0;
    float terminoanterior = 0;
    int i = 0;
    int numero = 0;
    printf("Ingrese un numero: ");
    scanf("%d", &numero);
    printf("Ingrese la  tolerancia: ");
    scanf("%f", &tol);
    do
    {
        terminoanterior = termino; // El terminoanterior SIEMPRE empieza con valor de 1.
        termino = 0.5*(terminoanterior+(numero/terminoanterior)); // Impuesto por el algoritmo.
    }
    while(fabs(termino-terminoanterior)>tol); // Evaluo si el error cometido es mayor que la tolerancia.
    printf("La raiz cuadrada de %d es: %f", numero, termino);
}
