#include <stdio.h>
#include <stdlib.h>
#include "burbuja.h"

int main()
{
    int i = 0;
    char *v = malloc(sizeof(char)*10);
    v[0] = 'Z'; v[1] = 'A'; v[2] = 'C'; v[3] = 'F'; v[4] = 'M';
    v[5] = 'Y'; v[6] = 'U'; v[7] = 'R'; v[8] = 'I'; v[9] = 'H';
    printf("DESPUES DEL ORDENAMIENTO\n");
    ord_burbuja_asc(v, 10);
    for(i=0; i<10;i++)
    {
        printf("%c\n", v[i]);
    }
    free(v);
}
