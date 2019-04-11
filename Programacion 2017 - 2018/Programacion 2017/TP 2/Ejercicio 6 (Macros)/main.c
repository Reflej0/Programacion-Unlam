#include <stdio.h>
#include <stdlib.h>
//No se puede usar el IF en macros, por eso se sustituye por el operador ternario.
#define truncate(numero) (((numero) - (int)(numero)) >= 0.5) ? ((int)numero+1) : ((int)numero)
#define less(a,b) ((a)<(b)) ? (a) : (b)
//Implementacion de max y min según stdlib.h
#ifndef max
#define max(a,b) (((a) > (b)) ? (a) : (b))
#define min(a,b) (((a) < (b)) ? (a) : (b))
#endif

#define change(a,b) typeof(a)(temp) = (a); (a) = (b); (b) = (temp);

int main()
{
    //Prueba del Macro #1.
    float numero;
    float a, b;
    printf("Ingrese un numero:");
    scanf("%f", &numero);
    printf("\nEl numero redondeado es:%d", truncate(numero));
    //Prueba del Macro #2.
    printf("\nIngrese dos numeros a,b:");
    scanf("%f,%f", &a, &b);
    //Prueba del Macro #3.
    printf("\nEl numero menor es:%f", less(a,b));
    printf("\nEl mayor numero es %f", max(a,b));
    //Prueba del Macro #4.
    change(a,b);
    printf("\nNumero a:%f\nNumero b:%f", a, b);
}
