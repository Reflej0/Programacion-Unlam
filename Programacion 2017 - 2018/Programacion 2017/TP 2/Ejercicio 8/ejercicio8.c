#include <stdio.h>
#include <stdlib.h>
#include "ejercicio8.h"

size_t ingresar_texto(char *text)
{
    size_t tamano = 0;
    printf("Ingrese un texto, separelo con .\nTexto:");
    gets(text);
    while(text[tamano]!='\0')
    {
        tamano++;
    }
    return tamano++; //Para agregar el \0.
}

void primera_palabra(char *text)
{
    int caracteres_primera_palabra = 0; // Esta variable contiene la cantidad de caracteres de la primera palabra.
    char primera_palabra[TAM]; //Esta variable guarda la primera palabra.
    while(((text[caracteres_primera_palabra]!='\0') && (text[caracteres_primera_palabra]!='.'))) //Este ciclo donde termina la primera palabra.
    {
        caracteres_primera_palabra++;
    }
    printf("La primera palabra es:");
    for(int j = 0; j<caracteres_primera_palabra;j++)
    {
        primera_palabra[j] = text[j];
        printf("%c", primera_palabra[j]);
    }
}

void palabras_texto(char *text)
{
    int maxima_longitud = 0; //Esta variable guarda la longitud de la palabra mas larga.
    char palabras_totales[TAM][TAM]; // Tengo que hacer una reserva de memoria grande por las dudas.
    int caracteres_palabras[TAM]; // Con este vector guardo la cantidad de letras de cada palabra.
    int i = 0, k = 0, z = 0; //Variables auxiliares.
    while((text[i]!='\0')) // Voy recorriendo el texto hasta que termine.
    {
        palabras_totales[k][z] = text[i]; // Voy guardando las palabras totales.
        if(text[i] == '.') // Si hay un punto cambio de palabra.
        {
            caracteres_palabras[k] = z;
            k++; //La variable k guarda la cantidad de palabras.
            z = 0; //La variable z guarda la cantidad de caracteres de la palabra actual.
        }
        z++;
        i++;
    }
    for(int t=0;t<k;t++)
    {
        if(maxima_longitud<caracteres_palabras[t])
        {
            maxima_longitud = caracteres_palabras[t];
        }
    }
    printf("\nCantidad de palabras en el texto:%d", k);
    printf("\nLa palabra mas larga tiene %d caracteres", maxima_longitud);
}
