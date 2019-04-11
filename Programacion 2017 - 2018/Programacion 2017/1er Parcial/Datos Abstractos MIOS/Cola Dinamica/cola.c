#include <stdio.h>
#include <stdlib.h>
#include "cola.h"
#include "string.h"

void crear_cola(T_cola *pc)
{
    pc->fr = NULL;
    pc->fo = NULL;
}

int poner_en_cola(T_cola *pc, T_dato *d)
{
    T_nodo *nue = malloc(sizeof(T_nodo));
    if(!nue) // Si no hay mas espacio.
    {
        return 1; //FALSO
    }
    nue->dato = *d;
    nue->siguiente = NULL; // En principio no tiene siguiente.
    if(!(pc->fr)) // Si no tiene frente, es decir es el primer elemento ingresado.
    {
        pc->fr = nue; // Ahora si pasa a tener frente.
    }
    else // Si ya tenia un elemento.
    {
        pc->fo->siguiente = nue;
    }
    pc->fo = nue; // El fondo ahora es el nuevo.
    return 0; //VERDADERO
}

int sacar_de_cola(T_cola *pc, T_dato *d)
{
    if(!(pc)->fr) // Si no hay nada en el frente, esta vacia.
    {
        return 1; //FALSO.
    }
    T_nodo *nae = pc->fr; // El nodo a eliminar es el primer elemento.
    pc->fr = nae->siguiente; // El que va a pasar a ser el nuevo frente, es el siguiente del primero.
    *d = nae->dato; // El dato que del nodo a eliminar.
    free(nae); // Libero la memoria.
    if(!(pc)->fr) // Si el frente es nulo, esta vacio.
    {
        pc->fo = NULL; // El fondo entonces tambien es nulo.
    }
    return 0; //VERDADERO.
}

int ver_frente_de_cola(T_cola const *pc, T_dato *d)
{
    if(!(pc)->fr) // Si no hay nada en el frente, esta vacia.
    {
        return 1; //FALSO.
    }
    *d = pc->fr->dato;
    return 0;
}

void vaciar_cola(T_cola *pc)
{
    while((pc->fr))
    {
    T_nodo *nae = pc->fr;
    pc->fr = nae->siguiente;
    free(nae);
    }
    pc->fo = NULL;
}

int cola_vacia(const T_cola *pc)
{
    if(!(pc->fr)) // Si no hay nada en el frente esta vacio.
    {
        return 0; //VACIO.
    }
    return 1; //ALGO.
}

int cola_llena(const T_cola *pc)
{
    T_nodo *nue = malloc(sizeof(T_nodo));
    if(!nue)
    {
        return 1; // FALSO.
    }
    return 0;
}
