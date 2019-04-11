#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

int comp_int(const void* a, const void* b)
{
    return *(int*)a-*(int*)b;
}

void crear_lista(T_lista* pl)
{
    *pl = NULL;
}

void mostrar_int(const void* a)
{
    printf("Dato: %d\n", *(int*)a);
}

void mostrar_adelante_desde_actual(const T_lista* pl, T_show show)
{
    if(!*pl)
        return;
    T_nodo* act = *pl;
    if(act)
        show(&act->d);
    while((act)->sig)
    {
        act = act->sig;
        show(&act->d);
    }
}

void mostrar_desde_principio(const T_lista* pl, T_show show)
{
    if(!*pl)
        return;
    T_nodo* act = *pl;
    while(act->ant)
        act = act->ant;
    while(act)
    {
        show(&act->d);
        act = act->sig;
    }
}

void mostrar_desde_final(const T_lista* pl, T_show show)
{
    if(!*pl)
        return;
    T_nodo* act = *pl;
    while(act->sig)
        act = act->sig;
    while(act)
    {
        show(&act->d);
        act = act->ant;
    }
}

void mostrar_atras_desde_actual(const T_lista* pl, T_show show)
{
    if(!*pl)
        return;
    T_nodo* act = *pl;
    if(act)
        show(&act->d);
    while(act->ant)
    {
        act = act->ant;
        show(&act->d);
    }
}

int agregar_ordenado_lista(T_lista* pl, const T_dato* pd, T_cmp cmp)
{
    T_nodo* act = *pl;
	T_nodo *sig, *ant;
	///RECORRIDO SI HAY LISTA.
	if(act)
	{
		while(act->sig && cmp(pd, &act->d) >0)
            act = act->sig;
		while(act->ant && cmp(pd, &act->d) <0)
			act = act->ant;
		if(cmp(pd, &act->d) >0)
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
	///SI NO HAY LISTA, NO HAY RECORRIDO.
	else
	{
		ant = NULL;
		sig = NULL;
	}
	///NODO NUEVO.
	T_nodo* nue = malloc(sizeof(T_nodo));
	if(!nue)
		return SIN_MEMORIA;
    ///ENGANCHES DEL NODO NUEVO.
	nue->sig = sig;
	nue->ant = ant;
	nue->d = *pd;
	///ENGANCHES DE LOS NODOS ANTERIORES Y SIGUIENTES.
	if(ant)
        ant->sig=nue;
    if(sig)
        sig->ant=nue;
	*pl = nue;
	return 1;
}

int eliminar_de_lista(T_lista* pl, T_dato* pd, T_cmp cmp)
{
    ///COMPROBACION DE LISTA VACIA.
    if(!*pl)
        return LISTA_VACIA;
    T_nodo* act = *pl;
	///BUSQUEDA DEL DATO SEGUN CRITERIO DE COMPARACION.
	if(act)
	{
		while(act->sig && cmp(pd, &act->d) >0)
            act = act->sig;
		while(act->ant && cmp(pd, &act->d) <0)
			act = act->ant;
		if(cmp(pd, &act->d) !=0)
			return NO_ENCONTRADO;
	}
	///ENGANCHES PRE-ELIMINACION.
	T_nodo* nae = act;
	///SI ES NODO UNICO.
	if(!nae->ant && !nae->sig)
    {
        *pl = NULL;
    }
    ///SI EL NODO A ELIMINAR TIENE ANTERIOR.
	if(nae->ant)
    {
        nae->ant->sig = nae->sig;
        *pl = nae->ant;
    }
    ///SI EL NODO A ELIMINAR TIENE SIGUIENTE.
    if(nae->sig)
    {
        nae->sig->ant = nae->ant;
        *pl = nae->sig;
    }
    ///RETORNO DE DATO Y ELIMINACION DE NODO.
    *pd = nae->d;
    free(nae);
    return 1;
}

void vaciar_lista(T_lista* pl)
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

size_t _count(const T_lista* pl)
{
    if(!*pl)
        return 0;
    T_nodo *sig = *pl, *ant=*pl;
    size_t n = 1;
    ///CUENTO LOS NODOS SIGUIENTES DESDE EL ACTUAL.
    while(sig->sig)
    {
        n++;
        sig = sig->sig;
    }
    ///ELIMINO LOS NODOS ANTERIORES DESDE EL ACTUAL.
    while(ant->ant)
    {
        n++;
        ant = ant->ant;
    }
    return n;
}

void eliminar_duplicados(T_lista* pl, T_cmp cmp)
{
    if(!*pl || (!(*pl)->sig && !(*pl)->ant))
        return;
    T_nodo *acts = *pl, *acta = *pl;
    T_nodo *sig = acts->sig;
    T_nodo *ant = acta->ant;
    ///RECORRO LA LISTA PARA ADELANTE DESDE ACTUAL.
    while(acts && sig)
    {
        ///SI EL ACTUAL ES IGUAL AL SIGUIENTE, ELIMINO EL SIGUIENTE.
        if(cmp(&acts->d, &sig->d) == 0)
        {
            ///ENGANCHE DE ACTUAL, SI EL SIGUIENTE TIENE SIGUIENTE.
            if(sig->sig)
            {
                acts->sig = sig->sig;
                sig->sig->ant = acts;
            }
            ///SI EL SIGUIENTE ES EL ULTIMO, EL SIGUIENTE DEL ACTUAL ES NULO.
            else
                acts->sig = NULL;
            free(sig);
        }
        ///SI EL ACTUAL NO ES IGUAL AL SIGUIENTE, SIMPLEMENTE AVANZO EL ACTUAL.
        else
            acts = acts->sig;
        ///DETERMINO EL VALOR DEL SIGUIENTE, SEGUN EL VALOR DE ACTUAL.
        if(acts)
            sig = acts->sig;
        else
            sig = NULL;

    }
    ///RECORRO LA LISTA PARA ATRAS DESDE ACTUAL.
    while(acta && ant)
    {
        ///SI EL ACTUAL ES IGUAL AL ANTERIOR SEGUN EL CRITERIO DE COMPARACION.
        if(cmp(&acta->d, &ant->d) == 0)
        {
            ///ENGANCHE DE ACTUAL, SI EL ANTERIOR TIENE ANTERIOR.
            if(ant->ant)
            {
                acta->ant = ant->ant;
                ant->ant->sig = acta;
            }
            ///SI EL ANTERIOR ES EL ULTIMO, EL ANTERIOR DEL ACTUAL ES NULO.
            else
                acta->ant = NULL;
            free(ant);
        }
        ///SI EL ACTUAL NO ES IGUAL AL ANTERIOR, SIMPLEMENTE RETROCEDO EL ACTUAL.
        else
            acta = acta->ant;
        ///DETERMINO EL VALOR DEL ANTERIOR, SEGUN EL VALOR DE ACTUAL.
        if(acta)
            ant = acta->ant;
        else
            ant = NULL;
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

void ordenar_lista_sin_seleccion(T_lista* pl, T_cmp comp)
{
    T_lista* ord = (T_lista*)malloc(sizeof(T_lista));
    T_dato d;
    crear_lista(ord);
    while(eliminar_del_principio(pl, &d)!=0)
        agregar_ordenado_duplicados(ord, &d, comp);
    *pl = *ord;
}

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