#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

elemento* ultimo = NULL; // El valor inicial es nulo.

void agregar(elemento* _elemento)
{
    _elemento->siguiente = NULL; //Valor inicial.
    if(ultimo == NULL) //Verifico si la pila esta vacia.
    {
        ultimo = _elemento;
    }
    else
    {
        _elemento->siguiente = ultimo;
        ultimo = _elemento;
    }
}

elemento* extraer()
{
    if(ultimo == NULL) // Verifico si la pila esta vacia.
    {
        return NULL;
    }
    elemento* elemento_retorno = ultimo;
    ultimo = elemento_retorno -> siguiente;
    return elemento_retorno;
}
