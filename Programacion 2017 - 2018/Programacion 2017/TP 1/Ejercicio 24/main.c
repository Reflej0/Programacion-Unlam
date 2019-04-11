#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i = 0;
    int posicion;
    int vector[5] = {10, 100, 50, 80, 40};
    printf("Ingrese la posicion");
    scanf("%d", &posicion);
    vector[posicion-1] = 0;
}
