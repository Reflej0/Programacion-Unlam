#include <iostream>
#include "racional.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Racional::Racional(double numero)
{
    int signo = 1;
    if(numero<0)
    {
        signo = -1;
    }
    char c_numero[30]; // Variable auxiliar que contiene el numero decimal en formato char.
    sprintf(c_numero, "%f", numero); // FLOAT -> CHAR*
    char* punto; // Variable auxiliar que contiene la direccion del punto si la hubiese.
    punto = strchr(c_numero, '.'); // Busqueda del punto.
    ///Caso en el que el numero introducido en realidad sea un entero.
    if(punto == NULL)
    {
        this->numerador = numero;
        this->denominador = 1;
        this->signo = signo;
        return;
    }
    ///Caso en el que el numero introducido tiene punto.
    else
    {
        char *p_numero = c_numero;
        while(*p_numero) // Recorro todo el numero en formato char.
        {
            if(*p_numero == '.') // Le elimino el punto.
            {
                printf("p_numero:%c", *p_numero);
                system("PAUSE");
                *c_aux_numero = *p_numero;
            }
            p_numero++;
        }
        this->numerador = atoi(c_aux_numero);
        int ceros[] = {0, 10, 100, 1000, 10000, 100000, 1000000, 10000000};
        this->denominador = ceros[strlen(punto)];
        printf("NUMERADOR: %d", this->numerador);
        printf("NUMERADOR: %d", this->denominador);
        system("PAUSE");
    }
}

ostream& operator<<(ostream&sal, Racional& r)
{

}

///Método estático, no necesito de un objeto racional para invocarlo.
int Racional::MCD(int a, int b)
{
    if(b==0)
    {
        return a;
    }
    return MCD(b, a%b);
}
///Método estático, no necesito de un objeto racional para invocarlo.
int Racional::MCM(int a, int b)
{
    if(a== 0 || b==0)
    {
        return 0;
    }
    return (a / MCD(a,b)* b);
}
