#include <stdio.h>
#include <stdlib.h>

char* pos_fin(const char* s)
{
    char* fin = (char*)s;
    while(*fin)
    {
        fin++;
    }
    return --fin;
}

void intercambio_char(char *a, char *b)
{
    *a += *b;
    *b = *a-*b;
    *a -= *b;
}

char* invertir_cadena(char* s)
{
    char* inicio = s;
    char* fin = pos_fin(s);
    while(s<fin)
    {
        intercambio_char(s, fin);
        s++;
        fin--;
    }
    return inicio;
}

int main()
{
    char s[] = "Soleado";
    printf("%s", invertir_cadena(s));
    return 1;
}
