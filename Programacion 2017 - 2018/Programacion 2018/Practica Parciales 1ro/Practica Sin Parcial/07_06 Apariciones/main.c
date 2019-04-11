#include <stdio.h>
#include <stdlib.h>

char* strcpy(char* dest, const char* src)
{
    char* inicio = dest;
    while(*src)
    {
        *dest = *src;
    }
    *dest = '\0';
    return inicio;
}

size_t strlen(const char* s)
{
    size_t l = 0;
    while(*s)
    {
        l++;
        s++;
    }
    return l;
}

char* reemplazar_subcadena(char* s, const char* t, const char* r)
{
    size_t l = strlen(t);
    char aux[strlen(s)];
    int coincidencias = 0;
    while(*s)
    {
        if(*s == *t)
        {
            if(coincidencias == l)
            {

            }
        }
    }
}

int main()
{
    char s[100] = "ana lana pana a veces retrocede sana";
    char t[] = "ana";
    char r[] = "soleado";
    printf(reemplazar_subcadena());
}
