#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void _toUpper(char* src)
{

    while(*src)
    {
        if(*src>='a' && *src<='z')
        {
            *src-=32;
        }
        src++;
    }
}

void _toLower(char* src)
{

    while(*src)
    {
        if(*src>='A' && *src<='Z')
        {
            *src+=32;
        }
        src++;
    }
}

int main()
{
    char str[] = "Mira mis cuentas: 03+01=4";
    _toUpper(str);
    printf("Mayusculas:%s", str);
    _toLower(str);
    printf("\nMinusculas:%s", str);
}
