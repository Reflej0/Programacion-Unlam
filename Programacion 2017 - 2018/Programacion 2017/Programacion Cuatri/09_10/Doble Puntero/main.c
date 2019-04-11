#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char info[20];
} t_palabra;

int main()
{
    t_palabra normal;
    strcpy(normal.info, "Texto");
    t_palabra* palabra = &normal;
    void** void_palabra = (void*)&palabra;
    void* aux = *void_palabra;
    t_palabra* aux2 = (t_palabra*)aux;
    printf("%s", aux2->info);

}
