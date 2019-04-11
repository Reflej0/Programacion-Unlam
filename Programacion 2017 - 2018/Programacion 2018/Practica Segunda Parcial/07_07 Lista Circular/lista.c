#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

void crear_lista(T_lista* pl)
{
    *pl = NULL;
}

void mostrar_lista(const T_lista* pl, T_show show)
{
    if(!*pl) return;
    T_nodo* recorr = (*pl)->sig; //PL APUNTA AL ULTIMO ELEMENTO DE LA LISTA.
    while(recorr != *pl)
    {
        show(&recorr->info);
        recorr = recorr->sig;
    }
    show(&recorr->info); //MUESTRO EL ULTIMO.
}

int agregar_al_final(T_lista* pl, const T_dato* d)
{
    T_nodo* nue = (T_nodo*)malloc(sizeof(T_nodo));
    if(!nue) return 0; //LISTA LLENA.
    nue->info = *d;
    if(!*pl)
    {
        nue->sig = nue;
        *pl = nue;
        return 1;
    }
    nue->sig = (*pl)->sig;
    (*pl)->sig = nue;
    *pl = nue;
    return 1;
}

int agregar_al_principio(T_lista* pl, const T_dato* d)
{
    T_nodo* nue = (T_nodo*)malloc(sizeof(T_nodo));
    if(!nue) return 0;
    nue->info = *d;
    if(!*pl)
    {
        nue->sig = nue;
        *pl = nue;
        return 1;
    }
    nue->sig = (*pl)->sig; //(*pl)->sig es el primer elemento de la lista.
    (*pl)->sig = nue;
    return 1;
}

int eliminar_principio(T_lista* pl, T_dato* d)
{
    if(!*pl) return 0; //SIN MEMORIA.
    T_nodo* nae = (*pl)->sig;
    (*pl)->sig = nae->sig;
    if(*pl == nae) *pl = NULL;
    free(nae);
    return 1;
}
/* Al tener pl apuntando al ultimo elemento de la lista
para realizar los enganches al eliminar el ultimo elemento
debo recorrer la lista para posicionarme en el anteultimo elemento.
*/
int eliminar_final(T_lista* pl, T_dato* d)
{
    if(!*pl) return 0; //SIN MEMORIA.
    T_nodo* recorr = (*pl)->sig;
    while(recorr->sig != *pl)
        recorr = recorr->sig;
    recorr->sig = (*pl)->sig;
    free(*pl);
    if(*pl == recorr) *pl = NULL;
    else *pl = recorr;
    return 1;
}

size_t contar_elementos_lista(const T_lista* pl)
{
    if(!*pl) return 0; //SIN MEMORIA.
    if(*pl == (*pl)->sig) return 1;
    size_t i = 1;
    T_nodo* recorr = (*pl)->sig;
    while(recorr != *pl)
    {
        recorr = recorr->sig;
        i++;
    }
    return i;
}

int buscar_clave(const T_lista* pl, T_dato* d, T_cmp cmp)
{
    if(!*pl) return 0; //SIN MEMORIA.
    T_nodo* recorr = (*pl)->sig;
    while(cmp(d, &recorr->info)>0 && recorr != *pl)
        recorr = recorr->sig;
    if(cmp(d, &recorr->info)!=0)
        return -1; //DATO NO ENCONTRADO.
    *d = recorr->info;
    return 1; //DATO ENCONTRADO.
}
/* Admite duplicados.
*/
int agregar_ordenado(T_lista* pl, const T_dato* d, T_cmp cmp)
{
    T_nodo* nue = (T_nodo*)malloc(sizeof(T_nodo));
    if(!nue) return 0; //LISTA LLENA.
    nue->info = *d;
    if(!*pl)
    {
        nue->sig = nue;
        *pl = nue;
        return 1;
    }
    T_nodo *ant=*pl, *recorr = (*pl)->sig;
    while(cmp(&nue->info, &recorr->info)>0 && recorr != *pl)
    {
        ant = recorr;
        recorr = recorr->sig;
    }
    ant->sig = nue;
    nue->sig = recorr;
    if(cmp(&nue->info, &(*pl)->info)>0) //Si el dato ingresado es mayor que el ultimo.
        *pl = nue; //El dato ingresado es el nuevo ultimo.
    return 1;
}
