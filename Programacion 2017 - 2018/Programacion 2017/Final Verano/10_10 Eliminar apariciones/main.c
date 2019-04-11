#include <stdio.h>
#include <stdlib.h>

int _strlen(char* cad) // YO.
{
    int l = 0;
    while(*cad)
    {
        l++;
        cad++;
    }
    return l;
}

char* _strstr(char* cadena, char* abuscar) // YO.
{
    int lon = _strlen(abuscar);
    int i = 0;
    while(*cadena)
    {
        i = 0;
        while(*cadena == *abuscar)
        {
            i++;
            cadena++;
            abuscar++;
            if(i == lon)
            {
                return cadena-=i; // Si quiero que me muestre a partir de donde lo encontro.
            }
        }
        cadena++;
        abuscar-=i;
    }
    return NULL;
}

void _strcat(char* dest, char* con)
{
    while(*dest)
    {
        dest++;
    }
    while(*con)
    {
        *dest = *con;
        dest++;
        con++;
    }
    *dest = '\0';
}

void removeSubstr (char *string, char *sub) {
    char *match;
    int len = _strlen(sub);

    while ((match = _strstr(string, sub))) {
        *match = '\0';
        _strcat(string, match+len);
    }
}

int main()
{
    char frase[] = "Hola soy como las OlAs que dicen hola, donde olas chau OLAS.";
    removeSubstr(frase, "OlA");
    printf("%s", frase);
}
