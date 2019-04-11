#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

void crear_lista(T_lista* pl)
{
    *pl = NULL;
}

int agregar_principio(T_lista* pl, const T_dato *d)
{
    T_nodo* nue = malloc(sizeof(T_nodo));
    if(!nue)
    {
        return 1; //Memoria llena.
    }
    nue->dato = *d;
    nue->siguiente = *pl;
    (*pl) = nue;
    return 0;
}

int agregar_final(T_lista* pl, const T_dato *d)
{
    T_nodo* nue = malloc(sizeof(T_nodo));
    if(!nue)
    {
        return 1; //Memoria llena.
    }
    while((*pl)->siguiente) // Esta es la condicion para encontrar el ultimo.
    {
        pl = &(*pl)->siguiente;
    }
    nue->dato = *d;
    nue->siguiente = NULL;
    (*pl)->siguiente = nue;
    return 0;
}

int agregar_ordenado(T_lista* pl, const T_dato *d, T_cmp cmp)
{
    T_nodo* nue = malloc(sizeof(T_nodo));
    if(!nue)
    {
        return 1; //Memoria llena.
    }
    while(*pl && cmp(d, &(*pl)->dato) < 0)
    {
        pl =&(*pl)->siguiente;
    }
    if(cmp(d, &(*pl)->dato) == 0)
    {
        return -1; //Duplicado.
    }
    nue->dato = *d;
    nue->siguiente = (*pl)->siguiente;
    (*pl)->siguiente = nue;
    return 0;
}

int eliminar_principio(T_lista* pl, T_dato *d)
{
    if(!*pl)
    {
        return 1; //Lista vacia.
    }
    T_nodo* nae = *pl;
    *pl = (*pl)->siguiente;
    free(nae);
    return 0;
}

int eliminar_indice(T_lista* pl, T_dato *d, size_t indice)
{
    int i = 0;
    while(i < (indice-1))
    {
        pl = &(*pl)->siguiente;
        i++;
    }
    T_nodo* nae = (*pl)->siguiente;
    (*pl)->siguiente = nae->siguiente;
    free(nae);
    return 0;
}

int buscar_indice(T_lista* pl, T_dato *d, size_t indice)
{
    int i = 0;
    if(!*pl)
    {
        return 1; //Lista vacia.
    }
    while(i<indice) // Esta es la condicion para encontrar el ultimo.
    {
        pl = &(*pl)->siguiente;
        i++;
    }
    *d = (*pl)->dato;
    return 0;
}

int cmp_alu(const void* alu1, const void* alu2)
{
    T_dato* alumno1 = (T_dato*)alu1;
    T_dato* alumno2 = (T_dato*)alu2;
    return (alumno1->dni)-(alumno2->dni);
}

size_t cantidad_elementos(T_lista *pl)
{
    size_t i = 0;
    while(*pl)
    {
        pl = &(*pl)->siguiente;
        i++;
    }
    return i;
}

void ordenar_lista(T_lista* pl)
{
    T_lista inicio_lista = *pl; // Esto es para no perder el inicio de la lista.
    size_t longitud = cantidad_elementos(pl); // La cantidad de elementos de la lista.
    size_t i = 0; // Variable auxiliar.
    T_dato elementos[longitud]; // Esta variable contiene los T_datos de la lista.
    while(i < longitud)
    {
        elementos[i] = (*pl)->dato;
        pl = &(*pl)->siguiente;
        i++;
    }
    ordenar_datos(elementos, longitud);
    i = 0;
    *pl = inicio_lista;
    while(i < longitud)
    {
        (*pl)->dato = elementos[i];
        pl = &(*pl)->siguiente;
        i++;
    }
    *pl = NULL;
}

void ordenar_datos(T_dato* vec, size_t longitud)
{
    int i, j;
    for(i = 0; i < longitud; i++)
    {
        for(j = 0; j < i; j++)
        {
            if(cmp_alu(&vec[i], &vec[j]) > 0)
            {
                intercambiar_punteros((void**)&vec[i], (void**)&vec[j]);
            }
        }
    }
}

void intercambiar_punteros(void** a, void** b)
{
    void* aux = *a;
    *a = *b;
    *b = aux;
}

void mostrar_lista(T_lista* pl)
{
    while(*pl)
    {
        printf("\nElemento de la lista %d", (*pl)->dato.dni);
        pl = &(*pl)->siguiente;
    }
}
