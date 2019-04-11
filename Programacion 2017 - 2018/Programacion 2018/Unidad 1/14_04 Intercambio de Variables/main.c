#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

///No funciona.
/*void intercambio_algebra_bool_mejorado(int* a, int* b)
{
    *a ^= *b ^= *a ^= *b;
}*/

///Intercambio utilizando algebra de bool.
void intercambio_algebra_bool(int* a, int* b)
{
    *a ^= *b;
    *b ^= *a;
    *a ^= *b;
}

///Intercambio utilizando operadores += -=
void intercambio_aritmetica_mejorada(int* a, int* b)
{
    *a += (*b);
    *b = (*a)-(*b);
    *a -= (*b);
}

///Intercambio utilizando aritmetica.
void intercambio_arimetica(int* a, int* b)
{
    *a = (*a)+(*b);
    *b = (*a)-(*b);
    *a = (*a)-(*b);
}

///Intercambio tradicional con una variable auxiliar.
void intercambio_tradicional(int* a, int* b)
{
    int aux = *a;
    *a = *b;
    *b = aux;
}

int main()
{
    int a = 5;
    int b = 13;
    ///Pruebas de rendimiento(tiempo).
    int i;
    struct timeval stop, start;
    gettimeofday(&start, NULL); // Inicio del cronometro.
    for(i=0; i<1000000; i++)
    {
        intercambio_tradicional(&a, &b);
    }
    gettimeofday(&stop, NULL); // Stop del cronometro.
    printf("Tiempo intercambio tradicional: %lums\n", stop.tv_usec - start.tv_usec);
    for(i=0; i<1000000; i++)
    {
        intercambio_arimetica(&a, &b);
    }
    gettimeofday(&stop, NULL);
    printf("Tiempo intercambio arimetica: %lums\n", stop.tv_usec - start.tv_usec);
    for(i=0; i<1000000; i++)
    {
        intercambio_aritmetica_mejorada(&a, &b);
    }
    gettimeofday(&stop, NULL);
    printf("Tiempo intercambio arimetica(mejorada): %lums\n", stop.tv_usec - start.tv_usec);
    gettimeofday(&start, NULL);
    for(i=0; i<1000000; i++)
    {
        intercambio_algebra_bool(&a, &b);
    }
    gettimeofday(&stop, NULL);
    printf("Tiempo intercambio algebra bool: %lums\n", stop.tv_usec - start.tv_usec);
}
