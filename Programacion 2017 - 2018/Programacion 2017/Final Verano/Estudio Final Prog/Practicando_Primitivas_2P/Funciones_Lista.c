#include "Prototipos.h"
void crear_Lista(t_lista *pl)
{
    *pl = NULL;
}
void mostrar_Lista_Doble(t_lista *pl)
{
    if(!*pl)
    {
        puts("\nLISTA VACIA");
        return;
    }
    while((*pl)->pant)
        *pl = (*pl)->pant;
    while(*pl)
    {
        printf("%d\t",(*pl)->info);
        pl = &(*pl)->psig;
    }
}
int insertar_en_lista_ord(t_lista *pl,t_dato *pd,t_cmp cmp)
{   t_nodo_lis *nue,*ant,*sig,*act = *pl;
    if(!act)
    {
        sig = ant = NULL;
    }
    else
    {
        while(act->pant && cmp(pd,&act->info)<0)
            act = act->pant;
        while(act->psig && cmp(pd,&act->info)>0)
            act = act->psig;
        int comp = cmp(pd,&act->info);
        if(comp < 0)
        {
            sig = act;
            ant = act->pant;
        }
        else
        {
            ant = act;
            sig = act->psig;
        }
    }
    nue = (t_nodo_lis *)malloc(sizeof(t_nodo_lis));
        if(!nue)
            return 3;///SIN MEM;
    nue->pant = ant;
    nue->psig = sig;
    if(ant)
        ant->psig = nue;
    if(sig)
        sig->pant = nue;
    *pl = nue;
    nue->info = *pd;
    return 1;///TODO OK
}
int sacar_de_lista_ord(t_lista *pl,t_dato *pd,t_cmp cmp)
{      t_nodo_lis *nae;
        if(!*pl)
            return 0;
        while((*pl)->pant)
            *pl = (*pl)->pant;
        nae = *pl;
        *pl = nae->psig;
        *pd = nae->info;
        if(*pl)
            (*pl)->pant = NULL;
        free(nae);
        return 1;///TODO OK
}
int eliminar_duplicados_lista(t_lista *pl,t_cmp cmp)
{
    t_nodo_lis *nae,*act;
    if(!*pl)
        return 0;///lista vacia;
    while((*pl)->pant)
        *pl = (*pl)->pant;

    while(*pl)
    {
        while((*pl)->psig && cmp(&(*pl)->info,&((*pl)->psig)->info)==0)
              {
                    act = *pl;
                    nae = (*pl)->psig;
                    if(!nae->psig)
                        nae->psig = NULL;
                    else
                        {
                            (*pl)->psig = nae->psig;
                            (*pl)->psig->pant = (*pl);
                        }
                    (*pl)->psig = nae->psig;
                    free(nae);
                    if((*pl)->psig && cmp(&(*pl)->info,&((*pl)->psig)->info)!=0)
                        pl=&(*pl)->psig;


                }
              pl=&(*pl)->psig;
    }
       return 1;
}
int sacar_primero_de_lista_ord(t_lista *pl,t_dato *pd)
{
    t_nodo_lis *nae;
    if(!*pl)
        return 0;
    while(*pl && (*pl)->pant)
        pl = &(*pl)->pant;
    if((*pl)->psig)
    {
        nae = *pl;
        nae->info = (*pl)->info;
        *pd = nae->info;
        *pl = nae->psig;
        (*pl)->pant = NULL;
        free(nae);
    }
    else
    {
        nae = *pl;
        nae->info = (*pl)->info;
        *pl = NULL;
        free(nae);
    }
    return 1;

}
int ordenarLista(t_lista *pl,t_cmp cmp)
{
    t_nodo_lis *act,*sig,*ant,*sig_act,*ant_act;

    int cambio=1;
    while((*pl)->pant)
        *pl = (*pl)->pant;
    while(cambio)
    {
        act = *pl;
        while(act && act->psig)
        {
            if(cmp(&act->info,&act->psig->info)>0)
            {
                cambio=0;
                if(!act->pant)
                    ant_act = NULL;
                else
                    ant_act = act->pant;
                    ///ant_act = act->psig->pant;

                if(!(act->psig->psig))
                    sig_act = NULL;
                else
                    sig_act = act->psig->psig;

                sig = act->psig;
                ant = act;
                act->psig = sig_act;
                sig->pant = ant_act;
                sig->psig = ant;
                ant->pant = sig;
                if(ant_act)
                    ant_act->psig = sig;
            }
            act = act->psig;
        }
    }

return 1;
}
/**int ordenarLista(t_lista *pl,t_cmp cmp)
{
    t_nodo* recorrido;
    void** auxRecorrido,
        * auxIntercambio;

    if(!*pl)
        return 0;
    while((*pl)->pant)
        *pl=(*pl)->pant;///llevo el puntero al principio

    while(*pl)///comienzo a ciclar
    {
        auxRecorrido=&(*pl)->info;
        recorrido=(*pl)->psig;
        while(recorrido)
        {
            if(cmp(*auxRecorrido,recorrido->info)>0)
                auxRecorrido=&recorrido->info;
            recorrido=recorrido->psig;
        }
        if(cmp(*auxRecorrido,(*pl)->info)!=0)
        {
            auxIntercambio=*auxRecorrido;
            *auxRecorrido=(*pl)->info;
            (*pl)->info=auxIntercambio;
        }
        pl=&(*pl)->psig;
    }
    return 1;
}**/
int agregar_al_principio(t_lista* pl, t_dato* d)
{
    ///VOY AL PRINCIPIO.
    while((*pl) && (*pl)->pant)
    {
        *pl = (*pl)->pant;
    }
    t_nodo_lis* nue = malloc(sizeof(t_nodo_lis));
        if(!nue)
            return 0;
    nue->pant = NULL;
    nue->info = *d;
    nue->psig = *pl;
    ///SI LA LISTA TIENE AL MENOS UN ELEMENTO.
    if(*pl)
    {
        (*pl)->pant = nue;
    }
    *pl = nue;
    return 1; //VERDADERO.
}
int eliminar_elemento_de_lista(t_lista *pl,t_dato *pd,t_cmp cmp)
{
    t_nodo_lis *nae,*ant,*sig;
    if(!*pl)
        return 0;
    while((*pl)->pant)
        *pl = (*pl)->pant;
    while(*pl)
    {
        if(cmp(pd,&(*pl)->info)==0)
        {
            nae = *pl;
            if(!nae->psig)
                sig = NULL;
            else
                sig = nae->psig;
            if(!nae->pant)
                ant = NULL;
            else
                ant = nae->pant;
            if(ant)
            {
                *pl = ant;
                (*pl)->psig = sig;

            }
            if(sig)
            {
                *pl = sig;
                (*pl)->pant = ant;
            }
            free(nae);
            return 1;
        }
        pl = &(*pl)->psig;
    }
return 0;
}
