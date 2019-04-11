#include <stdio.h>
#include <stdlib.h>
#include "cola.h"

 // Al principio, no empiezo con ningun elemento.
elemento *primer = NULL;
elemento *ultimo = NULL;

//Voy a agregar un elemento el cual paso por parametro.
void agregar(elemento *_elemento)
{
    //Valor inicial.
    _elemento -> proximo = NULL;
    //La primera vez (cuando la cola esta vacia), se asigna el primer elemento y el ultimo.
    if(primer == NULL)
    {
        primer = _elemento;
        ultimo = _elemento;
    }
    //Las siguientes veces, solo se asigna el ultimo elemento.
    else
    {
        ultimo -> proximo = _elemento;
        ultimo = _elemento;
    }
}

//Voy a extraer un elemento, devuelvo por parametro el elemento extraido.
elemento* extraer()
{
    //Si la cola esta vacia devuelvo null.
    if(primer == NULL)
    {
        return NULL;
    }
    elemento *elemento_retorno = primer;
    primer = primer -> proximo;
    return elemento_retorno;
}
