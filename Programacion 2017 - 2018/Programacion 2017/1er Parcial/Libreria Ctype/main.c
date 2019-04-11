#include <stdio.h>
#include <stdlib.h>
#include "ctype.h"

int main()
{
    char cadena[] = "HOLA MUNDO";
    toLower(cadena);
    printf("%s", cadena);
    toUpper(cadena);
    printf("\n%s", cadena);
}
