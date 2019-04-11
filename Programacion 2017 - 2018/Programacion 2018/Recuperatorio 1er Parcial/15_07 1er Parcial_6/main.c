#include <stdio.h>
#include <stdlib.h>
#define ES_LETRA_ESPACIO(c) (((c>='a' && c<='z') || (c>='A' && c<='Z') || (c==' ')) ? 1 : 0)
#define ES_LETRA(c) (((c>='a' && c<='z') || (c>='A' && c<='Z')) ? 1 : 0)
#define ES_NUMERO(c) ((c>='0' && c<='9') ? 1 : 0)
#define TOUPPER(c) ((c>='a' && c<='z') ? (c-32) : (c))
#define TOLOWER(c) ((c>='A' && c<='Z') ? (c+32) : (c))

int separar (char *calle, char *nume, char *resto, const char *domi)
{
    int correcto = 0;
    if(!domi || !*domi) return -1;
    const char* inicio = domi;
    while(!ES_NUMERO(*domi))
    {
        *calle = *domi;
        domi++;
        calle++;
    }
    *calle = '\0';
    if(inicio == domi) return -1; ///Si no entro al while anterior ya escribieron mal al principio.
    while(ES_NUMERO(*domi))
    {
        *nume = *domi;
        domi++;
        nume++;
        correcto = 1;
    }
    *nume = '\0';
    while(*domi)
    {
        *resto = *domi;
        domi++;
        resto++;
        correcto = 0;
    }
    *resto = '\0';
    return correcto;
}

char* normalizar_titulo(char* titulo)
{
    if(!titulo || !*titulo) return titulo;
    char* inicio = titulo;
    char* escritura = titulo;
    while(*titulo == ' ')
        titulo++;
    while(!ES_LETRA(*titulo) && !ES_NUMERO(*titulo))
        titulo++;
    *escritura = TOUPPER(*titulo);
    titulo++;
    escritura++;
    while(*titulo)
    {
        if(ES_LETRA(*titulo))
        {
            *escritura = TOLOWER(*titulo);
            escritura++;
        }
        if(*titulo == ' ')
        {
            *escritura = *titulo;
            escritura++;
            titulo++;
            *escritura = TOUPPER(*titulo);
            escritura++;
        }
        titulo++;
    }
    while(*escritura == ' ')
        escritura--;
    escritura++;
    *escritura = '\0';
    return inicio;
}

int main()
{
    char ti1[55] = "   a/*L*/*/g**/O mUy MaL eScRiTo";
    char ti2[55] = "porotos blancos";
    printf("%s", normalizar_titulo(ti1));
    return 0;
}

/*int main()
{
    char domi1[50]="Perdida s/n e/Monte y Aráoz";
    char domi2[50]="Presidente Perón 1704";
    char domi3[50]="Rivadavia 23902";
    char domi4[50]="Pampa 1704 3ro A";
    char domi5[50]="Rivadavia 123902";
    char calle[50]="";
    char num[50]="";
    char otro[50]="";
    int resu = separar(calle, num, otro, domi4);
    printf("CALLE:%s\nNUM:%s\nOTRO:%s\nRESU:%d", calle, num, otro, resu);
    return 0;
}*/
