#include <stdio.h>
#include <stdlib.h>
#include "normalizacion_cadenas.h"
int main()
{
    char cadena[] = ",. \thOLA ;.mUndO  \t:@\0";
    normalizar_cadena(cadena);
}
