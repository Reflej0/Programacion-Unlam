#include <iostream>
#include "entero.h"
#include <stdlib.h>

///CONSTRUCTORES

Entero::Entero(const int numero, const bool positivo)
{
    this->numero = numero;
    this->positivo = positivo;
}

Entero::Entero(const int numero)
{
    if(numero>=0)
    {
        this->numero = numero;
        this->positivo = true;
    }
    else
    {
        this->numero = -numero;
        this->positivo = false;
    }

}

Entero::Entero(const Entero& e)
{
    this->numero = e.numero;
    this->positivo = e.positivo;
}

///GETS

int Entero::getNumero()const
{
    return this->numero;
}

bool Entero::getPositivo()const
{
    return this->positivo;
}

Entero Entero::operator+(const Entero& otro)const
{
    int n1 = ((this->positivo) ? 1 : -1)*this->numero;
    int n2 = ((otro.positivo) ? 1 : -1)*otro.numero;
    return Entero(n1+n2);
}

///UNARIOS PRE.

Entero& Entero::operator-() //Al ser PRE se define modificar el objeto llamador.
{
    this->positivo = !this->positivo;
    return *this;
}

Entero& Entero::operator+() // Se utiliza ya que matematicamente es valido.
{
    return *this;
}

///COMPARADORES.

bool Entero::operator==(const Entero& otro)const
{
    if(this->numero == otro.numero && this->positivo == otro.positivo)
        return true;
    return false;
}

bool Entero::operator!=(const Entero& otro)const
{
    if(this->numero == otro.numero && this->positivo == otro.positivo)
        return false;
    return true;
}

bool Entero::operator<(const Entero& otro)const
{
    return (((this->positivo) ? 1 : -1)* this->numero)<((otro.positivo) ? 1 : -1*otro.numero);
}

bool Entero::operator>(const Entero& otro)const
{
    return (((this->positivo) ? 1 : -1)* this->numero)>((otro.positivo) ? 1 : -1*otro.numero);
}

///FRIENDS.

ostream& operator<<(ostream& sal, const Entero& otro)
{
    return sal << ((otro.positivo) ? '+' : '-') << otro.numero;
}


istream& operator>>(istream& ent, Entero& otro)
{
    cout << "Ingrese numero:";
    ent >>otro.numero;
    if(otro.numero >= 0)
        otro.positivo = true;
    else
    {
        otro.numero*=-1;
        otro.positivo = false;
    }

    return ent;
}

///UNARIOS PRE-POST INCREMENTOS.

Entero& Entero::operator++()
{
    if(this->positivo)
        this->numero++;
    else
    {
        if(numero == 1)
            this->positivo = true;
        this->numero--;
    }
    return *this;
}

Entero Entero::operator++(int)
{
    if(this->positivo)
        return Entero(this->numero++);
    else
    {
        if(numero == 1)
            return Entero(0);
        return Entero(this->numero--);
    }
}

Entero& Entero::operator--()
{
    if(this->positivo)
        this->numero--;
    else
    {
        if(numero == 1)
            this->positivo = false;
        this->numero++;
    }
    return *this;
}

Entero Entero::operator--(int)
{
    if(!this->positivo)
        return Entero(this->numero--);
    else
    {
        if(numero == 1)
            return Entero(0);
        return Entero(this->numero++);
    }
}

///PRIMITIVO + ENTERO.

int operator+(int primitivo, const Entero& otro)
{
    return primitivo+((otro.getPositivo())?1:-1)*otro.getNumero();
}
