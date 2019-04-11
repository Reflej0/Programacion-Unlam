#include <stdio.h>
#include <stdlib.h>

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

char* insertar_espacios(char* cad)
{
    int i = 0;
    int signos = 0;
    ///RECORRO Y CUENTO LA CANTIDAD DE . y ,
    while(*cad)
    {
        if(*cad == '.' || *cad == ',')
        {
            signos++;
        }
        i++;
        cad++;
    }
    cad-=i;
    ///CREO UN NUEVO CHAR* CON UN ESPACIO APROXIMADO.
    char* r = (char*)malloc((sizeof(char)*i)+signos);
    i = 0;
    char c;
    while(*cad)
    {
        *r = *cad;
        c = *(cad+1);
        if((*cad == '.' || *cad == ',') && c != ' ')
        {
            r++;
            *r = ' ';
            i++;
        }
        cad++;
        r++;
        i++;
    }
    *r = '\0';
    r-=i;
    return r;
}

char* normalizar_letras(char* cad)
{
    char* r = (char*)malloc(sizeof(char)*_strlen(cad)+1);
    ///PRIMERA LETRA.
    int pl = 1;
    int i = 0;
    while(*cad)
    {
        *r = *cad;
        if(pl == 1 && (*cad >='a' && *cad <='z'))
        {
            *r = (*cad-32);
        }
        if(pl == 0 && (*cad >='A' && *cad <='Z'))
        {
            *r = (*cad+32);
        }
        if(*(cad) == ' ' && *(cad-1) == '.')
        {
            pl = 1;
        }
        else
        {
            pl = 0;
        }
        cad++;
        r++;
        i++;
    }
    *r = '\0';
    r-=i;
    return r;
}

int main()
{
    char * cad = "Hola,soy,UNA,frase.Que no tiene, tantos espacIOs adecuados. por ende,FALLO con. normalidad";
    //SALIDA: Hola, soy una frase. Que no tiene, tantos espacios adecuados.
    char* espacios_normalizados = insertar_espacios(cad);
    char* letras_normalizadas = normalizar_letras(espacios_normalizados);
    printf("%s", letras_normalizadas);
}
