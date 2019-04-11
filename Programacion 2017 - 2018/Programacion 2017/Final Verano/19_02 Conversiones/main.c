#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int _atoi(char* c)
{
    int signo = 1;
    int numero = 0;
    if(*c == '-')
    {
        signo = -1;
        c++;
    }
    while(*c)
    {
        numero = (numero*10) + (*c-'0');
        c++;
    }
    return (signo*numero);
}

float _atof(char* c)
{
    float signo = 1;
    float numero;
    float decimales = 0;
    float vec[] = {0.1, 0.01, 0.001, 0.0001, 0.00001, 0.000001};
    int i = 0;
    if(*c == '-')
    {
        signo = -1;
        c++;
    }
    while(*c && *c != '.')
    {
        numero = (numero*10) + (*c-'0');
        c++;
    }
    if(*c == '.')
    {
        c++;
        while(*c)
        {
            decimales += (*c-'0')*vec[i];
            c++;
            i++;
        }
    }
    return (signo*(numero+decimales));
}

int _strlen(char* cad)
{
    int l = 0;
    while(*cad)
    {
        l++;
        cad++;
    }
    return l;
}

void invertir_cadena(char* cad)
{
    int i;
    int l = _strlen(cad);
    char* inv = (char*)malloc(sizeof(char)*l+1);
    for(i=l-1; i>=0; i--)
    {
        *inv = cad[i];
        inv++;
    }
    *inv = '\0';
    strcpy(cad, inv-l);
}

char* __itoa(int n)
{
    char* numero_char = (char*)malloc(sizeof(char)*11);
    int r;
    int i = 0;
    while(n > 0)
    {
        r = n % 10;
        *numero_char = r+'0';
        numero_char++;
        n /=10;
        i++;
    }
    *numero_char = '\0';
    numero_char-=i;
    invertir_cadena(numero_char);
    return (numero_char);
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
    /*scanf("%s", numero_char);
    float numero = _atof(numero_char);
    numero+=0.01;
    printf("Numero:%f", numero);*/
    ///ITOA
    int numero;
    scanf("%d", &numero);
    char* num_char = __itoa(numero);
    printf("%s", num_char);
}
