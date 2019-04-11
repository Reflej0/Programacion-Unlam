#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int _strlen(char* s)
{
    int l = 0;
    while(*s)
    {
        l++;
        s++;
    }
    return l;
}

int comparacion(char* palabra, char* dato)
{
    char c;
    int l = _strlen(dato);
    int coinc = 0;
    while(*palabra)
    {
        c = toupper(*palabra);
        //printf("%c", c);
        //system("PAUSE");
        if(c == *dato)
        {
            dato++;
            coinc++;
        }
        else
        {
            dato-=coinc;
            coinc = 0;
        }
        if(coinc == l)
        {
            return 1;
        }
        palabra++;
    }
    return 0;
}

int main()
{
    ///PARA CONTAR APARICIONES
    char palabra[20];
    int i = 0;
    int apariciones = 0;
    ///PARA ELIMINAR APARICIONES
    char sinola[100];
    int flag = 0;
    char* frase = "Hola soy como las OlAs que dicen hola, donde olas chau OLAS.";
    ///Contar la aparición del substr "ola" sin importar mayusculas y minusculas.
    ///Resultado final: 5.
    while(*frase)
    {
        i = 0;
        while(*frase != ' ' && *frase !='.')
        {
            palabra[i] = *frase;
            i++;
            frase++;
        }
        palabra[i] = '\0';
        apariciones+= comparacion(palabra, "OLA");
        if(comparacion(palabra, "OLA") == 0)
        {
            if(flag == 0)
            {
                strcpy(sinola, palabra);
            }
            else
            {
                strcat(sinola, " ");
                strcat(sinola, palabra);
            }
            flag++;
        }
        frase++;
    }
    printf("Frase sin ola:%s", sinola);
    printf("Apariciones:%d", apariciones);
}
