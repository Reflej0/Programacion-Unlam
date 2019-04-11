#include <stdio.h>
#include <stdlib.h>
#include "lista.h"
#include "iterador.h"

void crear_lista(T_lista* pl)
{
    *pl = NULL;
}

int agregar_principio(T_lista* pl, const T_dato* d)
{
    T_nodo* nue = malloc(sizeof(T_nodo));
    if(!nue)
    {
        return 1; // Memoria llena.
    }
    nue->dato = *d;
    nue->siguiente = *pl;
    *pl = nue;
    return 0;
}

int agregar_final(T_lista* pl, const T_dato* d)
{
    T_nodo* nue = malloc(sizeof(T_nodo));
    if(!nue)
    {
        return 1; // Memoria llena.
    }
    nue->dato = *d;
    nue->siguiente = NULL;
    while((*pl)->siguiente) // Avanzo mientras haya siguiente.
    {
        pl = &(*pl)->siguiente;
    }
    (*pl)->siguiente = nue;
    return 0;
}

int agregar_ordenado(T_lista* pl, const T_dato* d, T_cmp cmp, T_iterador* ite)
{
    while((*pl) && cmp((void*)d, (void*)&(*pl)->dato) > 0)
    {
        pl = &(*pl)->siguiente;
    }
    if((*pl) && cmp((void*)d,(void*)&(*pl)->dato) == 0)
    {
        return -1; // DUPLICADO.
    }
    T_nodo* nue = malloc(sizeof(T_nodo));
    if(!nue)
    {
        return 1; //Memoria llena.
    }
    nue->dato = *d;
    nue->siguiente = *pl;
    *pl = nue;
    ///Cuando inserto un nuevo nodo, ahora el actual del iterador va a apuntar al nuevo nodo insertado.
    set_nodo_actual(ite, nue);
    return 0;
}

int eliminar_principio(T_lista* pl, T_dato *d)
{
    if(!*pl)
    {
        return 1; //Lista vacia.
    }
    T_nodo* nae;
    nae = *pl;
    *pl = nae->siguiente;
    free(nae);
    return 0;
}

int eliminar_ultimo(T_lista* pl, T_dato *d)
{
    if(!*pl)
    {
        return 1; //Lista vacia.
    }
    while((*pl)->siguiente) // Mientras el nodo tenga un siguiente.
    {
        pl = &(*pl)->siguiente; // Cambio de nodo.
    }
    T_nodo* nae = *pl; // NAE es el último nodo.
    *pl = NULL; // Ahora el último elemento de la lista es nulo.
    *d = nae->dato; // Copio el dato.
    free(nae); // Libero la memoria.
    return 0;
}

int eliminar_lista(T_lista* pl)
{
    if(!*pl)
    {
        return 1; //Lista vacia.
    }
    while(*pl)
    {
        T_nodo* nae = *pl;
        *pl = nae->siguiente;
        free(nae);
    }
    return 0;
}

///REVISAR FIX indice-1
int eliminar_indice(T_lista* pl, T_dato* d, const int indice)
{
    if(!*pl)
    {
        return 1; //LISTA VACIA.
    }

    int i = 0;
    while(i < indice-1)
    {
        pl = &(*pl)->siguiente;
        i++;
    }
    T_nodo* nae = *pl;
    *pl = nae->siguiente;
    free(nae);
    return 0; // TODO OK;
}

int eliminardelista(T_lista* pl, T_dato* d)
{
    if(!*pl)
    {
        return -1; //LISTA VACIA.
    }
    T_nodo* aux;
    while(*pl){
        if((*pl)->dato.dni == d->dni)
        {
            aux = *pl;
            *pl = aux->siguiente;
            free(aux);
            return 1; // ENCONTRADO.
        }
        else
        {
            pl = &(*pl)->siguiente;
        }
    }
    return 0; // NO ENCONTRADO.
}

int cantidad_elementos(T_lista* pl)
{
    int i = 0;
    while(*pl) // Mientras haya nodos.
    {
        pl = &(*pl)->siguiente; // Avanzo de nodo.
        i++; // Avanzo de lugar en el vector.
    }
    return i;
}

///CMP de T_Dato DNI
int cmp(const void* num1, const void* num2)
{
    T_dato* n1 = (T_dato*)num1;
    T_dato* n2 = (T_dato*)num2;
    return (n1->dni)-(n2->dni);
}

void intercambiar_punteros(void** p1, void** p2)
{
    void* aux;
    aux = *p1;
    *p1 = *p2;
    *p2 = aux;
}

void mostrar_lista(T_lista* pl)
{
    while(*pl)
    {
        printf("\nRegistro numero %d, DNI: %ld", (*pl)->dato.nro_reg, (*pl)->dato.dni);
        pl = &(*pl)->siguiente;
    }
}
