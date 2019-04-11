#include <stdio.h>
#include <stdlib.h>
#include "auxiliares_arbol.h"

int comp_int(const void* a, const void* b)
{
    return *(T_dato*)a - *(T_dato*)b;
}

void show_int(const void* a)
{
    printf("DATO: %d\n", *(T_dato*)a);
}
