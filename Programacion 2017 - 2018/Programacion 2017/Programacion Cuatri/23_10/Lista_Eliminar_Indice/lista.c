#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

int cmp_int(const void* num, const void* num2)
{
    int* numero = (int*)num;
    int* numero2 = (int*)num2;
    return *numero-*numero2;
}

void crear_lista(T_lista* lista)
{
    *lista = NULL;
}

int poner_en_lista_principio(T_lista* lista, T_dato* dato)
{
    T_nodo* nue = malloc(sizeof(T_nodo));
    if(!nue)
    {
    return 1; //FALSO.
    }
    nue->dato = *dato;
    nue->siguiente = *lista;
    *lista = nue;
    return 0; //VERDADERO.
}

int poner_en_lista_final(T_lista* lista, T_dato* dato)
{
    T_nodo* nue = malloc(sizeof(T_nodo));
    if(!nue)
    {
    return 1; //FALSO.
    }
    nue->dato = *dato;
    nue->siguiente = NULL; // El nuevo nodo va a ser el último.
    (*lista)->siguiente = nue; // Al anterior último nodo le asigno el siguiente.
    return 0; // VERDADERO.
}

int poner_en_lista_ord(T_lista* lista, const T_dato* dato, T_cmp cmp)
{
    while(*lista && cmp(dato, &(*lista)->dato) <0)
    {
        lista = &(*lista)->siguiente;
    }
    if(*lista && cmp(dato, &(*lista)->dato) == 0)
    {
        return -1; //DUPLICADO.
    }
    T_nodo* nue = malloc(sizeof(T_nodo));
    if(!nue)
    {
    return 1; //FALSO.
    }
    nue->dato = *dato;
    nue->siguiente = *lista;
    (*lista) = nue;
    return 0;
}

void mostrar_lista(T_lista* lista)
{
    int i = 1;
    while(*lista)
    {
        printf("\nElemento numero %d es: %d", i, (*lista)->dato);
        lista = &(*lista)->siguiente;
        i++;
    }
}

int buscar_en_lista_por_posicion(T_lista* lista, const int posicion, T_dato* respuesta)
{
    int i = 0;
    while(*lista && i < posicion)
    {
        lista = &(*lista)->siguiente;
        i++;
    }
    if(!(*lista))
    {
        return 1; // FALSO, NO ENCONTRADO.
    }
    *respuesta = (*lista)->dato;
    return 0; // VERDADERO, ENCONTRADO.
}

int buscar_en_lista_por_clave(T_lista* lista, const T_dato* dato)
{
    int posicion = 1;
    while(*lista)
    {
        if(cmp_int(dato, &(*lista)->dato) == 0)
        {
            return posicion;
        }
        lista = &(*lista)->siguiente;
        posicion++;
    }
        return -1; // FALSO, NO ENCONTRADO.
}

void ordenar_lista(T_lista* lista, T_cmp cmp, T_lista* lista_ordenada)
{
    int i = 0; // Variable con el indice del nodo.
    T_dato menor = (*lista)->dato;
    while(*lista)
    {
        if(cmp(&menor, &(*lista)->dato) > 0)
        {
            menor = (*lista)->dato;
            //eliminar_indice(lista, &menor, i);
            poner_en_lista_ord(lista_ordenada, &menor, cmp);
        }
        lista = &(*lista)->siguiente;
        i++;
    }
}

int eliminar_indice(T_lista* pl, T_dato* d, const int indice)
{
    if(!*pl)
    {
        return 1; //LISTA VACIA.
    }

    int i = 0;
    while(i < indice)
    {
        pl = &(*pl)->siguiente;
        i++;
    }
    T_nodo* nae = *pl;
    *pl = nae->siguiente;
    free(nae);
    return 0; // TODO OK;
}
