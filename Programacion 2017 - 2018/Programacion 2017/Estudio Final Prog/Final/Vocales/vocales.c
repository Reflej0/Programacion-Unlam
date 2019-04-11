#include <stdio.h>
#include <stdlib.h>
#include "vocales.h"

int cantidad_palabras_4_mas_vocales(char* frase)
{
    int vocales = 0;
    int palabrascon4omasvocales = 0;
    ///CONDICION DE CORTE *frase o *frase != '\0'
    while(*frase)
    {
        ///MIENTRAS QUE ESTE EN UNA PALABRA.
        while((*frase >= 'a' && *frase <='z') || (*frase >= 'A' && *frase <='Z') || (*frase >= '0' && *frase <='9'))
        {
            ///PARA EVITAR UN IF TAN LARGO SE PODRIA PASAR A MAYUSCULA O MINUSCULA.
            if(*frase == 'a' || *frase == 'e' || *frase == 'i' || *frase == 'o' || *frase == 'u' || *frase == 'A' || *frase == 'E'  || *frase == 'I' || *frase == 'O' || *frase == 'U')
            {
                vocales++;
            }
            ///AVANZO DE CARACTER.
            frase++;
        }
        ///SI CUMPLE LA CONSIGNA.
        if(vocales >= 4)
        {
            palabrascon4omasvocales++;
        }
        ///SI DEJE DE ESTAR EN UNA PALABRA RESETEO EL CONTADOR DE VOCALES Y AVANZO DE CARACTER.
        vocales = 0;
        frase++;
    }
    return palabrascon4omasvocales;
}
