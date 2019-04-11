#include <iostream>
#include <stdlib.h>
#include <cmath>

#include "racional.h"

using namespace std;

//************************ CONSTRUCTORES
Racional::Racional()
{
    this->numerador=0;
    this->denominador=1;
}
Racional::Racional(int numerador,int denominador)
{
    int div;
    this->numerador=numerador;
    this->denominador=denominador;
    if(this->denominador < 0)
    {
        this->denominador*=-1; // LE SACO EL SIGNO
        this->numerador*=-1; // LE PONGO EL NEGRATIVO AL NUMERADOR
    }

}
//********************************************************** PARA MOSTRAR
ostream& operator<<(ostream& os,Racional& racional)
{
    os<<racional.numerador<<"/"<<racional.denominador<<endl;
    return os;
}

//****************************** MCD
int mcd(int n,int d)
{
    int aux;
    int maxi; // RECORRE NUMEROS DESDE EL 0
    int maxDiv=1; // MANTIENE AL QUE DIVIDE LOS DOS
    int tope; // COPIA DEL NUMERO MAS GRANDE
    int comp1;
    int comp2;
    if(n<0)
        n=n*(-1); // DEBEN SER POSITIVOS
    if(d<0)
        d=d*(-1); // DEBEN SER POSITIVOS
    if(n==0 && d==0)
    {
        aux=0;
        return aux;
    }
    if(n==0)
    {
        aux=d;
        return aux;
    }

    if(d==0)
    {
        aux=n;
        return aux;
    }

    if(n>d)
        tope=n; // GUARDO EL MENOR
    if(d<n)
        tope=d; // GUARDO EL MENOR
    if(d==n)
    {
    aux=d;
    return aux;
    }

    maxi=0;
    while(maxi<=tope)
    {
        comp1=d;
        comp1=comp1%maxi;
        comp2=n;
        comp2=comp2%maxi;
        if((comp1)==0 && (comp2)==0)
        {
            maxDiv=maxi;
        }
        maxi++;
    }

    aux=maxDiv;
    return aux;

}

//***************************************************** IGUALACION
Racional& Racional::operator=(Racional& racional)
{
    int div;

    this->numerador=racional.numerador;
    this->denominador=racional.denominador;


    /*div=mcd(this->numerador,this->denominador);
    this->numerador=this->numerador/div;
    this->denominador=this->denominador/div;*/


    return *this;
}
//*********************************************** SUMA DE NUMERO CON RACIONAL
Racional& operator+(int n,Racional& racional)
{
    int div;
    Racional aux;
    aux.numerador=((n*racional.denominador)+racional.numerador);
    aux.denominador=racional.denominador;


    /*div=mcd(aux.numerador,aux.denominador);
    aux.numerador=aux.numerador/div;
    aux.denominador=aux.denominador/div;*/


    return aux;
}
//****************************************************SUMA DE RACIONALES
Racional& Racional::operator+(Racional& racional)
{
    Racional aux;
    int div;
    if(this->denominador!=racional.denominador)
    {
        aux.denominador=(this->denominador*racional.denominador);
        aux.numerador=(this->numerador*aux.denominador)+(racional.numerador*aux.denominador);
    }
    else
    {
        aux.denominador=this->denominador;
        aux.numerador=this->numerador+racional.numerador;
    }

    /*div=mcd(aux.numerador,aux.denominador);
    aux.numerador=aux.numerador/div;
    aux.denominador=aux.denominador/div;*/

    return aux;
}

//******************************* DESTRUCTOR
Racional::~Racional()
{
    //dtor.
}



