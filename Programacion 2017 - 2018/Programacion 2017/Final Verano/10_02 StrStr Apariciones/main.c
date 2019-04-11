#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define TAM 20

int _strcmp(char* aux)
{
    char _ola[] = "OLA"; // SUBSTR A BUSCAR.
    int coincidencias = 0;
    int i = 0;
    while(*aux)
    {
        *aux = toupper(*aux); //PASO EL CARACTER A MAYUSCULA.
        if(*aux == _ola[i])
        {
            coincidencias++;
            aux++;
            i++;
        }
        else
        {
            coincidencias = 0;
            aux++;
            i = 0;
        }
        if(coincidencias == 3)
        {
            return 1;
        }
    }
    return 0;
}

int main()
{
    char* frase = "Hola soy como las OlAs que dicen hola, donde olas chau OLAS.";
    ///Contar la aparición del substr "ola" sin importar mayusculas y minusculas.
    ///Resultado final: 5.
    char aux[TAM]; // Variable auxiliar que va guardando las palabras.
    int i = 0;
    int repeticiones = 0; // Variable para contar las repeticiones.
    //Recorro la frase.
    while(*frase)
    {
        //Mientras no me tope con un espacio.
        if(*frase != ' ' && *frase!= '.')
        {
            aux[i] = *frase;
            i++;
        }
        //Si estoy acá es que me tope con un espacio en blanco.
        else
        {
            aux[i] = '\0';
            if(_strcmp(aux) == 1)
            {
                repeticiones++;
            }
            i = 0;
            aux[0] = '\0';
        }
        frase++;
    }
    printf("La cantidad de veces que aparecio:%d", repeticiones);
}


