#include <stdio.h>
#include <stdlib.h>
#include "cadenas.h"

int main()
{
    char* cad = "Hola hay olasolas que se van sin decir HoLa entonces adios olasolas, ojala ola";

    int l = _strlen(cad);
    int i = 0;
    int flagprimerapalabra = 0;
    char* aux = (char*)malloc(sizeof(char)*21);
    char* sinola = (char*)malloc(sizeof(char)*l+1);
    int avance = 0;
    int repeticiones = 0;
    ///Repeticiones de ola: 5.
    while/*(*cad)*/(i < l+1)
    {
        if(*cad != ' ' && *cad!='\0')
        {
            *aux = *cad;
            aux++;
            avance++;
        }
        else
        {
            *aux = '\0';
            repeticiones += comparador(aux-avance, "OLA");
            if(comparador(aux-avance, "OLA") != 1 && flagprimerapalabra > 0)
            {
                _strcat(sinola, " ");
                _strcat(sinola, aux-avance);
            }
            if(comparador(aux-avance, "OLA") != 1 && flagprimerapalabra == 0)
            {
                _strcpy(sinola, aux-avance);
                flagprimerapalabra++;
            }
            aux-=avance;
            avance = 0;
        }
        cad++;
        i++;
    }
    printf("%s\n", sinola);
    printf("La cantidad de apariciones es: %d", repeticiones);
}
