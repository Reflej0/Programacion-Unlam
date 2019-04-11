#include <stdio.h>
#include <stdlib.h>

///12 MINUTOS.

char _toUpper(char c)
{
    return (c>='a' && c<='z') ? c-=32 : c;
}

size_t _strlen(const char* s)
{
    size_t l = 0;
    while(*s)
    {
        l++;
        s++;
    }
    return l;
}

int _strstr(char* s1, const char* s2)
{
    int pos = 1;
    int coincidencia = 0;
    int l2 = _strlen(s2);
    while(*s1)
    {
        if(_toUpper(*s1) == _toUpper(*s2))
        {
            coincidencia++;
            s2++;
            if(coincidencia == l2)
                return pos-coincidencia;
        }
        else
        {
            s2-= coincidencia;
            coincidencia = 0;
        }
        s1++;
        pos++;
    }
    return -1;
}

int main()
{
    char s1[] = "La casa es grande";
    char s2[] = "casa en";
    char s3[] = "casa e";
    char s4[] = "La casa es grande y linda";
    char s5[] = "grande";
    char s6[] = "es";
    int resultado = _strstr(s1, s3);
    printf("Resultado: %d", resultado);
    return 1;
}
