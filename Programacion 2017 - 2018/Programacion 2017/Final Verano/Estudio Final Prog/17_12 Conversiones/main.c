#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int _atoi(char* numero_char)
{
    int signo = 1;
    int numero = 0;
    if(*numero_char == '-')
    {
        signo = -1;
        numero_char++;
    }
    while(*numero_char)
    {
        numero = (numero*10)+(*numero_char-'0');
        numero_char++;
    }
    return numero*signo;
}

float _atof(char* numero_char)
{
    float signo = 1;
    float numero = 0;
    float decimales = 0.1;
    if(*numero_char == '-')
    {
        signo = -1;
        numero_char++;
    }
    ///RECORRO HASTA EL PUNTO EN CASO DE EXISTIR.
    while(*numero_char != '.' && *numero_char)
    {
        numero = (numero*10)+(*numero_char-'0');
        numero_char++;
    }
    numero_char++;
    while(*numero_char)
    {
        numero += (*numero_char-'0')*decimales;
        decimales /=10;
        numero_char++;
    }
    return numero*signo;
}

void _itoa(int numero, char* cadena)
{
    char* act = cadena;
    while(numero!=0)
    {
        *act = numero%10+'0';
        numero/=10;
    }
    invert_cadena(act);
}

void invert_cadena(char* origen)
{
    int longitud = strlen(origen);
    int i;
    char aux;
    for(i=0;i<(longitud/2);i++)
    {
        aux = origen[i];
        printf("%c", aux);
        system("PAUSE");
        origen[i] =  origen[longitud-i];
        origen[longitud-i] = aux;
    }
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
    numero+=0.5;
    printf("Numero:%f", numero);*/
    ///ITOA
    int numero;
    char cadena[10];
    scanf("%d", &numero);
    _itoa(numero, cadena);
    printf("CADENA: %s", cadena);
}
