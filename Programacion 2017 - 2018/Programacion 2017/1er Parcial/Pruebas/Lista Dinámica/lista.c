#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

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

int agregar_ordenado(T_lista* pl, const T_dato* d, T_cmp cmp)
{
    while((*pl) && cmp((void*)d, (void*)&(*pl)->dato) > 0)
    {
        pl = &(*pl)->siguiente;
    }
    if(cmp((void*)d,(void*)&(*pl)->dato) == 0)
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
    return 0;
}

void mostrar_lista(T_lista *pl)
{
    if(!*pl)
    {
        printf("Lista vacia");
    }
    int i = 1;
    while(*pl) // El ultimo elemento de la lista es NULO.
    {
        printf("\nElemento de la lista %d, con valor: %d", i, (*pl)->dato);
        pl = &(*pl)->siguiente;
        i++;
    }
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

void ordenar_lista(T_lista* pl, T_cmp cmp)
{
    int cant_elementos = cantidad_elementos(pl); // Cantidad de elementos de la lista.
    T_nodo **l = pl; // Para no perder el puntero al inicio de la lista.
    if(!*pl)
    {
        printf("Lista vacia");
    }
    int i = 0; // Variable aux para el vector.
    T_dato vec[cant_elementos]; // Vector que contendra los datos de los nodos.
    while(*pl) // Recorro la lista desordenada.
    {
        vec[i] = (*pl)->dato; // Copio el dato del nodo.
        pl = &(*pl)->siguiente; // Avanzo de nodo.
        i++; // Avanzo de lugar en el vector.
    }
    ordenar_vector((T_dato*)&vec); // Ordeno el vector de T_datos.
    *pl = *l; // El puntero de la lista vuelve a apuntar al primer nodo.
    i = 0; // Seteo i en 0 de nuevo.
    while(i < cant_elementos) // Vuelvo a recorrer la lista, para ordenarla.
    {
        (*pl)->dato = vec[i]; // Ahora el primer nodo esta ordenado.
        pl = &(*pl)->siguiente; // Avanzo de nodo.
        i++; // Avanzo de lugar en el vector.
    }
    *pl = NULL; // ?
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

void ordenar_vector(T_dato* vec)
{
    int i, j;
    for(i = 0; i < 4; i++)
    {
        for(j = 0; j < i; j++)
        {
            if(cmp((void*)&vec[i], (void*)&vec[j])>0)
            {
                intercambiar_punteros((void**)&vec[i], (void**)&vec[j]);
            }
        }
    }
}

int cmp(const void* num1, const void* num2)
{
    int* n1 = (int*)num1;
    int* n2 = (int*)num2;
    return *n1-*n2;
}

void intercambiar_punteros(void** p1, void** p2)
{
    void* aux;
    aux = *p1;
    *p1 = *p2;
    *p2 = aux;
}
