#include <stdio.h>
#include <stdlib.h>

int es_Letra(const char c)
{
    if((c >='a' && c<='z') || (c >='A' && c<='Z'))
        return 1;
    return 0;
}

int es_Espacio(const char c)
{
    if(c==' ')
        return 1;
    return 0;
}

char toUpper(char c)
{
    if(c >='a' && c<='z')
        return c-=32;
    return c;
}

char toLower(char c)
{
    if(c >='A' && c<='Z')
        return c+=32;
    return c;
}

char* normalizar_nya(char* nya)
{
    char* inicio = nya;
    char* l=nya;
    char* e=nya;
    int letra = 0;
    while(*l)
    {
        if(es_Letra(*l))
        {
            if(letra == 0)
                *e = toUpper(*l);
            else
            *e = toLower(*l);
            e++;
            letra = 1;
        }
        if(es_Espacio(*l) && letra!=0)
        {
            *e = *l;
            e++;
            letra = 0;
        }
        l++;
    }
    while(!es_Letra(*e))
    {
        e--;
    }
    e++;
    *e = '\0';
    return inicio;
}

int main()
{
    char nya[] = "  *@!#_)*(j!#Ua*N @!4t0123Ocin!0O       ";
    printf("*%s*", normalizar_nya(nya));
    return 1;
}
