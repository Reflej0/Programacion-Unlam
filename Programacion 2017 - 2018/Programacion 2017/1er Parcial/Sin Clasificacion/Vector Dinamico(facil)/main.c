#include <stdio.h>
#include <stdlib.h>

int main()
{
    void *vector_din = NULL;
    int *vector_convertido = NULL;
    vector_din = malloc(4*sizeof(int));
    int i;
    for(i=0;i<10;i++)
    {
        int numero;
        printf("Ingrese un numero:\n");
        scanf("%d", &numero);
        vector_convertido = (int*)vector_din;
        vector_convertido[i] = numero;
        if((i+1)==sizeof(vector_din)/sizeof(int))
        {
            vector_din = realloc(vector_din, 10*sizeof(int));
        }
    }
    for(i=0;i<10;i++)
    {
        printf("%d", vector_convertido[i]);
    }
}
