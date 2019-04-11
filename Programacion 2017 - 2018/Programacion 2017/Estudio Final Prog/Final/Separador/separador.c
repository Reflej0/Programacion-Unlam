#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "separador.h"

void reemplazar_separador(char* frase)
{
    ///MIENTRAS QUE NO LLEGUE AL FINAL.
    while(*frase)
    {
        ///SI EL CARACTER NO ESTA DENTRO de a-z A-Z 0-9, entonces es un separador.
        if(!((*frase >= 'a' && *frase <='z') || (*frase >= 'A' && *frase <='Z') || (*frase >= '0' && *frase <='9')))
        {
            *frase = ';';
        }
        frase++;
    }
}
