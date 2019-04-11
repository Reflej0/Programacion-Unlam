#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "seleccion_floats.h"

int main()
{
    int i = 0;
    float *v = malloc(sizeof(float)*20);
    srand(time(NULL));
    for(i=0; i<20;i++)
    {
        v[i] = (float)rand()/(float)RAND_MAX;
    }
    for(i=0; i<20;i++)
    {
        printf("%.2f\n", v[i]);
    }
    printf("DESPUES DEL ORDENAMIENTO\n");
    ord_seleccion_asc(v, 20);
    for(i=0; i<20;i++)
    {
        printf("%.2f\n", v[i]);
    }
    free(v);
}
