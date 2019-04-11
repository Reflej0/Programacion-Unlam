#include <stdio.h>
#include <stdlib.h>
#include "recursividad.h"

int main()
{
    char s[20] = "Frase";
    int v[5] = {10, 20, 30, 40, 50};
    printf("Longitud: %d", _strlen(s));
    printf("\nFactorial de 20: %I64d", _factorial(20));
    printf("\nLa suma de los primeros 5 numeros al cuadrado, %I64d\n", _primeros_n_cuadrado(5));
    _mostrar_cadena_menos_caracter("Sana sana colita de rana", 'a');
    printf("\n");
    _mostrar_cadena_escalonada("Murcielago");
    _print_vector_int(v, 5, '\t');
    return 0;
}
