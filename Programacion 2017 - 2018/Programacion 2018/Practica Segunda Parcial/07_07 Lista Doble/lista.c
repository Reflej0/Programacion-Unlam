#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

void mostrar_lista_desde_principio(const T_lista* pl, T_show show)
{
    if(!*pl) return;
    T_nodo* act = *pl;
    while(act->ant)
        act = act->ant;
    while(act)
    {
        show(&act->info);
        act = act->sig;
    }
}

void crear_lista(T_lista* pl)
{
    *pl = NULL;
}

int agregar_ordenado_duplicados(T_lista* pl, const T_dato* d, T_cmp cmp)
{
    T_nodo* act = *pl, *sig, *ant;
    if(act)
    {
        while(act->sig && cmp(d, &act->info) > 0)
            act = act->sig;
        while(act->ant && cmp(d, &act->info) < 0)
            act = act->ant;
        if(cmp(d, &act->info) > 0)
        {
            ant = act;
            sig = ant->sig;
        }
        else
        {
            sig = act;
            ant = sig->ant;
        }
    }
    else
    {
        sig = ant = NULL;
    }
    T_nodo* nue = (T_nodo*)malloc(sizeof(T_nodo));
    if(!nue) return 0;
    nue->info = *d;
    nue->sig = sig;
    nue->ant = ant;
    if(sig)
        sig->ant = nue;
    if(ant)
        ant->sig = nue;
    *pl = nue;
    return 1;
}

int eliminar_ordenado(T_lista* pl, T_dato* d, T_cmp cmp)
{
    if(!*pl) return 0;
    T_nodo* act = *pl;
    if(act)
    {
        while(act->sig && cmp(d, &act->info) > 0)
            act = act->sig;
        while(act->ant && cmp(d, &act->info) < 0)
            act = act->ant;
        if(cmp(d, &act->info)!=0)
            return -1; //NO ENCONTRADO.
    }
    if(!act->sig && !act->ant)
        *pl = NULL;
    if(act->sig)
    {
        act->sig->ant = act->ant;
        *pl = act->sig;
    }
    if(act->ant)
    {
        act->ant->sig = act->sig;
        *pl = act->ant;
    }
    *d = act->info;
    free(act);
    return 1;
}

void eliminar_duplicados(T_lista* pl, T_cmp cmp)
{
    if(!*pl) return;
    if(!(*pl)->sig && !(*pl)->ant) return;
    ///PARA LOS DE ADELANTE DESDE PL
    T_nodo* act = *pl;
    T_nodo* sig = (act->sig) ? act->sig : NULL;
    while(act && sig)
    {
        if(cmp(&act->info, &sig->info) == 0)
        {
            if(sig->sig)
            {
                act->sig = sig->sig;
                sig->sig->ant = act;
            }
            else
                act->sig = NULL;
            free(sig);
        }
        else
            act = act->sig;
        sig = act->sig;
    }
    ///PARA LOS ANTERIORES DESDE PL
    act = *pl;
    T_nodo* ant = (act->ant) ? act->ant : NULL;
    while(act && ant)
    {
        if(cmp(&act->info, &ant->info) == 0)
        {
            if(ant->ant)
            {
                act->ant = ant->ant;
                ant->ant->sig = act;
            }
            else
                act->ant = NULL;
            free(ant);
        }
        else
            act = act->ant;
        ant = act->ant;
    }
}
/* Nota: Es requisito que la lista este ordenada, por el criterio "mejor"
es decir si necesito los 5 vendedores con mas ventas, ordenar a los vendedores por cantidad de ventas.
*/
void los_n_mejores(const T_lista* pl, T_dato* vec, T_cmp cmp, size_t n)
{
    if(!*pl) return;
    T_nodo* act = *pl;
    while(act->sig)
        act = act->sig;
    int i = 0;
    //Quiza se solicitan mas numero de mejores que los existentes en la lista.
    for(; (i<n || act->ant); i++)
    {
        *vec = (act)->info;
        vec++;
        act = act->ant;
    }
}

int eliminar_del_principio(T_lista* pl, T_dato* d)
{
    if(!*pl)return 0;
    *d = (*pl)->info;
    T_nodo* nae = (*pl);
    *pl = ((*pl)->sig) ? (*pl)->sig : NULL;
    free(nae);
    return 1;
}

int agregar_al_principio(T_lista* pl, const T_dato* d)
{
    T_nodo* nue = (T_nodo*)malloc(sizeof(T_nodo));
    if(!nue) return 0;
    while((*pl) && (*pl)->ant)
        (*pl) = (*pl)->ant;
    nue->info = *d;
    nue->ant = NULL;
    nue->sig = *pl;
    *pl = nue;
    return 1;
}

void ordenar_lista_sin_seleccion(T_lista* pl, T_cmp comp)
{
    T_lista* ord = (T_lista*)malloc(sizeof(T_lista));
    T_dato d;
    crear_lista(ord);
    while(eliminar_del_principio(pl, &d)!=0)
        agregar_ordenado_duplicados(ord, &d, comp);
    *pl = *ord;
}

void eliminar_lista(T_lista* pl)
{
    if(!*pl)
        return;
    T_nodo* act = *pl;
    T_nodo* nae;
    ///ELIMINO LOS NODOS SIGUIENTES AL ACTUAL.
    while(act->sig)
    {
        nae = act->sig;
        if(nae->sig)
            act->sig = nae->sig;
        else
            act->sig = NULL;
        free(nae);
    }
    ///ELIMINO LOS NODOS ANTERIORES AL ACTUAL.
    while(act->ant)
    {
        nae = act->ant;
        if(nae->ant)
            act->ant = nae->ant;
        else
            act->ant = NULL;
        free(nae);
    }
    ///ELIMINO EL NODO ACTUAL(EL UNICO).
    free(act);
    *pl = NULL;
}

///MEMORIZAR / RAZONAR.

void intercambiar(T_nodo** a, T_nodo** b)
{
    T_nodo* aux = *b;
    *b = (*b)->sig;
    aux->sig = *a;
    *a = aux;
}

T_nodo** buscarMenor(T_lista* l, T_cmp comp)
{
    T_nodo** menor = l;
    while(*l)
    {
        if(comp(&(*l)->info, &(*menor)->info) < 0)
            menor = l;

        l = &(*l)->sig;
    }
    return menor;
}

void ordenar_lista(T_lista* l, T_cmp comp)
{
    if(!*l)return;
    while((*l)->ant)
        *l = (*l)->ant;
    T_nodo** menor;
    while(*l && (*l)->sig)
    {
        menor = l;  //El primer menor es el nodo sobre el que estoy parado
        menor = buscarMenor(l, comp);
        if(l != menor)
            intercambiar(l, menor);
        l = &(*l)->sig;
    }
}
