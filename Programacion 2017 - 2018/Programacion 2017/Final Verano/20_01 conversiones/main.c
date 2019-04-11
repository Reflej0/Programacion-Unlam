#include <stdio.h>
#include <stdlib.h>

int _atoi(char* numero)
{
    int signo = 1;
    int int_numero = 0;
    if(*numero == '-')
    {
        signo = -1;
        numero++;
    }
    while(*numero)
    {
        int_numero = (int_numero*10)+(*numero-'0');
        numero++;
    }
    return signo*int_numero;
}

float _atof(char* numero)
{
    int signo = 1;
    float float_numero = 0;
    if(*numero == '-')
    {
        signo = -1;
        numero++;
    }
    while(*numero && *numero!='.')
    {
        float_numero = (float_numero*10)+(*numero-'0');
        numero++;
    }
    if(*numero == '.')
    {
        float i = 0.1;
        numero++;
        while(*numero)
        {
            float_numero  += (*numero-'0')*i;
            i /= 10;
            numero++;
        }
    }
    return signo*float_numero;
}

int main()
{
    char numero_char[10];
    printf("Introduzca un numero:");
    ///ATOI
    /*scanf("%s", numero_char);
    int numero = _atoi(numero_char);
    numero+=5;
    printf("Numero:%d", numero);*/
    ///ATOF
    scanf("%s", numero_char);
    float numero = _atof(numero_char);
    numero+=0.5;
    printf("Numero:%f", numero);
}
