#include <stdio.h>
#include <stdlib.h>
#include "_stdlib.h"

int main()
{
    char numero[] = "-450";
    //printf("%d",_atoi(numero));
    char decimales[] = "10.25";
    //printf("%f",_atof(decimales));
    int num = 4708;
    char nu[4] = "";
    _itoa(num, nu, 10);
    printf("%s", nu);
}
