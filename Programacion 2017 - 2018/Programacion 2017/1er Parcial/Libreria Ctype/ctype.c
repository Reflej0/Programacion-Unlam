#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ctype.h"

void toLower(char *cadena)
{
    int i;
    for(i=0;i<strlen(cadena); i++)
    {
        if(cadena[i] >='A' && cadena[i]<='Z')
        {
            cadena[i]+=32;
        }
    }
}

void toUpper(char *cadena)
{
    int i;
    for(i=0;i<strlen(cadena); i++)
    {
        if(cadena[i] >='a' && cadena[i]<='z')
        {
            cadena[i]-=32;
        }
    }
}
