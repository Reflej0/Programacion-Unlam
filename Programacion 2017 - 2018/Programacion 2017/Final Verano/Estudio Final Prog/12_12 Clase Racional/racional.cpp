#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "racional.h"
#define PRECISION 10

///Constructor, recibe como parametro un float y construye un numero fraccionario.
Racional::Racional(float numero)
{
    ///Si el numero es negativo, entonces establezco el signo en -1.
    if(numero < 0)
    {
        this->signo = -1;
    }
    else
    {
        this->signo = 1;
    }
    char numero_char[PRECISION] = "";
    //Paso el numero a char*
    sprintf(numero_char, "%f", numero);
    //Busco si hay un punto.
    char* punto = strchr(numero_char, '.');
    ///Si no hay un punto.
    if(!punto)
    {
        this->numerador = numero;
        this->denominador = 1;
        return;
    }
    ///Si tiene un punto.
    else
    {
        char* pEnd; //Variable auxiliar.
        ///Establezco el denominador por default es la maxima precision del float.
        this->denominador = 1000000;
        ///El numerador es la parte entera*denominador + la parte decimal.
        this->numerador = abs((int)numero*1000000)+strtod(punto+1, &pEnd);
        ///En este punto tengo la fraccion sin simplificar.
        int mcd = MCD(this->numerador, this->denominador);
        this->numerador /= mcd;
        this->denominador /= mcd;
        return;
    }
}
///Este constructor sirve para construir un fraccionario simplificado a partir de un fraccionario sin simplificar.
Racional::Racional(unsigned numerador, unsigned denominador, int signo)
{
    this->numerador = numerador;
    this->denominador = denominador;
    this->signo = signo;
    this->Simplificar();
}

Racional Racional::operator+(const Racional &otro)
{
    ///Encuentro el minimo comun multiplo, que va a ser el nuevodenominador.
    unsigned nuevodenominador = MCM(this->denominador, otro.denominador);
    int nuevonumerador = ((this->numerador)*(nuevodenominador/this->denominador)*this->signo) + ((otro.numerador)*(nuevodenominador/otro.denominador)*otro.signo);
    int signo = 1;
    if(nuevonumerador < 0)
    {
        signo = -1;
    }
    ///Creo el nuevo racional a devolver ya que no se modifica el this ni el otro.
    Racional retorno(nuevonumerador, nuevodenominador, signo);
    return retorno;
}

Racional Racional::operator-(const Racional &otro)
{
    ///Encuentro el minimo comun multiplo, que va a ser el nuevodenominador.
    unsigned nuevodenominador = MCM(this->denominador, otro.denominador);
    int nuevonumerador = ((this->numerador)*(nuevodenominador/this->denominador)*this->signo) - ((otro.numerador)*(nuevodenominador/otro.denominador)*otro.signo);
    int signo = 1;
    if(nuevonumerador < 0)
    {
        signo = -1;
    }
    ///Creo el nuevo racional a devolver ya que no se modifica el this ni el otro.
    Racional retorno(nuevonumerador, nuevodenominador, signo);
    return retorno;
}

Racional Racional::operator*(const Racional &otro)
{
    unsigned nuevonumerador = this->numerador*otro.numerador;
    unsigned nuevodenominador = this->denominador*otro.denominador;
    int signo = this->signo * otro.signo;
    ///Creo el nuevo racional a devolver ya que no se modifica el this ni el otro.
    Racional retorno(nuevonumerador, nuevodenominador, signo);
    return retorno;
}

Racional Racional::operator/(const Racional &otro)
{
    unsigned nuevonumerador = this->numerador*otro.denominador;
    unsigned nuevodenominador = this->denominador*otro.numerador;
    int signo = this->signo * otro.signo;
    ///Creo el nuevo racional a devolver ya que no se modifica el this ni el otro.
    Racional retorno(nuevonumerador, nuevodenominador, signo);
    return retorno;
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

///Metodo que simplifica un fraccionario.
void Racional::Simplificar()
{
    int mcd = MCD(this->numerador, this->denominador);
    this->numerador /= mcd;
    this->denominador /= mcd;
}

ostream& operator<<(ostream& sal, Racional otro)
{
    char c;
    if(otro.signo == -1)
    {
        c = '-';
    }
    else
    {
        c = '+';
    }
    sal << c << otro.numerador << '/' << otro.denominador;
    return sal;
}
