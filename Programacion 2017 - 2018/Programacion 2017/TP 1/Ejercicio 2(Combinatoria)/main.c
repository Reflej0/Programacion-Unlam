#include <stdio.h>
#include <stdlib.h>

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
    int m = 0;
    int n = 0;
    int combinatoria = 0;
    printf("Ingrese m: ");
    scanf("%d", &m);
    printf("Ingrese n: ");
    scanf("%d", &n);
    combinatoria = (factorial(m)) / (factorial(n) * factorial(m-n));
    printf("La combinatoria es: %d\n", combinatoria);
    system("pause");
}
