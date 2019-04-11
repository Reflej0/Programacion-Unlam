#include <stdio.h>
#include <stdlib.h>

void _strcpy(char* des, char* src)
{
    while(*src)
    {
        *des = *src;
        src++;
        des++;
    }
    *des = '\0';
}

///Identico a strlen de string.h
size_t _strlen(char* cad)
{
    size_t l = 0;
    while(*cad)
    {
        l++;
        cad++;
    }
    return l; // Por el \0;
}

///Metodo para encontrar la cantidad de ocurrencias
///de un caracter en una cadena.
unsigned int ocurrencias(char* cad, char c)
{
    unsigned int apariciones = 0;
    while(*cad)
    {
        if(*cad == c)
        {
            apariciones++;
        }
        cad++;
    }
    return apariciones;
}


///Metodo para devolver una cadena sin espacio.
char* sinEspacios(char* cad)
{
    int tam = _strlen(cad);
    int espacios_totales = ocurrencias(cad, ' ');
    char* retorno = malloc(tam);
    while(*cad)
    {
        if(*cad != ' ')
        {
            *retorno = *cad;
            retorno++;
        }
        cad++;
    }
    *retorno = '\0';
    retorno-=(tam-espacios_totales);
    return retorno;
}

///Metodo para pasar una cadena a minusculas.
char* aMinusculas(char* cad)
{
    int tam = _strlen(cad);
    char* minus = malloc(tam);
    while(*cad)
    {
        if(*cad >= 'A' && *cad<= 'Z')
        {
            *minus = (*cad+32);
        }
        else
        {
            *minus = *cad;
        }
        cad++;
        minus++;
    }
    *minus = '\0';
    minus-=tam;
    return minus;
}

///Usando la misma cadena pero vector[i]
///Metodo para comprobar si una cadena es palindromo.
int esPalindromo(char* cad)
{
    int tam = _strlen(cad);
    int i;
    for(i=0; i<(tam/2); i++)
    {
        if(cad[i] != cad[tam-1-i])
        {
            return 0;
        }
    }
    return 1;
}
///Usando cadena auxiliar pero con arimetica de punteros.
///Metodo para comprobar si una cadena es palindromo.
int esPalindromo2(char* cad)
{
    int tam = _strlen(cad);
    char* _cad = malloc(tam+1); // Cadena auxiliar.
    _strcpy(_cad, cad); // Copio la misma cadena.
    _cad+=(tam-1); // En la cadena auxiliar empiezo de atras, para no invertir la cadena.
    int i;
    for(i=0; i<(tam/2); i++)
    {
        if(*cad == *_cad)
        {
            return 0;
        }
        cad++;
        _cad--;
    }
    return 1;
}

int main()
{
    ///Palindromos.
    char* cad1 = "Anita Lava La tina";
    char* cad2 = "Neuquen";
    char* cad3 = "anita lava la tina";
    char* cad4 = "1001";
    ///No-Palindromo.
    char* cad5 = "Anita Lava la tinax";
    ///Primero saco los espacios de la cadena, despues paso todo a minusculas.
    printf("Palindromo:%d", esPalindromo(aMinusculas(sinEspacios(cad5))));
}
