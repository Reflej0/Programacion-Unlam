#include <stdio.h>
#include <stdlib.h>
#include "burbuja.h"

void ord_burbuja_asc(char *v, int const ce)
{
    int i = 0;
    int j = 0;
    int aux;
    for(i=1;i<ce;i++)
    {
        for(j=0;j<ce-i;j++)
        {
            if(v[j]>=v[j+1])
            {
                aux = v[j];
                v[j] = v[j+1];
                v[j+1] = aux;
            }
        }
    }
}
