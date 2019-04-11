#include <stdio.h>
#include <stdlib.h>
#define ES_ALFANUMERICO(c) ((c>='a' && c<='z') || (c>='A' && c<='Z') || (c>='0' && c<='9')) ? 1 : 0
#define ES_ESPACIO(c) (c==' ') ? 1 : 0

void normalizar_cadena_full(char* cad)
{
    char* aux = cad;
    while(*aux && ES_ESPACIO(*aux))
    {
            aux++;
    }
    while(*aux)
    {
        if(ES_ALFANUMERICO(*aux) || ES_ESPACIO((*aux)))
        {
           *cad = *aux;
           cad++;
        }
        aux++;
    }
    cad--;
    while(ES_ESPACIO(*cad))
    {
        cad--;
    }
    cad++;
    *cad = '\0';
}

int main()
{
    char cad[] = "";
    normalizar_cadena_full(cad);
    printf("%s", cad);
}
