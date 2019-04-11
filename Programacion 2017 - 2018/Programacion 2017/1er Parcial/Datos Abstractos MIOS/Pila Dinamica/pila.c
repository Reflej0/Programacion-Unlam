#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

void crear_pila(T_pila *p)
{
    *p = NULL;
}

int poner_en_pila(T_pila *p, const T_dato *d)
{
    T_nodo *nue = (T_nodo*)malloc(sizeof(T_nodo));
    if(!nue)
    {
        return 1; //FALSO.
    }
    nue->dato = *d; // Nuevo tiene el dato pasado por parametro.
    nue->siguiente = *p;
    *p = nue; // La direccion de memoria a la que apunta p es la de nue.
    return 0; // VERDADERO.
}

int sacar_de_pila(T_pila *p, T_dato *d)
{
    if(!*p)
    {
        return 1; // PILA VACIA.
    }
    T_nodo* nae = *p;
    *p = nae->siguiente;
    *d = nae->dato;
    free(nae);
    return 0; // TODO OK.
}

int pila_vacia(const T_pila *p)
{
    if(!*p)
    {
        return 1; // PILA VACIA.
    }
    return 0; //PILA CON AL MENOS UN ELEMENTO.
}

int pila_llena(const T_pila *p) //ES ASI ?
{
    T_nodo *nue = (T_nodo*)malloc(sizeof(T_nodo));
    if(!nue)
    {
        return 1; //MEMORIA LLENA.
    }
    free(nue);
    return 0; //MEMORIA CON ESPACIO.
}

int ver_tope_de_pila(const T_pila *p, T_dato *d)
{
    if(!*p)
    {
        return 1; // PILA VACIA.
    }
    *d = (*p)->dato;
    return 0; // TODO OK.
}

void vaciar_pila(T_pila *p)
{
    while(*p)
    {
        T_nodo* nae = *p;
        *p = nae->siguiente;
        free(nae);
    }

}

