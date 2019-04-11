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
    T_nodo *ant, *sig, *act = *pl;
    if(act)
    {
        while(act->sig && cmp(d, &act->info)>0)
            act = act->sig;
        while(act->ant && cmp(d, &act->info)<0)
            act = act->ant;
        if(cmp(d, &act->info)>0)
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
        ant = sig = NULL;
    }
    T_nodo* nue = (T_nodo*)malloc(sizeof(T_nodo));
    if(!nue)
        return 0; //SIN MEMORIA.
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
    T_nodo* act = *pl;
    if(!act) return 0; //LISTA VACIA.
    while(act->sig && cmp(d, &act->info)>0)
        act = act->sig;
    while(act->ant && cmp(d, &act->info)<0)
        act = act->ant;
    if(cmp(d, &act->info)!=0)
        return 0; //NO ENCONTRADO.
    if(!act->sig && !act->ant)
        *pl = NULL;
    if(act->ant)
    {
        act->ant->sig = act->sig;
        *pl = act->ant;
    }
    if(act->sig)
    {
        act->sig->ant = act->ant;
        *pl = act->sig;
    }
    *d = act->info;
    free(act);
    act = NULL;
    return 1;
}

void eliminar_duplicados(T_lista* pl, T_cmp cmp)
{
    if(!*pl || (!(*pl)->sig && !(*pl)->ant)) return;
    T_nodo* act = *pl;
    T_nodo* sig = act->sig;
    T_nodo* ant = act->ant;
    while(act && sig)
    {
        if(cmp(&act->info, &sig->info)==0)
        {
            if(sig->sig)
            {
                act->sig = sig->sig;
                sig->sig->ant = act;
            }
            else
                act->sig = NULL;
            free(sig);
            sig = act->sig;
        }
        else
        {
            act = act->sig;
            if(act->sig)
                sig = act->sig;
            else
                sig = NULL;
        }
    }
    act = *pl;
    while(act && ant)
    {
        if(cmp(&act->info, &ant->info)==0)
        {
            if(ant->ant)
            {
                act->ant = ant->ant;
                ant->ant->sig = act;
            }
            else
                act->ant = NULL;
            free(ant);
            ant = act->ant;
        }
        else
        {
            act = act->ant;
            if(act->ant)
                ant = act->ant;
            else
                ant = NULL;
        }
    }
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

void intercambio_menor(T_nodo** a, T_nodo** b)
{
    T_nodo* aux = *b;
    *b = (*b)->sig;
    aux->sig = *a;
    *a = aux;
}

T_nodo** buscar_menor(const T_lista* pl, T_cmp cmp)
{
    if(!*pl) return NULL;
    T_nodo** menor = (T_nodo**)pl;
    while((*pl)->sig)
    {
        if(cmp(&(*menor)->info, &(*pl)->info)>0)
            menor = (T_nodo**)pl;
        pl = &(*pl)->sig;
    }
    return menor;
}

void ordenar_lista(T_lista* pl, T_cmp cmp)
{
    if(!*pl && (!(*pl)->sig && !(*pl)->ant)) return;
    while((*pl)->ant)
        *pl = (*pl)->ant;
    T_nodo** menor = pl;
    while((*pl)->sig)
    {
        menor = pl;
        menor = buscar_menor(pl, cmp);
        if(menor!=pl)
            intercambio_menor(pl, menor);
        pl = &(*pl)->sig;
    }

}

//VARIANTE

/*void eliminar_duplicados(T_lista* pl, T_cmp cmp)
{
	if(!*pl && (!(*pl)->sig && !(*pl)->ant)) return;
	T_nodo* act = *pl;
	T_nodo* sig = act->sig;
	while(act && sig)
	{
		if(cmp(&act->info, &sig->info)==0)
		{
			act->sig = sig->sig;
			if(sig->sig)
				sig->sig->ant = act;
			free(sig);
			(act->sig) ? sig = act->sig : sig = NULL;
		}
		else
		{
			act = act->sig;
			(act->sig) ? sig = act->sig : sig = NULL;
		}
	}
}*/
