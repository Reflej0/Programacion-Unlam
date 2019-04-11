#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

int cmp(const void* n1, const void* n2)
{
    T_dato* e1 = (T_dato*)n1;
    T_dato* e2 = (T_dato*)n2;
    return *e1-*e2;
}

void crear_lista(T_lista* lista)
{
    *lista = NULL;
}

int agregar_ordenado(T_lista* pl, T_dato* d, T_cmp cmp)
{
    T_nodo* nue = (T_nodo*)malloc(sizeof(T_nodo));
    if(!nue)
    {
        return -1;
    }
    nue->info = *d;
    ///1er caso lista vacia.
    if(!*pl)
    {
        nue->anterior = NULL;
        nue->siguiente = NULL;
        *pl = nue;
        return 1;
    }
    ///2do caso, ya hay lista pero el valor que se va a ingresar es menor que el primero.
    T_nodo* act = *pl;
    if(cmp(d, &act->info) <= 0)
    {
        nue->anterior = NULL;
        nue->siguiente = act;
        act->anterior = nue;
        *pl = nue;
        return 1;
    }
    ///Bifurcación de los dos últimos casos.
    else
    {
        while(act->siguiente && cmp(d, &act->info) >= 0)
        {
            act = act->siguiente;
        }
        ///3er caso, que el valor que voy a ingresar sea mayor que el ultimo de la lista.
        if(!act->siguiente && cmp(d, &act->info) >= 0)
        {
            nue->siguiente = NULL;
            nue->anterior = act;
            act->siguiente = nue;
            return 1;
        }
        ///4to caso, que el valor que voy a ingresar este en el medio.
        else
        {
            nue->anterior = act->anterior;
            nue->siguiente = act;
            act->anterior->siguiente = nue;
            act->anterior = nue;
            return 1;
        }
    }
}

int eliminar_valor_lista(T_lista* pl, T_dato* d, T_cmp cmp)
{
    if(!*pl)
    {
        return -1; //LISTA VACIA.
    }
    T_nodo* act = *pl;
    ///1er caso que la lista tenga un solo elemento.
    if(!act->anterior && !act->siguiente && cmp(d, &act->info) == 0)
    {
        free(*pl);
        *pl = NULL;
        return 1;
    }
    ///2do caso que el valor a eliminar sea el primero, pero la lista tenga mas de un elemento.
    if(!act->anterior && act->siguiente && cmp(d, &act->info) == 0)
    {
        act->siguiente->anterior = NULL;
        *pl = (*pl)->siguiente; //La lista apunta al segundo elemento ahora.
        free(act);
        return 1;
    }
    ///Bifurcación de los dos últimos casos.
    else
    {
        while(act->siguiente && cmp(d, &act->info)!=0)
        {
            act = act->siguiente;
        }
        ///3er caso que el valor a eliminar sea el ultima de la lista.
        if(!act->siguiente && cmp(d, &act->info)==0)
        {
            act->anterior->siguiente = NULL; // Limpio la referencia del anterior al ultimo.
            free(act);
            return 1;
        }
        ///4to caso que el valor a eliminar este en el medio.
        if(act->siguiente && cmp(d, &act->info)==0)
        {

            act->anterior->siguiente = act->siguiente;
            act->siguiente->anterior = act->anterior;
            free(act);
            return 1;
        }
    }
    return 0; //Si el valor a eliminar no esta en la lista.
}

int eliminar_primero(T_lista* pl, T_dato* d)
{
    if(!*pl)
    {
        return -1;
    }
    *d = (*pl)->info;
    T_nodo* act = *pl;
    ///1er caso que sea el único y último elemento de la lista.
    if(!act->siguiente)
    {
        free(act);
        *pl = NULL;
        return 1;
    }
    ///2do caso que haya mas elementos además del primero.
    else
    {
        act->siguiente->anterior = NULL;
        *pl = (*pl)->siguiente;
        free(act);
        return 1;
    }
}

void ordenar_lista(T_lista* pl, T_cmp cmp)
{
    if(!*pl)
    {
        return;
    }
    T_lista* l_ord = (T_lista*)malloc(sizeof(T_lista));
    T_dato aux;
    crear_lista(l_ord);
    while(eliminar_primero(pl, &aux)!=-1)
    {
        agregar_ordenado(l_ord, &aux, cmp);
    }
    *pl = *l_ord;
}

int agregar_al_principio(T_lista* pl, T_dato* d)
{
    T_nodo* nue = (T_nodo*)malloc(sizeof(T_nodo));
    if(!nue)
    {
        return -1;
    }
    nue->info = *d;
    ///1er caso que la lista este vacía.
    if(!*pl)
    {
        nue->anterior = NULL;
        nue->siguiente = NULL;
        *pl = nue;
        return 1;
    }
    else
    {
        T_nodo* act = *pl;
        act->anterior = nue;
        nue->siguiente = act;
        nue->anterior = NULL;
        *pl = nue;
        return 1;
    }
}

void eliminar_duplicados(T_lista* pl, T_cmp cmp)
{
    ///Si la lista esta vacía o tiene un solo elemento.
    if(!*pl || ((!(*pl)->anterior) && !(*pl)->siguiente))
    {
        return;
    }
    T_nodo* act = *pl;
    T_nodo* sig = act->siguiente;
    while(act && act->siguiente)
    {
        while(cmp(&act->info, &sig->info)==0)
        {
            ///Si el siguiente tiene siguiente.
            if(sig->siguiente)
            {
                act->siguiente = sig->siguiente;
                sig->siguiente->anterior = act;
                free(sig);
            }
            else
            {
                act->siguiente = NULL;
                free(sig);
            }
            sig = act->siguiente;
        }
        act=act->siguiente;
        sig = act->siguiente;
    }
}

void ver_lista_desde_principio(T_lista* pl)
{
    if(!*pl)
    {
        return;
    }
    T_nodo* act = *pl;
    while(act && act->anterior)
    {
        act = act->anterior;
    }
    while(act)
    {
        printf("DATO:%d\n", act->info);
        act = act->siguiente;
    }
}
