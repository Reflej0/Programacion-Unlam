#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TOUPPER(c) ((c>='a' && c<='z') ? (c-32) : (c))

int compXlong(const char* cad1, const char* cad2)
{
    while(*cad1 && *cad2)
    {
        cad1++;
        cad2++;
    }
    if(*cad1 == '\0' && *cad2 != '\0')
        return -1;
    if(*cad1 != '\0' && *cad2 == '\0')
        return 1;
    return 0;
}

int compLexic(const char* cad1, const char* cad2)
{
    while(*cad1 && *cad2)
    {
        if(TOUPPER(*cad1)<TOUPPER(*cad2))
            return -1;
        else if(TOUPPER(*cad1)>TOUPPER(*cad2))
            return 1;
        cad1++;
        cad2++;
    }
    return 0;
}

int main()
{
    char cadenas[20][81];
    int i = 0;
    while(i<20)
    {
        printf("Ingrese la cadena 1:");
        scanf("%s", cadenas[i]);
        if(strcmp(cadenas[i], "FIN")==0)
        {
            i--;
            strcpy(cadenas[i], "\0");
            break;
        }
        i++;
        printf("Ingrese la cadena 2:");
        scanf("%s", cadenas[i]);
        if(strcmp(cadenas[i], "FIN")==0)
        {
            i--;
            strcpy(cadenas[i], "\0");
            break;
        }
        i++;
    }
}

/*int main()
{
    char c1[50] = "Frase extensa";
    char c2[50] = "Frase corta";
    char c3[50] = "FRASE EXTENSA";
    int complong = compXlong(c1, c3);
    int compLex = compLexic(c1, c2);
    printf("Comparacion de longitud: %d", complong);
    printf("\nComparacion lexicografica: %d", compLex);
    return 0;
}*/
