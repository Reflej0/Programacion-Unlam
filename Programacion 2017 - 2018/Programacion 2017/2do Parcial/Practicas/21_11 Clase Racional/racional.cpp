#include "racional.h"
#include "stdio.h"
#include "string.h"
#include "stdlib.h"

Racional::Racional()
{
    this->numerador = 1;
    this->denominador = 1;
    this->signo = 1;
}

Racional::Racional(const float numero)
{
    //CONVERSION A CHAR*
    char numero_string[15] = "";
    sprintf(numero_string, "%f", numero);
    //DETECCION SIGNO
    if(numero < 0)
    {
        this->signo = -1;
    }
    else
    {
        this->signo = 1;
    }

    //DETECCION DE PUNTO.
    char* punto = strchr(numero_string, '.');
    //Si no tiene punto, es decir es un numero entero.
    if(!punto)
    {
        this->numerador = (int)numero;
        this->denominador = 1;
        return;
    }
    //Si tiene punto, es decir es un numero decimal.
    char *endptr;
    long partedecimal = strtod(punto+1, &endptr);
    long denominador = 10000000;
    long numerador = abs(numero)*denominador + (partedecimal*10);
    int mcd = MCD(numerador, denominador);
    this->numerador = numerador/mcd;
    this->denominador = denominador/mcd;
    return;
}

void Racional::operator+=(const Racional& otro)
{
    unsigned mcm = MCM(this->denominador, otro.denominador);
    int num1 = (this->numerador)*mcm / this->denominador;
    int num2 = (otro.numerador)*mcm / otro.denominador;
    int numerador = (num1*this->signo) + (num2*otro.signo);
    if(numerador < 0)
    {
        this->signo = -1;
    }
    else
    {
        this->signo = 1;
    }
    this->numerador = abs(numerador);
    this->denominador = mcm;;
    this->Simplificar();
}

void Racional::Simplificar()
{
    int mcd = MCD(this->numerador, this->denominador);
    this->numerador /= mcd;
    this->denominador /= mcd;
}

unsigned Racional::getNumerador()const
{
    return this->numerador;
}

unsigned Racional::getDenominador()const
{
    return this->denominador;
}

int Racional::getSigno()const
{
    return this->signo;
}

int Racional::MCD(int a, int b)
{
    if(b == 0)
    {
        return a;
    }
    return MCD(b, a%b);
}

int Racional::MCM(int a, int b)
{
    if(a== 0 || b == 0)
    {
        return 0;
    }
    return (a/MCD(a,b)*b);
}
