#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

int cmp(const void* num, const void* num2)
{
    T_dato* n1 = (T_dato*)num;
    T_dato* n2 = (T_dato*)num2;
    return *n1-*n2;
}

void crear_lista(T_lista* pl)
{
    *pl = NULL;
}

int agregar_principio(T_lista* pl, const T_dato* d)
{
    T_nodo* nue = (T_nodo*)malloc(sizeof(T_nodo));
    if(!nue)
    {
        return -1;
    }
    nue->dato = *d;
    if(!*pl)
    {
        nue->siguiente = NULL;
        *pl = nue;
        return 1;
    }
    else
    {
        nue->siguiente = *pl;
        *pl = nue;
        return 1;
    }
}

int agregar_final(T_lista* pl, const T_dato* d)
{
    T_nodo* nue = (T_nodo*)malloc(sizeof(T_nodo));
    if(!nue)
    {
        return -1;
    }
    nue->dato = *d;
    if(!*pl)
    {
        nue->siguiente = NULL;
        *pl = nue;
        return 1;
    }
    else
    {
        T_nodo* aux = *pl;
        while(aux->siguiente)
        {
            aux = aux->siguiente;
        }
        aux->siguiente = nue;
        nue->siguiente = NULL;
        return 1;
    }
}

int agregar_ordenado(T_lista* pl, const T_dato* d, T_cmp cmp)
{
    T_nodo* nue = (T_nodo*)malloc(sizeof(T_nodo));
    T_nodo* atras;
    nue->dato = *d;
    //SI ES EL PRIMER ELEMENTO.
    if(!*pl)
    {
        nue->siguiente = NULL;
        *pl = nue;
        return 1;
    }
    //SI ES MENOR QUE EL PRIMERO.
    if(*pl && cmp(d, &(*pl)->dato) < 0)
    {
        nue->siguiente = *pl;
        *pl = nue;
        return 1;
    }
    while(*pl && cmp(d, &(*pl)->dato) > 0)
    {
        atras = *pl;
        pl = &(*pl)->siguiente;
    }
    nue->siguiente = *pl; // *pl = atras->siguiente.
    atras->siguiente = nue;
    return 1;
}

int eliminar_principio(T_lista* pl, T_dato *d)
{
    if(!*pl)
    {
        return 0;
    }
    T_nodo* nae = *pl;
    *d = nae->dato;
    *pl = nae->siguiente;
    free(nae);
    return 1;
}

int eliminar_ultimo(T_lista* pl, T_dato *d)
{
    if(!*pl)
    {
        return 0;
    }
    while((*pl)->siguiente)
    {
        pl = &(*pl)->siguiente;
    }
    *d = (*pl)->dato;
    free(*pl);
    *pl = NULL;
    return 1;
}

int eliminar_valor(T_lista* pl, const T_dato *d, T_cmp cmp)
{
    if(!*pl)
    {
        return 0;
    }
    T_nodo* atras;
    ///SI EL QUE QUIERO ELIMINAR ES EL PRIMERO.
    if(cmp(d, &(*pl)->dato) == 0)
    {
        T_nodo* nae = *pl;
        *pl = nae->siguiente;
        free(nae);
        return 1;
    }
    ///AVANZO LA LISTA MIENTRAS HAYA ELEMENTOS Y NO ENCUENTRE EL QUE QUIERO ELIMINAR.
    while(*pl && cmp(d, &(*pl)->dato) != 0)
    {
        atras = *pl;
        pl = &(*pl)->siguiente;
    }
    ///ME FIJO SI LO ENCONTRE O SI TERMINO LA LISTA.
    if(cmp(d, &(*pl)->dato) == 0)
    {
        T_nodo* nae = *pl;
        atras->siguiente = nae->siguiente;
        free(nae);
        return 1;
    }
    return 0; // NO ENCONTRADO.
}

int eliminar_indice(T_lista* pl, T_dato *d, const int indice)
{
    if(!*pl)
    {
        return 0;
    }
    if(indice == 0)
    {
        T_nodo* nae = *pl;
        *pl = nae->siguiente;
        free(nae);
        return 1;
    }
    int i = 0;
    T_nodo* atras;
    ///AVANZO LA LISTA MIENTRAS HAYA ELEMENTOS Y NO ENCUENTRE EL QUE QUIERO ELIMINAR.
    while(i != indice)
    {
        atras = *pl;
        pl = &(*pl)->siguiente;
        i++;
    }
    T_nodo* nae = *pl;
    atras->siguiente = nae->siguiente;
    free(nae);
    return 1;
}

void ordenar_lista(T_lista* pl, T_cmp cmp)
{
    T_lista* l_ord = (T_lista*)malloc(sizeof(T_lista));
    crear_lista(l_ord);
    T_dato d;
    while(eliminar_principio(pl, &d) != 0)
    {
        agregar_ordenado(l_ord, &d, cmp);
    }
    *pl = *l_ord;
}


void mostrar_lista(T_lista* pl)
{
    if(!*pl)
    {
        return;
    }
    T_nodo* aux = *pl;
    while(aux)
    {
        printf("DATO: %d\n", aux->dato);
        aux = aux->siguiente;
    }
}
