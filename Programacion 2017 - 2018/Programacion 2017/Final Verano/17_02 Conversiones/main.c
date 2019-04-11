#include <stdio.h>
#include <stdlib.h>

int _atoi(char* cad)
{
    int signo = 1;
    int numero = 0;
    if(*cad == '-')
    {
        signo = -1;
        cad++;
    }
    while(*cad)
    {
        numero = numero*10 + *cad-'0';
        cad++;
    }
    return (signo*numero);
}

float _atof(char* cad)
{
    float signo = 1;
    float numero = 0;
    float decimales = 0;
    float vec[] = {0.1, 0.01, 0.001, 0.0001, 0.00001, 0.000001, 0.0000001};
    int i = 0;
    if(*cad == '-')
    {
        signo = -1;
        cad++;
    }
    while(*cad && *cad !='.')
    {
        numero = numero*10 + *cad-'0';
        cad++;
    }
    if(*cad == '.')
    {
        cad++;
        while(*cad)
        {
            decimales += ((*cad-'0')*vec[i]);
            cad++;
            i++;
        }
    }
    return signo*(numero+decimales);
}

int _strlen(char* cad)
{
    int i = 0;
    while(*cad)
    {
        i++;
        cad++;
    }
    return i;
}

char* invertir_cadena(char* cad)
{
    int l = _strlen(cad);
    int i = l;
    char* inv = (char*)malloc((sizeof(char)*l)+1);
    cad+=l-1;
    while(i > 0)
    {
        *inv = *cad;
        cad--;
        inv++;
        i--;
    }
    *inv = '\0';
    return (inv-l);
}

char* __itoa(int numero)
{
    char* cad = (char*)malloc(sizeof(char)*10);
    int _numero = numero;
    int i = 0;
    while(_numero > 0)
    {
        int resto = _numero % 10;
        *cad = resto+'0';
        _numero /= 10;
        cad++;
        i++;
    }
    *cad = '\0';
    char* invertida = invertir_cadena(cad-i);
    return invertida;
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
