#include <ListaD.h>
#include <stdio.h>
#include <stdlib.h>

void crear_lista(t_lista* pl)
{
    *pl = NULL;
}

int insertar_en_lista_principio(t_lista* pl, const t_dato_lista* pd)
{
    t_nodod* nue = (t_nodod*)malloc(sizeof(t_nodod));
    if(!nue)
    {
        return -1;
    }
    nue->info = *pd;
    nue->pant = NULL;
    if(!*pl)
    {
        nue->psig = NULL;
        *pl = nue;
        return 1;
    }
    else
    {
        nue->psig = *pl;
        (*pl)->pant = nue;
        *pl = nue;
        return 1;
    }
}

int sacar_principio_lista(t_lista* pl,  t_dato_lista* pd)
{
    if(!*pl)
    {
        return 0;
    }
    t_nodod* act = *pl;
    if(!act->psig)
    {
        *pd = act->info;
        free(*pl);
        *pl = NULL;
        return 1;
    }
    else
    {
        *pd = act->info;
        act->psig->pant = NULL;
        *pl = act->psig;
        free(act);
        return 1;
    }
}
