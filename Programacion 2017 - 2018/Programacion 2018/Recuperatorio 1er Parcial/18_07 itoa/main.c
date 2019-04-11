#include <stdio.h>
#include <stdlib.h>

char* __strlen(const char* s)
{
    while(*s)
        s++;
    return (char*)(s-1);
}

void _swap(char* a, char* b)
{
    char aux = *a;
    *a = *b;
    *b = aux;
}

char* invertir_cadena(char* cad)
{
    char* inicio = cad;
    char* fin = __strlen(cad);
    while(inicio<fin)
    {
        _swap(inicio, fin);
        inicio++;
        fin--;
    }
    return inicio;
}

char* __itoa(int n, char* cad, int base)
{
    char* inicio = cad;
    if(base < 10)
    {
        while(n>0)
        {
            *cad = (n%base)+'0';
            cad++;
            n/=base;
        }
    }
    else /// Base Hexa 16.
    {
        while(n>0)
        {
            if(n%base == 10)
                *cad = 'A';
            else if (n%base == 11)
                *cad = 'B';
            else if (n%base == 12)
                *cad = 'C';
            else if (n%base == 13)
                *cad = 'D';
            else if (n%base == 14)
                *cad = 'E';
            else if (n%base == 15)
                *cad = 'F';
            else
                *cad = (n%base)+'0';
            cad++;
            n/=base;
        }
    }
    *cad='\0';
    invertir_cadena(inicio);
    return inicio;
}

int main()
{
    char lote[10] = "";
    printf("Numero cadena: %s", __itoa(999, lote, 16));
    return 0;
}
