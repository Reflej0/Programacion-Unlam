#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int _atoi(char* cad)
{
    int signo = 1;
    if(*cad == '-')
    {
        signo = -1;
        cad++;
    }
    if(*cad == '+')
    {
        cad++;
    }
    int numero;
    while(*cad)
    {
        numero += numero*10 + *cad - '0';
        cad++;
    }
    return signo*numero;
}

float _atof(char* cad)
{
    float signo = 1;
    if(*cad == '-')
    {
        signo = -1;
        cad++;
    }
    if(*cad == '+')
    {
        cad++;
    }
    float numero;
    while(*cad != '\0' && *cad != '.')
    {
        numero += numero*10 + *cad - '0';
        cad++;
    }
    if(*cad == '.')
    {
        cad++;
        float decimales = 1;
        float partedecimal = 0;
        while(*cad != '\0')
        {
            decimales*=0.1;
            partedecimal += (*cad - '0') *decimales;
            cad++;
        }
        numero+=partedecimal;
    }

    return (signo*numero);
}

void invertir(char* invertida, const char* cadena)
{
    int lon = strlen(cadena);
    int i;
    int aux = lon-1;
    for(i=0;i<lon;i++)
    {
        invertida[i] = cadena[aux-i];
    }
}

char* ___itoa(int numero)
{
    char* resp = malloc(sizeof(char)*10);
    int _numero = numero;
    int k = 0;
    int aux;
    while(_numero>=1)
    {
        aux = _numero % 10;
        *resp = aux + '0';
        resp++;
        _numero /= 10;
        k++;
    }
    *resp = '\0';
    char* cadena_invertida = malloc(sizeof(char)*10);
    invertir(cadena_invertida, resp-k);
    cadena_invertida[k] = '\0';
    free(resp);
    return cadena_invertida;
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
    char* num_char = ___itoa(numero);
    printf("%s", num_char);
}
