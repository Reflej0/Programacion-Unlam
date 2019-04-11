#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "header.h"

int comp_int(const void* a, const void* b ,int orden)
{
    if(orden == DESC)
        return *(int*)a - *(int*)b;
    return *(int*)b - *(int*)a;
}

void mostrar_vector_int(int* v, const size_t nro_ele)
{
    int* fin = v+nro_ele;
    for(; v<fin; v++)
    {
        printf("ELEMENTO: %d\n", *v);
    }
}

void* buscarMenor(void* inicio, void* fin, const size_t size_ele, T_cmp cmp, const int orden)
{
    void* menor = inicio;
    void* i = inicio+size_ele; //Para no comparar siempre el primero contra el primero en el IF.
    for(; i < fin; i+=size_ele)
    {
        if(cmp(menor, i, orden)<0)
        {
            menor = i;
        }
    }
    return menor;
}

void intercambiar(void* a, void* b, const size_t s)
{
    void* x = malloc(s);
    if(!x)
        return;
    memcpy(x, a, s);
    memcpy(a, b, s);
    memcpy(b, x, s);
    free(x);
}

void ordenar(void* v, const size_t size_ele, const size_t nro_ele, T_cmp cmp, const int orden)
{
    void* pos_menor = v;
    void* fin = v + size_ele*nro_ele;
    for(; v<fin-size_ele; v+=size_ele)
    {
        pos_menor = buscarMenor(v, fin, size_ele, cmp, orden);
        if(v != pos_menor)
            intercambiar(v, pos_menor, size_ele);
    }
}
