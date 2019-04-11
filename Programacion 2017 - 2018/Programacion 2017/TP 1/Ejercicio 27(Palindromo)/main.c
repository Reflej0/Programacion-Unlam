#include <stdio.h>
#include <stdlib.h>
#define MAX_STRING 50

int main()
{
    int numero;
    printf("Ingrese el numero de caracteres:");
    scanf("%d", &numero);
    numero -= 1;
    char palabra[numero];
    printf("Ingrese la palabra:");
    scanf("%s", &palabra);
    int i;
    int j = 0;
    for(i=0; i<=numero;i++){
       if(palabra[i] == palabra[numero-i]){
           j++;
          }
        }
    if(j == numero+1){
        printf("La cadena de caracteres es palindromo");
    }
    else{
        printf("La cadena de caracteres no es palindromo");
    }
}
