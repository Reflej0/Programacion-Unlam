#include <stdio.h>
#include <stdlib.h>
#define ES_SIGNO(c) (((c)=='-' || (c)=='+') ? 1 : 0)
#define ES_NUMERO(c) (((c)>='0' && (c)<='9') ? 1 : 0)

float _atof(const char* cad)
{
    if(!cad || !*cad) return 0;
    float signo = 1;
    float numero = 0;
    float decimales = 0;
    while(*cad == ' ')
        cad++;
    while(!ES_SIGNO(*cad) && !(ES_NUMERO(*cad)))
        cad++;
    if(*cad == '-')
    {
        signo = -1;
        cad++;
    }
    else if(*cad == '+')
    {
        signo = +1;
        cad++;
    }
    while(*cad && *cad!='.')
    {
        if(!ES_NUMERO(*cad))
            return 0;
        numero = numero*10 + *cad - '0';
        cad++;
    }
    if(*cad == '.')
    {
        cad++;
        while(*cad)
        {
            if(!ES_NUMERO(*cad))
                return 0;
            decimales = decimales + *cad - '0';
            decimales/=10;
            cad++;
        }
    }
    return (decimales+numero)*signo;
}

int _atoi(const char* cad)
{
    if(!cad || !*cad) return 0;
    int signo = 1;
    int numero = 0;
    while(*cad == ' ')
        cad++;
    while(!ES_SIGNO(*cad) && !(ES_NUMERO(*cad)))
        cad++;
    if(*cad == '-')
    {
        signo = -1;
        cad++;
    }
    else if(*cad == '+')
    {
        signo = +1;
        cad++;
    }
    while(*cad)
    {
        if(!ES_NUMERO(*cad))
            return 0;
        numero = numero*10 + *cad - '0';
        cad++;
    }
    return numero*signo;;
}

int main()
{
    //char lote[10] = "210";
    char lotef[10] = "-204.32";
    //printf("Numero: %d", _atoi(lote));
    printf("\nNumero: %f", _atof(lotef));
    return 0;
}
