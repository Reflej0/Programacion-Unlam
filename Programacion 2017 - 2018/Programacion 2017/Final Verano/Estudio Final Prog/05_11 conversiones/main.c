#include <stdio.h>
#include <stdlib.h>

int _atoi(const char* cadena)
{
    int signo = 1;
    if(*cadena == '-')
    {
        signo= -1;
        cadena++;
    }
    int numero = 0;
    while(*cadena)
    {
        numero = numero*10 + *cadena - '0';
        cadena++;
    }
    return signo*numero;
}

float _atof(const char* cadena)
{
    float numero = 0;
    float signo = 1;
    float decimales = 0.1;
    if(*cadena == '-')
    {
        signo= -1;
        cadena++;
    }
    //RECORRO HASTA EL PUNTO.
    while(*cadena && *cadena !='.')
    {
        numero = numero*10 + *cadena - '0';
        cadena++;
    }
    //RECORRO DESPUES DEL PUNTO.
    cadena++;
    while(*cadena)
    {
        numero +=  (*cadena - '0')*decimales;
        decimales /= 10;
        cadena++;
    }
    return signo*numero;
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
