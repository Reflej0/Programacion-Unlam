#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "insercion_ints.h"

int main()
{
    int i = 0;
    int *v = malloc(sizeof(int)*20);
    srand(time(NULL));
    for(i=0; i<20;i++)
    {
        v[i] = rand() % 20;
    }
    for(i=0; i<20;i++)
    {
        printf("%d\n", v[i]);
    }
    printf("DESPUES DEL ORDENAMIENTO\n");
    ord_insercion_asc(v, 20);
    for(i=0; i<20;i++)
    {
        printf("%d\n", v[i]);
    }
    free(v);
}
