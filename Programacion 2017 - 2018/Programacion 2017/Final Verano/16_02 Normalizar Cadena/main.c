#include <stdio.h>
#include <stdlib.h>

int _strlen(char* cad)
{
    int l = 0;
    while(*cad)
    {
        l++;
        cad++;
    }
    return l;
}

///PRIMERO TRIM, SUPRIMO ESPACIO DE MAS AL PRINCIPIO Y AL FINAL.
char* trim(char* cad)
{
    char* r = (char*)malloc((sizeof(char)*_strlen(cad))+1);
    int i = 0;
    int flag_primer_espacio = 0;
    while(*cad)
    {
        if(*cad == ' ' && flag_primer_espacio == 0)
        {
            cad++;
        }
        else
        {
            flag_primer_espacio++;
            *r = *cad;
            r++;
            cad++;
            i++;
        }
    }
    *r ='\0'; // FINALIZO LA CADENA.
    flag_primer_espacio = 0;
    r--;
    while(i > 0 && flag_primer_espacio == 0)
    {
        if(*r == ' ')
        {
            r--;
            i--;
        }
        else
        {
            flag_primer_espacio = 1;
        }
    }
    *r = '\0';
    return r-i+1;
}

char* normalizar_cadena(char* cad)
{
    char* r = (char*)malloc(sizeof(char)*_strlen(cad)+1);
    int primeraletrapalabra = 1;
    int i = 0;
    while(*cad)
    {
        if((*cad >= 'a' && *cad <='z') || (*cad >= 'A' && *cad <= 'Z') || (*cad >= '0' && *cad<='9') || *cad == ' ' || *cad == '.')
        {
            *r = *cad;
            if(primeraletrapalabra == 1 && (*cad >= 'a' && *cad <='z'))
            {
                *r = (*cad-32);
            }
            if(primeraletrapalabra == 0 && (*cad >= 'A' && *cad <='Z'))
            {
                *r = (*cad+32);
            }
            r++;
            i++;
        }
        if(*cad == ' ' || *cad == '.' || *cad == '*' || *cad == ')' || *cad == '_' || *cad == '<' || *cad == '>' || *cad == '!' || *cad == '@' || *cad == '#')
        {
            primeraletrapalabra = 1;
        }
        else
        {
            primeraletrapalabra = 0;
        }
        cad++;
    }
    *r = '\0';
    r-= i;
    return r;
}

int main()
{
    char* cad = "  *hOla )_SoY.<>una CadenA no!@#Normalizadaa            ";
    ///SALIDA: Hola soy. Una cadena no normalizada
    char* cadena_normalizada = trim(cad);
    cadena_normalizada = normalizar_cadena(cadena_normalizada);
    printf("%s", cadena_normalizada);

    //printf("c");
}
