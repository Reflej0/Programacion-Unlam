#include <stdio.h>
#include <stdlib.h>
#include "_stdlib.h"

int _atoi(char const *cadena)
{
    int numero = 0;
    int signo = 1;
    int i = 0;
    if(cadena[i] == '-')
    {
        signo= -1;
        i++;
    }
    for(; cadena[i]!='\0';i++)
    {
        numero = numero*10 + cadena[i] - '0';
    }
    return (numero*signo);
}

float _atof(char const *cadena)
{
    float numero = 0;
    float signo = 1;
    float decimales = 0.1;
    int i = 0;
    if(cadena[i] == '-')
    {
        signo= -1;
        i++;
    }
    //Recorro hasta que finalice la cadena (float sin decimales), o hasta que encuentra un punto (float con decimales).
    for(; (cadena[i]!='\0' && cadena[i]!='.');i++)
    {
        numero = numero*10 + cadena[i] - '0';
    }
    //Si detecto que la cadena tiene . entonces tiene decimales.
    if(cadena[i] == '.')
    {
        i++; // Empiezo despues del punto.
        for(; cadena[i]!='\0'; i++)
        {
            numero +=  (cadena[i] - '0')*decimales;
            decimales /= 10;
        }
    }
    return (numero*signo);
}

void _itoa(int num, char *cad, int base)
{
    char *act = cad;
    int dig;
    int longitud = -1;
    while(num!=0)
    {
        dig = num % base;
        *act = dig < 10 ? dig + '0' : dig - 10 + 'A';
        num/=base;
        act++;
        longitud++;
    }
    *act = '\0';
    int i = 0;
    char aux;
    //Desde aca se invierte la cadena.
    dig = 0;
    if(longitud%2==0)
    {
        dig/=2;
    }
    else
    {
        dig/=2;
        dig++;
    }
    //Se invierte la cadena.
    for( ;i<dig;i++)
    {
        aux = cad[i];
        cad[i] = cad[longitud];
        cad[longitud] = aux;
        longitud--;
    }
}
