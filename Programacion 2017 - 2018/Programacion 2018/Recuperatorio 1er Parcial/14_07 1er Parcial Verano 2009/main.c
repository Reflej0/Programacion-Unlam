#include <stdio.h>
#include <stdlib.h>

char* consigna(char* cad)
{
    if(cad == NULL || *cad == '\0') return cad;
    char* inicio = cad;
    char* escritura = cad;
    char c;
    while(*cad == ' ')
        cad++;
    c = *cad;
    while(*cad)
    {
        if(*cad != c)
        {
            *escritura = *cad;
            escritura++;
        }
            cad++;
    }
    while(*escritura == ' ')
        escritura--;
    escritura++;
    *escritura = '\0';
    return inicio;
}

int main()
{
    char cad[100]="    ayer la mar estaba calma     ";
    char cad2[100];
    char* cad3 = NULL;
    char cad4[100] = "     aaaaaaaaaaaa     ";
    printf("--%s--", consigna(cad));
    return 0;
}
