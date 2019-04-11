#include <stdio.h>
#include <stdlib.h>



void printf_(const char* cad)
{
    while(*cad || *cad == '.')
    {
        printf("%c", *(cad)+1);
        cad++;
    }
}

int main()
{
    char cad[1001];
    printf("Ingrese una cadena:");
    fgets(cad, 1000, stdin);
    printf_(cad);
    return 1;
}
