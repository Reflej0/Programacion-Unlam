#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

void intercambio(char *c, char *d)
{
    char aux = *c;
    *c = *d;
    *d = aux;
}

char* normalizar_nya(char* nya)
{
    char* inicio = nya;
    char* escritura = nya;
    int primeraletra = 1;
    char* coma = NULL;
    while(*nya == ' ') //Sacar los espacios al inicio.
    {
        nya++;
    }
    while(*nya)
    {
        if(((*nya>='a' && *nya<='z') || (*nya>='A' && *nya<='Z')))
        {
            if(primeraletra == 1){*escritura = toupper(*nya); primeraletra = 0;}
            else *escritura = tolower(*nya);
            escritura++;
        }
        else if(*nya == ' ' && *(nya+1)!=' ' && *(nya+1)!='\0')
        {
            primeraletra = 1;
            *escritura = ',';
            escritura++;
            coma = escritura;
        }
        nya++;
    }
    *escritura = '\0';
    if(coma) //Insertar el espacio despues de la coma y desplazar a la derecha.
    {
        char c = ' ';
        intercambio(coma, &c);
        while(*coma)
        {
            coma++;
            intercambio(coma, &c);
        }
    }
    return inicio;
}

int main()
{
    char nya[40];
    gets(nya);
    printf("\n%s",normalizar_nya(nya));
    return 0;
}
