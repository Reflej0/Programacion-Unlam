#include "racional.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

///Constructor por defecto.
Racional::Racional()
{
    this->numerador = 1;
    this->denominador = 1;
    this->signo = 1;
}

///Constructor del racional en base a un decimal.
Racional::Racional(const float numero)
{
    ///CONVERSION FLOAT -> STRING.
    char cadena[15]; //Variable auxiliar para pasar el num decimal a char*.
    sprintf(cadena, "%f", numero); // Proceso de conversion.

    ///DETECCION DE FLOAT SIN PARTE DECIMAL O CON PARTE DECIMAL.
    char* punto = strchr(cadena, '.');

    ///DETECCION DE NEGATIVO SIN IMPORTAR SI TIENE PARTE DECIMAL O NO.
    if(numero<0)
    {
        this->signo = -1;
    }
    else
    {
        this->signo = 1;
    }

    ///SI ES UN FLOAT SIN PARTE DECIMAL.
    if(punto == NULL)
    {
        this->numerador = numero;
        this->denominador = 1;
    }

    ///SI ES UN FLOAT CON PARTE DECIMAL.
    else
    {
        char* endptr;
        long partedecimal = strtod((punto+1),&endptr); // Obtengo la parte decimal del numero.
        long denominador = 10000000; //Es la cantidad maxima de 0 del float.
        long numerador = ((abs(numero)*denominador)+(partedecimal*10));
        ///ENCUENTRO EL MAXIMO COMUN DIVISOR.
        int mcd = MCD(numerador, denominador);
        this->denominador = denominador / mcd;
        this->numerador = numerador / mcd;
    }

}
///GETTER DEL NUMERADOR.
unsigned Racional::getNumerador()const
{
    return this->numerador;
}
///GETTER DEL DENOMINADOR.
unsigned Racional::getDenominador()const
{
    return this->denominador;
}
///GETTER DEL SIGNO.
int Racional::getSigno()const
{
    return this->signo;
}
///Suma de fracciones.
void Racional:: operator+=(const Racional& num)
{
    //Obtengo el Minimo Comun Multiplo de ambos denominadores.
    int mcm = MCM(this->denominador, num.denominador);
    //Obtengo el nuevo numerador del primer numero.
    int num1 = (mcm / this->denominador) * this->numerador;
    //Obtengo el nuevo denominador del segundo numero.
    int num2 = (mcm / num.denominador) * num.numerador;
    //Construyo el nuevo numerador.
    int nuevo_numerador = (this->signo)*(num1)+(num.signo)*(num2);
    this->numerador = abs(nuevo_numerador);
    //Tengo que evaluar si la suma pudo haber dado negativa.
    if(nuevo_numerador<0)
    {
        this->signo = -1;
    }
    else
    {
        this->signo = 1;
    }
    this->denominador = mcm;
    this->Simplificar(); // Simplifico la fraccion resultante.
}

///Resta de fracciones.
void Racional:: operator-=(const Racional& num)
{
    //Obtengo el Minimo Comun Multiplo de ambos denominadores.
    int mcm = MCM(this->denominador, num.denominador);
    //Obtengo el nuevo numerador del primer numero.
    int num1 = (mcm / this->denominador) * this->numerador;
    //Obtengo el nuevo denominador del segundo numero.
    int num2 = (mcm / num.denominador) * num.numerador;
    //Construyo el nuevo numerador.
    int nuevo_numerador = (this->signo)*(num1)-(num.signo)*(num2);
    this->numerador = abs(nuevo_numerador);
    //Tengo que evaluar si la resta pudo haber dado negativa.
    if(nuevo_numerador<0)
    {
        this->signo = -1;
    }
    else
    {
        this->signo = 1;
    }
    this->denominador = mcm;
    this->Simplificar(); // Simplifico la fraccion resultante.
}

///Multiplicacion de fracciones.
void Racional:: operator*=(const Racional &num)
{
    this->numerador = (this->numerador) * num.getNumerador();
    this->denominador = (this->denominador) * num.getDenominador();
    this->signo = (this->signo) * num.getSigno();
    this->Simplificar(); // Simplifico la fraccion resultante.
}

///Division de fracciones.
void Racional:: operator/=(const Racional &num)
{
    this->numerador = (this->numerador) * num.getDenominador();
    this->denominador = (this->denominador) * num.getNumerador();
    this->signo = (this->signo) * num.getSigno();
    this->Simplificar(); // Simplifico la fraccion resultante.
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
///Simplifica un objeto racional.
void Racional::Simplificar()
{
    int mcd = MCD(this->numerador, this->denominador);
    this->denominador = denominador / mcd;
    this->numerador = numerador / mcd;
}
