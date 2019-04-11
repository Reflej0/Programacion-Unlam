#include <stdio.h>
#include <stdlib.h>

void toLower(char* cadena)
{
    while(*cadena)
    {
        if(*cadena >= 'A' && *cadena <= 'Z')
        {
            *cadena = *cadena+32;
        }
        cadena++;
    }
}

void toUpper(char* cadena)
{
    while(*cadena)
    {
        if(*cadena >= 'a' && *cadena <= 'z')
        {
            *cadena = *cadena-32;
        }
        cadena++;
    }
}

int main()
{
    char palabra[10];
    printf("Ingrese una palabra:");
    scanf("%s", palabra);
    toUpper(palabra);
    printf("\n%s", palabra);
}
